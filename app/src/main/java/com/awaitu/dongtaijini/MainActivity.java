package com.awaitu.dongtaijini;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.

    public static final String TAG = "TestJni";
    public TextView mTv;
    public JniClient mJniClient;

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        mTv = (TextView) findViewById(R.id.text);
        mJniClient = new JniClient();
//        String result = mJniClient.getStr();
        int sum = mJniClient.addInt(2, 3);
        String summ = String.valueOf(sum);
        mTv.setText(summ);
    }
}
