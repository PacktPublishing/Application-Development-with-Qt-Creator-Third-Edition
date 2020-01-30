package org.qtproject.example;

import android.content.Context;
import android.widget.Toast;

public class MyToast extends org.qtproject.qt5.android.bindings.QtActivity
{
    public MyToast()
    {
    }

    public static void notify(Context context, String message)
    {
	int duration = Toast.LENGTH_SHORT;
	Toast toast = Toast.makeText(context, message, duration);
	toast.show();
    }
}
