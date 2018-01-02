// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import "AppDelegate.h"

#import "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#import "libpiziot/def_func.h"
#import "libpiziot/libpiziot_core_cms/def_libpiziot_core_cms.h"
#import "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#import "../../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#import "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#import "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

@interface AppDelegate ()

@end

@implementation AppDelegate

- (id)init {
    self = [super init];
    if(self) {
        self->Flppiziot_p2p_device = nil;
    }
    return self;
}


- (xpiziot_p2p_device *)piziot_p2p_device {
    return self->Flppiziot_p2p_device;
}


- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application

    if (self->Flppiziot_p2p_device == nil) {
        self->Flppiziot_p2p_device = [[xpiziot_p2p_device alloc] init];
        if(self->Flppiziot_p2p_device != nil) {
            if([self->Flppiziot_p2p_device core_p2p_initialize] != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application

    if (self->Flppiziot_p2p_device != nil) {
        [self->Flppiziot_p2p_device core_p2p_finalize];
        self->Flppiziot_p2p_device = nil;
    }
}


@end
