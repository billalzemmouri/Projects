package com.example.shark.todolist;
import android.graphics.Outline;

import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.PorterDuff;
import android.graphics.drawable.Drawable;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {

    DbHelper dbHelper;
    static ArrayAdapter<String> mAdapter;
    static ArrayAdapter<String> nAdapter;

    ListView lstTask;
    private static final String TAG = "myApp";
    private static int a =0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
        dbHelper = new DbHelper(this);
        lstTask = (ListView) findViewById(R.id.lstTask);
        loadTaskList();
    }

    private void loadTaskList() {
        int i = 0;
        ArrayList<String> tasList = new ArrayList<>();
        ArrayList<Task> taList = dbHelper.getTaskList();
        while(taList.size() > i ){
            tasList.add(taList.get(i).getName());
            i = i + 1;
        }
        if (mAdapter == null) {
            Log.v(TAG,"3");
            mAdapter = new ArrayAdapter<String>(this , R.layout.row, R.id.task__title);
            lstTask.setAdapter(mAdapter);
        }
        else{
            Log.v(TAG,"4");
            mAdapter.clear();
            mAdapter.addAll(tasList);
            mAdapter.notifyDataSetChanged();
        }
    }

    @Override

    public boolean onCreateOptionsMenu (Menu menu) {
        getMenuInflater().inflate(R.menu.menu, menu);
        Drawable icon = menu.getItem(0).getIcon();
        icon.mutate();
        icon.setColorFilter(getResources().getColor(android.R.color.white), PorterDuff.Mode.SRC_IN);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()){
                case R.id.action_add_task:
                    Intent intent = new Intent(MainActivity.this, addTaskDisplay.class);
                    startActivityForResult(intent, 1);
                return true;
        }
        return super.onOptionsItemSelected(item);
    }


    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == 1 && resultCode == Activity.RESULT_OK){
            Task task =  (Task) data.getExtras().getSerializable("task");
            dbHelper.insertNewTask(task);
            loadTaskList();
        }
    }

    public void deleteTask(View view) {
        View parent = (View)view.getParent();
        TextView taskTextView = (TextView)findViewById(R.id.task__title);
        String task = String.valueOf(taskTextView.getText());
        dbHelper.deleteTask(task);
        loadTaskList();
    }
}
