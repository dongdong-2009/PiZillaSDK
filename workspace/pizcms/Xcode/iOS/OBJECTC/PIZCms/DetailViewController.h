// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController

@property (strong, nonatomic) NSDate *detailItem;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_MODEL;
- (IBAction)buttonNAS_AND_CMS_MODEL_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_FWVERP2P;
- (IBAction)buttonNAS_AND_CMS_FWVERP2P_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_REBOOT;
- (IBAction)buttonNAS_AND_CMS_REBOOT_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_TIMEZONE;
- (IBAction)buttonNAS_AND_CMS_TIMEZONE_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_LOCK;
- (IBAction)buttonNAS_AND_CMS_LOCK_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_UNLOCK;
- (IBAction)buttonNAS_AND_CMS_UNLOCK_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_MUTE;
- (IBAction)buttonNAS_AND_CMS_MUTE_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_UNMUTE;
- (IBAction)buttonNAS_AND_CMS_UNMUTE_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_CALLOUT;
- (IBAction)buttonNAS_AND_CMS_CALLOUT_OnTouchUpInside:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *buttonNAS_AND_CMS_UNCALLOUT;
- (IBAction)buttonNAS_AND_CMS_UNCALLOUT_OnTouchUpInside:(id)sender;

@end

