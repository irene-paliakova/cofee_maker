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

using namespace std;

void printLogo();
void printMainMenu();
void putMoney();
bool isEnoughMoney(double coffeeCost);
void printUserMessage(string message);
void buyCoffee(double coffeeCost, string &message);
void progressBar();
bool isCheckingPin();
int inputChoiceUser(int attemptPin);
void blockProgram();
void manageServiceMenu();
void printServiceMenu();
int inputChoiceService();

int cup = 7;
double customerBalance = 0.0;
double machineBalance = 0.0;


int main()
{
	int choiceUser = 0;
	string message = WELCOME_MESSAGE;
				
	while (true) {		
		printLogo();
		printUserMessage(message);
		printMainMenu();
		cin  >> choiceUser;
		
		// check input value??
		if (choiceUser == 1) {
			printLogo();
			message = WELCOME_MESSAGE;
			putMoney();
		}
		else if (choiceUser == 2) {
			if (isEnoughMoney(COST_ESPRESSO))
				buyCoffee(COST_ESPRESSO, message);
			else message = ADD_MONEY_MESSAGE;
		}
		else if (choiceUser == 3) {
			if (isEnoughMoney(COST_CAPPUCCINO))
				buyCoffee(COST_CAPPUCCINO, message);
			else message = ADD_MONEY_MESSAGE;
		}
		else if (choiceUser == 4) {
			if (isEnoughMoney(COST_LATTE))
				buyCoffee(COST_LATTE, message);
			else message = ADD_MONEY_MESSAGE;
		}
		else if (choiceUser == 5) {
			if (isCheckingPin()) {
				manageServiceMenu();
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

void printMainMenu()
{	
	cout << "Balance: " << customerBalance << endl;
	cout << "1. Deposit money" << endl;
	cout << "2. Espresso       1.0 BYN" << endl;
	cout << "3. Cappuccino     1.5 BYN" << endl;
	cout << "4. Latte          1.5 BYN" << endl;
	cout << "5. Service" << endl << endl;
	cout << "Please, make your choice and press the button ENTER: ";
}

void printDepositMenu() {
	cout << "Balance: " << customerBalance << endl;
	cout << "1. 10 coins" << endl;
	cout << "2. 20 coins" << endl;
	cout << "3. 50 coins" << endl;
	cout << "4. 1 ruble" << endl;
	cout << "5. 2 rubles" << endl;
	cout << "6. Back to main menu" << endl << endl;
	cout << "Please, make your choice and press the button ENTER: ";
}

void putMoney()
{
	double byn = 0.0;
	int choiceUser = 0;
	
	cout << "Pay attention that the coffee machine doesn't give change" << endl;	
	cout << "Please, deposit money:" << endl;
	
	while (choiceUser != 6) {
		printLogo();
		printDepositMenu();
		cin>>choiceUser;
		switch (choiceUser) {
			case 1: byn = 0.1; break;
			case 2: byn = 0.2; break;
			case 3: byn = 0.5; break;
			case 4: byn = 1; break;
			case 5: byn = 2; break;
			case 6: printMainMenu();
					byn = 0.0;
					break;
			default: byn = 0; break;
		}
		customerBalance += byn;
		machineBalance += byn;
	}	
}

bool isEnoughMoney(double coffeeCost) {
	if (coffeeCost > customerBalance) 
		return false;
	else return true;
}

void buyCoffee(double coffeeCost, string &message) {
	customerBalance -= coffeeCost;
	cup--;
	progressBar();
	message = TAKE_COFFEE_MESSAGE;
}

void progressBar() {
	cout << "Please Wait, we are cooking the best coffee for your";
	for (int i = 1; i <= 10; i++)
    {
        Sleep(1000);
        cout << "." << flush;
    }
    cout << endl;
}

bool isCheckingPin() {
	int attemptPin = 3;
	
	while (attemptPin > 0) {
		
		int pin = inputChoiceUser(attemptPin);
		// check input value??
		//if (pin == 1)
		//	return false;
		//else 
		if (pin == PIN)
			return true;
		else
			cout << "PIN is wrong!" << endl;			
		attemptPin--;		
		if (attemptPin == 0)
			blockProgram();
	}	
}

int inputChoiceUser(int attemptPin) {
	int pin = 0, choice = 0;
	string pass = "";
	int ch = 0;
	
	system("cls");
	printLogo();
	cout << "1. Back to Main Menu" << endl;
	cout << "2. Enter a PIN-code" << endl;
	cout << "Please, make your choice and press the button ENTER: ";
	cin >> 	choice;
	switch (choice) {
		case 1: return false;
		case 2: 
			cout << "Please, input PIN (" << attemptPin << " attempt left) and press the button ENTER: ";
			for (int i = 0; i < 4; i++) {
				ch = _getch();
				cout << "*";
				pass = pass + (char)ch;
			}
			cout << endl;
			system("pause");
			break;
		default: inputChoiceUser(attemptPin);
	}
	pin = atoi(pass.c_str());
	
	return pin;
}

void blockProgram() {
	cout << "The machine is blocked";
	exit(-1);	
}

void manageServiceMenu() {			
	int addCup = 0;
	
	cout << "Service Menu" << endl;
	while (true) {
		printServiceMenu();
		int choiceService = inputChoiceService();
		if (choiceService == 1) {
			cout << "How many cups are you adding?" << endl;
			cin  >> addCup;
			
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

void printServiceMenu() {
	system("cls");
	printLogo();
	cout << "Welcome to the service menu" << endl;
	cout << "Total balance: " << machineBalance << endl;
	cout << "Cups remaining: " << cup << endl;
	cout << "Please, choose the option:" << endl;
	cout << "1. Add cups" << endl;
	cout << "2. Withdraw proceeds" << endl;
	cout << "3. Back to Main Menu" << endl << endl;	
}

int inputChoiceService() {
	int choiceService = 0;
		
	cout << "Please, make your choice and press the button ENTER: ";
	cin  >> choiceService;
	
	return choiceService;
}
