#pragma once
#include <iostream>

class Menu
{
protected:
	int m_sel = -1;
	void get_sel(int valid_start, int valid_end);
	virtual void print_menu();

public:
	void run(int valid_start, int valid_end);
	int return_sel() { return m_sel; }

};