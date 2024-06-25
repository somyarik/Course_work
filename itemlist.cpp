#include "itemlist.h"

void item::changecount() {
	std::string input;
	std::cout << "������� ����������: ";
	std::cin >> input;
	int choice;
	bool error = false;

	try {
		choice = stoi(input);
	}
	catch (...) {
		error = true;
	}

	if (!error && choice >= 0) {
		setcount(choice);
	}
	else{
		std::cout << "������������ ����" << std::endl;
		changecount();
	}
}

void itemlist::goback() {
	system("cls");
	sortitemsname();
	exportitems();
	parent->run();
}

void itemlist::additem() {																		//�������� �������
	std::string inputname, inputcount;
	int count;

	bool breaker;
	while (true) {
		breaker = false;
		
		std::cout << "������� �������� ������: ";
		std::cin >> inputname;
		for (int i = 0;i < items.size();i++) {
			if (inputname == items[i]->getname()) {
				std::cout << "����� ����� ��� ����������." << std::endl;
				breaker = true;
			}
		}
		if (breaker) continue;

		std::cout << "������� ���������� ������: ";
		std::cin >> inputcount;
		try {
			count = stoi(inputcount);
		}
		catch (...) {
			std::cout << "������������ ����" << std::endl;
			breaker = true;
		}
		if (count < 0){
			std::cout << "������������ ����" << std::endl;
			breaker = true;
		}
		if (breaker) continue;

		item* item1 = new item(inputname, count);
		items.push_back(item1);
		break;
	}
	system("cls");
	exportitems();
	run();
}
void itemlist::removeitem() {																		//������ �������
	showitems();
	std::string input;
	std::cout << "������� ����� ��� �������� ������ ������� �� ������ �������: ";
	std::cin >> input;

	int num;
	bool isnum = false;
	bool nothing = true;
	try {
		num = stoi(input);
		isnum = true;
	}
	catch (...) {
		isnum = false;
	}

	if (isnum == true) {
		if (num <= items.size() && num > 0) {
			nothing = false;
			items.erase(items.begin() + num - 1);
		}
	}
	else {
		for (int i = 0;i < items.size();i++) {
			if (items[i]->getname() == input) {
				items.erase(items.begin() + i);
				nothing = false;
				break;
			}
		}
	}
	if (nothing) std::cout << "������ ������ ������������." << std::endl;
	system("cls");
	exportitems();
	run();
}
void itemlist::changeitemquantity() {																		//�������� ����������
	showitems();
	std::string input;
	std::cout << "������� ����� ��� �������� ������, ���������� �������� �� ������ ��������: ";
	std::cin >> input;

	int num;
	bool isnum = false;
	bool nothing = true;
	try {
		num = stoi(input);
		isnum = true;
	}
	catch (...) {
		isnum = false;
	}

	if (isnum == true) {
		if (num <= items.size() && num > 0) {
			nothing = false;
			items[num - 1]->changecount();
		}
	}
	else {
		for (int i = 0;i < items.size();i++) {
			if (items[i]->getname() == input) {
				items[i]->changecount();
				nothing = false;
				break;
			}
		}
	}
	if (nothing) std::cout << "������ ������ ������������." << std::endl;
	system("cls");
	exportitems();
	run();
}
void itemlist::sortitemsname() {																		//���������� �� �����
	for (int i = 0;i < items.size();i++) {
		for (int j = 0;j < items.size() - 1;j++) {
			if (items[j]->getname() > items[j + 1]->getname()) {
				swapitems(items[j], items[j + 1]);
			}
		}
	}
}
void itemlist::sortitemscount() {																		//���������� �� ����������
	for (int i = 0;i < items.size();i++) {
		for (int j = 0;j < items.size() - 1;j++) {
			if (items[j]->getcount() < items[j + 1]->getcount()) {
				swapitems(items[j], items[j + 1]);
			}
		}
	}
}


void itemlist::importitems() {																		//������
	std::ifstream file("itemlist.csv");

	std::string name, quantity, stream, temp;
	int num = 0;
	std::vector<std::string> thing;
	thing.push_back(name);
	thing.push_back(quantity);

	while (true)
	{
		temp = "";
		num = 0;
		file >> stream;
		/*std::cout << stream << std::endl;*/
		if (stream == "end;") break;
		for (int i = 0;i < stream.size();i++) {
			if (stream[i] == ';') {
				thing[num] = temp;
				num++;
				temp = "";
			}
			else {
				temp.push_back(stream[i]);
			}
		}
		thing[num] = temp;
		/*for (int i = 0;i < thing.size();i++) {
			std::cout << thing[i] << ' ';
		}
		std::cout << std::endl;*/
		item* importitem = new item(thing[0], stoi(thing[1]));
		items.push_back(importitem);
	}
	file.close();
}
void itemlist::exportitems() {																		//�������
	std::ofstream file("itemlist.csv");
	for (int i = 0;i < items.size();i++) {
		file << items[i]->getname() << ';' << items[i]->getcount() << std::endl;
	}
	file << "end;";
	file.close();
}

void itemlist::showitems() {																		//�������� �����
	for (int i = 0;i < items.size();i++) {
		std::cout << i+1 << ')' << items[i]->getname() << ' ' << items[i]->getcount() << std::endl;
	}
}

void itemlist::run() {																		//������
	std::cout << "���������� �����/��������/����������" << std::endl;
	showitems();

	if (parent->gettitle() == "�������������") {
		isprotected = true;
	}
	else {
		isprotected = false;
	}

	std::cout << std::endl << "�������� ��������: " << std::endl;
	if (isprotected) {
		std::cout << "1) �������� �����" << std::endl << "2) ������� �����" << std::endl << "3) �������� ���������� ������" << std::endl << "4) ������������� ����� �� ��������" << std::endl << "5) ������������� ����� �� ����������" << std::endl << "6) �����" << std::endl;

		std::string input;
		std::cout << "�����: ";
		std::cin >> input;
		int choice;
		bool error = false;

		try {
			choice = stoi(input);
		}
		catch (...) {
			system("cls");
			std::cout << "������������ ����" << std::endl;
			error = true;
		}

		if (!error && !(choice <= 0) && !(choice >= 7)) {
			if (choice == 1) {
				system("cls");
				additem();
			}
			else if (choice == 2) {
				system("cls");
				removeitem();
			}
			else if (choice == 3) {
				system("cls");
				changeitemquantity();
			}
			else if (choice == 4) {
				system("cls");
				sortitemsname();
				run();
			}
			else if (choice == 5) {
				system("cls");
				sortitemscount();
				run();
			}
			else {
				exportitems();
				goback();
			}
		}
		else {
			system("cls");
			std::cout << "������������ ����" << std::endl;
			run();
		}
	}
	else {
		std::cout << "1) ������������� ����� �� ��������" << std::endl << "2) ������������� ����� �� ����������" << std::endl << "3) �����" << std::endl;

		std::string input;
		std::cout << "�����: ";
		std::cin >> input;
		int choice;
		bool error = false;

		try {
			choice = stoi(input);
		}
		catch (...) {
			system("cls");
			std::cout << "������������ ����" << std::endl;
			error = true;
		}

		if (!error && !(choice <= 0) && !(choice >= 4)) {
			if (choice == 1) {
				system("cls");
				sortitemsname();
				run();
			}
			else if (choice == 2) {
				system("cls");
				sortitemscount();
				run();
			}
			else {
				exportitems();
				goback();
			}
		}
		else {
			system("cls");
			std::cout << "������������ ����" << std::endl;
			run();
		}
	}
}