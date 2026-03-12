📚 Library Management System (C++)

A console-based Library Management System developed in C++ that helps manage books, members, borrowing, returning, requests, and fines in an organized and digital way.

This project was developed as part of the Programming Fundamentals course (Fall 2025) at the Department of Computer Science, University of Engineering and Technology (UET) Lahore.

📌 Project Overview

The Library Management System (LMS) is designed to simplify library operations by replacing manual record-keeping with a digital system.

The application is a menu-driven console program that allows three types of users to interact with the system:

Admin (Head)

Librarian (Staff)

Student (User)

Each role has specific permissions and functionalities. The system manages:

Book inventory

Member records

Book borrowing and returning

Book requests

Fine calculation

Search functionality

The project also uses file handling to store data permanently so that records remain saved even after the program closes.

✨ Features

✔ Menu-driven interface for easy navigation
✔ Role-based access control
✔ Book management (Add / Update / Delete)
✔ Member registration and management
✔ Borrow and return books
✔ Book request and approval system
✔ Book search by Title, Author, or ID
✔ View borrowed books
✔ Fine checking system
✔ Change password feature
✔ File handling for data persistence
✔ Automatic book availability updates

👥 User Roles & Functionalities
🛠 Admin (Head)

Admin manages the library inventory and member records.

Admin Features

View all books

Add new books

Delete books

Update book details

View all members

Add/register new members

📖 Librarian (Staff)

The Librarian manages daily library operations.

Librarian Features

View borrowed books

Approve or decline book requests

Borrow books manually

Return books

Search books

🎓 Student (User)

Students can access books and manage their own borrowing activity.

Student Features

View all books

Search books

Request books

View borrowed books

Check fines

Change password

💾 Data Storage

The system uses file handling in C++ to store records in text files.

Data stored includes:

Books data

Members data

Borrowed books

Book requests

This ensures that data is automatically loaded when the program starts, preventing data loss.
