#include <iostream>
#include <cstdlib>
using namespace std;

struct Item {
    int number;
    Item* next;
    Item* prev;
};

class DoubleList {
    int junk;
    Item* begin;
    Item* end;
public:
    DoubleList() : begin(nullptr),end(nullptr), junk(888) {};
    void push_front(int number) {
        if (begin == nullptr) {  // for the 1st element
            begin = new Item;
            end=begin;
            begin->next = nullptr;
            begin->prev = nullptr;
        } else { // for following elements
            begin->prev = new Item;
            begin->prev->prev = nullptr;
            begin->prev->next = begin;
            begin = begin->prev;
        }
        begin->number = number;
    }
    int& operator[](size_t index) {
        Item* iterator = begin;

        if (!iterator)
            return junk;

        for (size_t i = 0; i < index; ++i) {
            if (iterator->next != nullptr) {
                iterator = iterator->next;
            } else {
                cerr << " ERROR\n";
                return junk;
            }
        }
        return iterator->number;
    }
};

int main() {
    DoubleList list;
    cout << list[1]<<endl;
    for (int i = 0; i < 10; i++) {
        list.push_front(i);
    }
    cout<<list[]<<endl;
    return 0;
}
