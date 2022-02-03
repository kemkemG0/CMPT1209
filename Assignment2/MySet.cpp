#include<iostream>
#include<assert.h>
#include"MySet.h"
#include<algorithm>

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
    set = new int[size];
    for(int i=0;i<size;++i) set [i]=anotherSet.set[i];
}


MySet::~MySet(){delete[] set;}


//O(N)
void MySet::allocateNewBuffer(int new_size){
    //allocate memory
    int* new_set = new int[new_size];
    int new_ind=0;
    for(int old_ind=0;old_ind<size;++old_ind,++new_ind){
        new_set[new_ind]=set[old_ind];
    }
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
        int mid = (ok+ng)/2;
        assert(mid>=0);
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
    set[ok]=item;
    ++size;
    return true;
}


//O( Nlog(N))
bool MySet::add(const int sequence[], int size){
    assert(bufferSize>=this->size);
    auto copy_seq = new int[size];
    for(int i=0;i<size;++i) copy_seq[i] = sequence[i];
    std::sort(copy_seq,copy_seq+size);//O(NlogN)
    bool ret=false;
    // allocate buffer if needed
    if((this->size + size) > bufferSize) allocateNewBuffer(this->size + size);
    // a,b,b,c,d,e,e,f,g
    for(int i=0;i<size;++i){//O(N)
        if(i-1>=0 && copy_seq[i]==copy_seq[i-1])continue;
        if(has(copy_seq[i]))continue;//O(logN)
        /*This is not sorted yet*/
        set[this->size]=copy_seq[i];
        (this->size)++;
        ret=true;
    }
    std::sort(set,set+this->size);//O(NlogN)
    return ret;
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
    auto ano_set = anotherSet.set;
    auto ano_size = anotherSet.size;
    int self_ind=0, ano_ind=0;
    auto ret = MySet();
    while(ano_ind<ano_size || self_ind<size){//O(N)
        if(self_ind>=size)ret.add(ano_set[ano_ind]),++ano_ind;//O(1)
        else if(ano_ind>=ano_size)ret.add(set[self_ind]),++self_ind;//O(1)
        else{
            if(ano_set[ano_ind]==set[self_ind]){
                ret.add(set[self_ind]);//O(1)
                ++ano_ind, ++self_ind;
            }
            else if(ano_set[ano_ind]>set[self_ind]){
                ret.add(set[self_ind]);//O(1)
                ++self_ind;
            }
            else{
                ret.add(ano_set[ano_ind]);//O(1)
                ++ano_ind;
            }
        }
    }
    ano_set = nullptr;
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
int MySet::getSize() const{
    return size;
}


//O( N )
void MySet::print() const{
    assert(bufferSize>=size);   
    std::cout<<"{";
    for (int i = 0; i < size; i++) std::cout<< set[i]<<", ";
    std::cout<<"}"<<std::endl;
}

// This is only for test code
int* MySet::st()const{
    return set;
}