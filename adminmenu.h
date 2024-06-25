#pragma once
#include "menu.h"

class adminmenu : public menu
{
public:
	adminmenu(std::string title, std::string maintitle) { this->title = title; this->maintitle = maintitle; }

	void setaccess(bool access) { this->access = access; }
	
	bool getaccess() { return access; }

	bool checkpassword();
	void changepassword();

	void goback();
	void run();
private:
	bool access = false;
};

