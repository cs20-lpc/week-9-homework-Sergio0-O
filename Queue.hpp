#ifndef QUEUE_HPP
#define QUEUE_HPP

using namespace std;

template <typename T>
class Queue {
public:
    virtual ~Queue() {}
    virtual void enqueue(const T&) = 0;
    virtual void dequeue() = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int size() const = 0;
};

#endif
