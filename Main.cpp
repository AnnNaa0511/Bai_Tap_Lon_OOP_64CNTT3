#include "Shop.cpp"
#include "Player.cpp"
#include "Item.cpp"
#include "conio.h"    //getch() from this lib
#include "cstdlib"

Player p;
list<Shop> shops;

void printPrologue();
void initPlayer();
void initShop();
void DisplayOpening();
void DisplayOpenGame();
void DisplayShopList();
void DisplayShop();
void DisplayBuy(Shop &newShop);
void DisplaySell(Shop &newShop);
void getInforShop(Shop newShop);
void getInforInventory();
void useItemInventory();
string NFS(string s);

int main(){
    printPrologue();
    DisplayOpenGame();
    return 0;
}

void printPrologue(){
    ifstream inp1,inp2,inp3,inp4;
    inp1.open("Prologue1.txt");
    if(inp1.fail()){
        perror("Prologue1.txt");
        return;
    }
    inp2.open("Prologue2.txt");
    if(inp2.fail()){
        perror("Prologue1.txt");
        return;
    }
    inp3.open("Prologue3.txt");
    if(inp3.fail()){
        perror("Prologue1.txt");
        return;
    }
    inp4.open("Prologue4.txt");
    if(inp4.fail()){
        perror("Prologue4.txt");
        return;
    }
    string s;
    system("cls");

    while(getline(inp1,s)) cout << s << endl;
    cout<<"(Press any key to continue...)";
    getch();
    system("cls");

    while(getline(inp2,s)) cout << s << endl;
    cout<<"(Press any key to continue...)";
    getch();
    system("cls");

    while(getline(inp3,s)) cout << s << endl;  
    cout<<"(Press any key to continue...)";
    getch();
    system("cls");

    while(getline(inp4,s)) cout << s << endl;  
    cout<<"(Press any key to continue...)";
    getch();
    system("cls");
    inp1.close();
    inp2.close();
    inp3.close();
    inp4.close();
}
string NFS(string s){
    stringstream ss(s);
    string token = "";
    string rs = "";
    while(ss >> token){
        rs += token + " ";
    }
    rs.erase(rs.size() - 1);
    return rs;
}
void initPlayer(){
    string name;
    while(1){
        system("cls");
        cout<<"Enter your name sir: "; getline(cin,name);
        if(NFS(name) == ""){
            system("cls");
            cout << "Invalid Name. Please try again." << "\nPress any key to continue...";
            getch();
        }
        else if(name.size() > 10){
            system("cls");;
            cout << "Your name must be less than 11 character. Please try again." << "\nPress any key to continue...";
            getch();
        }
        else break;
    }
    p.init(name,1000);
    p.addSomeItem(Item("Wooden Sword",100, "None", "Just a normal wooden sword"),1);
    p.addSomeItem(Item("Cloth T-shirt",50, "None", "Normal cloth"),1);
    p.addSomeItem(Item("Cloth trousers", 50, "None", "Normal cloth"),1);
    p.addSomeItem(Item("Healing Potion",85,"HP+", "A normal potion"),2);
    p.addSomeItem(Item("Red Herb", 30, "HP", "Heal your body, but not your soul"),5);
    p.addSomeItem(Item("Blue Herb",40, "MANA", "All poor magicians need this"),3);
    system("cls");
    cout << "Okay let's enjoy your journey, " << name <<"!!!(^ v ^)\n";
    cout << "Press any key to continue...";
    getch();
    
}
void initShop(){
    shops.push_back(Shop("LEATHER SHOP",3000));
        shops.back().addSomeItem(Item("Wolf Skin", 70, "None", "A skin of a cunning wolf, remember never solo with it"),15);
        shops.back().addSomeItem(Item("Bear Skin", 150, "None", "To defeat this beast, we need atleast 10 well trained hunter"),10);
        shops.back().addSomeItem(Item("Tiger Skin", 250, "None", "A rare trophy of someone,can use for making armor"),7);
        shops.back().addSomeItem(Item("Phoenix Feathers", 500, "None", "It's too hot to hold by hand"),5);

    shops.push_back(Shop("EQUIPMENT SHOP",3000));
        shops.back().addSomeItem(Item("Steel Sword", 300, "None", "A sword for a well-trained knight, not for you."),14);
        shops.back().addSomeItem(Item("Silver Sword", 700, "None", "Legend said this sword can defeat a powerful vampire"),8);
        shops.back().addSomeItem(Item("Holy Sword", 1000, "None", "A Legend Sword was used by hero, certainly not for you"),3);
        shops.back().addSomeItem(Item("Leather Armor", 700, "None", "Good for hunting"),14);
        shops.back().addSomeItem(Item("Steel Armor", 1800, "None", "A heavy armor for knight"),7);
        shops.back().addSomeItem(Item("Holy Armor",3500,"None", "Only the chosen one can use it"),5);
        shops.back().addSomeItem(Item("Steel Shield", 1000, "None", "Very heavy, but it provides a large amount of defense"),5);
        shops.back().addSomeItem(Item("Holy Shield", 2700, "None", "Noone can carry it but hero"),2);

    shops.push_back(Shop("MEDICINE SHOP",3000));
        shops.back().addSomeItem(Item("Healing Potion", 150, "HP+", "A normal potion"),50);
        shops.back().addSomeItem(Item("Mana Potion", 170, "MANA+", "A normal potion"),50);
        shops.back().addSomeItem(Item("Cure Potion", 220, "MANA&HP+", "Heal your body and your mana, the richs like this"),50);
        shops.back().addSomeItem(Item("Super Healing Potion", 300, "HP++", "Potion for rich people"),20);
        shops.back().addSomeItem(Item("Super Mana Potion", 400, "MANA++", "Potion for rich people"),20);
        shops.back().addSomeItem(Item("Phoenix Potion", 800, "None", "Legend said this potion make you imortal"),5);
        shops.back().addSomeItem(Item("Red Herb",35,"HP","Heal your body, but not your soul"),100);
        shops.back().addSomeItem(Item("Blue Herb",40,"HP","All poor magicians need this"),100);
        shops.back().addSomeItem(Item("Green Herb",60,"HP&MANA","RED + BLUE = GREEN!,right?"),100);

    shops.push_back(Shop("FOOD STORE",3000));
        shops.back().addSomeItem(Item("Pork", 100, "None", "Raw meat, take from food store or a boar"),50);
        shops.back().addSomeItem(Item("Beef", 150, "None", "Raw meat and limited, because cows are used for farming"),20);
        shops.back().addSomeItem(Item("Lamb", 170, "None", "Raw meat, very soft and rich in flavor"),50);
        shops.back().addSomeItem(Item("Toasted Pork", 250, "None", "Grill meat are the best!"),20);
        shops.back().addSomeItem(Item("BeefSteak",370,"None","Grill meat are the best!"),20);
        shops.back().addSomeItem(Item("Grilled Lamb",400,"None","Grill meat are the best!"),20);
        shops.back().addSomeItem(Item("Hamberger", 230, "None" , "Fast food are not good for heath, but tasty"),50);
        shops.back().addSomeItem(Item("Meat Soup",250,"None","A good soup for cold days in Winter"),50);
}
void DisplayOpening(){
    cout << "|*=*=*=*=*=======************========*=*=*=*=*|\n";
    cout << "|        WELCOME TO BUSSINESS TRAVELER        |\n";
    cout << "|_____________________________________________|\n";
    cout << "\\--------->>>>>****************<<<<<----------/ \n";
    cout << "<1>--Start Game\n";
    cout << "<2>--Exit\n";
    cout << "Press key(1-2)\n";
}
void DisplaySell(Shop &newShop){
    while(1){
        system("cls");
        newShop.printInfor();
        cout << endl;
        p.printInfor();
        cout << endl;
        cout << "Enter the name of item you would like to sell(1-" << p.getSizeOfItems() << ") or press 0 to back: ";
        int nameGood;
        int number;
        cin >> nameGood; cin.ignore();
        if(nameGood == 0) return;
        cout << "Enter the number you would like to sell or press 0 to back: ";
        cin >> number; cin.ignore();
        if(number == 0) return;
        int test = p.takeSomeItem(nameGood,number);
        if(test == 0){
            system("cls");
            cout << "Item is not exist. Please try again.\n";
            cout << "Press any key to continue...";
            getch();
        }
        else if(test == 1){
            system("cls");
            cout << "You don't have enough item. Please try again.\n";
            cout << "Press any key to continue...";
            getch();
        }
        else if(test == 3) continue;
        else{
            if(test > newShop.getMoney()){
                system("cls");
                cout << "The shop doesn't have enough money. Please try again.\n";
                cout << "Press any key to continue...";
                getch();
            }
            else{
                p.setMoney(p.getMoney() + test);
                Item Good = p.findItem(nameGood);
                newShop.addSomeItem(Good,number);
                newShop.setMoney(newShop.getMoney() - test);
            }
        }
    }
}
void DisplayBuy(Shop &newShop){
    while(1){
        system("cls");
        newShop.printInfor();
        cout << endl;
        p.printInfor();
        cout << endl;
        cout << "Enter the ID of item you would like to buy or press 0 to back(1-" << newShop.getSizeOfItems() << "): ";
        int nameGood;
        int number;
        cin >> nameGood; cin.ignore();
        if(nameGood == 0) return;
        cout << "Enter the number you would like to buy or press 0 to back: ";
        cin >> number; cin.ignore();
        if(number == 0) return;
        int test = newShop.takeSomeItem(nameGood,number);
        if(test == 0){
            system("cls");
            cout << "Item is not exist. Please try again.\n";
            cout << "Press any key to continue...";
            getch();
        }
        else if(test == 1){
            system("cls");
            cout << "Shop doesn't have enough item for you. Please try again.\n";
            cout << "Press any key to continue...";
            getch();
        }
        else if(test == 3) continue;
        else{
            if(test > p.getMoney()){
                system("cls");
                cout << "You don't have enough money. Please try again.\n";
                cout << "Press any key to continue...";
                getch();
            }
            else{
                system("cls");
                newShop.setMoney(newShop.getMoney() + test);
                Item Good = newShop.findItem(nameGood);
                cout << "You have just bought a " << Good.getName() << endl;
                cout << "Money -" << Good.getValue() << " Gold\n";
                cout << "Press any key to continue...";
                getch();
                p.addSomeItem(Good,number);
                p.setMoney(p.getMoney() - test);
            }
        }
    }
}
void DisplayShop(Shop &newShop){
    while(1){
        system("cls");
        newShop.printInfor();
        cout << endl;
        p.printInfor();
        cout << "\nWould you like to buy or sell?\n";
        cout << "1.Buy\n2.Sell\n3.See information\n4.Exit\nPress key to choose(1-4)\n";
        char ch = getch();
        if(ch != '1' && ch != '2' && ch != '3' && ch != '4'){
            system("cls");
            cout << "Invalid input. Please try again.\n";
            cout << "Press any key to continue.";
            getch();
        }
        else if(ch == '4') return;
        else if(ch == '1') DisplayBuy(newShop);
        else if(ch == '2') DisplaySell(newShop);
        else getInforShop(newShop);
    }
}
void getInforShop(Shop newShop){
    while(1){
        system("cls");
        newShop.printInfor();
        cout << endl;
        cout << "What item do you want to see?(1-" << newShop.getSizeOfItems() << ") or press 0 to back: ";
        int inp;
        cin >> inp; cin.ignore();
        if(inp < 0 || inp > newShop.getSizeOfItems()){
            system("cls");
            cout << "Invalid input. Please try again.\n";
            cout << "Press any key to continue...";
            getch();
        }
        else if(inp == 0) return;
        else {
            system("cls");
            Item rs = newShop.findItem(inp);
            rs.printInfor();
            cout << "\nPress any key to continue...";
            getch();
        }
    }
}
void useItemInventory(){
    while(1){
        system("cls");
        p.printInfor();
        cout << endl;
        cout << "What item do you want to use?(1-" << p.getSizeOfItems() << ") or press 0 to back: ";
        int inp;
        cin >> inp; cin.ignore();
        if(inp < 0 || inp > p.getSizeOfItems()){
            system("cls");
            cout << "Invalid input. Please try again.\n";
            cout << "Press any key to continue...";
            getch();
        }
        else if(inp == 0) return;
        else {
            system("cls");
            Item rs = p.findItem(inp);
            rs.printInfor();
            if(rs.getType() == "None"){
                cout << "\nCan't use this item. Please try again.\n";
                cout << "Press any key to continue...";
                getch();
            }
            else{
                p.useItem(rs);
                if(rs.getType() != "LIGHT" && rs.getType() != "DARK" && rs.getType() != "FIRE" ) p.takeOneItem(rs);
                cout << "\nPress any key to continue...";
                getch();  
            }   
        }
    }
}
void getInforInventory(){
    while(1){
        system("cls");
        p.printInfor();
        cout << endl;
        cout << "What item do you want to see?(1-" << p.getSizeOfItems() << ") or press 0 to back: ";
        int inp;
        cin >> inp; cin.ignore();
        if(inp < 0 || inp > p.getSizeOfItems()){
            cout << "Invalid input. Please try again.\n";
            cout << "Press any key to continue...";
            getch();
        }
        else if(inp == 0) return;
        else {
            system("cls");
            Item rs = p.findItem(inp);
            rs.printInfor();
            cout << "\nPress any key to continue...";
            getch();
        }
    }
}
void DisplayShopList(){
    while(1){
        system("cls");
        cout << "What would you like to do, " << p.getName() <<"?\n";
        int i = 0;
        for(auto it = shops.begin(); it != shops.end(); it++){
            cout << "<" << i+1 << ">--GO TO " << (*it).getName() << endl;
            i++;
        }
        cout << "<" << i+1 << ">--" << "OPEN YOUR INVENTORY" << endl;
        cout << "<" << i+2 << ">--" << "SEE YOUR POWER" << endl;
        cout << "<" << i+3 << ">--" << "Exit" << endl;
        cout << "Enter your choice(1-7)";
        char ch = getch();
        if(ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7'){
            system("cls");
            cout << "Invalid input. Please try again.\n";
            cout << "Press any key to continue.";
            getch();
        }
        else if(ch == '5'){
            while(1){
                system("cls");
                p.printInfor();
                cout << "\nWhat would you do?\n";
                cout << "<1>--Use item\n";
                cout << "<2>--See information\n";
                cout << "<3>--Exit\n";
                cout << "\nEnter your choice(1-3)";
                char t = getch();
                if(t == '3') break;
                else if(t == '2') getInforInventory();
                else useItemInventory();    
            }
        }
        else if(ch == '6'){
            system("cls");
            p.printPower();
            cout << "\nPress any key to continue...";
            getch();
        }
        else if(ch == '7') return;
        else{
            int ich = ch - '0';
            ich--;
            auto iter = shops.begin();
            while (ich--) iter++;
            Shop shopp = (*iter);
            DisplayShop(shopp);
            *iter = shopp;
        }
    }
}
void DisplayOpenGame(){
    bool isDone = false;
     while(!isDone){
        p = Player();
        shops.clear();
        system("cls");
        DisplayOpening();
        char ch = getch();

        if(ch != '1' && ch != '2'){
            system("cls");
            cout << "Invalid input. Please try again.\n";
            cout << "Press any key to continue...";
            getch();
        }
        else if(ch == '2'){
                system("cls");
                cout << "|------------------------------------------------|" << endl;
                cout << "|Good Bye! Thanks for playing my game (=^ v ^=)~~|" << endl;
                cout << "|------------------------------------------------|" << endl;
                cout << "Press any key to exit...";
                getch();
                isDone = true;
        }
        else{
            initPlayer();
            initShop();
            DisplayShopList();
        }
    }
    return;
}