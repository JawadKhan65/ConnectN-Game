#include <iostream>
#include<string>

using namespace std;
string stringconverter(int dig) {
	string strNumber = to_string(dig);
	return strNumber;
}
bool Retake(string ar[3][3], int index ) {
	if (index >= 1 && index < 4) {
		
		if (ar[0][index - 1] != " ") {
			
			return true;
		}

		
	}
	else if (index >= 4 && index < 7) {
		if (index % 3 == 0) {

			
			if (ar[1][2] != " ") {
				
				return true;

				}

			

		}
		else {
			int cont = (index % 3) - 1;
			
			if (ar[1][cont] != " ") {
				
				return true;

				}

			

		}
	}
	else if (index >= 7 && index < 10) {

		if (index % 3 == 0) {

			
			if (ar[2][2] != " ") {
				
				return true;

				}

			
		}
		else {
			int cont1 = (index % 3) - 1;
			
			if (ar[2][cont1] != " ") {
				
				return true;

			}

		}
	}
	return false;
}
void Put(string ar[3][3], int index , int turn) {
	if (index>=1 && index<4  ) {
		if (turn == 1) {
			ar[0][index-1] = "X";

		}
		else {
			ar[0][index-1] = "O";

		}
	}
	else if (index >= 4 && index < 7) {
		if (index % 3 == 0) {

			if (turn == 1) {
				ar[1][2] = "X";

			}
			else {
				ar[1][2] = "O";

			}

		}
		else {
			int cont = (index % 3)-1;
			if (turn == 1) {
				ar[1][cont] = "X";

			}
			else {
				ar[1][cont] = "O";

			}

		}
	}
	else if (index >= 7 && index < 10) {
		
		if (index % 3 == 0) {

			if (turn == 1) {
				ar[2][2] = "X";

			}
			else {
				ar[2][2] = "O";

			}
		}
		else {
			int cont1 = (index % 3)-1;
			if (turn == 1) {
				ar[2][cont1] = "X";

			}
			else {
				ar[2][cont1] = "O";

			}

		}
	}

}

void Checker(string ar[3][3], int digit, int turn) {

	for (int j = 0; j <= 2; j++)
	{
		for (int k = 0; k <= 2; k++)
		{
			if (ar[j][k] == stringconverter(digit)) {
				if (turn == 1) {
					ar[j][k] = "X";
				}
				else {
					ar[j][k] = "O";
				}
			}


		}

	}
}
bool WinORElse(string ar[3][3], string turn) {
	int yes = 0;

	// Check rows and columns for a win
	for (int i = 0; i < 3; i++) {
		if ((ar[i][0] == ar[i][1]) && (ar[i][1] == ar[i][2]) && ar[i][0] != "") {
			cout << turn << " Wins by row " << i + 1 << endl;
			return true;
		}
		if ((ar[0][i] == ar[1][i]) && (ar[1][i] == ar[2][i]) && ar[0][i] != "") {
			cout << turn << " Wins by column " << i + 1 << endl;
			return true;
		}
	}

	// Check diagonals for a win
	if ((ar[0][0] == ar[1][1]) && (ar[1][1] == ar[2][2]) && ar[0][0] != "") {
		cout << turn << " Wins by diagonal" << endl;
		return true;
	}
	if ((ar[0][2] == ar[1][1]) && (ar[1][1] == ar[2][0]) && ar[0][2] != "") {
		cout << turn << " Wins by diagonal" << endl;
		return true;
	}

	return false;
}

void PrintARRAY(string space[3][3]) {
	cout << endl;
	cout << "		|		|		\n";
	cout << "		|		|		\n";
	cout << "	" << space[0][0] << "	|	" << space[0][1] << "	|	" << space[0][2] << "  \n";
	cout << "		|		|		\n";
	cout << "________________|_______________|__________\n";
	cout << "		|		|		\n";
	cout << "		|		|		\n";
	cout << "	" << space[1][0] << "	|	" << space[1][1] << "	|	" << space[1][2] << "  \n";
	cout << "		|		|		\n";
	cout << "________________|_______________|__________\n";
	cout << "		|		|		\n";
	cout << "		|		|		\n";
	cout << "	" << space[2][0] << "	|	" << space[2][1] << "	|	" << space[2][2] << "  \n";
	cout << "		|		|		\n";
	cout << "		|		|		\n";

	cout << endl;
}

int main() {

	// arrays for structure like 3 by 3 matrix
			// with index  like row with column number
				// for 3x3 0-2 rows and 0-2 cols
	//int space[3][3] = { { 00,01,02},{10,11,12},{20,21,22} };
	string space[3][3] ;
	string ONGOING[3][3] = { {"1","2","3"} ,{"4","5","6"},{"7","8","9"}};
	
	

	//players names Input
	string n1; 
	string n2;
	cout << "Enter Name of Player 1 : ";
	getline(cin, n1);
	cout << endl;
	cout << "Enter Name of Player 2 : ";
	getline(cin, n2);
	cout << endl;
	cout << n1 << " will play first \n";
	cout << n2 << " will play second \n";
	cout << endl;
	
	// Value assigning
	int initVAL = 1;
	for (int j = 0; j <=2; j++)
	{
		for (int k = 0; k <= 2; k++)
		{
			space[j][k] = stringconverter(initVAL++);
		}

	}

	// Taking inputs and giving turn
	int digit;
	int taken = 1;
	while(taken<=9)
	{
		if (taken % 2==0) {
			int turn = 2;
			string player = n2;
			cout << " --> " <<n2 << " turn " << endl;
			cout << "Enter index : ";
			cin >> digit;
			bool checking = Retake(ONGOING, digit);
			if (!checking) {
				cout << " Invalid : already taken enter the available one" << endl;
				cin >> digit;
			}
			Put(ONGOING, digit, turn);
			if (digit > 9) {
				cout << " Invalid Input : Please input according to Matrix .";
				cin >> digit;
				bool checking = Retake(ONGOING, digit);
				if (!checking) {
					cout << " Invalid : already taken enter the available one" << endl;
					cin >> digit;
				}
				
				Put(ONGOING, digit, turn);
				Checker(space, digit,turn);
				WinORElse(ONGOING,player);
				bool x = WinORElse(ONGOING,player);
				PrintARRAY(space);		
				if (WinORElse) {
					break;
				}
			}
			else {

				Checker(space, digit, turn);
				WinORElse(ONGOING,player);
				PrintARRAY(space);
				bool x = WinORElse(ONGOING, player);
				if (x) {
					break;
				}
			}


		}
		else {
			cout<<" --> " << n1 << "  turn " << endl;
			int turn1 = 1;
			string player1 = n1;

			cout << "Enter index : ";

			cin >> digit;
			bool checking = Retake(ONGOING, digit);
			if (!checking) {
				cout << " Invalid : already taken enter the available one" << endl;
				cin >> digit;
			}
			Put(ONGOING, digit, turn1);
			if (digit > 9) {
				cout << " Invalid Input : Please input according to Matrix .";
				cin >> digit;
				bool checking = Retake(ONGOING, digit);
				if (!checking) {
					cout << " Invalid : already taken enter the available one" << endl;
					cin >> digit;
				}
				Put(ONGOING, digit, turn1);
				Checker(space, digit, turn1);
				WinORElse(ONGOING,player1);
				
				PrintARRAY(space);
				bool x = WinORElse(ONGOING, player1);
				if (x) {
					break;
				}

			}
			else {
				Checker(space, digit, turn1);
				WinORElse(ONGOING,player1);
				PrintARRAY(space);
				bool x = WinORElse(ONGOING, player1);
				if (x) {
					break;
				}

			}
		}
		taken++;
	}
	
	
	

	// sketching the table matrix & adding the input by user

	PrintARRAY(space);

	return 0;
}