// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

import Cocoa

class ViewController: NSViewController {

    @IBOutlet weak var buttonQuit: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_MODEL: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_FWVERP2P: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_REBOOT: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_TIMEZONE: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_LOCK: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_UNLOCK: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_MUTE: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_UNMUTE: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_CALLOUT: NSButton!
    @IBOutlet weak var buttonNAS_AND_CMS_UNCALLOUT: NSButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }

    @IBAction func buttonQuit_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        if (lpNSApp.piziot_p2p_device()?.core_p2p_finalize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        exit(0);
    }

    @IBAction func buttonNAS_AND_CMS_MODEL_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_common_get_model((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_FWVERP2P_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_REBOOT_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_common_set_reboot((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_TIMEZONE_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_common_set_timezone((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_common_get_timezone((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_LOCK_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_UNLOCK_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_MUTE_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_UNMUTE_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_CALLOUT_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_UNCALLOUT_OnAction(_ sender: Any) {
        let lpNSApp: AppDelegate = NSApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpNSApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
    
}
