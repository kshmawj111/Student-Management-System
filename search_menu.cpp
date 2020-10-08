#pragma once
#include "search_menu.h"
#include <string>

using namespace std;

void Search::run(int valid_start, int valid_end)
{
	print_menu();
	get_sel(valid_start, valid_end);
	
	do {
		valid_keyword = 0;
		get_keyword();
	} while (!valid_keyword);
}

void Search::print_menu()
{
	cout << "- Search Option\n"
		"1. Search by name\n"
		"2. Search by student ID (10 numbers)\n"
		"3. Search by admission year(4 numbers)\n"
		"4. Search by department name\n"
		"5. List all\n"
		"> ";
}

void Search::print_keyword()
{
	cout << '\n';
	if (m_sel == 1) {
		cout << "Please enter name keyword: ";
	}
	else if (m_sel == 2) {
		cout << "Please enter student id number: ";
	}
	else if (m_sel == 3) {
		cout << "Please enter admission year: ";
	}
	else if (m_sel == 4) {
		cout << "Please enter department name: ";
	}

}

void Search::get_keyword()
{
	string keyword;

	if (m_sel != 5) {

		print_keyword();
		getline(cin, keyword);
		cin.clear();

		if (keyword.size() != 0) {
			if (m_sel == 1) {	// id must be 10 length
				if (keyword.size() <= 15) {
					m_keyword = keyword;
					valid_keyword = 1;	// if keyword input is succesful
				}
				else {
					cout << "Error: Name must be shorter than 15 characters including space.";

				}
			}

			else if (m_sel == 2) {	// id must be 10 length
				if (keyword.size() == 10) {
					m_keyword = keyword;
					valid_keyword = 1;	// if keyword input is succesful
				}
				else {
					cout << "Error: Student id must be 10 digits long.";

				}
			}

			else if (m_sel == 3) {	// admission year must be 4 length
				if (keyword.size() == 4) {
					m_keyword = keyword;
					valid_keyword = 1;
				}
				else {
					cout << "Error: Admission year must be length of four.";
				}
			}
		}
		else {
			cout << "Keyword must not be empty";
		}
		cout << "\n";
	}
	else valid_keyword = 1;
}