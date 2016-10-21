#ifndef __HISI_HIMNTN_ENUM_H__
#define __HISI_HIMNTN_ENUM_H___

/*Add , please keep the same as definition in reboot_reason.h in fastboot !!!!*/
enum himntnEnum
{
    HIMNTN_NVE_VALID = 0,
    HIMNTN_WDT_MIN,
    HIMNTN_AP_WDT = HIMNTN_WDT_MIN,
    HIMNTN_GLOBAL_WDT,
    HIMNTN_MODEM_WDT,
    HIMNTN_LPM3_WDT,
    HIMNTN_IOM3_WDT,
    HIMNTN_HIFI_WDT,
    HIMNTN_SECOS_WDT,
    HIMNTN_ISP_WDT,
    HIMNTN_IVP_WDT,
    HIMNTN_RESERVED_WDT1 = 10,
    HIMNTN_RESERVED_WDT2,
    HIMNTN_RESERVED_WDT3,
    HIMNTN_WDT_MAX = HIMNTN_RESERVED_WDT3,
    HIMNTN_FST_DUMP_MEM,
    HIMNTN_LINUX_DUMP_MEM,
    HIMNTN_SD2JTAG,
    HIMNTN_PRESS_KEY_TO_FASTBOOT,
    HIMNTN_PANIC_INTO_LOOP,
    HIMNTN_GOBAL_RESETLOG,
    HIMNTN_NOC_INT_HAPPEN,
    HIMNTN_NOC_ERROR_REBOOT = 20,
    HIMNTN_RESERVED1,
    HIMNTN_DDR_ERROR_REBOOT,
    HIMNTN_RESERVED2,
    HIMNTN_WATCHPOINT_EN,
    HIMNTN_KMEMLEAK_SWITCH,
    HIMNTN_FB_PANIC_REBOOT,
    HIMNTN_RESERVED3,
    HIMNTN_RESERVED4,
    HIMNTN_RESERVED5,
    HIMNTN_KERNEL_DUMP_ENABLE = 30, /*Hook switch is the same one of kdump.*/
    HIMNTN_SD2DJTAG,
    HIMNTN_MMC_TRACE,
    HIMNTN_LPM3_PANIC_INTO_LOOP,
    HIMNTN_RESERVED6,
    HIMNTN_CORESIGHT,
    /*Add above, and keep the same as definition in reboot_reason.h in fastboot !!!!*/
    HIMNTN_BOTTOM
};
#endif

