package com.pppiziot.www.libpiziot;

// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

public class jpiziot_os {
    static {
        System.loadLibrary("piziot_os");
    }

    static public final int LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE = 1;
    static public final int LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS = 0;
}
