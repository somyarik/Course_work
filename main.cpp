#include "menu.h"
#include "mainmenu.h"
#include "adminmenu.h"
#include "usermenu.h"
#include "itemlist.h"

void start() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    mainmenu menumain = mainmenu("somtitle1", "Выбор способа входа");

    adminmenu menuadmin = adminmenu("Администратор", "Выполнен вход как Администратор");
    usermenu menuuser = usermenu("Пользователь", "Выполнен вход как пользователь");
    itemlist listitem = itemlist("Просмотреть товар", "Список товаров:");

    menumain.addoption(&menuadmin);
    menuadmin.setparent(&menumain);
    menumain.addoption(&menuuser);
    menuuser.setparent(&menumain);

    menuadmin.addoption(&listitem);
    menuuser.addoption(&listitem);
    listitem.importitems();

    menumain.run();
}

int main()
{
    start();
    return 0;
}
