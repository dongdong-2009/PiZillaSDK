package com.pppiziot.www.libpiziot;

import com.pppiziot.www.libpiziot.jpiziot_core_cms;
import com.pppiziot.www.libpiziot.jpiziot_os;

/**
 * Created by W10SP on 2017/11/5.
 */

public class jpiziot_p2p_device {

    jpiziot_core_cms piziot_core_cms = null;

    static public volatile int cms_viewer_ipcamera_ref_1 = -1;
    static public volatile int cms_viewer_ipcamera_ref_2 = -1;
    static public volatile int cms_viewer_ipcamera_ref_3 = -1;
    static public volatile int cms_viewer_nas_ref_1 = -1;
    static public volatile int cms_viewer_nas_ref_2 = -1;
    static public volatile int cms_viewer_nas_ref_3 = -1;
    static public volatile int cms_viewer_nas_ref_4 = -1;

    static public native int libpiziot_core_p2p_cms_nas_channel_common_get_model(int Aviewer_handle);

    static public native int libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p(int Aviewer_handle);

    static public native int libpiziot_core_p2p_cms_nas_channel_common_set_reboot(int Aviewer_handle);

    static public final int LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI = 8;

    static public native int libpiziot_core_p2p_cms_nas_channel_common_set_timezone(int Aviewer_handle, int Atimezone);

    static public native int libpiziot_core_p2p_cms_nas_channel_common_get_timezone(int Aviewer_handle);

    static public final int LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO = 0;
    static public final int LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES = 1;

    static public native int libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(int Aviewer_handle, int Alock_mode);

    static public native int libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(int Aviewer_handle);

    static public native int libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute(int Aviewer_handle, int Amute_mode);

    static public native int libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute(int Aviewer_handle);

    static public native int libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout(int Aviewer_handle, int Acallout_mode);

    static public native int libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout(int Aviewer_handle);

    public int core_p2p_initialize() {
        int rval = jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
        do {
            if (this.piziot_core_cms != null) {
                rval = jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
                break;
            } else {
                this.piziot_core_cms = new jpiziot_core_cms();
            }
            if (this.piziot_core_cms.libpiziot_core_cms_initialize() != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS)
                break;
            /*
            {
                cms_viewer_ipcamera_ref_1 = this.piziot_core_cms.libpiziot_core_p2p_cms_connect_ipcamera("FRPU9954PXFWAHPGUHF1"); //for self test only
                if (cms_viewer_ipcamera_ref_1 != -1) {
                    this.piziot_core_cms.libpiziot_core_p2p_cms_enable_ipcamera_channel(cms_viewer_ipcamera_ref_1, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
                }
            }
            */
            /*
            {
                cms_viewer_ipcamera_ref_2 = this.piziot_core_cms.libpiziot_core_p2p_cms_connect_ipcamera("00:12:15:5A:40:2B"); //HI3518E
                if (cms_viewer_ipcamera_ref_2 != -1) {
                    this.piziot_core_cms.libpiziot_core_p2p_cms_enable_ipcamera_channel(cms_viewer_ipcamera_ref_2, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
                }
            }
            {
                cms_viewer_ipcamera_ref_3 = this.piziot_core_cms.libpiziot_core_p2p_cms_connect_ipcamera("00:12:16:81:CC:EA"); //HI3518EV2
                if (cms_viewer_ipcamera_ref_3 != -1) {
                    this.piziot_core_cms.libpiziot_core_p2p_cms_enable_ipcamera_channel(cms_viewer_ipcamera_ref_3, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
                }
            }
            {
                cms_viewer_nas_ref_1 = this.piziot_core_cms.libpiziot_core_p2p_cms_connect_nas("FRPU9954PXFWAHPGUHF1"); //for self test only
                if (cms_viewer_nas_ref_1 != -1) {
                    this.piziot_core_cms.libpiziot_core_p2p_cms_enable_nas_channel(cms_viewer_nas_ref_1, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
                }
            }
            {
                cms_viewer_nas_ref_2 = this.piziot_core_cms.libpiziot_core_p2p_cms_connect_nas("A0:2E:F3:00:52:89"); //RTL8881
                if (cms_viewer_nas_ref_2 != -1) {
                    this.piziot_core_cms.libpiziot_core_p2p_cms_enable_nas_channel(cms_viewer_nas_ref_2, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
                }
            }
            {
                cms_viewer_nas_ref_3 = this.piziot_core_cms.libpiziot_core_p2p_cms_connect_nas("00:E0:4C:81:96:C9"); //RTL8881
                if (cms_viewer_nas_ref_3 != -1) {
                    this.piziot_core_cms.libpiziot_core_p2p_cms_enable_nas_channel(cms_viewer_nas_ref_3, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
                }
            }
            */
            {
                cms_viewer_nas_ref_4 = this.piziot_core_cms.libpiziot_core_p2p_cms_connect_nas("20:14:07:16:01:80"); //RTL8196
                if (cms_viewer_nas_ref_4 != -1) {
                    this.piziot_core_cms.libpiziot_core_p2p_cms_enable_nas_channel(cms_viewer_nas_ref_4, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
                }
            }
            rval = jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        } while (false);
        return rval;
    }

    public int core_p2p_finalize() {
        int rval = jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE;
        do {
            if (this.piziot_core_cms == null) {
                rval = jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
                break;
            }
            if (cms_viewer_ipcamera_ref_1 != -1) {
                this.piziot_core_cms.libpiziot_core_p2p_cms_disable_ipcamera_channel(cms_viewer_ipcamera_ref_1, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
                this.piziot_core_cms.libpiziot_core_p2p_cms_disconnect_ipcamera(cms_viewer_ipcamera_ref_1); //for self cms only
                cms_viewer_ipcamera_ref_1 = -1;
            }
            if (cms_viewer_ipcamera_ref_2 != -1) {
                this.piziot_core_cms.libpiziot_core_p2p_cms_disable_ipcamera_channel(cms_viewer_ipcamera_ref_2, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
                this.piziot_core_cms.libpiziot_core_p2p_cms_disconnect_ipcamera(cms_viewer_ipcamera_ref_2); //HI3518E
                cms_viewer_ipcamera_ref_2 = -1;
            }
            if (cms_viewer_ipcamera_ref_3 != -1) {
                this.piziot_core_cms.libpiziot_core_p2p_cms_disable_ipcamera_channel(cms_viewer_ipcamera_ref_3, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND);
                this.piziot_core_cms.libpiziot_core_p2p_cms_disconnect_ipcamera(cms_viewer_ipcamera_ref_3); //HI3518EV2
                cms_viewer_ipcamera_ref_3 = -1;
            }
            if (cms_viewer_nas_ref_1 != -1) {
                this.piziot_core_cms.libpiziot_core_p2p_cms_disable_nas_channel(cms_viewer_nas_ref_1, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
                this.piziot_core_cms.libpiziot_core_p2p_cms_disconnect_nas(cms_viewer_nas_ref_1); //for self cms only
                cms_viewer_nas_ref_1 = -1;
            }
            if (cms_viewer_nas_ref_2 != -1) {
                this.piziot_core_cms.libpiziot_core_p2p_cms_disable_nas_channel(cms_viewer_nas_ref_2, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
                this.piziot_core_cms.libpiziot_core_p2p_cms_disconnect_nas(cms_viewer_nas_ref_2); //RTL8881
                cms_viewer_nas_ref_2 = -1;
            }
            if (cms_viewer_nas_ref_3 != -1) {
                this.piziot_core_cms.libpiziot_core_p2p_cms_disable_nas_channel(cms_viewer_nas_ref_3, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
                this.piziot_core_cms.libpiziot_core_p2p_cms_disconnect_nas(cms_viewer_nas_ref_3); //RTL8881
                cms_viewer_nas_ref_3 = -1;
            }
            if (cms_viewer_nas_ref_4 != -1) {
                this.piziot_core_cms.libpiziot_core_p2p_cms_disable_nas_channel(cms_viewer_nas_ref_4, this.piziot_core_cms.LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND);
                this.piziot_core_cms.libpiziot_core_p2p_cms_disconnect_nas(cms_viewer_nas_ref_4); //RTL8196
                cms_viewer_nas_ref_4 = -1;
            }
            this.piziot_core_cms.libpiziot_core_cms_finalize();
            this.piziot_core_cms = null;
            rval = jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS;
        } while (false);
        return rval;
    }

}
