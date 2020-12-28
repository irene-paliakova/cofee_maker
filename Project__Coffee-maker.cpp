#include <iostream>

#define PIN 6666

using namespace std;

void printMainMenu(double);
double putMoney();
bool checkPin();
void serviceMenu();

int main()
{
	int choiceUser = 0, cup = 7;
	double byn = 0.0;
			
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
			
		}
		else if (choiceUser == 3) {
			
		}
		else if (choiceUser == 4) {
			
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

bool checkPin()
{

}

