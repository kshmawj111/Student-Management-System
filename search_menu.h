#pragma once
#include <iostream>
#include "menu.h"

using namespace std;

class Search : public Menu
{
private:
	string m_keyword = "";
	int valid_keyword = -1;
	void print_menu();
	void print_keyword();
	void get_keyword();

public:
	void run(int valid_start, int valid_end);
	string return_keyword() { return m_keyword; }
};