#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QueueFactory.hpp"

using namespace std;

int main() {
    srand(time(0));

    // ===== Simulation 1 (Array Queue - max 10) =====
    cout << "Simulation 1 (Ticket Line)\n";
    Queue<int>* q1 = QueueFactory<int>::GetQueue(10);

    for (int i = 0; i < 100; i++) {
        int r = rand() % 3 - 1;  // -1 to 1

        if (r < 0) {
            q1->dequeue();
        } else {
            q1->enqueue(1);
        }

        cout << "Size: " << q1->size() << endl;
    }

    delete q1;


    // ===== Simulation 2 (Linked List Queue) =====
    cout << "\nSimulation 2 (Bank Line)\n";
    Queue<int>* q2 = QueueFactory<int>::GetQueue();

    for (int i = 0; i < 100; i++) {
        int r = rand() % 4 - 1;  // -1 to 2

        if (r < 0) {
            q2->dequeue();
        } else {
            q2->enqueue(1);
        }

        cout << "Size: " << q2->size() << endl;
    }

    delete q2;

    return 0;
}
