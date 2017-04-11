package com.listentomeet.model;

import com.google.gson.annotations.SerializedName;


public class Data {
    @SerializedName("status")
    String statut;
    @SerializedName("error")
    int error;

    public String getStatut() {
        return statut;
    }

    public void setStatut(String statut) {
        this.statut = statut;
    }

    public int getError() {
        return error;
    }

    public void setError(int error) {
        this.error = error;
    }
}
