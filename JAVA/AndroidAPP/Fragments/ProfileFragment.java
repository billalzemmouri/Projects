package com.listentomeet.Fragments;


import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.listentomeet.MainActivity;
import com.listentomeet.R;
import com.listentomeet.SessionManager;

public class ProfileFragment extends Fragment implements View.OnClickListener {
    private SessionManager sessionManager;
    private TextView tv_pseudo;
    private TextView tv_email;
    private Button btn_logout;


    public ProfileFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View v =  inflater.inflate(R.layout.fragment_profile, container, false);
        tv_pseudo = (TextView) v.findViewById(R.id.tv_pseudo);
        tv_email = (TextView) v.findViewById(R.id.tv_email);
        btn_logout = (Button) v.findViewById(R.id.btn_logout);
        btn_logout.setOnClickListener(this);
        sessionManager = new SessionManager(getActivity());
        if(sessionManager.isLogged()) {
            String pseudo = sessionManager.getPseudo();
            int id = sessionManager.getId();
            String email = sessionManager.getEmail();
            tv_pseudo.setText(pseudo);
            tv_email.setText(email);
        }
        return v;
    }

    @Override
    public void onClick(View v) {
        sessionManager.logout();
        Intent intent  = new Intent(getActivity().getApplicationContext(),MainActivity.class);
        startActivity(intent);
        getActivity().finish();
    }
}
