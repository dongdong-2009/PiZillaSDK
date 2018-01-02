// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var buttonQuit: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_MODEL: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_FWVERP2P: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_REBOOT: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_TIMEZONE: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_LOCK: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_UNLOCK: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_MUTE: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_UNMUTE: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_CALLOUT: UIButton!
    @IBOutlet weak var buttonNAS_AND_CMS_UNCALLOUT: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func buttonQuit_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        if (lpUIApp.piziot_p2p_device()?.core_p2p_finalize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        exit(0)
        //UIControl().sendAction(#selector(NSXPCConnection.suspend), to: UIApplication.shared, for: nil)
    }

    @IBAction func buttonNAS_AND_CMS_MODEL_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_common_get_model((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
    
    @IBAction func buttonNAS_AND_CMS_FWVERP2P_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_REBOOT_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_common_set_reboot((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
    
    @IBAction func buttonNAS_AND_CMS_TIMEZONE_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_common_set_timezone((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_common_get_timezone((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
    
    @IBAction func buttonNAS_AND_CMS_LOCK_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
    
    @IBAction func buttonNAS_AND_CMS_UNLOCK_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_MUTE_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
    
    @IBAction func buttonNAS_AND_CMS_UNMUTE_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    @IBAction func buttonNAS_AND_CMS_CALLOUT_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
    
    @IBAction func buttonNAS_AND_CMS_UNCALLOUT_OnPrimaryActionTriggered(_ sender: Any) {
        let lpUIApp: AppDelegate = UIApplication.shared.delegate as! AppDelegate
        let lppiziot_p2p_device : xpiziot_p2p_device? = lpUIApp.piziot_p2p_device()
        if(lppiziot_p2p_device != nil) {
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!, LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout((lppiziot_p2p_device?.cms_viewer_nas_ref_4)!) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

}
