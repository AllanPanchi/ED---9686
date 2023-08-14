#include <iostream>
#include "Menu.h"

int main() {
	try {
		Menu::menuPrincipal();
	} catch (const std::exception&) {
		std::cout << "Error" << std::endl;
	}
	return 0;
}
