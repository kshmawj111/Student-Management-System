/*
*	Header file containing interface for constructing a student information
*	class StudentInfo's set_data method get user input and save the value to the member.
*	Only the set_data and other getters are public.
* 
*/
#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Student
{
public:
	void set_data(vector <Student> student_db, map <string, string> mapping_table);
	void set_data(string name, string id, string depart, string email, string tel);
	void set_name(string name) {m_name = name;}
	void set_id(string id) { m_student_id = id; }
	void set_email(string email) { m_email = email; }
	void set_tel(string tel) { m_tel = tel; }
	void set_department(map <string, string> mapping_table);
	void set_department(string student_id);

	bool check_id_unique() { return id_unique; }	// if id is unique, return true

	string return_name(void) { return m_name; }
	string return_id(void) { return m_student_id; }
	string return_depart(void) { return m_department; }
	string return_email(void) { return m_email; }
	string return_tel(void) { return m_tel; }

private:
	string m_name;
	string m_student_id;
	string m_department;
	string m_email;
	string m_tel;

	bool id_unique = true;

	void set_name(void);
	void set_id(vector <Student> student_db);
	void set_email(void);
	void set_tel(void);
	bool is_unique_id(string id, vector <Student> student_db);

};



