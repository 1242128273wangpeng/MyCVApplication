package com.opencv.tools;

import java.util.Arrays;

/**
 * Created by WangPeng on 2018/7/1.
 */

public class Mat {
    public Mat() {
        super();
        pixels = new int[w * h];
    }

    public int[] pixels;
    public int w = 1;
    public int h = 1;

    @Override
    public String toString() {
        return "Mat{" +
                "pixels=" + Arrays.toString(pixels) +
                ", w=" + w +
                ", h=" + h +
                '}';
    }
}
