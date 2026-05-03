# it-school-base-project

Base Setup for Final Project

To build and run tests:
```shell
cmake --build out/build && cd out/build && ctest --output-on-failure
```

## Library Management System

A simple console-based library management system written in C++.
Supports book and member management, borrow/return transactions, and CSV-based data persistence.

---

## Features

- Add, search, list, and delete books
- Add and list library members
- Borrow and return books with transaction tracking
- Automatic save/load using CSV files
- Full report of books and transactions

---

## Requirements

- C++17 or later
- GCC

---

## Compilation

```bash
g++ -std=c++17 -o library main.cpp
```

---

## Usage

```bash
./library
```

The program auto-loads data from CSV files on startup and auto-saves on exit.

### Menu Options

| Option | Description |
|--------|-------------|
| 1 | Add a book |
| 2 | List all books |
| 3 | Search book by title |
| 4 | Delete a book |
| 5 | Add a member |
| 6 | List all members |
| 7 | Borrow a book |
| 8 | Return a book |
| 9 | Full report |
| 10 | Save data manually |
| 11 | Load data manually |
| 0 | Exit |

---

## Data Storage

Data is persisted automatically in three CSV files:

| File | Contents |
|------|----------|
| `books.csv` | Book ID, title, author, availability |
| `members.csv` | Member ID, name |
| `transactions.csv` | Member ID, book ID, return status |

> These files are created automatically in the same directory as the executable.

---

### Project Structure

library-management/
├── main.cpp          # All source code (structs, Library class, main)
└── README.md

## Key Components

- **`Book`** — stores ID, title, author, and availability status
- **`Member`** — stores ID and name
- **`Transaction`** — links a member to a borrowed book, tracks return status
- **`Library`** — main class handling all operations and the interactive menu

---

### Example Session

BIBLIOTECA 

Adauga carte
...
Optiune: 1
ID: 01
Titlu: The C++ Programming Language
Autor: Bjarne Stroustrup
└── Carte adaugata!
