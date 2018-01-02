// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import <Cocoa/Cocoa.h>

@interface ViewController : NSViewController

@property (weak) IBOutlet NSButton *buttonQuit;
- (IBAction)buttonQuit_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_MODEL;
- (IBAction)buttonNAS_AND_CMS_MODEL_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_FWVERP2P;
- (IBAction)buttonNAS_AND_CMS_FWVERP2P_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_REBOOT;
- (IBAction)buttonNAS_AND_CMS_REBOOT_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_TIMEZONE;
- (IBAction)buttonNAS_AND_CMS_TIMEZONE_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_LOCK;
- (IBAction)buttonNAS_AND_CMS_LOCK_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_UNLOCK;
- (IBAction)buttonNAS_AND_CMS_UNLOCK_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_MUTE;
- (IBAction)buttonNAS_AND_CMS_MUTE_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_UNMUTE;
- (IBAction)buttonNAS_AND_CMS_UNMUTE_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_CALLOUT;
- (IBAction)buttonNAS_AND_CMS_CALLOUT_OnAction:(id)sender;

@property (weak) IBOutlet NSButton *buttonNAS_AND_CMS_UNCALLOUT;
- (IBAction)buttonNAS_AND_CMS_UNCALLOUT_OnAction:(id)sender;

@end

