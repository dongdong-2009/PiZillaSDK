// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (weak, nonatomic) IBOutlet UIButton *buttonQuit;
- (IBAction)buttonQuit_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_MODEL;
- (IBAction)buttonNAS_AND_CMS_MODEL_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_FWVERP2P;
- (IBAction)buttonNAS_AND_CMS_FWVERP2P_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_REBOOT;
- (IBAction)buttonNAS_AND_CMS_REBOOT_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_TIMEZONE;
- (IBAction)buttonNAS_AND_CMS_TIMEZONE_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_LOCK;
- (IBAction)buttonNAS_AND_CMS_LOCK_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_UNLOCK;
- (IBAction)buttonNAS_AND_CMS_UNLOCK_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_MUTE;
- (IBAction)buttonNAS_AND_CMS_MUTE_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_UNMUTE;
- (IBAction)buttonNAS_AND_CMS_UNMUTE_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_CALLOUT;
- (IBAction)buttonNAS_AND_CMS_CALLOUT_OnPrimaryActionTriggered:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_UNCALLOUT;
- (IBAction)buttonNAS_AND_CMS_UNCALLOUT_OnPrimaryActionTriggered:(id)sender;

@end
