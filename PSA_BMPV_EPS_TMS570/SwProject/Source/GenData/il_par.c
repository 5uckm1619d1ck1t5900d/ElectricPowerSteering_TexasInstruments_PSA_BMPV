/* -----------------------------------------------------------------------------
  Filename:    il_par.c
  Description: Toolversion: 05.00.17.01.30.06.60.01.00.00
               
               Serial Number: CBD1300660
               Customer Info: Nexteer Automotive Corporation
                              Package: CBD Psa SLP4
                              Micro: 0812BPGEQQ1
                              Compiler: TexasInstruments 4.9.5
               
               
               Generator Fwk   : GENy 
               Generator Module: Il_Vector
               
               Configuration   : C:\synergy_projects_working\PSA\PSA_BMPV_EPS_TMS570\Tools\AsrProject\Config\System\EPS.gny
               
               ECU: 
                       TargetSystem: Hw_Tms470/570Cpu (Dcan)
                       Compiler:     TexasInstruments
                       Derivates:    TMS570LS0322
               
               Channel "Channel0":
                       Databasefile: C:\synergy_projects_working\PSA\PSA_BMPV_EPS_TMS570\Tools\AsrProject\Config\System\PSA_BMPV.dbc
                       Bussystem:    CAN
                       Manufacturer: PSA
                       Node:         PSCM

  Generated by , 2016-05-11  13:17:06
 ----------------------------------------------------------------------------- */
/* -----------------------------------------------------------------------------
  C O P Y R I G H T
 -------------------------------------------------------------------------------
  Copyright (c) 2001-2011 by Vector Informatik GmbH. All rights reserved.
 
  This software is copyright protected and proprietary to Vector Informatik 
  GmbH.
  
  Vector Informatik GmbH grants to you only those rights as set out in the 
  license conditions.
  
  All other rights remain with Vector Informatik GmbH.
 -------------------------------------------------------------------------------
 ----------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
    &&&~ Misra  justifications
 ----------------------------------------------------------------------------- */

/* PRQA S 3458 EOF *//* MD_CBD_19.4 */
/* PRQA S 3408 EOF *//* MD_Il_8.8 */
/* PRQA S 3460 EOF *//* MD_CBD_19.4 */
/* PRQA S 3412 EOF *//* MD_CBD_19.4 */
/* PRQA S 3453 EOF *//* MD_CBD_19.7 */
/* PRQA S 2006 EOF *//* MD_CBD_14.7 */
/* PRQA S 0777 EOF *//* MD_Il_0777 */
/* PRQA S 0778 EOF *//* MD_Il_0778 */
/* PRQA S 0779 EOF *//* MD_Il_0779 */
/* PRQA S 3673 EOF *//* MD_Il_3673 */
/* PRQA S 0310 EOF *//* MD_Il_0310 */
/* PRQA S 0312 EOF *//* MD_Il_0312 */
/* PRQA S 0635 EOF *//* MD_Il_0635 */
/* PRQA S 0781 EOF *//* MD_Il_0781 */
/* PRQA S 3410 EOF *//* MD_Il_3410 */
/* PRQA S 1330 EOF *//* MD_Il_1330 */
/* PRQA S 0342 EOF *//* MD_Il_0342 */
/* PRQA S 0857 EOF *//* MD_CBD_1.1 */
/* PRQA S 3109 EOF *//* MD_CBD_14.3 */
/* PRQA S 0883 EOF *//* */


#include "il_inc.h"

/* -----------------------------------------------------------------------------
    &&&~ local variables
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_CYCLIC_EVENT)
#endif



/* -----------------------------------------------------------------------------
    &&&~ Local function prototypes
 ----------------------------------------------------------------------------- */



/* -----------------------------------------------------------------------------
    &&&~ Internal Get Tx Signal Access for signals smaller or equal 8bit
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:                    CODE_DEFAUT,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxCODE_DEFAUT()          (IS_SUPV_DIRA.IS_SUPV_DIRA.CODE_DEFAUT)
#endif

/* Handle:    2,Name:                 ETAT_ASSIST_DA,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxETAT_ASSIST_DA()       (IS_SUPV_DIRA.IS_SUPV_DIRA.ETAT_ASSIST_DA)
#endif

/* Handle:    3,Name:                 ETAT_LIGNE_APC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
#define IlPrivateGetTxETAT_LIGNE_APC()       (IS_SUPV_DIRA.IS_SUPV_DIRA.ETAT_LIGNE_APC)
#endif



/* -----------------------------------------------------------------------------
    &&&~ Internal Get Tx Signal Access for signals greater 8bit and smaller or equal 32bit
 ----------------------------------------------------------------------------- */

/* Handle:    1,Name:              STATUS_CONFABSENT,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
vuint32 IlPrivateGetTxSTATUS_CONFABSENT(void)
{
  vuint32 rc;
  IlEnterCriticalSTATUS_CONFABSENT();
  rc = ((vuint32) IS_SUPV_DIRA.IS_SUPV_DIRA.STATUS_CONFABSENT_0);
  rc |= ((vuint32) IS_SUPV_DIRA.IS_SUPV_DIRA.STATUS_CONFABSENT_1) << 8;
  rc |= ((vuint32) IS_SUPV_DIRA.IS_SUPV_DIRA.STATUS_CONFABSENT_2) << 16;
  rc |= ((vuint32) IS_SUPV_DIRA.IS_SUPV_DIRA.STATUS_CONFABSENT_3) << 24;
  IlLeaveCriticalSTATUS_CONFABSENT();
  return rc;
}


#endif



#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT)
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 IlTxTimeoutIndirection[kIlNumberOfTxObjects] = 
{
  kIlNoTxToutIndirection /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  kIlNoTxToutIndirection /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  kIlNoTxToutIndirection /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_FAST_ON_START)
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxFastOnStartDuration[kIlNumberOfTxObjects] = 
{
  kIlNoFastOnStartDuration /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  kIlNoFastOnStartDuration /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  2 /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  kIlNoFastOnStartDuration /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  kIlNoFastOnStartDuration /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_FAST_ON_START) && defined(IL_ENABLE_TX_MODE_SIGNALS)
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxFastOnStartMuxDelay[kIlNumberOfTxObjects] = 
{
  0 /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  0 /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  0 /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  0 /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  0 /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxStartCycles[kIlNumberOfTxObjects] = 
{
  kIlNoCycleTime /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  kIlNoCycleTime /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  2 /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  kIlNoCycleTime /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  kIlNoCycleTime /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 IltTxUpdateCounter V_MEMROM2 IlTxUpdateCycles[kIlNumberOfTxObjects] = 
{
  kIlNoDelayTime /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  kIlNoDelayTime /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  kIlNoDelayTime /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  kIlNoDelayTime /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  kIlNoDelayTime /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxCyclicCycles[kIlNumberOfTxObjects] = 
{
  200 /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  kIlNoCycleTime /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  20 /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  2 /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  kIlNoCycleTime /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_TX) && (defined(IL_ENABLE_TX_CYCLIC_EVENT) || defined(IL_ENABLE_TX_SECURE_EVENT) || defined(IL_ENABLE_TX_FAST_ON_START))
V_MEMROM0 V_MEMROM1 IltTxCounter V_MEMROM2 IlTxEventCycles[kIlNumberOfTxObjects] = 
{
  200 /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  kIlNoCycleTimeFast /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  20 /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  2 /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  kIlNoCycleTimeFast /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_POLLING)
V_MEMROM0 V_MEMROM1 IlConfirmationFct V_MEMROM2 IlTxConfirmationFctPtr[kIlNumberOfTxObjects] = 
{
  V_NULL /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  V_NULL /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  V_NULL /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  V_NULL /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  V_NULL /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_TIMEOUT) && defined(C_MULTIPLE_RECEIVE_CHANNEL) && defined(IL_ENABLE_TX_VARYING_TIMEOUT) && (kIlNumberOfChannels > 1)
V_MEMROM0 V_MEMROM1 IltTxTimeoutCounter V_MEMROM2 IlTxTimeout[kIlNumberOfChannels] = 
{
  5
};
#endif


#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_SECURE_EVENT) && defined(IL_ENABLE_TX_VARYING_REPETITION) && (kIlNumberOfTxObjects > 1)
V_MEMROM0 V_MEMROM1 IltTxRepetitionCounter V_MEMROM2 IlTxRepetitionCounters[kIlNumberOfTxObjects] = 
{
  0 /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  0 /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  0 /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  0 /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  0 /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_POLLING)
V_MEMROM0 V_MEMROM1 IlIndicationFct V_MEMROM2 IlCanRxIndicationFctPtr[kIlCanNumberOfRxObjects] = 
{
  V_NULL /* ID: 0x00000772, Handle: 0, IS_ACQ_JDD_CAN_BSI_772 [FC] */, 
  V_NULL /* ID: 0x0000055f, Handle: 1, IS_ACQ_NEW_JDD_55F [FC] */, 
  V_NULL /* ID: 0x00000552, Handle: 2, IS_DAT4_V2_BSI_552 [FC] */, 
  V_NULL /* ID: 0x00000432, Handle: 3, IS_DAT_BSI_432 [FC] */, 
  V_NULL /* ID: 0x00000412, Handle: 4, IS_DAT_BSI_412 [FC] */, 
  V_NULL /* ID: 0x000003f2, Handle: 5, IS_DAT_BSI_3F2 [FC] */, 
  V_NULL /* ID: 0x00000388, Handle: 6, IS_DYN_CMM_388 [FC] */, 
  V_NULL /* ID: 0x00000348, Handle: 7, IS_DYN2_CMM_348 [FC] */, 
  V_NULL /* ID: 0x00000208, Handle: 8, IS_DYN_CMM_208 [FC] */, 
  V_NULL /* ID: 0x00000092, Handle: 9, IS_INTE_ELECTRON_BSI [FC] */
};
#endif


/* -----------------------------------------------------------------------------
    &&&~ TxDefaultInitValue Message Tables
 ----------------------------------------------------------------------------- */

V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 IS_EMIS_NEW_JDD_CAN_DIRAIlTxDefaultInitValue[8] = 
{
  0x81, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 IS_DAT_DIRAIlTxDefaultInitValue[4] = 
{
  0x7F, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 IS_DYN_DAEIlTxDefaultInitValue[7] = 
{
  0xB0, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};
V_MEMROM0 V_MEMROM1 static vuint8 V_MEMROM2 IS_VERS_DIRA_115IlTxDefaultInitValue[8] = 
{
  0x00, 
  0x01, 
  0x01, 
  0x00, 
  0x00, 
  0x00, 
  0x00, 
  0x00
};


/* -----------------------------------------------------------------------------
    &&&~ TxDefaultInitValue
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX) && defined(IL_ENABLE_TX_DEFAULTVALUE)
V_MEMROM0 IL_MEMROM1 vuint8 IL_MEMROM2 IL_MEMROM3 *V_MEMROM1 V_MEMROM2  IlTxDefaultInitValue[kIlNumberOfTxObjects] =
{
  V_NULL,
  IS_EMIS_NEW_JDD_CAN_DIRAIlTxDefaultInitValue,
  IS_DAT_DIRAIlTxDefaultInitValue,
  IS_DYN_DAEIlTxDefaultInitValue,
  IS_VERS_DIRA_115IlTxDefaultInitValue
};
#endif



/* -----------------------------------------------------------------------------
    &&&~ Declaration checking macro for signals OnChange or OnChangeWithRepetition with size < 32bit
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
#define CODE_DEFAUTValueChanged(sigData)     (((sigData) != (IlPrivateGetTxCODE_DEFAUT())))
#endif

#if defined(IL_ENABLE_TX)
#define STATUS_CONFABSENTValueChanged(sigData) (((sigData) != (IlPrivateGetTxSTATUS_CONFABSENT())))
#endif

#if defined(IL_ENABLE_TX)
#define ETAT_ASSIST_DAValueChanged(sigData)  (((sigData) != (IlPrivateGetTxETAT_ASSIST_DA())))
#endif

#if defined(IL_ENABLE_TX)
#define ETAT_LIGNE_APCValueChanged(sigData)  (((sigData) != (IlPrivateGetTxETAT_LIGNE_APC())))
#endif



/* -----------------------------------------------------------------------------
    &&&~ Implementation of a function to check IfActive flags
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_SYS_TX_SIGNALS_ARE_ACTIVE_FCT)
Il_Boolean IlTxSignalsAreActive(void )
{
  return IL_FALSE;
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Implementation function to reset indication flags
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_RX) && defined(IL_ENABLE_RX_POLLING)
void IlResetCanIndicationFlags(void )
{
  CanGlobalInterruptDisable();
  CanGlobalInterruptRestore();
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Implementation function to reset confirmation flags
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
void IlResetCanConfirmationFlags(void )
{
  CanGlobalInterruptDisable();
  IlGetTxConfirmationFlags(0) &= (vuint8) 0xE0;
  CanGlobalInterruptRestore();
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Get Rx Signal Access for signals greater 8bit and smaller or equal 32bit
 ----------------------------------------------------------------------------- */

/* Handle:   19,Name:          COLUMN_ANGLE_SETPOINT,Size: 14,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxCOLUMN_ANGLE_SETPOINT(void)
{
  vuint16 rc;
  IlEnterCriticalCOLUMN_ANGLE_SETPOINT();
  rc = ((vuint16) IS_DAT_BSI_3F2.IS_DAT_BSI_3F2.COLUMN_ANGLE_SETPOINT_0);
  rc |= ((vuint16) IS_DAT_BSI_3F2.IS_DAT_BSI_3F2.COLUMN_ANGLE_SETPOINT_1) << 6;
  IlLeaveCriticalCOLUMN_ANGLE_SETPOINT();
  return rc;
}


#endif

/* Handle:   20,Name:             VITESSE_VEHICLE_BV,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_RX
vuint16 IlGetRxVITESSE_VEHICLE_BV(void)
{
  vuint16 rc;
  IlEnterCriticalVITESSE_VEHICLE_BV();
  rc = ((vuint16) IS_DYN_CMM_388.IS_DYN_CMM_388.VITESSE_VEHICLE_BV_0);
  rc |= ((vuint16) IS_DYN_CMM_388.IS_DYN_CMM_388.VITESSE_VEHICLE_BV_1) << 8;
  IlLeaveCriticalVITESSE_VEHICLE_BV();
  return rc;
}


#endif



/* -----------------------------------------------------------------------------
    &&&~ Set Tx Signal Access 
 ----------------------------------------------------------------------------- */

/* Handle:    0,Name:                    CODE_DEFAUT,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxCODE_DEFAUT(vuint8 sigData)
{
  if(CODE_DEFAUTValueChanged(sigData))
  {
    IlEnterCriticalCODE_DEFAUT();
    IS_SUPV_DIRA.IS_SUPV_DIRA.CODE_DEFAUT = ((vuint8) sigData);
    IlSetEvent(IlTxSigHndCODE_DEFAUT);
    IlLeaveCriticalCODE_DEFAUT();
  }
}


#endif

/* Handle:    1,Name:              STATUS_CONFABSENT,Size: 32,UsedBytes:  4,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSTATUS_CONFABSENT(vuint32 sigData)
{
  if(STATUS_CONFABSENTValueChanged(sigData))
  {
    IlEnterCriticalSTATUS_CONFABSENT();
    IS_SUPV_DIRA.IS_SUPV_DIRA.STATUS_CONFABSENT_0 = ((vuint8) sigData);
    IS_SUPV_DIRA.IS_SUPV_DIRA.STATUS_CONFABSENT_1 = ((vuint8) (sigData >> 8));
    IS_SUPV_DIRA.IS_SUPV_DIRA.STATUS_CONFABSENT_2 = ((vuint8) (sigData >> 16));
    IS_SUPV_DIRA.IS_SUPV_DIRA.STATUS_CONFABSENT_3 = ((vuint8) (sigData >> 24));
    IlSetEvent(IlTxSigHndSTATUS_CONFABSENT);
    IlLeaveCriticalSTATUS_CONFABSENT();
  }
}


#endif

/* Handle:    2,Name:                 ETAT_ASSIST_DA,Size:  3,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxETAT_ASSIST_DA(vuint8 sigData)
{
  if(ETAT_ASSIST_DAValueChanged(sigData))
  {
    IlEnterCriticalETAT_ASSIST_DA();
    IS_SUPV_DIRA.IS_SUPV_DIRA.ETAT_ASSIST_DA = ((vuint8) (sigData & (vuint8) 0x07));
    IlSetEvent(IlTxSigHndETAT_ASSIST_DA);
    IlLeaveCriticalETAT_ASSIST_DA();
  }
}


#endif

/* Handle:    3,Name:                 ETAT_LIGNE_APC,Size:  1,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxETAT_LIGNE_APC(vuint8 sigData)
{
  if(ETAT_LIGNE_APCValueChanged(sigData))
  {
    IlEnterCriticalETAT_LIGNE_APC();
    IS_SUPV_DIRA.IS_SUPV_DIRA.ETAT_LIGNE_APC = ((vuint8) (sigData & (vuint8) 0x01));
    IlSetEvent(IlTxSigHndETAT_LIGNE_APC);
    IlLeaveCriticalETAT_LIGNE_APC();
  }
}


#endif

/* Handle:    6,Name:                   Frame_Number,Size:  2,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxFrame_Number(vuint8 sigData)
{
  IlEnterCriticalFrame_Number();
  IS_EMIS_NEW_JDD_CAN_DIRA.IS_EMIS_NEW_JDD_CAN_DIRA.Frame_Number = ((vuint8) (sigData & (vuint8) 0x03));
  IlSetEvent(IlTxSigHndFrame_Number);
  IlLeaveCriticalFrame_Number();
}


#endif

/* Handle:   29,Name:                  ANGLE_COLONNE,Size: 16,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxANGLE_COLONNE(vuint16 sigData)
{
  IlEnterCriticalANGLE_COLONNE();
  IS_DYN_DAE.IS_DYN_DAE.ANGLE_COLONNE_0 = ((vuint8) sigData);
  IS_DYN_DAE.IS_DYN_DAE.ANGLE_COLONNE_1 = ((vuint8) (sigData >> 8));
  IlLeaveCriticalANGLE_COLONNE();
}


#endif

/* Handle:   30,Name:                VITESSE_COLONNE,Size: 12,UsedBytes:  2,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxVITESSE_COLONNE(vuint16 sigData)
{
  IlEnterCriticalVITESSE_COLONNE();
  IS_DYN_DAE.IS_DYN_DAE.VITESSE_COLONNE_0 = ((vuint8) (sigData & (vuint8) 0x0F));
  IS_DYN_DAE.IS_DYN_DAE.VITESSE_COLONNE_1 = ((vuint8) (sigData >> 4));
  IlLeaveCriticalVITESSE_COLONNE();
}


#endif

/* Handle:   32,Name:                    System_Code,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSystem_Code(vuint8 sigData)
{
  IlEnterCriticalSystem_Code();
  IS_VERS_DIRA_115.IS_VERS_DIRA_115.System_Code = ((vuint8) sigData);
  IlSetEvent(IlTxSigHndSystem_Code);
  IlLeaveCriticalSystem_Code();
}


#endif

/* Handle:   33,Name:                   Download_Day,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDownload_Day(vuint8 sigData)
{
  IlEnterCriticalDownload_Day();
  IS_VERS_DIRA_115.IS_VERS_DIRA_115.Download_Day = ((vuint8) sigData);
  IlSetEvent(IlTxSigHndDownload_Day);
  IlLeaveCriticalDownload_Day();
}


#endif

/* Handle:   34,Name:                 Download_Month,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDownload_Month(vuint8 sigData)
{
  IlEnterCriticalDownload_Month();
  IS_VERS_DIRA_115.IS_VERS_DIRA_115.Download_Month = ((vuint8) sigData);
  IlSetEvent(IlTxSigHndDownload_Month);
  IlLeaveCriticalDownload_Month();
}


#endif

/* Handle:   35,Name:                  Download_Year,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxDownload_Year(vuint8 sigData)
{
  IlEnterCriticalDownload_Year();
  IS_VERS_DIRA_115.IS_VERS_DIRA_115.Download_Year = ((vuint8) sigData);
  IlSetEvent(IlTxSigHndDownload_Year);
  IlLeaveCriticalDownload_Year();
}


#endif

/* Handle:   36,Name:               Application_Code,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxApplication_Code(vuint8 sigData)
{
  IlEnterCriticalApplication_Code();
  IS_VERS_DIRA_115.IS_VERS_DIRA_115.Application_Code = ((vuint8) sigData);
  IlSetEvent(IlTxSigHndApplication_Code);
  IlLeaveCriticalApplication_Code();
}


#endif

/* Handle:   37,Name:               Software_Version,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSoftware_Version(vuint8 sigData)
{
  IlEnterCriticalSoftware_Version();
  IS_VERS_DIRA_115.IS_VERS_DIRA_115.Software_Version = ((vuint8) sigData);
  IlSetEvent(IlTxSigHndSoftware_Version);
  IlLeaveCriticalSoftware_Version();
}


#endif

/* Handle:   38,Name:           Software_Edition_MSB,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSoftware_Edition_MSB(vuint8 sigData)
{
  IlEnterCriticalSoftware_Edition_MSB();
  IS_VERS_DIRA_115.IS_VERS_DIRA_115.Software_Edition_MSB = ((vuint8) sigData);
  IlSetEvent(IlTxSigHndSoftware_Edition_MSB);
  IlLeaveCriticalSoftware_Edition_MSB();
}


#endif

/* Handle:   39,Name:           Software_Edition_LSB,Size:  8,UsedBytes:  1,SingleSignal */
#ifdef IL_ENABLE_TX
void IlPutTxSoftware_Edition_LSB(vuint8 sigData)
{
  IlEnterCriticalSoftware_Edition_LSB();
  IS_VERS_DIRA_115.IS_VERS_DIRA_115.Software_Edition_LSB = ((vuint8) sigData);
  IlSetEvent(IlTxSigHndSoftware_Edition_LSB);
  IlLeaveCriticalSoftware_Edition_LSB();
}


#endif



#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 CanTransmitHandle V_MEMROM2 IlTxIndirection[kIlNumberOfTxObjects] = 
{
  2 /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  3 /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  5 /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  6 /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  7 /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif


/* -----------------------------------------------------------------------------
    &&&~ CAN handle to Il start stop handle
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX) && defined(C_ENABLE_CAN_CANCEL_NOTIFICATION)
V_MEMROM0 V_MEMROM1 IlStartStopHnd V_MEMROM2 IlCanHndToIlHnd[kIlCanNumberOfTxObjects] = 
{
  { 0, 0 } /* no Il message */, 
  { 0, 0 } /* no Il message */, 
  { 0, 1 } /* start - stop  ID: 0x00000795, IS_SUPV_DIRA [FC] */, 
  { 1, 2 } /* start - stop  ID: 0x00000775, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  { 0, 0 } /* no Il message */, 
  { 2, 3 } /* start - stop  ID: 0x00000495, IS_DAT_DIRA [FC] */, 
  { 3, 4 } /* start - stop  ID: 0x000002f5, IS_DYN_DAE [FC] */, 
  { 4, 5 } /* start - stop  ID: 0x00000115, IS_VERS_DIRA_115 [FC] */
};
#endif




/* -----------------------------------------------------------------------------
    &&&~ TxTypes for interaction layer tx messages 
 ----------------------------------------------------------------------------- */

#if defined(IL_ENABLE_TX)
V_MEMROM0 V_MEMROM1 vuint8 V_MEMROM2 IlTxType[kIlNumberOfTxObjects] = 
{
  kTxSendCyclic /* ID: 0x00000795, Handle: 0, IS_SUPV_DIRA [FC] */, 
  kTxNoTxType /* ID: 0x00000775, Handle: 1, IS_EMIS_NEW_JDD_CAN_DIRA [FC] */, 
  kTxSendCyclic /* ID: 0x00000495, Handle: 2, IS_DAT_DIRA [FC] */, 
  kTxSendCyclic /* ID: 0x000002f5, Handle: 3, IS_DYN_DAE [FC] */, 
  kTxNoTxType /* ID: 0x00000115, Handle: 4, IS_VERS_DIRA_115 [FC] */
};
#endif




