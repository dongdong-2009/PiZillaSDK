// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import <Cocoa/Cocoa.h>

#include "libpiziot/xpiziot_p2p_device.h"

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
    xpiziot_p2p_device *Flppiziot_p2p_device;
}

- (xpiziot_p2p_device *)piziot_p2p_device;

@end

