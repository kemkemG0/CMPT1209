#include<assert.h>

template <class T,size_t size = 100>
class PriorityQueue{
    private:
        T pq_list[size+10];
        size_t current_size;
    public:
        PriorityQueue();
        bool insert(T item);
        T remove();
        bool isEmpty();
        bool isFull();
        size_t getSize();
};


// O(1)
template <class T,size_t size>
PriorityQueue<T,size>:: PriorityQueue(){
// if dynamic
// auto pq_list = new T[size]
// this->sz = some value;
    current_size = 0;
    return;
}

// O(1)
template <class T,size_t size>
bool PriorityQueue<T,size>:: insert(T item){
    if(isFull())return false;
    pq_list[current_size]=item;
    ++current_size;
    return true;
}

// O(N)
template <class T,size_t size>
T PriorityQueue<T,size>:: remove(){
    if(isEmpty()) throw "PQ is empty!!";
    assert(current_size!=0);
    // remobe biggest one
    // T has to have operator <
    size_t mx_ind = 0;
    T mx_T=pq_list[0];
    
    for(int i=0;i<current_size;++i){
        if(mx_T<pq_list[i]){
            mx_T = pq_list[i];
            mx_ind = i;
        }
    }
    assert(current_size-1 >=0 );
    std::swap(pq_list[mx_ind],pq_list[current_size-1]);
    --current_size;
    return mx_T;
}

// O(1)
template <class T,size_t size>
bool PriorityQueue<T,size>:: isEmpty(){return current_size==0;}

// O(1)
template <class T,size_t size>
bool PriorityQueue<T,size>:: isFull(){return current_size == size;}

// O(1)
template <class T,size_t size>
size_t PriorityQueue<T,size>:: getSize(){return current_size;}


