#ifndef QUEUEFACTORY_HPP
#define QUEUEFACTORY_HPP

#include "ArrayQueue.hpp"
#include "LinkedListQueue.hpp"

template <typename T>
class QueueFactory {
public:

    static Queue<T>* GetQueue() {
        return new LinkedListQueue<T>();
    }


    static Queue<T>* GetQueue(int size) {
        return new ArrayQueue<T>(size);
    }
};

#endif
