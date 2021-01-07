#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

#define PIN             7712
#define COST_ESPRESSO   1
#define COST_CAPPUCCINO 1.5
#define COST_LATTE      1.5

#define WELCOME_MESSAGE     "* YOU + Me + Coffee = HAPPY!  *"
#define ADD_MONEY_MESSAGE   "* Please, deposit more money  *"
#define TAKE_COFFEE_MESSAGE "* Please, take your coffee    *"
#define NO_CUPS_MESSAGE     "* We are very sorry, but there are no cups left *"

using namespace std;

void printLogo();
void printMainMenu(double customerBalance);
void printShortMainMenu(double customerBalance);
void printDepositMenu(double customerBalance);
void putMoney(double &customerBalance, double &machineBalance, string &message);
void changeBalance(double &customerBalance, double &machineBalance, double byn);
bool isEnoughMoney(double coffeeCost, double customerBalance);
void printUserMessage(string message);
void buyCoffee(double &customerBalance, double coffeeCost, int &cup, string &message);
void progressBar();
void isCheckingPin();
void printTemporaryPinMenu();
bool isTemporaryPinChoice();
int  inputPin(int attemptPin);
void blockProgram();
void manageServiceMenu(double &customerBalance, double &machineBalance, int &cup);
void printServiceMenu(double machineBalance, int cup);
void addCup(int &cup);
int  checkExtraCup();
void nullingBalance(double &machineBalance, double &customerBalance);
int  inputNumber();

int main()
{
	int cup = 7;
	double customerBalance = 0.0, machineBalance = 0.0;
	string message = WELCOME_MESSAGE;	
				
	while (true) {		
		printLogo();
		if (cup == 0) {			
			printUserMessage(NO_CUPS_MESSAGE);
			printShortMainMenu(customerBalance);
		} else {
			printUserMessage(message);
			printMainMenu(customerBalance);
		}
		message = WELCOME_MESSAGE;	
		
		int choiceUser = inputNumber();
		
		if (choiceUser == 1 and cup != 0) {
			putMoney(customerBalance, machineBalance, message);
		} else if (choiceUser == 2 and cup != 0) {
			if (isEnoughMoney(COST_ESPRESSO, customerBalance))
				buyCoffee(customerBalance, COST_ESPRESSO, cup, message);
			else {
				message = ADD_MONEY_MESSAGE;
				putMoney(customerBalance, machineBalance, message);
			}							
		} else if (choiceUser == 3 and cup != 0) {
			if (isEnoughMoney(COST_CAPPUCCINO, customerBalance))
				buyCoffee(customerBalance, COST_CAPPUCCINO, cup, message);
			else {
				message = ADD_MONEY_MESSAGE;
				putMoney(customerBalance, machineBalance, message);
			}
		} else if (choiceUser == 4 and cup != 0) {
			if (isEnoughMoney(COST_LATTE, customerBalance))
				buyCoffee(customerBalance, COST_LATTE, cup, message);
			else {
				message = ADD_MONEY_MESSAGE;
				putMoney(customerBalance, machineBalance, message);
			}
		} else if (choiceUser == 5) {
			if (isTemporaryPinChoice())
				manageServiceMenu(customerBalance, machineBalance, cup);
		}				
	}  			
	return 0;
}

void printLogo() {
	system("cls");
	cout << "CoffeeShop Software v. 1.0" << endl << "Powered by Irene & Vital" << endl << endl;
	cout << "*******************************" << endl;
	cout << "*          CoffeeShop         *" << endl;
	cout << "*              by             *" << endl;
	cout << "*        EspressoBiancci      *" << endl;
	cout << "*******************************" << endl << endl;
}

void printUserMessage(string message) {
	cout << message << endl;
}

void printMainMenu(double customerBalance) {
	cout << endl;
	cout << "*******************************" << endl;	
	cout << "   Balance:          " << customerBalance << " BYN" <<endl;
	cout << "*******************************" << endl;
	cout << "*  1. Deposit money           *" << endl;
	cout << "*                             *" << endl;
	cout << "*  2. Espresso       1.0 BYN  *" << endl;	
	cout << "*  3. Cappuccino     1.5 BYN  *" << endl;
	cout << "*  4. Latte          1.5 BYN  *" << endl;	
	cout << "*******************************" << endl;
	cout << "*  5. Service                 *" << endl;
	cout << "*******************************" << endl << endl;
	cout << "* Please, make your choice and press the button ENTER: ";
}

void printShortMainMenu(double customerBalance) {	
	cout << endl;
	cout << "*******************************" << endl;
	cout << "   Balance:          " << customerBalance << " BYN" <<endl;
	cout << "*******************************" << endl;
	cout << "*  5. Service                 *" << endl;
	cout << "*******************************" << endl << endl;
	cout << "* Please, make your choice and press the button ENTER: ";
}

void printDepositMenu(double customerBalance) {
	cout << endl;
	cout << "*******************************" << endl;
	cout << "   Balance: " << customerBalance << " BYN" << endl;
	cout << "*******************************" << endl;
	cout << "*  1. 10 coins                *" << endl;
	cout << "*  2. 20 coins                *" << endl;
	cout << "*  3. 50 coins                *" << endl;
	cout << "*  4. 1  ruble                *" << endl;
	cout << "*  5. 2  rubles               *" << endl;
	cout << "* --------------------------- *" << endl;
	cout << "*  6. Back to main menu       *" << endl;
	cout << "*******************************" << endl << endl;
	cout << "* Please, make your choice and press the button ENTER: ";
}

void putMoney(double &customerBalance, double &machineBalance, string &message) {
	double byn = 0.0;
	int choiceUser = 0;
	
	while (choiceUser != 6) {
		printLogo();
		printUserMessage(message);
		printUserMessage("* Pay attention, the coffee machine does NOT give a change *");
		printDepositMenu(customerBalance);
		choiceUser = inputNumber();
		
		switch (choiceUser) {
			case 1: byn = 0.1; break;
			case 2: byn = 0.2; break;
			case 3: byn = 0.5; break;
			case 4: byn = 1.0; break;
			case 5: byn = 2.0; break;
			case 6: byn = 0.0; break;			
		}		
		changeBalance(customerBalance, machineBalance, byn);
	}	
	message = WELCOME_MESSAGE;
}

void changeBalance(double &customerBalance, double &machineBalance, double byn) {
	customerBalance += byn;
	machineBalance += byn;
}

bool isEnoughMoney(double coffeeCost, double customerBalance) {
	if (coffeeCost > customerBalance) 
		return false;
	else return true;
}

void buyCoffee(double &customerBalance, double coffeeCost, int &cup, string &message) {
	customerBalance -= coffeeCost;
	cup--;
	progressBar();
	message = TAKE_COFFEE_MESSAGE;
	cout << endl;
	printUserMessage("* Here is the best Coffee in the city. Bon appetit! *");
	Sleep(3000);
}

void progressBar() {
	cout << endl << "* Please wait, we are cooking the best coffee for you";
	for (int i = 0; i <= 7; i++) {
        Sleep(777);
        cout << " *" << flush;
    }
    cout << endl;
}

void isCheckingPin() {
	int attemptPin = 3;
	
	printLogo();				
	while (attemptPin > 0) {
		int pin = inputPin(attemptPin);
		
		if (pin == PIN)
			break;
		else printUserMessage("* PIN is wrong! *");					
		attemptPin--;		
		if (attemptPin == 0)
			blockProgram();
	}	
}
	
void printTemporaryPinMenu() {
	cout << "*******************************" << endl;
	cout << "*  1. Back to Main Menu       *" << endl;
	cout << "* --------------------------- *" << endl;
	cout << "*  2. Enter a PIN-code        *" << endl;
	cout << "*******************************" << endl << endl;
	cout << "* Please, make your choice and press the button ENTER: ";
}

bool isTemporaryPinChoice() {
	printLogo();
	printTemporaryPinMenu();
	int choice = inputNumber();
	
	switch (choice) {
		case 1: return false;			 	
		case 2: isCheckingPin();
			 	return true;
		default: isTemporaryPinChoice();
	}
}

int inputPin(int attemptPin) {
	int pin = 0, ch = 0;
	string pass = "";
	
	cout << endl << "* Please, input PIN (" << attemptPin << " attempt left) and press the button ENTER: ";
	for (int i = 0; i < 4; i++) {
		ch = _getch();
		cout << "*";
		pass = pass + (char)ch;
	}
	cout << endl;
	Sleep(300);
		
	pin = atoi(pass.c_str());
	
	return pin;
}

void blockProgram() {
	cout << endl << "* The machine is blocked! *" << endl << "* Call to the service 102 *" << endl;
	exit(-1);	
}

void manageServiceMenu(double &customerBalance, double &machineBalance, int &cup) {			
	int choiceService = 0;
	
	while (choiceService != 3) {		
		printServiceMenu(machineBalance, cup);		
		choiceService = inputNumber();
		
		switch (choiceService) {
			case 1: cout << endl;
					addCup(cup); break;			 	
			case 2: if (machineBalance == 0) {
						cout << endl;
						printUserMessage("* Sorry! The coin acceptor is empty! *");
						Sleep(4000);	
					} else {
						cout << endl << "* " << machineBalance;
						printUserMessage(" BYN were given away *");
						cout << endl;
						Sleep(4000);			
						nullingBalance(machineBalance, customerBalance);
					}					
		}		
	}	
}

void addCup(int &cup) {
	int extraCup = checkExtraCup();
	cup += extraCup;
}

int checkExtraCup() {
	int extraCup = 0;
	
	while (true) {
		printUserMessage("* How many cups are you adding? *");
        extraCup = inputNumber();        
        
		if (extraCup < 1)
			cout << endl << "* Invalid data! Please correct number of cups and try again *" << endl;		    
		else break;		
	}	
	return extraCup;	
}

void nullingBalance(double &machineBalance, double &customerBalance) {
	machineBalance = 0.0;
	customerBalance = 0.0;
}

void printServiceMenu(double machineBalance, int cup) {
    printLogo();    
	cout << "  Welcome to the Service Menu" << endl << endl;
	cout << "*******************************" << endl << endl;
	cout << "   Total balance:  " << machineBalance << " BYN" << endl;
	cout << "  ---------------------------" << endl;
	cout << "   Cups remaining: " << cup << " cups" << endl << endl;
	cout << "*******************************" << endl;	
	cout << "*  1. Add cups                *" << endl;
	cout << "*  2. Withdraw proceeds       *" << endl;
	cout << "* --------------------------- *" << endl;
	cout << "*  3. Back to Main Menu       *" << endl;
	cout << "*******************************" << endl << endl;	
	cout << "* Please, make your choice and press the button ENTER: ";
}

int inputNumber() {
	int number = 0;		
	
	cin >> number;
	
	return number;
}
