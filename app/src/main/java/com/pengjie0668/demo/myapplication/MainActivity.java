package com.pengjie0668.demo.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                callJavaMethodTest("您回调了java层方法");
            }
        });
    }


    //java层调用native层方法
    public native String stringFromJNI();

    //native层回调java层方法
    public void callJavaMethod(String text) {
        Toast.makeText(this, text, Toast.LENGTH_LONG).show();
    }

    //java层调用native层方法
    public native void callJavaMethodTest(String text);

}