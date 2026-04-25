#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string title, author, dueDate;

public:
    LibraryItem(string t, string a, string d) {
        title = t;
        author = a;
        dueDate = d;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
public:
    Book(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() override {
        dueDate = "15 Days";
    }

    void returnItem() override {
        dueDate = "Available";
    }

    void displayDetails() const override {
        cout << "Book | Title: " << title
             << " | Author: " << author
             << " | Status: " << dueDate << endl;
    }
};

class DVD : public LibraryItem {
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d) {
        duration = dur;
    }

    void checkOut() override {
        dueDate = "7 Days";
    }

    void returnItem() override {
        dueDate = "Available";
    }

    void displayDetails() const override {
        cout << "DVD | Title: " << title
             << " | Author: " << author
             << " | Duration: " << duration
             << " mins | Status: " << dueDate << endl;
    }
};

class Magazine : public LibraryItem {
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d) {
        issueNumber = issue;
    }

    void checkOut() override {
        dueDate = "30 Days";
    }

    void returnItem() override {
        dueDate = "Available";
    }

    void displayDetails() const override {
        cout << "Magazine | Title: " << title
             << " | Author: " << author
             << " | Issue: " << issueNumber
             << " | Status: " << dueDate << endl;
    }
};

int main() {
    const int MAX = 10;
    LibraryItem* items[MAX];
    int count = 0;

    int choice;

    do {
        cout << "\n===== Library Menu =====";
        cout << "\n1. Add Book";
        cout << "\n2. Add DVD";
        cout << "\n3. Add Magazine";
        cout << "\n4. Display All";
        cout << "\n5. Checkout Item";
        cout << "\n6. Return Item";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        try {
            if (choice == 1 && count < MAX) {
                string t, a, d;
                cout << "Enter title: ";
                cin >> t;
                cout << "Enter author: ";
                cin >> a;
                cout << "Enter due date: ";
                cin >> d;

                items[count++] = new Book(t, a, d);
            }
            else if (choice == 2 && count < MAX) {
                string t, a, d;
                int dur;

                cout << "Enter title: ";
                cin >> t;
                cout << "Enter author: ";
                cin >> a;
                cout << "Enter due date: ";
                cin >> d;
                cout << "Enter duration: ";
                cin >> dur;

                if (dur < 0) throw "Invalid duration";

                items[count++] = new DVD(t, a, d, dur);
            }
            else if (choice == 3 && count < MAX) {
                string t, a, d;
                int issue;

                cout << "Enter title: ";
                cin >> t;
                cout << "Enter author: ";
                cin >> a;
                cout << "Enter due date: ";
                cin >> d;
                cout << "Enter issue number: ";
                cin >> issue;

                if (issue < 0) throw "Invalid issue number";

                items[count++] = new Magazine(t, a, d, issue);
            }
            else if (choice == 4) {
                for (int i = 0; i < count; i++) {
                    cout << "Index " << i << ": ";
                    items[i]->displayDetails();
                }
            }
            else if (choice == 5) {
                int i;
                cout << "Enter index: ";
                cin >> i;

                if (i >= 0 && i < count)
                    items[i]->checkOut();
                else
                    cout << "Invalid index\n";
            }
            else if (choice == 6) {
                int i;
                cout << "Enter index: ";
                cin >> i;

                if (i >= 0 && i < count)
                    items[i]->returnItem();
                else
                    cout << "Invalid index\n";
            }

        } catch (const char* msg) {
            cout << "Error: " << msg << endl;
        }

    } while (choice != 0);

    for (int i = 0; i < count; i++) {
        delete items[i];
    }

    return 0;
}