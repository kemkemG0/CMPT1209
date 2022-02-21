#ifndef QUEUE_H
#define QUEUE_H

template <typename T, int capacity> // T is the generic type used for the items in the queue and capacity is the initial size of the queue
class Queue {
public:
	Queue(); // Creates an empty Queue object with the maximum size of "capacity"

	void insert(const T& x); // Inserts x at the end of the queue; if required the queue is expanded (doubled)
	T remove(); // Removes and returns the first item of the queue (i.e. item at index 0), or throws an exception if the queue is empty,
	bool empty() const; // Returns true if the queue is empty, or false otherwise.
	int getSize() const; // Returns the number of items in the queue.
    
private:
	T* q; // q points to the front of the queue in the heap
	int size; // size is the number of items in the queue
	int maxSize; // maxSize is the maximum size of the array pointed by q.
};

#endif