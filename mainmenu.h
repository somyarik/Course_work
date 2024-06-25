#pragma once
#include "menu.h"

class mainmenu : public menu
{
public:
	mainmenu(std::string title, std::string maintitle) { this->title = title; this->maintitle = maintitle; }

	void exit();
	void run();
};

