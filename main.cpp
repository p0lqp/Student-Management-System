#include <iostream>
#include <fstream>
#include <string>
#include "DataStructures.h"

using namespace std;

int main() {
    StudentList list;
    MyStack stack;
    MyHash hash;

    ifstream fIn("data.txt");
    int id;
    string name;
    double gpa;

    while (fIn >> id) {
        fIn.ignore();           
        getline(fIn, name, '#'); 
        fIn >> gpa;             
    
        list.add(id, name, gpa);
        Student s = {id, name, gpa};
        hash.put(s);
    }
    fIn.close();

    int op;
    do {

        cout << "\n--- Student Management Menu ---" << endl;
        cout << "1. Add New Student" << endl;
        cout << "2. Print All Students" << endl;
        cout << "3. Search" << endl;
        cout << "4. Edit Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. View History" << endl;
        cout << "7. Save and Exit" << endl;
        cout << "Choice: ";
        cin >> op;
        cout << endl;
        if (op == 1) {
            cout << "ID: ";
            cin >> id;

            cout << "Name: ";
            cin.ignore();        
            getline(cin, name); 

            cout << "GPA: ";
            cin >> gpa;

            list.add(id, name, gpa);
            Student s = {id, name, gpa}; 
            hash.put(s);
            stack.push("Added: " + name);
        }
        else if (op == 2) {
            list.print();
        } 
        else if (op == 3) {
            cout << "Enter ID to search: ";
            cin >> id;
            hash.search(id);
        }
        else if (op == 4) {
            cout << "Enter ID to edit: ";
            cin >> id;

            if (list.findStudent(id) == NULL) {
                cout << "Student not found!" << endl;
            } 
            else {
                cout << "New Name: ";
                cin.ignore();        
                getline(cin, name);  

                cout << "New GPA: ";
                cin >> gpa;

                list.edit(id, name, gpa); 
                stack.push("Edited ID: " + to_string(id));
            }
        }
        else if (op == 5) {
            cout << "Enter ID to delete: ";
            cin >> id;

            list.remove(id);
            stack.push("Deleted ID: " + to_string(id));
        }
        else if (op == 6) {
            stack.show();
        }

    } while (op != 7);

    ofstream fOut("data.txt");
        Node* t = list.head;
        while (t != NULL) {

            fOut << t->data.id << " " << t->data.name << "#" << t->data.gpa << endl;
            t = t->next;
        }
        fOut.close();

    cout << "Data saved to data.txt. Bye!" << endl;

    return 0;
}