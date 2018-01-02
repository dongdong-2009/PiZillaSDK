package com.pppiziot.www.pizcms;

import android.os.Bundle;
import android.widget.TextView;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;

//import com.pppiziot.www.app.jpiziot_core_app;
import com.pppiziot.www.libpiziot.jpiziot_os;
import com.pppiziot.www.libpiziot.jpiziot_p2p_device;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'piziot_core_app' library on application startup.
    static {
        System.loadLibrary("piziot_core_app");
    }

    private jpiziot_p2p_device piziot_p2p_device = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (this.piziot_p2p_device == null) {
            this.piziot_p2p_device = new jpiziot_p2p_device();
            this.piziot_p2p_device.core_p2p_initialize();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (this.piziot_p2p_device != null) {
            this.piziot_p2p_device.core_p2p_finalize();
            this.piziot_p2p_device = null;
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    /**
     * A native method that is implemented by the 'piziot_core_app' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public void buttonQuit_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            this.piziot_p2p_device.core_p2p_finalize();
            this.piziot_p2p_device = null;
        }
        finish();
        //int j = this.piziot_p2p_device.cms_viewer_nas_ref_4;
    }

    public void buttonNAS_AND_CMS_MODEL_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_common_get_model(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_FWVERP2P_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_common_get_fwverp2p(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_REBOOT_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_common_set_reboot(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_TIMEZONE_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_common_set_timezone(this.piziot_p2p_device.cms_viewer_nas_ref_4, this.piziot_p2p_device.LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_TIMEZONE_TAIPEI) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_common_get_timezone(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_LOCK_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(this.piziot_p2p_device.cms_viewer_nas_ref_4, this.piziot_p2p_device.LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_UNLOCK_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_set_lock(this.piziot_p2p_device.cms_viewer_nas_ref_4, this.piziot_p2p_device.LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_get_lock(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_MUTE_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute(this.piziot_p2p_device.cms_viewer_nas_ref_4, this.piziot_p2p_device.LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_UNMUTE_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_set_mute(this.piziot_p2p_device.cms_viewer_nas_ref_4, this.piziot_p2p_device.LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_get_mute(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_CALLOUT_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout(this.piziot_p2p_device.cms_viewer_nas_ref_4, this.piziot_p2p_device.LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_YES) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

    public void buttonNAS_AND_CMS_UNCALLOUT_OnClick(View view) {
        if (this.piziot_p2p_device != null) {
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_set_callout(this.piziot_p2p_device.cms_viewer_nas_ref_4, this.piziot_p2p_device.LIBPIZIOT_CORE_P2P_PROTOCOL_OPTION_YN_NO) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
            if (this.piziot_p2p_device.libpiziot_core_p2p_cms_nas_channel_zigbee_get_callout(this.piziot_p2p_device.cms_viewer_nas_ref_4) != jpiziot_os.LIBPIZIOT_OS_TYPE_FUNC_RESULT_SUCCESS) {
            }
        }
    }

}
