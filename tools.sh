#! /bin/bash

FedoraPackageCheckNotFound()
{
    local conffile="$1"
    local packagename="$2"
    local conffile64="$3"
    [ ! "${conffile64}" ] && conffile64="$1"

    if [ -f /usr/bin/dnf ] ; then
        echo "sudo dnf install ""${packagename}"
    else
        echo "sudo yum install ""${packagename}"
    fi

    if [ ! -f "${conffile}" ] && [ ! -d "${conffile}" ] && [ ! -f "${conffile64}" ] && [ ! -d "${conffile64}" ] ; then
       #echo '#repoquery --whatprovides '"${conffile}"
       #repoquery --whatprovides "${conffile}"
        echo
        echo "Package: ""${packagename}"
        echo "File   : $conffile"' not found !!'
        echo
        if [ -f /usr/bin/dnf ] ; then
            echo "Example:sudo dnf search ""${packagename}"
            echo "        sudo dnf install ""${packagename}"
            sudo dnf ${skip_broken} -y install "${packagename}"
            if [ ! -f "${conffile}" ] && [ ! -d "${conffile}" ] && [ ! -f "${conffile64}" ] && [ ! -d "${conffile64}" ] ; then
                echo "Package: ""${packagename}"
                echo "File   : ""${conffile}"' not found !!'
                echo
                echo "Example:sudo dnf search ""${packagename}"
                echo "        sudo dnf install ""${packagename}"
                exit
            fi
        else
            echo "Example:sudo yum search ""${packagename}"
            echo "        sudo yum install ""${packagename}"
            sudo yum ${skip_broken} -y install "${packagename}"
            if [ ! -f "${conffile}" ] && [ ! -d "${conffile}" ] && [ ! -f "${conffile64}" ] && [ ! -d "${conffile64}" ] ; then
                echo "Package: ""${packagename}"
                echo "File   : ""${conffile}"' not found !!'
                echo
                echo "Example:sudo yum search ""${packagename}"
                echo "        sudo yum install ""${packagename}"
                exit
            fi
        fi
    else
        echo "Package: ""${packagename}" 'found'
    fi
   #if [ -f "${conffile}" ] ; then
   #    rpm -q --whatprovides "${conffile}"
   #    rpm -ql "${packagename}" | grep "${conffile}"
   #fi
}

UbuntuPackageCheckNotFound()
{
    local conffile="$1"
    local packagename="$2"
    local conffile64="$3"
    [ ! "${conffile64}" ] && conffile64="$1"

    if [ -f /usr/bin/dnf ] ; then
        echo "sudo dnf install ""${packagename}"
    else
        echo "sudo yum install ""${packagename}"
    fi

    if [ ! -f "${conffile}" ] && [ ! -d "${conffile}" ] && [ ! -f "${conffile64}" ] && [ ! -d "${conffile64}" ] ; then
        echo
        echo "Package: ""${packagename}"
        echo "File   : $conffile"' not found !!'
        echo
        if [ -f /usr/bin/dnf ] ; then
            echo "Example:sudo dnf search ""${packagename}"
            echo "        sudo dnf install ""${packagename}"
            sudo dnf ${skip_broken} -y install "${packagename}"
            if [ ! -f "${conffile}" ] && [ ! -d "${conffile}" ] && [ ! -f "${conffile64}" ] && [ ! -d "${conffile64}" ] ; then
                echo "Package: ""${packagename}"
                echo "File   : ""${conffile}"' not found !!'
                echo
                echo "Example:sudo dnf search ""${packagename}"
                echo "        sudo dnf install ""${packagename}"
               #if [ -f "${conffile}" ] ; then
               #    rpm -q --whatprovides "${conffile}"
               #    rpm -ql "${packagename}" | grep "${conffile}"
               #fi
                exit
            fi
        else
            echo "Example:sudo yum search ""${packagename}"
            echo "        sudo yum install ""${packagename}"
            sudo yum ${skip_broken} -y install "${packagename}"
            if [ ! -f "${conffile}" ] && [ ! -d "${conffile}" ] && [ ! -f "${conffile64}" ] && [ ! -d "${conffile64}" ] ; then
                echo "Package: ""${packagename}"
                echo "File   : ""${conffile}"' not found !!'
                echo
                echo "Example:sudo yum search ""${packagename}"
                echo "        sudo yum install ""${packagename}"
               #echo '#repoquery --whatprovides '"${conffile}"
               #repoquery --whatprovides "${conffile}"
                exit
            fi
        fi
    else
        echo "Package: ""${packagename}" 'found'
    fi
}

Install_Fedora_Package()
{
    echo 'Install_Fedora_Package()'

    [ ! -f /etc/fedora-release ] && return

    FedoraPackageCheckNotFound '/usr/bin/gcc'                             'gcc'
    FedoraPackageCheckNotFound '/usr/bin/g++'                             'gcc-c++'
    FedoraPackageCheckNotFound '/usr/bin/gdb'                             'gdb'

    local temp=`uname -r | grep 'x86_64'`
    if [ "$temp" ] ; then
        FedoraPackageCheckNotFound '/usr/lib64/libc.so'                   'glibc-devel.x86_64'
    fi

    local temp=`uname -r | grep i686`
    if [ ! "$temp" ] ; then
        FedoraPackageCheckNotFound '/lib/ld-linux.so.2'                       'glibc.i686'
        FedoraPackageCheckNotFound '/usr/include/gnu/stubs-32.h'              'glibc-devel.i686'
        FedoraPackageCheckNotFound '/lib/libgcc_s.so.1'                       'libgcc.i686'
        FedoraPackageCheckNotFound '/usr/lib/libstdc++.so.6'                  'libstdc++.i686'
        FedoraPackageCheckNotFound '/usr/lib/libz.so.1'                       'zlib.i686'
    fi
    FedoraPackageCheckNotFound '/usr/bin/file'                                'file'

    #for RK3328 Board (RK3328)
    FedoraPackageCheckNotFound '/usr/bin/aarch64-linux-gnu-gcc'               'gcc-aarch64-linux-gnu'
    FedoraPackageCheckNotFound '/usr/bin/aarch64-linux-gnu-g++'               'gcc-c++-aarch64-linux-gnu'
    FedoraPackageCheckNotFound '/usr/bin/aarch64-linux-gnu-strip'             'binutils-aarch64-linux-gnu'

    #for pizumbo
    FedoraPackageCheckNotFound '/usr/include/curl/curl.h'                     'libcurl-devel'
    FedoraPackageCheckNotFound '/usr/include/mysql/mysql.h'                   'mariadb-devel'
}

Install_Ubuntu_Package()
{
    echo 'Install_Ubuntu_Package()'

    sudo apt-get update

   #sudo apt-get install -y apt-file
   #sudo apt-file update
   #sudo apt-file find /usr/bin/make

    sudo apt-get install -y make
    sudo apt-get install -y gcc
    sudo apt-get install -y libc6-dev-i386
    sudo apt-get install -y g++
    sudo apt-get install -y g++-multilib
    sudo apt-get install -y lib32z1
}

Install_Package()
{
    if [ -f /etc/fedora-release ] ; then
        Install_Fedora_Package
        return
    fi
    if [ -f /etc/lsb-release ] ; then
        temp=`cat /etc/lsb-release | grep Ubuntu`
        if [ "${temp}" ] ; then
            Install_Ubuntu_Package
            return
        fi
    fi
}

[ "$current_path" ] && return

Install_Package

