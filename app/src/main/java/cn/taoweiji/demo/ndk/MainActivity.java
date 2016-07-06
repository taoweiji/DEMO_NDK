package cn.taoweiji.demo.ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import cn.taoweiji.nativemodule.NativeDemo;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("joyrun");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView textView = (TextView) findViewById(R.id.text);
        int result = NativeDemo.add(1,2);
        textView.setText("1+2=" + String.valueOf(result));

        NativeDemo.say("Hello,I am Java.");
        Log.e("MainActivity",NativeDemo.getInfo());

        NativeDemo.nativeToJava(new NativeDemo());
    }

}
