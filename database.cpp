#include <iostream>
#include <string>

using namespace std;

class Category;
class List;

class Cell {
    public:
    int id;
    Cell* prev;
    Cell* next;
    Category* category;
    string text;

    void init (Cell* p, Cell* n, Category* c, string t) {
        prev = p;
        next = n;
        category = c;
        text = t;
    }
};

class Category: public Cell {
    public:
    List* data = nullptr;    
};

class List {
    public:
    Cell* head = nullptr;
    Cell* tail = nullptr;

    void add (Cell* new_cell) {
        if (this->head == nullptr) {
            this->head = new_cell;
            this->tail = new_cell;
        } 
        else {
            this->tail->next = new_cell;
            new_cell->prev = this->tail;
            this->tail = new_cell;
        }
    }
};

class Database {
    public:
    int cell_count = 0;
    string name;
    Cell* head;
    List* categories;

    void init (string n, List* c) {
        name = n;
        categories = c;
    }
};

Database* database = new Database;

int main(int argc, char *argv[]) {
    int option;
    string name;
    int cat_number;
    string cat_name;
    Cell* iterator = new Cell;
    iterator = nullptr;

    cout << "Please press:\n1 to create a database\n0 to quit\n";
    cin >> option;

    switch (option) {
    case 1: {
        cout << "Please enter name for your database:\n";
        cin >> name;
        cout << "How many columns is it going to have?\n";
        cin >> cat_number;
        List* list = new List;
        cout << "Please enter the names of the columns:\n";
        for (int i = 0; i < cat_number; i++) {
            cin >> cat_name;
            Category* new_cat = new Category;
            new_cat->init(nullptr, nullptr, nullptr, cat_name);
            list->add(new_cat);
        }
        database->init(name, list);

        iterator = database->categories->head;
        for (int i = 0; i < cat_number; i++) {
            
        }
        break;       
    }
    default:
        break;
    }
}