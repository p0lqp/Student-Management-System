#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    double gpa;
};

struct Node {
    Student data;
    Node* next;
};

#endif