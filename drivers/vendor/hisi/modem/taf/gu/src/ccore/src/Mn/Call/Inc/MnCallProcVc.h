/******************************************************************************

                  版权所有 (C), 2001-2014, 华为技术有限公司

 ******************************************************************************
  文 件 名   : MnCallProcVc.h
  版 本 号   : 初稿
  作    者   : y00245242
  生成日期   : 2014年04月01日
  最近修改   :
  功能描述   : MnCallVcProc.c 的头文件
  函数列表   :
  修改历史   :
  1.日    期   : 2014年04月01日
    作    者   : y00245242
    修改内容   : 创建文件

******************************************************************************/
#ifndef _MN_CALL_PROC_VC_H_
#define _MN_CALL_PROC_VC_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"
#include  "PsTypeDef.h"
#include  "VcCallInterface.h"

#include  "MnCallApi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  1 全局变量定义
*****************************************************************************/

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/*****************************************************************************
  3 枚举定义
*****************************************************************************/

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
VOS_VOID TAF_CALL_RcvVcCallEndCall(VC_CALL_MSG_STRU *pstEndCall);

#if (FEATURE_ON == FEATURE_ECALL)
VOS_VOID TAF_CALL_RcvVcEcallTransStatusNtf(VC_CALL_ECALL_TRANS_STATUS_NTF_STRU *pstEcallTransStatusNtf);
#endif /* end of FEATURE_ECALL */


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of _MN_CALL_VC_PROC_H */


