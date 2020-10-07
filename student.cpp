#include "student.h"

using namespace std;

void Student::set_name() {
	string name;
	int valid_name;

	do {
		valid_name = 0;
		cout << "Name: ";
		getline(cin, name);
		cin.clear();

		if (6 < name.size() && name.size() <= 15) {
			m_name = name;
			valid_name = 1;
		}
		else  if (name.size() == 0) cout << "Name should not be blank.\n" << endl;
		else cout << "Name must be longer than 6 and shorter than 16.\n" << endl;
	} while (!valid_name);
}


void Student::set_id(void) {
	string id;
	int valid_id;

	do {
		valid_id = 0;
		cout << "student id: ";
		getline(cin, id);
		cin.clear();

		if (id.size() == 10) {
			// id must be 10 length
			m_student_id = id;
			valid_id = 1;
		}
		else if (id.size() == 0) {
			cout << "Student id should not be blank.\n" << endl;
		}
		else {
			cout << "Student id must be exactly 10 length.\n" << endl;
		}
	} while (!valid_id);
}


void Student::set_department(map <string, string> mapping_table)
{
	string mapping_key = m_student_id.substr(4, 3);
	string depart;

	if (mapping_table.count(mapping_key) != 0) {
		depart = mapping_table[mapping_key];
		m_department = depart;
	}
	else {
		cout << "Deaprtment information is empty. Failed to get the department\n";
		m_department = "Unknown";
	}
	
}


void Student::set_department(string depart)
{
	m_department = depart;
}

void Student::set_email() {
	string email;
	int valid_email;

	do {
		valid_email = 0;
		cout << "Email: ";
		getline(cin, email);
		cin.clear();


		if (email.size() > 15) cout << "Email must be shorter than 16.\n" << endl;
		else {
			m_email = email;
			valid_email = 1;
		}
	} while (!valid_email);
}


void Student::set_tel(void) {
	string tel;
	int valid_tel;

	do {
		valid_tel = 0;
		cout << "Telephone number: ";
		getline(cin, tel);
		cin.clear();

		if (tel.size() > 12) cout << "Telephone number must be shorter than 16.\n" << endl;
		else {
			m_tel = tel;
			valid_tel = 1;
		}
	} while (!valid_tel);
}


void Student::set_data(map <string, string> mapping_table) {

	set_name();
	set_id();
	set_department(mapping_table);
	set_email();
	set_tel();
}


void Student::set_data(string name, string id, string depart, string email, string tel)
{
	m_name = name;
	m_student_id = id;
	m_department = depart;
	m_email = email;
	m_tel = tel;

}