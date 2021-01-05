#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <string>

#define PIN 6666
#define COST_ESPRESSO 1
#define COST_CAPPUCCINO 1.5
#define COST_LATTE 1.5

#define WELCOME_MESSAGE "Try the best coffee"
#define ADD_MONEY_MESSAGE "Please deposit more money"
#define TAKE_COFFEE_MESSAGE "Please take your coffee"
#define NO_CUPS_MESSAGE "We are very sorry but there are no cups left"

using namespace std;

void printLogo();
void printMainMenu(double customerBalance);
void printShortMainMenu(double customerBalance);
void printDepositMenu(double customerBalance);
void putMoney(double &customerBalance, double &machineBalance);
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
int  inputNumber();

int main()
{
	int cup = 7;
	double customerBalance = 0.0, machineBalance = 0.0;
	string message = WELCOME_MESSAGE;
				
	while (true) {	
		if (cup == 0 ) {
			message = NO_CUPS_MESSAGE;
		} 	
		printLogo();
		printUserMessage(message);
		message = WELCOME_MESSAGE;
		if (cup == 0 ) {
			printShortMainMenu(customerBalance);
		} else {
			printMainMenu(customerBalance);
		}
		
		int choiceUser = inputNumber();
		
		if (choiceUser == 1 and cup != 0) {
			putMoney(customerBalance, machineBalance);
		}
		else if (choiceUser == 2 and cup != 0) {
			if (isEnoughMoney(COST_ESPRESSO, customerBalance))
				buyCoffee(customerBalance, COST_ESPRESSO, cup, message);
			else message = ADD_MONEY_MESSAGE;
		}
		else if (choiceUser == 3 and cup != 0) {
			if (isEnoughMoney(COST_CAPPUCCINO, customerBalance))
				buyCoffee(customerBalance, COST_CAPPUCCINO, cup, message);
			else message = ADD_MONEY_MESSAGE;
		}
		else if (choiceUser == 4 and cup != 0) {
			if (isEnoughMoney(COST_LATTE, customerBalance))
				buyCoffee(customerBalance, COST_LATTE, cup, message);
			else message = ADD_MONEY_MESSAGE;
		}
		else if (choiceUser == 5) {
			if (isTemporaryPinChoice()) {
				manageServiceMenu(customerBalance, machineBalance, cup);
			}
		}				
	}  			
	return 0;
}

void printLogo() {
	system("cls");
	cout << "CoffeeShop" << endl << endl;
}

void printUserMessage(string message) {
	cout << message << endl << endl;
}

void printMainMenu(double customerBalance) {	
	cout << "Balance: " << customerBalance << " BYN" <<endl;
	cout << "1. Deposit money" << endl;
	cout << "2. Espresso       1.0 BYN" << endl;
	cout << "3. Cappuccino     1.5 BYN" << endl;
	cout << "4. Latte          1.5 BYN" << endl;
	cout << "5. Service" << endl << endl;
	cout << "Please, make your choice and press the button ENTER: ";
}

void printShortMainMenu(double customerBalance) {	
	cout << "Balance: " << customerBalance << " BYN" << endl;
	cout << "5. Service" << endl << endl;
	cout << "Please, make your choice and press the button ENTER: ";
}

void printDepositMenu(double customerBalance) {
	cout << "Balance: " << customerBalance << " BYN" << endl;
	cout << "1. 10 coins" << endl;
	cout << "2. 20 coins" << endl;
	cout << "3. 50 coins" << endl;
	cout << "4. 1 ruble" << endl;
	cout << "5. 2 rubles" << endl;
	cout << "6. Back to main menu" << endl << endl;
	cout << "Please, make your choice and press the button ENTER: ";
}

void putMoney(double &customerBalance, double &machineBalance) {
	double byn = 0.0;
	int choiceUser = 0;
	
	while (choiceUser != 6) {
		printLogo();
		printUserMessage("Pay attention that the coffee machine doesn't give change");
		printDepositMenu(customerBalance);
		choiceUser = inputNumber();
		
		switch (choiceUser) {
			case 1: byn = 0.1; break;
			case 2: byn = 0.2; break;
			case 3: byn = 0.5; break;
			case 4: byn = 1.0; break;
			case 5: byn = 2.0; break;
			case 6: printMainMenu(customerBalance);
					byn = 0.0;
					break;
			default: byn = 0.0; break;
		}
		
		changeBalance(customerBalance, machineBalance, byn);
	}	
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
}

void progressBar() {
	cout << "Please wait, we are cooking the best coffee for your";
	for (int i = 1; i <= 5; i++)
    {
        Sleep(1000);
        cout << "." << flush;
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
		else
			printUserMessage("PIN is wrong!");					
		attemptPin--;		
		if (attemptPin == 0)
			blockProgram();
	}	
}
	
void printTemporaryPinMenu() {
	cout << "1. Back to Main Menu" << endl;
	cout << "2. Enter a PIN-code" << endl << endl;
	cout << "Please, make your choice and press the button ENTER: ";
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
	
	cout << "Please, input PIN (" << attemptPin << " attempt left) and press the button ENTER: ";
	for (int i = 0; i < 4; i++) {
		ch = _getch();
		cout << "*";
		pass = pass + (char)ch;
	}
	cout << endl;
	system("pause");
		
	pin = atoi(pass.c_str());
	
	return pin;
}

void blockProgram() {
	cout << "The machine is blocked" << endl;;
	system("pause");
	exit(-1);	
}

void manageServiceMenu(double &customerBalance, double &machineBalance, int &cup) {			
	cout << "Service Menu" << endl;
	while (true) {
		printServiceMenu(machineBalance, cup);
		int choiceService = inputNumber();
		if (choiceService == 1) {
			cout << "How many cups are you adding?" << endl;
			int addCup = inputNumber();
			
			cup += addCup;			
		}
		else if (choiceService == 2) {
			cout << machineBalance << " BYN were given away";
			machineBalance = 0.0;
			customerBalance = 0.0;
						
		}
		else if (choiceService == 3)
			break;
	}	
}

void printServiceMenu(double machineBalance, int cup) {
	printLogo();
	cout << "Welcome to the service menu" << endl;
	cout << "Total balance: " << machineBalance << " BYN" << endl;
	cout << "Cups remaining: " << cup << endl;
	cout << "Please, choose the option:" << endl;
	cout << "1. Add cups" << endl;
	cout << "2. Withdraw proceeds" << endl;
	cout << "3. Back to Main Menu" << endl << endl;	
	cout << "Please, make your choice and press the button ENTER: ";
}

int inputNumber() {
	int number = 0;		
	
	cin >> number;
	
	return number;
}
