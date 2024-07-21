#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};

template <typename T>
class List {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int size = 0;

public:
    void show() {
        Node<T>* iterator = head;
        for (int i = 0; i < size; i++) {
            cout << iterator->data << " ";
            iterator = iterator->next;
        }
    }

    void push_front(T data) {
        Node<T>* newNode = new Node<T>{ data, head };
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr)
            tail = newNode;
        size++;
    }

    void push_back(T data) {
        Node<T>* newNode = new Node<T>{ data, nullptr, tail };
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr)
            head = newNode;
        size++;

    }

    void insert(T data, int index) {
        if (index<0 || index>size) return;
        if (index == 0) {
            push_front(data);
            return;
        }
        if (index == size) {
            push_back(data);
            return;
        }
        if (size / 2 > index) {
            Node<T>* iterator = head;
            for (int i = 0; i < index - 1; i++) {
                iterator = iterator->next;
            }

            Node<T>* newNode = new Node<T>{ data, iterator->next, iterator };
            if (iterator->next != nullptr) {
                iterator->next->prev = newNode;
            }
            iterator->next = newNode;
        }
        else {
            Node<T>* iterator = tail;
            for (int i = size; i > index + 1; i--) {
                iterator = iterator->prev;
            }

            Node<T>* newNode = new Node<T>{ data, iterator, iterator->prev };
            if (iterator->prev != nullptr) {
                iterator->prev->next = newNode;
            }
            iterator->prev = newNode;

        }




        size++;

    }

    void remove(T data) {
        Node<T>* iterator = head;
        while (iterator != nullptr) {
            if (iterator->data == data) {
                if (iterator->prev != nullptr) {
                    iterator->prev->next = iterator->next;
                }
                else {
                    head = iterator->next;
                }
                if (iterator->next != nullptr) {
                    iterator->next->prev = iterator->prev;
                }
                else {
                    tail = iterator->prev;
                }
                delete iterator;
                size--;
                return;
            }
            iterator = iterator->next;
        }
    }

    void erase(int index) {
        if (index < 0 || index >= size) return;
        Node<T>* iterator;
        if (index == 0) {
            iterator = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
        }
        else if (index == size - 1) {
            iterator = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
        }
        else {
            if (index <= size / 2) {
                iterator = head;
                for (int i = 0; i < index; ++i) {
                    iterator = iterator->next;
                }
            }
            else {
                iterator = tail;
                for (int i = size - 1; i > index; --i) {
                    iterator = iterator->prev;
                }
            }
            iterator->prev->next = iterator->next;
            iterator->next->prev = iterator->prev;
            delete iterator;
        }
        size--;
    }

};

int main()
{
    List<int> lst;
    lst.push_front(4);
    lst.push_front(7);
    lst.push_front(9);
    lst.push_front(1);
    lst.push_back(6);
    lst.insert(5, 4);
    lst.show(); 
    lst.remove(7);
    lst.show(); 
    lst.erase(2);
    lst.show(); 

    return 0;
}
