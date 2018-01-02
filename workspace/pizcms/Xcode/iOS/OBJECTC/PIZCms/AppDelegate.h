// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import <UIKit/UIKit.h>

#include "libpiziot/xpiziot_p2p_device.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
    xpiziot_p2p_device *Flppiziot_p2p_device;
}

- (xpiziot_p2p_device *)piziot_p2p_device;

@property (strong, nonatomic) UIWindow *window;

@end

