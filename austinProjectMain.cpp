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

// for waiting, and standard specifications
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

int main() {
    
    // for game restarting
    bool gameRunning = true;

    while (gameRunning) {
    
    // initial variables - player
    int playerHealth, playerGold, playerStatus, playerDefense, playerAttack, playerClass, playerClassInfoSelection;
    string playerName;

    // initial variables - enemies
    int enemyHealth, enemyGold, enemyStatus, enemyDefense, enemyAttack;

    // initial variables - checks
    bool menuStatus, shopStatus, fightStatus, playerHasInput;
    menuStatus = true;
    playerClassInfoSelection = 0;

    // variables for main fight section
    int currentPlayerSelection, damageDealtPlayer, damageDealtEnemy, powerStrikeTurn, totalRounds, playerGameOverSelection;
    currentPlayerSelection = 0;
    powerStrikeTurn = 0;

    ////////////////////////////
    //   MAIN CLASS SECTION   //
    ////////////////////////////
    

    
    while (menuStatus == true && playerClassInfoSelection == 0) {
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

                menuStatus = false;
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

                menuStatus = false;
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

                menuStatus = false;
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
    fightStatus = true;
    totalRounds = 1;

    // inital enemy creation, gets effected per each round progressed
    int baseEnemyAttack = 10;
    int baseEnemyHealth = 35;
    int baseEnemyDefense = 3;
    enemyAttack = baseEnemyAttack;
    enemyHealth = baseEnemyHealth;
    enemyDefense = baseEnemyDefense;
    
    // initial setting of base player stats (for when dying to reset properly)
    int basePlayerAttack = playerAttack;
    int basePlayerHealth = playerHealth;
    int basePlayerDefense = playerDefense;

    while (currentPlayerSelection == 0 && shopStatus == false && menuStatus == false && fightStatus == true) {

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
                fightStatus = false;
                shopStatus = false;

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
    
    }

}