package com.listentomeet;

import android.content.Context;
import android.content.SharedPreferences;
import android.widget.ProgressBar;


public class SessionManager {

    private SharedPreferences prefs;
    private SharedPreferences.Editor editor;
    private final static String PREFS_NAME= "app_prefs";
    private final static int PRIVATE_MODE = 0;
    private static String IS_LOGGED = "isLogged";
    private static String EMAIL = "email";
    private static String PSEUDO = "pseudo";

    private static String ID = "id";
    private Context context;


    public SessionManager(Context context) {
        this.context = context;
        prefs = context.getSharedPreferences(PREFS_NAME, PRIVATE_MODE);
        editor = prefs.edit();
    }

    public boolean isLogged(){
        return prefs.getBoolean(IS_LOGGED, false);
    }

    public String getEmail(){
        return prefs.getString(EMAIL, null);
    }

    public int getId(){
        return prefs.getInt(ID,0);
    }
    public String getPseudo(){
        return prefs.getString(PSEUDO, null);
    }
    public void insetUser(int id, String email, String pseudo){
        editor.putBoolean(IS_LOGGED,true);
        editor.putInt(ID,id);
        editor.putString(EMAIL,email);
        editor.putString(PSEUDO,pseudo);
        editor.commit();
    }

    public void logout(){
        editor.clear().commit();
    }

}
