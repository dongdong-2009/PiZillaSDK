#! /bin/bash

MAKE_PRJ()
{
    if [ -f /etc/issue ] ; then
        local is_raspbian=`cat /etc/issue | grep Raspbian`
        [ "${is_raspbian}" ] && return
    fi

    if [ -f /etc/fedora-release ] ; then
        local is_bcm28xx_fedora_os=`cat /etc/fedora-release | grep Fedora`
        local is_bcm28xx_fedora_arch=`uname -r | grep armv7hl`
        if [ "${is_bcm28xx_fedora_os}" ] && [ "${is_bcm28xx_fedora_arch}" ] ; then
            return
        fi
    fi

    local is_rk3328=`uname -r | grep rockchip | grep ayufan`
    [ "${is_rk3328}" ] && return

    cp_name="$1"
    echo "BUILD"" $cp_name"
    cd "${cp_name}"
    if [ "$2" == "clean" ] ; then
        make clean
    else
        make clean
        make
    fi
    cd ${current_path}
}

MAKE_PRJ_BY_TOOLCHAIN()
{
    toolchain_name="$1"
    [ ! -d ${current_path}/../"${toolchain_name}" ] && return

    cp_name="$2"
    echo "BUILD"" $cp_name"
    cd "${cp_name}"
    if [ "$3" == "clean" ] ; then
        make clean
    else
        make clean
        make
    fi
    cd ${current_path}
}

MAKE_PRJ_BCM28XX_RASPBIAN9()
{
    [ ! -f /etc/issue ] && return
    local is_raspbian=`cat /etc/issue | grep Raspbian`
    [ ! "${is_raspbian}" ] && return

    echo "BUILD"" $cp_name"
    cp_name="$1"
    cd "${cp_name}"
    if [ "$2" == "clean" ] ; then
        make clean
    else
        make clean
        make
    fi
    cd ${current_path}
}

MAKE_PRJ_BCM28XX_FEDORA27()
{
    [ ! -f /etc/fedora-release ] && return
    local is_bcm28xx_fedora_os=`cat /etc/fedora-release | grep Fedora`
    local is_bcm28xx_fedora_arch=`uname -r | grep armv7hl`
    if [ ! "${is_bcm28xx_fedora_os}" ] || [ ! "${is_bcm28xx_fedora_arch}" ] ; then
        return
    fi

    cp_name="$1"
    echo "BUILD"" $cp_name"
    cd "${cp_name}"
    if [ "$2" == "clean" ] ; then
        make clean
    else
        make clean
        make
    fi
    cd ${current_path}
}

MAKE_PRJ_RK3328_UBM1604()
{
    local is_rk3328=`uname -r | grep rockchip | grep ayufan`
    [ ! "${is_rk3328}" ] && return

    cp_name="$1"
    echo "BUILD"" $cp_name"
    cd "${cp_name}"
    if [ "$2" == "clean" ] ; then
        make clean
    else
        make clean
        make
    fi
    cd ${current_path}
}

current_path=`pwd`

MAKE_PRJ workspace/libpiziot_core_ipcamera/Linux/x86_32_Linux_Release "$1"
MAKE_PRJ workspace/pizcam/Linux/x86_32_Linux_Release "$1"
MAKE_PRJ workspace/libpiziot_core_nas/Linux/x86_32_Linux_Release "$1"
MAKE_PRJ workspace/piznas/Linux/x86_32_Linux_Release "$1"
MAKE_PRJ workspace/libpiziot_core_cms/Linux/x86_32_Linux_Release "$1"
MAKE_PRJ workspace/pizcms/Linux/x86_32_Linux_Release "$1"
MAKE_PRJ workspace/libpiziot_core_ipcamera/Linux/x86_32_Linux_Debug "$1"
MAKE_PRJ workspace/pizcam/Linux/x86_32_Linux_Debug "$1"
MAKE_PRJ workspace/libpiziot_core_nas/Linux/x86_32_Linux_Debug "$1"
MAKE_PRJ workspace/piznas/Linux/x86_32_Linux_Debug "$1"
MAKE_PRJ workspace/libpiziot_core_cms/Linux/x86_32_Linux_Debug "$1"
MAKE_PRJ workspace/pizcms/Linux/x86_32_Linux_Debug "$1"
MAKE_PRJ workspace/libpiziot_core_ipcamera/Linux/x86_64_Linux_Release "$1"
MAKE_PRJ workspace/pizcam/Linux/x86_64_Linux_Release "$1"
MAKE_PRJ workspace/libpiziot_core_nas/Linux/x86_64_Linux_Release "$1"
MAKE_PRJ workspace/piznas/Linux/x86_64_Linux_Release "$1"
MAKE_PRJ workspace/libpiziot_core_cms/Linux/x86_64_Linux_Release "$1"
MAKE_PRJ workspace/pizcms/Linux/x86_64_Linux_Release "$1"
MAKE_PRJ workspace/libpiziot_core_ipcamera/Linux/x86_64_Linux_Debug "$1"
MAKE_PRJ workspace/pizcam/Linux/x86_64_Linux_Debug "$1"
MAKE_PRJ workspace/libpiziot_core_nas/Linux/x86_64_Linux_Debug "$1"
MAKE_PRJ workspace/piznas/Linux/x86_64_Linux_Debug "$1"
MAKE_PRJ workspace/libpiziot_core_cms/Linux/x86_64_Linux_Debug "$1"
MAKE_PRJ workspace/pizcms/Linux/x86_64_Linux_Debug "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518E workspace/libpiziot_core_ipcamera/Linux/HI3518E "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518E workspace/pizcam/Linux/HI3518E "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518E workspace/libpiziot_core_nas/Linux/HI3518E "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518E workspace/piznas/Linux/HI3518E "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518E workspace/libpiziot_core_cms/Linux/HI3518E "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518E workspace/pizcms/Linux/HI3518E "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518EV2 workspace/libpiziot_core_ipcamera/Linux/HI3518EV2 "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518EV2 workspace/pizcam/Linux/HI3518EV2 "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518EV2 workspace/libpiziot_core_nas/Linux/HI3518EV2 "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518EV2 workspace/piznas/Linux/HI3518EV2 "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518EV2 workspace/libpiziot_core_cms/Linux/HI3518EV2 "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3518EV2 workspace/pizcms/Linux/HI3518EV2 "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3520D workspace/libpiziot_core_ipcamera/Linux/HI3520D "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3520D workspace/pizcam/Linux/HI3520D "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3520D workspace/libpiziot_core_nas/Linux/HI3520D "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3520D workspace/piznas/Linux/HI3520D "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3520D workspace/libpiziot_core_cms/Linux/HI3520D "$1"
MAKE_PRJ_BY_TOOLCHAIN HI3520D workspace/pizcms/Linux/HI3520D "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8881 workspace/libpiziot_core_ipcamera/Linux/RTL8881 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8881 workspace/pizcam/Linux/RTL8881 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8881 workspace/libpiziot_core_nas/Linux/RTL8881 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8881 workspace/piznas/Linux/RTL8881 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8881 workspace/libpiziot_core_cms/Linux/RTL8881 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8881 workspace/pizcms/Linux/RTL8881 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8196 workspace/libpiziot_core_ipcamera/Linux/RTL8196 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8196 workspace/pizcam/Linux/RTL8196 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8196 workspace/libpiziot_core_nas/Linux/RTL8196 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8196 workspace/piznas/Linux/RTL8196 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8196 workspace/libpiziot_core_cms/Linux/RTL8196 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8196 workspace/pizcms/Linux/RTL8196 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8197 workspace/libpiziot_core_ipcamera/Linux/RTL8197 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8197 workspace/pizcam/Linux/RTL8197 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8197 workspace/libpiziot_core_nas/Linux/RTL8197 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8197 workspace/piznas/Linux/RTL8197 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8197 workspace/libpiziot_core_cms/Linux/RTL8197 "$1"
MAKE_PRJ_BY_TOOLCHAIN RTL8197 workspace/pizcms/Linux/RTL8197 "$1"
MAKE_PRJ_BY_TOOLCHAIN BCM28XX workspace/libpiziot_core_ipcamera/Linux/BCM28XX "$1"
MAKE_PRJ_BY_TOOLCHAIN BCM28XX workspace/pizcam/Linux/BCM28XX "$1"
MAKE_PRJ_BY_TOOLCHAIN BCM28XX workspace/libpiziot_core_nas/Linux/BCM28XX "$1"
MAKE_PRJ_BY_TOOLCHAIN BCM28XX workspace/piznas/Linux/BCM28XX "$1"
MAKE_PRJ_BY_TOOLCHAIN BCM28XX workspace/libpiziot_core_cms/Linux/BCM28XX "$1"
MAKE_PRJ_BY_TOOLCHAIN BCM28XX workspace/pizcms/Linux/BCM28XX "$1"
MAKE_PRJ_BCM28XX_RASPBIAN9 workspace/libpiziot_core_ipcamera/Linux/BCM28XX_RASPBIAN9 "$1"
MAKE_PRJ_BCM28XX_RASPBIAN9 workspace/pizcam/Linux/BCM28XX_RASPBIAN9 "$1"
MAKE_PRJ_BCM28XX_RASPBIAN9 workspace/libpiziot_core_nas/Linux/BCM28XX_RASPBIAN9 "$1"
MAKE_PRJ_BCM28XX_RASPBIAN9 workspace/piznas/Linux/BCM28XX_RASPBIAN9 "$1"
MAKE_PRJ_BCM28XX_RASPBIAN9 workspace/libpiziot_core_cms/Linux/BCM28XX_RASPBIAN9 "$1"
MAKE_PRJ_BCM28XX_RASPBIAN9 workspace/pizcms/Linux/BCM28XX_RASPBIAN9 "$1"
MAKE_PRJ_BCM28XX_FEDORA27 workspace/libpiziot_core_ipcamera/Linux/BCM28XX_FEDORA27 "$1"
MAKE_PRJ_BCM28XX_FEDORA27 workspace/pizcam/Linux/BCM28XX_FEDORA27 "$1"
MAKE_PRJ_BCM28XX_FEDORA27 workspace/libpiziot_core_nas/Linux/BCM28XX_FEDORA27 "$1"
MAKE_PRJ_BCM28XX_FEDORA27 workspace/piznas/Linux/BCM28XX_FEDORA27 "$1"
MAKE_PRJ_BCM28XX_FEDORA27 workspace/libpiziot_core_cms/Linux/BCM28XX_FEDORA27 "$1"
MAKE_PRJ_BCM28XX_FEDORA27 workspace/pizcms/Linux/BCM28XX_FEDORA27 "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/libpiziot_core_ipcamera/Linux/RK3328_UBM1604_Release "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/pizcam/Linux/RK3328_UBM1604_Release "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/libpiziot_core_nas/Linux/RK3328_UBM1604_Release "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/piznas/Linux/RK3328_UBM1604_Release "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/libpiziot_core_cms/Linux/RK3328_UBM1604_Release "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/pizcms/Linux/RK3328_UBM1604_Release "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/libpiziot_core_ipcamera/Linux/RK3328_UBM1604_Debug "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/pizcam/Linux/RK3328_UBM1604_Debug "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/libpiziot_core_nas/Linux/RK3328_UBM1604_Debug "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/piznas/Linux/RK3328_UBM1604_Debug "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/libpiziot_core_cms/Linux/RK3328_UBM1604_Debug "$1"
MAKE_PRJ_RK3328_UBM1604 workspace/pizcms/Linux/RK3328_UBM1604_Debug "$1"
