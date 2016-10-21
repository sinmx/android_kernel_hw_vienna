/******************************************************************************

        @(#)Copyright(C)2008,Hisilicon Co. LTD.

 ******************************************************************************
    File name   : NasEmmGutiPubInterface.h
    Description : 这是EMM GUTI模块的接口头文件
    History     :
  1. Date       : 2008-08-28
     Author     : z57968
     Modification:Create
  2. Data       :
     Author     :
     Modification:
******************************************************************************/
#ifndef _NASEMMGUTIPUBINTERFACE_H
#define _NASEMMGUTIPUBINTERFACE_H



/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "NasEmmPubUGlobal.h"


/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif
/*****************************************************************************
  #pragma pack(*)    设置字节对齐方式
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

/*****************************************************************************
  2 macro
*****************************************************************************/

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/

/*****************************************************************************
  4 Enum
*****************************************************************************/


/*****************************************************************************
  5 STRUCT
*****************************************************************************/


/*****************************************************************************
  6 UNION
*****************************************************************************/

/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/

/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/
/*给PUBLIC模块提供的接口函数**************************************/

extern  VOS_VOID     NAS_EMM_GutiInit(VOS_VOID);
extern  VOS_VOID     NAS_EMM_FreeGutiDyn( VOS_VOID );
extern VOS_UINT32    NAS_EMM_AnyStateMsgGtReCmd(VOS_UINT32  ulMsgId,
                                                VOS_VOID  *pMsgStru);
/*给TAU-ATTACH提供的guti和tai list操作接口函数**************************/
extern  VOS_UINT32   NAS_EMM_TaiListSet(const NAS_EMM_TA_LIST_STRU *pstTaiList);

/*****************************************************************************
  9 OTHERS
*****************************************************************************/

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif
