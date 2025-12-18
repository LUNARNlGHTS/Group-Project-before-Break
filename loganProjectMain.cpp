/*Still need a working looping menu that has the options ot start a new adventure then lead to 
character select or exit the program. Add a counter of some sorts maybe a total rounds cleared or
enemies beaten. Add data validation to every user input with while loops*/

#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <thread>
#include <random>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

int main() {

    // initial variables - player
    int playerHealth, playerStatus, playerDefense, playerAttack;
    int playerGold = 10;
    string playerClass, playerName;




    // player name input
    cout << "Please enter your name: ";
    cin >> playerName;

    // class declarations for basic, glass cannon, and tank
    cout << "What class would you like?: (Adventurer, Wizard, Knight)";
    cin >> playerClass;
    if(playerClass == "Adventurer"){
        playerHealth = 100;
        playerAttack = 12;
        playerDefense = 10;
    }
    if(playerClass == "Wizard"){
        playerHealth = 90;
        playerAttack = 15;
        playerDefense = 5;
    }
    if(playerClass == "Knight"){
        playerHealth = 120;
        playerAttack = 15;
        playerDefense = 20;
    }
    while(playerClass != "Adventurer" && playerClass != "Wizard" && playerClass != "Knight"){
        cout << "Please choose a class (Case sensitive)";
        cin >> playerClass;
    }
    cout << "Welcome " << playerName << " " << "to Half-Life 3!";









    // initial variables - enemies
    int enemyHealth, enemyGold, enemyStatus, enemyDefense, enemyAttack;

    // initial variables - checks
    bool menuStatus, shopStatus, fightStatus, playerHasInput;

    // variables for main fight section
    int currentPlayerSelection, currentPlayerItemSelection, damageDealtPlayer, damageDealtEnemy;
    currentPlayerSelection = 0;
    playerHasInput = false;
    shopStatus = false;
    menuStatus = false;

    while (currentPlayerSelection == 0 && shopStatus == false && menuStatus == false) {
        fightStatus = true;
        cout << "\n\n\n\n\n\n" << endl; // both of these are for new line padding, looks better

        if (playerHasInput == true) {

            while (playerHasInput == true) {

                enemyAttack = damageDealtEnemy;
                cout << "You took " << damageDealtEnemy << " points of damage!" << endl;
                sleep_for(seconds(1));
                currentPlayerSelection = 0;
                playerHasInput = false;

            }

        } else if (playerHasInput == false) {

            // main battle scene & input
            cout << "An enemy appears! What will you do?" << endl;
            cout << "[1] - Fight            [2] - Item" << endl;
            cout << "[3] - Inspect          [4] - Defend" << endl;
            cout << "Selection: ";
            cin >> currentPlayerSelection;

        }

        cout << "\n\n\n\n\n\n" << endl;

        while (currentPlayerSelection == 1 && playerHasInput == false) {

            // player attacking
            playerAttack = damageDealtPlayer;
            cout << damageDealtPlayer << " damage was done to the enemy!" << endl;
            sleep_for(seconds(1));
            playerHasInput = true;
            currentPlayerSelection = 0;

        }
        while (currentPlayerSelection == 2) {

        }
        while (currentPlayerSelection == 3) {

            cout << "Current enemies stats" << endl;
            cout << "Health:  " << enemyHealth << endl;
            cout << "Attack:  " << enemyAttack << endl;
            cout << "Defense: " << enemyDefense << endl;
            cout << "Status:  " << enemyStatus << endl;
            sleep_for(seconds(8));
            playerHasInput = true;
            currentPlayerSelection = 0;

        }
    }









   
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
    cout << "1. " << shopOpt1 << " $" << shopPrice1 << " 2. " << shopOpt2 << " $" << shopPrice2 << endl;
    cout << "3. " << shopOpt3 << " $" << shopPrice3 << " 4. Leave" << endl;
    cin >> shopChoice;
    while (shopChoice < 1 || shopChoice > 4){
      cout << "Please enter a valid choice" << endl;
      cout << "1. " << shopOpt1 << " $" << shopPrice1 << " 2. " << shopOpt2 << " $" << shopPrice2  << endl;
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
