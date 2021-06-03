#include<iostream>
#include<fstream>
#include<string>
#include"list.h"
using namespace std;
int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Error: provide database filename\n";
		return 1;
	}
	muzei monaliza("Mona_Liza","Day_Vinci",500);
	List list(monaliza);
	Menu menu(list);
	menu.list.LoadFile(argv[1]);
	char number = 0;
	while (number != '6') {
		cout << "\n";
		cout << "Muzeum:\n";
		cout << "1) Print all exponats \n";
		cout << "2) Add exponats\n";
		cout << "3) Search exponat \n";

		cout << "4) Change author \n";
		cout << "5) Delete exponat \n";
		cout << "6) Exit \n";
		cout << "\n";
		cout << "Print number from 1 to 6:\n";
		cin >> number;

		menu.Cls();
		switch (number) {
		case '1':
			menu.Print();
			break;
		case '2':
			menu.Add();
			break;
		case '3':
			menu.Search();
			break;
		case '4':
			menu.Change();
			break;
		case '5':
			menu.Del();
			break;
		case '6':
		default:
			break;
		}
	}
	menu.list.PrintFile(argv[1]);
	menu.list.Free();
	return 0;
}
