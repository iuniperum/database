#include <iostream>
#include <string>

using namespace std;

class Cell {
    public:
    int id;
    Cell* prev;
    Cell* next;
    Category* category;
    string text;
};

class Category: public Cell {
    public:
    List* data;
};

class List {
    public:
    Cell* head;
    Cell* tail;
};

void add (List* dest, Cell* new_cell) {
    if (dest->head == nullptr) {
        dest->head = new_cell;
        dest->tail = new_cell;
    }
    dest->tail->next = new_cell;
    new_cell->prev = dest->tail;
    new_cell->next = nullptr;
    dest->tail = new_cell;
}

void find(List* dest, int number) {
    Cell* it = dest->head;
    while (it != nullptr) {

    }
}

class database {
    string name;
    Cell* head;
    //dictionary: number of column->category?
};

int main(int argc, char *argv[]) {
    List* lista = new List;
    lista->head = nullptr;
    lista->tail = nullptr;
    for (int i = 0; i < 10; i++) {
        Cell* newcell = new Cell;
        newcell->id = i;
        add(lista, newcell);
    }

    Cell* it = lista->head;
    for (int i = 0; i < 10; i++) {
        cout << it->id << "\n";
        it = it->next;
    }
}