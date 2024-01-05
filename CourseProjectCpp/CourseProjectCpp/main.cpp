#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
    int itemNumber;
    float price;

public:
    Item() = default;
    Item(int _itemNumber, float _price) : itemNumber(_itemNumber), price(_price) {}

    int getItemNumber() const { return itemNumber; }
    float getPrice() const { return price; }

    virtual void printInfo() const {
        cout << "Item number: " << itemNumber << "\nPrice: " << price << endl;
    }

    float calculateTotalAmount() const {
        const float VATRate = 0.2;
        return price * (1 + VATRate);
    }

    ~Item() { cout << "Item destroyed!\n"; }
};

class Book : public Item {
    string title;
    string author;
    int yearOfPublishing;

public:
    Book() = default;
    Book(string _title, string _author, int _yearOfPublishing, int _itemNumber, float _price)
        : Item(_itemNumber, _price), title(_title), author(_author), yearOfPublishing(_yearOfPublishing) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYearOfPublishing() const { return yearOfPublishing; }

    void printInfo() const override {
        Item::printInfo(); 
        cout << "Title: " << title << "\nAuthor: " << author << "\nYear of Publishing: " << yearOfPublishing << endl;
    }

    ~Book() { cout << "Book destroyed!\n"; }
};

// Function to print information about books by a given author published after 2020
void printBooksByAuthorPublishedAfter(const vector<Book>& books, const string& author, int year) {
    cout << "\nBooks by " << author << " published after 2020:\n";
    for (const Book& book : books) {
        if (book.getAuthor() == author && book.getYearOfPublishing() > 2020) {
            book.printInfo();
        }
    }
}

int main() {
    vector<Book> books;

    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;

    for (int i = 0; i < numBooks; ++i) {
        string title, author;
        int yearOfPublishing;
        int itemNumber;
        float price;

        cout << "\nEnter details for Book #" << i + 1 << ":\n";
        cout << "Title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Author: ";
        getline(cin, author);

        cout << "Year of Publishing: ";
        cin >> yearOfPublishing;

        cout << "Item Number: ";
        cin >> itemNumber;

        cout << "Price: ";
        cin >> price;

        books.push_back(Book(title, author, yearOfPublishing, itemNumber, price));
    }

    cout << "\n\n\n";

    cout << "\n--- Details of entered books: ---\n";
    int j = 1;
    for (const Book& book : books) {
        printf("\nBook #%d\n", j);
        book.printInfo();
        j++;
    }

    cout << "\n\n\n";

    cout << "\nTotal order amounts including 20% VAT:\n";
    for (const Book& book : books) {
        cout << "Book #" << book.getItemNumber() << ": " << book.calculateTotalAmount() << endl;
    }

    string authorToSearch;
    cout << "\nEnter the author to search for: ";
    cin.ignore();
    getline(cin, authorToSearch);

    printBooksByAuthorPublishedAfter(books, authorToSearch, 2020);

    cout << "\n\n\n";

    return 0;
}