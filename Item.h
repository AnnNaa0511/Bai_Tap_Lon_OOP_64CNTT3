#pragma once
#include<bits/stdc++.h>
using namespace std;

class Item{
    protected:
        string _name;
        int _value;
        int _count;
        string _type;
        string _description;
    public:
        Item();
        Item(string name, int value);
        Item(string name, int value, int count);
        Item(string, int, string, string);
        string getDescription();
        string getName();
        int getValue();
        int getCount();
        void setCount(int count);
        string getType();
        void printInfor();
};
