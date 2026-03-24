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
    bool if_category = false;
    int id;
    Cell* prev = nullptr;
    Cell* next = nullptr;
    Cell* category;
    string text;
    List* data_if_cat = nullptr;

    void init (Cell* p, Cell* n, Cell* c, string t) {
        prev = p;
        next = n;
        category = c;
        text = t;
    }
};

class List {
    public:
    Cell* head = nullptr;
    Cell* tail = nullptr;
    List* prev;
    List* next;

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
        Cell* iterator = this->head;
        if (iterator->if_category == false) {
            iterator = iterator->next;
        }
        while (iterator != nullptr) {
            cout << iterator->text << "   ";
            iterator = iterator->next;
        }
    }

    void fill_up(int number) {
        for (int i = 0; i < number; i++) {
            cin >> name;
            Cell* new_cat = new Cell;
            new_cat->init(nullptr, nullptr, nullptr, name);
            new_cat->data_if_cat = new List;
            new_cat->if_category = true;
            this->add(new_cat);
        }
    }
};

class List_id {
    public:
    List* head = nullptr;
    List* tail = nullptr;

    void add (List* new_cell) {
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
    int record_count = 0;
    string name;
    List* categories = nullptr;
    int cat_number = 0;
    List_id* records = nullptr;

    void init (string n, List* c, int cn) {
        name = n;
        categories = c;
        cat_number = cn;
        records = new List_id;
    }

    void add_record(int n){
        List* record = new List;
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
            iterator->data_if_cat->add(new_cell);
            iterator = iterator->next;
        }
        this->record_count += 1;
    }

    void show() {
        this->categories->write();
        List* iterator = this->records->head;
        while (iterator != nullptr) {
            //cout << "Record no. " << iterator->head->text << ": ";
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
            if (database->categories == nullptr) {
                cout << "\nThere are no database yet. Please choose 1 to create it.\n";
                break;
            }
            else {
                cout << "Adding record no. " << database->record_count + 1 << "\n";
                database->add_record(database->record_count + 1);
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
                break;
            }
        }
        default:
            break;
        }
    }
}