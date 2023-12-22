#include "Shop.h"

int Shop::getSizeOfItems(){
    return Items.size();
}
Item Shop::findItem(int nameGood){
    auto it = Items.begin();
    nameGood--;
    while(nameGood --) it++;
    Item rs = (*it);
    if((*it).getCount() == 0) Items.erase(it);
    return rs;
}
void Shop::setMoney(int money){
    _money = money;
}
string Shop::getName(){
    return _name;
}
int Shop::getMoney(){
    return _money;
}
void Shop::printInfor(){
    cout << "*********\\ WELCOME TO "<<_name<<" /**********\n\n";
    int i = 1;
    cout << "Money: " << _money << " Gold" << endl;
    for(auto it = Items.begin(); it != Items.end(); it++){
        cout << left << setw(30) << "<" + to_string(i) + ">--" + (*it).getName() + " x" + to_string((*it).getCount())
        << "Price: " + to_string((*it).getValue()) + " Gold\n";
        i++;
    }
}
int Shop::takeSomeItem(int newItem, int mount){
    auto it = Items.begin();
    newItem--;
    if(newItem < 0 || (long long)newItem > (long long)Items.size()) return 0;
    while(newItem --) it++;
    if((*it).getCount() < mount){
        return 1;
    }
    cout << "Are you sure?(Y/N)\n";
    char t = getch();
    if(t == 'Y' || t == 'y'){
        (*it).setCount((*it).getCount() - mount);
    //    if((*it).getCount() == 0) Items.erase(it);
        return (*it).getValue() * mount;
    }
    return 3;
}
void Shop::addSomeItem(Item newItem, int mount){
    for(auto it = Items.begin(); it != Items.end(); it++){
        if((*it).getName() == newItem.getName()){
            (*it).setCount((*it).getCount() + mount);
            return;
        }
    }
    newItem.setCount(mount);
    Items.push_back(newItem);
    return;
}
void Shop::init(string name,int money){
    _name = name;
    _money = money;
}