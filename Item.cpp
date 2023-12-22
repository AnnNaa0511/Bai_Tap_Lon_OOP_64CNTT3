#include "Item.h"

void Item::printInfor(){
    cout << "*****************************************\n";
    cout << "Name: "  << _name  << endl;
    cout << "Value: " << _value << endl;
    cout << "Type: "  << _type  << endl;
    cout << "Describe: " << "\"" << _description << "\"" << endl;
    cout << "*************---------------*************\n";
}
string Item::getType(){
    return _type;
}
Item::Item(){
    _name = "";
    _value = 0;
    _count = 0;
}
Item::Item(string name, int value, string type, string description){
    _name = name;
    _value = value;
    _type = type;
    _count = 0;
    _description = description;
}
Item::Item(string name,int value){
    _name = name;
    _value = value;
    _count = 0;
}
Item::Item(string name,int value, int count){
    _name = name;
    _value = value;
    _count = count;
}
string Item::getName(){
    return _name;
}
int Item::getValue(){
    return _value;
}
int Item::getCount(){
    return _count;
}
void Item::setCount(int count){
    _count = count;
}