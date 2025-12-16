#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <iomanip>
#include <random>

using namespace std;

int main() {
   bool shopStatus = false;
   string shopOpt1;
   string shopOpt2;
   string shopOpt3;
   
   int shopPrice1;
   int shopPrice2;
   int shopPrice3;

   int shopChoice;

   while (shopStatus == true){
    //decide the three items going to be in the shop from a list of 8 items 2 to increase each stat and 2 health potions with two tiers for each stat and potion

    cout << "Welcome to the shop what would you like to buy" << endl;
    cout << "1. " << shopOpt1 + " $" << shopPrice1 << " 2. " << shopOpt2 << " $" << shopPrice2 << " 3. " << shopOpt3 << " $" << shopPrice3 << "4. Leave" << endl;
    cin >> shopChoice;
    while (shopChoice < 1 || shopChoice > 4){
    cout << "Please enter a valid choice" << endl;
    cout << "1. " << shopOpt1 + " $" << shopPrice1 << " 2. " << shopOpt2 << " $" << shopPrice2 << " 3. " << shopOpt3 << " $" << shopPrice3 << " 4. Leave" << endl;
    cin >> shopChoice; 
    }
    if (shopChoice == 1){

    } else if (shopChoice == 2){

    } else if (shopChoice == 3){

    } else {

    }
    shopStatus = false;
   }
}