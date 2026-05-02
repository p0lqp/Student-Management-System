===========================================================
PROJECT: Student Management System (CS214)
AUTHOR: Majed Traheeb Alruqi
UNIVERSITY ID: 441109831
SECTION: 6013
SUPERVISOR: Dr. Osamah Alzakan
===========================================================

1. DESCRIPTION
--------------
This project is a Student Management System implemented in C++. It allows 
users to manage student records efficiently using high-performance 
data structures. The system supports full CRUD operations (Create, Read, 
Update, Delete), fast search, and operation history tracking.

2. DATA STRUCTURES USED
-----------------------
To ensure maximum efficiency, the project utilizes:

* Linked List: Used for dynamic student storage in memory.
* Stack: Implements the 'Action History' tracking (LIFO).
* Hash Table: Used for high-speed searching by Student ID (O(1) search).

3. FILE STRUCTURE
-----------------
* main.cpp: Contains the menu logic and file handling.
* DataStructures.h: Implementation of List, Stack, and Hash Table.
* Student.h: Definition of Student and Node structures.
* data.txt: Database file for persistent storage.

4. TECHNICAL NOTE (FILE PERSISTENCE)
------------------------------------
The system uses a '#' delimiter in 'data.txt' to separate the Student 
Name from the GPA. This ensures the program can accurately read names 
containing spaces without parsing errors.

5. HOW TO RUN
-------------
1. Compile all files using a C++ compiler (e.g., g++):
   g++ main.cpp -o StudentSystem

2. Run the executable:
   ./StudentSystem

6. GITHUB REPOSITORY
--------------------
You can find the full source code and version history at:
https://github.com/p0lqp/Student-Management-System
===========================================================