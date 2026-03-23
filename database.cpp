#include <iostream>
#include <string>

using namespace std;

class Category;
class List;

string name;
string cat_name;
int option = -1;
int cat_number;
char if_proceed;

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

    void add_record(Database* db){
        Cell* iterator = new Cell;
        iterator = db->categories->head;
        for (int i = 0; i < db->cat_number; i ++) {
            //ID
            Cell* id = new Cell;
            id->init(nullptr,nullptr, nullptr, to_string(i + 1));
            //po kolei kategorie + odnośniki do kategorii + do listy kategorii ( <-> )
        }
    }

    void fill_up(int number) {
        for (int i = 0; i < number; i++) {
            cin >> name;
            Category* new_cat = new Category;
            new_cat->init(nullptr, nullptr, nullptr, name);
            this->add(new_cat);
        }
    }
};

class Database {
    public:
    int record_count = 0;
    string name;
    List* categories = nullptr;
    int cat_number = 0;
    List* records = nullptr;

    void init (string n, List* c, int cn) {
        name = n;
        categories = c;
        cat_number = cn;
    }
};

Database* database = new Database;

int main(int argc, char *argv[]) {
    Cell* iterator = new Cell;
    iterator = nullptr;

    while (option != 0) {
        cout << "Please press:\n1 to create a database\n2 to add a record to database\n0 to quit\n";
        cin >> option;
        switch (option) {
        case 1: {
            cout << "\nPlease enter name for your database:\n";
            cin >> name;

            cout << "\nHow many columns is it going to have?\n";
            cin >> cat_number;

            List* list = new List;
            cout << "\nPlease enter the names of the columns:\n";
            list->fill_up(cat_number);

            cout << "\nWAre those good categories? [y/n]\n";
            iterator = list->head;
            for (int i = 0; i < cat_number; i++) {
                cout << iterator->text << " ";
                iterator = iterator->next;
            }
            cin >> if_proceed;
            switch (if_proceed)
            {
            case 'y': {
                database->init(name, list, cat_number);
                break;
            }
            case 'n': {
                //RESET CATEGORIES
                break;
            }
            default:
                break;
            }
            break;       
        }
        case 2: {
            if (database->categories = nullptr) {
                cout << "\nThere are no database yet. Please choose 1 to create it.\n";
                break;
            }
            else {
                cout << "Adding record no. " << database->record_count + 1 << "\n";
                break;
            }
        }
        default:
            break;
        }
    }
}