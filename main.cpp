#include "student_db.h"
#include "search_menu.h"
#include "Student.h"
#include "sort_menu.h"
#include "db_reader.h"

using namespace std;

int main()
{
	int sel, valid_sel, sort_sel;
	StudentDB student_db;
	FileModule filemanager;
	map <string, string> mapping_table;
	
	filemanager.read_mapping("file2.txt"); // mapping table must be made before reading database from file1.txt
	filemanager.read_db("file1.txt");
	

	student_db.return_db() = filemanager.return_db();
	mapping_table = filemanager.reuturn_mapping();

	while (true) {
		do {
			{
				sel = 0, valid_sel = 0;
				cout << "Select the number to execute\n"
					"1. Insertion\n"
					"2. Search\n"
					"3. Sorting Option\n"
					"4. Exit\n"
					"> ";

				cin >> sel;
				cin.clear();
				cin.ignore(1024, '\n');
				cout << "\n";

				if (1 <= sel && sel <= 4) { valid_sel = 1; }
				else {
					cout << "Selection must be an integer between 1 and 4\n" << endl;
					}
			}
		} while (!valid_sel);

		switch (sel) {
			case 1:	// insertion
			{
				Student* new_student = new Student;
				new_student->set_data(mapping_table);
				student_db.add_student(new_student);
				cout << "\nStudent information successfuly saved.\n";
				break;
			}

			case 2:	// search
			{
				Search search_menu;
				cout << "\n";
				search_menu.run(1, 5);

				int search_sel = search_menu.return_sel();
				string keyword = search_menu.return_keyword();
				
				student_db.search_db(keyword, search_sel);
				student_db.print_searched();
				break;
			}

			case 3:	// sort
			{
				Sort sort_menu;
				cout << "\n";
				sort_menu.run(1, 3);	// valid choices for sort is 1 to 3
				sort_sel = sort_menu.return_sel();
				student_db.sort_db(sort_sel);
				break;
			}

			case 4:	// exit
			{
				filemanager.write_obj("file1.txt", student_db.return_db());
				cout << "Exiting the program.";
				exit(1);
				break;
			}

		}
		cout << "\n";
	}

	return 0;
}