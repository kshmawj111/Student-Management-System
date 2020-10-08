 /*
*
*  student database class
* 
*		member variable: 
* 
*			m_student_db:Vector containing Student class 
*			m_search_db: Vector containing results for search
* 
*		member functions:
* 
*			add_student: appends new student class to the m_student_db
*			show_students: prints the contents of the m_student_db. If the db is sorted, print result will be applied.
*			sort_db(ref): sort by std sort algorithm with given ref integer.
*			search_db(keyword, ref): 
*/

#pragma once
#include "Student.h"
#include <vector>
#include <algorithm>

class StudentDB {
private:
	vector <Student> m_student_db;
	vector <Student> m_search_db;

public:
	void add_student(const Student* student);
	void print_searched();
	void sort_db(int ref);	// ref: 1, 2, 3, 4, 5 -> name, id, depart, email, tel. 
	void search_db(string keyword, int ref);	// keyword: target, ref: 1, 2, 3, 4, 5 -> name, id, admission_year, department name, all
	vector <Student> return_db() { return m_student_db; }
	void load_db(vector <Student> student_db) { m_student_db = student_db; }

};