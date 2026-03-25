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

    void init_cell (Cell* p, Cell* n, Cell* c, string t) {
        prev = p;
        next = n;
        category = c;
        text = t;
    }

    void init_cat (Cell* p, Cell* n, Cell* c, string t) {
        prev = p;
        next = n;
        data = new Cell;
        data->head = nullptr;
        data->tail = nullptr;
        text = t;
    }

    void init_list (Cell* p, Cell* n, Cell* h, Cell* t) {
        prev = p;
        next = n;
        head = h;
        tail = t;
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
};

class Database {
    public:
    int record_count = 0;
    string name;
    Cell* categories;
    int cat_number = 0;
    Cell* records = nullptr;

    void init (string n) {
        name = n;
        records = new Cell;
    }

    void add_columns(){
        this->categories = new Cell;
        this->categories->init_list(nullptr, nullptr, nullptr, nullptr);

        int number;
        cout << "\nHow many columns would you like?\n";
        cin >> number;
        this->cat_number = number;

        Cell* it = new Cell;

        cout << "\nPlease enter the names of the columns:\n";
        for (int i = 0; i < number; i++) {
            string cat_name;
            cin >> cat_name;

            Cell* new_cat = new Cell;
            new_cat->init_cat(nullptr, nullptr, nullptr, cat_name);
            new_cat->if_category = true;

            this->categories->add(new_cat);
        }
    }

    void add_record(){
        Cell* record = new Cell;
        record->init_list(nullptr, nullptr, nullptr, nullptr);

        Cell* it = this->categories->head;

        for (int i = 0; i < this->cat_number; i ++) {
            Cell* new_cell = new Cell;

            cout << "Please enter " << it->text << ": "; 
            cin >> text;
            new_cell->init_cell(nullptr, nullptr, it, text);

            record->add(new_cell);
            it = it->next;
        }
        record->write();
        this->records->add(record);
        this->record_count += 1;
    }

    void show() {
        this->categories->write();
        cout << "\n-----------------------------------";
        Cell* it = this->records->head;
        while (it != nullptr) {
            cout << "\n";
            Cell* data = it->head;
            while (data != nullptr){
                cout << data->text << "   ";
                data = data->next;
            }
            it = it->next;
        }
    }
};

Database* database = new Database;

int main(int argc, char *argv[]) {

    while (option != 0) {
        cout << "\nPlease press:\n1 to create a database\n2 to add a record to database\n3 to show full database\n0 to quit\n";
        cin >> option;
        switch (option) {
        case 1: {
            cout << "\nPlease enter name for your database:\n";
            cin >> name;

            database->add_columns();

            cout << "\nAre those good column names? [y/n]\n";
            database->categories->write();
            cout << "\n";

            cin >> if_proceed;

            while (if_proceed != 'y') {
                if (if_proceed != 'n') {
                    cout << "\nPlease type \'y\' for yes and \'n\' for no.\n";
                    cin >> if_proceed;
                }
                else {
                    Cell* list = new Cell;
                    database->add_columns();

                    cout << "\nAre those good column names? [y/n]\n";
                    list->write();
                    cout << "\n";

                    cin >> if_proceed;
                }
            }
            database->init(name);
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