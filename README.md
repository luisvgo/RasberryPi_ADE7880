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

The IEC61850 works by means of the LibIEC61850 public library and the SCL descriptive file, a set of pointers to the functions to read and write to DEMVE are passed to a method that, when in the first run, takes them, and opens the required independent  threads to write or read the, acting as a server that retrieves the content of the container object of the information

Open the Readme.doc file for more information


Luis Alvarez
