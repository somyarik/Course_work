#include "usermenu.h"

void usermenu::goback() {
	system("cls");
	parent->run();
}

void usermenu::run() {
	std::cout << maintitle << std::endl;

	int i;
	for (i = 0;i < options.size();i++) {
		std::cout << i + 1 << ") " << options[i]->gettitle() << std::endl;
	}
	std::cout << i + 1 << ") �����" << std::endl;

	std::string input;
	std::cout << "�������� �����: ";
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

	if (!error && !(choice <= 0) && !(choice >= 3)) {
		if (choice == i + 1) {
			goback();
		}
		else {
			system("cls");
			options[0]->setparent(parent->getoption(1));
			options[choice - 1]->run();
		}
	}
	else {
		run();
	}
}