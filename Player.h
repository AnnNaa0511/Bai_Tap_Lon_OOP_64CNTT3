#pragma once
#include "Object.h"
#include "Item.h"
#include <conio.h>

class Player : public Object{
    private:
        int _HP;
        int _ATK;
        int _MATK;
        int _DEF;
        int _MANA;
        string _TYPE;
    public:
        Player(){}
        Player(string name, int money) : Object(name, money){
            _HP = 200;
            _ATK = 4;
            _MATK = 15;
            _DEF = 10;
            _MANA = 100;
            _TYPE = "None";
        }
        void useItem(Item);
        int getHP();
        int getATK();
        int getMATK();
        int getDEF();
        int getMANA();
        string getType();
        void setHP(int);
        void setATK(int);
        void setMATK(int);
        void setDEF(int);
        void setMANA(int);
        void setTYPE(string);
        string getName();
        int getMoney();
        void printInfor();
        int takeSomeItem(int, int);
        void addSomeItem(Item,int);
        void init(string,int);
        void setMoney(int);
        int getSizeOfItems();
        Item findItem(int);
        void printPower();
        void takeOneItem(Item);
};