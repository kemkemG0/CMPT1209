#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<assert.h>

template <typename T, int capacity> // T is the generic type used for the items in the queue and capacity is the initial size of the queue
class Queue {
public:
	Queue(); // Creates an empty Queue object with the maximum size of "capacity"
	Queue(const Queue<T,capacity>& another_q); // copy constructor

	void insert(const T& x); // Inserts x at the end of the queue; if required the queue is expanded (doubled)
	T remove(); // Removes and returns the first item of the queue (i.e. item at index 0), or throws an exception if the queue is empty,
	bool empty() const; // Returns true if the queue is empty, or false otherwise.
	int getSize() const; // Returns the number of items in the queue.
    
    Queue<T,capacity>& operator =(const Queue<T,capacity>& r_val);
    Queue<T,capacity>& operator +(const Queue<T,capacity>& r_val);
    void operator +=(const T& item);
    void operator -=(const Queue<T,capacity>& r_val);
    bool operator ==(const Queue<T,capacity>& r_val) const;
    bool operator !=(const Queue<T,capacity>& r_val) const;

    friend std::ostream& operator << (std::ostream& os, const Queue<T,capacity>& outputQ);



private:
	T* q; // q points to the front of the queue in the heap
	int size; // size is the number of items in the queue
	int maxSize; // maxSize is the maximum size of the array pointed by q.
    
    size_t head; // first element's index
    size_t tail; // last element's index + 1
    bool isFull() const;
};


template<typename T,int capacity>
Queue<T,capacity>::Queue(){
    size = head =  0, tail =1;
    maxSize = capacity;
    q = new T[maxSize];
}


template<typename T,int capacity>
Queue<T,capacity>::Queue(const Queue<T,capacity>& another_q){
    this->operator=(another_q);
}


template<typename T,int capacity>
void Queue<T,capacity>::insert(const T& x){
    
}


template<typename T,int capacity>
T Queue<T,capacity>::remove(){
    if(empty()) throw "queue is empty";
    assert(head < maxSize);
    T ret = q[head];
    head = (head+1) % maxSize;
    --size;
    return ret;
}


template<typename T,int capacity>
bool Queue<T,capacity>::isFull() const{ 
    return (head==0 && tail==maxSize) || abs(int(head)-int(tail))==1; 
}

template<typename T,int capacity>
bool Queue<T,capacity>::empty() const{return size==0;}


template<typename T,int capacity>
int Queue<T,capacity>::getSize() const{return size;}


template<typename T,int capacity>
Queue<T,capacity>& Queue<T,capacity>::operator =(const Queue<T,capacity>& r_val){
    //copy another_q to this
    delete[] this->q;
    this->q = new T[r_val.maxSize];

    for(int i=0;i<r_val.maxSize;++i)
        this->q[i] = r_val[i];
    this->size = r_val.size;
    this->maxSize = r_val.maxSize;
    this->head = r_val.head;
    this->tail = r_val.tail;
    return *this;
}

template<typename T,int capacity>
Queue<T,capacity>& Queue<T,capacity>::operator +(const Queue<T,capacity>& r_val){
    
}

template<typename T,int capacity>
void Queue<T,capacity>::operator +=(const T& item){
    this->insert(item);
}

template<typename T,int capacity>
void Queue<T,capacity>::operator -=(const Queue<T,capacity>& r_val){
    
}

template<typename T,int capacity>
bool Queue<T,capacity>::operator ==(const Queue<T,capacity>& r_val) const{
    
}

template<typename T,int capacity>
bool Queue<T,capacity>::operator !=(const Queue<T,capacity>& r_val) const{
    return ! this->operator==(r_val);
}

template<typename T,int capacity>
std::ostream& operator <<(std::ostream& os, const Queue<T,capacity>& outputQ) {
    for(int i=0;i<outputQ.size;++i)
        os << outputQ.q[i] << " ";
    os << "\n";
    return os;
}

#endif