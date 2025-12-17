#include <iostream>
#include <fstream> 
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
//WE DON'T WANT THE PLAY TO GET ANTHING TOO GOOD AT THE START.
int main() {

    // initial variables - player
    int playerHealth, playerStatus, playerDefense, playerAttack;
    int playerGold = 10;
    string playerClass, playerName;

    // initial variables - enemies
    int enemyHealth, enemyGold, enemyStatus, enemyDefense, enemyAttack;

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




    // main menu code would be here, including name specifics and class choosing

    // assuming general combat code would be here, cycling 3 enemies before going to the shop

    // shop code would be here, then combat would repeat same with shop every 3 rounds
 
    
}
