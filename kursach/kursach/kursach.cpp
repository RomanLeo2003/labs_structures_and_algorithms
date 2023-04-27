#include "Bank.h"
#include "Menu.h"
int main() {
	setlocale(LC_ALL, "rus");
	Menu menu = Menu();
	menu.MenuRunLoop();
	// fprintf(stdout, "jopa");
	return 0;
}