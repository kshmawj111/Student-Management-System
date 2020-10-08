#include "menu.h"

using namespace std;

// method that shows the menu text and gets input from user.
void Menu::run(int valid_start, int valid_end)
{
	print_menu();
	get_sel(valid_start, valid_end);

}

// menu print method
void Menu::print_menu(){
	cout << "Menu needs to be typed by overriding print_menu() method.\n";
}


// method that gets input from user and validate it.
void Menu::get_sel(int valid_start, int valid_end)
{
	int sel, valid_sel;

	do {
		valid_sel = 0;
		cin >> sel;
		cin.ignore(1024, '\n');

		if (valid_start <= sel &&  sel <= valid_end) {
			valid_sel = 1;
			m_sel = sel;
		}

		else {
			cout << "Wrong number entered. Please choose the right number.\n";
			cout << ">> ";
		}
	} while (!valid_sel);

}