#define MC_TORQUE_LOW_ADDR 					0x00
#define MC_TORQUE_HIGH_ADDR 				0x01
#define MC_SUCTION_TEMP_LOW_ADDR 			0x02
#define MC_SUCTION_TEMP_HIGH_ADDR 			0x03
#define MC_COOLANT_GOING_TEMP_LOW_ADDR 		0x04
#define MC_COOLANT_GOING_TEMP_HIGH_ADDR 	0x05
#define MC_COOLANT_RETURN_TEMP_LOW_ADDR 	0x06
#define MC_COOLANT_RETURN_TEMP_HIGH_ADDR 	0x07
#define MC_ENGINE_BLOCK_TEMP_LOW_ADDR		0x08
#define MC_ENGINE_BLOCK_TEMP_HIGH_ADDR		0x09
#define MC_EXHAUST_TEMP_LOW_ADDR			0x0A
#define MC_EXHAUST_TEMP_HIGH_ADDR			0x0B
#define MC_OIL_TEMP_LOW_ADDR				0x0C
#define MC_OIL_TEMP_HIGH_ADDR				0x0D
#define MC_CRANKSHAFT_RPM_LOW_ADDR			0x0E
#define MC_CRANKSHAFT_RPM_HIGH_ADDR			0x0F
#define MC_FUEL_GOING_LOW_ADDR				0x10
#define MC_FUEL_GOING_HIGH_ADDR				0x11
#define MC_FUEL_RETURN_LOW_ADDR				0x12
#define MC_FUEL_RETURN_HIGH_ADDR			0x13
#define MC_SUCTION_FLOW_LOW_ADDR			0x14
#define MC_SUCTION_FLOW_HIGH_ADDR			0x15
#define MC_AVR_BIN_INPUT_1					0x16
#define MC_AVR_BIN_OUTPUT_1					0x17
#define MC_AVR_REGISTERS_ALL				0xAA

//MC_BIN_INPUT_1 MASKS
#define MC_BIN_INPUT_1_OILPRESSURE_OK	 	0
#define MC_BIN_INPUT_1_EMERG_STOP			1
#define MC_BIN_INPUT_1_MIN_FUEL_LVL			2
#define MC_BIN_INPUT_1_ANNEALING_ON			3

//MC_BIN_OUTPUT_1 MASKS
#define MC_BIN_OUTPUT_1_MOTOR_START			0
#define MC_BIN_OUTPUT_1_MOTOR_STOP			1
#define MC_BIN_OUTPUT_1_EXHAUST_VAC_ON		2
#define MC_BIN_OUTPUT_1_EXHAUST_VAN_OFF		3
#define MC_BIN_OUTPUT_1_RPM_UP				4
#define MC_BIN_OUTPUT_1_RPM_DOWN			5
