#include "db_IO.h"

using namespace std;

void FileModule::parse_to_db(string text, char delimiter, int db_pos)
{
	string token;
	int variable_count=1;
	Student temp;
	int pos;

	while (((pos = text.find(delimiter)) != string::npos)) {
		token = text.substr(0, pos);

		switch (variable_count++) {
		case 1:	// token == name
			temp.set_name(token);
			text.erase(0, pos + 1);
			break;

		case 2:	// token == id
			temp.set_id(token);
			text.erase(0, pos + 1);
			break;

		case 3:	// token == department
			temp.set_department(token);	// overloading department with string argument.
			text.erase(0, pos + 1);
			break;

		case 4: // token == email
			temp.set_email(token);
			text.erase(0, pos + 1);
			break;		
		
		}
	}

	// 마지막 남은 텍스느는 여기로
	token = text.substr(0, pos);
	temp.set_tel(token);
	text.erase(0, pos + 1);

	m_student_db.push_back(temp);
}

void FileModule::parse_to_map(string line, char delimiter)
{
	string key, value;
	int pos;

	pos = line.find(delimiter);
	key = line.substr(0, pos);
	value = line.substr(pos + 1, line.length());
	m_mapping_table[key] = value;


}

void FileModule::read_file(string filename)
{
	int idx;
	size_t filesize;
	string  string_buf;

	streampos start, end;

	ifstream file(filename, ios::in);

	start = file.tellg();
	file.seekg(0, ios::end);
	end = file.tellg();
	file.seekg(0, ios::beg);

	filesize = end - start;
	
	if (filesize > 0) {	// read Student objects only in the case the file is not empty.
		if (file.is_open() == true) {
			idx = 0;

			while (getline(file, string_buf)) {
				parse_to_db(string_buf, ',', idx++);
				
			}
		}
	}
	else {
		cout << "**************************************************************\n";
		cout << "Warning: " << filename << " is empty." << endl;
		cout << "This warning may arise at the first launch of program.\n";
		cout << "**************************************************************\n\n";

	}

	file.close();
}

void FileModule::read_mapping(string filename)
{
	int idx, filesize;
	string  string_buf;

	streampos start, end;

	ifstream file(filename, ios::in);

	start = file.tellg();
	file.seekg(0, ios::end);
	end = file.tellg();
	file.seekg(0, ios::beg);

	filesize = end - start;

	if (filesize > 0) {	// read Student objects only in the case the file is not empty.
		if (file.is_open() == true) {
			idx = 0;

			while (getline(file, string_buf)) {
				parse_to_map(string_buf, ' ');

			}
		}
	}
	else {
		cout << "Error occured while reading " << filename << endl;
		exit(1);
	}

	file.close();

}


void FileModule::db_to_file(string filename, vector <Student> student_db)
{
	ofstream file(filename);	// file is created at this point
	int length = student_db.size(), i;

	if (length > 0) {

		for (i = 0; i < length; i++) {
			Student temp = student_db[i];

			file << temp.return_name() << ',' 
				<< temp.return_id() << ','
				<< temp.return_depart() << ',' 
				<< temp.return_email() << ','
				<< temp.return_tel() << "\n";
		}

		cout << "Database is succesfully saved as " << filename << ".\n";
	}

}