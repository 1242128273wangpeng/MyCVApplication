package com.opencv.tools;

import java.util.UUID;

/**
 * Created by WangPeng on 2018/6/30.
 */

public class Tools {
    public static String Tag = "tools";
    public int COUNT = 20;

    public native Mat printMat(Mat m);

    public int randomNumber() {
        return (int) (Math.random() * 100 + 200);
    }

    public static String getUUID() {
        return UUID.randomUUID().toString();
    }

    public static native int[] ImageBlur(int[] pixels, int w, int h);

    public static native void changeValue();

    public native void changeValue2();

    public native int callRandomNumber();

    public static native String callStaticUUID();

}
