package com.listentomeet;

import android.content.Intent;
import android.os.Handler;
import android.support.design.widget.TextInputLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.listentomeet.model.MyRequest;

public class MainActivity extends AppCompatActivity {

    private Button btn_register,btn_send;
    private TextInputLayout til_email, til_password;
    private MyRequest request;
    private RequestQueue queue;
    private ProgressBar pb_loader;
    private Handler handler;
    private SessionManager sessionManager;




    @Override
    protected void onCreate(final Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Intent intent = getIntent();
        if(intent.hasExtra("REGISTER")){
            Toast.makeText(this,intent.getStringExtra("REGISTER"),Toast.LENGTH_SHORT).show();
        }

        btn_send = (Button) findViewById(R.id.btn_send);
        btn_register = (Button) findViewById(R.id.btn_register);
        til_email = (TextInputLayout) findViewById(R.id.til_email);
        til_password = (TextInputLayout) findViewById(R.id.til_password);
        pb_loader = (ProgressBar) findViewById(R.id.pb_loader);
        queue = VolleySingleton.getInstance(this).getRequestQueue();
        request = new MyRequest(this, queue);
        handler = new Handler();
        sessionManager = new SessionManager(this);
        if(sessionManager.isLogged()){
            Intent intent2 = new Intent(this, MapsActivity.class);
            startActivity(intent2);
           finish();
        }

        btn_register.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), RegisterActivity.class);
                startActivity(intent);
            }
        });

        btn_send.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(getApplicationContext(), MapsActivity.class);
                startActivity(intent);

                final String email = til_email.getEditText().getText().toString().trim();
                final String password = til_password.getEditText().getText().toString().trim();
                pb_loader.setVisibility(View.VISIBLE);
                if(email.length() > 0 && password.length() > 0) {
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            pb_loader.setVisibility(View.VISIBLE);
                            request.connection(email, password, new MyRequest.LoginCallBack() {
                                @Override
                                public void onSuccess(int id, String email, String pseudo){
                                    pb_loader.setVisibility(View.GONE);
                                    sessionManager.insetUser(id,email,pseudo);

                                    Intent intent = new Intent(getApplicationContext(), MapsActivity.class);
                                    startActivity(intent);
                                }

                                @Override
                                public void onError(String message) {
                                    Toast.makeText(getApplicationContext(),message,Toast.LENGTH_SHORT).show();
                                    pb_loader.setVisibility(View.GONE);

                                }
                            });
                        }
                    },1000);
                }else{
                    Toast.makeText(getApplicationContext(),"Veuillez remplir tous les champs",Toast.LENGTH_SHORT).show();
                    pb_loader.setVisibility(View.GONE);

                }
            }
        });

    }
}
