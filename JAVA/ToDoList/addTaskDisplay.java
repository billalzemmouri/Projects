package com.example.shark.todolist;

import android.app.Dialog;
import android.app.Activity;
import android.app.TimePickerDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.icu.text.SimpleDateFormat;
import android.icu.util.Calendar;
import android.net.ParseException;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.RadioButton;
import android.widget.TextView;
import android.app.DatePickerDialog;
import android.widget.TimePicker;

import java.io.Serializable;
import java.util.Date;

/**
 * Created by Shark on 29/01/2017.
 */

public class addTaskDisplay extends Activity {


    private Button btnChangeDate;
    private Button btnChangeTime;
    private int year;
    private int month;
    private int day;
    private int hour;
    private int minute;
    String datef;
    String timef;
    static final int DATE_DIALOG_ID = 999;
    static final int TIME_DIALOG_ID = 998;


    @Override

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.add_task);

        addListenerOnButton();

        final Calendar c = Calendar.getInstance();
        year = c.get(Calendar.YEAR);
        month = c.get(Calendar.MONTH);
        day = c.get(Calendar.DAY_OF_MONTH);
        hour = c.get(Calendar.HOUR_OF_DAY);
        minute = c.get(Calendar.MINUTE);

        TextView tv2 = (TextView) findViewById(R.id.textView3);
        TextView tv = (TextView) findViewById(R.id.textView2);

        SimpleDateFormat sdf = new SimpleDateFormat("dd-MM-YYYY");
        Date cal = (Date) Calendar.getInstance().getTime();
        String dateString = sdf.format(cal);
        datef = dateString;
        tv.setText(dateString);

        SimpleDateFormat sdf2 = new SimpleDateFormat("HH:mm");
        timef = sdf2.format(cal);
        tv2.setText(timef);
    }


    public void addListenerOnButton() {

        btnChangeDate = (Button) findViewById(R.id.btnChangeDate);
        btnChangeTime = (Button) findViewById(R.id.btnChangeTime);

        btnChangeDate.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {
                showDialog(DATE_DIALOG_ID);
            }

        });

        btnChangeTime.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View v) {

                showDialog(TIME_DIALOG_ID);

            }

        });

    }

    @Override
    protected Dialog onCreateDialog(int id) {
        switch (id) {
            case DATE_DIALOG_ID:
                return new DatePickerDialog(this, datePickerListener, year, month,
                        day);
            case TIME_DIALOG_ID:
                return new TimePickerDialog(this, timePickerListener, hour, minute ,false);
    }
        return null;
    }

    private TimePickerDialog.OnTimeSetListener timePickerListener = new TimePickerDialog.OnTimeSetListener() {
        // when dialog box is closed, below method will be called.
        public void onTimeSet(TimePicker view,
        int selectedHour, int selectedMinute)throws ParseException {

            String stringtodate = "" + (selectedHour) + ":" + selectedMinute ;
            SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");

            try{
                Date dateString = sdf.parse(stringtodate);
                SimpleDateFormat sdf2 = new SimpleDateFormat("HH:mm");

                TextView tv = (TextView) findViewById(R.id.textView3);
                String timef = sdf2.format(dateString);
                tv.setText(timef);
            }
            catch (java.text.ParseException e) {
                e.printStackTrace();
            }
    }
    };

    private DatePickerDialog.OnDateSetListener datePickerListener = new DatePickerDialog.OnDateSetListener() {

        public void onDateSet(DatePicker view, int selectedYear,
                              int selectedMonth, int selectedDay)throws ParseException {

            String stringtodate = "" + selectedDay + "/" + (selectedMonth + 1) + "/" + selectedYear;
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
            try{
                Date dateString = sdf.parse(stringtodate);
                SimpleDateFormat sdf2 = new SimpleDateFormat("dd-MM-YYYY");
                TextView tv = (TextView) findViewById(R.id.textView2);
                String datef = sdf2.format(dateString);
                tv.setText(datef);
            }
            catch (java.text.ParseException e) {
                e.printStackTrace();
            }

        }
    };

    public void addNewTask(View view) {
            String name = ((TextView) findViewById(R.id.Name_task)).getText().toString();
            if (name.isEmpty() == false) {
                int category;
                if (((RadioButton) findViewById(R.id.radioNormal)).isChecked() == true)
                    category = 0;
                else if (((RadioButton) findViewById(R.id.radioImportant)).isChecked() == true)
                    category = 1;
                else
                    category = 1;

                String datetime = new String(datef + " " + timef);
                Task task1 = new Task(name, ((TextView) findViewById(R.id.Commentary_task)).getText().toString(), category, datetime);
                Intent i = getIntent();
                i.putExtra("task", (Serializable) task1);
                setResult(Activity.RESULT_OK, i);
                finish();
            }
            else {
                AlertDialog dialog = new AlertDialog.Builder(this)
                        .setTitle("Error")
                        .setMessage("You must specify the name of task.")
                        .setPositiveButton("OK", null)
                        .create();
                dialog.show();
            }
        }
    }