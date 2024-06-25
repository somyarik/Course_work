#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>

class menu
{
public:
	menu() : title{ "Default title" }, maintitle{ "Default maintitle" } {}
	menu(std::string title, std::string maintitle) : title{ title }, maintitle{ maintitle } {}

	void settitle(std::string title) { this->title = title; }
	void setmaintitle(std::string maintitle) { this->maintitle = maintitle; }
	void setparent(menu* parent) { this->parent = parent; }

	std::string gettitle() { return title; }
	std::string getmaintitle() { return maintitle; }
	menu* getparent() { return parent; }
	menu* getoption(int option) { return options[option]; }

	void addoption(menu* option) { options.push_back(option); }

	virtual void run() = 0;
protected:
	std::string title;
	std::string maintitle;
	std::vector<menu*> options;
	menu* parent = nullptr;
};

