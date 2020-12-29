#include <iostream>
#include <Windows.h>
#include <cstdlib>

#define PIN 6666
#define COST_ESPRESSO 1
#define COST_CAPPUCCINO 1.5
#define COST_LATTE 1.5

using namespace std;

void printLogo();
void printMainMenu();
void putMoney();
void buyCoffee(double coffeeCost);
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
				
	while (true) {		
		printMainMenu();
		cin  >> choiceUser;
		
		// check input value??
		if (choiceUser == 1) {
			putMoney();
		}
		else if (choiceUser == 2) {
			buyCoffee(COST_ESPRESSO);
		}
		else if (choiceUser == 3) {
			buyCoffee(COST_CAPPUCCINO);
		}
		else if (choiceUser == 4) {
			buyCoffee(COST_LATTE);
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
	cout << "CoffeeShop" << endl << endl;
}

void printMainMenu()
{	
	system("cls");
	printLogo();
	cout << "Balance: " << customerBalance << endl;
	cout << "1. Deposit money" << endl;
	cout << "2. Espresso       1.0 BYN" << endl;
	cout << "3. Cappuccino     1.5 BYN" << endl;
	cout << "4. Latte          1.5 BYN" << endl;
	cout << "5. Service" << endl << endl;
	cout << "Please, make your choice and press the button ENTER: ";
}

void putMoney()
{
	double byn = 0.0;
	int choiceUser = 0;
	
	system("cls");
	printLogo();
	cout << "Pay attention that the coffee machine doesn't give change" << endl;	
	cout << "Please, deposit money:" << endl;
	
	while (choiceUser != 6) {
		system("cls");
		printLogo();
		cout << "Balance: " << customerBalance << endl;
		cout << "1. 10 coins" << endl;
		cout << "2. 20 coins" << endl;
		cout << "3. 50 coins" << endl;
		cout << "4. 1 ruble" << endl;
		cout << "5. 2 rubles" << endl;
		cout << "6. Back to main menu" << endl << endl;
		cout << "Please, make your choice and press the button ENTER: ";
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

void buyCoffee(double coffeeCost) {
	customerBalance -= coffeeCost;
	cup--;
	progressBar();
	cout << "Please take your coffee" << endl;
}

void progressBar() {
	cout << "Please Wait, we are cooking the best coffee for your";
	for (int i = 1; i <= 10; i++)
    {
        Sleep(1000);
        cout << "." << std::flush;
    }
    cout << endl;
}

bool isCheckingPin() {
	int attemptPin = 3;
	
	while (attemptPin > 0) {
		
		int pin = inputChoiceUser(attemptPin);
		// check input value??
		if (pin == 1)
			return false;
		else if (pin == PIN)
			return true;
		else
			cout << "PIN is wrong!" << endl;			
		attemptPin--;		
		if (attemptPin == 0)
			blockProgram();
	}	
}

int inputChoiceUser(int attemptPin) {
	int pin = 0;
	
	system("cls");
	printLogo();
	cout << "1. Back to Main Menu" << endl;	
	cout << "Please, input PIN (" << attemptPin << " attempt left) and press the button ENTER: ";
	cin  >> pin;
	
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
	cout << "Balance: " << machineBalance << endl;
	cout << "There are '" << cup << "' cups loaded" << endl;
	cout << "Please, choose the option:" << endl;
	cout << "1. Add cups" << endl;
	cout << "2. Withdrawal of proceeds" << endl;
	cout << "3. Back to Main Menu" << endl << endl;	
}

int inputChoiceService() {
	int choiceService = 0;
		
	cout << "Please, make your choice and press the button ENTER: ";
	cin  >> choiceService;
	
	return choiceService;
}
