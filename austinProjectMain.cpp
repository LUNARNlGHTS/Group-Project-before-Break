#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <thread>

// for waiting, and standard specifications
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

int main() {

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
    int currentPlayerSelection, damageDealtPlayer, damageDealtEnemy;
    currentPlayerSelection = 0;
    
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
            playerAttack = 12;
            playerDefense = 10;

            // info
            cout << "The Adventurer has mainly average stats, being useful in many categories." << endl;
            cout << "Health:  " << playerHealth << endl;
            cout << "Attack:  " << playerAttack << endl;
            cout << "Defense: \n" << playerDefense << endl;

            cout << "[1] - Select             [0] - Return" << endl;
            cout << "Selection: ";
            cin >> playerClassInfoSelection;

            if (playerClassInfoSelection == 1) {

                menuStatus = false;
                shopStatus = false;
                fightStatus = true;

            }

        }
        /*
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
    while (playerClass != "Adventurer" && playerClass != "Wizard" && playerClass != "Knight") {
        cout << "Please choose a class: " << endl;
        cout << "Input: ";
        cin >> playerClass;
    }
    */
}
    // declaring things for fighting (MUST be active for the thing function)
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
            cout << "[1] - Fight            [2] - Gamble" << endl;
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
            sleep_for(seconds(5));
            playerHasInput = true;
            currentPlayerSelection = 0;

        }
    }

}