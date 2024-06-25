#pragma once
#include "menu.h"

class item {
public:
	item() : name{ "Default" }, count{ 0 } {}
	item(std::string name, int count) : name{ name }, count{ count } {}

	void setname(std::string name) { this->name = name; }
	void setcount(int count) { this->count = count; }

	std::string getname() { return name; }
	int getcount() { return count; }

	void changecount();
private:
	std::string name;
	int count;
};

class itemlist : public menu
{
public:
	itemlist(std::string title, std::string maintitle) { this->title = title; this->maintitle = maintitle; }

	void setisprotected(bool isprotected) { this->isprotected = isprotected; }

	bool getisprotected() { return isprotected; }

	void swapitems(item* item1, item* item2) { item temp = *item1;*item1 = *item2;*item2 = temp; }
	void additem();
	void removeitem();
	void changeitemquantity();
	void sortitemsname();
	void sortitemscount();
	void importitems();
	void exportitems();

	void showitems();

	void goback();
	void run();
private:
	std::vector<item*> items;
	bool isprotected = false;
};



