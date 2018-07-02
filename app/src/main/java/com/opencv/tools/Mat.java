package com.opencv.tools;

import java.util.Arrays;

/**
 * Created by WangPeng on 2018/7/1.
 */

public class Mat {
    public Mat() {
        super();
    }

    public int[] pixels = new int[30];
    public int w = 3;
    public int h = 6;

    @Override
    public String toString() {
        return "Mat{" +
                "pixels=" + Arrays.toString(pixels) +
                ", w=" + w +
                ", h=" + h +
                '}';
    }
}
