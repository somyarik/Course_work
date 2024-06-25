#pragma once
#include "menu.h"

class usermenu : public menu
{
public:
	usermenu(std::string title, std::string maintitle) { this->title = title; this->maintitle = maintitle; }

	void goback();
	void run();
private:

};

