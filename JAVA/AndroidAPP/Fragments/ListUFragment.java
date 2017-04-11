package com.listentomeet.Fragments;


import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.listentomeet.R;

/**
 * A simple {@link Fragment} subclass.
 */
public class ListUFragment extends Fragment {
    ListView listView;


    public ListUFragment() {
        // Required empty public constructor
    }


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
       View v = inflater.inflate(R.layout.fragment_list_u, container, false);
        listView = (ListView)  v.findViewById(R.id.listView1);
        String[] prenoms = { "Manon", "Guillaume", "Julien", "Paul", "Julie"};
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(getActivity(),
                android.R.layout.simple_list_item_1, android.R.id.text1, prenoms);
        listView.setAdapter(adapter);
        return inflater.inflate(R.layout.fragment_list_u, container, false);
    }

}
