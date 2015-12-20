# RasberryPi_ADE7880
RasPi interfacing a ADE7880 energy meter and a M16C62P to control the energy produced by an electric motor


Project to control a gasoline motor powered electric generator:

It consisted in a system operated remotely from DEMVE laboratory with MicroSCADA like system by means of IEC61850 standard.

A gasoline powered electric generator in Technobothnia Mechanical department that had no interface to get the data, just cables. From this, the operator had to be able to read motor status, read generated power, its related values as load current and generator voltages and quality, and change the status of the motor (ON/OFF) as well as to read, measure and evaluate status of all the different sensors. The system automatically send events of error conditions and motor status changes.

Since the Vacon frequency converter had an RS485 interface where from one could get the readings and set values to it, formatted with Modbus protocol and I2C communications, this part was mostly a software task to implement Libmodbus library in a Raspberry Pi reading through a USB to RS485 cable. And to communicate with DEMVE lab, IEC61850 standard over ethernet, by means of Substation Configuration Language (SCL). To make the device compatible with the standard, IED Capability Description (ICD) was created using the RedWind IED Modeler splitting a single physical device in multiple logical devices, in this model the device was split into solar panel and the transformer side. Then each Vacon variable is mapped to corresponding logical nodes.

With the second part there was a bit more to do with hardware, but not less with the software. Since the motor had only cables coming out of the sensors, there was a need to implement an interface to get and set values to it. Since the electric generator had only cable out of it, another interface was needed.

To interface the gasoline motor, an AVR Atmega 8bits was initially chosen to read all the sensors, which consisted of voltage levels, pulses and logic signals. Since the AVR was proven as inefficient, another implementation was made by means of a RENESAS MC16/62P µController to retrieve up to 18 different signals. This µController works as a SPI slave of a Raspberry Pi that calls to retrieve the readings and process them.

As, for security reasons, direct access to the motor wasn’t granted, a simulator was designed and built to simulate the different signals out of the sensors and test this interface.

To interface the electric generator, a ADE7880 IC was implemented. This IC is a powerful energy meter which outputs all the necessary data by means of SPI, I2C or HSDC slave interfaces. SPI was implemented for speed and simplicity compared to I2C and HSDC, moreover I have been working in another project for VASPEC Oy, in wich I was measuring the harmonics in power lines, by means of the same IC and using SPI. Meaning that I had already developed a SPI dirver to interface this IC and the Raspberry Pi SPI bus was requiring some more work to implement both channels, one for the Renesas µC and the other for the ADE7880.

As both devices are placed in the motor’s proximity, a PCB was designed to provide a socket to integrate the ADE7880 IC, another socket to connect the µC SPI I/O and another socket to connect the Raspberry Pi as SPI master. This PCB provides power to all devices, 5V to Raspberry Pi and Renesas µC, 3.3V isolated power to the ADE7880, and voltage translation, TTL to CMOS for the SPI lines. The main power source is the 12V motor battery and by means of a DC/DC buck to supply power to a 5V voltage regulator and a 3.3V linear and isolated output regulator.

The Raspberry Pi acts as the master for SPI and server for EC61850. The implementation is built is a way that when running the program, it will create a thread for each task. Thanks to the reentrant and non blocking properties of the drivers and software design, they can run freely such that they get their time to access the required communications driver whenever required. All the information is stored with timestamps and quality of the measurement. Stored in a global container, this object, a structure to store energy values and motor sensors, is passed as a void pointer to all the tasks, and, to control the access, the required semaphore is opened.

The IEC61850 works in the same manner as the solar panel implementation. By means of the LibIEC61850 public library and the SCL descriptive file, a set of pointers to the functions to read and write to DEMVE are passed to a method that, when in the first run, takes them, and opens the required independent  threads to write or read the, acting as a server that retrieves the content of the container object of the information


ESP_MCU Folders & files structure:

•	/src: 
◦	main.c
◦	main.h
◦	/energy_data: //reading_energy() thread
▪	energy_meter.c
▪	energy_meter.h
◦	/motor_data: 	//reading_motor() thread
▪	motor_data.c
▪	motor_data.h
◦	/motor_control: //Write or read  to DEMVE server
▪	motor_control_srvc.c
▪	motor_control_srvc.h
▪	transmission.c
▪	transmission.h
•	/pi_spi_bcm2835:	//Raspberry Pi SPI driver
◦	pi_spi_bcm2835.c
◦	pi_spi_bcm2835.h
◦	/bcm2835:
▪	bcm2835.c
▪	bcm2835.h
•	pi_m16c_spi:		// M16C62P SPI driver and middware
◦	definitions.h
◦	sensors.h
◦	m16c_endianness.h
◦	m16c_spi.c
◦	m16c_spi.h
◦	pi_m16c_spi.c
◦	pi_m16c_spi.h
•	pi_ade7880		// Energy meter driver and middware
◦	pi_ade7880_config.h
◦	/src:
▪	ade7880_driver.h
▪	pi_ade7880_drv.c
▪	pi_ade7880_drv.h
▪	pi_ade7880_gpio.c
▪	/ade7880:
•	ade7880_configuration.h
•	ade7880_registers.h
•	preamble.h
•	ade7880_spi_protocol.c
•	ade7880_spi_protocol.h
•	ade7880_srv_cmd_handler.c
•	ade7880_srv_cmd_handler.h
•	/libIEC61850_server:
◦	Description_on_motorcontrollerIED.xls
◦	motorcontrollerIED.icd
◦	iec_server.cfg
◦	static_model.c
◦	static_model.h
◦	/lib:
▪	libiec61850.a
▪	libiec61850_wrapper.a
◦	/include
▪	All libIEC61850 related include files.
•	/Documentation


Files content

•	main.h:
To avoid "includes" doubled defined and the headache that they may carry, general and common 'includes' that belong to the files under /src folder are all declared once and here in this file, such in a way that the source files must refer to this 'main.h' to get them. In exceptional cases that a particular header file is required uniquely by an internal source file, this may be included only in the related source file. This idea is similar to the applied by Labrosse in his system, µC/OS
	Includes as well, the set of definitions of a new type of variable to hold the readings from the two different sources. The ADE7880 energy meter and the M16C/62P µController that reads and writes to the motor. By using them, one may access the read values easily. They are similar to those defined inside the drivers folders but those are optimized for tx rv purposes inside the driver, and they may not be accessed from outside of each environment. Follow this order:
•	server_data_st
◦	mc_data_st	motor
▪	uint8_t		command;
▪	uint8_t 		cmd_addr;
▪	mc_tval_st	torque;
▪	mc_tval_st 	suction_temp;
▪	mc_tval_st	coolant_in_temp;
▪	mc_tval_st	coolant_return_temp;
▪	mc_tval_st	block_temp;
▪	mc_tval_st	exhaust_temp;
▪	mc_tval_st	oil_temp;
▪	mc_tval_st  	crankShaft_rpm;
▪	mc_tval_st  	fuel_in;
▪	mc_tval_st  	fuel_return;
▪	mc_tval_st  	suction_flow;
▪	mc_bval_st   	bin_input;
•	mc_bin__ut
◦	uint16_t  bin_all;
◦	bit_s
▪	uint16_t 	oil_pressure_OK	:1;
▪	uint16_t  	emergency_stop	:1;
▪	uint16_t 	min_fuel_lvl		:1;
▪	uint16_t 	annealing_ON		:1;
▪	uint16_t 	battery_charging	:1;
▪	uint16_t   	motor_on		:1;
▪	uint16_t 	motor_off		:1;
▪	uint16_t 	reserved		:9; 

◦	em_data_st	energy
▪	em_phase_t 	phase_a;
▪	em_phase_t 	phase_b;
▪	em_phase_t 	phase_c;
▪	em_neutral_t 	neutral_line;
•	em_phase_t
◦	em_tval_st 	IRMS;
◦	em_tval_st 	VRMS;
◦	em_tval_st 	WH;
◦	em_tval_st 	POWER;
•	em_neutral_t
◦	em_tval_st 	IN_IRMS;
◦	em_tval_st 	INSTANT_IN;
◦	em_tval_st 	IN_HXIRMS;
◦	em_tval_st 	IN_HYIRMS;
◦	em_tval_st 	IN_HZIRMS;
◦	em_tval_st 	IN_HXIHD;
◦	em_tval_st 	IN_HYIHD;
◦	em_tval_st 	IN_HZIHD;
◦	em_tval_st 	ISUM_HXVRMS;
◦	em_tval_st 	ISUM_HYVRMS;
◦	em_tval_st 	ISUM_HZVRMS;
◦	em_tval_st 	ISUM_HXVHD;
◦	em_tval_st 	ISUM_HYVHD;
◦	em_tval_st 	ISUM_HZVHD;
▪	em_tval_st
•	float 	value;
•	uint64_t timestamp;

i.e. to accesss the timestamp of the phase a instantaneos rms current in:

server_data_st 	data;		// declare an element of the variable from the header
uint64_t  irms_timestamp = data.energy.phase_a.IRMS.timestamp	 //use it


•	/src/main.c
Opens three new threads, one to handle the M16C readings (reading_motor), another to the ADE7880 (reading_energy)and one more to upload these values to the DEMVE system (motor_control_srvc).
A variable member of 'server_data_st' is created previously, initialized and passed as a pointer to its memory address to the three threads. In this way all the threads have a common place to read from or write to.
To protect the access to this variable and accesses to the SPI driver, semaphores are created here too.
The infinite loop will catch any keyboard press and exit if 'q' is read. Each loop execution sleeps for 100ms

•	/src/motor_data/motor_data.h:   
Application unique PID
macros to convert ADC values to Flow and pulses to RPM. 

•	/src/motor_data/motor_data.c:
reading_motor() thread.
In first execution initializes SPI communications if not initialized before.
Then calls M16C µController by reading all the sensors data in one call. One may call each sensor individually if required, but this is not efficient.
The received data is checked and filtered. If no error is detected, values are loaded one by one into a local variable together with a time stamp taken at that moment, to be passed altogether to the main container, the pointer to the 'server_data_st' member.. This step is protected by a semaphore, as each access to it is. Time stamps are taken by the Raspberry Pi and not the M16C because this has not a realtime clock and to avoid the overload of this µController acting as a peripheral. Despite of this, the sensors are read all every microsecond in polling mode, the same for the bit values constantly checked, and  flow and revolutions are measured by 16 bit timers at 750KHz and 3MHz respectively, triggering interrupts in a time gap from 0 to 87.38ms (flow) and 0 to 21.85ms(RPM). The total length of the transmission is 2 bytes in the MOSI and 33 back in the MISO, 35 bytes equals to 280bits. When the transmission speed is set to 3.8Kbps, 73ms is the total transmission time. The processing time is less than 1ms. This gives us a minimum delay of 74ms up to a maximum of 160ms. These values are transmitted at a relaxed speed of 3.8kbps that can be raised to 7.6kbps if required. Giving a minimum of 37ms up to 125ms per transmission but increasing the chance of error  . Tested at 15kbps the chance of error rises heavily due to the ISR overload
 In the M16C. Said this, one may take the timestamp as the time the measure has arrived and, if required, improve it by adding a µController with a real time clock to set timestamps from it.
There is included a call to transmit_measures() which is no more than a function to display the data on screen for debugging purposes. Uncomment it if required.
Then the thread sleeps for a determined time in miliseconds.
As for each source file that holds the code for an independent thread, an APP_ID has to be defined for the thread. Initially is only used to control accesses to the SPI driver. In this file, one may find it defined as MOTOR _TASK_PID and refers to a unique 32 bits integer number, no other APP_ID can have the same value. Calls to the drivers require this number.

•	/src/energy_data/energy_meter.h:
Application unique PID

•	/src/energy_data/energy_meter.c:
reading_energy() thread.
First run opens 'bcm2835' library and SPI communications, if not opened jet, and proceed to configure the ADE7880 as an energy meter
The loop reads the required ADE registers. As this device has many different, one by one are read and not all at the same time as with the M16C communications. Processed in the same way as teh motor readings, the transmission speed is 1Mbps that can be raised up to 2Mbps. The speed has been tested and proved that one register read and processing takes less than half of a millisecond, reading a set of 5 registers from 2 to 3 milliseconds. Note that the test conditions were to add printouts of the timestamp of each reading in the code, function that, itself, adds a delay.

•	/src/motor_control/motor_control_srvc.h has nothing relevant

•	/src/motor_control/motor_control_srvc.c
motor_control_srvc() thread 
This thread executes only once. It creates independent threads that call the server_writeData() and server_readData() callbacks and network connection to hold DEMVE transmissions by means of libIEC61850. These functions upload and read back data to DEMVE system.
Only server_writeData() is implemented to upload the data to DEMVE, for security issues, we cannot access or control the motor in any way so despite of defined for a future use and included in the code, it remains empty. 
Data is uploaded using the methods provided by the library after building the required IED description file.

•	/pi_spi_bcm2835/pi_spi_bcm2835.h 
Provides definitions and prototypes for public functions

•	/pi_spi_bcm2835/pi_spi_bcm2835.c
Midware driver for SPI access, makes access to the SPI reentrant but non-blocking and adds extra control over it. One must use the provided functions in here and not access the driver directly in any case. This middware makes the driver fully compatible with systems that have different applications running in different threads with calls to the same device using different configurations and speeds. It could be implemented even if having more than one different SPI bus and always warrantee that one application is using it at a time with its own configuration. Read doxygen documentation for more information.

•	/pi_spi_bcm2835/bcm2835 
This folder holds the SPI bcm2835 driver, if the driver is installed in the system the access to this folder is no longer required.
Bcm2835 library driver is the result of the work from Mike McCauley for accessing the RasPi GPIO pins v1 and v2

•	/pi_m16c_spi/definitions.h 
Use it to set the CS channel in use by the M16C µController SPI (CS1). 
Set the transmission speed to 0 as the safest (3.815kHz)
Read and write command, have to be the same in M16C code. Is the first byte in the MOSI line and indicates the type of operation to perform

•	/ pi_m16c_spi/m16c_endianness.h
M16C transmission translation at byte level. Set here the required configuration (usually little, and that is the one in M16C code). The code will do the rest, including the necessary to arrange the correct byte position.

•	/ pi_m16c_spi/sensors.h
Holds the definitions for each sensor controlled by the M16C.Required to address each sensor call. Has to be the same as in M16C code

•	/ pi_m16c_spi/pi_m16c_spi.h. Nothing relevant.

•	/ pi_m16c_spi/pi_m16c_spi.c
Midware for the M16C SPI driver. Provides the access to the SPI under control, avoiding access conflicts, it not only avoids different apps collisions but different threads of the same app as well.
Use it always whenever the M16C requires access to the SPI driver. 
At this moment only PI_M16C_SPI_Write and PI_M16C_SPI_Read are implemented but they are enough. These methods are of the same structure like those found in the pi_ade7880 midware


•	/ pi_m16c_spi/m16c_spi.h
Include definitions to build the transmission or reception buffer. It is build up as a concatenate set of structures altogether with unions, providing access to the whole transmitted string or to each individual set of information.
To pack the bytes aligned together, instead of using compiler specific code, this file provides a way to control the starting point of every new set of information by setting its relative offset to the beginning of the buffer. This is a static way to build it up but it offers a higher portability.

•	/ pi_m16c_spi/m16c_spi.c
M16C SPI driver for Raspberry Pi. Provides only readings from the M16C since motor cannot be controlled therefore not accepting writes to its settings.
The driver provides two main methods to access the peripheral, one to read a specific sensor address content and, a second one, to read all the addresses content in a row. This latest is the only one in use since it is much more efficient. To read individual sensor addresses will not only take longer, but affect slightly the quality of the measurements since the Chip Select signal triggers an interrupt, and this has a high priority in the peripheral that might, rarely but possible, affect another interrupts like the RPMs. A word about the M16C code at the end of this document if time allows.
The calls to the driver handle the transmissions buffer byte arrangement. If the byte “endianness” has been set correctly, the content will be stored in the right order. 
This file provides two methods to get or set the transmissions buffer, M16C_set_tx_buffer, M16C_get_tx_buffer, M16C_set_single_tx_buffer and M16C_get_single_tx_buffer.This methods handle the byte padding, packing the whole buffer based in the defined offsets. 

•	/pi_ade7880/pi_ade7880_config.h
Global ADE7880 configurations, SPI channel in use by the peripheral, the SPI clock speed and a delay in µseconds while waiting access to SPI driver. One may set here the seconds to yield the current task, no further use in this code since it will always get access in time. 

•	/pi_ade7880/src/ade7880_driver.h
The file that any project should include to grant the access to the driver. Read Doxygen documentation for more information.

•	/pi_ade7880/src/pi_ade7880_drv.h
Definitions to hook the peripheral pins to the Raspberry Pi pins and the structure definition for storing the measured data

•	/ pi_ade7880/src/pi_ade7880_drv.c
To keep the driver portable and system independent, required to hook the driver code to the system. Provides access from the driver to methods that have direct access to the hardware (GPIO) or other system drivers, in other words, is the way the hardware (RasPi) is hidden from the ADE7880 driver.
In order to achieve a fully independent driver, the methods that are required inside it, have to be passed from the middware as callbacks, said this, a call to PI_ADE_driverCallbacks() is required before calling any driver’s method. 


Luis Alvarez
