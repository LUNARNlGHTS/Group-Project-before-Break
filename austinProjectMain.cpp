#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

int main() {

    // initial variables - player
    int playerHealth, playerGold, playerStatus, playerDefense, playerAttack;
    string playerClass, playerName;

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

}