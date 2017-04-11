package com.example.shark.todolist;

import android.os.Parcel;
import android.os.Parcelable;

import java.io.Serializable;

/**
 * Created by Shark on 28/01/2017.
 */

public class Task implements Serializable {

        private int ID;
        private String name;
        private String commentary;
        private String date;
        private int category;

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public Task(int ID, String name, String commentary, int category,String date) {

            this.ID = ID;
            this.name = name;
            this.commentary = commentary;
            this.category = category;
        this.date = date;
        }

    public Task(String name, String commentary, int category , String date) {
        this.ID = -1;
        this.name = name;
        this.commentary = commentary;
        this.category = category;
        this.date = date;
    }

    public Task(int ID, String name, String commentary) {
        this.ID = ID;
        this.name = name;
        this.commentary = commentary;
        this.category =  0;
    }

    public String getName() {
        return name;
    }

    public String getCommentary() {
        return commentary;
    }

    public int getCategory() {
        return category;
    }

    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        date = date;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCommentary(String commentary) {
        this.commentary = commentary;
    }

    public void setCategory(int category) {
        this.category = category;
    }
}
