#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

void addDice(int& diceSize, vector<int>& diceCollection)
{
	cout << "\n\n" << "Dice size: ";
	cin >> diceSize;
	diceCollection.push_back(diceSize);
}

void removeDice(vector<int>& diceCollection)
{
	if (!diceCollection.empty())
	{
		cout << "\n\n" << "Removing last dice added..." << endl;
		diceCollection.pop_back();
		cout << "Dice removed" << endl;
	}
	else
	{
		cout << "\n\n" << "Dice collection is already empty." << endl;
	}
}

void rollDice(int& roll, int& total, vector<int>& diceCollection)
{
	cout << "\n\n";

	for (int i = 0; i < diceCollection.size(); i++)
	{
		roll = rand() % diceCollection[i] + 1;

		cout << "Dice "
			<< i + 1
			<< " roll result: "
			<< roll
			<< endl;

		total += roll;
	}
	cout << "Total: " << total << endl;
}

int main()
{
	srand(time(NULL));

	int choice = 0;
	int diceSize = 0;
	int total = 0;
	int roll = 0;
	vector<int> diceCollection;

	cout << "Let's roll the dice, please choose: "
		<< "\n"
		<< "\t1 - Add dice"
		<< "\n"
		<< "\t2 - Remove last dice added"
		<< "\n"
		<< "\t3 - Roll the dice"
		<< "\n"
		<< "\t4 - quit"
		<< "\n"
		<< "your choice: ";
	cin >> choice;

	while (choice != 4)
	{
		switch (choice)
		{
			case 1:
				addDice(diceSize, diceCollection);
				break;

			case 2:
				removeDice(diceCollection);
				break;

			case 3:
				rollDice(roll, total, diceCollection);
				break;

			default:
				cout << "ERROR: This is not a valid option, try again!" << endl;
				break;
		}

		cout << "\n\n" << "What you want now: "
			<< "\n"
			<< "\t1 - Add dice"
			<< "\n"
			<< "\t2 - Remove last dice added"
			<< "\n"
			<< "\t3 - Roll the dice"
			<< "\n"
			<< "\t4 - quit"
			<< "\n"
			<< "your choice: ";
		cin >> choice;

	}

	cout << "\n\n" << "End of game! Your final score is: "
		<< total
		<< endl;

	return 0;
}