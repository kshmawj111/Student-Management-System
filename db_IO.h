#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "student.h"
#include <vector>
#include <map>

using namespace std;

class FileModule
{
private:
	vector <Student> m_student_db;
	map<string, string> m_mapping_table;
	void parse_to_db(string text, char delimiter, int db_pos);
	void parse_to_map(string text, char delimiter);

public:
	void read_file(string filename);	// read txtfile and save the contents to the student vector
	void db_to_file(string filename, vector <Student> student_db);
	void read_mapping(string filename);
	vector <Student> return_db() { return m_student_db; }
	map <string, string> reuturn_mapping() { return m_mapping_table; }

};