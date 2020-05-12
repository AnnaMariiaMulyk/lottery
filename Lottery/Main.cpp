#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;
#define SLEEP Sleep(1000);
struct user
{
	int money;
	int number;
};
user addMoney(user player)
{
	int addMoney;
	cout << "Enter money to add: ";
	cin >> addMoney;
	player.money += addMoney;
	cout << "Your money balance: " << player.money << endl;
	
	return player;
}

user playGame(user player)
{
	int choiseMoney;
	int endlessChoise = 0;
	int endlessChoise1 = 0;
	string presents[7] = { "1$", "100$", "Lanos", "BMW 6", "10 000$", " one week at Hawaii", "Nothing" };
	string door[7];
	int myRand; //для рандому приза з масиву з призами
	int myRand1; //для рандому дверей, в які буде поміщено приз
	int pickDoor;
	
	
		if (player.money < 200)
		{
			
				cout << "You don`t have enough money to play!" << endl;
				cout << "Do you want to add money?" << endl;
				cout << "Enter action: (1 - yes/2 - no)";
				cin >> choiseMoney;
				if (choiseMoney == 1)
				{
					player = addMoney(player);
				}
				else
				{
					cout << "Goodbye!" << endl;
					return player;
				}
		}
		else
		{
			int myRandom;
			
			player.money -= 200;
			cout << "Rules!!!" << endl;
			cout << "Computer randoms a number from 1 to 10" << endl;
			cout << "You need to guess the number" << endl;
			cout << "One game coasts 200$" << endl;
			cout << "LETS BEGINE!" << endl;
			myRandom = rand() % 1 + 10;
			SLEEP
				cout << "Enter the number:...";
			cin >> player.number;
			if (player.number == myRandom)
			{

				cout << "Congrats!!! You passed first round!" << endl;
				cout << endl;
				cout << "SECOND ROUND" << endl;
				cout << "Rules:" << endl;
				cout << "Imagine, you see 7 doors" << endl;
				cout << "1 of them insert very expencive present" << endl;
				cout << "Now you need to choose one of them" << endl;
				cout << "One try coasts 50$" << endl;
				do
				{
					if (player.money < 50)
					{
						cout << "You don`t have enough money to play!" << endl;
						cout << "Do you want to add money?" << endl;
						cout << "Enter action: (1 - yes/2 - no)";
						cin >> choiseMoney;
						if (choiseMoney == 1)
						{
							do
							{
								player = addMoney(player);

							} while (player.money < 50);
						}
						else
						{
							cout << "Goodbye!" << endl;
							return player;
						}
					}
					else
					{
						do
						{
							player.money -= 50;
							myRand = rand() % 6 + 0;
							myRand1 = rand() % 6 + 0;

							door[myRand1] = presents[myRand];
							cout << "Pick a door: ";
							cin >> pickDoor;
							if (pickDoor == myRand1)
							{
								cout << "Congrats! You won " << door[myRand1] << endl;
								return player;

							}
							else
							{
								cout << "Wrong door (T ^ T)" << endl;
								cout << "Do you want to try again?(1-yes/2-no)" << endl;
								cin >> endlessChoise1;
								if (endlessChoise1 == 2)
								{
									cout << "Okay! See you next time!" << endl;
									return player;
								}
							}
						} while (endlessChoise1 != 2);

					}
				} while (choiseMoney != 2 ); //q
				}
			else
			{
				do
				{
					cout << "You loose" << endl;
					cout << "Do you want to try again?" << endl;
					cin >> endlessChoise;
					if (endlessChoise == 2)
					{
						cout << "Okay! See you next time!" << endl;
						return player;
					}
				} while (endlessChoise != 2);
			}
			
		}
	 //q
	return player;
}



int main()
{
	user player;
	int choise;
	int choiseMoney;
	int addMoney;
	player.money = 0;
	do
	{
		cout << "\tMENU" << endl;
		cout << "1. Play game" << endl;
		cout << "2. My money balance" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		cout << "Enter action: ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			player = playGame(player);
			break;
		case 2:
			cout << "Money: " << player.money << endl;
			cout << "Do you want to add money?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> choiseMoney;
			if (choiseMoney == 1)
			{
				cout << "Enter money to add: ";
				cin >> addMoney;
				player.money += addMoney;
			}
			break;
		case 3:
			cout << "Goodbye!" << endl;
			break;
		default:
			break;
		}
	} while (choise != 3);
	return 0;
}