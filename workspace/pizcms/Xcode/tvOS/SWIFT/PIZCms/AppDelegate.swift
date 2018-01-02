// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    private var Flppiziot_p2p_device : xpiziot_p2p_device?
    
    func piziot_p2p_device() -> xpiziot_p2p_device? {
        return self.Flppiziot_p2p_device
    }

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.

        if (self.Flppiziot_p2p_device == nil) {
            self.Flppiziot_p2p_device = xpiziot_p2p_device()
            if(self.Flppiziot_p2p_device != nil) {
                if(self.Flppiziot_p2p_device?.core_p2p_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                }
            }
        }
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.

        if (self.Flppiziot_p2p_device != nil) {
            if(self.Flppiziot_p2p_device?.core_p2p_finalize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            self.Flppiziot_p2p_device = nil
        }
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.

        if (self.Flppiziot_p2p_device == nil) {
            self.Flppiziot_p2p_device = xpiziot_p2p_device()
            if(self.Flppiziot_p2p_device != nil) {
                if(self.Flppiziot_p2p_device?.core_p2p_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                }
            }
        }
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.

        if (self.Flppiziot_p2p_device != nil) {
            if(self.Flppiziot_p2p_device?.core_p2p_finalize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            self.Flppiziot_p2p_device = nil
        }
    }

}

