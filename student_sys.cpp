#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string name;
    vector<string> courses;

    Student(string n) {
        name = n;
    }
};

int main() {

    vector<Student> students;
    int choice;
    string name, course;

    do {
        cout << "\n=== Student Management System ===" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Add Course to Student" << endl;
        cout << "4. Delete Course from Student" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Exit" << endl;

        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                cout << "Enter student name: ";
                cin >> name;

                bool found = false;

                for (int i = 0; i < students.size(); i++) {
                    if (students[i].name == name) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    cout << "Student already exists!" << endl;
                }
                else {
                    students.push_back(Student(name));
                    cout << "Student \"" << name << "\" added." << endl;
                }

                break;
            }

            case 2: {
                cout << "Enter student name: ";
                cin >> name;

                bool found = false;

                for (int i = 0; i < students.size(); i++) {
                    if (students[i].name == name) {
                        students.erase(students.begin() + i);
                        cout << "Student \"" << name << "\" deleted." << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found!" << endl;
                }

                break;
            }

            case 3: {
                cout << "Enter student name: ";
                cin >> name;

                bool found = false;

                for (int i = 0; i < students.size(); i++) {
                    if (students[i].name == name) {
                        cout << "Enter course name: ";
                        cin >> course;

                        students[i].courses.push_back(course);

                        cout << "Course \"" << course
                             << "\" added to " << name << "." << endl;

                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student not found!" << endl;
                }

                break;
            }

            case 4: {
                cout << "Enter student name: ";
                cin >> name;

                bool foundStudent = false;

                for (int i = 0; i < students.size(); i++) {
                    if (students[i].name == name) {
                        foundStudent = true;

                        cout << "Enter course name: ";
                        cin >> course;

                        bool foundCourse = false;

                        for (int j = 0; j < students[i].courses.size(); j++) {
                            if (students[i].courses[j] == course) {
                                students[i].courses.erase(
                                    students[i].courses.begin() + j
                                );

                                cout << "Course \"" << course
                                     << "\" removed from " << name << "." << endl;

                                foundCourse = true;
                                break;
                            }
                        }

                        if (!foundCourse) {
                            cout << "Course not found!" << endl;
                        }

                        break;
                    }
                }

                if (!foundStudent) {
                    cout << "Student not found!" << endl;
                }

                break;
            }

            case 5: {
                if (students.empty()) {
                    cout << "No students found." << endl;
                }
                else {
                    for (int i = 0; i < students.size(); i++) {
                        cout << "\nStudent: " << students[i].name << endl;
                        cout << "Courses: ";

                        if (students[i].courses.empty()) {
                            cout << "No courses enrolled.";
                        }
                        else {
                            for (int j = 0; j < students[i].courses.size(); j++) {
                                cout << students[i].courses[j];

                                if (j < students[i].courses.size() - 1) {
                                    cout << ", ";
                                }
                            }
                        }

                        cout << endl;
                    }
                }

                break;
            }

            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
