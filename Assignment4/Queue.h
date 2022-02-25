#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<assert.h>
#include<queue>

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
    Queue<T,capacity>& operator --();
    bool operator ==(const Queue<T,capacity>& r_val) const;
    bool operator !=(const Queue<T,capacity>& r_val) const;

    template <typename U, int capacityU>
    friend std::ostream& operator << (std::ostream& os, const Queue<U,capacityU>& outputQ);


    //for debug and test
    bool isSame(std::queue<T>& real_q);

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
    size = head = tail = 0;
    maxSize = capacity;
    q = new T[maxSize];
}


template<typename T,int capacity>
Queue<T,capacity>::Queue(const Queue<T,capacity>& another_q){
    this->operator=(another_q);
}


template<typename T,int capacity>
void Queue<T,capacity>::insert(const T& x){
    if(isFull()){
        // std::cout<<maxSize<<" will be doubled.\n";
        // std::cout<<"head: "<<head<<" ,tail: "<<tail<<std::endl;
        //expand
        auto new_maxSize = maxSize * 2;
        auto new_q = new T[new_maxSize];
        //copy to the new_q
        auto count = getSize();
        size_t new_q_ind=0,old_q_ind=head;
        while((old_q_ind) != tail){
            new_q[new_q_ind] = q[old_q_ind];
            old_q_ind = (old_q_ind+1) % (maxSize);
            ++new_q_ind;
        }
        delete[] q;
        q = new_q;
        maxSize = new_maxSize;
        // q should be straitforward, from 0 to (tail-1)
        head=0, tail = size;
    }
    assert(!isFull());
    // push new element
    
    this->q[tail]=x;
    
    ++tail , ++size, tail%=maxSize;
    assert(tail<=maxSize);
}


template<typename T,int capacity>
T Queue<T,capacity>::remove(){
    if(empty()) throw "queue is empty";
    assert(head < maxSize);
    auto ret = q[head];
    head = (head+1) % maxSize;
    --size;
    return ret;
}


template<typename T,int capacity>
bool Queue<T,capacity>::isFull() const{ 
    assert( ((tail+1)%maxSize == head) == (size==maxSize-1));
    return (tail+1)%maxSize == head;
}

template<typename T,int capacity>
bool Queue<T,capacity>::empty() const{return size==0;}


template<typename T,int capacity>
int Queue<T,capacity>::getSize() const{
    assert(size>=0);
    return size;
}


template<typename T,int capacity>
Queue<T,capacity>& Queue<T,capacity>::operator =(const Queue<T,capacity>& r_val){
    //copy another_q to this
    delete[] q;
    q = new T[r_val.maxSize];

    for(int i=0;i<r_val.maxSize;++i)
        q[i] = r_val.q[i];
    size = r_val.size;
    maxSize = r_val.maxSize;
    head = r_val.head;
    tail = r_val.tail;
    return *this;
}

template<typename T,int capacity>
Queue<T,capacity>& Queue<T,capacity>::operator +(const Queue<T,capacity>& r_val){
    auto new_queue = new Queue<T,capacity>;
    (*new_queue).operator=(*this);
    for(int i=0;i<r_val.getSize();++i) *new_queue+=r_val.q[i];
    return *new_queue;
}

template<typename T,int capacity>
void Queue<T,capacity>::operator +=(const T& item){
    this->insert(item);
}

template<typename T,int capacity>
Queue<T,capacity>& Queue<T,capacity>::operator --(){
    this->remove();
    return *this;
}

template<typename T,int capacity>
bool Queue<T,capacity>::operator ==(const Queue<T,capacity>& r_val) const{
    if(this->getSize()!=r_val.getSize()) return false;

    for(int i=0;i<this->getSize();++i)
        if(this->q[i] != r_val.q[i]) return false;

    return true;
}


template<typename T,int capacity>
bool Queue<T,capacity>::operator !=(const Queue<T,capacity>& r_val) const{
    return ! operator==(r_val);
}

template<typename T,int capacity>
std::ostream& operator <<(std::ostream& os, const Queue<T,capacity>& outputQ) {
    using namespace std;
    for(int i=0;i<outputQ.size;++i)
        cout << outputQ.q[(outputQ.head+i)%outputQ.maxSize] << " ";
    os << "\n";
    return os;
}


template<typename T,int capacity>
bool Queue<T,capacity>::isSame(std::queue<T>& real_q){
    if(real_q.size()!=this->getSize()){
        std::cout<<"size differ"<<std::endl;
        return false;
    }
    int ind=head;
    auto cp_q = real_q;
    while(!cp_q.empty()){
        auto e = cp_q.front(); cp_q.pop();
        if(e!=q[ind]) return false;
        ++ind,ind%=maxSize;
    }
    return true;
}



#endif