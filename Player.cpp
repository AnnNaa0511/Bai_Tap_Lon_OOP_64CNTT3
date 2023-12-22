#include "Player.h"

void Player::takeOneItem(Item newItem){
    for(auto it = Items.begin(); it != Items.end(); it++){
        if((*it).getName() == newItem.getName()){
            (*it).setCount((*it).getCount() - 1);
            if((*it).getCount() == 0) Items.erase(it);
            break;
        }
    }
}
void Player::printPower(){
    cout << "*********" << _name << "'S INFORMATION********\n";
    cout << left << setw(15) << "<Name> " << setw(15) << _name << endl;
    cout << left << setw(15) << "<HP> "   << setw(15) << _HP   << endl;
    cout << left << setw(15) << "<MANA> " << setw(15) << _MANA << endl;
    cout << left << setw(15) << "<ATK> "  << setw(15) << _ATK  << endl;
    cout << left << setw(15) << "<MATK> " << setw(15) << _MATK << endl;
    cout << left << setw(15) << "<DEF> "  << setw(15) << _DEF  << endl;
    cout << left << setw(15) << "<TYPE> " << setw(15) <<  _TYPE << endl;
    cout << "------------***********-----------\n";
}
void Player::useItem(Item x){
    string test = x.getType();
    string var1 = "HP", var2 = "MANA", var3 = "HP&MANA", var4 = "DEF", var5 = "MATK", var6 = "LIGHT", var7 = "DARK", var8 = "FIRE";
    if(test == var1){
        _HP = max(200, _HP + 25);
        cout << "You used " << x.getName() <<".\nHP +25";
    }
    else if(test == var1 + "+"){
        _HP = max(200, _HP + 55);
        cout << "You used " << x.getName() <<".\nHP +55";
    }
    else if(test == var1 + "++"){
        _HP = max(200, _HP + 85);
        cout << "You used " << x.getName() <<".\nHP +85";
    }
    else if(test == var2){
        _MANA = max(100, _MANA + 15);
        cout << "You used " << x.getName() <<".\nMANA +15";
    }
    else if(test == var2 + "+"){
        _MANA = max(100, _MANA + 25);
        cout << "You used " << x.getName() <<".\nMANA +25";
    }
    else if(test == var2 + "++"){
        _MANA = max(100, _MANA + 55);
        cout << "You used " << x.getName() <<".\nMANA +55";
    }
    else if(test == var3){
        _HP   = max(200, _HP + 15);
        _MANA = max(100, _MANA + 10);
        cout << "You used " << x.getName() <<".\nHP +15\nMANA +10";
    }
    else if(test == var3 + "+"){
        _HP   = max(200, _HP + 25);
        _MANA = max(100, _MANA + 20);
        cout << "You used " << x.getName() <<".\nHP +25\nMANA +20";
    }
    else if(test == var3 + "++"){
        _HP   = max(200, _HP + 35);
        _MANA = max(100, _MANA + 30);
        cout << "You used " << x.getName() <<".\nHP +35\nMANA +30";
    }   
    else if(test == var4){
        _DEF += 8;
        cout << "You used " << x.getName() <<".\nDEF +8";
    }       
    else if(test == var4 + "+"){
        _DEF += 13;
        cout << "You used " << x.getName() <<".\nDEF +13";
    }   
    else if(test == var4 + "++"){
        _DEF += 17;
        cout << "You used " << x.getName() <<".\nDEF +17";
    }  
    else if(test == var5){
        _MATK += 10;
        cout << "You used " << x.getName() <<".\nMATK +10";
    }            
    else if(test == var5 + "+"){
        _MATK += 15;
        cout << "You used " << x.getName() <<".\nMATK +15";
    }   
    else if(test == var5 + "++"){
        _MATK += 20;
        cout << "You used " << x.getName() <<".\nMATK +20";
    }  
    else if(test == var6){
        _TYPE = "LIGHT";
        cout << "You used " << x.getName() <<".\nYour Attack and Defend are switched to type LIGHT";
    }
    else if(test == var7){
        _TYPE = "DARK";
        cout << "You used " << x.getName() <<".\nYour Attack and Defend are switched to type DARK";
    }      
    else if(test == var8){
        _TYPE = "FIRE";
        cout << "You used " << x.getName() <<".\nYour Attack and Defend are switched to type FIRE";
    }       
}
int Player::getHP(){
    return _HP;
}
int Player::getATK(){
    return _ATK;
}
int Player::getMATK(){
    return _MATK;
}
int Player::getDEF(){
    return _DEF;
}
int Player::getMANA(){
    return _MANA;
}
string Player::getType(){
    return _TYPE;
}
void Player::setHP(int HP){
    _HP = HP;
}
void Player::setATK(int ATK){
    _ATK = ATK;
}
void Player::setMATK(int MATK){
    _MATK = MATK;
}
void Player::setDEF(int DEF){
    _DEF = DEF;
}
void Player::setMANA(int MANA){
    _MANA = MANA;
}
void Player::setTYPE(string TYPE){
    _TYPE = TYPE;
}
Item Player::findItem(int nameGood){
    auto it = Items.begin();
    nameGood--;
    while(nameGood --) it++;
    Item rs = (*it);
    if((*it).getCount() == 0) Items.erase(it);
    return rs;
}
void Player::setMoney(int money){
    _money = money;
}
string Player::getName(){
    return _name;
}
int  Player::getMoney(){
    return _money;
}
void Player::printInfor(){
    cout << "*********" << _name << "'S INVENTORY**********\n";
    int i = 1;
    cout << "Money: " << _money << " Gold" << endl;
    for(auto it = Items.begin(); it != Items.end(); it++){
        cout << left << setw(30) << "<" + to_string(i) + ">--" + (*it).getName() + " x" + to_string((*it).getCount())
        << "Price: " + to_string((*it).getValue()) + " Gold\n";
        i++;
    }
}
int Player::takeSomeItem(int newItem,int mount){
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
void Player::addSomeItem(Item newItem,int mount){
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
int Player::getSizeOfItems(){
    return Items.size();
}
void Player::init(string name,int money){
    _name = name;
    _money = money;
    _HP = 200;
    _ATK = 4;
    _MATK = 15;
    _DEF = 10;
    _MANA = 100;
    _TYPE = "None";
}