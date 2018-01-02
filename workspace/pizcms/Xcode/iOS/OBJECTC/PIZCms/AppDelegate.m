// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import "AppDelegate.h"
#import "DetailViewController.h"

#import "libpiziot/libpiziot_os/def_libpiziot_os_type.h"
#import "libpiziot/def_func.h"
#import "libpiziot/libpiziot_core_cms/def_libpiziot_core_cms.h"
#import "libpiziot/libpiziot_p2p/def_libpiziot_p2p_core.h"

#import "../../../../../libpiziot_core_cms/Linux/include/menu_config.h"

#import "libpiziot/libpiziot_os/def_libpiziot_os_debug.h"
#import "libpiziot/libpiziot_os/def_libpiziot_os_mem.h"

@interface AppDelegate () <UISplitViewControllerDelegate>

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


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    UISplitViewController *splitViewController = (UISplitViewController *)self.window.rootViewController;
    UINavigationController *navigationController = [splitViewController.viewControllers lastObject];
    navigationController.topViewController.navigationItem.leftBarButtonItem = splitViewController.displayModeButtonItem;
    splitViewController.delegate = self;

    if (self->Flppiziot_p2p_device == nil) {
        self->Flppiziot_p2p_device = [[xpiziot_p2p_device alloc] init];
        if(self->Flppiziot_p2p_device != nil) {
            if([self->Flppiziot_p2p_device core_p2p_initialize] != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.

    if (self->Flppiziot_p2p_device != nil) {
        [self->Flppiziot_p2p_device core_p2p_finalize];
        self->Flppiziot_p2p_device = nil;
    }
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.

    if (self->Flppiziot_p2p_device == nil) {
        self->Flppiziot_p2p_device = [[xpiziot_p2p_device alloc] init];
        if(self->Flppiziot_p2p_device != nil) {
            if([self->Flppiziot_p2p_device core_p2p_initialize] != LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.

    if (self->Flppiziot_p2p_device != nil) {
        [self->Flppiziot_p2p_device core_p2p_finalize];
        self->Flppiziot_p2p_device = nil;
    }
}


#pragma mark - Split view

- (BOOL)splitViewController:(UISplitViewController *)splitViewController collapseSecondaryViewController:(UIViewController *)secondaryViewController ontoPrimaryViewController:(UIViewController *)primaryViewController {
    if ([secondaryViewController isKindOfClass:[UINavigationController class]] && [[(UINavigationController *)secondaryViewController topViewController] isKindOfClass:[DetailViewController class]] && ([(DetailViewController *)[(UINavigationController *)secondaryViewController topViewController] detailItem] == nil)) {
        // Return YES to indicate that we have handled the collapse by doing nothing; the secondary controller will be discarded.
        return YES;
    } else {
        return NO;
    }
}

@end
