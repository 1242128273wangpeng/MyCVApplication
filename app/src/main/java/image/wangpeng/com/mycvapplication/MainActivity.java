package image.wangpeng.com.mycvapplication;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.opencv.tools.Mat;
import com.opencv.tools.Tools;

public class MainActivity extends AppCompatActivity {
    private Bitmap bitmap;
    private ImageView imageView;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        imageView = findViewById(R.id.imageView);
        bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.b);
        Tools tools = new Tools();
        Log.i("main", "TAG before:" + Tools.Tag);
        Tools.changeValue();
        Log.i("main", "TAG after:" + Tools.Tag);
        Log.i("main", "COUNT before:" + tools.COUNT);
        tools.changeValue2();
        Log.i("main", "COUNT after:" + tools.COUNT);
        Log.i("main", "randomNumber call:" + tools.callRandomNumber());
        Log.i("main", "getUUID call:" + Tools.callStaticUUID());
//        Log.i("main", "printMat call:" + tools.printMat(new Mat()).toString());
        Log.i("main","mat:"+new Mat().toString());
    }

    public void loadOrigin(View view) {
        bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.b);
        imageView.setImageBitmap(bitmap);
    }

    public Bitmap doBlur(Bitmap bitmap) {
        int w = bitmap.getWidth();
        int h = bitmap.getHeight();
        int[] pixels = new int[w * h];
        bitmap.getPixels(pixels, 0, w, 0, 0, w, h);
        int images[] = Tools.ImageBlur(pixels, w, h);
        Bitmap desBitmap = Bitmap.createBitmap(w, h, Bitmap.Config.RGB_565);
        desBitmap.setPixels(images, 0, w, 0, 0, w, h);
        return desBitmap;
    }

    public void loadBlur(View view) {
        imageView.setImageBitmap(doBlur(bitmap));
    }
}
