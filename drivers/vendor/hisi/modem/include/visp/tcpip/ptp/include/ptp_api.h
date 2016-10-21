/*******************************************************************************
*
*
*                Copyright 2008, Huawei Technologies Co. Ltd.
*                            ALL RIGHTS RESERVED
*
*-------------------------------------------------------------------------------
*
*                              ptp_api.h
*
*  Project Code: IPCLOCK SERVER V100R002
*   Module Name: PTP api
*  Date Created: 2008-12-17
*        Author: wangchengyang
*   Description: ptp��visp����ʱ�����ṩ�Ľӿ�����
*
*-------------------------------------------------------------------------------
*  Modification History
*  DATE        NAME             DESCRIPTION    
*-------------------------------------------------------------------------------
*  2008-12-17  wangchengyang    Create the first version.
*
*******************************************************************************/

#ifndef _PTP_API_H_
#define _PTP_API_H_

#ifdef __cplusplus
extern "C" {
#endif

/* ��visp����ʱ����ptp_cbb_api.h���ṩ�Ľӿ��⻹���ⶨ�����û��ӿ�,�ο���������� */
#include "ptp/include/ptp_cbb_api.h"

/*PPI ����ö�ٶ���*/
typedef enum tagPTP_PPI_CMD_E
{
        PTP_PPI_ADD,            /* �·�����SYNC���ķ�����·���� */
        PTP_PPI_SET,            /* �·�����delay/pdelay��������ʱ������ */
        PTP_PPI_UNSET,          /* �·�ֹͣ����ʱ������ */
        PTP_PPI_DEL,            /* �·�ɾ��SYNC���ķ�����·���� */
        PTP_PPI_SETUTC,         /* ����UTC��־λ��ƫ����*/
        /*Add By t00110672 For BC3D03060,2010-5-5,ѡԴ�Ż�����ʵ��*/
        PTP_PPI_SET_BESTCLASS,
        PTP_PPI_SETIP,          /* �·�IP�����Ϣ*/
        PTP_PPI_SETMAC,         /* �·�MAC�����Ϣ*/
        PTP_PPI_BMC_PARA_CHANGED,/*IPCLK ����:ѡԴ�Ĳ��������仯��
                                   PPI �·�ֻЯ�����ˡ��Զ˵�ַ���Զ�PortId��Ϣ
                                  ������Ϣ��Ҫ��Ʒ��PTP_GetParentDS����ȡ*/
        /*Add by heyijun 00218462 for DTS2014091108767 on 2014-9-11 ����timeScale�仯���PPI�ϱ�*/
        PTP_PPI_PARA_UPDATE,    /*ANN������timescale�����仯���·�����*/
        PTP_PPI_MAX
} PTP_PPI_CMD_E;

/*PPI �����ṹ����*/
typedef struct tagPTP_PPI_S
{
        /*ST���⣬Զ��ʱ��ID�����ǲ�֪���� 20080717�� l00128792*/
        PTP_PORT_ID_S  stDstPortIdentity;        /*Դ�˿ڱ�ʶ*/
        /*Add By t00110672 For BC3D02767,2010-3-4,��TD��Ʒ���󡿡�PTP��ʵ��1588����ѡԴ�����Ż���*/
        UCHAR  ucBestClass; /*�Ƿ�Ϊ��ѡԴ���Ƿ�Ϊ��ѡԴ���ֶΣ�
                                    ʱ�ӵȼ��Ƿ�����6��7��13��14��ʱ��ԴΪ��ѡԴ
                                    BOOL_FALSE:����ѡԴ
                                    BOOL_TRUE:��ѡԴ*/
         UCHAR ucPad;
        /*Mod End*/

        /*ST����: END*/
        CHAR    cLogSyncInterval;                /*Sync ���ͼ��*/
        CHAR    cLogMinDelayReqInterval;         /*DelayReq ���ͼ��*/
        CHAR    cLogMinPdelayReqInterval;        /*PdelayReq ���ͼ��*/
        UCHAR   ucPortState;                     /*�˿ڹ���ģʽ(master  slave )*/
        PTP_PORT_ADDR_S stRemoteIP;              /*Զ�˵�ַ*/
        PTP_PORT_ADDR_S stLocalIP;               /*����ַ*/
        ULONG ulRemotePort;                      /*Զ�˶˿�*/
        ULONG ulLocalPort;                       /*���ض˿�*/
        UCHAR ucTimeSource;                      /* ʱ��Դ����,���ö��ֵ����PTP_TIMESOURCE_E */
        /*Added by raofei for VISPV1R8C03*/
        UCHAR ucPadding;
        BOOL_T bTimeScale;

        /*Add By t00110672/z00146309  10-1-11,֧��·��������ʵ�����²ݰ������� */
        BOOL_T bTwoStep;/*TRUE:TwoStep;FALSE:OneStep,Ĭ��ΪOneStep;*/
        USHORT  usReserved1;
        ULONG ulSyncDurationField;/*�·�Sync���ĵķ���ʱ��*/
        ULONG ulDelayReqDurationField;/*�·�DelayReq���ĵķ���ʱ��*/
        ULONG ulPDelayReqDurationField;/*�·�PDelayReq���ĵķ���ʱ��*/
        /*Add By t00110672 For BC3D02586,IPCLK ��Ʒʵ��˫IP������*/
        PTP_PORT_ADDR_S stRemoteExtIP;              /*Զ����չ��ַ*/
        /*Add By t00110672 For BC3D02987,IEEE1588V2 ֧��UTCʱ��ʵ�ַ���*/
        BOOL_T bOffsetValid;
        SHORT sUtcOffset;
        /*Added by zhangbo146309, �����˿ڶ�Ӧ, 2010/4/14 */
        ULONG ulIfIndex;/*�·����ؽӿ�����*/
} PTP_PPI_S;

typedef  ULONG ( *PTP_PPI_HOOK_FUNC ) ( USHORT  usPtpPortNumber, ULONG ulPtpPpiCmd, PTP_PPI_S* pstPtpPpiInfo);

/* PPIͳ����Ϣ */
typedef struct tagPTP_PPI_COUNT_S
{
    /* PTP����֪ͨ�ܴ��� */
    ULONG ulPTPUpdateTotal; 
    /* PTP����֪ͨʧ�ܴ��� */
    ULONG ulPTPUpdateFailure; 
}PTP_PPI_COUNT_S;


/******************************************************************************
*Func Name   : PTP__RegFuncPpiHook
*Description : PPI ע�ắ��
*Input       : pfPtpPpiHook   PTP_PPI_HOOK_FUNC ���͵ĺ���ָ��
*Output      : .
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش�����
*Caution     :
*Calls       :
*Called by   :
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME               DESCRIPTION
*
*******************************************************************************/
extern ULONG  PTP_RegFuncPpiHook(PTP_PPI_HOOK_FUNC pfPtpPpiHook);

/*******************************************************************************
*    Func Name: PTP_ComputePTPPPIUpdateCost
* Date Created: 2008-12-15
*       Author: 
*  Description: ʹ�ܼ���PTP PPI�·�ʱ�ӿ���
*        Input: ULONG ulSetYes:ʹ�ܿ���:1ʹ��,0ȥʹ��
*       Output: ��
*       Return: �ɹ�PTP_OK,��������ʧ��
*      Caution: 
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*
*******************************************************************************/
extern ULONG PTP_ComputePTPPPIUpdateCost(ULONG ulSetYes);

/*******************************************************************************
*    Func Name: PTP_ShowPTPPPIUpdateCost
* Date Created: 2008-12-15
*       Author: 
*  Description: ��ʾPTP PPI�·���ʱ��Ϣ
*        Input: ��
*       Output: ��
*       Return: VOID
*      Caution: 
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*
*******************************************************************************/
extern VOID PTP_ShowPTPPPIUpdateCost(VOID);

/******************************************************************************
*Func Name   : PTP_SetPpiDebugSwitch
*Description : ���ppi������Ϣ
*Input       : ulDebugFlag:����PPI���Ա��,1-��,0-�ر�
*Output      : 
*Return      : .
*******************************************************************************/
extern ULONG PTP_SetPpiDebugSwitch(ULONG ulDebugFlag);

/******************************************************************************
*Func Name   : PTP_PPI_Count_Get
*Description : ��ȡPPI�·�ͳ����Ϣ
*Input       : 
*Output      : PTP_PPI_COUNT_S *pstCount:�·�ͳ��ָ��
*Return      : �ɹ�����PTP_OK,ʧ�ܷ���PTP_ERR.
*******************************************************************************/
extern ULONG PTP_PPI_Count_Get(PTP_PPI_COUNT_S *pstCount);

/******************************************************************************
*Func Name   : PTP_PPI_Count_Reset
*Description : ���PPI�·�ͳ����Ϣ
*Input       : 
*Output      : 
*Return      : �ɹ�����PTP_OK,ʧ�ܷ���PTP_ERR.
*******************************************************************************/
extern ULONG PTP_PPI_Count_Reset(VOID);

/******************************************************************************
*Func Name   : PTP_PPI_ShowCount
*Description : ��ʾPTP PPI�·�ͳ����Ϣ
*Input       : 
*Output      : 
*Return      : 
*******************************************************************************/
extern VOID PTP_PPI_ShowCount(VOID);

/*******************************************************************************
*    Func Name: PTP_GetCPUType
* Date Created: 2008-9-11
*       Author: wangchengyang
*  Description: ��ȡCPU����
*        Input: CHAR *pCPUType: �������CPU������Ϣ
*       Output: 
*       Return: BFD_OK/BFD_ERR
*      Caution: 
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME             DESCRIPTION    
*  ----------------------------------------------------------------------------
*  2008-9-11    Wangchengyang    Creat the first version.
*
*******************************************************************************/
extern ULONG PTP_GetCPUType(CHAR *pCPUType);

/******************************************************************************
*Func Name   : PTP_SetDSCPPriority
*Description : ����IP���ĵ����ȼ�
*Input       : UInteger32 ulPriority  IP���ĵ����ȼ�����Χ��0��63
*Output      : .
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش����룬                             
*Caution     : �ṩ����IP���ĵ����ȼ����ṩʱ�Ӱ���ĳЩ�����е�ת���ٶȣ�
*              server��clent�˶�Ҫʹ�ã�Ĭ������������ȼ���63
*Calls       : 
*Called by   :  
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME           DESCRIPTION
*  2008-6-3             wangchengyang  Create
*******************************************************************************/
extern ULONG PTP_SetDSCPPriority(UCHAR ucPriority);

/******************************************************************************
*Func Name   : PTP_GetDSCPPriority
*Description : ��ѯIP���ĵ����ȼ�
*Input       : .
*Output      : UInteger32 *pulPriority  IP���ĵ����ȼ�����Χ��0��63.
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش����룬                             
*Caution     : �ṩ��ѯIP���ĵ����ȼ���server��client�˶�Ҫʹ��
*Calls       : 
*Called by   :  
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME           DESCRIPTION
*  2008-6-3             wangchengyang  Create
*******************************************************************************/
extern ULONG PTP_GetDSCPPriority(UCHAR *pucPriority);

/*******************************************************************************
*    Func Name: PTP_SetDSCPPriorityWithVrf
* Date Created: 2012-08-09
*       Author: wuxiaowu217009
*  Description: ����ָ��Master��IP���ĵ����ȼ�
*        Input: UCHAR ucPriority:  IP���ĵ����ȼ�����Χ��0��63.
*               PTP_PORT_ADDR_S *pstPortAddr: Master�ĵ�ַ.
*               pcVrfName: VRF��.
*       Output: 
*       Return: �ɹ�����PTP_OK��ʧ�ܷ��ش�����.
*      Caution: �ṩ����ָ��Master��IP���ĵ����ȼ���ֻ��slave�����ģʽ�еĵ�
*               ��ģʽ��ʹ�ã�Ĭ������������ȼ���63
*        Calls: 
*    Called by: 
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2012-08-09   wuxiaowu217009          Create
*
*******************************************************************************/
extern ULONG PTP_SetDSCPPriorityWithVrf(UCHAR ucPriority, PTP_PORT_ADDR_S *pstPortAddr, CHAR *pcVrfName);

/*******************************************************************************
*    Func Name: PTP_GetDSCPPriorityWithVrf
* Date Created: 2012-08-09
*       Author: wuxiaowu217009
*  Description: ��ѯָ��Master��IP���ĵ����ȼ�
*        Input: PTP_PORT_ADDR_S *pstPortAddr: Master�ĵ�ַ.
*               pcVrfName: VRF��.
*       Output: UCHAR *pucPriority: ָ��Master��IP���ĵ����ȼ�.
*       Return: �ɹ�����PTP_OK��ʧ�ܷ��ش�����.
*      Caution: �ṩ��ѯָ��Master��IP���ĵ����ȼ���ֻ��slave�����ģʽ�еĵ�
*               ��ģʽ��ʹ�ã�Ĭ������������ȼ���63
*        Calls: 
*    Called by: 
*------------------------------------------------------------------------------
*  Modification History
*  DATE         NAME                    DESCRIPTION
*  ----------------------------------------------------------------------------
*  2012-08-09   wuxiaowu217009          Create
*
*******************************************************************************/
extern ULONG PTP_GetDSCPPriorityWithVrf(PTP_PORT_ADDR_S *pstPortAddr, CHAR *pcVrfName, UCHAR *pucPriority);

/******************************************************************************
*Func Name   : PTP_Shell_Init
*Description : PTP Shell ��ʼ��
*Input       : ULONG ulFlag:�Ƿ���Ҫ����event��Ϣsocket���,0-����Ҫ;��0-��Ҫ
*Output      : .
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش�����                             
*Caution     : 
*Calls       : 
*Called by   :  
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME           DESCRIPTION
*  2008-6-3             wangchengyang  Create
*  2008-8-27            wangchengyang  �����Ƿ���Ҫ����event��Ϣsocket�����
*******************************************************************************/
extern ULONG PTP_Shell_Init(ULONG ulFlag);

/******************************************************************************
*Func Name   : PTP_Shell_UnInit
*Description : PTP Shell ȥ��ʼ��
*Input       : NA��
*Output      : .
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش�����                             
*Caution     : 
*Calls       : 
*Called by   :  
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME           DESCRIPTION
*  2008-6-3             wangchengyang  Create
*******************************************************************************/
extern ULONG PTP_Shell_UnInit(VOID);

/******************************************************************************
*Func Name   : PTP_Shell_Profile
*Description : ģ�����ú���
*Input       :  1. usPortNumber    �˿ں�
                    2. ulProfileType   ģ������
                    3. ulFsmMode    ״̬��ģʽ
*Output      : .
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش�����
*Caution     :
*Calls       :
*Called by   :
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME               DESCRIPTION
*
*******************************************************************************/
extern ULONG PTP_Shell_Profile(USHORT usPortNumber,ULONG ulProfileType,ULONG ulFsmMode);


/*Added by limin00188004, PTP6_Shell_Init �� PTP6_Shell_UnInit ��������Ҫ�ŵ�ptp_api.h�У������Ʒ����, 2011/11/16   ���ⵥ��:DTS2011111600282 */
/******************************************************************************
*Func Name   : PTP6_Shell_Init
*Description : PTP6 Shell ��ʼ��
*Input       : ULONG ulFlag:�Ƿ���Ҫ����event��Ϣsocket���,0-����Ҫ;��0-��Ҫ
*Output      : .
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش�����                             
*Caution     : 
*Calls       : 
*Called by   :  
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME                        DESCRIPTION
*  2010-09-21   raofei62469&zhangbo146309             Create
*******************************************************************************/
extern ULONG PTP6_Shell_Init (ULONG ulFlag);

/******************************************************************************
*Func Name   : PTP6_Shell_UnInit
*Description : PTP6 Shell ȥ��ʼ��
*Input       : VOID
*Output      : .
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش�����                             
*Caution     : 
*Calls       : 
*Called by   :  
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME                        DESCRIPTION
*  2010-09-21   raofei62469&zhangbo146309             Create
*******************************************************************************/
extern ULONG PTP6_Shell_UnInit(VOID);

/* End of Added by limin00188004, 2011/11/16   ���ⵥ��:DTS2011111600282 */


extern ULONG PTP_GetVrfIndexByName(CHAR *pcVrfName, ULONG *pulVrfIndex);


extern ULONG PTP_GetVrfNameByIndex(CHAR *pcVrfName, ULONG ulVrfIndex);
/******************************************************************************
*Func Name   : PTP6_SetDSCPPriority
*Description : ����IP���ĵ����ȼ�
*Input       : UCHAR ucPriority  IP���ĵ����ȼ�����Χ��0��63
*Output      : .
*Return      : �ɹ�����PTP_OK��ʧ�ܷ��ش����룬                             
*Caution     : �ṩ����IP���ĵ����ȼ����ṩʱ�Ӱ���ĳЩ�����е�ת���ٶȣ�
*              server��clent�˶�Ҫʹ�ã�Ĭ������������ȼ���63
*Calls       : 
*Called by   :  
*-----------------------------------------------------------------------------
*  Modification History
*  DATE                 NAME                        DESCRIPTION
*  2010-09-21   raofei62469&zhangbo146309             Create
*******************************************************************************/
extern ULONG PTP6_SetDSCPPriority(UCHAR ucPriority);
#ifdef __cplusplus 
}
#endif   /* end of __cplusplus          */

#endif   /* end of _PTP_API_H_    */ 

