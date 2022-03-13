#include <iostream>
using namespace std;

int main(){
	string action;
	int account = 0;
	int password = 0;
	int balance = 0;
	int valid = -1;
	int accLocation = 0;
	int amount = 0;
	int dummy = 0;
	int info[3][6] = {
		{ 123,456,789,336,775,566 },
		{ 456,789,888,558,666,221 },
		{ 9000,5000,6000,10000,12000,7000 }
	};

	while (valid == -1) {
		cin >> account;
		cin >> password;
		cin.ignore();
		for (int i = 0; i < 6; i++) {
			if (account == info[0][i]) {
				valid = -2;
				accLocation = i;
				if (password == info[1][accLocation]) {
					valid = -2;
					cout << "OK" << endl;
					balance = info[2][accLocation];
				}
				else
					valid = -1;
			}
		}
		if (valid == -1)
			cout << "ERROR" << endl;
	}

	cin >> action;
	if (action == "L")
		cin >> amount;
	while (1) {
		if (action != "S" && action != "L" && action != "E") {
			cin >> dummy;
			cout << "ERROR" << endl;
		}
		else if (action[0] == 'S') {
			cout << info[2][accLocation] << endl;
		}
		else if (action[0] == 'L') {
			if (amount <= balance) {
				balance -= amount;
				info[2][accLocation] = balance;
				cout << "OK" << endl;
			}
			else
				cout << "ERROR" << endl;
		}
		else if (action[0] == 'E') {
			cout << "BYE" << endl;
			break;
		}
		else {
			cout << "ERROR" << endl;
		}
		cin >> action;
		if (action == "L")
			cin >> amount;
	}
	return 0;
}