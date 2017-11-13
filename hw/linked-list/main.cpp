/*
 * Modify this and create a doubly linked list
 * Also, create two more methods:
 * - traverseBackwards(): traverse the list backwards using the prev pointer
 * - insertAtEnd(): insert value at end of tail
 */

#include <iostream>
#include <cassert>

using namespace std;

class Node {
public:
    friend class LinkedList;
    Node(int value) : value(value), next(nullptr) {}
    Node(int value, Node* next) : value(value), next(next) {}

    int value;
private:
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList() {
        while (!isEmpty()) {
            remove();
        }
    }

    void traverse() {
        Node* it = head;
        while (it != nullptr) {
            std::cout << it->value << " ";
            it = it->next;
        }
        std::cout << std::endl;
    }

    void insert(int data) {
        Node* prevHead = head;
        head = new Node(data);
        head->next = prevHead;
        size++;
    }

    void remove() {
        assert(head != nullptr);

        Node* finalHead = head->next;
        delete head;
        head = finalHead;
        size--;
    }

    void removeAt(int index) {
        assert(index < size);

        if (index == 0) {
            remove();
            return;
        }

        int counter = 0; 
        Node* it = head;
        while (counter < index - 1) {
            it = it->next;
            counter++;
        }

        Node* temp = it->next->next;
        delete it->next;
        it->next = temp;
        size--;
    }

    int get(int index) {
        assert(!isEmpty());
        assert(index >= 0 && index < size);

        int counter = 0;
        Node* it = head;
        while (counter < index) {
            it = it->next;
            counter++;
        }

        return it->value;
    }

    bool isEmpty() {
        return size == 0;
    }

private:
    Node* head;
    int size;
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(5);
    list.insert(8);
    list.insert(13);
    list.traverse();
    list.remove();
    list.traverse();
    list.removeAt(2);
    list.traverse();
    list.removeAt(0);
    list.traverse();
    list.removeAt(2);
    list.traverse();

    // Output:
    // 13 8 5 3 2 1
    // 8 5 3 2 1
    // 8 5 2 1
    // 5 2 1
    // 5 2
    
    list.insertAtEnd(10);
    list.insertAtEnd(11);
    list.insertAtEnd(12);
    list.traverse();
    list.traverseBackwards();

    // Output:
    // 5 2 10 11 12
    // 12 11 10 2 5

    return 0;
}
