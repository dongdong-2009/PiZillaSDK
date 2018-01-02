package com.pppiziot.www.libpiziot;

/// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

public class jpiziot_core_cms {
    static {
        //System.loadLibrary("piziot_core_cms");
    }

    //PIZCam
    static public final int LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND = 100;

    //extern char *libpiziot_core_p2p_get_ipcamera_uid(void);

    //static public native int libpiziot_core_p2p_create_ipcamera(String ConnectUID);

    //static public native int libpiziot_core_p2p_delete_ipcamera(int Aarray_index);

    //static public native void libpiziot_core_p2p_ipcamera_enable_device_channel(int Aarray_index, int Achannel_id);

    //static public native void libpiziot_core_p2p_ipcamera_disable_device_channel(int Aarray_index, int Achannel_id);

    //NPIZNas
    static public final int LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND = 200;

    //extern char *libpiziot_core_p2p_get_nas_uid(void);

    //static public native int libpiziot_core_p2p_create_nas(String ConnectUID);

    //static public native int libpiziot_core_p2p_delete_nas(int Aarray_index);

    //static public native void libpiziot_core_p2p_nas_enable_device_channel(int Aarray_index, int Achannel_id);

    //static public native void libpiziot_core_p2p_nas_disable_device_channel(int Aarray_index, int Achannel_id);

    //static public native int libpiziot_core_p2p_nas_connect_ipcamera(String ConnectUID);

    //static public native int libpiziot_core_p2p_nas_disconnect_ipcamera(int Aarray_index);

    //static public native void libpiziot_core_p2p_nas_enable_viewer_channel(int Aarray_index, int Achannel_id);

    //static public native void libpiziot_core_p2p_nas_disable_viewer_channel(int Aarray_index, int Achannel_id);

    //PIZCms
    static public native int libpiziot_core_p2p_cms_connect_ipcamera(String ConnectUID);

    static public native int libpiziot_core_p2p_cms_disconnect_ipcamera(int Aarray_index);

    static public native void libpiziot_core_p2p_cms_enable_ipcamera_channel(int Aarray_index, int Achannel_id);

    static public native void libpiziot_core_p2p_cms_disable_ipcamera_channel(int Aarray_index, int Achannel_id);

    static public native int libpiziot_core_p2p_cms_connect_nas(String ConnectUID);

    static public native int libpiziot_core_p2p_cms_disconnect_nas(int Aarray_index);

    static public native void libpiziot_core_p2p_cms_enable_nas_channel(int Aarray_index, int Achannel_id);

    static public native void libpiziot_core_p2p_cms_disable_nas_channel(int Aarray_index, int Achannel_id);

    //PIZGserver
    //extern char *libpiziot_core_p2p_get_gserver_uid(void);

    //static public native int libpiziot_core_p2p_create_gserver(String ConnectUID);

    //static public native int libpiziot_core_p2p_delete_gserver(int Aarray_index);

    //PIZGclient
    //static public native int libpiziot_core_p2p_connect_gserver(String ConnectUID);

    //static public native int libpiziot_core_p2p_disconnect_gserver(int Aarray_index);

    static public native int libpiziot_core_cms_initialize();

    static public native void libpiziot_core_cms_finalize();
}
