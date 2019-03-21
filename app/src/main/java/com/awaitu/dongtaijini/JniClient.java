package com.awaitu.dongtaijini;

/**
 * Created by lucky on 2019/3/18.
 */

public class JniClient {
    public	JniClient() {

    }
    static {
        System.loadLibrary("native-lib");
    }
    public static native int addInt(int a, int b);

}
