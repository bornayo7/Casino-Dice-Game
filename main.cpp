//Program Name : assign_RollBones
//Date : 2024 - 8 - 30
//Author : Yash Baruah
//Module Purpose
//This program is a casino with dice.

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

unsigned askForInititalStakeAmountFunc();
unsigned askForBetDonePlayingFunc(unsigned& stakeUns);
unsigned rollDemBonesFunc(unsigned& rollCountUns);
void     evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns);
bool     pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns);

int main() {
    int stake;
  unsigned
    stakeUns,
    betUns,
    rollCountUns = 0,
    diceRollResultsUns;

    //$ assign stakeUns result from askForInititalStakeAmountFunc();
  stakeUns = askForInititalStakeAmountFunc();

  do {
    //$ assign betUns result from askForBetDonePlayingFunc(stakeUns);
    betUns = askForBetDonePlayingFunc(stakeUns);
    //$ based on betUns determine wether or not to call rollDemBonesFunc(rollCountUns)
    if (betUns == 0)  break;
    diceRollResultsUns = rollDemBonesFunc(rollCountUns);
    //$ and then call evaluateRollFunc(diceRollResultsUns, rollCountUns, stakeUns, betUns);
    evaluateRollFunc(diceRollResultsUns, rollCountUns, stakeUns, betUns);
  } while (betUns != 0 && stakeUns !=0); //$ execute loop as long as betUns != 0 and stakeUns != 0;

  
  //$ Out of loop
  //$ Check if betUns is 0 
  //$   then display player ends game
  //$   else display player out of money
  if (betUns == 0) {
      cout << "Player ends game." << endl ;
  }
  else {
      cout << "Player is out of money" << endl;
  }
  //$ display a Roll Count message;
  cout << "Roll Count: " << rollCountUns << endl;
  //$ display a final stake amount messaqge
  cout << "Final Stake Amount: " << stakeUns << endl << endl;
  // $ Hold the screen before exiting
  cout << "Press enter key once or twice to end ... ";
  cin.ignore();
  cin.get();

  exit(EXIT_SUCCESS);
}

/*
Name:              askForInitialStakeAmountFunc
Function Purpose : Retrieves the initial money from prompting the user
Function Design:   Checks if the input stake amount the player enters a proper amount:
                   stakeStartUns > 0
                   not a negative amount
Inputs:            None
Outputs:           By function name an unsigned integer that's the stake amount
*/

unsigned askForInititalStakeAmountFunc() {
   int stakeStartUns;

  do {
    //$ ask for stake amount
    cout << "What is your stake amount? ";
    cin >> stakeStartUns;
    cout << endl;
    //$ if stake amount > 0) leave check loop
    if (stakeStartUns > 0) {
        break;
    }
    //$  else 
      //$ display message that You have to enter a > 0 or positive amount of money to bet with. Try again!
      //$ continue the loop
    else {
        cout << "You have to enter a more than 0 or positive amount of money to bet with. Try again!" << endl << endl;
    }

  } while (true); 

  // $ return stake start amount
  return stakeStartUns;

}

/*
Name: askForBetDonePlayingFunc
Function Purpose : Asks for what the player will bet and checks for validity
Function Design:   Checks for valid entry
                   if not valid entry, staes the reason why
                   retry entry if not valid
Inputs:            stakeUns - The total stake amount
Outputs:           By function name an unsigned integer that's the bet amount
*/

unsigned askForBetDonePlayingFunc(unsigned& stakeUns) {

  //$ design necssary code
    unsigned bet;
  //Design a validation loop
    do {

    
     //$ display current stake amount
     //$ ask for a bet
        cout << "Current Stake Amount : $" << stakeUns << endl << endl ;
        cout << "What will you bet ? ";
        cin >> bet;
        cout << endl << endl;


        //$ check if input  amount more than stake amount
         //$ display error message
         //$ continue the loop
        if (bet > stakeUns) {
            cout << "Bet amount is not valid" << endl << endl;
        }else if (bet < 0) {
            cout << "Bet amount is not valid" << endl << endl ;
        }
        else {
            break;
        }
     
     //$ set valid bet amount
         // leave the loop
    } while (true);

   //$ return the valid inputted bet
  return bet;
}

/*
Name:             rollDemBonesFunc
Function Purpose: generates an independent random number for each die
                  calculates the roll sum
                  increments rollCountUns
Function Design:  Prompts the user to throw the dice
                  Using rand() generates 2 random variables from 1 to 6 and adds to simulate dice throw
Inputs/Outpuut:   &rollCountUns - Reference of total rolls count in game
Outputs:          By function name an unsigned integer that's the sum of the two rolled dice
*/

unsigned rollDemBonesFunc(unsigned& rollCountUns) {
    unsigned dice1;
    unsigned dice2;
  //$ display Press enter key once or twice to throw the dice
  //$ see assigment to use ignore() and get() to hold the screen
    cout << "Press enter key once or twice to throw the dice" << endl;
    cin.ignore(); 
    cin.get();

  //$ increment the roll count
    rollCountUns++;
  //$seed the random number generator
    srand(clock());

  //$execute the dice roll as two separate rolls
    dice1 = (rand() % 6) + 1;
    cout << "Die 01 is " << dice1 << endl;
    srand(clock());
    dice2 = (rand() % 6) + 1;
    cout << "Die 02 is " << dice2 << endl;
    cout << "The dice throw results : " << dice1 + dice2 << " !" << endl << endl;
  //$ return the dice sum
  return dice1+dice2;
}

/*
Name: evaluateRollFunc
Function Purpose: Check for a winning roll, a losing roll, or a point roll result
                  Adjust stakeUns using betUns for win or loss result
Function Design:  2, 3, 12      loses
                  7, 11         winner
                  anything else executes point rolls
Inputs:           diceRollResultsUns - The dice roll sum
                  betUns             - The placed bet
Input/Output:     &rollCountUns      - Reference to tally of total rolls
                  &stakeUns          - Reference to the total at stake
*/

void evaluateRollFunc(unsigned diceRollResultsUns, unsigned& rollCountUns, unsigned& stakeUns, unsigned betUns) {
//$ Code up this function as per game rules in assignment
    if (diceRollResultsUns == 7 || diceRollResultsUns == 11) {
        stakeUns += 2 * betUns;
        cout << "We've got ourselves a winner!" << endl << endl;
    }else if (diceRollResultsUns == 2 || diceRollResultsUns == 3 || diceRollResultsUns == 12) {
        stakeUns -= betUns;
        cout << "Sorry, you lose." << endl << endl ;
    }else {
        bool outcome = pointRollDemBonesFunc(diceRollResultsUns, rollCountUns);
        if (outcome == true) {
            stakeUns += 2 * betUns;
            cout << "We've got ourselves a winner!" << endl << endl; 
        } else {
            stakeUns -= betUns;
            cout << "Sorry, you lose." << endl << endl;
        }

    }
    cout << "Current Stake Amount: $" << stakeUns << endl << endl;
}

/*
Name:             pointRollDemBonesFunc
Function Purpose: Executes the point rolls
Function Design:  Displays the point value.
                  Executes repeating rolls using rollDemBonesFunc until the point or 7 is the result
                  Each roll passes to rollDemBonesFunc() the rollCountUns and recives back the rollCountUns
Inputs:           pointUns      - The point set by the first roll
Inputs/Outputs    &rollCountUns - Reference to total roll count
Outputs:          After point rolls produces a return for a win (true) or a loss (false)
*/

bool pointRollDemBonesFunc(unsigned pointUns, unsigned& rollCountUns) {
  
  unsigned pointRollUns;

  //Executes until point  value  or 7 is rolled
  do {
      cout << "The point is " << pointUns << endl;
      cout << "Throw em again and hope that luck is on your side!" << endl << endl;
      pointRollUns = rollDemBonesFunc(rollCountUns);
      if (pointRollUns == pointUns) {
          return true;
      } else if(pointRollUns == 7) {
          return false;
      }
  } while (true);

}


