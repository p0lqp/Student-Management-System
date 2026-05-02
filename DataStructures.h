#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

struct StudentList {
    Node* head = NULL;

    Node* findStudent(int id) {
        Node* t = head;
        while (t != NULL) {
            if (t->data.id == id) {
                return t; 
            }
            t = t->next;
        }
        return NULL; 
    }

    void add(int id, string name, double gpa) {
        Node* newNode = new Node;
        newNode->data.id = id;
        newNode->data.name = name;
        newNode->data.gpa = gpa;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } 
        else {
            Node* t = head;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = newNode;
        }
    }

    void print() {
        Node* t = head;
        if (t == NULL) {
            cout << "List is empty!" << endl;
        }
        while (t != NULL) {
            cout << "ID: " << t->data.id;
            cout << " | Name: " << t->data.name;
            cout << " | GPA: " << t->data.gpa << endl;
            t = t->next;
        }
    }

    void edit(int id, string newName, double newGpa) {
        Node* t = head;
        while (t != NULL) {
            if (t->data.id == id) {
                t->data.name = newName;
                t->data.gpa = newGpa;
                cout << "Student updated!" << endl;
                return;
            }
            t = t->next;
        }
        cout << "Student not found!" << endl;
    }

    void remove(int id) {
        Node *t = head;
        Node *prev = NULL;
        
        while (t != NULL) {
            if (t->data.id == id) {
                if (prev == NULL) {
                    head = t->next;
                } 
                else {
                    prev->next = t->next;
                }
                delete t;
                cout << "Student deleted!" << endl;
                return;
            }
            prev = t;
            t = t->next;
        }
        cout << "Student not found!" << endl;
    }
};

struct MyStack {
    string arr[10];
    int top = -1;

    void push(string msg) {
        if (top < 9) {
            top++;
            arr[top] = msg;
        }
    }

    void show() {
        if (top == -1) {
            cout << "No history." << endl;
        }
        for (int i = top; i >= 0; i--) {
            cout << "-> " << arr[i] << endl;
        }
    }
};

struct MyHash {
    Student* table[20];
    bool taken[20];

    MyHash() {
        for (int i = 0; i < 20; i++) {
            taken[i] = false;
        }
    }

    int getHash(int id) {
        return id % 20;
    }

    void put(Student s) {
        int idx = getHash(s.id);
        while (taken[idx]) {
            idx = (idx + 1) % 20;
        }
        table[idx] = new Student;
        *table[idx] = s;
        taken[idx] = true;
    }

    void search(int id) {
        int idx = getHash(id);
        int startIdx = idx; 

        while (taken[idx]) {
            if (table[idx]->id == id) {
                cout << "Found in Hash: " << table[idx]->name << endl;
                return;
            }
            idx = (idx + 1) % 20; 
            if (idx == startIdx) break; 
        }
        cout << "Not found in Hash Table!" << endl;
    }
};

#endif