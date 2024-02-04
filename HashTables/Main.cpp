#include "HashTable.h"

int main() {
	HashTable groups;
	cout << "0 - Exit\n1 - add student\n2 - delete student\n3 - print groups\n4 - find student\n5 - load\n6 - save" << endl;
	size_t user_answer = 1;
	while (user_answer != 0) {
		cout << "Enter num: ";
		cin >> user_answer;
		switch (user_answer) {
		case 0:
			break;
		case 1:
		{
			Student st;
			cin >> st;
			groups.push(st);
		}
		break;
		case 2:
		{
			PIB pib;
			cout << "Enter PIB: ";
			cin >> pib.Fname;
			cin >> pib.Lname;
			cin >> pib.Sname;
			cout << "Enter Group: ";
			string group;
			cin >> group;
			groups.remove(pib, group);
		}
		break;
		case 3:
			groups.print();
			break;
		case 4:
		{
			cout << "Enter last name: ";
			string Lname;
			cin >> Lname;
			cout << "Enter Group: ";
			string group;
			cin >> group;
			if (groups.find(Lname, group)) cout << groups.find(Lname, group)->value;
			else cout << "Student not found\n";
		}
		break;
		case 5:
			groups.load();
			break;
		case 6:
			groups.save();
			break;
		default:
			cout << "Error\n";
			break;
		}
	}
}