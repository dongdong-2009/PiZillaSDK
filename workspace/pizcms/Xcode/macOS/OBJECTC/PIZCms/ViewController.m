// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import "ViewController.h"
#import "AppDelegate.h"

#import "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#import "libpiziot/def_func.h"
#import "libpiziot/libpiziot_core_cms/def_libpiziot_core_cms.h"
#import "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#import "../../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#import "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#import "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


- (IBAction)buttonQuit_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    if([lpNSApp piziot_p2p_device] != nil) {
        if([lpNSApp.piziot_p2p_device core_p2p_finalize] != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
    exit(0);
}


- (IBAction)buttonNAS_AND_CMS_MODEL_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_common_get_model([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_FWVERP2P_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_REBOOT_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_common_set_reboot([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_TIMEZONE_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_common_set_timezone([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_common_get_timezone([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_LOCK_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_UNLOCK_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_MUTE_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_UNMUTE_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_CALLOUT_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_UNCALLOUT_OnAction:(id)sender {
    AppDelegate *lpNSApp = (AppDelegate *)[NSApp delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpNSApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}

@end
