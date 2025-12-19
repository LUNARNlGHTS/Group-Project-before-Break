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

    ////////////////////////////
    //   VAR / INIT SECTION   //
    ////////////////////////////

    // for game restarting
    bool gameRunning = true;

    while (gameRunning) {
    
    // initial variables - player
    int playerHealth, playerGold, playerStatus, playerDefense, playerAttack, playerClass, playerClassInfoSelection;
    string playerName;

    // initial variables - enemies
    int enemyHealth, enemyGold, enemyStatus, enemyDefense, enemyAttack;

    // initial variables - checks
    bool menuStatus, characterSelectStatus, shopStatus, fightStatus, playerHasInput;
    menuStatus = true;
    playerClassInfoSelection = 0;

    // variables for main fight section
    int menuSelection, currentPlayerSelection, damageDealtPlayer, damageDealtEnemy, powerStrikeTurn, totalRounds, playerGameOverSelection;
    currentPlayerSelection = 0;
    powerStrikeTurn = 0;

    ///////////////////////////
    //   MAIN MENU SECTION   //
    ///////////////////////////
    
   while (menuStatus == true) {

      while (menuSelection > 2 || menuSelection < 1) {

         cout << "\n\n\n\n\n\n" << endl;

         // main menu printing
         cout << "Half Life 3" << endl;
         cout << "\n" << endl;
         cout << "[1] - Start Adventure" << endl;
         cout << "[2] - Exit" << endl;
         cout << "Selection: ";
         cin >> menuSelection;

      }

      if (menuSelection == 1) {

         menuStatus = false;
         characterSelectStatus = true;

      } else {

         gameRunning = false;
         return 0;

      }

   }

    ////////////////////////////
    //   MAIN CLASS SECTION   //
    ////////////////////////////
    
    while (characterSelectStatus == true && playerClassInfoSelection == 0) {
        cout << "\n\n\n\n\n\n" << endl;

        // main prompting
        cout << "What class would you like to play?\nEach has unique stats that are viewed upon selecting one." << endl;
        cout << "[1] - Adventurer       [2] - Wizard" << endl;
        cout << "[3] - Knight" << endl;
        cout << "Selection: ";
        cin >> playerClass;
        
        cout << "\n\n\n\n\n\n" << endl;

        if (playerClass == 1) {

            // specifying
            playerHealth = 100;
            playerAttack = 13;
            playerDefense = 10;

            // info
            cout << "The Adventurer has mainly average stats, being useful in many categories." << endl;
            cout << "Health:  " << playerHealth << endl;
            cout << "Attack:  " << playerAttack << endl;
            cout << "Defense: " << playerDefense << "\n" << endl;

            cout << "[1] - Select             [0] - Return" << endl;
            cout << "Selection: ";
            cin >> playerClassInfoSelection;

            if (playerClassInfoSelection == 1) {
                
                cout << "\n\n\n\n\n\n" << endl;
                cout << "What is your name? (this will be used to show records of your progress!)" << endl;
                cout << "Adventurer ";
                cin >> playerName;

                characterSelectStatus = false;
                shopStatus = false;
                fightStatus = true;

            } else {
                
                playerClassInfoSelection = 0;
                
            }

        } else if (playerClass == 2) {

            // specifying
            playerHealth = 90;
            playerAttack = 22;
            playerDefense = 5;

            // info
            cout << "The Wizard has a high attack power, but lower defense power compared to other characters." << endl;
            cout << "Health:  " << playerHealth << endl;
            cout << "Attack:  " << playerAttack << endl;
            cout << "Defense: " << playerDefense << "\n" << endl;

            cout << "[1] - Select             [0] - Return" << endl;
            cout << "Selection: ";
            cin >> playerClassInfoSelection;

            if (playerClassInfoSelection == 1) {

                cout << "\n\n\n\n\n\n" << endl;
                cout << "What is your name? (this will be used to show records of your progress!)" << endl;
                cout << "Wizard ";
                cin >> playerName;

                characterSelectStatus = false;
                shopStatus = false;
                fightStatus = true;

            } else {
                playerClassInfoSelection = 0;
            }

        } else if (playerClass == 3) {

            // specifying
            playerHealth = 120;
            playerAttack = 8;
            playerDefense = 18;

            // info
            cout << "The Knight is a brute, who has high defense and health, although having a lower attack." << endl;
            cout << "Health:  " << playerHealth << endl;
            cout << "Attack:  " << playerAttack << endl;
            cout << "Defense: " << playerDefense << "\n" << endl;

            cout << "[1] - Select             [0] - Return" << endl;
            cout << "Selection: ";
            cin >> playerClassInfoSelection;

            if (playerClassInfoSelection == 1) {

                cout << "\n\n\n\n\n\n" << endl;
                cout << "What is your name? (this will be used to show records of your progress!)" << endl;
                cout << "Knight ";
                cin >> playerName;

                characterSelectStatus = false;
                shopStatus = false;
                fightStatus = true;

            } else {
                playerClassInfoSelection = 0;
            }

        }
        
    }

    /////////////////////////////
    //  MAIN FIGHTING SECTION  //
    /////////////////////////////

    // declaring things for fighting (MUST be active for the thing function)
    playerHasInput = false;
    shopStatus = false;
    menuStatus = false;
    characterSelectStatus = false;
    fightStatus = true;
    totalRounds = 1;

    // inital enemy creation, gets effected per each round progressed
    int baseEnemyAttack = 10000;
    int baseEnemyHealth = 35;
    int baseEnemyDefense = 3;
    enemyAttack = baseEnemyAttack;
    enemyHealth = baseEnemyHealth;
    enemyDefense = baseEnemyDefense;
    
    // initial setting of base player stats (for when dying to reset properly)
    int basePlayerAttack = playerAttack;
    int basePlayerHealth = playerHealth;
    int basePlayerDefense = playerDefense;

    while (currentPlayerSelection == 0 && shopStatus == false && menuStatus == false && fightStatus == true && characterSelectStatus == false) {

        fightStatus = true;
        cout << "\n\n\n\n\n\n" << endl; // both of these are for new line padding, looks better

        if (playerHealth <= 0) {
            
            cout << "\033[31mYou collapsed...\033[37m" << endl;
            cout << "\n[1] - Retry            [0] - Menu" << endl;
            cout << "Selection: ";
            cin >> playerGameOverSelection;
            cout << "\n\n\n\n\n\n" << endl;
            
            if (playerGameOverSelection == 1) {
                
                // gamerule resetting
                totalRounds = 1;
                playerHasInput = false;
                shopStatus = false;
                menuStatus = false;
                characterSelectStatus = false;
                playerClassInfoSelection = 0;
                
                // enemy resetting
                enemyAttack = baseEnemyAttack;
                enemyHealth = baseEnemyHealth;
                enemyDefense = baseEnemyDefense;
                
                // player resetting
                playerAttack = basePlayerAttack;
                playerHealth = basePlayerHealth;
                playerDefense = basePlayerDefense;
                
            } else if (playerGameOverSelection == 0) {
                
                // status resetting
                menuStatus = true;
                characterSelectStatus = false;
                fightStatus = false;
                shopStatus = false;
                menuSelection = 0;

                // player input resetting
                playerClassInfoSelection = 0;
                currentPlayerSelection = 0;
                playerHasInput = false;

                continue;
                
            }
            
        }

        if (enemyHealth <= 0) {

            totalRounds = totalRounds + 1;

            cout << "You defeated the enemy! Another one approaches..." << endl;
            powerStrikeTurn = powerStrikeTurn + 1;
            sleep_for(seconds(3));
            cout << "\n\n\n\n\n\n";

            enemyAttack = baseEnemyAttack * pow(1.1, totalRounds);
            enemyHealth = baseEnemyHealth * pow(1.1, totalRounds);
            enemyDefense = baseEnemyDefense * pow(1.1, totalRounds);

            playerHasInput = false;
            currentPlayerSelection = 0;

        }

        if (playerHasInput == true) {

            while (playerHasInput == true) {

                damageDealtEnemy = enemyAttack;
                playerHealth = playerHealth - damageDealtEnemy;
                cout << "You took " << damageDealtEnemy << " points of damage!" << endl;
                sleep_for(seconds(1));
                currentPlayerSelection = 0;
                playerHasInput = false;
                powerStrikeTurn = powerStrikeTurn + 1;

            }

        } else if (playerHasInput == false) {

            // main battle scene & input
            
            // checking if health should appear red
            if (playerHealth <= 25) { 
                
                cout << "HP: \033[31m" << playerHealth 
                << "\033[37m  ATK: " << playerAttack 
                << "  DEF: " << playerDefense 
                << "  ROUND: " << totalRounds 
                << endl;
                
            } else {
                
                cout << "HP: " << playerHealth 
                << "  ATK: " << playerAttack 
                << "  DEF: " << playerDefense 
                << "  ROUND: " << totalRounds 
                << endl;
                
            }
            
            // checking if power strike should appear yellow
            if (powerStrikeTurn >= 3) {
                
                cout << "An enemy appears! What will you do?" << endl;
                cout << "[1] - Fight            \033[33m[2] - Power Strike\033[37m" << endl;
                cout << "[3] - Inspect          [4] - Defend" << endl;
                cout << "Selection: ";
                cin >> currentPlayerSelection;
                
            } else {
                
                cout << "An enemy appears! What will you do?" << endl;
                cout << "[1] - Fight            [2] - Power Strike" << endl;
                cout << "[3] - Inspect          [4] - Defend" << endl;
                cout << "Selection: ";
                cin >> currentPlayerSelection;
                
            }
            

        }

        cout << "\n\n\n\n\n\n" << endl;

        while (currentPlayerSelection == 1 && playerHasInput == false) {

            // player attacking
            damageDealtPlayer = playerAttack;
            enemyHealth = enemyHealth - damageDealtPlayer;
            cout << damageDealtPlayer << " damage was done to the enemy!" << endl;
            sleep_for(seconds(1));
            playerHasInput = true;
            currentPlayerSelection = 0;

        }
        while (currentPlayerSelection == 2) {

            if (powerStrikeTurn >= 3) {

                // power strike attacking
                damageDealtPlayer = playerAttack;
                damageDealtPlayer = damageDealtPlayer * 3;
                enemyHealth = enemyHealth - damageDealtPlayer;
                cout << "A power strike of " << damageDealtPlayer << " damage was done to the enemy!!" << endl;
                sleep_for(seconds(1));

                // resetting
                powerStrikeTurn = powerStrikeTurn - 4;
                damageDealtPlayer = playerAttack;
                playerHasInput = true;
                currentPlayerSelection = 0;

            } else if (powerStrikeTurn <= 2) {

                // if player hasn't charged power strike for 3 rounds
                cout << "You need to charge your power strike for 3 rounds (currently " << powerStrikeTurn << ") in order to power strike!" << endl;
                cout << "\n[0] - Quit" << endl;
                cout << "Selection: ";
                cin >> currentPlayerSelection;

            }
            
        }

        while (currentPlayerSelection == 3) {

            // stat displaying
            cout << "Stats of the current enemy" << endl;
            cout << "HP:  " << enemyHealth << endl;
            cout << "ATK:  " << enemyAttack << endl;
            cout << "DEF: " << enemyDefense << endl;
            cout << "STATUS:  " << enemyStatus << endl;
            cout << "\n[0] - Quit" << endl;
            cout << "Selection: ";
            cin >> currentPlayerSelection;

        }

        while (currentPlayerSelection == 4) {

            cout << "Stats of the current enemy" << endl;
            cout << "Health:  " << enemyHealth << endl;
            cout << "Attack:  " << enemyAttack << endl;
            cout << "Defense: " << enemyDefense << endl;
            cout << "Status:  " << enemyStatus << endl;
            cout << "\n[0] - Quit" << endl;
            cout << "Selection: ";
            cin >> currentPlayerSelection;

        }

        while (currentPlayerSelection >= 5) {

            currentPlayerSelection = 0;

        }
      
    }
    
    ///////////////////////////
    //   MAIN SHOP SECTION   //
    ///////////////////////////
    
    // shop selection options
    string shopOpt1, shopOpt2, shopOpt3;

    // shop items
    string shopItem1 = "Health Potion: Heals 20 HP";
    string shopItem2 = "Mega Health Potion: Heals 50 HP";
    string shopItem3 = "Dull Sword: Increases ATK by 3";
    string shopItem4 = "Crowbar: Increases ATK by 10";
    string shopItem5 = "Wooden Shield: Increases DEF by 3";
    string shopItem6 = "Iron Shield: Increases DEF by 10";

    // shop pricing
    int shopPrice1;
    int shopPrice2;
    int shopPrice3;

    // shop choosing
    int shopChoice;

    // random elements for shopping
    random_device rd;
    mt19937 rng(rd()); 
    uniform_int_distribution<int> uni(1, 100);
    int randomInteger = uni(rng);

    while (shopStatus == true) {
      
    // decide the three items going to be in the shop from a list of 8 items 2 to increase each stat and 2 health potions with two tiers for each stat and potion
    for (int i = 0; i<3; i++) {

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

}
