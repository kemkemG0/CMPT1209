#include<iostream>
#include<assert.h>
#include<algorithm>
// This is only for test
#include <set>

template<typename T>
class MySet {
public:
	MySet();
	MySet(const T sequence[], int size);
	MySet(const MySet& anotherSet);
	~MySet();
	bool add(T item);
	bool add(const T sequence[], int size);
	bool remove(T item);
	bool has(T item) const;
	MySet unionWith(const MySet& anotherSet) const;
	MySet intersectWith(const MySet& anotherSet) const;
	void clear();
	int getSize() const;
	void print() const;
    //for debug and test
    bool isSameSet(std::set<T>& checkSet)const;
private:
	T* set;
	int size;
	int bufferSize;
    void allocateNewBuffer(int size);
    
    
};


template<typename T>
MySet<T>::MySet(){
    set = new T[10];
    size=0, bufferSize=10;
    assert(bufferSize>=size);
}

template<typename T>
MySet<T>::MySet(const T sequence[], int size){
    this->set = new T[10];
    this->size=0;
    this->bufferSize=10;
    add(sequence,size);
    assert(bufferSize>=this->size);
}

template<typename T>
MySet<T>::MySet(const MySet& anotherSet){
    bufferSize = anotherSet.bufferSize;
    size = anotherSet.size;
    assert(bufferSize>=size);
    set = new T[bufferSize];
    for(int i=0;i<size;++i) set[i]=anotherSet.set[i];
}


template<typename T>
MySet<T>::~MySet(){delete[] set;}


//O(N)
template<typename T>
void MySet<T>::allocateNewBuffer(int new_size){
    //allocate memory
    T* new_set = new T[new_size];
    int new_ind=0;
    for(int old_ind=0;old_ind<size;++old_ind,++new_ind)
        new_set[new_ind]=set[old_ind];
    delete[] set, set = new_set;
    bufferSize = new_size;
}


//O(N)
template<typename T>
bool MySet<T>::add(T item){
    //After added, the set should be sorted;
    assert(bufferSize>=size);
    if(size==0){
        set[0]=item, ++size;
        return true;
    }
    if(has(item))return false;
    if(bufferSize==size) allocateNewBuffer(bufferSize+bufferSize/2);

    //add to the tail
    assert(size-1>=0);
    if(set[size-1]<item){
        set[size]=item, ++size;
        return true;
    }
    //insert to middle
    //binary search
    int ok = size-1, ng = -1;
    assert(item<set[ok]);
    while(ok-ng>1){
        int mid = (ok+ng)/2; assert(mid>=0);
        if(set[mid]>item)ok=mid;
        else ng = mid;
        assert(item<set[ok]);
    }
    assert(ok-1 < 0 || item > set[ok-1]);
    /*
        Shift to right
            a, b, ok, c, d
    =>      a, b, new,ok,c,d
        set[size-1]=>set[size], set[ok]=>set[ok+1];
    */
    //Shift to right
    for(int i=size-1;i>=ok;--i) set[i+1] = set[i];
    set[ok]=item, ++size;
    return true;
}


//O( Nlog(N))
template<typename T>
bool MySet<T>::add(const T sequence[], int size){
    assert(bufferSize >= this->size);
    int all_size = size + this->size;
    auto all_seq = new T[all_size];
    for(int i=0; i<size; ++i) all_seq[i] = sequence[i];
    for(int i=0; i<this->size; ++i) all_seq[i+size] = set[i];
    std::sort(all_seq, all_seq + all_size);//O(NlogN) // might have same items
    // allocate buffer if needed
    if(all_size > bufferSize) allocateNewBuffer(all_size);
    int cnt=0;
    for(int i=0;i<all_size;++i){//O(N)
        assert(bufferSize>=this->size);
        cnt+=add(all_seq[i]);
    }
    delete[] all_seq;
    std::sort(set, set+ this->size);//O(NlogN)
    return cnt > 0;
}


//O(N)
template<typename T>
bool MySet<T>::remove(T item){
    if(!has(item))return false;
    int ok = size-1, ng = -1;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        if(set[mid]>=item)ok=mid;
        else ng=mid;
    }
    //remove set[ok]
    assert(set[ok]==item);
    // left shift
    for(int i=ok;i<size-1;++i) set[i] = set[i+1];
    --size;
    return true;
}


//O(logN)
template<typename T>
bool MySet<T>::has(T item) const{
    assert(bufferSize>=size);
    if(size==0 || set[size-1]<item)return false;
    bool ret = false;
    // set[ok]>=item is always true
    int ok=size-1, ng = -1;
    assert(set[ok]>=item);
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        if(set[mid]>=item)ok=mid;
        else ng = mid;
        assert(set[ok]>=item);
    }
    return set[ok]==item;
}


//O(N)
template<typename T>
MySet<T> MySet<T>::unionWith(const MySet& anotherSet) const{
    auto ret = MySet(anotherSet);
    ret.add(this->set, this->size);
    return ret;
}


//O( NlogN )
template<typename T>
MySet<T> MySet<T>::intersectWith(const MySet& anotherSet) const{
    assert(bufferSize>=size);
    auto ano_set = anotherSet.set;
    auto ano_size = anotherSet.size;
    auto ret = MySet();
    for (int i = 0; i < ano_size; i++){
        if(!has(ano_set[i]))continue;//O(logN)
        ret.add(ano_set[i]);// O(1) cuz ano_set is ascending order
    }
    return ret;
}


//O( 1 )
template<typename T>
void MySet<T>::clear(){
    assert(bufferSize>=size);
    delete[] set;
    set = new T[10];
    size=0, bufferSize=10;
    return;
}


//O( 1 )
template<typename T>
int MySet<T>::getSize() const{return size;}


//O( N )
template<typename T>
void MySet<T>::print() const{
    assert(bufferSize>=size);
    std::cout<<"{";
    for (int i = 0; i < size; i++) std::cout<< set[i]<<", ";
    std::cout<<"}"<<std::endl;
}

// This is only for test code
template<typename T>
bool MySet<T>::isSameSet(std::set<T>& checkSet)const{{
    std::set<T> realSet;
    for (int i = 0; i < size; i++) realSet.insert(set[i]);
    assert(realSet.size()==size);
    return realSet == checkSet;
}}