#include "adminmenu.h"

void adminmenu::goback(){
	system("cls");
	parent->run();
}

bool adminmenu::checkpassword() {
	if (access) {
		//xd
	}
	else {
		std::ifstream fileinput("password.txt");
		std::string password;

		if (!fileinput) {
			fileinput.close();
			std::ofstream fileoutput("password.txt");
			fileoutput << "admin";
			fileoutput.close();
			std::ifstream fileinput("password.txt");
		}

		fileinput >> password;

		std::string input;
		std::cout << "Введите пароль(q для выхода): ";
		std::cin >> input;

		if (input == "q") {
			system("cls");
			return false;
		}
		else if (password == input) {
			system("cls");
			access = true;
			return true;
		}
		else {
			system("cls");
			std::cout << "Неверный пароль" << std::endl;
			checkpassword();
		}
	}

}
void adminmenu::changepassword() {
	system("cls");
	std::string input;
	std::cout << "Введите пароль(кроме q): ";
	std::cin >> input;


	if (input == "q") {
		std::cout << "q нельзя!!!" << std::endl;
		changepassword();
	}
	else {
		std::ofstream fileoutput("password.txt");
		fileoutput << input;
		fileoutput.close();
		access = false;
		goback();
	}
}

void adminmenu::run() {
	if (!checkpassword()) {
		goback();
	}
	else {
		std::cout << maintitle << std::endl;

		int i;
		for (i = 0;i < options.size();i++) {
			std::cout << i + 1 << ") " << options[i]->gettitle() << std::endl;
		}
		std::cout << i + 1 << ") Сменить пароль" << std::endl;
		i++;
		std::cout << i + 1 << ") Назад" << std::endl;

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
				goback();
			}
			else if (choice == i) {
				changepassword();
			}
			else {
				system("cls");
				options[0]->setparent(parent->getoption(0));
				options[choice - 1]->run();
			}
		}
		else {
			run();
		}
	}
}