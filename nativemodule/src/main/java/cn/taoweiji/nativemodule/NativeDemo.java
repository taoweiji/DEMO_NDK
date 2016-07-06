package cn.taoweiji.nativemodule;

import android.util.Log;

public class NativeDemo {
    public static native int add(int param1, int param2);

    public static native void say(String name);

    public static native String getInfo();

    public static native void nativeToJava(NativeDemo nativeDemo);

    public int subtract(int param1, int param2) {
        Log.e("NativeDemo", String.format("%s - %s = %s", param1, param2, param1 - param2));
        return param1 - param2;
    }
}