package com.listentomeet.model;

import com.google.gson.annotations.SerializedName;


public class Login_response {
    @SerializedName("user")
   private Account account;
    @SerializedName("data")
   private Data    data;

    public Account getAccount() {
        return account;
    }

    public void setAccount(Account account) {
        this.account = account;
    }

    public Data getData() {
        return data;
    }

    public void setData(Data data) {
        this.data = data;
    }
}
