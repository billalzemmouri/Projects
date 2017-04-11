package com.listentomeet;
import android.location.LocationListener;
import android.location.LocationManager;
import android.support.annotation.IdRes;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentTransaction;
import android.widget.ImageView;

import com.google.android.gms.maps.GoogleMap;
import com.listentomeet.Fragments.ListUFragment;
import com.listentomeet.Fragments.ProfileFragment;
import com.roughike.bottombar.BottomBar;
import com.roughike.bottombar.OnTabSelectListener;

public class MapsActivity extends FragmentActivity {

    private GoogleMap mMap;
    private LocationListener locationListener;
    private LocationManager locationManager;
    private boolean isStarted = false;
    private ImageView pins;
    private BottomBar bottomBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        bottomBar = (BottomBar) findViewById(R.id.bottomBar);
        bottomBar.setOnTabSelectListener(new OnTabSelectListener() {
            @Override
            public void onTabSelected(@IdRes int tabId) {
                Fragment fragment;
                FragmentManager manager = getSupportFragmentManager();
                FragmentTransaction transaction = manager.beginTransaction();
                switch (tabId){
                    case R.id.tab_map:
                        fragment = new com.listentomeet.Fragments.MapFragment();
                        transaction.replace(R.id.container_view, fragment);
                        transaction.commit();
                        break;
                    case R.id.tab_list:
                        fragment = new ListUFragment();
                        transaction.replace(R.id.container_view, fragment);
                        transaction.commit();
                        break;
                    case R.id.tab_profile:
                        fragment = new ProfileFragment();
                        transaction.replace(R.id.container_view, fragment);
                        transaction.commit();
                        break;
                }

            }
        });
    }
}
