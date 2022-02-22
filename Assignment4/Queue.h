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
    
    Queue<T,capacity>& operator =(const Queue<T,capacity>& r_val);
    Queue<T,capacity>& operator +(const Queue<T,capacity>& r_val);
    void operator +=(const Queue<T,capacity>& r_val);
    void operator -=(const Queue<T,capacity>& r_val);
    bool operator ==(const Queue<T,capacity>& r_val) const;
    bool operator !=(const Queue<T,capacity>& r_val) const;


private:
	T* q; // q points to the front of the queue in the heap
	int size; // size is the number of items in the queue
	int maxSize; // maxSize is the maximum size of the array pointed by q.
};


template<typename T,int capacity>
Queue<T,capacity>::Queue(){
    size = 0;
    maxSize = capacity;
    q = new T[maxSize];
}


template<typename T,int capacity>
void Queue<T,capacity>::insert(const T& x){
    
}


template<typename T,int capacity>
T Queue<T,capacity>::remove(){

}


template<typename T,int capacity>
bool Queue<T,capacity>::empty() const{return size==0;}


template<typename T,int capacity>
int Queue<T,capacity>::getSize() const{return size;}


template<typename T,int capacity>
Queue<T,capacity>& Queue<T,capacity>::operator =(const Queue<T,capacity>& r_val){
    
}

template<typename T,int capacity>
Queue<T,capacity>& Queue<T,capacity>::operator +(const Queue<T,capacity>& r_val){
    
}

template<typename T,int capacity>
void Queue<T,capacity>::operator +=(const Queue<T,capacity>& r_val){
    
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


#endif