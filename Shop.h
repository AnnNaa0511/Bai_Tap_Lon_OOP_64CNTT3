#pragma once
#include "Object.h"
#include "Item.h"
#include <conio.h>

class Shop : public Object{
    public:
        Shop(){}
        Shop(string name,int money) : Object(name, money){}
        string getName();
        int getMoney();
        void printInfor();
        int takeSomeItem(int, int);
        void addSomeItem(Item, int);
        void init(string, int);
        void setMoney(int);
        Item findItem(int);
        int getSizeOfItems();
};