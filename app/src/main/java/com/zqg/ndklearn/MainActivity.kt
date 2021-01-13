package com.zqg.ndklearn

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Example of a call to a native method
        sample_text.text = stringFromJNI()

        addBtn.setOnClickListener {
            val left = leftTV.text.toString().toInt()
            val right = rightTV.text.toString().toInt()
            showToast(addNum(left, right))
        }

        subBtn.setOnClickListener {
            val left = leftTV.text.toString().toInt()
            val right = rightTV.text.toString().toInt()
            showToast(subNum(left, right))
        }
    }

    fun showToast(str: Int) {
        Toast.makeText(this, str.toString(), Toast.LENGTH_SHORT).show()
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String
    external fun addNum(a: Int, b: Int): Int
    external fun subNum(a: Int, b: Int): Int

    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }
}
