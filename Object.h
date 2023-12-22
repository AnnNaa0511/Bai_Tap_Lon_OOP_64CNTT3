#pragma once
#include<bits/stdc++.h>
# include "Item.h"
using namespace std;

class Object{
    protected:
        string _name;
        list<Item> Items;
        int _money;
        
    public:
        Object(){}
        Object(string name,int money){
            _name = name;
            _money = money;
        }
        virtual string getName() = 0;
        virtual int getMoney() = 0;
        virtual void printInfor() = 0;
        virtual int takeSomeItem(int, int) = 0;
        virtual void addSomeItem(Item, int) = 0;
        virtual void init(string, int) = 0;
        virtual void setMoney(int) = 0;
        virtual Item findItem(int) = 0;
        virtual int getSizeOfItems() = 0;
};