// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

import UIKit

class xpiziot_p2p_device: NSObject {
    
    public var cms_viewer_ipcamera_ref_1 : Int32 = -1
    public var cms_viewer_ipcamera_ref_2 : Int32 = -1
    public var cms_viewer_ipcamera_ref_3 : Int32 = -1
    public var cms_viewer_nas_ref_1 : Int32 = -1
    public var cms_viewer_nas_ref_2 : Int32 = -1
    public var cms_viewer_nas_ref_3 : Int32 = -1
    public var cms_viewer_nas_ref_4 : Int32 = -1
    
    func core_p2p_initialize() -> libpiziot_os_type_func_result_e {
        var rval : libpiziot_os_type_func_result_e = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE
        repeat {
            if libpiziot_core_cms_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS {
                break
            }
            //var ConnectUID : String = ""
            /*
            if true {
                self.cms_viewer_ipcamera_ref_1 = libpiziot_core_p2p_cms_connect_ipcamera("FRPU9954PXFWAHPGUHF1") //for self test only
                if self.cms_viewer_ipcamera_ref_1 != -1 {
                    libpiziot_core_p2p_cms_enable_ipcamera_channel(self.cms_viewer_ipcamera_ref_1, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
                }
            }
            */
            /*
            if true {
                self.cms_viewer_ipcamera_ref_2 = libpiziot_core_p2p_cms_connect_ipcamera("00:12:15:5A:40:2B") //HI3518E
                if self.cms_viewer_ipcamera_ref_2 != -1 {
                    libpiziot_core_p2p_cms_enable_ipcamera_channel(self.cms_viewer_ipcamera_ref_2, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
                }
            }
            if true {
                self.cms_viewer_ipcamera_ref_3 = libpiziot_core_p2p_cms_connect_ipcamera("00:12:16:81:CC:EA") //HI3518EV2
                if (self.cms_viewer_ipcamera_ref_3 != -1) {
                    libpiziot_core_p2p_cms_enable_ipcamera_channel(self.cms_viewer_ipcamera_ref_3, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
                }
            }
            if true {
                self.cms_viewer_nas_ref_1 = libpiziot_core_p2p_cms_connect_nas("FRPU9954PXFWAHPGUHF1") //for self test only
                if (self.cms_viewer_nas_ref_1 != -1) {
                    libpiziot_core_p2p_cms_enable_nas_channel(self.cms_viewer_nas_ref_1, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                }
            }
            if true {
                self.cms_viewer_nas_ref_2 = libpiziot_core_p2p_cms_connect_nas("A0:2E:F3:00:52:89") //RTL8881
                if (self.cms_viewer_nas_ref_2 != -1) {
                    libpiziot_core_p2p_cms_enable_nas_channel(self.cms_viewer_nas_ref_2, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                }
            }
            if true {
                self.cms_viewer_nas_ref_3 = libpiziot_core_p2p_cms_connect_nas("00:E0:4C:81:96:C9") //RTL8881
                if (self.cms_viewer_nas_ref_3 != -1) {
                    libpiziot_core_p2p_cms_enable_nas_channel(self.cms_viewer_nas_ref_3, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                }
            }
            */
            self.cms_viewer_nas_ref_4 = libpiziot_core_p2p_cms_connect_nas("20:14:07:16:01:80") //RTL8196
            if (self.cms_viewer_nas_ref_4 != -1) {
                libpiziot_core_p2p_cms_enable_nas_channel(self.cms_viewer_nas_ref_4, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
            }
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS
        } while false
        return rval
    }
    
    func core_p2p_finalize() -> libpiziot_os_type_func_result_e {
        var rval : libpiziot_os_type_func_result_e = LIBPIZIOT_OS_TYPE_FUNC_RESULT_FAILURE
        repeat {
            if (self.cms_viewer_ipcamera_ref_1 != -1) {
                libpiziot_core_p2p_cms_disable_ipcamera_channel(self.cms_viewer_ipcamera_ref_1, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
                libpiziot_core_p2p_cms_disconnect_ipcamera(self.cms_viewer_ipcamera_ref_1) //for self cms only
                self.cms_viewer_ipcamera_ref_1 = -1
            }
            if (self.cms_viewer_ipcamera_ref_2 != -1) {
                libpiziot_core_p2p_cms_disable_ipcamera_channel(self.cms_viewer_ipcamera_ref_2, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
                libpiziot_core_p2p_cms_disconnect_ipcamera(self.cms_viewer_ipcamera_ref_2) //HI3518E
                self.cms_viewer_ipcamera_ref_2 = -1
            }
            if (self.cms_viewer_ipcamera_ref_3 != -1) {
                libpiziot_core_p2p_cms_disable_ipcamera_channel(self.cms_viewer_ipcamera_ref_3, LIBPIZIOT_CORE_P2P_PROTOCOL_IPCAMERA_COMMAND)
                libpiziot_core_p2p_cms_disconnect_ipcamera(self.cms_viewer_ipcamera_ref_3) //HI3518EV2
                self.cms_viewer_ipcamera_ref_3 = -1
            }
            if (self.cms_viewer_nas_ref_1 != -1) {
                libpiziot_core_p2p_cms_disable_nas_channel(self.cms_viewer_nas_ref_1, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                libpiziot_core_p2p_cms_disconnect_nas(self.cms_viewer_nas_ref_1) //for self cms only
                self.cms_viewer_nas_ref_1 = -1
            }
            if (self.cms_viewer_nas_ref_2 != -1) {
                libpiziot_core_p2p_cms_disable_nas_channel(self.cms_viewer_nas_ref_2, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                libpiziot_core_p2p_cms_disconnect_nas(self.cms_viewer_nas_ref_2) //RTL8881
                self.cms_viewer_nas_ref_2 = -1
            }
            if (self.cms_viewer_nas_ref_3 != -1) {
                libpiziot_core_p2p_cms_disable_nas_channel(self.cms_viewer_nas_ref_3, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                libpiziot_core_p2p_cms_disconnect_nas(self.cms_viewer_nas_ref_3) //RTL8881
                self.cms_viewer_nas_ref_3 = -1
            }
            if (self.cms_viewer_nas_ref_4 != -1) {
                libpiziot_core_p2p_cms_disable_nas_channel(self.cms_viewer_nas_ref_4, LIBPIZIOT_CORE_P2P_PROTOCOL_NAS_COMMAND)
                libpiziot_core_p2p_cms_disconnect_nas(self.cms_viewer_nas_ref_4) //RTL8196
                self.cms_viewer_nas_ref_4 = -1
            }
            libpiziot_core_cms_finalize()
            rval = LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS
        } while false
        return rval
    }
}
