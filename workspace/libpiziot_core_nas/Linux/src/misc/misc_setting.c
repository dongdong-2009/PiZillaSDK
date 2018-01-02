#include "stdafx.h"

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

//Define C Libary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define Platform
#include "libpiziot/libpiziot_os/def_libpiziot_os_platform.h"

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#elif defined(__LIBPIZIOT_OS_FREERTOS__)
#elif defined(__LIBPIZIOT_OS_PLATFORM_LINUX_GENERIC__)
#include <inttypes.h>
#else

#include <inttypes.h>

#endif

//Define Windows Library

//Define MENU_CONFIG_H Library
#include "../../include/menu_config.h"

//Define Kernel Library

//Define Static Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_signal.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_pthread.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mutex.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_file.h"
#include "libpiziot/libpiziot_p2p/def_libpiziot_p2p_common.h"
#include "libpiziot/libpiziot_core_nas/def_libpiziot_core_nas.h"
#include "../piziot_core_nas/piziot_core_nas.h"

//Define this Header
#include "misc_setting.h"

//Define OtherHeader
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
//#include "ShlObj.h"
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

#include "../p2p/p2p_func.h"
#include "../p2p/p2p_func_client.h"

#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS)

//Define Common Library

//Define Debug Library
#include "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#include "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

//Define new
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if 0
#define TRACEB TRACEA
#else
#define TRACEB(...) {LIBPIZIOT_FIX_ANDROID_COMPILE_MIPS_ERROR(0);} //TRACEA
#endif

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#if defined(ENABLE_MFC_GUI)
libpiziot_core_nas_event_p lplibpiziot_core_nas_event = 0;
#endif //defined(ENABLE_MFC_GUI)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

#if defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_HTSERVER)
#define ENABLE_SHOW_FREE_SD_SPACE
#endif //defined(ENABLE_P2P_IPCAMERA) || defined(ENABLE_P2P_NAS) || defined(ENABLE_P2P_CMS) || defined(ENABLE_P2P_HTSERVER)

#define MISC_SETTING_IPTABLES_SHOW_COMMAND 1
#define MISC_SETTING_IPTABLES_HIDE_COMMAND 0

#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)
#if 0
static void misc_setting_iptables_set_rule(char* Alppopen_line, int32_t Ashow_cmd, char* Alppopen_return_line, int32_t Amax_return_line_size)
{
    FILE *fd = NULL;
    do
    {
        Alppopen_return_line[0] = 0;
        if (Ashow_cmd == MISC_SETTING_IPTABLES_SHOW_COMMAND)
        {
            TRACEA("#%s\n", Alppopen_line);
        }
        fd = popen(Alppopen_line, "r");
        if (fd == NULL)
        {
            break;
        }
        if ((Alppopen_return_line == 0) || (Amax_return_line_size <= 0)) break;
        while (fgets(Alppopen_return_line, Amax_return_line_size, fd))
        {
            if (Ashow_cmd == MISC_SETTING_IPTABLES_SHOW_COMMAND)
            {
                TRACEA("==> %s", Alppopen_return_line);
            }
        }

    } while (0);
    if (fd != NULL)
    {
        pclose(fd);
    }
}
#endif //0
#endif

#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)

static int32_t misc_setting_iptables_check_bring_up_rtl8881(void) {
#if defined(ENABLE_CONFIG_RTL8881_CHECK_IPTABLE_BRING_UP)
#define MAX_IPTABLE_LINE_BUFFER 256
    char popen_line[MAX_IPTABLE_LINE_BUFFER + 1];
    char popen_return_line[MAX_IPTABLE_LINE_BUFFER + 1];
    sprintf(popen_line, "iptables -S | grep 'P INPUT DROP'");
    {
        FILE *fd = NULL;
        do {
            popen_return_line[0] = 0;
            fd = popen(popen_line, "r");
            if (fd == NULL) {
                break;
            }
            while (fgets(popen_return_line, MAX_IPTABLE_LINE_BUFFER, fd)) {
            }

        } while (0);
        if (fd != NULL) {
            pclose(fd);
        }
    }
    if (strlen(popen_return_line) == 0) {
        return 0;
    }
#endif //defined(ENABLE_CONFIG_RTL8881_CHECK_IPTABLE_BRING_UP)
    return 1;
}

static void misc_setting_iptables_enable_rtl8881(void) {
#if 0
#define MAX_IPTABLE_LINE_BUFFER 256
    char popen_line[MAX_IPTABLE_LINE_BUFFER + 1];
    char popen_return_line[MAX_IPTABLE_LINE_BUFFER + 1];
    sprintf(popen_line, "iptables -S | grep 'dport %d' | grep -v 'grep'", SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT);
    misc_setting_iptables_set_rule(popen_line, MISC_SETTING_IPTABLES_HIDE_COMMAND, popen_return_line, MAX_IPTABLE_LINE_BUFFER);
    if (strlen(popen_return_line) == 0)
    {
        sprintf(popen_line, "iptables -A INPUT -i eth1 -p udp -m udp --dport %d -j ACCEPT", SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT);
        misc_setting_iptables_set_rule(popen_line, MISC_SETTING_IPTABLES_SHOW_COMMAND, popen_return_line, MAX_IPTABLE_LINE_BUFFER);
    }
#endif //0
}

static void misc_setting_iptables_disable_rtl8881(void) {
#if 0
#define MAX_IPTABLE_LINE_BUFFER 256
    char popen_line[MAX_IPTABLE_LINE_BUFFER + 1];
    char popen_return_line[MAX_IPTABLE_LINE_BUFFER + 1];
    int32_t loop = 1;
    while (loop)
    {
        loop = 0;
        sprintf(popen_line, "iptables -S | grep 'dport %d' | grep -v 'grep'", SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT);
        misc_setting_iptables_set_rule(popen_line, MISC_SETTING_IPTABLES_HIDE_COMMAND, popen_return_line, MAX_IPTABLE_LINE_BUFFER);
        if (strlen(popen_return_line) != 0)
        {
            loop = 1;
            sprintf(popen_line, "iptables -D INPUT -i eth1 -p udp -m udp --dport %d -j ACCEPT", SAMPLE_CODE_P2P_LAN_SERVER_PORT_DEFAULT);
            misc_setting_iptables_set_rule(popen_line, MISC_SETTING_IPTABLES_SHOW_COMMAND, popen_return_line, MAX_IPTABLE_LINE_BUFFER);
        }
    }
#endif //0
}

#endif //defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)

#if defined(__LIBPIZIOT_OS_FREERTOS__)
#else

void misc_setting_iptables_enable(void) {
#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8197__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3520D__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518EV2__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_BCM28XX_RASPBERRY__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)
    do
    {
        if (libpiziot_os_signal_get_terminate_flag() == 1) break;
        if (misc_setting_iptables_check_bring_up_rtl8881() == 1) break;
        TRACEA("PIZNas:Wait iptables bring up ...\n");
        usleep(1000000);
    } while (1);
    misc_setting_iptables_enable_rtl8881();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8196__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RK3328_ROCK64__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_MT7688_LINKIT__)
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
#elif (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
#else
#error
#endif
}

void misc_setting_iptables_disable(void) {
#if defined(__LIBPIZIOT_CORE_MENU_CONFIG_X86_32_64__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8197__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3520D__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518E__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_HI3518EV2__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_BCM28XX_RASPBERRY__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8881__)
    misc_setting_iptables_disable_rtl8881();
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RTL8196__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_RK3328_ROCK64__)
#elif defined(__LIBPIZIOT_CORE_MENU_CONFIG_MT7688_LINKIT__)
#elif defined(__LIBPIZIOT_OS_PLATFORM_ANDROID__)
#elif (defined(__LIBPIZIOT_OS_PLATFORM_XCODE_IOS__) || defined(__LIBPIZIOT_OS_PLATFORM_XCODE_MACOS__))
#else
#error
#endif
}

#if defined(ENABLE_SHOW_FREE_SD_SPACE)

static char *misc_setting_get_path_mnt_sd_free_space(void) {
    return BASE_SDB1;
}

#endif //defined(ENABLE_SHOW_FREE_SD_SPACE)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#else
#define TRIMz(x) ((tz = (unsigned long long)(x)) < 0 ? 0 : tz)
static unsigned long long value_user = 0;
static unsigned long long value_user_sav = 0;
static unsigned long long value_user_frme = 0;
static unsigned long long value_system = 0;
static unsigned long long value_system_sav = 0;
static unsigned long long value_system_frme = 0;
static unsigned long long value_nice = 0;
static unsigned long long value_nice_sav = 0;
static unsigned long long value_nice_frme = 0;
static unsigned long long value_idle = 0;
static unsigned long long value_idle_sav = 0;
static unsigned long long value_idle_frme = 0;
static unsigned long long value_iowait = 0;
static unsigned long long value_iowait_sav = 0;
static unsigned long long value_iowait_frme = 0;
static unsigned long long value_irq = 0;
static unsigned long long value_irq_sav = 0;
static unsigned long long value_irq_frme = 0;
static unsigned long long value_softirq = 0;
static unsigned long long value_softirq_sav = 0;
static unsigned long long value_softirq_frme = 0;
static unsigned long long value_stead = 0;
static unsigned long long value_stead_sav = 0;
static unsigned long long value_stead_frme = 0;

static unsigned long long tot_frme = 0;
static unsigned long long tz = 0;
float scale = 0;

//#define CHECK_IDL_AVERAGE_VALUE
#if defined(CHECK_IDL_AVERAGE_VALUE)
static float idl_cnt = 0;
static float idl_cnt2 = 0;
static unsigned long long idl_value = 0;
#endif //defined(CHECK_IDL_AVERAGE_VALUE)
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

void misc_setting_cpu_stat(void) {
    uint64_t memory_size;
#if defined(ENABLE_SHOW_FREE_SD_SPACE)
    uint64_t lFreeSpaceValue;
#endif //defined(ENABLE_SHOW_FREE_SD_SPACE)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    int32_t return_flag = 1;
#else
    int32_t return_flag = 0;
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
    if (return_flag) return;

    memory_size = libpiziot_os_mem_get_system_total_free_memory();

#if defined(ENABLE_SHOW_FREE_SD_SPACE)
    libpiziot_os_mutex_plock_lock(&libpiziot_os_file_mx_free_space);
    {
        if (libpiziot_ice_os_file_get_free_space(&lFreeSpaceValue, misc_setting_get_path_mnt_sd_free_space()) != 0) {
            TRACEA("%s,user_file_get_path_free_space,error\n", LIBPIZIOT_OS__FUNCTION__);
        }
    }
    libpiziot_os_mutex_plock_unlock(&libpiziot_os_file_mx_free_space);
#endif //defined(ENABLE_SHOW_FREE_SD_SPACE)

#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#else
    {
        char buff[128 + 1];
        FILE *fp_stat = fopen("/proc/stat", "r");
        if (fp_stat == NULL) {
            return;
        }
        while (fgets(buff, 128, fp_stat)) {
            if (strstr(buff, "cpu")) {
                sscanf(buff, "cpu %Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu", &value_user, &value_nice, &value_system, &value_idle, &value_iowait, &value_irq, &value_softirq, &value_stead);
                break;
            }
        }
        fclose(fp_stat);
        value_user_frme = value_user - value_user_sav;
        value_system_frme = value_system - value_system_sav;
        value_nice_frme = value_nice - value_nice_sav;
        value_idle_frme = TRIMz(value_idle - value_idle_sav);
        value_iowait_frme = value_iowait - value_iowait_sav;
        value_irq_frme = value_irq - value_irq_sav;
        value_softirq_frme = value_softirq - value_softirq_sav;
        value_stead_frme = value_stead - value_stead_sav;
        tot_frme = value_user_frme + value_system_frme + value_nice_frme + value_idle_frme + value_iowait_frme + value_irq_frme + value_softirq_frme + value_stead_frme;
        if (tot_frme < 1) tot_frme = 1;
        scale = 100.0 / (float)tot_frme;
    }
#endif //#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)

    //if((value_idle_frme * scale) < 90)
    {
#if defined(CHECK_IDL_AVERAGE_VALUE)
        idl_cnt2++;
        if (idl_cnt2 > 10) {
            idl_cnt++;
            idl_value += value_idle_frme * scale;
        }
        if (idl_cnt > 0) {
            TRACEA("%5.1f%%,MF(%"
                PRId64
                "MB),DF(%"
                PRId64
                "MB),UR(%5.1f%%) SY(%5.1f%%) IDL(%5.1f%%) IR(%d>%d>%d) MD(%d>%d)\n"
                //"nice(%5.1f%%) iowait(%5.1f%%) irq(%5.1f%%) softirq(%5.1f%%) stead(%5.1f%%)\n"
                //"\n"
                , idl_value / idl_cnt, memory_size / 1000 / 1000, lFreeSpaceValue / 1000 / 1000, value_user_frme * scale, value_system_frme * scale, value_idle_frme * scale
                //,value_nice_frme * scale,value_iowait_frme * scale,value_irq_frme * scale,value_softirq_frme * scale,value_stead_frme * scale
                , IR_on_ambient, Air_value, IR_off_ambient, active_num, alarm_th
            );
        }
#else
        TRACEA("PIZNas:M("T_FMT_64D"M)"
#if defined(ENABLE_SHOW_FREE_SD_SPACE)
            ",D("T_FMT_64D"M)"
#endif //defined(ENABLE_SHOW_FREE_SD_SPACE)
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#else
            ",U(%1.1f%%)"
            ",S(%1.1f%%)"
            ",IL(%1.1f%%)"
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
            "\n"
            //"\nnice(%5.1f%%) iowait(%5.1f%%) irq(%5.1f%%) softirq(%5.1f%%) stead(%5.1f%%)\n"
            , memory_size / 1024 / 1024
#if defined(ENABLE_SHOW_FREE_SD_SPACE)
            , lFreeSpaceValue / 1024 / 1024
#endif //defined(ENABLE_SHOW_FREE_SD_SPACE)
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#else
            , value_user_frme * scale, value_system_frme * scale, value_idle_frme * scale
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
            //,value_nice_frme * scale,value_iowait_frme * scale,value_irq_frme * scale,value_softirq_frme * scale,value_stead_frme * scale
        );
#endif //defined(CHECK_IDL_AVERAGE_VALUE)
    }
#if defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
#else
    value_user_sav = value_user;
    value_system_sav = value_system;
    value_nice_sav = value_nice;
    value_idle_sav = value_idle;
    value_iowait_sav = value_iowait;
    value_irq_sav = value_irq;
    value_softirq_sav = value_softirq;
    value_stead_sav = value_stead;

    libpiziot_ice_os_file_proc_sys_vm_drop_caches();
#endif //defined(__LIBPIZIOT_OS_PLATFORM_MFC__)
}

#endif //defined(__LIBPIZIOT_OS_FREERTOS__)
