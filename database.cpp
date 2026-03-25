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
string text;

class Cell {
    public:
    int id;
    bool if_category = false;
    bool if_list = false;

    Cell* prev = nullptr;
    Cell* next = nullptr;

    Cell* head = nullptr;
    Cell* tail = nullptr;
    
    Cell* category;
    string text;

    Cell* data;

    void init (Cell* p, Cell* n, Cell* c, string t) {
        prev = p;
        next = n;
        category = c;
        text = t;
    }

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

    void write() {
        Cell* it = this->head;
        while (it != nullptr) {
            cout << it->text << "   ";
            it = it->next;
        }
    }

    void fill_up(int number) {
        for (int i = 0; i < number; i++) {
            cin >> name;
            Cell* new_cat = new Cell;
            new_cat->init(nullptr, nullptr, nullptr, name);
            new_cat->data = new Cell;
            new_cat->if_category = true;
            this->add(new_cat);
        }
    }
};

class Database {
    public:
    int record_count = 0;
    string name;
    Cell* categories = nullptr;
    int cat_number = 0;
    Cell* records = nullptr;

    void init (string n, Cell* c, int cn) {
        name = n;
        categories = c;
        cat_number = cn;
        records = new Cell;
    }

    void add_record(){
        Cell* record = new Cell;
        Cell* it = this->categories->head;
        for (int i = 0; i < this->cat_number; i ++) {
            Cell* new_cell = new Cell;
            cout << "Please enter " << it->text << ": "; 
            cin >> text;
            new_cell->init(nullptr, nullptr, it, text);
            record->add(new_cell);
            it->data->add(new_cell);
            it = it->next;
        }
        record->write();
        this->records->add(record);
        this->record_count += 1;
    }

    void add_r(int n){ 
        Cell* record = new Cell;
        Cell* id = new Cell;
        id->init(nullptr,nullptr, nullptr, to_string(n));
        record->add(id);
        this->records->add(record);
        Cell* iterator = this->categories->head;
        for (int i = 0; i < this->cat_number; i ++) {
            Cell* new_cell = new Cell;
            cout << "Please enter " << iterator->text << ": "; 
            cin >> text;
            new_cell->init(nullptr, nullptr, iterator, text);
            record->add(new_cell);
            iterator->data->add(new_cell);
            iterator = iterator->next;
        }
        record->write();
        this->record_count += 1;
    }

    void show() {
        this->categories->write();
        Cell* iterator = this->records->head;
        while (iterator != nullptr) {
            cout << "\n";
            iterator->write();
            iterator = iterator->next;
        }
    }
};

Database* database = new Database;

int main(int argc, char *argv[]) {
    Cell* iterator = new Cell;
    iterator = nullptr;

    while (option != 0) {
        cout << "\nPlease press:\n1 to create a database\n2 to add a record to database\n3 to show full database\n0 to quit\n";
        cin >> option;
        switch (option) {
        case 1: {
            cout << "\nPlease enter name for your database:\n";
            cin >> name;

            cout << "\nHow many columns is it going to have?\n";
            cin >> cat_number;

            Cell* list = new Cell;
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
            if (database->categories == nullptr) {
                cout << "\nThere are no database yet. Please choose 1 to create it.\n";
                break;
            }
            else {
                cout << "Adding record no. " << database->record_count + 1 << "\n";
                database->add_record();
                break;
            }
        }
        case 3: {
            if (database->categories == nullptr) {
                cout << "\nThere are no database yet. Please choose 1 to create it.\n";
                break;
            }
            else if(database->records->head == nullptr){
                cout << "\nYour database is empty. Please choose 2 to add a record.\n";
                break;
            }
            else {
                database->show();
            }
        }
        default:
            break;
        }
    }
}