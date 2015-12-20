/*
 * static_model.c
 *
 * automatically generated from motorcontrollerIED_final.icd
 */
#include <stdlib.h>
#include "iec61850_model.h"

extern IedModel iedModel;
static void initializeValues();
extern LogicalDevice iedModel_LDGenerator;
extern LogicalNode   iedModel_LDGenerator_LLN0;
extern DataObject    iedModel_LDGenerator_LLN0_Beh;
extern DataAttribute iedModel_LDGenerator_LLN0_Beh_q;
extern DataAttribute iedModel_LDGenerator_LLN0_Beh_t;
extern DataAttribute iedModel_LDGenerator_LLN0_Beh_stVal;
extern DataObject    iedModel_LDGenerator_LLN0_Health;
extern DataAttribute iedModel_LDGenerator_LLN0_Health_q;
extern DataAttribute iedModel_LDGenerator_LLN0_Health_t;
extern DataAttribute iedModel_LDGenerator_LLN0_Health_stVal;
extern DataObject    iedModel_LDGenerator_LLN0_Mod;
extern DataAttribute iedModel_LDGenerator_LLN0_Mod_q;
extern DataAttribute iedModel_LDGenerator_LLN0_Mod_t;
extern DataAttribute iedModel_LDGenerator_LLN0_Mod_stVal;
extern DataObject    iedModel_LDGenerator_LLN0_NamPlt;
extern DataAttribute iedModel_LDGenerator_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_LDGenerator_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_LDGenerator_LLN0_NamPlt_d;
extern LogicalNode   iedModel_LDGenerator_MMXU1;
extern DataObject    iedModel_LDGenerator_MMXU1_TotW;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotW_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotW_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotW_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotW_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotW_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotW_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotW_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_PPV;
extern DataObject    iedModel_LDGenerator_MMXU1_PPV_phsAB;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_PPV_phsBC;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_PPV_phsCA;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_A;
extern DataObject    iedModel_LDGenerator_MMXU1_A_phsA;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_cVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_cVal_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_cVal_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_A_phsB;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_cVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_cVal_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_cVal_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_A_phsC;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_cVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_cVal_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_cVal_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_Beh;
extern DataAttribute iedModel_LDGenerator_MMXU1_Beh_stVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_Beh_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_Beh_t;
extern DataObject    iedModel_LDGenerator_MMXU1_Health;
extern DataAttribute iedModel_LDGenerator_MMXU1_Health_stVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_Health_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_Health_t;
extern DataObject    iedModel_LDGenerator_MMXU1_Mod;
extern DataAttribute iedModel_LDGenerator_MMXU1_Mod_stVal;
extern DataAttribute iedModel_LDGenerator_MMXU1_Mod_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_Mod_t;
extern DataObject    iedModel_LDGenerator_MMXU1_NamPlt;
extern DataAttribute iedModel_LDGenerator_MMXU1_NamPlt_vendor;
extern DataAttribute iedModel_LDGenerator_MMXU1_NamPlt_swRev;
extern DataAttribute iedModel_LDGenerator_MMXU1_NamPlt_d;
extern DataObject    iedModel_LDGenerator_MMXU1_TotVA;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVA_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVA_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVA_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVA_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVA_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVA_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVA_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_TotVAr;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_units_multiplier;
extern DataObject    iedModel_LDGenerator_MMXU1_TotPF;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotPF_mag;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotPF_mag_f;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotPF_q;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotPF_t;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotPF_units;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotPF_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMXU1_TotPF_units_multiplier;
extern LogicalNode   iedModel_LDGenerator_MMTN1;
extern DataObject    iedModel_LDGenerator_MMTN1_Beh;
extern DataAttribute iedModel_LDGenerator_MMTN1_Beh_q;
extern DataAttribute iedModel_LDGenerator_MMTN1_Beh_t;
extern DataAttribute iedModel_LDGenerator_MMTN1_Beh_stVal;
extern DataObject    iedModel_LDGenerator_MMTN1_TotVAh;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_actVal;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_q;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_t;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_units;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_units_multiplier;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_pulsQty;
extern DataObject    iedModel_LDGenerator_MMTN1_TotWh;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotWh_actVal;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotWh_q;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotWh_t;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotWh_units;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotWh_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotWh_units_multiplier;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotWh_pulsQty;
extern DataObject    iedModel_LDGenerator_MMTN1_TotVArh;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_actVal;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_q;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_t;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_units;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_units_SIUnit;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_units_multiplier;
extern DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_pulsQty;
extern LogicalDevice iedModel_LDMotorIO;
extern LogicalNode   iedModel_LDMotorIO_LLN0;
extern DataObject    iedModel_LDMotorIO_LLN0_Beh;
extern DataAttribute iedModel_LDMotorIO_LLN0_Beh_q;
extern DataAttribute iedModel_LDMotorIO_LLN0_Beh_t;
extern DataAttribute iedModel_LDMotorIO_LLN0_Beh_stVal;
extern DataObject    iedModel_LDMotorIO_LLN0_Health;
extern DataAttribute iedModel_LDMotorIO_LLN0_Health_q;
extern DataAttribute iedModel_LDMotorIO_LLN0_Health_t;
extern DataAttribute iedModel_LDMotorIO_LLN0_Health_stVal;
extern DataObject    iedModel_LDMotorIO_LLN0_Mod;
extern DataAttribute iedModel_LDMotorIO_LLN0_Mod_q;
extern DataAttribute iedModel_LDMotorIO_LLN0_Mod_t;
extern DataAttribute iedModel_LDMotorIO_LLN0_Mod_stVal;
extern DataObject    iedModel_LDMotorIO_LLN0_NamPlt;
extern DataAttribute iedModel_LDMotorIO_LLN0_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_LLN0_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_LLN0_NamPlt_d;
extern LogicalNode   iedModel_LDMotorIO_YLTC1;
extern DataObject    iedModel_LDMotorIO_YLTC1_Torq;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Torq_mag;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Torq_mag_f;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Torq_q;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Torq_t;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Torq_units;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Torq_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Torq_units_multiplier;
extern DataObject    iedModel_LDMotorIO_YLTC1_EndPosR;
extern DataAttribute iedModel_LDMotorIO_YLTC1_EndPosR_stVal;
extern DataAttribute iedModel_LDMotorIO_YLTC1_EndPosR_q;
extern DataAttribute iedModel_LDMotorIO_YLTC1_EndPosR_t;
extern DataObject    iedModel_LDMotorIO_YLTC1_EndPosL;
extern DataAttribute iedModel_LDMotorIO_YLTC1_EndPosL_stVal;
extern DataAttribute iedModel_LDMotorIO_YLTC1_EndPosL_q;
extern DataAttribute iedModel_LDMotorIO_YLTC1_EndPosL_t;
extern DataObject    iedModel_LDMotorIO_YLTC1_Beh;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Beh_stVal;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Beh_q;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Beh_t;
extern DataObject    iedModel_LDMotorIO_YLTC1_Mod;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Mod_stVal;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Mod_q;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Mod_t;
extern DataObject    iedModel_LDMotorIO_YLTC1_NamPlt;
extern DataAttribute iedModel_LDMotorIO_YLTC1_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_YLTC1_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_YLTC1_NamPlt_d;
extern DataObject    iedModel_LDMotorIO_YLTC1_Health;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Health_stVal;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Health_q;
extern DataAttribute iedModel_LDMotorIO_YLTC1_Health_t;
extern LogicalNode   iedModel_LDMotorIO_SIML1;
extern DataObject    iedModel_LDMotorIO_SIML1_TMP;
extern DataAttribute iedModel_LDMotorIO_SIML1_TMP_mag;
extern DataAttribute iedModel_LDMotorIO_SIML1_TMP_mag_f;
extern DataAttribute iedModel_LDMotorIO_SIML1_TMP_q;
extern DataAttribute iedModel_LDMotorIO_SIML1_TMP_t;
extern DataAttribute iedModel_LDMotorIO_SIML1_TMP_units;
extern DataAttribute iedModel_LDMotorIO_SIML1_TMP_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_SIML1_TMP_units_multiplier;
extern DataObject    iedModel_LDMotorIO_SIML1_InsAlm;
extern DataAttribute iedModel_LDMotorIO_SIML1_InsAlm_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML1_InsAlm_q;
extern DataAttribute iedModel_LDMotorIO_SIML1_InsAlm_t;
extern DataObject    iedModel_LDMotorIO_SIML1_Beh;
extern DataAttribute iedModel_LDMotorIO_SIML1_Beh_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML1_Beh_q;
extern DataAttribute iedModel_LDMotorIO_SIML1_Beh_t;
extern DataObject    iedModel_LDMotorIO_SIML1_Mod;
extern DataAttribute iedModel_LDMotorIO_SIML1_Mod_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML1_Mod_q;
extern DataAttribute iedModel_LDMotorIO_SIML1_Mod_t;
extern DataObject    iedModel_LDMotorIO_SIML1_Health;
extern DataAttribute iedModel_LDMotorIO_SIML1_Health_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML1_Health_q;
extern DataAttribute iedModel_LDMotorIO_SIML1_Health_t;
extern DataObject    iedModel_LDMotorIO_SIML1_NamPlt;
extern DataAttribute iedModel_LDMotorIO_SIML1_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_SIML1_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_SIML1_NamPlt_d;
extern LogicalNode   iedModel_LDMotorIO_SIML2;
extern DataObject    iedModel_LDMotorIO_SIML2_TMP;
extern DataAttribute iedModel_LDMotorIO_SIML2_TMP_mag;
extern DataAttribute iedModel_LDMotorIO_SIML2_TMP_mag_f;
extern DataAttribute iedModel_LDMotorIO_SIML2_TMP_q;
extern DataAttribute iedModel_LDMotorIO_SIML2_TMP_t;
extern DataAttribute iedModel_LDMotorIO_SIML2_TMP_units;
extern DataAttribute iedModel_LDMotorIO_SIML2_TMP_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_SIML2_TMP_units_multiplier;
extern DataObject    iedModel_LDMotorIO_SIML2_InsAlm;
extern DataAttribute iedModel_LDMotorIO_SIML2_InsAlm_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML2_InsAlm_q;
extern DataAttribute iedModel_LDMotorIO_SIML2_InsAlm_t;
extern DataObject    iedModel_LDMotorIO_SIML2_Beh;
extern DataAttribute iedModel_LDMotorIO_SIML2_Beh_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML2_Beh_q;
extern DataAttribute iedModel_LDMotorIO_SIML2_Beh_t;
extern DataObject    iedModel_LDMotorIO_SIML2_Mod;
extern DataAttribute iedModel_LDMotorIO_SIML2_Mod_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML2_Mod_q;
extern DataAttribute iedModel_LDMotorIO_SIML2_Mod_t;
extern DataObject    iedModel_LDMotorIO_SIML2_Health;
extern DataAttribute iedModel_LDMotorIO_SIML2_Health_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML2_Health_q;
extern DataAttribute iedModel_LDMotorIO_SIML2_Health_t;
extern DataObject    iedModel_LDMotorIO_SIML2_NamPlt;
extern DataAttribute iedModel_LDMotorIO_SIML2_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_SIML2_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_SIML2_NamPlt_d;
extern LogicalNode   iedModel_LDMotorIO_SIML3;
extern DataObject    iedModel_LDMotorIO_SIML3_TMP;
extern DataAttribute iedModel_LDMotorIO_SIML3_TMP_mag;
extern DataAttribute iedModel_LDMotorIO_SIML3_TMP_mag_f;
extern DataAttribute iedModel_LDMotorIO_SIML3_TMP_q;
extern DataAttribute iedModel_LDMotorIO_SIML3_TMP_t;
extern DataAttribute iedModel_LDMotorIO_SIML3_TMP_units;
extern DataAttribute iedModel_LDMotorIO_SIML3_TMP_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_SIML3_TMP_units_multiplier;
extern DataObject    iedModel_LDMotorIO_SIML3_InsAlm;
extern DataAttribute iedModel_LDMotorIO_SIML3_InsAlm_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML3_InsAlm_q;
extern DataAttribute iedModel_LDMotorIO_SIML3_InsAlm_t;
extern DataObject    iedModel_LDMotorIO_SIML3_Beh;
extern DataAttribute iedModel_LDMotorIO_SIML3_Beh_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML3_Beh_q;
extern DataAttribute iedModel_LDMotorIO_SIML3_Beh_t;
extern DataObject    iedModel_LDMotorIO_SIML3_Mod;
extern DataAttribute iedModel_LDMotorIO_SIML3_Mod_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML3_Mod_q;
extern DataAttribute iedModel_LDMotorIO_SIML3_Mod_t;
extern DataObject    iedModel_LDMotorIO_SIML3_Health;
extern DataAttribute iedModel_LDMotorIO_SIML3_Health_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML3_Health_q;
extern DataAttribute iedModel_LDMotorIO_SIML3_Health_t;
extern DataObject    iedModel_LDMotorIO_SIML3_NamPlt;
extern DataAttribute iedModel_LDMotorIO_SIML3_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_SIML3_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_SIML3_NamPlt_d;
extern LogicalNode   iedModel_LDMotorIO_SIML4;
extern DataObject    iedModel_LDMotorIO_SIML4_TMP;
extern DataAttribute iedModel_LDMotorIO_SIML4_TMP_mag;
extern DataAttribute iedModel_LDMotorIO_SIML4_TMP_mag_f;
extern DataAttribute iedModel_LDMotorIO_SIML4_TMP_q;
extern DataAttribute iedModel_LDMotorIO_SIML4_TMP_t;
extern DataAttribute iedModel_LDMotorIO_SIML4_TMP_units;
extern DataAttribute iedModel_LDMotorIO_SIML4_TMP_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_SIML4_TMP_units_multiplier;
extern DataObject    iedModel_LDMotorIO_SIML4_InsAlm;
extern DataAttribute iedModel_LDMotorIO_SIML4_InsAlm_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML4_InsAlm_q;
extern DataAttribute iedModel_LDMotorIO_SIML4_InsAlm_t;
extern DataObject    iedModel_LDMotorIO_SIML4_Beh;
extern DataAttribute iedModel_LDMotorIO_SIML4_Beh_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML4_Beh_q;
extern DataAttribute iedModel_LDMotorIO_SIML4_Beh_t;
extern DataObject    iedModel_LDMotorIO_SIML4_Mod;
extern DataAttribute iedModel_LDMotorIO_SIML4_Mod_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML4_Mod_q;
extern DataAttribute iedModel_LDMotorIO_SIML4_Mod_t;
extern DataObject    iedModel_LDMotorIO_SIML4_Health;
extern DataAttribute iedModel_LDMotorIO_SIML4_Health_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML4_Health_q;
extern DataAttribute iedModel_LDMotorIO_SIML4_Health_t;
extern DataObject    iedModel_LDMotorIO_SIML4_NamPlt;
extern DataAttribute iedModel_LDMotorIO_SIML4_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_SIML4_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_SIML4_NamPlt_d;
extern LogicalNode   iedModel_LDMotorIO_SIML5;
extern DataObject    iedModel_LDMotorIO_SIML5_TMP;
extern DataAttribute iedModel_LDMotorIO_SIML5_TMP_mag;
extern DataAttribute iedModel_LDMotorIO_SIML5_TMP_mag_f;
extern DataAttribute iedModel_LDMotorIO_SIML5_TMP_q;
extern DataAttribute iedModel_LDMotorIO_SIML5_TMP_t;
extern DataAttribute iedModel_LDMotorIO_SIML5_TMP_units;
extern DataAttribute iedModel_LDMotorIO_SIML5_TMP_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_SIML5_TMP_units_multiplier;
extern DataObject    iedModel_LDMotorIO_SIML5_InsAlm;
extern DataAttribute iedModel_LDMotorIO_SIML5_InsAlm_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML5_InsAlm_q;
extern DataAttribute iedModel_LDMotorIO_SIML5_InsAlm_t;
extern DataObject    iedModel_LDMotorIO_SIML5_Beh;
extern DataAttribute iedModel_LDMotorIO_SIML5_Beh_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML5_Beh_q;
extern DataAttribute iedModel_LDMotorIO_SIML5_Beh_t;
extern DataObject    iedModel_LDMotorIO_SIML5_Mod;
extern DataAttribute iedModel_LDMotorIO_SIML5_Mod_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML5_Mod_q;
extern DataAttribute iedModel_LDMotorIO_SIML5_Mod_t;
extern DataObject    iedModel_LDMotorIO_SIML5_Health;
extern DataAttribute iedModel_LDMotorIO_SIML5_Health_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML5_Health_q;
extern DataAttribute iedModel_LDMotorIO_SIML5_Health_t;
extern DataObject    iedModel_LDMotorIO_SIML5_NamPlt;
extern DataAttribute iedModel_LDMotorIO_SIML5_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_SIML5_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_SIML5_NamPlt_d;
extern LogicalNode   iedModel_LDMotorIO_SIML6;
extern DataObject    iedModel_LDMotorIO_SIML6_TMP;
extern DataAttribute iedModel_LDMotorIO_SIML6_TMP_mag;
extern DataAttribute iedModel_LDMotorIO_SIML6_TMP_mag_f;
extern DataAttribute iedModel_LDMotorIO_SIML6_TMP_q;
extern DataAttribute iedModel_LDMotorIO_SIML6_TMP_t;
extern DataAttribute iedModel_LDMotorIO_SIML6_TMP_units;
extern DataAttribute iedModel_LDMotorIO_SIML6_TMP_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_SIML6_TMP_units_multiplier;
extern DataObject    iedModel_LDMotorIO_SIML6_InsAlm;
extern DataAttribute iedModel_LDMotorIO_SIML6_InsAlm_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML6_InsAlm_q;
extern DataAttribute iedModel_LDMotorIO_SIML6_InsAlm_t;
extern DataObject    iedModel_LDMotorIO_SIML6_Beh;
extern DataAttribute iedModel_LDMotorIO_SIML6_Beh_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML6_Beh_q;
extern DataAttribute iedModel_LDMotorIO_SIML6_Beh_t;
extern DataObject    iedModel_LDMotorIO_SIML6_Mod;
extern DataAttribute iedModel_LDMotorIO_SIML6_Mod_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML6_Mod_q;
extern DataAttribute iedModel_LDMotorIO_SIML6_Mod_t;
extern DataObject    iedModel_LDMotorIO_SIML6_Health;
extern DataAttribute iedModel_LDMotorIO_SIML6_Health_stVal;
extern DataAttribute iedModel_LDMotorIO_SIML6_Health_q;
extern DataAttribute iedModel_LDMotorIO_SIML6_Health_t;
extern DataObject    iedModel_LDMotorIO_SIML6_NamPlt;
extern DataAttribute iedModel_LDMotorIO_SIML6_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_SIML6_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_SIML6_NamPlt_d;
extern LogicalNode   iedModel_LDMotorIO_SIMG1;
extern DataObject    iedModel_LDMotorIO_SIMG1_InsAlm;
extern DataAttribute iedModel_LDMotorIO_SIMG1_InsAlm_stVal;
extern DataAttribute iedModel_LDMotorIO_SIMG1_InsAlm_q;
extern DataAttribute iedModel_LDMotorIO_SIMG1_InsAlm_t;
extern DataObject    iedModel_LDMotorIO_SIMG1_InsLevMin;
extern DataAttribute iedModel_LDMotorIO_SIMG1_InsLevMin_stVal;
extern DataAttribute iedModel_LDMotorIO_SIMG1_InsLevMin_q;
extern DataAttribute iedModel_LDMotorIO_SIMG1_InsLevMin_t;
extern DataObject    iedModel_LDMotorIO_SIMG1_Beh;
extern DataAttribute iedModel_LDMotorIO_SIMG1_Beh_stVal;
extern DataAttribute iedModel_LDMotorIO_SIMG1_Beh_q;
extern DataAttribute iedModel_LDMotorIO_SIMG1_Beh_t;
extern DataObject    iedModel_LDMotorIO_SIMG1_NamPlt;
extern DataAttribute iedModel_LDMotorIO_SIMG1_NamPlt_vendor;
extern DataAttribute iedModel_LDMotorIO_SIMG1_NamPlt_swRev;
extern DataAttribute iedModel_LDMotorIO_SIMG1_NamPlt_d;
extern LogicalNode   iedModel_LDMotorIO_LPHD1;
extern DataObject    iedModel_LDMotorIO_LPHD1_Proxy;
extern DataAttribute iedModel_LDMotorIO_LPHD1_Proxy_stVal;
extern DataAttribute iedModel_LDMotorIO_LPHD1_Proxy_q;
extern DataAttribute iedModel_LDMotorIO_LPHD1_Proxy_t;
extern DataObject    iedModel_LDMotorIO_LPHD1_PwrUp;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PwrUp_stVal;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PwrUp_q;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PwrUp_t;
extern DataObject    iedModel_LDMotorIO_LPHD1_PwrDn;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PwrDn_stVal;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PwrDn_q;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PwrDn_t;
extern DataObject    iedModel_LDMotorIO_LPHD1_PhyHealth;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PhyHealth_q;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PhyHealth_t;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PhyHealth_stVal;
extern DataObject    iedModel_LDMotorIO_LPHD1_PhyNam;
extern DataAttribute iedModel_LDMotorIO_LPHD1_PhyNam_vendor;
extern LogicalNode   iedModel_LDMotorIO_GGIO1;
extern DataObject    iedModel_LDMotorIO_GGIO1_Alm1;
extern DataAttribute iedModel_LDMotorIO_GGIO1_Alm1_stVal;
extern DataAttribute iedModel_LDMotorIO_GGIO1_Alm1_q;
extern DataAttribute iedModel_LDMotorIO_GGIO1_Alm1_t;
extern DataObject    iedModel_LDMotorIO_GGIO1_Beh;
extern DataAttribute iedModel_LDMotorIO_GGIO1_Beh_q;
extern DataAttribute iedModel_LDMotorIO_GGIO1_Beh_t;
extern DataAttribute iedModel_LDMotorIO_GGIO1_Beh_stVal;
extern LogicalNode   iedModel_LDMotorIO_GGIO2;
extern DataObject    iedModel_LDMotorIO_GGIO2_Alm1;
extern DataAttribute iedModel_LDMotorIO_GGIO2_Alm1_stVal;
extern DataAttribute iedModel_LDMotorIO_GGIO2_Alm1_q;
extern DataAttribute iedModel_LDMotorIO_GGIO2_Alm1_t;
extern DataObject    iedModel_LDMotorIO_GGIO2_Beh;
extern DataAttribute iedModel_LDMotorIO_GGIO2_Beh_q;
extern DataAttribute iedModel_LDMotorIO_GGIO2_Beh_t;
extern DataAttribute iedModel_LDMotorIO_GGIO2_Beh_stVal;
extern LogicalNode   iedModel_LDMotorIO_GGIO3;
extern DataObject    iedModel_LDMotorIO_GGIO3_Alm1;
extern DataAttribute iedModel_LDMotorIO_GGIO3_Alm1_stVal;
extern DataAttribute iedModel_LDMotorIO_GGIO3_Alm1_q;
extern DataAttribute iedModel_LDMotorIO_GGIO3_Alm1_t;
extern DataObject    iedModel_LDMotorIO_GGIO3_Beh;
extern DataAttribute iedModel_LDMotorIO_GGIO3_Beh_q;
extern DataAttribute iedModel_LDMotorIO_GGIO3_Beh_t;
extern DataAttribute iedModel_LDMotorIO_GGIO3_Beh_stVal;
extern LogicalNode   iedModel_LDMotorIO_GGIO4;
extern DataObject    iedModel_LDMotorIO_GGIO4_Alm1;
extern DataAttribute iedModel_LDMotorIO_GGIO4_Alm1_stVal;
extern DataAttribute iedModel_LDMotorIO_GGIO4_Alm1_q;
extern DataAttribute iedModel_LDMotorIO_GGIO4_Alm1_t;
extern DataObject    iedModel_LDMotorIO_GGIO4_Beh;
extern DataAttribute iedModel_LDMotorIO_GGIO4_Beh_q;
extern DataAttribute iedModel_LDMotorIO_GGIO4_Beh_t;
extern DataAttribute iedModel_LDMotorIO_GGIO4_Beh_stVal;
extern LogicalNode   iedModel_LDMotorIO_TRTN1;
extern DataObject    iedModel_LDMotorIO_TRTN1_RotSpdSv;
extern DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_instMag;
extern DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_instMag_f;
extern DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_q;
extern DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_t;
extern DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_units;
extern DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_units_multiplier;
extern DataObject    iedModel_LDMotorIO_TRTN1_Beh;
extern DataAttribute iedModel_LDMotorIO_TRTN1_Beh_q;
extern DataAttribute iedModel_LDMotorIO_TRTN1_Beh_t;
extern DataAttribute iedModel_LDMotorIO_TRTN1_Beh_stVal;
extern LogicalNode   iedModel_LDMotorIO_TFLW1;
extern DataObject    iedModel_LDMotorIO_TFLW1_FlwSv;
extern DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_instMag;
extern DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_instMag_f;
extern DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_q;
extern DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_t;
extern DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_units;
extern DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_units_multiplier;
extern DataObject    iedModel_LDMotorIO_TFLW1_Beh;
extern DataAttribute iedModel_LDMotorIO_TFLW1_Beh_q;
extern DataAttribute iedModel_LDMotorIO_TFLW1_Beh_t;
extern DataAttribute iedModel_LDMotorIO_TFLW1_Beh_stVal;
extern LogicalNode   iedModel_LDMotorIO_TFLW2;
extern DataObject    iedModel_LDMotorIO_TFLW2_FlwSv;
extern DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_instMag;
extern DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_instMag_f;
extern DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_q;
extern DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_t;
extern DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_units;
extern DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_units_multiplier;
extern DataObject    iedModel_LDMotorIO_TFLW2_Beh;
extern DataAttribute iedModel_LDMotorIO_TFLW2_Beh_q;
extern DataAttribute iedModel_LDMotorIO_TFLW2_Beh_t;
extern DataAttribute iedModel_LDMotorIO_TFLW2_Beh_stVal;
extern LogicalNode   iedModel_LDMotorIO_TFLW3;
extern DataObject    iedModel_LDMotorIO_TFLW3_FlwSv;
extern DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_instMag;
extern DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_instMag_f;
extern DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_q;
extern DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_t;
extern DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_units;
extern DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_units_SIUnit;
extern DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_units_multiplier;
extern DataObject    iedModel_LDMotorIO_TFLW3_Beh;
extern DataAttribute iedModel_LDMotorIO_TFLW3_Beh_q;
extern DataAttribute iedModel_LDMotorIO_TFLW3_Beh_t;
extern DataAttribute iedModel_LDMotorIO_TFLW3_Beh_stVal;



LogicalDevice iedModel_LDGenerator = {
    LogicalDeviceModelType,
    "LDGenerator",
    (ModelNode*) &iedModel,
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDGenerator_LLN0
};

LogicalNode iedModel_LDGenerator_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_LDGenerator,
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Beh,
};

DataObject iedModel_LDGenerator_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDGenerator_LLN0,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Health,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Beh_q,
    0
};

DataAttribute iedModel_LDGenerator_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Beh,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Beh,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDGenerator_LLN0,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Mod,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Health_q,
    0
};

DataAttribute iedModel_LDGenerator_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Health,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Health,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Health_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Health,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDGenerator_LLN0,
    (ModelNode*) &iedModel_LDGenerator_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Mod_q,
    0
};

DataAttribute iedModel_LDGenerator_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Mod,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Mod,
    (ModelNode*) &iedModel_LDGenerator_LLN0_Mod_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDGenerator_LLN0_Mod,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LDGenerator_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDGenerator_LLN0,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_LLN0_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDGenerator_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDGenerator_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDGenerator_LLN0_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDGenerator_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDGenerator_LLN0_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDGenerator_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDGenerator_MMXU1 = {
    LogicalNodeModelType,
    "MMXU1",
    (ModelNode*) &iedModel_LDGenerator,
    (ModelNode*) &iedModel_LDGenerator_MMTN1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW,
};

DataObject iedModel_LDGenerator_MMXU1_TotW = {
    DataObjectModelType,
    "TotW",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_mag,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_TotW_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotW_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotW_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotW_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotW_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotW_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotW_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotW_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_PPV = {
    DataObjectModelType,
    "PPV",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB,
    0
};

DataObject iedModel_LDGenerator_MMXU1_PPV_phsAB = {
    DataObjectModelType,
    "phsAB",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal_mag,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_cVal_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsAB_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsAB_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_PPV_phsBC = {
    DataObjectModelType,
    "phsBC",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal_mag,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_cVal_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsBC_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsBC_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_PPV_phsCA = {
    DataObjectModelType,
    "phsCA",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal_mag,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_cVal_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_PPV_phsCA_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_PPV_phsCA_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_A = {
    DataObjectModelType,
    "A",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Beh,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA,
    0
};

DataObject iedModel_LDGenerator_MMXU1_A_phsA = {
    DataObjectModelType,
    "phsA",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_cVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_cVal_mag,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_cVal,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_cVal_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_cVal_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsA_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsA_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_A_phsB = {
    DataObjectModelType,
    "phsB",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_cVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_cVal_mag,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_cVal,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_cVal_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_cVal_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsB_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsB_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_A_phsC = {
    DataObjectModelType,
    "phsC",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_cVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_cVal = {
    DataAttributeModelType,
    "cVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_cVal_mag,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_cVal_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_cVal,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_cVal_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_cVal_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_cVal_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_A_phsC_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_A_phsC_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Health,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Beh_stVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Beh,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Beh,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Mod,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Health_stVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Health,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Health_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Health,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_NamPlt,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Mod_stVal,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Mod,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Mod_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Mod,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_Mod,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_NamPlt,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_NamPlt,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_TotVA = {
    DataObjectModelType,
    "TotVA",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_mag,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_TotVA_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVA_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVA_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVA_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVA_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVA_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVA_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVA_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_TotVAr = {
    DataObjectModelType,
    "TotVAr",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_mag,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotVAr_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotVAr_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMXU1_TotPF = {
    DataObjectModelType,
    "TotPF",
    (ModelNode*) &iedModel_LDGenerator_MMXU1,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_mag,
    0
};

DataAttribute iedModel_LDGenerator_MMXU1_TotPF_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_q,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotPF_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotPF_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotPF_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotPF_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotPF_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_units,
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMXU1_TotPF_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMXU1_TotPF_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

LogicalNode iedModel_LDGenerator_MMTN1 = {
    LogicalNodeModelType,
    "MMTN1",
    (ModelNode*) &iedModel_LDGenerator,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_Beh,
};

DataObject iedModel_LDGenerator_MMTN1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDGenerator_MMTN1,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_Beh_q,
    0
};

DataAttribute iedModel_LDGenerator_MMTN1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_Beh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_Beh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMTN1_TotVAh = {
    DataObjectModelType,
    "TotVAh",
    (ModelNode*) &iedModel_LDGenerator_MMTN1,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_actVal,
    0
};

DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_q,
    NULL,
    0,
    ST,
    INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_units,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_pulsQty,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_units,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVAh_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVAh,
    NULL,
    NULL,
    0,
    CF,
    FLOAT32,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMTN1_TotWh = {
    DataObjectModelType,
    "TotWh",
    (ModelNode*) &iedModel_LDGenerator_MMTN1,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_actVal,
    0
};

DataAttribute iedModel_LDGenerator_MMTN1_TotWh_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_q,
    NULL,
    0,
    ST,
    INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotWh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotWh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_units,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotWh_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_pulsQty,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotWh_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_units,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotWh_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotWh_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotWh,
    NULL,
    NULL,
    0,
    CF,
    FLOAT32,
    0,
    NULL,
    0};

DataObject iedModel_LDGenerator_MMTN1_TotVArh = {
    DataObjectModelType,
    "TotVArh",
    (ModelNode*) &iedModel_LDGenerator_MMTN1,
    NULL,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_actVal,
    0
};

DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_actVal = {
    DataAttributeModelType,
    "actVal",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_q,
    NULL,
    0,
    ST,
    INT64,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_units,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_pulsQty,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_units,
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDGenerator_MMTN1_TotVArh_pulsQty = {
    DataAttributeModelType,
    "pulsQty",
    (ModelNode*) &iedModel_LDGenerator_MMTN1_TotVArh,
    NULL,
    NULL,
    0,
    CF,
    FLOAT32,
    0,
    NULL,
    0};


LogicalDevice iedModel_LDMotorIO = {
    LogicalDeviceModelType,
    "LDMotorIO",
    (ModelNode*) &iedModel,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_LLN0
};

LogicalNode iedModel_LDMotorIO_LLN0 = {
    LogicalNodeModelType,
    "LLN0",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Beh,
};

DataObject iedModel_LDMotorIO_LLN0_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_LLN0,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Health,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_LLN0_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Beh,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LLN0_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Beh,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LLN0_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_LLN0_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDMotorIO_LLN0,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Mod,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Health_q,
    0
};

DataAttribute iedModel_LDMotorIO_LLN0_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Health,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LLN0_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Health,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Health_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LLN0_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Health,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_LLN0_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDMotorIO_LLN0,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Mod_q,
    0
};

DataAttribute iedModel_LDMotorIO_LLN0_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Mod,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LLN0_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Mod,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Mod_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LLN0_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_Mod,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataObject iedModel_LDMotorIO_LLN0_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_LLN0,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_LLN0_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LLN0_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_LLN0_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LLN0_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_LLN0_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_YLTC1 = {
    LogicalNodeModelType,
    "YLTC1",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_SIML1,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq,
};

DataObject iedModel_LDMotorIO_YLTC1_Torq = {
    DataObjectModelType,
    "Torq",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosR,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_mag,
    0
};

DataAttribute iedModel_LDMotorIO_YLTC1_Torq_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_q,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Torq_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Torq_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Torq_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Torq_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Torq_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_units,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Torq_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Torq_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_YLTC1_EndPosR = {
    DataObjectModelType,
    "EndPosR",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosL,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosR_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_YLTC1_EndPosR_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosR,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosR_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_EndPosR_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosR,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosR_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_EndPosR_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosR,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_YLTC1_EndPosL = {
    DataObjectModelType,
    "EndPosL",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosL_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_YLTC1_EndPosL_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosL,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosL_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_EndPosL_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosL,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosL_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_EndPosL_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_EndPosL,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_YLTC1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Mod,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Beh_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_YLTC1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_YLTC1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Mod_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_YLTC1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Mod,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Mod_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Mod,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Mod,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_YLTC1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Health,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_YLTC1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_YLTC1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Health_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_YLTC1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Health,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Health_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Health,
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_YLTC1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_YLTC1_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_SIML1 = {
    LogicalNodeModelType,
    "SIML1",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_SIML2,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP,
};

DataObject iedModel_LDMotorIO_SIML1_TMP = {
    DataObjectModelType,
    "TMP",
    (ModelNode*) &iedModel_LDMotorIO_SIML1,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_mag,
    0
};

DataAttribute iedModel_LDMotorIO_SIML1_TMP_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_q,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_TMP_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_TMP_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_TMP_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_TMP_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_TMP_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_units,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_TMP_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_TMP_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML1_InsAlm = {
    DataObjectModelType,
    "InsAlm",
    (ModelNode*) &iedModel_LDMotorIO_SIML1,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_InsAlm_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML1_InsAlm_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_InsAlm_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_InsAlm_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_InsAlm_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_InsAlm_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_InsAlm,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_SIML1,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Beh_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML1_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDMotorIO_SIML1,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Mod_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML1_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Mod_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Mod,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML1_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDMotorIO_SIML1,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Health_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML1_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Health_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_SIML1,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_SIML1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML1_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_SIML1_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_SIML2 = {
    LogicalNodeModelType,
    "SIML2",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_SIML3,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP,
};

DataObject iedModel_LDMotorIO_SIML2_TMP = {
    DataObjectModelType,
    "TMP",
    (ModelNode*) &iedModel_LDMotorIO_SIML2,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_mag,
    0
};

DataAttribute iedModel_LDMotorIO_SIML2_TMP_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_q,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_TMP_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_TMP_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_TMP_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_TMP_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_TMP_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_units,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_TMP_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_TMP_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML2_InsAlm = {
    DataObjectModelType,
    "InsAlm",
    (ModelNode*) &iedModel_LDMotorIO_SIML2,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_InsAlm_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML2_InsAlm_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_InsAlm_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_InsAlm_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_InsAlm_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_InsAlm_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_InsAlm,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML2_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_SIML2,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Beh_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML2_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML2_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDMotorIO_SIML2,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Mod_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML2_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Mod_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Mod,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML2_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDMotorIO_SIML2,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Health_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML2_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Health_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML2_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_SIML2,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_SIML2_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML2_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML2_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_SIML2_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_SIML3 = {
    LogicalNodeModelType,
    "SIML3",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_SIML4,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP,
};

DataObject iedModel_LDMotorIO_SIML3_TMP = {
    DataObjectModelType,
    "TMP",
    (ModelNode*) &iedModel_LDMotorIO_SIML3,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_mag,
    0
};

DataAttribute iedModel_LDMotorIO_SIML3_TMP_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_q,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_TMP_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_TMP_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_TMP_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_TMP_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_TMP_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_units,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_TMP_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_TMP_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML3_InsAlm = {
    DataObjectModelType,
    "InsAlm",
    (ModelNode*) &iedModel_LDMotorIO_SIML3,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_InsAlm_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML3_InsAlm_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_InsAlm_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_InsAlm_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_InsAlm_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_InsAlm_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_InsAlm,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML3_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_SIML3,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Beh_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML3_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML3_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDMotorIO_SIML3,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Mod_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML3_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Mod_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Mod,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML3_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDMotorIO_SIML3,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Health_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML3_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Health_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML3_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_SIML3,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_SIML3_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML3_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML3_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_SIML3_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_SIML4 = {
    LogicalNodeModelType,
    "SIML4",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_SIML5,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP,
};

DataObject iedModel_LDMotorIO_SIML4_TMP = {
    DataObjectModelType,
    "TMP",
    (ModelNode*) &iedModel_LDMotorIO_SIML4,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_mag,
    0
};

DataAttribute iedModel_LDMotorIO_SIML4_TMP_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_q,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_TMP_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_TMP_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_TMP_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_TMP_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_TMP_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_units,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_TMP_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_TMP_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML4_InsAlm = {
    DataObjectModelType,
    "InsAlm",
    (ModelNode*) &iedModel_LDMotorIO_SIML4,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_InsAlm_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML4_InsAlm_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_InsAlm_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_InsAlm_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_InsAlm_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_InsAlm_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_InsAlm,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML4_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_SIML4,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Beh_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML4_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML4_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDMotorIO_SIML4,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Mod_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML4_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Mod_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Mod,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML4_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDMotorIO_SIML4,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Health_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML4_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Health_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML4_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_SIML4,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_SIML4_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML4_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML4_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_SIML4_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_SIML5 = {
    LogicalNodeModelType,
    "SIML5",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_SIML6,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP,
};

DataObject iedModel_LDMotorIO_SIML5_TMP = {
    DataObjectModelType,
    "TMP",
    (ModelNode*) &iedModel_LDMotorIO_SIML5,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_mag,
    0
};

DataAttribute iedModel_LDMotorIO_SIML5_TMP_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_q,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_TMP_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_TMP_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_TMP_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_TMP_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_TMP_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_units,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_TMP_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_TMP_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML5_InsAlm = {
    DataObjectModelType,
    "InsAlm",
    (ModelNode*) &iedModel_LDMotorIO_SIML5,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_InsAlm_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML5_InsAlm_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_InsAlm_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_InsAlm_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_InsAlm_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_InsAlm_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_InsAlm,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML5_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_SIML5,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Beh_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML5_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML5_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDMotorIO_SIML5,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Mod_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML5_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Mod_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Mod,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML5_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDMotorIO_SIML5,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Health_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML5_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Health_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML5_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_SIML5,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_SIML5_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML5_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML5_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_SIML5_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_SIML6 = {
    LogicalNodeModelType,
    "SIML6",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP,
};

DataObject iedModel_LDMotorIO_SIML6_TMP = {
    DataObjectModelType,
    "TMP",
    (ModelNode*) &iedModel_LDMotorIO_SIML6,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_mag,
    0
};

DataAttribute iedModel_LDMotorIO_SIML6_TMP_mag = {
    DataAttributeModelType,
    "mag",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_q,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_mag_f,
    0,
    MX,
    CONSTRUCTED,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_TMP_mag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_mag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_TMP_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_TMP_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_TMP_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_TMP_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_units,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_TMP_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_TMP_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML6_InsAlm = {
    DataObjectModelType,
    "InsAlm",
    (ModelNode*) &iedModel_LDMotorIO_SIML6,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_InsAlm_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML6_InsAlm_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_InsAlm_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_InsAlm_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_InsAlm_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_InsAlm_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_InsAlm,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML6_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_SIML6,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Beh_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML6_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML6_Mod = {
    DataObjectModelType,
    "Mod",
    (ModelNode*) &iedModel_LDMotorIO_SIML6,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Mod_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML6_Mod_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Mod_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_Mod_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Mod,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Mod_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_Mod_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Mod,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML6_Health = {
    DataObjectModelType,
    "Health",
    (ModelNode*) &iedModel_LDMotorIO_SIML6,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Health_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIML6_Health_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Health_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_Health_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Health,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Health_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_Health_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_Health,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIML6_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_SIML6,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_SIML6_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIML6_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIML6_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_SIML6_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_SIMG1 = {
    LogicalNodeModelType,
    "SIMG1",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsAlm,
};

DataObject iedModel_LDMotorIO_SIMG1_InsAlm = {
    DataObjectModelType,
    "InsAlm",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsLevMin,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsAlm_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIMG1_InsAlm_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsAlm_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIMG1_InsAlm_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsAlm,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsAlm_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIMG1_InsAlm_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsAlm,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIMG1_InsLevMin = {
    DataObjectModelType,
    "InsLevMin",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsLevMin_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIMG1_InsLevMin_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsLevMin,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsLevMin_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIMG1_InsLevMin_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsLevMin,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsLevMin_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIMG1_InsLevMin_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_InsLevMin,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIMG1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_Beh_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_SIMG1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_Beh_q,
    NULL,
    0,
    ST,
    INT32,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIMG1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIMG1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_Beh,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_SIMG1_NamPlt = {
    DataObjectModelType,
    "NamPlt",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_NamPlt_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_SIMG1_NamPlt_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_NamPlt_swRev,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIMG1_NamPlt_swRev = {
    DataAttributeModelType,
    "swRev",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_NamPlt,
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_NamPlt_d,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_SIMG1_NamPlt_d = {
    DataAttributeModelType,
    "d",
    (ModelNode*) &iedModel_LDMotorIO_SIMG1_NamPlt,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_LPHD1 = {
    LogicalNodeModelType,
    "LPHD1",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_Proxy,
};

DataObject iedModel_LDMotorIO_LPHD1_Proxy = {
    DataObjectModelType,
    "Proxy",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrUp,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_Proxy_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_LPHD1_Proxy_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_Proxy_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LPHD1_Proxy_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_Proxy,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_Proxy_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LPHD1_Proxy_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_Proxy,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_LPHD1_PwrUp = {
    DataObjectModelType,
    "PwrUp",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrDn,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrUp_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_LPHD1_PwrUp_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrUp,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrUp_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LPHD1_PwrUp_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrUp,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrUp_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LPHD1_PwrUp_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrUp,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_LPHD1_PwrDn = {
    DataObjectModelType,
    "PwrDn",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrDn_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_LPHD1_PwrDn_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrDn,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrDn_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LPHD1_PwrDn_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrDn,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrDn_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LPHD1_PwrDn_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PwrDn,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_LPHD1_PhyHealth = {
    DataObjectModelType,
    "PhyHealth",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyNam,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyHealth_q,
    0
};

DataAttribute iedModel_LDMotorIO_LPHD1_PhyHealth_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyHealth_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LPHD1_PhyHealth_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyHealth,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyHealth_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_LPHD1_PhyHealth_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyHealth,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_LPHD1_PhyNam = {
    DataObjectModelType,
    "PhyNam",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyNam_vendor,
    0
};

DataAttribute iedModel_LDMotorIO_LPHD1_PhyNam_vendor = {
    DataAttributeModelType,
    "vendor",
    (ModelNode*) &iedModel_LDMotorIO_LPHD1_PhyNam,
    NULL,
    NULL,
    0,
    DC,
    VISIBLE_STRING_255,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_GGIO1 = {
    LogicalNodeModelType,
    "GGIO1",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Alm1,
};

DataObject iedModel_LDMotorIO_GGIO1_Alm1 = {
    DataObjectModelType,
    "Alm1",
    (ModelNode*) &iedModel_LDMotorIO_GGIO1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Alm1_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_GGIO1_Alm1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Alm1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Alm1_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO1_Alm1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Alm1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Alm1_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO1_Alm1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Alm1,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_GGIO1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_GGIO1,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_GGIO1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_GGIO1_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_GGIO2 = {
    LogicalNodeModelType,
    "GGIO2",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Alm1,
};

DataObject iedModel_LDMotorIO_GGIO2_Alm1 = {
    DataObjectModelType,
    "Alm1",
    (ModelNode*) &iedModel_LDMotorIO_GGIO2,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Alm1_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_GGIO2_Alm1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Alm1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Alm1_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO2_Alm1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Alm1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Alm1_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO2_Alm1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Alm1,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_GGIO2_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_GGIO2,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_GGIO2_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO2_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO2_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_GGIO2_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_GGIO3 = {
    LogicalNodeModelType,
    "GGIO3",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Alm1,
};

DataObject iedModel_LDMotorIO_GGIO3_Alm1 = {
    DataObjectModelType,
    "Alm1",
    (ModelNode*) &iedModel_LDMotorIO_GGIO3,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Alm1_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_GGIO3_Alm1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Alm1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Alm1_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO3_Alm1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Alm1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Alm1_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO3_Alm1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Alm1,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_GGIO3_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_GGIO3,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_GGIO3_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO3_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO3_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_GGIO3_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_GGIO4 = {
    LogicalNodeModelType,
    "GGIO4",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Alm1,
};

DataObject iedModel_LDMotorIO_GGIO4_Alm1 = {
    DataObjectModelType,
    "Alm1",
    (ModelNode*) &iedModel_LDMotorIO_GGIO4,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Alm1_stVal,
    0
};

DataAttribute iedModel_LDMotorIO_GGIO4_Alm1_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Alm1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Alm1_q,
    NULL,
    0,
    ST,
    BOOLEAN,
    0 + TRG_OPT_DATA_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO4_Alm1_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Alm1,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Alm1_t,
    NULL,
    0,
    ST,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO4_Alm1_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Alm1,
    NULL,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_GGIO4_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_GGIO4,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_GGIO4_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO4_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Beh,
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_GGIO4_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_GGIO4_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_TRTN1 = {
    LogicalNodeModelType,
    "TRTN1",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv,
};

DataObject iedModel_LDMotorIO_TRTN1_RotSpdSv = {
    DataObjectModelType,
    "RotSpdSv",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_instMag,
    0
};

DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_instMag = {
    DataAttributeModelType,
    "instMag",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_q,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_instMag_f,
    0,
    MX,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_instMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_instMag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_units,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TRTN1_RotSpdSv_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_RotSpdSv_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_TRTN1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_TRTN1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TRTN1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TRTN1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_TRTN1_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_TFLW1 = {
    LogicalNodeModelType,
    "TFLW1",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv,
};

DataObject iedModel_LDMotorIO_TFLW1_FlwSv = {
    DataObjectModelType,
    "FlwSv",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_instMag,
    0
};

DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_instMag = {
    DataAttributeModelType,
    "instMag",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_q,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_instMag_f,
    0,
    MX,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_instMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_instMag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_units,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW1_FlwSv_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_FlwSv_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_TFLW1_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_TFLW1_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW1_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW1_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_TFLW1_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_TFLW2 = {
    LogicalNodeModelType,
    "TFLW2",
    (ModelNode*) &iedModel_LDMotorIO,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv,
};

DataObject iedModel_LDMotorIO_TFLW2_FlwSv = {
    DataObjectModelType,
    "FlwSv",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_instMag,
    0
};

DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_instMag = {
    DataAttributeModelType,
    "instMag",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_q,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_instMag_f,
    0,
    MX,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_instMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_instMag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_units,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW2_FlwSv_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_FlwSv_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_TFLW2_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_TFLW2_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW2_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW2_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_TFLW2_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};

LogicalNode iedModel_LDMotorIO_TFLW3 = {
    LogicalNodeModelType,
    "TFLW3",
    (ModelNode*) &iedModel_LDMotorIO,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv,
};

DataObject iedModel_LDMotorIO_TFLW3_FlwSv = {
    DataObjectModelType,
    "FlwSv",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_instMag,
    0
};

DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_instMag = {
    DataAttributeModelType,
    "instMag",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_q,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_instMag_f,
    0,
    MX,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_instMag_f = {
    DataAttributeModelType,
    "f",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_instMag,
    NULL,
    NULL,
    0,
    MX,
    FLOAT32,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_t,
    NULL,
    0,
    MX,
    QUALITY,
    0 + TRG_OPT_QUALITY_CHANGED,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_units,
    NULL,
    0,
    MX,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_units = {
    DataAttributeModelType,
    "units",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_units_SIUnit,
    0,
    CF,
    CONSTRUCTED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_units_SIUnit = {
    DataAttributeModelType,
    "SIUnit",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_units,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_units_multiplier,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW3_FlwSv_units_multiplier = {
    DataAttributeModelType,
    "multiplier",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_FlwSv_units,
    NULL,
    NULL,
    0,
    CF,
    ENUMERATED,
    0,
    NULL,
    0};

DataObject iedModel_LDMotorIO_TFLW3_Beh = {
    DataObjectModelType,
    "Beh",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3,
    NULL,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_Beh_q,
    0
};

DataAttribute iedModel_LDMotorIO_TFLW3_Beh_q = {
    DataAttributeModelType,
    "q",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_Beh_t,
    NULL,
    0,
    ST,
    QUALITY,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW3_Beh_t = {
    DataAttributeModelType,
    "t",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_Beh,
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_Beh_stVal,
    NULL,
    0,
    ST,
    TIMESTAMP,
    0,
    NULL,
    0};

DataAttribute iedModel_LDMotorIO_TFLW3_Beh_stVal = {
    DataAttributeModelType,
    "stVal",
    (ModelNode*) &iedModel_LDMotorIO_TFLW3_Beh,
    NULL,
    NULL,
    0,
    ST,
    ENUMERATED,
    0,
    NULL,
    0};






IedModel iedModel = {
    "motorcontrollerIED",
    &iedModel_LDGenerator,
    NULL,
    NULL,
    NULL,
    NULL,
    initializeValues
};

static void
initializeValues()
{
}
