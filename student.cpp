#include "student.h"

using namespace std;

void Student::set_name()
{
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
		else  if (name.size() == 0) cout << "\n@Error: Name should not be blank.\n" << endl;
		else cout << "\n@Error: Name must be longer than 6 and shorter than 16.\n" << endl;
	} while (!valid_name);
}


// return true if id is unique, return false if not unique
bool Student::is_unique_id(string id, vector <Student> student_db)
{

	vector <Student>::iterator iter;
	for (iter = student_db.begin(); iter != student_db.end(); iter++) {
		if (iter->m_student_id == id) return false;
	}

	return true;

}

void Student::set_id(vector <Student> student_db) 
{
	string id;

	bool is_unique = true, valid_id;
	vector <Student>::iterator iter;

	do {
		valid_id = false;
		cout << "student id: ";
		getline(cin, id);
		cin.clear();

		if (id.size() == 10) {
			// id must be 10 length

			if (student_db.size() > 0) {	
				// only checks duplicated student id when there is at least one data in the student db
				
				if ((is_unique = is_unique_id(id, student_db)) == true) {
					m_student_id = id;
					valid_id = true;
				}

				else {
					cout << "\n@Error: This id already exists in the student db.\n";
					cout << "Return to the main menu\n";
				}
			}

			else {
				// if student db is NULL, just save the student id
				is_unique = true;
				m_student_id = id;
				valid_id = true;
			}

			
		}
		else if (id.size() == 0) {	// blank entered
			cout << "\n@Error: Student id should not be blank.\n" << endl;
		}
		else {	// length not 10
			cout << "\n@Error: Student id must be exactly 10 length.\n" << endl;
		}

		if (is_unique == false) {	// if duplicate
			id_unique = is_unique;	// set member id_unique as false. So that other methods can get signal to pass the method.
			break;					// force exit when id is duplicated. Other cases ex) id size error still gets new input from the user
		}
	} while (!valid_id);
}


void Student::set_department(map <string, string> mapping_table)
{
	string mapping_key = m_student_id.substr(4, 3);
	string depart;

	if (mapping_table.count(mapping_key) != 0) {	// if mapping table has right key
		depart = mapping_table[mapping_key];
		m_department = depart;
	}
	else {
		cout << "@Warning: Cannot find right department value for key: " << mapping_key << "\n";
		cout << "Program instead marks the department information for this student as 'Unknown'" << endl;
		m_department = "Unknown";
	}
	
}


void Student::set_department(string depart)
{
	m_department = depart;
}

void Student::set_email() 
{
	string email;
	int valid_email;

	do {
		valid_email = 0;
		cout << "Email: ";
		getline(cin, email);
		cin.clear();


		if (email.size() > 15) cout << "\n@Error: Email must be shorter than 16.\n" << endl;
		else {
			m_email = email;
			valid_email = 1;
		}
	} while (!valid_email);
}


void Student::set_tel(void)
{
	string tel;
	bool valid_tel, only_num;


	do {
		valid_tel = false;
		only_num = true;
		cout << "Telephone number: ";
		getline(cin, tel);
		cin.clear();

		if (tel.size() > 12) cout << "\n@Error: Telephone number must be shorter than 16.\n" << endl;
		else {
			for (size_t i = 0; i < tel.size(); i++) {
				if (tel[i] < '0' || '9' < tel[i]) {
					cout << "\n@Error: Only numbers can be entered in the telephone number.\n";
					only_num = false;
					break;
				}
			}

			if (only_num == true) {
				m_tel = tel;
				valid_tel = true;
			}
		}
	} while (!valid_tel);
}


void Student::set_data(vector <Student> student_db, map <string, string> mapping_table) 
{

	set_name();
	set_id(student_db);
	if (id_unique == true) {	// execute other methods only in which id is unique
		set_department(mapping_table);
		set_email();
		set_tel();
	}
}


void Student::set_data(string name, string id, string depart, string email, string tel)
{
	m_name = name;
	m_student_id = id;
	m_department = depart;
	m_email = email;
	m_tel = tel;

}