// LIBPIZIOT 2007/01/09, pizillaorg@gmail.com
// The solution for build your own IoT software infrastructure

#import <Foundation/Foundation.h>

@interface xpiziot_p2p_device : NSObject
{
    int32_t cms_viewer_ipcamera_ref_1;
    int32_t cms_viewer_ipcamera_ref_2;
    int32_t cms_viewer_ipcamera_ref_3;
    int32_t cms_viewer_nas_ref_1;
    int32_t cms_viewer_nas_ref_2;
    int32_t cms_viewer_nas_ref_3;
    int32_t cms_viewer_nas_ref_4;
}

- (int32_t)cms_viewer_nas_ref_4;

- (int32_t)core_p2p_initialize;
- (int32_t)core_p2p_finalize;

@end
