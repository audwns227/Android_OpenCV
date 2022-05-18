package com.example.useopencvwithcmake;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class RadiusActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.get_radius);

        TextView showradius = (TextView)findViewById(R.id.showradius);

        int radius;

        Intent intent = getIntent();
        radius = intent.getIntExtra("반지름", 0);
        showradius.setText(String.valueOf(radius));

        Log.d("receiveradius", String.valueOf(radius));

    }
}
