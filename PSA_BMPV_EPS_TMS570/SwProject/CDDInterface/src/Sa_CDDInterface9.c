/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Sa_CDDInterface9.c
 *     Workspace:  C:/SynergyProjects/PSA_BMPV_EPS_TMS570-nzx5jd/PSA_BMPV_EPS_TMS570/Tools/AsrProject/Config/DCF/EPS.dcf
 *     SW-C Type:  Sa_CDDInterface9
 *  Generated at:  Tue Mar 10 14:29:04 2015
 *
 *     Generator:  MICROSAR RTE Generator Version 2.19.1
 *       License:  License CBD1010124 valid for CBD1010124 Nexteer  Package: BMW MSR SIP BAC3.0     Micro: TI TMS570 TMS570LS30306  Compiler: Code Composer Studio 4.9.0
 *
 *   Description:  C-Code implementation template for SW-C <Sa_CDDInterface9>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/* Version Control:
 * %version:          6 %
 * %derived_by:       nzx5jd %
 *---------------------------------------------------------------------------------------------------------------------
 * Date      Rev      Author         Change Description                                                        SCR #
 * -------   -------  --------  ---------------------------------------------------------------------------  ----------
 * 08/29/14   1       OT        Initial Version - based on Sa_CDDInterface.c v5                                12249
 * 09/17/14   2       OT        Added DID 2101 outputs, hard coded to TRUE until implemented                   12259
 * 09/24/14   3       OT        Added STTd output, hard coded to TRUE until implemented                        12260
 * 10/08/14   4       OT        Removed previous outputs, moved to Sa_CDDInterface6.c                          12363
 * 01/20/15   5       OT        Added MechMtrPos1 output for VehDyn v4                                         12867
 * 03/10/15   6       OT        Updates for DigMSB v8                                                          13104
 */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Data Element Prototypes:
 ========================
  Volt_f32 of Port Interface Voltage_Volt_f32
    This signal is intended to communicate any type voltage signal measured by the ecu.  This signal has a lower limit of 0 which reequires users of the signal to provide divide by 0 protection if it is used as a denominator in a calculation.  See Vecu port prototype if a port with a lower limit is desired.

 *********************************************************************************************************************/

#include "Rte_Sa_CDDInterface9.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#include "fixmath.h"
#include "CDD_Data.h"
#include "Nhet.h"
#include "EPS_DiagSrvcs_SrvcLUTbl.h"


#define D_PXACCUMMAX_CNT_U32	536870911UL
#define D_PHSADVSCALE_ULS_F32	(6144.0f/65536.0f)
#define D_HALFREV_CNT_U16		32768U
#define D_FULLREV_CNT_S32		65536L
#define D_PHASEA_CNT_U16		0U
#define D_PHASEB_CNT_U16		1U
#define D_PHASEC_CNT_U16		2U


#define CDDINTERFACE9_START_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */
STATIC VAR(uint32, CDDINTERFACE_VAR_NOINIT) PXAccumPrev_Cnt_M_u32[D_PHASEC_CNT_U16 + 1u];
#define CDDINTERFACE9_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean (standard type)
 * Double: Real in interval [-DBL_MAX...DBL_MAX] with double precision including NaN (standard type)
 * Float: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * SInt16: Integer in interval [-32768...32767] (standard type)
 * SInt32: Integer in interval [-2147483648...2147483647] (standard type)
 * SInt8: Integer in interval [-128...127] (standard type)
 * UInt16: Integer in interval [0...65535] (standard type)
 * UInt32: Integer in interval [0...4294967295] (standard type)
 * UInt8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * ManufModeType: Enumeration of integer in interval [0...2] with enumerators
 *   ProductionMode (0U)
 *   ManufacturingMode (1U)
 *   EngineeringMode (2U)
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Defined Constants
 *
 **********************************************************************************************************************
 *
 * Primitive Type Constants:
 * =========================
 * Boolean: D_FALSE_CNT_LGC = FALSE
 * Boolean: D_TRUE_CNT_LGC = TRUE
 * Double: D_SFINVMILLI_ULS_F32 = 1000
 * Float: D_100MS_SEC_F32 = 0.1F
 * Float: D_180OVRPI_ULS_F32 = 57.295779513082F
 * Float: D_2MS_SEC_F32 = 0.002F
 * Float: D_2PI_ULS_F32 = 6.2831853071796F
 * Float: D_MSECPERSEC_ULS_F32 = 1000.0F
 * Float: D_MTRTRQCMDHILMT_MTRNM_F32 = 8.8F
 * Float: D_MTRTRQCMDLOLMT_MTRNM_F32 = -8.8F
 * Float: D_ONE_ULS_F32 = 1.0F
 * Float: D_PIOVR180_ULS_F32 = 0.0174532925199F
 * Float: D_PI_ULS_F32 = 3.1415926535898F
 * Float: D_RADPERREV_ULS_F32 = 6.28318530718F
 * Float: D_VECUMIN_VOLTS_F32 = 5.0F
 * Float: D_ZERO_ULS_F32 = 0.0F
 * SInt16: D_NEGONE_CNT_S16 = -1
 * SInt16: D_ONE_CNT_S16 = 1
 * SInt16: D_ZERO_CNT_S16 = 0
 * SInt32: D_NEGONE_CNT_S32 = -1
 * SInt32: D_ONE_CNT_S32 = 1
 * SInt32: D_ZERO_CNT_S32 = 0
 * SInt8: D_NEGONE_CNT_S8 = -1
 * SInt8: D_ONE_CNT_S8 = 1
 * SInt8: D_ZERO_CNT_S8 = 0
 * UInt16: D_ONE_CNT_U16 = 1U
 * UInt16: D_ZERO_CNT_U16 = 0U
 * UInt32: D_ONE_CNT_U32 = 1U
 * UInt32: D_ZERO_CNT_U32 = 0U
 * UInt8: D_MTRPOLESDIV2_CNT_U8 = 3U
 * UInt8: D_ONE_CNT_U8 = 1U
 * UInt8: D_QUADRANT1_CNT_U8 = 1U
 * UInt8: D_QUADRANT2_CNT_U8 = 2U
 * UInt8: D_QUADRANT3_CNT_U8 = 3U
 * UInt8: D_QUADRANT4_CNT_U8 = 4U
 * UInt8: D_ZERO_CNT_U8 = 0U
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SA_CDDINTERFACE9_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface9_Init1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface9_Init1_IgnCnt_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Init1_IgnCnt_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Init1_MEC_Cnt_enum(ManufModeType data)
 *   ManufModeType *Rte_IWriteRef_CDDInterface9_Init1_MEC_Cnt_enum(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Init1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface9_Init1
 *********************************************************************************************************************/
	
	
	CDD_CDDDataAccessBfr_Cnt_G_u16 = 0U;
	PXAccumPrev_Cnt_M_u32[D_PHASEA_CNT_U16] = HET_P1ACC_1.memory.data_word >> 3U;
	PXAccumPrev_Cnt_M_u32[D_PHASEB_CNT_U16] = HET_P2ACC_1.memory.data_word >> 3U;
	PXAccumPrev_Cnt_M_u32[D_PHASEC_CNT_U16] = HET_P3ACC_1.memory.data_word >> 3U;
	
	
	Rte_IWrite_CDDInterface9_Init1_IgnCnt_Cnt_u16(Nvm_IgnCntr_Cnt_u16);
	Rte_IWrite_CDDInterface9_Init1_MEC_Cnt_enum(NxtrMEC_Uls_G_enum);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CDDInterface9_Per1
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 2ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Implicit S/R API:
 *   -----------------
 *   void Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_CumMechMtrPos_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_CumMechMtrPos_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die1RxError_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die1RxError_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die2RxError_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die2RxError_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(SInt16 data)
 *   SInt16 *Rte_IWriteRef_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MeasuredOnTimeA_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_MeasuredOnTimeA_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MeasuredOnTimeB_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_MeasuredOnTimeB_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MeasuredOnTimeC_Cnt_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_MeasuredOnTimeC_Cnt_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MechMtrPos1_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos1_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32(UInt32 data)
 *   UInt32 *Rte_IWriteRef_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_ModIdxFinal_Uls_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_ModIdxFinal_Uls_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrDax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrDax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrK1_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrK1_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrK2_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrK2_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrCurrQax_Amp_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrCurrQax_Amp_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrVoltDax_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrVoltDax_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_MtrVoltQax_Volt_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_MtrVoltQax_Volt_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32(Float data)
 *   Float *Rte_IWriteRef_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32(void)
 *   void Rte_IWrite_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16(void)
 *   void Rte_IWrite_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16(UInt16 data)
 *   UInt16 *Rte_IWriteRef_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16(void)
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_CDDPorts_ClearPhsReasSum(UInt16 DataAccessBfr_Cnt_T_u16)
 *     Synchronous Service Invocation. Timeout: None
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SA_CDDINTERFACE9_APPL_CODE) CDDInterface9_Per1(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CDDInterface9_Per1
 *********************************************************************************************************************/
	
	
	VAR(uint16,  AUTOMATIC) ReadBuffer_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) WriteBuffer_Cnt_T_u16;
	
	VAR(uint32,  AUTOMATIC) PXAccum_Cnt_T_u32[D_PHASEC_CNT_U16 + 1u];
	
	VAR(float32, AUTOMATIC) MtrCurr1_Volts_T_f32;
	VAR(float32, AUTOMATIC) MtrCurr2_Volts_T_f32;
	VAR(float32, AUTOMATIC) CorrMtrCurrPosition_Rev_T_f32;
	VAR(float32, AUTOMATIC) CorrMtrPosElec_Rev_T_f32;
	VAR(uint16,  AUTOMATIC) CorrectedElecMtrPos_Rev_T_u0p16;
	VAR(float32, AUTOMATIC) CumMechMtrPos_Rev_T_f32;
	VAR(uint16,  AUTOMATIC) Die1RxError_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) Die1RxMtrPos_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) Die1RxRevCtr_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) Die1UnderVoltgFltAccum_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) Die2RxError_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) Die2RxMtrPos_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) Die2RxRevCtr_Cnt_T_u16;
	VAR(uint32,  AUTOMATIC) ExpectedOnTimeA_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) ExpectedOnTimeB_Cnt_T_u32;
	VAR(uint32,  AUTOMATIC) ExpectedOnTimeC_Cnt_T_u32;
	VAR(uint16,  AUTOMATIC) PhaseAdvFinal_Cnt_T_u16;
	VAR(sint32,  AUTOMATIC) PhaseAdvFinal_Cnt_T_s32;
	VAR(float32, AUTOMATIC) PhaseAdvFinal_Cnt_T_f32;
	VAR(sint16,  AUTOMATIC) PhaseAdvFinal_Cnt_T_s16;
	VAR(uint32,  AUTOMATIC) MeasuredOnTime_Cnt_T_u32[D_PHASEC_CNT_U16 + 1u];
	VAR(float32, AUTOMATIC) MechMtrPos1_Rev_T_f32;
	VAR(uint32,  AUTOMATIC) MechMtrPos1Timestamp_uSec_T_u32;
	VAR(uint32,  AUTOMATIC) MechMtrPos2Timestamp_uSec_T_u32;
	VAR(float32, AUTOMATIC) ModIdx_Uls_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrDax_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrK1_Amps_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrK2_Amps_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrQaxFinalRef_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrCurrQax_Amp_T_f32;
	VAR(float32, AUTOMATIC) MtrVoltDax_Volt_T_f32;
	VAR(float32, AUTOMATIC) MtrVoltQax_Volt_T_f32;
	VAR(uint16,  AUTOMATIC) RxMtrPosParityAccum_Cnt_T_u16;
	VAR(float32, AUTOMATIC) SysCCorrMtrPosElec_Rev_T_f32;
	VAR(uint16,  AUTOMATIC) SysCVSwitchADC_Cnt_T_u16;
	VAR(uint16,  AUTOMATIC) UncorrMechMtrPos1_Rev_T_u0p16;
	
	VAR(uint16,  AUTOMATIC) i;
	
	
	ReadBuffer_Cnt_T_u16 = CDD_CDDDataAccessBfr_Cnt_G_u16;
	WriteBuffer_Cnt_T_u16 = (ReadBuffer_Cnt_T_u16 & 1u) ^ 1u;
	Rte_Call_CDDPorts_ClearPhsReasSum(WriteBuffer_Cnt_T_u16); /* PRQA S 3200 */
	CDD_CDDDataAccessBfr_Cnt_G_u16 = WriteBuffer_Cnt_T_u16;
	
	/* These NHET2 memory reads are performed immediately after the buffer swap for greatest possible synchronization */
	PXAccum_Cnt_T_u32[D_PHASEA_CNT_U16] = HET_P1ACC_1.memory.data_word >> 3u;
	PXAccum_Cnt_T_u32[D_PHASEB_CNT_U16] = HET_P2ACC_1.memory.data_word >> 3u;
	PXAccum_Cnt_T_u32[D_PHASEC_CNT_U16] = HET_P3ACC_1.memory.data_word >> 3u;
	
	
	MtrCurr1_Volts_T_f32 = CDD_MtrCurr1_Volts_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurr2_Volts_T_f32 = CDD_MtrCurr2_Volts_G_f32[ReadBuffer_Cnt_T_u16];
	CorrMtrCurrPosition_Rev_T_f32 = CDD_CorrMtrCurrPosition_Rev_G_f32[ReadBuffer_Cnt_T_u16];
	CorrMtrPosElec_Rev_T_f32 = FPM_FixedToFloat_m(CDD_CorrectedElecMtrPos_Rev_G_u0p16[ReadBuffer_Cnt_T_u16], u0p16_T);
	CorrectedElecMtrPos_Rev_T_u0p16 = CDD_CorrectedElecMtrPos_Rev_G_u0p16[ReadBuffer_Cnt_T_u16];
	CumMechMtrPos_Rev_T_f32 = FPM_FixedToFloat_m(CDD_CumMechMtrPos_Rev_G_s15p16[ReadBuffer_Cnt_T_u16], s15p16_T);
	Die1RxError_Cnt_T_u16 = CDD_Die1RxError_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	Die1RxMtrPos_Cnt_T_u16 = CDD_Die1RxMtrPos_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	Die1RxRevCtr_Cnt_T_u16 = CDD_Die1RxRevCtr_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	Die1UnderVoltgFltAccum_Cnt_T_u16 = CDD_Die1UnderVoltgFltAccum_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	Die2RxError_Cnt_T_u16 = CDD_Die2RxError_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	Die2RxMtrPos_Cnt_T_u16 = CDD_Die2RxMtrPos_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	Die2RxRevCtr_Cnt_T_u16 = CDD_Die2RxRevCtr_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeA_Cnt_T_u32 = CDD_PWMDutyCycleASum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeB_Cnt_T_u32 = CDD_PWMDutyCycleBSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	ExpectedOnTimeC_Cnt_T_u32 = CDD_PWMDutyCycleCSum_Cnt_G_u32[ReadBuffer_Cnt_T_u16];
	PhaseAdvFinal_Cnt_T_u16 = CDD_PhaseAdvFinal_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	MechMtrPos1_Rev_T_f32 = FPM_FixedToFloat_m(CDD_MechMtrPos1_Rev_G_u0p16[ReadBuffer_Cnt_T_u16], u0p16_T);
	MechMtrPos1Timestamp_uSec_T_u32 = CDD_MechMtrPos1TimeStamp_uSec_G_u32[ReadBuffer_Cnt_T_u16];
	MechMtrPos2Timestamp_uSec_T_u32 = CDD_MechMtrPos2TimeStamp_uSec_G_u32[ReadBuffer_Cnt_T_u16];
	ModIdx_Uls_T_f32 = FPM_FixedToFloat_m(CDD_ModIdxFinal_Uls_G_u16p16[ReadBuffer_Cnt_T_u16], u16p16_T);
	MtrCurrDax_Amp_T_f32 = CDD_MtrCurrDax_Amp_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurrK1_Amps_T_f32 = CDD_MtrCurrK1_Amps_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurrK2_Amps_T_f32 = CDD_MtrCurrK2_Amps_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurrQaxFinalRef_Amp_T_f32 = CDD_MtrCurrQaxFinalRef_Amp_G_f32[ReadBuffer_Cnt_T_u16];
	MtrCurrQax_Amp_T_f32 = CDD_MtrCurrQax_Amp_G_f32[ReadBuffer_Cnt_T_u16];
	MtrVoltDax_Volt_T_f32 = CDD_MtrVoltDax_Volt_G_f32[ReadBuffer_Cnt_T_u16];
	MtrVoltQax_Volt_T_f32 = CDD_MtrVoltQax_Volt_G_f32[ReadBuffer_Cnt_T_u16];
	RxMtrPosParityAccum_Cnt_T_u16 = CDD_RxMtrPosParityAccum_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	SysCCorrMtrPosElec_Rev_T_f32 = FPM_FixedToFloat_m(CDD_SysCCorrectedElecMtrPos_Rev_G_u0p16[ReadBuffer_Cnt_T_u16], u0p16_T);
	SysCVSwitchADC_Cnt_T_u16 = CDD_SysCVSwitchADC_Cnt_G_u16[ReadBuffer_Cnt_T_u16];
	UncorrMechMtrPos1_Rev_T_u0p16 = CDD_UncorrMechMtrPos1_Rev_G_u0p16[ReadBuffer_Cnt_T_u16];
	
	
	for(i = D_PHASEA_CNT_U16; i <= D_PHASEC_CNT_U16; i++)
	{
		if(PXAccum_Cnt_T_u32[i] < PXAccumPrev_Cnt_M_u32[i])
		{
			MeasuredOnTime_Cnt_T_u32[i] = (D_PXACCUMMAX_CNT_U32 - PXAccumPrev_Cnt_M_u32[i]) + PXAccum_Cnt_T_u32[i] + 1u;
		}
		else
		{
			MeasuredOnTime_Cnt_T_u32[i] = PXAccum_Cnt_T_u32[i] - PXAccumPrev_Cnt_M_u32[i];
		}
		
		PXAccumPrev_Cnt_M_u32[i] = PXAccum_Cnt_T_u32[i];
	}
	
	if( PhaseAdvFinal_Cnt_T_u16 >= D_HALFREV_CNT_U16 )
	{
		PhaseAdvFinal_Cnt_T_s32 = ((sint32)PhaseAdvFinal_Cnt_T_u16) - D_FULLREV_CNT_S32;
		PhaseAdvFinal_Cnt_T_f32 = ((float32)PhaseAdvFinal_Cnt_T_s32) * D_PHSADVSCALE_ULS_F32;
		PhaseAdvFinal_Cnt_T_s16 = (sint16)PhaseAdvFinal_Cnt_T_f32;
		
	}
	else
	{
		PhaseAdvFinal_Cnt_T_f32 = ((float32)PhaseAdvFinal_Cnt_T_u16) * D_PHSADVSCALE_ULS_F32;
		PhaseAdvFinal_Cnt_T_s16 = (sint16)PhaseAdvFinal_Cnt_T_f32;
	}
	
	
	Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr1_Volts_f32(MtrCurr1_Volts_T_f32);
	Rte_IWrite_CDDInterface9_Per1_ADCMtrCurr2_Volts_f32(MtrCurr2_Volts_T_f32);
	Rte_IWrite_CDDInterface9_Per1_CorrMtrCurrPosition_Rev_f32(CorrMtrCurrPosition_Rev_T_f32);
	Rte_IWrite_CDDInterface9_Per1_CorrMtrPosElec_Rev_f32(CorrMtrPosElec_Rev_T_f32);
	Rte_IWrite_CDDInterface9_Per1_CorrectedElecMtrPos_Rev_u0p16(CorrectedElecMtrPos_Rev_T_u0p16);
	Rte_IWrite_CDDInterface9_Per1_CumMechMtrPos_Rev_f32(CumMechMtrPos_Rev_T_f32);
	Rte_IWrite_CDDInterface9_Per1_Die1RxError_Cnt_u16(Die1RxError_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_Die1RxMtrPos_Cnt_u16(Die1RxMtrPos_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_Die1RxRevCtr_Cnt_u16(Die1RxRevCtr_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_Die1UnderVoltgFltAccum_Cnt_u16(Die1UnderVoltgFltAccum_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_Die2RxError_Cnt_u16(Die2RxError_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_Die2RxMtrPos_Cnt_u16(Die2RxMtrPos_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_Die2RxRevCtr_Cnt_u16(Die2RxRevCtr_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeA_Cnt_u32(ExpectedOnTimeA_Cnt_T_u32);
	Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeB_Cnt_u32(ExpectedOnTimeB_Cnt_T_u32);
	Rte_IWrite_CDDInterface9_Per1_ExpectedOnTimeC_Cnt_u32(ExpectedOnTimeC_Cnt_T_u32);
	Rte_IWrite_CDDInterface9_Per1_LRPRPhaseadvanceCaptured_Cnt_s16(PhaseAdvFinal_Cnt_T_s16);
	Rte_IWrite_CDDInterface9_Per1_MeasuredOnTimeA_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEA_CNT_U16]);
	Rte_IWrite_CDDInterface9_Per1_MeasuredOnTimeB_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEB_CNT_U16]);
	Rte_IWrite_CDDInterface9_Per1_MeasuredOnTimeC_Cnt_u32(MeasuredOnTime_Cnt_T_u32[D_PHASEC_CNT_U16]);
	Rte_IWrite_CDDInterface9_Per1_MechMtrPos1_Rev_f32(MechMtrPos1_Rev_T_f32);
	Rte_IWrite_CDDInterface9_Per1_MechMtrPos1Timestamp_USec_u32(MechMtrPos1Timestamp_uSec_T_u32);
	Rte_IWrite_CDDInterface9_Per1_MechMtrPos2Timestamp_USec_u32(MechMtrPos2Timestamp_uSec_T_u32);
	Rte_IWrite_CDDInterface9_Per1_ModIdxFinal_Uls_f32(ModIdx_Uls_T_f32);
	Rte_IWrite_CDDInterface9_Per1_MtrCurrDax_Amp_f32(MtrCurrDax_Amp_T_f32);
	Rte_IWrite_CDDInterface9_Per1_MtrCurrK1_Amp_f32(MtrCurrK1_Amps_T_f32);
	Rte_IWrite_CDDInterface9_Per1_MtrCurrK2_Amp_f32(MtrCurrK2_Amps_T_f32);
	Rte_IWrite_CDDInterface9_Per1_MtrCurrQaxFinalRef_Amp_f32(MtrCurrQaxFinalRef_Amp_T_f32);
	Rte_IWrite_CDDInterface9_Per1_MtrCurrQax_Amp_f32(MtrCurrQax_Amp_T_f32);
	Rte_IWrite_CDDInterface9_Per1_MtrVoltDax_Volt_f32(MtrVoltDax_Volt_T_f32);
	Rte_IWrite_CDDInterface9_Per1_MtrVoltQax_Volt_f32(MtrVoltQax_Volt_T_f32);
	Rte_IWrite_CDDInterface9_Per1_RxMtrPosParityAccum_Cnt_u16(RxMtrPosParityAccum_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_SysCCorrMtrPosElec_Rev_f32(SysCCorrMtrPosElec_Rev_T_f32);
	Rte_IWrite_CDDInterface9_Per1_SysCVSwitchADC_Cnt_u16(SysCVSwitchADC_Cnt_T_u16);
	Rte_IWrite_CDDInterface9_Per1_UncorrMechMtrPos1_Rev_u0p16(UncorrMechMtrPos1_Rev_T_u0p16);
	
	
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SA_CDDINTERFACE9_APPL_CODE
#include "MemMap.h" /* PRQA S 5087 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
