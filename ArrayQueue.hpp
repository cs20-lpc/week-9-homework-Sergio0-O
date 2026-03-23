#ifndef ARRAYQUEUE_HPP
#define ARRAYQUEUE_HPP

#include "Queue.hpp"
#include <string>

template <typename T>
class ArrayQueue : public Queue<T> {
private:
    T* buffer;
    int maxSize;
    int frontIndex;
    int backIndex;
    int length;

public:
    ArrayQueue(int size = 10) {
        maxSize = size;
        buffer = new T[maxSize];
        frontIndex = 0;
        backIndex = -1;
        length = 0;
    }

    ~ArrayQueue() {
        delete[] buffer;
    }

    void enqueue(const T& value) override {
        if (isFull()) return;

        backIndex = (backIndex + 1) % maxSize;
        buffer[backIndex] = value;
        length++;
    }

    void dequeue() override {
        if (isEmpty()) return;

        frontIndex = (frontIndex + 1) % maxSize;
        length--;
    }

    bool isEmpty() const override {
        return length == 0;
    }

    bool isFull() const override {
        return length == maxSize;
    }

    int size() const override {
        return length;
    }
};

#endif
