package com.example.shark.todolist;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.util.ArrayList;

/**
 * Created by Shark on 26/01/2017.
 */

public class DbHelper extends SQLiteOpenHelper {

    private static final String DB_NAME="ToDoList";
    private static final int DB_VER= 1;
    public static final String DB_TABLE="Task";
    public static final String DB_COLUMN_ID= "ID";
    public static final String DB_COLUMN_NAME= "TaskName";
    public static final String DB_COLUMN_COMMENTARY= "Description";
    public static final String DB_COLUMN_CATEGORY= "Category";
    public static final String DB_COLUMN_DATE= "Date";


    public DbHelper(Context context) {
        super(context, DB_NAME, null, DB_VER);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String query = String.format("CREATE TABLE %s(%s INTEGER PRIMARY KEY AUTOINCREMENT,%s TEXT NOT NULL,%s TEXT,%s INTEGER,%s TEXT);",DB_TABLE,DB_COLUMN_ID,DB_COLUMN_NAME,DB_COLUMN_COMMENTARY,DB_COLUMN_CATEGORY, DB_COLUMN_DATE);
        db.execSQL(query);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        String query = String.format("DELETE TABLE IF EXISTS %s",DB_TABLE);
        db.execSQL(query);
        onCreate(db);
    }

    public void insertNewTask(Task task){
        SQLiteDatabase db= this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put(DB_COLUMN_NAME,task.getName());
        values.put(DB_COLUMN_COMMENTARY,task.getCommentary());
        values.put(DB_COLUMN_CATEGORY,task.getCategory());
        values.put(DB_COLUMN_DATE,task.getDate());
        db.insertWithOnConflict(DB_TABLE, null, values,SQLiteDatabase.CONFLICT_REPLACE);
        db.close();
    }

    public void deleteTask(String task){
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(DB_TABLE,DB_COLUMN_NAME + " = ?" , new String[] {task});
        db.close();
    }

    public ArrayList<Task> getTaskList() {
        ArrayList<Task> taskList = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.query(DB_TABLE,new String[] {DB_COLUMN_ID, DB_COLUMN_NAME,DB_COLUMN_COMMENTARY,DB_COLUMN_CATEGORY,DB_COLUMN_DATE},null,null,null,null,null);
        while(cursor.moveToNext()){
            int indexId = cursor.getColumnIndex(DB_COLUMN_ID);
            int indexName = cursor.getColumnIndex(DB_COLUMN_NAME);
            int indexCommentary = cursor.getColumnIndex(DB_COLUMN_COMMENTARY);
            int indexCategory = cursor.getColumnIndex(DB_COLUMN_CATEGORY);
            int indexDate = cursor.getColumnIndex(DB_COLUMN_DATE);

            taskList.add(new Task(cursor.getInt(indexId),cursor.getString(indexName),cursor.getString(indexCommentary),cursor.getInt(indexCategory),cursor.getString(indexDate)));
        }
        cursor.close();
        db.close();
        return taskList;
    }
}
