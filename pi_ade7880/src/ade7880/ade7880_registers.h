/// \file ade7880_registers.h
/// \brief ADE7880 registers address and structure for easier access
/********************************************************
 *
 *   ADE7880 REGISTERS LIST
 *	 DataSheet Rev. A | Page 83 of 104
 *		Organized by Address, from lower to higher
 *
 *	DSP Registers Located in Data Memory RAM at addresses between 0x4380 and 0x43BE
 *
 *  The width of this memory is 28 bits. A two-stage pipeline is used when write
 *  operations to the data memory RAM are executed. This means two things: when
 *  only one register needs to be initialized, write it two more times to ensure
 *  the value has been written into RAM.
 *  When two or more registers need to be initialized, write the last register
 *  in the queue two more times to ensure the value has been written into RAM.
 *
 *  Internal DSP Memory RAM Registers from 0xE400 to 0xE40E
 *
 ********************************************************/

#ifndef __ADE7880_REGISTERS_H
#define __ADE7880_REGISTERS_H


#include <stdint.h>

/**********************************************************
 * DSP Registers Located in Data Memory RAM at addresses between 0x4380 and 0x43BE
 *********************************************************/
#define		AIGAIN 		0x4380 
#define 	AVGAIN 		0x4381 
#define 	BIGAIN 		0x4382 
#define 	BVGAIN 		0x4383 
#define 	CIGAIN 		0x4384 
#define 	CVGAIN 		0x4385 
#define 	NIGAIN 		0x4386 
#define 	DICOEFF 	0x4388 			// Register used in the digital integrator algorithm. 
#define 	DICOEFF_DEFAULT	0x0FFF8000	// If Integrator is on, must be set at 0xFF8000. It is transmitted as 0xFFF8000.
#define 	APGAIN 		0x4389 
#define 	AWATTOS 	0x438A 
#define 	BPGAIN 		0x438B 
#define 	BWATTOS 	0x438C 
#define 	CPGAIN 		0x438D 
#define 	CWATTOS 	0x438E 
#define 	AIRMSOS 	0x438F 
#define 	AVRMSOS 	0x4390 
#define 	BIRMSOS 	0x4391 
#define 	BVRMSOS 	0x4392 
#define 	CIRMSOS 	0x4393 
#define 	CVRMSOS 	0x4394 
#define 	NIRMSOS 	0x4395 
#define 	HPGAIN 		0x4398 
#define 	ISUMLVL 	0x4399 
#define 	VLEVEL 		0x439F 
#define 	AFWATTOS 	0x43A2 
#define 	BFWATTOS 	0x43A3 
#define 	CFWATTOS 	0x43A4 
#define 	AFVAROS 	0x43A5 
#define 	BFVAROS 	0x43A6 
#define 	CFVAROS 	0x43A7 
#define 	AFIRMSOS 	0x43A8 
#define 	BFIRMSOS 	0x43A9 
#define 	CFIRMSOS 	0x43AA 
#define 	AFVRMSOS 	0x43AB 
#define 	BFVRMSOS 	0x43AC 
#define 	CFVRMSOS 	0x43AD 
#define 	HXWATTOS 	0x43AE 
#define 	HYWATTOS 	0x43AF 
#define 	HZWATTOS 	0x43B0 
#define 	HXVAROS 	0x43B1 
#define 	HYVAROS 	0x43B2 
#define 	HZVAROS 	0x43B3 
#define 	HXIRMSOS 	0x43B4 
#define 	HYIRMSOS 	0x43B5 
#define 	HZIRMSOS 	0x43B6 
#define 	HXVRMSOS 	0x43B7 
#define 	HYVRMSOS 	0x43B8 
#define 	HZVRMSOS 	0x43B9 
//#define	End Of RAM 	0x43BE
#define 	AIRMS 		0x43C0 
#define 	AVRMS 		0x43C1 
#define 	BIRMS 		0x43C2 
#define 	BVRMS 		0x43C3 
#define 	CIRMS 		0x43C4 
#define 	CVRMS 		0x43C5 
#define 	NIRMS 		0x43C6 
#define 	ISUM 		0x43C7 


/**********************************************************
 *  Internal DSP Memory RAM Registers from 0xE400 to 0xE40E
 *********************************************************/

#define 	RUN 		0xE228			// DSP run control register

#define 	AWATTHR 	0xE400 
#define 	BWATTHR 	0xE401 
#define 	CWATTHR 	0xE402 
#define 	AFWATTHR 	0xE403 
#define 	BFWATTHR 	0xE404 
#define 	CFWATTHR 	0xE405 
#define 	AFVARHR 	0xE409 
#define 	BFVARHR 	0xE40A 
#define 	CFVARHR 	0xE40B 
#define 	AVAHR 		0xE40C 
#define 	BVAHR 		0xE40D 
#define 	CVAHR 		0xE40E 


/**********************************************************
 *  Configuration and Power Quality Registers
 *********************************************************/
 
/** IPEAK Register address and structure (Address 0xE500)   */
#define 	IPEAK 		0xE500 			///< Current peak register. See Figure 58(DS Page 34) and Table 34(DS Page 89) for details about its composition.
typedef union
{
	uint16_t 		REG_ALL;
	struct
	{									//bit	Def.Val
		uint32_t 	IPEAKVAL	:24;	//	23:0	0
		uint32_t 	IPPHASE_0	:1;		//	24		0
		uint32_t 	IPPHASE_1	:1;		//	25		0 
		uint32_t 	IPPHASE_2	:1;		//	26		0
		uint32_t 	RESERVED	:5;		//	31:27	0 These bits are always 0.
	}bits;
}IPEAK_reg_u;
/* End of IPEAK register */

/** VPEAK Register address and structure (Address 0xE500) */
#define 	VPEAK 		0xE501 			///< Voltage peak register. See Figure 58(DS Page 34) and Table 35(DS Page 89) for details about its composition.
typedef union
{
	uint16_t 		REG_ALL;
	struct
	{									//bit	Def.Val
		uint32_t 	VPEAKVAL	:24;	//	23:0	0
		uint32_t 	VPPHASE_0	:1;		//	24		0
		uint32_t 	VPPHASE_1	:1;		//	25		0 
		uint32_t 	VPPHASE_2	:1;		//	26		0
		uint32_t 	RESERVED	:5;		//	31:27	0 These bits are always 0.
	}bits;
}VPEAK_reg_u;
/* End of VPEAK */

/** STATUS0 Register Physical address and structure   */
#define 	STATUS0 	0xE502 			///< Interrupt Status Register 0. See Table 36(DS Page 89).
typedef union
{
	uint32_t 		REG_ALL;
	struct
	{									//bit	Def.Val
		uint32_t 	AEHF	   	:1;		//	0		0
		uint32_t 	FAEHF		:1;		//	1		0
		uint32_t 	Reserved	:1;		//	2		0 always
		uint32_t 	FREHF		:1;		//	3		0
		uint32_t 	VAEHF		:1;		//	4		0
		uint32_t 	LENERGY		:1;		//	5		0
		uint32_t 	REVAPA		:1;		//	6		0
		uint32_t 	REVAPB		:1;		//	7		0
		uint32_t 	REVAPC		:1;		//	8		0
		uint32_t 	REVPSUM1	:1;		//	9		0
		uint32_t 	REVFRPA		:1;		//	10		0
		uint32_t	REVFRPB		:1;		//	11		0
		uint32_t 	REVFRPC		:1;		//	12		0
		uint32_t 	REVPSUM2	:1;		//	13		0
		uint32_t 	CF1			:1;		//	14		
		uint32_t 	CF2			:1;		//	15		
		uint32_t 	CF3			:1;		//	16		
		uint32_t 	DREADY  	:1;		//	17		0
		uint32_t 	REVPSUM3	:1;		//	18		0
		uint32_t 	HREADY  	:1;		//	19		0	
		uint32_t 	RESERVED	:12;	//	31:20	0 always 0	         
	}bits;
}STATUS0_reg_u;
/* End of STATUS0 */

/** STATUS1 Register Physical address and structure   */
#define 	STATUS1 	0xE503 			///< Interrupt Status Register 1. See Table 37(DS Page 91).
#define 	STATUS1_DEFAULT		0x00208000
typedef union
{
	uint32_t 		REG_ALL;
	struct
	{									//bit	Def.Val
		uint32_t 	NLOAD   	:1;		//	0		0
		uint32_t 	FNLOAD		:1;		//	1		0
		uint32_t 	VANLOAD		:1;		//	2		0 
		uint32_t 	ZXTOVA		:1;		//	3		0
		uint32_t 	ZXTOVB		:1;		//	4		0
		uint32_t 	ZXTOVC		:1;		//	5		0
		uint32_t 	ZXTOIA		:1;		//	6		0
		uint32_t 	ZXTOIB		:1;		//	7		0
		uint32_t 	ZXTOIC		:1;		//	8		0
		uint32_t 	ZXVA		:1;		//	9		0
		uint32_t 	ZXVB		:1;		//	10		0
		uint32_t 	ZXVC		:1;		//	11		0
		uint32_t 	ZXIA		:1;		//	12		0
		uint32_t 	ZXIB		:1;		//	13		0
		uint32_t 	ZXIC		:1;		//	14		0
		uint32_t 	RSTDONE		:1;		//	15		1
		uint32_t 	SAG			:1;		//	16		0
		uint32_t 	OI  		:1;		//	17		0
		uint32_t 	OV			:1;		//	18		0
		uint32_t 	SEQERR  	:1;		//	19		0	
		uint32_t 	MISMTCH		:1;		//	20		0
		uint32_t 	RESERVED0	:1;		//	21		1 always 1
		uint32_t 	RESERVED1	:1;		//	22		0
		uint32_t 	PKI	  		:1;		//	23		0
		uint32_t 	PKV	  		:1;		//	24		0
		uint32_t 	CRC_CHK		:1;		//	25		0
		uint32_t 	RESERVED2	:6;		//	31:26	0 always 0	         
	}bits;
}STATUS1_reg_u;
/* End of STATUS1 */

#define 	AIMAV 		0xE504 
#define 	BIMAV 		0xE505 
#define	 	CIMAV 		0xE506 
#define 	OILVL 		0xE507 
#define 	OVLVL 		0xE508 
#define 	SAGLVL 		0xE509

/** MASK0 Register Physical address and structure  */
#define 	MASK0 		0xE50A 			///< Interrupt Enable Register 0. See Table 38(DS Page 92).
typedef union
{
	uint32_t 		REG_ALL;
	struct
	{									//bit	Def.Val
		uint32_t 	AEHF   		:1;		//	0		0
		uint32_t 	FAEHF		:1;		//	1		0
		uint32_t 	RESERVED	:1;		//	2		0 
		uint32_t 	FREHF		:1;		//	3		0
		uint32_t 	VAEHF		:1;		//	4		0
		uint32_t 	LENERGY		:1;		//	5		0
		uint32_t 	REVAPA		:1;		//	6		0
		uint32_t 	REVAPB		:1;		//	7		0
		uint32_t 	REVAPC		:1;		//	8		0
		uint32_t 	REVPSUM1	:1;		//	9		0
		uint32_t 	REVFRPA		:1;		//	10		0
		uint32_t 	REVFRPB		:1;		//	11		0
		uint32_t 	REVFRPC		:1;		//	12		0
		uint32_t 	REVPSUM2	:1;		//	13		0
		uint32_t 	CF1			:1;		//	14		0
		uint32_t 	CF2			:1;		//	15		0
		uint32_t 	CF3			:1;		//	16		0
		uint32_t 	DREADY  	:1;		//	17		0
		uint32_t 	REVPSUM3	:1;		//	18		0
		uint32_t 	HREADY  	:1;		//	19		0	
		uint32_t 	RESERVED1	:12;	//	31:20	0 	  
	}bits;
}MASK0_reg_u;
/* End of MASK0 */

/** MASK1 Register Physical address and structure */
#define 	MASK1 		0xE50B 			///< Interrupt Enable Register 1. See Table 39(DS Page 93).
typedef union
{
	uint32_t 		REG_ALL;
	struct
	{
		uint32_t	NOT_USED 	:24;
		uint32_t 	CRC1      	:1;
		uint32_t 	RESERVED 	:6; 
	}bits;
}MASK1_reg_u;
/* End of MASK1 */

#define 	IAWV 		0xE50C 
#define 	IBWV 		0xE50D 
#define 	ICWV 		0xE50E 
#define 	INWV 		0xE50F 
#define 	VAWV 		0xE510 
#define 	VBWV 		0xE511 
#define 	VCWV 		0xE512 
#define 	AWATT 		0xE513 
#define 	BWATT 		0xE514 
#define 	CWATT 		0xE515 
//#define AVA 0xE519 
//#define BVA 0xE51A 
//#define CVA 0xE51B 
#define 	AFVAR 		0xE519 
#define 	BFVAR 		0xE51A 
#define 	CFVAR 		0xE51B 
#define 	CHECKSUM 	0xE51F 
#define 	VNOM 		0xE520 
#define 	LAST_RWDATA32    0xE5FF

/** PHSTATUS Register Physical address and structure */
#define 	PHSTATUS 	0xE600			// Phase peak register. See Table 40.
typedef union
{
	uint16_t 		REG_ALL;
	struct
	{										//bit	Def.Val
		uint16_t 	RESERVED 	:3;		//	2:0		000
		uint16_t 	OIPHASE1 	:1;		//	3		0
		uint16_t 	OIPHASE2	:1;		//	4		0
		uint16_t 	OIPHASE3	:1;		//	5		0
		uint16_t 	RESERVED1 	:3;		//	8:6		000
		uint16_t 	OVPHASE1 	:1;		//	9		0
		uint16_t 	OVPHASE2 	:1;		//	10		0
		uint16_t 	OVPHASE3 	:1;		//	11		0
		uint16_t 	VSPHASE1 	:1;		//	12		0
		uint16_t 	VSPHASE2	:1;		//	13		0
		uint16_t 	VSPHASE3   	:1;		//	14		0
		uint16_t 	RESERVED2  	:1;		//	15		0        
	}bits; 
}PHSTATUS_reg_u;
/* End of PHSTATUS */

#define 	ANGLE0 		0xE601 
#define 	ANGLE1 		0xE602 
#define 	ANGLE2 		0xE603 

/** PHNOLOAD Register Physical address and structure */
#define 	PHNOLOAD 	0xE608 			// Phase no load register. See Table 41.
typedef union
{
	uint16_t 		REG_ALL;
	struct
	{									//bit	Def.Val
		uint16_t 	NLPHASE0 	:1;		//	0		0
		uint16_t 	NLPHASE1 	:1;		//	1		0
		uint16_t 	NLPHASE2	:1;		//	2		0
		uint16_t 	FNLPHASE0	:1;		//	3		0
		uint16_t 	FNLPHASE1 	:1;		//	4		0
		uint16_t 	FNLPHASE2 	:1;		//	5		0
		uint16_t 	VANLPHASE0 	:1;		//	6		0
		uint16_t 	VANLPHASE1 	:1;		//	7		0
		uint16_t 	VANLPHASE2 	:1;		//	8		0
		uint16_t 	RESERVED2  	:7;		//	15:9	000 0000        
	}bits; 
}PHNOLOAD_reg_u;
/* End of PHNOLOAD */

#define 	LINECYC 	0xE60C 
#define 	ZXTOUT 		0xE60D 

/** COMPMODE Register Physical address and structure */
#define 	COMPMODE 	0xE60E 				// Computation-mode register. See Table 42(DS Page 95).
typedef union
{
	uint16_t 		REG_ALL;
	struct
	{									// bit	Def.Val
		uint16_t 	TERMSEL1_0 	:1;		//	0		1
		uint16_t 	TERMSEL1_1 	:1;		//	1		1
		uint16_t 	TERMSEL1_2 	:1;		//	2		1
		uint16_t 	TERMSEL2_0 	:1;		//	3		1
		uint16_t 	TERMSEL2_1 	:1;		//	4		1
		uint16_t 	TERMSEL2_2 	:1;		//	5		1
		uint16_t 	TERMSEL3_0 	:1;		//	6		1
		uint16_t 	TERMSEL3_1 	:1;		//	7		1
		uint16_t 	TERMSEL3_2 	:1;		//	8		1
		uint16_t 	ANGLESEL	:2;		//	10:9	00
		uint16_t 	VNOMAEN    	:1;		//	11		0
		uint16_t 	VNOMBEN    	:1;		//	12		0
		uint16_t 	VNOMCEN    	:1;		//	13		0
		uint16_t 	SELFREQ    	:1;		//	14		0	
		uint16_t 	RESERVED	:1;		//	15		0          
	}bits; 
}COMPMODE_reg_u;
/* End of COMPMODE */

/** GAIN Register Physical address and structure  */
#define 	GAIN		0xE60F 			// PGA gains at ADC inputs. See Table 43.
// GAIN Common multipliers defines
#define 	GAIN_1     		00       
#define 	GAIN_2     		01   
#define 	GAIN_4     		02 
#define 	GAIN_8     		03
#define 	GAIN_16    		04

typedef enum 
{ 
	gain_1	= 	GAIN_1,       
	gain_2  = 	GAIN_2,   
	gain_4  = 	GAIN_4, 
	gain_8  = 	GAIN_8,
	gain_16 = 	GAIN_16
}pga_et;
typedef union
{
	uint16_t 		REG_ALL;
	struct
	{
	   pga_et 		PGA1		:3;
	   pga_et 		PGA2		:3; 	   
	   pga_et 		PGA3		:3; 
	   uint16_t 	RESERVED	:7;
	}bits;
}GAIN_reg_u;
// End of GAIN register

/** CFMODE Register Physical address and structure */
#define 	CFMODE 		0xE610 			// CFx configuration register. See Table 44.
typedef union
{
	uint16_t 		REG_ALL;
	struct
	{									//	bit		Def.Val
		uint16_t 	CF1SEL 		:3;		//	2:0		000
		uint16_t 	CF2SEL 		:3;		//	5:3		100
		uint16_t 	CF3SEL		:1;		//	8:6		010
		uint16_t 	CF1DIS		:1;		//	9		1
		uint16_t 	CF2DIS	 	:1;		//	10		1
		uint16_t 	CF3DIS	 	:1;		//	11		1
		uint16_t 	CF1LATCH 	:1;		//	12		0
		uint16_t 	CF2LATCH 	:1;		//	13		0
		uint16_t 	CF3LATCH 	:1;		//	15		0
		uint16_t 	RESERVED  	:1;		//	15		0        
	}bits; 
}CFMODE_reg_u;
/* End of CFMODE */ 

#define 	CF1DEN 		0xE611 
#define 	CF2DEN 		0xE612 
#define 	CF3DEN 		0xE613 
	
/** APHCAL Register Physical address and structure   */
#define 	APHCAL 		0xE614 			// Phase calibration of Phase A. See Table 45(DS Page 97).
typedef union
{
	uint16_t REG_ALL;
	struct
	{									// bit	Def.Val
		uint16_t 	PHCALVAL    :10;	//	9:0		0		// ADE7880 DataSheet Rev. A| Page 97 of 104
		uint16_t 	RESERVED    :6;		//	15:10	0
	}bits;
}APHCAL_reg_u;
/* End of APHCAL */ 

/** BPHCAL Register Physical address and structure   */
#define 	BPHCAL 		0xE615 			// Phase calibration of Phase B. See Table 45(DS Page 97).
typedef union
{
	uint16_t REG_ALL;
	struct
	{									// bit	Def.Val
		uint16_t 	PHCALVAL    :10;	//	9:0		0		// ADE7880 DataSheet Rev. A| Page 97 of 104
		uint16_t 	RESERVED    :6;		//	15:10	0
	}bits;
}BPHCAL_reg_u;
/* End of BPHCAL */ 

/** CPHCAL Register Physical address and structure   */
#define 	CPHCAL 		0xE616 			// Phase calibration Phase of C. See Table 45(DS Page 97).
typedef union
{
	uint16_t REG_ALL;
	struct
	{									// bit	Def.Val
		uint16_t 	PHCALVAL    :10;	//	9:0		0		// ADE7880 DataSheet Rev. A| Page 97 of 104
		uint16_t 	RESERVED    :6;		//	15:10	0
	}bits;
}CPHCAL_reg_u;
/* End of CPHCAL */ 

/** PHSIGN Register Physical address and structure  */
#define 	PHSIGN 		0xE617 			// Power sign register. See Table 46.
typedef union
{
	uint16_t 		REG_ALL;
	struct
	{									// bit	Def.Val
		uint16_t 	AWSIGN	 	:1;		//	0		0
		uint16_t 	BWSIGN	 	:1;		//	1		0
		uint16_t 	CWSIGN	 	:1;		//	2		0
		uint16_t 	SUM1SIGN 	:1;		//	3		0
		uint16_t 	AFVARSIGN 	:1;		//	4		0
		uint16_t 	BFVARSIGN 	:1;		//	5		0
		uint16_t 	CFVARSIGN 	:1;		//	6		0
		uint16_t 	SUM2SIGN 	:1;		//	7		0
		uint16_t 	SUM3SIGN 	:1;		//	8		0	
		uint16_t 	RESERVED	:7;		//	15:9	000 0000          
	}bits; 
}PHSIGN_reg_u;
/* End of PHSIGN */

/** CONFIG Register address and structure   */
#define CONFIG 				0xE618 		// ADE7880 configuration register. See Table 47 DS Rev. A| Page 97 of 104.
#define CONFIG_DEFAULT 		0x0002		// Constant macro for its default value
typedef union
{
	uint16_t REG_ALL;
	struct
	{										//bit	Def.Val
		uint16_t 	INTEN     	:1;		//	0		0
		uint16_t 	RESERVED    :1;		//	1		1
		uint16_t 	CF2DIS      :1;		//	2		0
		uint16_t 	SWAP	   	:1;		//	3		0
		uint16_t 	MOD1SHORT  	:1;		//	4		0
		uint16_t 	MOD2SHORT 	:1;		//	5		0
		uint16_t 	HSDCEN		:1;		//	6		0
		uint16_t 	SWRST	 	:1;	   	//	7		0
		uint16_t 	VTOIA	 	:2;		//	9:8		0
		uint16_t 	VTOIB	 	:2;		//	11:10	0
		uint16_t 	VTOIC	 	:2;		//	13:12	0		   
		uint16_t 	RESERVED2 	:2;		//	15:14	0	       
	}bits;
}CONFIG_reg_u;
/* End of CONFIG  */

#define MMODE 0xE700 

/** ACCMODE Register Physical address and structure   */
#define ACCMODE 0xE701 
// ACCMODE common definitions
#define MODE_0_0     		00       
#define MODE_0_1     		01   
#define MODE_1_0     		02 
#define MODE_1_1     		03

typedef enum
{
	mode_0_0 = MODE_0_0,       
	mode_0_1 = MODE_0_1,   
	mode_1_0 = MODE_1_0, 
	mode_1_1 = MODE_1_1
}mode_et;

typedef union
{
	uint8_t REG_ALL;
	struct
	{
		mode_et 	WATTACC 	:2;
		mode_et 	VARACC  	:2; 	   
		mode_et 	CONSEL  	:2; 
		uint8_t 	REVAPSEL	:1;
		uint8_t 	RESERVED	:1;
	}bits;
}ACCMODE_reg_u;
// End of ACCMODE register

/** LCYCMODE Register Physical address and structure   */
#define LCYCMODE 0xE702  
typedef union
{
	uint8_t REG_ALL;
	struct
	{
		uint8_t 	LWATT		:1;
		uint8_t 	LVAR 		:1;
		uint8_t 	LVA  		:1;
		uint8_t 	ZXSEL_A	    :1;
		uint8_t 	ZXSEL_B 	:1;
		uint8_t 	ZXSEL_C  	:1;
		uint8_t 	RSTREAD	    :1;
		uint8_t 	PFMODE 	    :1;
	}bits;
}LCYCMODE_reg_u;
/* End of LCYCMODE */

#define 	PEAKCYC 	0xE703 
#define 	SAGCYC 		0xE704 
#define 	CFCYC 		0xE705 

/** HSDC_CFG Register address and structure  */
#define HSDC_CFG 				0xE706 
#define HSDC_CFG_DEFAULT 		0x0000			// Constant macro for its default value
typedef union
{
	uint16_t REG_ALL;
	struct
	{										//bit	Def.Val
		uint16_t 	HCLK     	:1;		//	0		0
		uint16_t 	HSIZE    	:1;		//	1		0
		uint16_t 	HGAP      	:1;		//	2		0
		uint16_t 	HXFER	   	:1;		//	4:3		00
		uint16_t 	HSAPOL  	:1;		//	5		0		   
		uint16_t 	RESERVED 	:2;		//	7:6		00	       
	}bits;
}HSDC_CFG_reg_u; 
/* End of HSDC_CFG */

#define 	Version 	0xE707 
#define 	LAST_RWDATA8    0xE7FD
#define 	FVRMS 		0xE880 
#define 	FIRMS 		0xE881 
#define 	FWATT 		0xE882 
#define 	FVAR 		0xE883 
#define 	FVA 		0xE884 
#define 	FPF 		0xE885 
#define 	VTHDN 		0xE886 
#define 	ITHDN 		0xE887 
#define 	HXVRMS 		0xE888 
#define 	HXIRMS 		0xE889 
#define 	HXWATT 		0xE88A 
#define 	HXVAR 		0xE88B 
#define		HXVA 		0xE88C 
#define 	HXPF 		0xE88D 
#define 	HXVHD 		0xE88E 
#define 	HXIHD 		0xE88F 
#define 	HYVRMS 		0xE890 
#define 	HYIRMS 		0xE891 
#define 	HYWATT 		0xE892 
#define 	HYVAR 		0xE893 
#define 	HYVA 		0xE894 
#define 	HYPF 		0xE895 
#define 	HYVHD 		0xE896 
#define 	HYIHD 		0xE897 
#define 	HZVRMS 		0xE898 
#define 	HZIRMS 		0xE899 
#define 	HZWATT 		0xE89A 
#define		HZVAR 		0xE89B 
#define 	HZVA 		0xE89C 
#define 	HZPF 		0xE89D 
#define 	HZVHD 		0xE89E 
#define 	HZIHD 		0xE89F 
/** HCONFIG Register Physical address and structure  for harmonics calculation */
//! Description: Harmonic Calculations Configuration 
#define HCONFIG 0xE900 
//! Address: 0xE900 
//! Register Name: HCONFIG
//! R/W: R/W
//! Bit Length: 16 
//! Bit Length During Communication: 16  ZP = 10-bit unsigned register that is transmitted as a 16-bit word with six MSBs padded with 0s. 
//! Type: Unsigned 
//! Default Value: 0x08
#define HCONFIG_DEFAULT 0X08
typedef union
{
    uint16_t		REG_ALL;
    struct
    {
    	uint16_t 	HRCFG 		:1;	/*! HRCFG (Default = 0): When this bit is cleared to 0, the bit 19 (HREADY) interrupt in MASK0 register is triggered 
										after a certain delay period. The delay period is set by bits HSTIME. The update frequency 
										after the settling time is determined by bits HRATE. 
										When this bit is set to 1, the bit 19 (HREADY) interrupt in MASK0 register is triggered starting 
										immediately after the harmonic calculations block has been setup. The update frequency is 
										determined by bits HRATE.
									*/
        uint16_t 	HPHASE 		:2;	/*! HPHASE (Default = 00): These bits decide what phase or neutral is analyzed by the harmonic calculations block.
										00 = Phase A voltage and current. 
										01 = Phase B voltage and current. 
										10 = Phase C voltage and current. 
										11 = neutral current
									*/
    	uint16_t 	HSTIME		:2;	/*! HSTIME (Default = 01): These bits decide the delay period after which, if HRCFG bit is set to 1, bit 19 (HREADY) 
										interrupt in MASK0 register is triggered. 
										00 = 500 ms. 
										01 = 750 ms. 
										10 = 1000 ms. 
										11 = 1250 ms.
									*/
		uint16_t 	HRATE		:3; /*! HRATE (Default = 000): These bits manage the update rate of the harmonic registers. 
										000 = 125 �sec (8 kHz rate). 
										001 = 250 �sec (4 kHz rate). 
										010 = 1 ms (1 kHz rate). 
										011 = 16 ms (62.5 Hz rate). 
										100 = 128 ms (7.8125 Hz rate). 
										101 = 512 ms (1.953125 Hz rate). 
										110 = 1.024 sec (0.9765625 Hz rate). 
										111 = harmonic calculations disabled.
									*/
		uint16_t 	ACTPHSEL	:2;	/*! ACTPHSEL (Default = 00): These bits select the phase voltage used as time base for harmonic calculations. 
										00 = Phase A voltage. 
										01 = Phase B voltage. 
										10 = Phase C voltage. 
										11 = reserved. If selected, phase C voltage is used.
									*/
        uint16_t 	RESERVED	:6;	// Reserved. These bits do not manage any functionality.
		  
    }bits;
}HCONFIG_reg_u;
/* End of HCONFIG */

#define 	APF 		0xE902 
#define 	BPF 		0xE903 
#define 	CPF 		0xE904 
#define 	APERIOD 	0xE905 
#define 	BPERIOD 	0xE906 
#define 	CPERIOD 	0xE907 
#define 	APNOLOAD 	0xE908 
#define 	VARNOLOAD 	0xE909 
#define 	VANOLOAD 	0xE90A 
#define		LAST_ADD	0xE9FE			// The address of the register successfully accessed during the last read/write operation.
#define 	LAST_RWDATA16    0xE9FF		// Contains the data from the last successful 16-bit register communication.

/** CONFIG3 Register Physical address and structure   */
#define 	CONFIG3 	0xEA00 
#define 	CONFIG3_DEFAULT	0x01 		
typedef union
{
	uint8_t REG_ALL;
	struct
	{
		uint8_t 	HPFEN		:1;
		uint8_t 	LPFSEL  	:1;
		uint8_t 	INSEL   	:1;
		uint8_t 	ININTEN	    :1;
		uint8_t 	RESERVED    :1;
		uint8_t 	RESERVED2	:3;
	}bits;
}CONFIG3_reg_u;
/* End of CONFIG3 */

#define 	LAST_OP		0xEA01			// Indicates the type, read or write, of the last successful read/write operation.
// Threshold value registers'
#define 	WTHR 		0xEA02 			// Threshold used in phase total/ fundamental active power data path.
#define 	VARTHR 		0xEA03 			// Threshold used in phase total/ fundamental reactive power data path.
#define 	VATHR 		0xEA04 			// Threshold used in phase apparent power data path.
// Index of harmonics to monitor
#define 	HX 			0xEA08 			// Selects an index X of the harmonic monitored by the harmonic computations.
#define 	HY 			0xEA09 			// Selects an index Y of the harmonic monitored by the harmonic computations. 
#define 	HZ 			0xEA0A 			// Selects an index Z of the harmonic monitored by the harmonic computations. 

/** LPOILVL Register Physical address and structure  */
#define 	LPOILVL 	0xEC00 
typedef union
{
	uint8_t REG_ALL;
	struct
	{
		uint8_t 	LPOIL		:3;
		uint8_t 	LPLINE		:5;
	}bits;
}LPOILVL_reg_u;
/* End of LPOILVL */

/** CONFIG2 Register Physical address and structure    */
#define 	CONFIG2 	0xEC01 
typedef union
{
	uint8_t REG_ALL;
	struct
	{
		uint8_t 	EXTREFEN	:1;
		uint8_t 	I2C_LOCK	:1;
		uint8_t 	RESERVED	:6;
	}bits;
}CONFIG2_reg_u;
/* End of CONFIG2 */

/// A dummy Register
#define 	DUMMY   	0xEBFF  

#endif /* __ADE7880_REGISTERS_H */
