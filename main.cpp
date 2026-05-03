#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <limits>

using namespace std;

// Structures

struct Book {
    int id;
    string title;
    string author;
    bool available;
};

struct Member {
    int id;
    string name;
};

struct Transaction {
    int memberId;
    int bookId;
    bool returned;
};

// Class

class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Transaction> transactions;

    // Validation

    bool bookExists(int id) const {
        return any_of(books.begin(), books.end(),
            [id](const Book& b) { return b.id == id; });
    }

    bool memberExists(int id) const {
        return any_of(members.begin(), members.end(),
            [id](const Member& m) { return m.id == id; });
    }

    Book* getBook(int id) {
        for (auto& b : books)
            if (b.id == id) return &b;
        return nullptr;
    }

public:

    // Input

    void saveData() {
        ofstream fb("books.csv"), fm("members.csv"), ft("transactions.csv");

        for (auto& b : books)
            fb << b.id << "," << b.title << "," << b.author << "," << b.available << "\n";

        for (auto& m : members)
            fm << m.id << "," << m.name << "\n";

        for (auto& t : transactions)
            ft << t.memberId << "," << t.bookId << "," << t.returned << "\n";

        cout << "Date salvate!\n";
    }

    void loadData() {
        ifstream fb("books.csv"), fm("members.csv"), ft("transactions.csv");

        books.clear();
        members.clear();
        transactions.clear();

        Book b;
        while (fb >> b.id) {
            fb.ignore();
            getline(fb, b.title, ',');
            getline(fb, b.author, ',');
            fb >> b.available;
            fb.ignore();
            books.push_back(b);
        }

        Member m;
        while (fm >> m.id) {
            fm.ignore();
            getline(fm, m.name);
            members.push_back(m);
        }

        Transaction t;
        while (ft >> t.memberId) {
            ft.ignore();
            ft >> t.bookId;
            ft.ignore();
            ft >> t.returned;
            ft.ignore();
            transactions.push_back(t);
        }

        cout << "Date incarcate!\n";
    }

    // Books

    void addBook() {
        Book b;

        cout << "ID: "; cin >> b.id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (bookExists(b.id)) {
            cout << "(X) ID deja existent!\n";
            return;
        }

        cout << "Titlu: "; getline(cin, b.title);
        cout << "Autor: "; getline(cin, b.author);

        b.available = true;
        books.push_back(b);

        cout << "Carte adaugata!\n";
    }

    void searchBook() {
        string title;
        cin.ignore();
        cout << "Cauta titlu: ";
        getline(cin, title);

        for (auto& b : books) {
            if (b.title.find(title) != string::npos) {
                cout << b.id << " | " << b.title << " | " << b.author << endl;
            }
        }
    }

    void listBooks() const {
        cout << "\n--- CARTI ---\n";
        for (const auto& b : books) {
            cout << "ID: " << b.id
                 << " | " << b.title
                 << " | " << b.author
                 << " | " << (b.available ? "Disponibila" : "Imprumutata")
                 << endl;
        }
    }

    void deleteBook() {
        int id;
        cout << "ID: "; cin >> id;

        books.erase(remove_if(books.begin(), books.end(),
            [id](Book b) { return b.id == id; }), books.end());

        cout << "Carte stearsa!\n";
    }

    // Members

    void addMember() {
        Member m;

        cout << "ID: "; cin >> m.id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (memberExists(m.id)) {
            cout << "(X) ID existent!\n";
            return;
        }

        cout << "Nume: "; getline(cin, m.name);
        members.push_back(m);

        cout << " Membru adaugat!\n";
    }

    void listMembers() {
        cout << "\n MEMBRI\n";
        for (auto& m : members) {
            cout << m.id << " | " << m.name << endl;
        }
    }

    // Transactions

    void borrowBook() {
        int bid, mid;

        cout << "ID carte: "; cin >> bid;
        cout << "ID membru: "; cin >> mid;

        if (!memberExists(mid)) {
            cout << "(X) Membru invalid!\n";
            return;
        }

        for (auto& b : books) {
            if (b.id == bid && b.available) {
                b.available = false;
                transactions.push_back({mid, bid, false});
                cout << " Imprumut realizat!\n";
                return;
            }
        }

        cout << "(X) Carte indisponibila!\n";
    }

    void returnBook() {
        int bid;
        cout << "ID carte: "; cin >> bid;

        for (auto& t : transactions) {
            if (t.bookId == bid && !t.returned) {
                t.returned = true;

                for (auto& b : books)
                    if (b.id == bid) b.available = true;

                cout << "↩ Returnare realizata!\n";
                return;
            }
        }

        cout << "(X) Tranzactie inexistenta!\n";
    }

    // Reports

    void report() const {
        cout << "\n RAPORT COMPLET\n";

        listBooks();

        cout << "\nTRANZACTII\n";
        for (const auto& t : transactions) {
            cout << "Membru " << t.memberId
                 << " -> Carte " << t.bookId
                 << " | " << (t.returned ? "Returnata" : "Imprumutata")
                 << endl;
        }
    }

    // Menu

    void menu() {
        int opt;

        do {
            cout << "\n===== BIBLIOTECA =====\n";
            cout << "1. Adauga carte\n";
            cout << "2. Lista carti\n";
            cout << "3. Cauta carte\n";
            cout << "4. Sterge carte\n";
            cout << "5. Adauga membru\n";
            cout << "6. Lista membri\n";
            cout << "7. Imprumuta carte\n";
            cout << "8. Returneaza carte\n";
            cout << "9. Raport\n";
            cout << "10. Salveaza\n";
            cout << "11. Incarca\n";
            cout << "0. Exit\n";
            cout << "Optiune: ";

            cin >> opt;

            switch (opt) {
                case 1: addBook(); break;
                case 2: listBooks(); break;
                case 3: searchBook(); break;
                case 4: deleteBook(); break;
                case 5: addMember(); break;
                case 6: listMembers(); break;
                case 7: borrowBook(); break;
                case 8: returnBook(); break;
                case 9: report(); break;
                case 10: saveData(); break;
                case 11: loadData(); break;
            }

        } while (opt != 0);

        saveData(); // auto-save
    }
};

// Main

int main() {
    Library lib;
    lib.loadData(); // auto-load
    lib.menu();
    return 0;
}