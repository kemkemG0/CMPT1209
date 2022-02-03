#include<iostream>
#include<assert.h>
#include"MySet.h"
#include<algorithm>
// This is only for test
#include<set>
MySet::MySet(){
    set = new int[10];
    size=0, bufferSize=10;
    assert(bufferSize>=size);
}


MySet::MySet(const int sequence[], int size){
    this->set = new int[10];
    this->size=0;
    this->bufferSize=10;
    add(sequence,size);
    assert(bufferSize>=this->size);
}


MySet::MySet(const MySet& anotherSet){
    bufferSize = anotherSet.bufferSize;
    size = anotherSet.size;
    assert(bufferSize>=size);
    set = new int[bufferSize];
    for(int i=0;i<size;++i) set[i]=anotherSet.set[i];
}


MySet::~MySet(){delete[] set;}


//O(N)
void MySet::allocateNewBuffer(int new_size){
    //allocate memory
    int* new_set = new int[new_size];
    int new_ind=0;
    for(int old_ind=0;old_ind<size;++old_ind,++new_ind)
        new_set[new_ind]=set[old_ind];
    delete[] set, set = new_set;
    bufferSize = new_size;
}


//O(N)
bool MySet::add(int item){
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
bool MySet::add(const int sequence[], int size){
    assert(bufferSize >= this->size);
    int all_size = size + this->size;
    auto all_seq = new int[all_size];
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
bool MySet::remove(int item){
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
bool MySet::has(int item) const{
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
MySet MySet::unionWith(const MySet& anotherSet) const{
    auto ret = MySet(anotherSet);
    ret.add(this->set, this->size);
    return ret;
}


//O( NlogN )
MySet MySet::intersectWith(const MySet& anotherSet) const{
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
void MySet::clear(){
    assert(bufferSize>=size);
    delete[] set;
    set = new int[10];
    size=0, bufferSize=10;
    return;
}


//O( 1 )
int MySet::getSize() const{return size;}


//O( N )
void MySet::print() const{
    assert(bufferSize>=size);   
    std::cout<<"{";
    for (int i = 0; i < size; i++) std::cout<< set[i]<<", ";
    std::cout<<"}"<<std::endl;
}

// This is only for test code
bool MySet::isSameSet(std::set<int>& checkSet)const{{
    std::set<int> realSet;
    for (int i = 0; i < size; i++) realSet.insert(set[i]);
    assert(realSet.size()==size);
    return realSet == checkSet;
}}