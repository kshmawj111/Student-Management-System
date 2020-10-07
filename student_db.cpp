#include "student_db.h"

void StudentDB::add_student(const Student *student)
{
	m_student_db.push_back(*student);

}

void StudentDB::print_searched()
{
	int length = m_search_db.size();
	Student temp;
	if (length >= 1) {
		for (int i = 0; i < length; i++) {
			temp = m_search_db[i];

			cout << temp.return_name() << " " << temp.return_id() << " "
				<< temp.return_depart() << " " << endl;
		}
	}
	else {
		cout << "Nothing searched.\n";
	}
}

void StudentDB::sort_db(int refer)
{
	switch (refer) {
	
	case 2:	// sort by id
		sort(m_student_db.begin(), m_student_db.end(), [](Student s1, Student s2) -> bool
			{
				return s1.return_id() < s2.return_id();
			});
		break;

	case 3: // sort by department
		sort(m_student_db.begin(), m_student_db.end(), [](Student s1, Student s2) -> bool
			{
				return s1.return_depart() < s2.return_depart();
			});
		break;

	default: // sort by name. default
		sort(m_student_db.begin(), m_student_db.end(), [](Student s1, Student s2) -> bool
			{
				return s1.return_name() < s2.return_name();
			});
		break;
	}
}

void StudentDB::search_db(string keyword, int ref)
{
	// ref: 1, 2, 3, 4, 5 -> name, id, admission_year, department name
	int length = m_student_db.size(), i;
	string compared;

	for (i = 0; i < length; i++) {
		Student temp = m_student_db[i];

		if (ref == 1) {
			if (temp.return_name() == keyword) m_search_db.push_back(temp);
		}
		else if (ref == 2) {
			if (temp.return_id() == keyword) m_search_db.push_back(temp);
			break;	// loop out because student_id is unique.
		}
		else if (ref == 3) {
			if (temp.return_id().substr(0, 4) == keyword) m_search_db.push_back(temp);
			// first four characters are admission year
		}
		else if (ref == 4) {
			if (temp.return_depart() == keyword) m_search_db.push_back(temp);
		}
		else if (ref == 5){
			m_search_db.push_back(temp);
		}

	}
	
}