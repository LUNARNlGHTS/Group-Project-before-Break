#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <iomanip>
#include <random>

using namespace std;

int main() {

   int playerHealth = 100;
   int playerDefense = 10;
   int playerAttack = 10;
   int playerGold = 100;


   bool shopStatus = false;
   string shopOpt1, shopOpt2, shopOpt3;

   string shopItem1 = "Health Potion: Heals 20 HP";
   string shopItem2 = "Mega Health Potion: Heals 50 HP";
   string shopItem3 = "Dull Sword: Increases ATK by 3";
   string shopItem4 = "Crowbar: Increases ATK by 10";
   string shopItem5 = "Wooden Shield: Increases DEF by 3";
   string shopItem6 = "Iron Shield: Increases DEF by 10";
   

   int shopPrice1;
   int shopPrice2;
   int shopPrice3;

   int shopChoice;

   random_device rd;
   mt19937 rng(rd()); 
   uniform_int_distribution<int> uni(1, 100);
   int randomInteger = uni(rng);

   while (shopStatus == true){
      
    //decide the three items going to be in the shop from a list of 8 items 2 to increase each stat and 2 health potions with two tiers for each stat and potion
   for(int i = 0; i<3; i++){

      if (i==0){
         if(randomInteger >= 90){
            shopOpt1 = shopItem2;
            shopPrice1 = 67;
         } else if (randomInteger >= 80){
            shopOpt1 = shopItem4;
            shopPrice1 = 67;
         } else if (randomInteger >= 70){
            shopOpt1 = shopItem6;
            shopPrice1 = 67;
         } else if (randomInteger >= 50){
            shopOpt1 = shopItem3;
            shopPrice1 = 20;
         } else if (randomInteger >= 30){
            shopOpt1 = shopItem5;
            shopPrice1 = 20;
         } else {
            shopOpt1 = shopItem1;
            shopPrice1 = 15;
         }
      } else if (i==1){
         if(randomInteger >= 90){
            shopOpt2 = shopItem2;
            shopPrice2 = 67;
         } else if (randomInteger >= 80){
            shopOpt2 = shopItem4;
            shopPrice2 = 67;
         } else if (randomInteger >= 70){
            shopOpt2 = shopItem6;
            shopPrice2 = 67;
         } else if (randomInteger >= 50){
            shopOpt2 = shopItem3;
            shopPrice2 = 20;
         } else if (randomInteger >= 30){
            shopOpt2 = shopItem5;
            shopPrice2 = 20;
         } else {
            shopOpt2 = shopItem1;
            shopPrice2 = 15;
         }
      } else {
         if(randomInteger >= 90){
            shopOpt3 = shopItem2;
            shopPrice3 = 67;
         } else if (randomInteger >= 80){
            shopOpt3 = shopItem4;
            shopPrice3 = 67;
         } else if (randomInteger >= 70){
            shopOpt3 = shopItem6;
            shopPrice3 = 67;
         } else if (randomInteger >= 50){
            shopOpt3 = shopItem3;
            shopPrice3 = 20;
         } else if (randomInteger >= 30){
            shopOpt3 = shopItem5;
            shopPrice3 = 20;
         } else {
            shopOpt3 = shopItem1;
            shopPrice3 = 15;
         }
      }
      randomInteger = uni(rng);
   }

    cout << "Welcome to the shop what would you like to buy" << endl;
    cout << "1. " << shopOpt1 + " $" << shopPrice1 << " 2. " << shopOpt2 << " $" << shopPrice2 << endl;
    cout << "3. " << shopOpt3 << " $" << shopPrice3 << " 4. Leave" << endl;
    cin >> shopChoice;
    while (shopChoice < 1 || shopChoice > 4){
      cout << "Please enter a valid choice" << endl;
      cout << "1. " << shopOpt1 + " $" << shopPrice1 << " 2. " << shopOpt2 << " $" << shopPrice2  << endl;
      cout << "3. " << shopOpt3 << " $" << shopPrice3 << " 4. Leave" << endl;
      cin >> shopChoice; 
    }
    if (shopChoice == 1 && playerGold >= shopPrice1){
      if (shopOpt1 == shopItem1){
         playerHealth = playerHealth + 20;
         playerGold = playerGold - shopPrice1;
      } else if (shopOpt1 == shopItem2){
         playerHealth = playerHealth + 50;
         playerGold = playerGold - shopPrice1;
      } else if (shopOpt1 == shopItem3){
         playerAttack = playerAttack + 3;
         playerGold = playerGold - shopPrice1;
      } else if (shopOpt1 == shopItem4){
         playerAttack = playerAttack + 10;
         playerGold = playerGold - shopPrice1;
      } else if(shopOpt1 == shopItem5){
         playerDefense = playerDefense + 3;
         playerGold = playerGold - shopPrice1;
      } else {
         playerDefense = playerDefense + 10;
         playerGold = playerGold - shopPrice1;
      }
    } else if (shopChoice == 2 && playerGold >= shopPrice2){
      if (shopOpt2 == shopItem1){
         playerHealth = playerHealth + 20;
         playerGold = playerGold - shopPrice2;
      } else if (shopOpt2 == shopItem2){
         playerHealth = playerHealth + 50;
         playerGold = playerGold - shopPrice2;
      } else if (shopOpt2 == shopItem3){
         playerAttack = playerAttack + 3;
         playerGold = playerGold - shopPrice2;
      } else if (shopOpt2 == shopItem4){
         playerAttack = playerAttack + 10;
         playerGold = playerGold - shopPrice2;
      } else if(shopOpt2 == shopItem5){
         playerDefense = playerDefense + 3;
         playerGold = playerGold - shopPrice2;
      } else {
         playerDefense = playerDefense + 10;
         playerGold = playerGold - shopPrice2;
      }
    } else if (shopChoice == 3 && playerGold >= shopPrice3){
      if (shopOpt3 == shopItem1){
         playerHealth = playerHealth + 20;
         playerGold = playerGold - shopPrice3;
      } else if (shopOpt3 == shopItem2){
         playerHealth = playerHealth + 50;
         playerGold = playerGold - shopPrice3;
      } else if (shopOpt3 == shopItem3){
         playerAttack = playerAttack + 3;
         playerGold = playerGold - shopPrice3;
      } else if (shopOpt3 == shopItem4){
         playerAttack = playerAttack + 10;
         playerGold = playerGold - shopPrice3;
      } else if(shopOpt3 == shopItem5){
         playerDefense = playerDefense + 3;
         playerGold = playerGold - shopPrice3;
      } else {
         playerDefense = playerDefense + 10;
         playerGold = playerGold - shopPrice3;
      }
    } else {
      return 0;
    }
    shopStatus = false;
   }
}