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

// prototype
int randomInt(int min, int max);

int main()
{

   // file path specifications
   ofstream outFile("./halfLife3Results.txt");
   string filePath = "./halfLife3Results.txt";
   string command = "notepad.exe \"" + filePath + "\"";

   // for game restarting
   bool gameRunning = true;

   // initial variables - player
   int playerHealth, playerGold, playerStatus, playerDefense, playerAttack, playerClass, playerClassInfoSelection, randomEvent, eventSelect;
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
   totalRounds = 1;

   // random
   random_device rd;
   mt19937 rng(rd());
   uniform_int_distribution<int> uni(1, 100);
   int randomInteger = uni(rng);
   srand(static_cast<unsigned int>(time(nullptr)));

   ////////////////////////////
   //   MAIN CLASS SECTION   //
   ////////////////////////////

   while (gameRunning)
   {

      while (menuStatus == true)
      {

         while (menuSelection > 2 || menuSelection < 1)
         {
            cout << "\n\n\n\n\n\n"
                 << endl;

            cout << "Half Life 3" << endl;
            cout << "\n"
                 << endl;
            cout << "[1] - Start Adventure" << endl;
            cout << "[2] - Exit" << endl;
            cout << "Selection: ";
            cin >> menuSelection;
         }
         if (menuSelection == 1)
         {

            menuStatus = false;
            characterSelectStatus = true;
         }
         else
         {

            gameRunning = false;
            return 0;
         }
      }

      while (characterSelectStatus == true && playerClassInfoSelection == 0)
      {
         cout << "\n\n\n\n\n\n"
              << endl;

         // main prompting
         cout << "What class would you like to play?\nEach has unique stats that are viewed upon selecting one." << endl;
         cout << "[1] - Adventurer       [2] - Wizard" << endl;
         cout << "[3] - Knight" << endl;
         cout << "Selection: ";
         cin >> playerClass;

         cout << "\n\n\n\n\n\n"
              << endl;

         if (playerClass == 1)
         {

            // specifying
            playerHealth = 100;
            playerAttack = 14;
            playerDefense = 9;
            playerGold = 19;

            // info
            cout << "The Adventurer has mainly average stats, being useful in many categories." << endl;
            cout << "Health:  " << playerHealth << endl;
            cout << "Attack:  " << playerAttack << endl;
            cout << "Gold:  " << playerGold << endl;
            cout << "Defense: " << playerDefense << "\n"
                 << endl;

            cout << "[1] - Select             [0] - Return" << endl;
            cout << "Selection: ";
            cin >> playerClassInfoSelection;

            if (playerClassInfoSelection == 1)
            {

               cout << "\n\n\n\n\n\n"
                    << endl;
               cout << "What is your name? (this will be used to show records of your progress!)" << endl;
               cout << "Adventurer ";
               cin >> playerName;
               outFile << "Adventurer " << playerName << " started their adventure!\n\n" << endl;

               characterSelectStatus = false;
               shopStatus = false;
               fightStatus = true;
            }
            else
            {

               playerClassInfoSelection = 0;
            }
         }
         else if (playerClass == 2)
         {

            // specifying
            playerHealth = 90;
            playerAttack = 19;
            playerDefense = 4;
            playerGold = 6;

            // info
            cout << "The Wizard has a high attack power, but lower defense power compared to other characters." << endl;
            cout << "Health:  " << playerHealth << endl;
            cout << "Attack:  " << playerAttack << endl;
            cout << "Gold:  " << playerGold << endl;
            cout << "Defense: " << playerDefense << "\n"
                 << endl;

            cout << "[1] - Select             [0] - Return" << endl;
            cout << "Selection: ";
            cin >> playerClassInfoSelection;

            if (playerClassInfoSelection == 1)
            {

               cout << "\n\n\n\n\n\n"
                    << endl;
               cout << "What is your name? (this will be used to show records of your progress!)" << endl;
               cout << "Wizard ";
               cin >> playerName;
               outFile << "Wizard " << playerName << " started their adventure!\n\n" << endl;

               characterSelectStatus = false;
               shopStatus = false;
               fightStatus = true;
            }
            else
            {
               playerClassInfoSelection = 0;
            }
         }
         else if (playerClass == 3)
         {

            // specifying
            playerHealth = 120;
            playerAttack = 11;
            playerDefense = 15;
            playerGold = 30;

            // info
            cout << "The Knight is a brute, who has high defense and health, although having a lower attack." << endl;
            cout << "Health:  " << playerHealth << endl;
            cout << "Attack:  " << playerAttack << endl;
            cout << "Gold:  " << playerGold << endl;
            cout << "Defense: " << playerDefense << "\n"
                 << endl;

            cout << "[1] - Select             [0] - Return" << endl;
            cout << "Selection: ";
            cin >> playerClassInfoSelection;

            if (playerClassInfoSelection == 1)
            {

               cout << "\n\n\n\n\n\n"
                    << endl;
               cout << "What is your name? (this will be used to show records of your progress!)" << endl;
               cout << "Knight ";
               cin >> playerName;
               outFile << "Knight " << playerName << " started their adventure\n\n!" << endl;

               characterSelectStatus = false;
               shopStatus = false;
               fightStatus = true;

            }
            else
            {
               playerClassInfoSelection = 0;
            }

            totalRounds = 1;
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

      // inital enemy creation, gets effected per each round progressed
      int baseEnemyAttack;
      int baseEnemyHealth;
      int baseEnemyDefense;

      if (totalRounds == 1) {

         // woo hoo printing!
         outFile << "\n\nROUND 1\n\n";

         baseEnemyAttack = 12;
         baseEnemyHealth = 35;
         baseEnemyDefense = 3;
         enemyAttack = baseEnemyAttack;
         enemyHealth = baseEnemyHealth;
         enemyDefense = baseEnemyDefense;

      } else if (totalRounds >= 1) {

         // fixes
         enemyAttack  = baseEnemyAttack * pow(1.1, totalRounds);
         enemyHealth  = baseEnemyHealth * pow(1.1, totalRounds);
         enemyDefense = baseEnemyDefense * pow(1.1, totalRounds); 

      }

      // initial setting of base player stats (for when dying to reset properly)
      int basePlayerAttack = playerAttack;
      int basePlayerHealth = playerHealth;
      int basePlayerDefense = playerDefense;


      while (currentPlayerSelection == 0 && shopStatus == false && menuStatus == false && fightStatus == true && characterSelectStatus == false)
      {

         fightStatus = true;
         cout << "\n\n\n\n\n\n"
              << endl; // both of these are for new line padding, looks better

         if (playerHealth <= 0)
         {

            // death screen
            cout << "\033[31mYou collapsed...\033[37m" << endl;
            cout << "\n[1] - Retry            [2] - Print to File" << endl;
            cout << "[0] - Menu" << endl;
            cout << "Selection: ";
            cin >> playerGameOverSelection;
            cout << "\n\n\n\n\n\n"
                 << endl;

            while (playerGameOverSelection == 1)
            {

               outFile << "After they collapsed, a new glimmer of hope shined in their eyes, allowing them to live once again.\n\n\n" << endl;

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
            }
            while (playerGameOverSelection == 2)
            {

               // file printing
               outFile << "The adventure ended here, with the player surviving " << totalRounds << " rounds." << endl;
               outFile.close();

               // display
               ifstream inFile(filePath);
               string line;

               cout << "Attempting to open results in notepad.." << endl;

               // notepad specifications for opening
               string command = "notepad.exe \"" + filePath + "\"";
               system(command.c_str());

               if (!outFile) {
                  cout << "\n\033[31mError opening file.\033[0m" << endl;

               }

               playerGameOverSelection = 0;

            }
            while (playerGameOverSelection == 0)
            {

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

         if (enemyHealth <= 0)
         {

            totalRounds = totalRounds + 1;

            cout << "You defeated the enemy, and earned a bit of gold!" << endl;
            outFile << "\nThe enemy was defeated!\n\n\n" << endl;
            outFile << "\n\nROUND " << totalRounds << "\n\n";
            playerGold = playerGold + 6 * pow(1.1, totalRounds);
            powerStrikeTurn = powerStrikeTurn + 1;
            sleep_for(seconds(3));
            cout << "\n\n\n\n\n\n";

            enemyAttack = baseEnemyAttack * pow(1.1, totalRounds);
            enemyHealth = baseEnemyHealth * pow(1.1, totalRounds);
            enemyDefense = baseEnemyDefense * pow(1.1, totalRounds);

            if (totalRounds % 3 == 0)
            {
               fightStatus = false;
               shopStatus = true;
               break;
            }

            playerHasInput = false;
            currentPlayerSelection = 0;
         }

         if (playerHasInput == true)
         {

            while (playerHasInput == true)
            {

               damageDealtEnemy = max(0, enemyAttack - playerDefense / 2);
               if (damageDealtEnemy == 0) {
                  damageDealtEnemy = 1;
               }
               playerHealth = playerHealth - damageDealtEnemy;
               cout << "You took " << damageDealtEnemy << " points of damage!" << endl;
               outFile << "The enemy dealt " << damageDealtEnemy << " points of damage!" << endl;
               sleep_for(seconds(1));
               currentPlayerSelection = 0;
               playerHasInput = false;
               powerStrikeTurn = powerStrikeTurn + 1;
            }
         }
         else if (playerHasInput == false)
         {

            // main battle scene & input

            // checking if health should appear red
            if (playerHealth <= 25)
            {

               cout << "HP: \033[31m" << playerHealth
                    << "\033[37m  ATK: " << playerAttack
                    << "  DEF: " << playerDefense
                    << "  ROUND: " << totalRounds
                    << "  GOLD: " << playerGold
                    << endl;
            }
            else
            {

               cout << "HP: " << playerHealth
                    << "  ATK: " << playerAttack
                    << "  DEF: " << playerDefense
                    << "  ROUND: " << totalRounds
                    << "  GOLD: " << playerGold
                    << endl;
            }

            // checking if power strike should appear yellow
            if (powerStrikeTurn >= 3)
            {

               cout << "An enemy appears! What will you do?" << endl;
               cout << "[1] - Fight            \033[33m[2] - Power Strike\033[37m" << endl;
               cout << "[3] - Inspect" << endl;
               cout << "Selection: ";
               cin >> currentPlayerSelection;
            }
            else
            {

               cout << "An enemy appears! What will you do?" << endl;
               cout << "[1] - Fight            [2] - Power Strike" << endl;
               cout << "[3] - Inspect" << endl;
               cout << "Selection: ";
               cin >> currentPlayerSelection;
            }
         }

         cout << "\n\n\n\n\n\n"
              << endl;

         while (currentPlayerSelection == 1 && playerHasInput == false)
         {

            // player attacking
            damageDealtPlayer = playerAttack;
            enemyHealth = enemyHealth - damageDealtPlayer;
            cout << damageDealtPlayer << " damage was done to the enemy!" << endl;
            outFile << damageDealtPlayer << " damage was done to the enemy!" << endl;
            sleep_for(seconds(1));
            playerHasInput = true;
            currentPlayerSelection = 0;

            int randomEvent = randomInt(0, 100);
            if (randomEvent >= 85)
            {
               cout << "\n\n\n\n\n\n"
                    << endl;
               int eventSelect = randomInt(0, 25);
               if (eventSelect == 0)
               {

                  cout << "You tripped on the rock that holds the world together, and fell over and died. Loser.";
                  playerHealth = 0;
               }
               else if (eventSelect == 1)
               {

                  cout << "You looked into a mirror you found on the ground, and cried until you died of dehydration.";
                  playerHealth = 0;
               }
               else if (eventSelect == 2)
               {

                  cout << "You stubbed your toe. It hurts you a tiny bit.";
                  playerHealth = 1;
               }
               else if (eventSelect == 3)
               {
                  cout << "You ate dirt. nutritious";
                  playerHealth += 20;
               }
               else if (eventSelect == 4)
               {

                  cout << "You ate your index finger. This turns out to heal you, I guess.";
                  playerHealth += 10;
               }
               else if (eventSelect == 5)
               {
                  cout << "You had a stroke.";
                  playerHealth = 0;
               }
               else if (eventSelect == 6)
               {

                  cout << "You found a penny on the ground. It's on heads, so you feel an overwhelming sense of power.";
                  playerGold += 1;
                  playerAttack = playerAttack * 1.3;
               }
               else if (eventSelect == 7)
               {
                  cout << "You harrassed a baby into surrendering her candy to you.";
                  playerHealth += 5;
               }
               else if (eventSelect == 8)
               {
                  cout << "You went to the wrong block and King Von attacks you.";
                  playerHealth -= 10;
               }
               else if (eventSelect == 9)
               {
                  cout << "You feed a hungry landshark a pizza. Tobey Maguire. It pays you.";
                  playerGold += 20;
               }
               else if (eventSelect == 10)
               {
                  cout << "You found a magic brick wall. It told you that your grandma lied when she said you're handsome.";
                  playerHealth -= 5;
               }
               else if (eventSelect == 11)
               {
                  cout << "You found a sentient blade of grass, it gives you the overwhelming crushing truth about your love life.";
                  playerHealth -= 5;
               }
               else if (eventSelect == 12)
               {
                  cout << "You admire the beauty of a mutated frog that consists of no body, no eyes, no legs, but has a single arm.";
                  playerHealth += 3;
               }
               else if (eventSelect == 13)
               {
                  cout << "You ate a rock and felt more confident.";
                  playerHealth += 5;
               }
               else if (eventSelect == 14)
               {
                  cout << "You ran into Batman, but it's ok, as you're a law abiding citizen.";
                  playerAttack += 1;
               }
               else if (eventSelect == 15)
               {
                  cout << "Oh my lord is that John Roblox?!?";
                  playerGold += 5;
               }
               else if (eventSelect == 16)
               {
                  cout << "You saw a half a cockroach do a triple backflip. You are filled with determination.";
                     playerDefense += 1;
               }
               else if (eventSelect == 17)
               {
                  cout << "You caught Xaiver talking to a freshman, you are deeply and uterly disturbed.";
                     playerDefense -= 1;
               }
               else if (eventSelect == 18)
               {
                  cout << "You found Coleman, drifted off into a deep state of zoned out, you are intimidated.";
                     playerAttack -= 1;
               }
               else if (eventSelect == 19)
               {
                  cout << "Obama Prism";
                  playerGold += 15;
               }
               else if (eventSelect == 20)
               {
                  cout << "You ran into a angry monkey, he attacks you.";
                  playerHealth -=1;
               }
               else if (eventSelect == 21)
               {
                  cout << "You almost missed your attack, you are :Skull Moji:.";
                  playerAttack -=1;
               }
               else if (eventSelect == 22)
               {
                  cout << "You feel some strange power growing from inside you.";
                  playerAttack += 3;
               }
               else if (eventSelect == 23)
               {
                  cout << "You find a T.rex, your filled with primal awe.";
                  playerDefense += 2;
               }
               else if (eventSelect == 24)
               {
                  cout << "Is that Joe Rogan????";
                     playerDefense -= 2;
               }
               else if (eventSelect == 25)
               {
                  cout << "You're hungry.";
                  playerAttack -= 1;
                  playerDefense -=1;
               }

               cout << "\n";
               sleep_for(seconds(3));

               // resetting post random event
               playerHasInput = true;
               currentPlayerSelection = 0;
            }
         }
         while (currentPlayerSelection == 2)
         {

            if (powerStrikeTurn >= 3)
            {

               // power strike attacking
               damageDealtPlayer = playerAttack;
               damageDealtPlayer = damageDealtPlayer * 3;
               enemyHealth = enemyHealth - damageDealtPlayer;
               cout << "A power strike of " << damageDealtPlayer << " damage was done to the enemy!!" << endl;
               outFile << "A power strike of " << damageDealtPlayer << " damage was done to the enemy!!" << endl;
               sleep_for(seconds(1));

               // resetting
               powerStrikeTurn = powerStrikeTurn - 4;
               damageDealtPlayer = playerAttack;
               playerHasInput = true;
               currentPlayerSelection = 0;
            }
            else if (powerStrikeTurn <= 2)
            {

               // if player hasn't charged power strike for 3 rounds
               cout << "You need to charge your power strike for 3 rounds (currently " << powerStrikeTurn << ") in order to power strike!" << endl;
               cout << "\n[0] - Quit" << endl;
               cout << "Selection: ";
               cin >> currentPlayerSelection;
            }
         }

         while (currentPlayerSelection == 3)
         {

            // stat displaying
            cout << "Stats of the current enemy" << endl;
            cout << "HP:  " << enemyHealth << endl;
            cout << "ATK:  " << enemyAttack << endl;
            cout << "DEF: " << enemyDefense << endl;
            cout << "\n[0] - Quit" << endl;
            cout << "Selection: ";
            cin >> currentPlayerSelection;
         }

         while (currentPlayerSelection >= 4)
         {
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

      while (shopStatus == true)
      {

         // decide the three items going to be in the shop from a list of 8 items 2 to increase each stat and 2 health potions with two tiers for each stat and potion
         for (int i = 0; i < 3; i++)
         {

            if (i == 0)
            {
               if (randomInteger >= 90)
               {
                  shopOpt1 = shopItem2;
                  shopPrice1 = 67;
               }
               else if (randomInteger >= 80)
               {
                  shopOpt1 = shopItem4;
                  shopPrice1 = 67;
               }
               else if (randomInteger >= 70)
               {
                  shopOpt1 = shopItem6;
                  shopPrice1 = 67;
               }
               else if (randomInteger >= 50)
               {
                  shopOpt1 = shopItem3;
                  shopPrice1 = 20;
               }
               else if (randomInteger >= 30)
               {
                  shopOpt1 = shopItem5;
                  shopPrice1 = 20;
               }
               else
               {
                  shopOpt1 = shopItem1;
                  shopPrice1 = 15;
               }
            }
            else if (i == 1)
            {
               if (randomInteger >= 90)
               {
                  shopOpt2 = shopItem2;
                  shopPrice2 = 67;
               }
               else if (randomInteger >= 80)
               {
                  shopOpt2 = shopItem4;
                  shopPrice2 = 67;
               }
               else if (randomInteger >= 70)
               {
                  shopOpt2 = shopItem6;
                  shopPrice2 = 67;
               }
               else if (randomInteger >= 50)
               {
                  shopOpt2 = shopItem3;
                  shopPrice2 = 20;
               }
               else if (randomInteger >= 30)
               {
                  shopOpt2 = shopItem5;
                  shopPrice2 = 20;
               }
               else
               {
                  shopOpt2 = shopItem1;
                  shopPrice2 = 15;
               }
            }
            else
            {
               if (randomInteger >= 90)
               {
                  shopOpt3 = shopItem2;
                  shopPrice3 = 67;
               }
               else if (randomInteger >= 80)
               {
                  shopOpt3 = shopItem4;
                  shopPrice3 = 67;
               }
               else if (randomInteger >= 70)
               {
                  shopOpt3 = shopItem6;
                  shopPrice3 = 67;
               }
               else if (randomInteger >= 50)
               {
                  shopOpt3 = shopItem3;
                  shopPrice3 = 20;
               }
               else if (randomInteger >= 30)
               {
                  shopOpt3 = shopItem5;
                  shopPrice3 = 20;
               }
               else
               {
                  shopOpt3 = shopItem1;
                  shopPrice3 = 15;
               }
            }
            randomInteger = uni(rng);
         }

         cout << "\n\n\n\n\n\nHP: " << playerHealth
         << "  ATK: " << playerAttack
         << "  DEF: " << playerDefense
         << "  ROUND: " << totalRounds
         << "  GOLD: " << playerGold
         << endl;
         cout << "Welcome to the shop, what would you like to buy?" << endl << endl;
         cout << "[1] - " << shopOpt1 << " | $" << shopPrice1 << endl
              << "[2] - " << shopOpt2 << " | $" << shopPrice2 << endl;
         cout << "[3] - " << shopOpt3 << " | $" << shopPrice3 << endl
              << "[4] - Leave" << endl << endl;
              cout << "Selection: ";
         cin >> shopChoice;
         while (shopChoice < 1 || shopChoice > 4)
         {
            cout << "\n\n\n\n\n\nWelcome to the shop, what would you like to buy?" << endl << endl;
            cout << "[1] - " << shopOpt1 << " | $" << shopPrice1 << endl
            << "[2] - " << shopOpt2 << " | $" << shopPrice2 << endl;
            cout << "[3] - " << shopOpt3 << " | $" << shopPrice3 << endl
            << "[4] - Leave" << endl << endl;
            cout << "Selection: ";
            cin >> shopChoice;
         }
         if (shopChoice == 1 && playerGold >= shopPrice1)
         {
            if (shopOpt1 == shopItem1)
            {
               playerHealth = playerHealth + 20;
               playerGold = playerGold - shopPrice1;
            }
            else if (shopOpt1 == shopItem2)
            {
               playerHealth = playerHealth + 50;
               playerGold = playerGold - shopPrice1;
            }
            else if (shopOpt1 == shopItem3)
            {
               playerAttack = playerAttack + 3;
               playerGold = playerGold - shopPrice1;
            }
            else if (shopOpt1 == shopItem4)
            {
               playerAttack = playerAttack + 10;
               playerGold = playerGold - shopPrice1;
            }
            else if (shopOpt1 == shopItem5)
            {
               playerDefense = playerDefense + 3;
               playerGold = playerGold - shopPrice1;
            }
            else
            {
               playerDefense = playerDefense + 10;
               playerGold = playerGold - shopPrice1;
            }
            cout << "\n\n\n\n\n\nYou bought " << shopOpt1 << "." << endl;
            outFile << "The player bought a " << shopOpt1 << "." << endl;
            sleep_for(seconds(1));
         }
         else if (shopChoice == 2 && playerGold >= shopPrice2)
         {
            if (shopOpt2 == shopItem1)
            {
               playerHealth = playerHealth + 20;
               playerGold = playerGold - shopPrice2;
            }
            else if (shopOpt2 == shopItem2)
            {
               playerHealth = playerHealth + 50;
               playerGold = playerGold - shopPrice2;
            }
            else if (shopOpt2 == shopItem3)
            {
               playerAttack = playerAttack + 3;
               playerGold = playerGold - shopPrice2;
            }
            else if (shopOpt2 == shopItem4)
            {
               playerAttack = playerAttack + 10;
               playerGold = playerGold - shopPrice2;
            }
            else if (shopOpt2 == shopItem5)
            {
               playerDefense = playerDefense + 3;
               playerGold = playerGold - shopPrice2;
            }
            else
            {
               playerDefense = playerDefense + 10;
               playerGold = playerGold - shopPrice2;
            }
            cout << "\n\n\n\n\n\nYou bought " << shopOpt2 << endl;
            outFile << "The player bought a " << shopOpt2 << "." << endl;
            sleep_for(seconds(1));
         }
         else if (shopChoice == 3 && playerGold >= shopPrice3)
         {
            if (shopOpt3 == shopItem1)
            {
               playerHealth = playerHealth + 20;
               playerGold = playerGold - shopPrice3;
            }
            else if (shopOpt3 == shopItem2)
            {
               playerHealth = playerHealth + 50;
               playerGold = playerGold - shopPrice3;
            }
            else if (shopOpt3 == shopItem3)
            {
               playerAttack = playerAttack + 3;
               playerGold = playerGold - shopPrice3;
            }
            else if (shopOpt3 == shopItem4)
            {
               playerAttack = playerAttack + 10;
               playerGold = playerGold - shopPrice3;
            }
            else if (shopOpt3 == shopItem5)
            {
               playerDefense = playerDefense + 3;
               playerGold = playerGold - shopPrice3;
            }
            else
            {
               playerDefense = playerDefense + 10;
               playerGold = playerGold - shopPrice3;
            }
            cout << "\n\n\n\n\n\nYou bought " << shopOpt3 << endl;
            outFile << "The player bought a " << shopOpt3 << "." << endl;
            sleep_for(seconds(1));
         }
         else if (shopChoice == 4)
         {
            cout << "\n\n\n\n\n\nSee you later!" << endl;
            sleep_for(seconds(1));
         }
         else
         {
            cout << "\n\n\n\n\n\nYou were caught trying to steal from the shop, and got kicked out immediately." << endl;
            sleep_for(seconds(1));
         }

         // fix to enemies after shop
         shopStatus = false;
         fightStatus = true;

         enemyAttack  = baseEnemyAttack  * pow(1.1, totalRounds);
         enemyHealth  = baseEnemyHealth  * pow(1.1, totalRounds);
         enemyDefense = baseEnemyDefense * pow(1.1, totalRounds); 
         characterSelectStatus = false;
      }
   }
}

int randomInt(int min, int max)
{
   return rand() % (max - min + 1) + min;
}