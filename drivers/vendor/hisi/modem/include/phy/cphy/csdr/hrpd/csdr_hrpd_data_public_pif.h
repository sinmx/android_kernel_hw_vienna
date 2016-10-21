/** ****************************************************************************

                    Huawei Technologies Sweden AB (C), 2001-2015

 ********************************************************************************
 * @author    Automatically generated by DAISY
 * @version
 * @date      2015-08-28
 * @file
 * @brief
 * These container defines public structures used by both csdr_hrpd_encoder.h
 * and csdr_hrpd_decoder.h.
 * @copyright Huawei Technologies Sweden AB
 *******************************************************************************/
#ifndef CSDR_HRPD_DATA_PUBLIC_PIF_H
#define CSDR_HRPD_DATA_PUBLIC_PIF_H

/*******************************************************************************
 1. Other files included
*******************************************************************************/

#include "vos.h"
#include "csdr_ddr_ram_ext.h"


#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#pragma pack(4)

/*******************************************************************************
 2. Macro definitions
*******************************************************************************/

/**
 * It's define the num of  subframe information instances
 */
#define CSDR_HRPD_NUM_SUBFRAME_INFO_INSTANCES               ( 3 )
/**
 * It indicates SDR has not finished address initialization
 */
#define CSDR_HRPD_ADDR_MAGIC_NOT_READY                      ( 0xD22D2DD2 )
/**
 * It indicates SDR has finished address initialization
 */
#define CSDR_HRPD_ADDR_MAGIC_READY                          ( 0x78878778 )
/**
 * This special packet id is used when CSDR feedback into slot buffer when a
 * HARQ process meets MAC layer does not have data needs to transmit on the
 * HARQ process.
 * MAC should not fill this special packet id into reverse buffer. The valid
 * range produced by MAC to indicate CSDR to transmit a MAC layer packet, is in
 * [0x0..0xFFFE].
 */
#define CSDR_HRPD_NONE_PACKET_ID                            ( 0xFFFF )
/**
 * It's the same reason as CSDR_HRPD_DECODER_NUM_FWD_BUF_INSTANCES to define 6
 * here.
 */
#define CSDR_HRPD_NUM_SLOT_BUF_INSTANCES                    ( 6 )
/**
 * NRUPActive - Maximum size of the Active Set, it's 6 defined in section 8.7.8
 * Protocol Numeric Constants in 3GPP2 C.S0024-A v3.0: "cdma2000 High Rate
 * Packet Data Air Interface Specification".
 */
#define CSDR_HRPD_MAX_NUM_PILOTS_IN_ACTIVE_SET              ( 6 )

#define CSDR_HRPD_DRC_COVER_NULL                            ( 0 )



/**
   Invalid TCM pointer address of CTTF-CSDR share ddr buff.
   Use to indicator whether CSDR have finished the DDR buff contents initial.
   Also, CBT will start testing according this value.

*/
#define CSDR_HRPD_TCM_BASE_ADD_DEFAULT_VALUE                (0x5A5A5A5A)

/*******************************************************************************
 3. Enumerations declarations
*******************************************************************************/

/** ****************************************************************************
 * Name        : CSDR_HRPD_SUBPACKET_TYPE_ENUM_UINT16
 *
 * Description : It's used to define subpacketID, it means how many times the
 * packet is sent.
 *******************************************************************************/
enum CSDR_HRPD_SUBPACKET_TYPE_ENUM
{
    CSDR_HARQ_SUBPACKET_FIRST_TIME      = 0x0000,
    CSDR_HARQ_SUBPACKET_SECOND_TIME     = 0x0001,
    CSDR_HARQ_SUBPACKET_THIRD_TIME      = 0x0002,
    CSDR_HARQ_SUBPACKET_FOURTH_TIME     = 0x0003,
    CSDR_HARQ_SUBPACKET_BUTT            = 0x0004
};
typedef VOS_UINT16 CSDR_HRPD_SUBPACKET_TYPE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : CSDR_HRPD_ARQ_TYPE_ENUM_UINT16
 *
 * Description : It's used to define ARQ type
 *******************************************************************************/
enum CSDR_HRPD_ARQ_TYPE_ENUM
{
    CSDR_HRPD_ACKNAK_ACK                = 0x0000,
    CSDR_HRPD_ACKNAK_NACK               = 0x0001,
    CSDR_HRPD_ACKNAK_NO_ARQ             = 0x0002,
    CSDR_HRPD_ACKNAK_BUTT               = 0x0003
};
typedef VOS_UINT16 CSDR_HRPD_ARQ_TYPE_ENUM_UINT16;

/** ****************************************************************************
 * Name        : CSDR_HRPD_SUBFRAME_DATA_TYPE_ENUM_UINT16
 *
 * Description : It's used to define sub-frame data type.
 *******************************************************************************/
enum CSDR_HRPD_SUBFRAME_DATA_TYPE_ENUM
{
    CSDR_HARQ_SUBFRAME_NEW_DATA         = 0x0000, /**< the first time to send a packet */
    CSDR_HARQ_SUBFRAME_RETRANS_DATA     = 0x0001, /**< the packet is retransmission packet */
    CSDR_HARQ_SUBFRAME_SILENCE_DURATION = 0x0002, /**< no data to be sent in next sub-frame because of next sub-frame overlapping with
silence */
    CSDR_HARQ_SUBFRAME_NO_DATA          = 0x0003, /**< no data to be sent in next sub-frame, and the next sub-frame don't overlap with
silence */
    CSDR_HARQ_SUBFRAME_BUTT             = 0x0004
};
typedef VOS_UINT16 CSDR_HRPD_SUBFRAME_DATA_TYPE_ENUM_UINT16;

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
 * Name        : CSDR_HRPD_SC_MEAS_INFO_STRU
 *
 * Description : CSDR update the meas result after every MPS meas when CC is
 * setup.
 * set invalid when initial
 * set invalid when CC is release
 * set invalid when CC is reconfig before the new SC MPS meas is finished
 * set invalid when RSCPfilter or EcN0 is invalid
 *******************************************************************************/
typedef struct
{
    VOS_UINT16                          usScMeasInfoFlg; /**< 0-----the result is invalid    1------valid */
    VOS_INT16                           sMaxTxpower;     /**< the max tx power, unit is 0.25dbm */
    VOS_INT16                           sMeanRxPower;    /**< CSDR report the SC RSCPfilter, unit is 0.25dbm */
    VOS_INT16                           sPilotStrenght;  /**< CSDR report the SC EcN0, unit is 0.25db */
} CSDR_HRPD_SC_MEAS_INFO_STRU;

/** ****************************************************************************
 * Name        : CSDR_HRPD_SUBFRAME_BUF_CTRL_STRU
 *
 * Description : This struct defines the control part of the Sub-frame Buffer.
 * Additional parameter information:
 * Every 4 slots, headIndex needs to be incremented one by CSDR_HRPD. tailIndex
 * is incremented when CSDR_HRPD has read out the content of an element in the
 * circular buffer.
 *
 * They are initialed by CSDR to zero.
 * If head index == tail index, it means empty; if head index + 1 mod
 * CSDR_HRPD_NUM_SUBFRAME_INFO_INSTANCES  == tail index, it means full.
 * When buffer is full, SDR drops new sub-frame information. Otherwise, SDR
 * puts  sub-frame information into the place of head index, then plus one to
 * head index.
 * After MAC read out it from the place of tail index, then plus one to tail
 * index.
 *
 * this buffer is used during MAC running in subtype3. Every 4 slots interrupt,
 * MAC must read the sub-frame buffer to get information for T2P algorithm.  if
 * buffer is empty when  4 slots interrupt is arrived, Mac will arise error.
 *
 * When CSDR receives release request when it's doing decoding, CSDR needs to
 * wait until finished decoding, then do release operation. And the last
 * decoded data needs to write into data buffer and move head index as usually.
 * However, MAC may drop it after received CPROC_CTTF_HRPD_TCH_RELEASE_CNF, as
 * MAC may drop the data waiting for itself to read out.
 *
 * If CSDR receives release-all request, after done release operation, CSDR
 * needs to force to make tail and head point to the same position.
 *******************************************************************************/
typedef struct
{
    VOS_UINT32                          ulTailIndex; /**< [0...CSDR_HRPD_NUM_SUBFRAME_INFO_INSTANCES-1], Tail index */
    VOS_UINT32                          ulHeadIndex; /**< [0...CSDR_HRPD_NUM_SUBFRAME_INFO_INSTANCES-1], Head index */
} CSDR_HRPD_SUBFRAME_BUF_CTRL_STRU;

/** ****************************************************************************
 * Name        : CSDR_HRPD_ADDR_INFO_STRU
 *
 * Description : @ulMagicNum: magic number is used to do synchronizing between
 * HRPD SDR and MAC,
 * when MS power-on, SDR will set it to not ready at first, and then set
 * addresses below, at last set magic number to ready
 * it's not allowed MAC to read addresses, until magic number turns to ready
 * All address will be initialed by SDR only when MS power-on
 * @ulFCtrlMgmtAddr: start address of CSDR_HRPD_FWD_DATA_BUF_INFO_STRU
 * @ulRCtrlMgmtAddr: start address of CSDR_HRPD_REV_DATA_BUF_INFO_STRU
 * @ulSlotMgmtAddr: start address of CSDR_HRPD_SLOT_BUF_STRU
 * @ulSubFrameMgmtAddr: start address of CSDR_HRPD_SUBFRAME_BUF_STRU
 *******************************************************************************/
typedef struct
{
    VOS_UINT32                          ulMagicNum;
    VOS_UINT32                          ulFCtrlMgmtAddr;        /**< the address to TCM */
    VOS_UINT32                          ulRCtrlMgmtAddr;        /**< the address to TCM */
    VOS_UINT32                          ulSlotMgmtAddr;         /**< the address to TCM */
    VOS_UINT32                          ulSubFrameMgmtAddr;     /**< the address to TCM */
    VOS_UINT32                          ulFtcBuffCtrAddr;       /**< the address  of  CSDR_HRPD_FWD_DATA_BUF_CTRL_STRU,   SRAM */
    VOS_UINT32                          ulSlotBuffCtrAddr;      /**< the address of CSDR_HRPD_SLOT_BUF_CTRL_STRU, SRAM */
    VOS_UINT32                          ulSubFrameBuffCtrAddr;  /**< the address of CSDR_HRPD_SUBFRAME_BUF_CTRL_STRU, SRAM */
    VOS_UINT32                          ulScMeasResultInfoAddr; /**< the address of CSDR_HRPD_SC_MEAS_INFO_STRU, SRAM */
} CSDR_HRPD_ADDR_INFO_STRU;

/** ****************************************************************************
 * Name        : CSDR_HRPD_SLOT_BUF_CTRL_STRU
 *
 * Description : This struct defines the control part of the FWD Slot Buffer.
 * Additional parameter information:
 * Every slot, headIndex needs to be incremented one by CSDR_HRPD . But if
 * CSDR_HRPD has been pending, that has no chance to go to decode RA bit,
 * CSDR_HRPD will not put slot data into the slot buffer and will not increase
 * head index.
 * @tailIndex is incremented when CTTF_HRPD_MAC has read out the content of an
 * element in the circular buffer.
 *
 * They are initialed by CSDR to zero.
 * If head index == tail index, it means empty; if head index + 1 mod
 * CSDR_HRPD_NUM_SLOT_BUF_INSTANCES == tail index, it means full.
 * When buffer is full, SDR drops new slot buffer data. Otherwise, SDR puts
 * data into the place of head index, then plus one to head index.
 * After MAC read out it from the place of tail index, then plus one to tail
 * index.
 *
 * When CSDR receives release request when it's doing decoding, CSDR needs to
 * wait until finished decoding, then do release operation. And the last
 * decoded slot buffer data needs to write into slot buffer and move head index
 * as usually. However, MAC may drop it after received
 * CPROC_CTTF_HRPD_TCH_RELEASE_CNF, as MAC may drop the slot buffer data
 * waiting for itself to read out.
 *
 * If CSDR receives release-all request, after done release operation, CSDR
 * needs to force to make tail and head point to the same position.
 *******************************************************************************/
typedef struct
{
    VOS_UINT32                          ulTailIndex; /**< [0...CSDR_HRPD_NUM_SLOT_BUF_INSTANCES -1], Tail index */
    VOS_UINT32                          ulHeadIndex; /**< [0...CSDR_HRPD_NUM_SLOT_BUF_INSTANCES -1], Head index */
} CSDR_HRPD_SLOT_BUF_CTRL_STRU;

/** ****************************************************************************
 * Name        : CSDR_HRPD_SUBFRAME_INFO_STRU
 *
 * Description : This struct defines the sub-frame information echo back to
 * MAC. CSDR will write this buffer every 4 slot.
 * Before the next sub-frame start, CSDR should determine how to do(describe in
 * CSDR_HRPD_SUBFRAME_INFO_STRU) based on H-ARQ during next sub-frame and write
 * this information(ProcessorID,subpacketId,new data or retransmission data
 * ect) to the buffer.
 * MAC will read this buffer when the latest 4 slots interrupt arrived.
 * According this information, MAC will understand the handling of the next sub
 * frame.
 *
 * @usProcessId: the processor id will use in next sub-frame
 * @enSubPacketId: the sub-packet id in the next sub-frame. If next sub-frame
 * will send a new data, this value is CSDR_HARQ_SUBPACKET_FIRST_TIME. And if
 * next sub-frame will be retransmission, this value is
 * CSDR_HARQ_SUBPACKET_SECOND_TIME, CSDR_HARQ_SUBPACKET_THIRD_TIME OR
 * CSDR_HARQ_SUBPACKET_FOURTH_TIME, based on times of the packet
 * retransmission.
 * @enDataType:  It indicates the data type will be sent in next sub-frame.
 * -  If next sub-frame will send a new data, this value is
 *    CSDR_HRPD_SUBFRAME_NEW_DATA
 * -  If next sub-frame will retransmit, this value is
 *    CSDR_HRPD_SUBFRAME_RETRANS_DATA.
 * -  If next sub-frame is overlap with reverse silence duration, this value is
 *     CSDR_HRPD_SUBFRAME_SILENCE_DURATION
 * -  If next sub-frame is not overlap with reverse silence duration and there
 *    is no data in reverse data buffer, this value is
 *    CSDR_HRPD_SUBFRAME_NO_DATA
 *******************************************************************************/
typedef struct
{
    VOS_UINT16                                              usProcessId;   /**< the processer id of the next sub frame, value range is 0~2 */
    CSDR_HRPD_SUBPACKET_TYPE_ENUM_UINT16                    enSubPacketId;

    CSDR_HRPD_SUBFRAME_DATA_TYPE_ENUM_UINT16                enDataType;    /**< it indicates which type data will sCSDR_HRPD_SUBFRAME_DATA_TYPE_ENUM_UINT16 end. Possible values are : no data to send, new data, retransmission data, silence duration */
    VOS_UINT16                                              ausReserve[1];
} CSDR_HRPD_SUBFRAME_INFO_STRU;

/** ****************************************************************************
 * Name        : CSDR_HRPD_SLOT_BUF_DATA_STRU
 *
 * Description : This struct defines the data content of the FWD Slot Buffer.
 *
 * Parameters list:
 * -  usActiveSetId: An ID to identify active set, it's echoed parameter back
 *    from CSDR
 * -  pilotInUseBitMask: Bitmask to indicate which pilots are in use within the
 *    AS.
 * -  usServingSectorBitMask: Bitmask to indicate which pilot in AS is forward
 *    link serving sector. It'll be used in T2P calculation.
 * -  sPowerHeadroom: It indicates the headroom of power for data channel. unit
 *    of 0.25dbm
 * -  sPilotPower:It indicates the power of pilot. unit of 0.25dbm
 * -  usDrcTentative: Tentative DRC(maximum data rate an AT can receive for a
 *    predetermined PER), it's DRC based on radio conditions. It is needed for
 *    DRC Supervision. For DFTC, usDrcTentative is real DRCValue. For EFTC,
 *    usDrcTentative is Tentative DRC.
 * -  ausRab: Reverse Activity Bit (RAB)(1-bit). It's used to control every
 *    sector-wide load in BS. RAB=1 (busy); RAB=0 (not busy)
 * -  asSoftRab: soft value of RAB from 12.2.1.6 Reception of the Reverse
 *    Activity Channel and
 * 13.2.2.3 Reception of the Reverse Activity Channel
 * -  ARQ_PacketID: Echoed back to CTTF_HRPD_MAC. Needed to synch ACK/NAK with
 *    RLP packets.
 * -  enArqType: If it's a NAK, MAC should trigger ReverseTrafficPacketsMissed
 *    callback, because in our product, CSDR works on BBE16. It's impossible
 *    for CSDR to send PhysicalLayer.ReverseTrafficPacketsMissed indication to
 *    RLP works on ARM, which is defined in SUBTYPE 2 Physical Layer and
 *    Multi-Flow Packet Application in 3GPP2 C.S0024-A v3.0: "cdma2000 High
 *    Rate Packet Data Air Interface Specification". We use MAC to send it
 *    instead.
 * -  asPilotStrength: Pilot strength of all pilots in the Active Set in unit
 *    of 0.25dbm
 * Additional parameter information:
 * -  usActiveSetId and usPilotInUseBitMask
 * Physical layer measures pilots in AS by turn. Every 4 slots it can measure
 * one pilot. Once Physical layer received new AS list, it will replace
 * previous AS immediately. Thus, after at most 6*4 = 24 slots, AT can measure
 * all pilots in AS at the beginning of each configuration. So to use
 * usPilotInUseBitMask to indicate which pilot in slot buffer is valid. After
 * the front 24 slots at most, Physical layer always report all pilot
 * measurement into slot buffer, which means pilot of usPilotInUseBitMask is
 * always 1, reported pilot number equals to configured pilot number.
 * When switch AS, once MAC received AS, MAC increases @usActiveSetId by one,
 * and sends configuration to Physical layer. Physical layer then will switch
 * to new pilot in AS. And Physical layer still does measurement by turn.
 * Before Physical layer received new AS, it still uses old AS to do
 * measurement, and reports slot buffer with old @usActiveSetId. During this
 * period, MAC can distinguish slot buffer value with old @usActiveSetId, and
 * new slot buffer value through it.
 * As it's needed 4 slots to finish one pilot measurement in Physical Layer,
 * for the first 3 slots after received a new @usActiveSetId, Physical layer
 * may report 0 pilot measurement in slot buffer, with usPilotInUseBitMask
 * zero. After this period time, Physical layer will report at least one pilot
 * information.
 * And if Physical Layer has not measured the sector's pilot, then there is no
 * pilot information, rab, softrab about this sector and the related bit in
 * @usPilotInUseBitMask is 0.
 * -  usPilotInUseBitMask and usServingSectorBitMask
 * Active Set pilot parameters is an array(@astPilotParameters), the order of
 * records are related with @usPilotInUseBitMask and @usServingSectorBitMask.
 * LSB of them is related with astPilotParameters[0], the next LSB is related
 * with astPilotParameters[1], and so on. E.g., there are 5 pilots in AS
 * (pilot[0]=2, pilot[1]=3, pilot[2]=4, pilot[3]=5, pilot[4]=6). And
 * @usPilotInUseBitMask is 0b00010011, it means pilot[0]=2, pilot[1]=3, and
 * pilot[4] are valid. And if @usServingSectorBitMask is 0b00010000, it means
 * pilot[4]=6 is serving pilot.
 * -  sPowerHeadroom
 * "The access terminal shall transmit at a data rate no higher than the
 * highest data rate that can be accommodated by the available transmit power"
 * from 3GPP2 C.S0024-A v3.0: "cdma2000 High Rate Packet Data Air Interface
 * Specification". As the higher the required data rate, the higher the
 * required AT transmit power to send the data on the Reverse Traffic channel.
 * The AT transmits a power no higher or equal to the total allowed AT transmit
 * power. The AT total allowed power consist of Primary Pilot Power + DRC
 * channel power + ACK channel Power (Based on received fwd data) + Data
 * channel Power or Primary Pilot Power + RRI power + DSC channel Power + DRC
 * channel power + ACK channel Power (Based on received fwd data) + Auxiliary
 * Pilot Power (Based on  Data Rate) + DRC channel power + Data channel Power.
 * The PowerHeadroom defined as the power reserved for transmit data, so it
 * formulate as below:
 * sPowerHeadroom = Total allowed Power - (Primary Pilot Power + DRC channel
 * power + ACK channel Power (Based on received fwd data))
 * or
 * sPowerHeadroom = Total allowed Power - (Primary Pilot Power + RRI power +
 * DSC channel Power + DRC channel power + ACK channel Power (Based on received
 * fwd data))
 * The unit of sPowerHeadroom is 0.25dbm.
 * -  sPilotPower
 * it indicates the Pilot channel power.
 * -  asSoftRab
 * "Once the connection is established, the access terminal shall process the
 * RA bit for each sector in its active set along with the RAChannelGain public
 * data of the Reverse Traffic Channel MAC protocol, to generate the
 * log-likelihood ratio LLRrab. The access terminal shall map the
 * log-likelihood ratio (LLR) of the RA bit demodulation, LLRrab from a range
 * of [-Infinite, +Infinite] to a range of [-1, +1] to generate SoftRAB for
 * each sector in its active set using the following function:
 * SoftRAB = 0.4 * LLRrab, -2.5 <= LLRrab <= 2.5
 * where -1 <= SoftRAB <= 1 and SoftRAB is a real-valued input for the Reverse
 * Traffic Channel MAC Protocol" from 3GPP2 C.S0024-A v3.0: "cdma2000 High Rate
 * Packet Data Air Interface Specification".
 * As it's real value through log-likelihood ratio, it's convenient to expand
 * 128*10 times. (Suppose 7-bit width, 7th power of 2 equals 128, then by 10 to
 * avoid floating type calculation.)
 * -  ARQ_PacketID and enArqType
 * When transmit a MAC layer packet, MAC will produce a Packet ID, and write
 * data into reverse buffer with Packet ID. After P-ARQ, CSDR needs to feedback
 * enArqType(either be ACK or NAK), meanwhile echoes back the related Packet
 * ID. For other slots of current H-ARQ process, CSDR writes NO_ARQ and the
 * related Packet ID belongs to current H-ARQ process.
 * When AT does not transmit a MAC layer packet, this H-ARQ process always
 * feedback special Packet ID(None, MAC ignores this @usArqPacketID) and
 * NO-ARQ. It's possible one, two or all H-ARQ processes are without any data
 * to transmit.
 * When no reverse channel is established, CSDR feedback enArqType with NO_ARQ
 * and special Packet ID(None, MAC ignores it, too).
 * -  usDrcLockUpdated
 * Because at the end of DRC channel duration, CSDR updates DrcLock bits into
 * ausDrcLock[]. When latest 4 slots interrupt arrives(CTTF is triggered by 4
 * slots interrupt periodically), MAC does not know which @usPilotInUseBitMask
 * is related to @ausDrcLock[], there are 4 slots information stored in
 * @astSlotDataBuffer[]. So there is @usDrcLockUpdated flag to indicate MAC
 * which slot CSDR updated @ausDrcLock[]. The slot when CSDR update it, CSDR
 * sets @usDrcLockUpdated to 1, otherwise set flag to 0.
 *******************************************************************************/
typedef struct
{
    VOS_UINT16                          usActiveSetId;                                           /**< Echoed back to L2 to sync Active Set config in use */
    VOS_UINT16                          usPilotInUseBitMask;                                     /**< Bit mask to indicate which pilots in AS is in use */
    VOS_UINT16                          usServingSectorBitMask;                                  /**< Bit mask to indicate which pilot in AS is forward link serving sector */
    VOS_UINT16                          usDrcLockUpdated;                                        /**< 1: updated at current slot, 0: not updated at current slot */
    VOS_INT16                           sPowerHeadroom;                                          /**< Needed for rate adoption in L2, in unit of 0.25dbm */
    VOS_INT16                           sPilotPower;                                             /**< the power of Pilot channel  in unit of 0.25dbm */
    VOS_UINT16                          usTxDrcCover;                                            /**< need for FtcTrafficMonitor */
    VOS_UINT16                          usDrcTentative;                                          /**< Needed for DRC Supervision */
    VOS_UINT16                          ausRab[CSDR_HRPD_MAX_NUM_PILOTS_IN_ACTIVE_SET];

    VOS_INT16                           asSoftRab[CSDR_HRPD_MAX_NUM_PILOTS_IN_ACTIVE_SET];       /**< [-1280, 1280] */
    VOS_UINT16                          usArqPacketID;                                           /**< ID used to match P-ARQ to RLP packets */
    CSDR_HRPD_ARQ_TYPE_ENUM_UINT16      enArqType;                                               /**< NO_ARQ, ACK, NAK corresponds to P-ARQ */
    VOS_INT16                           asPilotStrength[CSDR_HRPD_MAX_NUM_PILOTS_IN_ACTIVE_SET]; /**< in uint of 0.25dbm */
} CSDR_HRPD_SLOT_BUF_DATA_STRU;

/** ****************************************************************************
 * Name        : CSDR_HRPD_SUBFRAME_BUF_STRU
 *
 * Description : The types defined below are used to communicate the next
 * sub-frame information to CTTF_HRPD_MAC. Sub-frame buffer is updated every
 * sub-frame(4 slots).
 *******************************************************************************/
typedef struct
{
    /* CSDR_HRPD_SUBFRAME_BUF_CTRL_STRU    stSubframeBufferCtrl; */                                  /**< Buffer Control */
    CSDR_HRPD_SUBFRAME_INFO_STRU        astSubframeInfo[CSDR_HRPD_NUM_SUBFRAME_INFO_INSTANCES]; /**< sub-frame information instances */
} CSDR_HRPD_SUBFRAME_BUF_STRU;

/** ****************************************************************************
 * Name        : CSDR_HRPD_SLOT_BUF_STRU
 *
 * Description : The types defined below are used to communicate decoded MAC
 * Channel data, and parameters needed for rate adoption such as power headroom
 * and pilot strength to CTTF_HRPD_MAC. Slot buffer is updated every slot.
 *
 * Additional parameter information:
 * At the slot related to end of DRC Channel, after CSDR decides every sector's
 * lock bit, write them into @asuDrcLock[]. The related @pilotInUseBitMask is
 * stored in @astSlotDataBuffer[].
 * -  If in latest 4 slots(CTTF is triggered by 4 slots interrupt
 *    periodically), CSDR has updated @asuDrcLock[] at slot X, then the
 *    @usDrcLockUpdated of X is 1, other slots @usDrcLockUpdated is 0.
 * -  If in latest 4 slots, CSDR has not updated @asuDrcLock[], then these 4
 *    slots' @usDrcLockUpdated are 0.
 * At the beginning, when established DRC Lock Channel, it's suppose all
 * configured sectors are in lock.
 *******************************************************************************/
typedef struct
{
  /*  CSDR_HRPD_SLOT_BUF_CTRL_STRU        stSlotDataBufferCtrl;    */                            /**< Buffer Control */
    VOS_UINT16                          ausDrcLock[CSDR_HRPD_MAX_NUM_PILOTS_IN_ACTIVE_SET];  /**< DRCLock bits: 1 - In Lock, 0 - Out of Lock */
    CSDR_HRPD_SLOT_BUF_DATA_STRU        astSlotDataBuffer[CSDR_HRPD_NUM_SLOT_BUF_INSTANCES]; /**< slot buffer instances */
} CSDR_HRPD_SLOT_BUF_STRU;

/*******************************************************************************
 7. OTHER declarations
*******************************************************************************/

/*******************************************************************************
 8. Global  declaration
*******************************************************************************/

/*******************************************************************************
 9. Function declarations
*******************************************************************************/

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
