#include "mainmenu.h"

void mainmenu::exit() {
	system("cls");
	std::cout << "Выход";
}

void mainmenu::run() {
	std::cout << maintitle << std::endl;
	
	int i;
	for (i = 0;i < options.size();i++) {
		std::cout << i + 1 << ") " << options[i]->gettitle() << std::endl;
	}
	std::cout << i + 1 << ") Выход" << std::endl;

	std::string input;
	std::cout << "Выберите опцию: ";
	std::cin >> input;
	int choice;
	bool error = false;

	try {
		choice = stoi(input);
	}
	catch (...) {
		system("cls");
		std::cout << "Неправильный ввод" << std::endl;
		error = true;
	}

	if (!error && !(choice <= 0) && !(choice >= 4)) {
		if (choice == i + 1) {
			exit();
		}
		else {
			system("cls");
			options[choice - 1]->run();
		}
	}
	else {
		run();
	}
}