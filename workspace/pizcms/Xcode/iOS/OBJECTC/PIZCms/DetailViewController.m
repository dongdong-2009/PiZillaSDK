// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import "DetailViewController.h"
#import "AppDelegate.h"

#import "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#import "libpiziot/def_func.h"
#import "libpiziot/libpiziot_core_cms/def_libpiziot_core_cms.h"
#import "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#import "../../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#import "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#import "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

@interface DetailViewController ()

@end

@implementation DetailViewController

- (void)configureView {
    // Update the user interface for the detail item.
    if (self.detailItem) {
        self.detailDescriptionLabel.text = [self.detailItem description];
    }
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self configureView];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - Managing the detail item

- (void)setDetailItem:(NSDate *)newDetailItem {
    if (_detailItem != newDetailItem) {
        _detailItem = newDetailItem;
        
        // Update the view.
        [self configureView];
    }
}


- (IBAction)buttonNAS_AND_CMS_MODEL_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_common_get_model([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_FWVERP2P_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_REBOOT_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_common_set_reboot([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_TIMEZONE_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_common_set_timezone([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_common_get_timezone([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_LOCK_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_UNLOCK_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_MUTE_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_UNMUTE_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}

- (IBAction)buttonNAS_AND_CMS_CALLOUT_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}


- (IBAction)buttonNAS_AND_CMS_UNCALLOUT_OnTouchUpInside:(id)sender {
    AppDelegate *lpUIApp = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    xpiziot_p2p_device *lppiziot_p2p_device = [lpUIApp piziot_p2p_device];
    if(lppiziot_p2p_device != nil) {
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout([lppiziot_p2p_device cms_viewer_nas_ref_4], LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
        if(libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout([lppiziot_p2p_device cms_viewer_nas_ref_4]) != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
        }
    }
}

@end
