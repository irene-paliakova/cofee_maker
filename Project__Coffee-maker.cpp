#include <iostream>
#include <Windows.h>

#define PIN 6666
#define COST_ESPRESSO 1
#define COST_CAPPUCCINO 1.5
#define COST_LATTE 1.5

using namespace std;

void printMainMenu(double);
double putMoney();
void buyCoffee(double coffeeCost);
void progressBar();
bool checkPin();
void serviceMenu();

int cup = 7;
double byn = 0.0;


int main()
{
	int choiceUser = 0;
				
	cout << "CoffeeShop" << endl << endl;
	while (true) {		
		printMainMenu(byn);
		cout << "Please, make your choice and press the button ENTER: ";
		cin  >> choiceUser;
		
		// check input value??
		if (choiceUser == 1) {
			byn = putMoney();
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
			if (checkPin()) {
				serviceMenu();
			}
		}
				
	}  
			
	return 0;
}

void printMainMenu(double byn)
{		
	cout << "Dear Customer, make your choice:" << endl << endl;
	cout << "Balance: " << byn << endl;
	cout << "1. Deposit money" << endl;
	cout << "2. Espresso       1.0 BYN" << endl;
	cout << "3. Cappuccino     1.5 BYN" << endl;
	cout << "4. Latte          1.5 BYN" << endl;
	cout << "5. Service" << endl << endl;
}

double putMoney()
{
	double byn = 0.0;
		
	cout << "Please, deposit money" << endl << "Minimal note is 1 BYN" << endl;
	cout << "Pay attention that the coffee machine doesn't give change" << endl;
	cin  >> byn;
	
	return byn;
}

void buyCoffee(double coffeeCost) {
	byn -= coffeeCost;
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

bool checkPin()
{

}

void serviceMenu() {
	
}

