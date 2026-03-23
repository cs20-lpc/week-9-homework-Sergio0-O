#ifndef LINKEDLISTQUEUE_HPP
#define LINKEDLISTQUEUE_HPP

#include "Queue.hpp"

template <typename T>
class LinkedListQueue : public Queue<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    LinkedListQueue() {
        head = tail = nullptr;
        length = 0;
    }

    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& value) override {
        Node* n = new Node(value);

        if (isEmpty()) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }

        length++;
    }

    void dequeue() override {
        if (isEmpty()) return;

        Node* temp = head;
        head = head->next;
        delete temp;
        length--;

        if (head == nullptr) tail = nullptr;
    }

    bool isEmpty() const override {
        return length == 0;
    }

    bool isFull() const override {
        return false;
    }

    int size() const override {
        return length;
    }
};

#endif
