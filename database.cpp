#include <iostream>
#include <string>

using namespace std;

class cell {
    public:
    int id;
    cell* prev;
    cell* next;
    string text;
};

class list {
    public:
    cell* head;
    cell* tail;
};

void add (list* dest, cell* new_cell) {
    if (dest->head == nullptr) {
        dest->head = new_cell;
        dest->tail = new_cell;
    }
    dest->tail->next = new_cell;
    new_cell->prev = dest->tail;
    new_cell->next = nullptr;
    dest->tail = new_cell;
}

class database {
    cell* head;

};

int main(int argc, char *argv[]) {
    list* lista = new list;
    lista->head = nullptr;
    lista->tail = nullptr;
    for (int i = 0; i < 4; i++) {
        cell* newcell = new cell;
        newcell->id = i;
        add(lista, newcell);
    }

    cell* it = lista->head;
    for (int i = 0; i < 4; i++) {
        cout << it->id << "\n";
        it = it->next;
    }
}