// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    private var Flppiziot_p2p_device : xpiziot_p2p_device?
    
    func piziot_p2p_device() -> xpiziot_p2p_device? {
        return self.Flppiziot_p2p_device
    }

    func applicationDidFinishLaunching(_ aNotification: Notification) {
        // Insert code here to initialize your application

        if (self.Flppiziot_p2p_device == nil) {
            self.Flppiziot_p2p_device = xpiziot_p2p_device()
            if(self.Flppiziot_p2p_device != nil) {
                if(self.Flppiziot_p2p_device?.core_p2p_initialize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
                }
            }
        }
    }

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application

        if (self.Flppiziot_p2p_device != nil) {
            if(self.Flppiziot_p2p_device?.core_p2p_finalize() != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            self.Flppiziot_p2p_device = nil
        }
    }

}
