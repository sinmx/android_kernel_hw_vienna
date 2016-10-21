/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2015

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2015-04-30
 * @file
 * @brief
 *
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef CNAS_CTTF_EHRPD_EHSM_PPP_PIF_H
#define CNAS_CTTF_EHRPD_EHSM_PPP_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/

#define CNAS_CTTF_EHRPD_IPV4_ADDRESS_LEN                    ( 4 )
#define CNAS_CTTF_EHRPD_MAX_APN_LEN                         ( 99 )
#define CNAS_CTTF_EHRPD_MAX_AUTHDATA_PASSWORD_LEN           ( 127 )
#define CNAS_CTTF_EHRPD_MAX_AUTHDATA_USERNAME_LEN           ( 127 )
/**
 * From "Table 32 PCO Info TLV" defined in section 11.3.3.7 PCO Info in
 * <INVALID REF>.
 */
#define CNAS_CTTF_EHRPD_MAX_PCO_LEN                         ( 251 )
#define CNAS_CTTF_EHRPD_PDN_ADDRESS_LEN                     ( 12 )

#define CNAS_CTTF_EHRPD_AddRESS_ALLOC_CAUSE_REQ             ( 0x00 )
#define CNAS_CTTF_EHRPD_AddRESS_ALLOC_CAUSE_ACK             ( 0xFF )

#define CNAS_CTTF_EHRPD_IPV4_ADDR_LEN                       ( 4 )
#define CNAS_CTTF_EHRPD_IPV6_ADDR_LEN                       ( 16 )

/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16
 *
 * Description :
 *******************************************************************************/
enum CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM
{
    ID_CNAS_CTTF_EHRPD_ATTACH_REQ                           = 0x0000, /* _H2ASN_MsgChoice CNAS_CTTF_EHRPD_ATTACH_REQ_STRU *//**< @sa CNAS_CTTF_EHRPD_ATTACH_REQ_STRU */
    ID_CTTF_CNAS_EHRPD_ATTACH_CNF                           = 0x0001, /* _H2ASN_MsgChoice CTTF_CNAS_EHRPD_ATTACH_CNF_STRU *//**< @sa CTTF_CNAS_EHRPD_ATTACH_CNF_STRU */
    ID_CNAS_CTTF_EHRPD_DETACH_REQ                           = 0x0002, /* _H2ASN_MsgChoice CNAS_CTTF_EHRPD_DETACH_REQ_STRU *//**< @sa CNAS_CTTF_EHRPD_DETACH_REQ_STRU */
    ID_CTTF_CNAS_EHRPD_DETACH_CNF                           = 0x0003, /* _H2ASN_MsgChoice CTTF_CNAS_EHRPD_DETACH_CNF_STRU *//**< @sa CTTF_CNAS_EHRPD_DETACH_CNF_STRU */
    ID_CTTF_CNAS_EHRPD_DETACH_IND                           = 0x0004, /* _H2ASN_MsgChoice CTTF_CNAS_EHRPD_DETACH_IND_STRU *//**< @sa CTTF_CNAS_EHRPD_DETACH_IND_STRU */
    ID_CNAS_CTTF_EHRPD_PDN_CONN_REQ                         = 0x0005, /* _H2ASN_MsgChoice CNAS_CTTF_EHRPD_PDN_CONN_REQ_STRU *//**< @sa CNAS_CTTF_EHRPD_PDN_CONN_REQ_STRU */
    ID_CTTF_CNAS_EHRPD_PDN_CONN_CNF                         = 0x0006, /* _H2ASN_MsgChoice CTTF_CNAS_EHRPD_PDN_CONN_CNF_STRU *//**< @sa CTTF_CNAS_EHRPD_PDN_CONN_CNF_STRU */
    ID_CNAS_CTTF_EHRPD_PDN_DISC_REQ                         = 0x0007, /* _H2ASN_MsgChoice CNAS_CTTF_EHRPD_PDN_DISC_REQ_STRU *//**< @sa CNAS_CTTF_EHRPD_PDN_DISC_REQ_STRU */
    ID_CTTF_CNAS_EHRPD_PDN_DISC_CNF                         = 0x0008, /* _H2ASN_MsgChoice CTTF_CNAS_EHRPD_PDN_DISC_CNF_STRU *//**< @sa CTTF_CNAS_EHRPD_PDN_DISC_CNF_STRU */
    ID_CTTF_CNAS_EHRPD_PDN_DISC_IND                         = 0x0009, /* _H2ASN_MsgChoice CTTF_CNAS_EHRPD_PDN_DISC_IND_STRU *//**< @sa CTTF_CNAS_EHRPD_PDN_DISC_IND_STRU */
    ID_CNAS_CTTF_EHRPD_PDN_LOC_DISC_IND                     = 0x000A, /* _H2ASN_MsgChoice CNAS_CTTF_EHRPD_PDN_LOC_DISC_IND_STRU *//**< @sa CNAS_CTTF_EHRPD_PDN_LOC_DISC_IND_STRU */
    ID_CNAS_CTTF_EHRPD_LOC_DETACH_IND                       = 0x000B, /* _H2ASN_MsgChoice CNAS_CTTF_EHRPD_LOC_DETACH_IND_STRU *//**< @sa CNAS_CTTF_EHRPD_LOC_DETACH_IND_STRU */

    ID_CNAS_CTTF_EHRPD_LINK_STATUS_NTF                      = 0x000C, /* _H2ASN_MsgChoice CNAS_CTTF_EHRPD_LINK_STATUS_NTF_STRU */
    ID_CTTF_CNAS_EHRPD_RECONN_IND                           = 0x000D, /* _H2ASN_MsgChoice CTTF_CNAS_EHRPD_RECONN_IND_STRU */

    ID_CTTF_CNAS_EHRPD_MODIFY_IND                           = 0x000E, /* _H2ASN_MsgChoice CTTF_CNAS_EHRPD_MODIFY_IND_STRU */

    ID_CNAS_CTTF_EHRPD_EHSM_PPP_PIF_MSG_TYPE_ENUM_BUTT      = 0xFFFF
};
typedef VOS_UINT16 CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_RSLT_ENUM_UINT8
 *
 * Description :
 *******************************************************************************/
enum CNAS_CTTF_EHRPD_RSLT_ENUM
{
    CNAS_CTTF_EHRPD_RSLT_SUCCESS        = 0x00,
    CNAS_CTTF_EHRPD_RSLT_FAILURE        = 0x01,
    CNAS_CTTF_EHRPD_RSLT_ENUM_BUTT      = 0x02
};
typedef VOS_UINT8 CNAS_CTTF_EHRPD_RSLT_ENUM_UINT8;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_ATTACH_TYPE_ENUM_UINT8
 *
 * Description :
 *******************************************************************************/
enum CNAS_CTTF_EHRPD_ATTACH_TYPE_ENUM
{
    CNAS_CTTF_EHRPD_ATTACH_TYPE_INITIAL                     = 0x01,
    CNAS_CTTF_EHRPD_ATTACH_TYPE_HANDOVER                    = 0x03,
    CNAS_CTTF_EHRPD_ATTACH_TYPE_ENUM_BUTT                   = 0x04
};
typedef VOS_UINT8 CNAS_CTTF_EHRPD_ATTACH_TYPE_ENUM_UINT8;


/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_ERROR_CODE_ENUM_UINT16
 *
 * Description : From "Table 5 Error Code values" defined in section 9.1.4.1
 * 3GPP2 VSNCP Configuration Options in <INVALID REF>.
 * The values greater than 0xFF are user-defined, e.g. LCP EAP failure.
 *******************************************************************************/
enum CNAS_CTTF_EHRPD_ERROR_CODE_ENUM
{
    CNAS_CTTF_EHRPD_ERROR_CODE_GENERAL_ERROR                                    = 0x0000,
    CNAS_CTTF_EHRPD_ERROR_CODE_UNAUTHORIZED_APN                                 = 0x0001,
    CNAS_CTTF_EHRPD_ERROR_CODE_PDN_LIMIT_EXCEEDED                               = 0x0002,
    CNAS_CTTF_EHRPD_ERROR_CODE_NO_PGW_AVAILABLE                                 = 0x0003,
    CNAS_CTTF_EHRPD_ERROR_CODE_PGW_UNREACHABLE                                  = 0x0004,
    CNAS_CTTF_EHRPD_ERROR_CODE_PGW_REJECT                                       = 0x0005,
    CNAS_CTTF_EHRPD_ERROR_CODE_INSUFFICIENT_PARAMETERS                          = 0x0006,
    CNAS_CTTF_EHRPD_ERROR_CODE_RESOURCE_UNAVAILABLE                             = 0x0007,
    CNAS_CTTF_EHRPD_ERROR_CODE_ADMIN_PROHIBITED                                 = 0x0008,
    CNAS_CTTF_EHRPD_ERROR_CODE_PDNID_ALREADY_IN_USE                             = 0x0009,
    CNAS_CTTF_EHRPD_ERROR_CODE_SUBSCRIPTION_LIMITATION                          = 0x000A,
    CNAS_CTTF_EHRPD_ERROR_CODE_PDN_CONNECTION_ALREADY_EXISTS_FOR_THIS_APN       = 0x000B,
    CNAS_CTTF_EHRPD_ERROR_CODE_EMERGENCY_SERVICES_NOT_SUPPORTED                 = 0x000C,
    CNAS_CTTF_EHRPD_ERROR_CODE_RECONNECT_TO_THIS_APN_NOT_ALLOWED                = 0x000D,
    CNAS_CTTF_EHRPD_ERROR_CODE_LCP_EAP_FAILURE                                  = 0x0100, /**< LCP does contain LCP negotiation and EAP authentication, this error code is
failure of EAP authentication. */
    CNAS_CTTF_EHRPD_ERROR_CODE_LCP_OTHER_FAILURE                                = 0x0101, /**< LCP does contain LCP negotiation and EAP authentication, this error code is
other failures except for EAP authentication. */
    CNAS_CTTF_EHRPD_ERROR_CODE_TIMEROUT                                         = 0x0102, /**< L2 hasn`t received AN ack in VSNDCP negotiation. */
    CNAS_CTTF_EHRPD_ERROR_CODE_PARA_ERROR                                       = 0x0103,

    CNAS_CTTF_EHRPD_ERROR_CODE_ENUM_BUTT                                        = 0xFFFF
};
typedef VOS_UINT16 CNAS_CTTF_EHRPD_ERROR_CODE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_PDN_TYPE_ENUM_UINT8
 *
 * Description :
 *******************************************************************************/
enum CNAS_CTTF_EHRPD_PDN_TYPE_ENUM
{
    CNAS_CTTF_EHRPD_PDN_TYPE_INVALID    = 0x00,
    CNAS_CTTF_EHRPD_PDN_TYPE_IPV4       = 0x01,
    CNAS_CTTF_EHRPD_PDN_TYPE_IPV6       = 0x02,
    CNAS_CTTF_EHRPD_PDN_TYPE_IPV4V6     = 0x03,
    CNAS_CTTF_EHRPD_PDN_TYPE_ENUM_BUTT  = 0xFF
};
typedef VOS_UINT8 CNAS_CTTF_EHRPD_PDN_TYPE_ENUM_UINT8;

/*****************************************************************************
 枚举名    : CNAS_CTTF_EHRPD_LINK_STATUS_ENUM
 结构说明  : 链路建链情况枚举
 1.日    期   : 2015年11月28日
   作    者   : g00261581
   修改内容   : 新建
*****************************************************************************/
enum CNAS_CTTF_EHRPD_LINK_STATUS_ENUM
{
    CNAS_CTTF_EHRPD_LINK_NOT_EXISTED             = 0x00,                        /* 链路不存在 */
    CNAS_CTTF_EHRPD_LINK_CONNING                 = 0x01,                        /* 建链过程中 */
    CNAS_CTTF_EHRPD_LINK_DISCING                 = 0x02,                        /* 断链过程中 */
    CNAS_CTTF_EHRPD_LINK_CONNECTED               = 0x03,                        /* 链路存在 */

    CNAS_CTTF_EHRPD_LINK_STATUS_BUTT
};

typedef VOS_UINT8 CNAS_CTTF_EHRPD_LINK_STATUS_ENUM_UINT8;

/*******************************************************************************
 4. Message Header declaration
*******************************************************************************/

/*******************************************************************************
 5. Message declaration
*******************************************************************************/

/*******************************************************************************
 6. STRUCT and UNION declaration
*******************************************************************************/

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_APN_AMBR_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpDLApnAmbr:1;
    VOS_UINT32                          bitOpULApnAmbr:1;
    VOS_UINT32                          bitOpDLApnAmbrExt:1;
    VOS_UINT32                          bitOpULApnAmbrExt:1;
    VOS_UINT32                          bitOpDLApnAmbrExt2:1;
    VOS_UINT32                          bitOpULApnAmbrExt2:1;
    VOS_UINT32                          bitOpSpare:26;
    VOS_UINT8                           ucDLApnAmbr;
    VOS_UINT8                           ucULApnAmbr;
    VOS_UINT8                           ucDLApnAmbrExt;
    VOS_UINT8                           ucULApnAmbrExt;
    VOS_UINT8                           ucDLApnAmbrExt2;
    VOS_UINT8                           ucULApnAmbrExt2;
    VOS_UINT8                           aucReserved[2];
} CNAS_CTTF_EHRPD_APN_AMBR_STRU;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_APN_STRU
 *
 * Description : 举例:编码前APN为HUAWEI.COM,则编码后的APN内容:6HUAWEI3COM,长度为11字节,
                 如果ucApnLen为0，表示没有APN
 *******************************************************************************/
typedef struct
{
    VOS_UINT8                           ucApnLen;                               /* 编码后APN的长度 */
    VOS_UINT8                           aucReserved[3];
    VOS_UINT8                           aucApn[CNAS_CTTF_EHRPD_MAX_APN_LEN + 1];/* APN有效长度最大为99，字符串末尾必须为'/0' */
} CNAS_CTTF_EHRPD_APN_STRU;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_PCO_STRU
 *
 * Description : If @ucPcoLen is zero, there is not any PCO.
 *******************************************************************************/
typedef struct
{
    VOS_UINT8                           ucPcoLen;
    VOS_UINT8                           aucPco[CNAS_CTTF_EHRPD_MAX_PCO_LEN];
} CNAS_CTTF_EHRPD_PCO_STRU;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_PDN_ADDRESS_STRU
 *
 * Description : @enPdnType: It needs to be 0, if it's a request from UE/AT.
                 如果enPdnType是CNAS_CTTF_EHRPD_PDN_TYPE_INVALID，则aucAddress为全0；
                 如果enPdnType是CNAS_CTTF_EHRPD_PDN_TYPE_IPV4，则aucAddress前4个字节有效-----IPV4的地址；
                 如果enPdnType是CNAS_CTTF_EHRPD_PDN_TYPE_IPV6，则aucAddress前8个字节有效-----IPV6的Interface ID
                 如果enPdnType是CNAS_CTTF_EHRPD_PDN_TYPE_IPV4V6，则aucAddress12个字节有效--IPV4的地址+IPV6的Interface ID
 *******************************************************************************/
typedef struct
{
    CNAS_CTTF_EHRPD_PDN_TYPE_ENUM_UINT8 enPdnType;
    VOS_UINT8                           aucReserved[3];
    VOS_UINT8                           aucAddress[CNAS_CTTF_EHRPD_PDN_ADDRESS_LEN];
} CNAS_CTTF_EHRPD_PDN_ADDRESS_STRU;

/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_ATTACH_REQ_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    MODEM_ID_ENUM_UINT16                                    enModemId;
    VOS_UINT8                                               aucReserved[2];
    VOS_UINT8                                               ucPdnId;
    CNAS_CTTF_EHRPD_ATTACH_TYPE_ENUM_UINT8                  enAttachType;
    CNAS_CTTF_EHRPD_PDN_TYPE_ENUM_UINT8                     enPdnType;
    VOS_UINT8                                               ucAddressAllocCause;
    VOS_UINT8                                               aucUserName[CNAS_CTTF_EHRPD_MAX_AUTHDATA_USERNAME_LEN+1];
    VOS_UINT8                                               aucPassword[CNAS_CTTF_EHRPD_MAX_AUTHDATA_PASSWORD_LEN+1];
    CNAS_CTTF_EHRPD_APN_STRU                                stApn;
    CNAS_CTTF_EHRPD_PDN_ADDRESS_STRU                        stPdnAddress;
    CNAS_CTTF_EHRPD_PCO_STRU                                stPco;
    VOS_UINT8                                               aucIpv4DefaultRouterAddress[CNAS_CTTF_EHRPD_IPV4_ADDRESS_LEN];
} CNAS_CTTF_EHRPD_ATTACH_REQ_STRU;

/** ****************************************************************************
 * Name        : CTTF_CNAS_EHRPD_ATTACH_CNF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    CNAS_CTTF_EHRPD_RSLT_ENUM_UINT8                         enAttachRslt;
    VOS_UINT8                                               ucPdnId;
    CNAS_CTTF_EHRPD_ERROR_CODE_ENUM_UINT16                  enErrorCode;
    CNAS_CTTF_EHRPD_ATTACH_TYPE_ENUM_UINT8                  enAttachType;
    CNAS_CTTF_EHRPD_PDN_TYPE_ENUM_UINT8                     enPdnType;          /**< to indicate IPv4 or v6, or both */
    VOS_UINT8                                               ucAddressAllocCause;
    VOS_UINT8                                               ucReserved;
    VOS_UINT16                                              usMtu;
    VOS_UINT8                                               aucReserved[2];
    CNAS_CTTF_EHRPD_APN_STRU                                stApn;
    CNAS_CTTF_EHRPD_APN_AMBR_STRU                           stApnAmbr;
    CNAS_CTTF_EHRPD_PDN_ADDRESS_STRU                        stPdnAddress;
    CNAS_CTTF_EHRPD_PCO_STRU                                stPco;
    VOS_UINT8                                               aucIpv4DefaultRouterAddress[CNAS_CTTF_EHRPD_IPV4_ADDRESS_LEN];
} CTTF_CNAS_EHRPD_ATTACH_CNF_STRU;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_DETACH_REQ_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[4];
} CNAS_CTTF_EHRPD_DETACH_REQ_STRU;

/** ****************************************************************************
 * Name        : CTTF_CNAS_EHRPD_DETACH_CNF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    CNAS_CTTF_EHRPD_RSLT_ENUM_UINT8                         enDetachRslt;
    VOS_UINT8                                               aucReserved[3];
} CTTF_CNAS_EHRPD_DETACH_CNF_STRU;

/** ****************************************************************************
 * Name        : CTTF_CNAS_EHRPD_DETACH_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[4];
} CTTF_CNAS_EHRPD_DETACH_IND_STRU;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_PDN_CONN_REQ_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               ucPdnId;
    CNAS_CTTF_EHRPD_ATTACH_TYPE_ENUM_UINT8                  enAttachType;
    CNAS_CTTF_EHRPD_PDN_TYPE_ENUM_UINT8                     enPdnType;
    VOS_UINT8                                               ucAddressAllocCause;
    VOS_UINT8                                               aucUserName[CNAS_CTTF_EHRPD_MAX_AUTHDATA_USERNAME_LEN+1];
    VOS_UINT8                                               aucPassword[CNAS_CTTF_EHRPD_MAX_AUTHDATA_PASSWORD_LEN+1];
    CNAS_CTTF_EHRPD_APN_STRU                                stApn;
    CNAS_CTTF_EHRPD_PDN_ADDRESS_STRU                        stPdnAddress;
    CNAS_CTTF_EHRPD_PCO_STRU                                stPco;
    VOS_UINT8                                               aucIpv4DefaultRouterAddress[CNAS_CTTF_EHRPD_IPV4_ADDRESS_LEN];
} CNAS_CTTF_EHRPD_PDN_CONN_REQ_STRU;

/** ****************************************************************************
 * Name        : CTTF_CNAS_EHRPD_PDN_CONN_CNF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    CNAS_CTTF_EHRPD_RSLT_ENUM_UINT8                         enPdnConnRslt;
    VOS_UINT8                                               ucPdnId;
    CNAS_CTTF_EHRPD_ERROR_CODE_ENUM_UINT16                  enErrorCode;
    CNAS_CTTF_EHRPD_ATTACH_TYPE_ENUM_UINT8                  enAttachType;
    CNAS_CTTF_EHRPD_PDN_TYPE_ENUM_UINT8                     enPdnType;          /**< to indicate IPv4 or v6, or both */
    VOS_UINT8                                               ucAddressAllocCause;
    VOS_UINT8                                               ucReserved;
    CNAS_CTTF_EHRPD_APN_STRU                                stApn;
    CNAS_CTTF_EHRPD_APN_AMBR_STRU                           stApnAmbr;
    CNAS_CTTF_EHRPD_PDN_ADDRESS_STRU                        stPdnAddress;
    CNAS_CTTF_EHRPD_PCO_STRU                                stPco;
    VOS_UINT8                                               aucIpv4DefaultRouterAddress[CNAS_CTTF_EHRPD_IPV4_ADDRESS_LEN];
} CTTF_CNAS_EHRPD_PDN_CONN_CNF_STRU;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_PDN_DISC_REQ_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               ucPdnId;
    VOS_UINT8                                               aucReserved[3];
} CNAS_CTTF_EHRPD_PDN_DISC_REQ_STRU;

/** ****************************************************************************
 * Name        : CTTF_CNAS_EHRPD_PDN_DISC_CNF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    CNAS_CTTF_EHRPD_RSLT_ENUM_UINT8                         enDiscRslt;
    VOS_UINT8                                               ucPdnId;
    VOS_UINT8                                               aucReserved[2];
} CTTF_CNAS_EHRPD_PDN_DISC_CNF_STRU;

/** ****************************************************************************
 * Name        : CTTF_CNAS_EHRPD_PDN_DISC_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               ucPdnId;
    VOS_UINT8                                               aucReserved[3];
} CTTF_CNAS_EHRPD_PDN_DISC_IND_STRU;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_PDN_LOC_DISC_IND_STRU
 *
 * Description : if during pdn deactivating,the air link disconnected,EHSM
 * notify CTTF to clear the pdn information.
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               ucPdnId;
    VOS_UINT8                                               aucReserved[3];
} CNAS_CTTF_EHRPD_PDN_LOC_DISC_IND_STRU;


/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_LOC_DETACH_IND_STRU
 *
 * Description : if during detaching,the air link disconnected,EHSM
 * notify CTTF to clear all the pdn information.
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[4];
} CNAS_CTTF_EHRPD_LOC_DETACH_IND_STRU;

/** ****************************************************************************
 * Name        : CNAS_CTTF_EHRPD_LINK_STATUS_NTF_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    CNAS_CTTF_EHRPD_LINK_STATUS_ENUM_UINT8                  enLinkStatus;
    VOS_UINT8                                               aucReserved[3];
} CNAS_CTTF_EHRPD_LINK_STATUS_NTF_STRU;

/** ****************************************************************************
 * Name        : CTTF_CNAS_EHRPD_RECONN_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               aucReserved[4];
} CTTF_CNAS_EHRPD_RECONN_IND_STRU;


/** ****************************************************************************
 * Name        : CTTF_CNAS_EHRPD_MODIFY_IND_STRU
 *
 * Description :
 *******************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16                enMsgId;            /* _H2ASN_Skip */
    VOS_UINT16                                              usOpId;
    VOS_UINT8                                               ucPdnId;
    VOS_UINT8                                               ucRsv;
    VOS_UINT16                                              usMtu;
    VOS_UINT8                                               aucIpv4DefaultRouterAddress[CNAS_CTTF_EHRPD_IPV4_ADDRESS_LEN];
    CNAS_CTTF_EHRPD_PDN_ADDRESS_STRU                        stPdnAddress;
    CNAS_CTTF_EHRPD_APN_STRU                                stApn;
    CNAS_CTTF_EHRPD_APN_AMBR_STRU                           stApnAmbr;
    CNAS_CTTF_EHRPD_PCO_STRU                                stPco;
} CTTF_CNAS_EHRPD_MODIFY_IND_STRU;

/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16   ulMsgId;                                /*_H2ASN_MsgChoice_Export CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16*/
    VOS_UINT8                           aucMsgBlock[2];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          CNAS_CTTF_EHRPD_PIF_MSG_TYPE_ENUM_UINT16
    ****************************************************************************/
}CNAS_CTTF_EHRPD_PIF_MSG_TYPE_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    CNAS_CTTF_EHRPD_PIF_MSG_TYPE_DATA          stMsgReq;
}Cnas_cttf_ehrpd_ehsm_ppp_pif_MSG;


/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/
CNAS_CTTF_EHRPD_LINK_STATUS_ENUM_UINT8 CNAS_EHSM_GetPdnLinkStatus(VOS_VOID);

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif
