package com.listentomeet.model;
import android.content.Context;
import android.media.audiofx.AcousticEchoCanceler;
import android.util.Log;

import com.android.volley.AuthFailureError;
import com.android.volley.NetworkError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.google.gson.Gson;
import com.google.gson.JsonParseException;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;


public class MyRequest {

    private Context context;
    private RequestQueue queue;

    public MyRequest(Context context, RequestQueue queue) {
        this.context = context;
        this.queue = queue;
    }

    public void register(final String pseudo, final String email, final String password, final RegisterCallBack callback){

        String url = "http://10.20.86.121:8081/account/inscription";

        StringRequest request = new StringRequest(Request.Method.POST, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                Log.d("HOZE_APP", response);
                Map<String, String> errors = new HashMap<>();

                try {
                    JSONObject json = new JSONObject(response);
                    int error = json.getInt("error");

                    if(error == 200){
                        callback.OnSucess("Vous êtes bien inscrit");
                        //Inscription OK
                    }else{
                        JSONObject messages = json.getJSONObject("message");
                        if(messages.has("pseudo")){
                            errors.put("pseudo", messages.getString("pseudo"));
                        }

                        if(messages.has("email")){
                            errors.put("email", messages.getString("email"));
                        }

                        if(messages.has("password")){
                            errors.put("password", messages.getString("password"));
                        }
                        callback.inputErrors(errors);
                    }
                }catch (JSONException e){
                    e.printStackTrace();
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                if (error instanceof NetworkError){
                    callback.onError("Impossible de se connecter");
                }else if(error instanceof VolleyError) {
                    callback.onError("Une erreur s'est produite, réessayer plus tard");
                }

                Log.d("APP", "ERROR = " + error);

            }
        }){
            @Override
            protected Map<String, String> getParams() throws AuthFailureError {

                Map<String, String> map = new HashMap<>();
                map.put("username", pseudo);
                map.put("email", email);
                map.put("password", password);
                return map;
            }
        };

        queue.add(request);

    }

    public interface  RegisterCallBack{

        void OnSucess(String message);
        void inputErrors(Map<String,String> errors);
        void onError(String message);

    }

    public void connection(final String email, final String password, final LoginCallBack callback){

        String url = "http://10.20.86.121:8081/account/connection";

        StringRequest request = new StringRequest(Request.Method.POST, url, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                Log.d("APP_CONNECTION", response);
                try {
                    Gson gson = new Gson();
                    Login_response login_response = gson.fromJson(response,Login_response.class);
                    switch (login_response.getData().getError()){
                        case 200:
                            Log.d("APP Deserialization", login_response.getAccount().getEmail() + " " + login_response.getAccount().getUsername() + " " + login_response.getAccount().getId());
                            callback.onSuccess(login_response.getAccount().getId(), email, "toto");

                            break;
                        case 400:
                            callback.onError("ERROR; 400");
                    }
                } catch (JsonParseException e) {
                    e.printStackTrace();
                }
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                if (error instanceof NetworkError){
                    callback.onError("Impossible de se connecter");
                }else if(error instanceof VolleyError) {
                    callback.onError("Une erreur s'est produite, réessayer plus tard");
                }

                Log.d("APP", "ERROR = " + error);

            }
        }){
            @Override
            protected Map<String, String> getParams() throws AuthFailureError {

                Map<String, String> map = new HashMap<>();
                map.put("email", email);
                map.put("password", password);
                return map;
            }
        };

        queue.add(request);

    }

    public interface LoginCallBack{
        void onSuccess(int id, String email, String pseudo);
        void onError(String message);
    }

}
