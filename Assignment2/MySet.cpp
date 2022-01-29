#include<iostream>
#include<assert.h>
#include"MySet.h"


//A no-arg constructor that creates an empty set with the buffer size of 10.
IntegerSet::IntegerSet(){
    set = new int[10];
    size=0;
    bufferSize=10;
    assert(bufferSize>=size);
}

IntegerSet::IntegerSet(const int sequence[], int size){
    set = new int[10];
    size=0;
    bufferSize=10;
    add(sequence,size);
    assert(bufferSize>=size);
}

IntegerSet::IntegerSet(const IntegerSet& anotherSet){
    assert(bufferSize>=size);
}
IntegerSet::~IntegerSet(){
    assert(bufferSize>=size);
    delete[] set;
}

//O( Nlog(N) )
bool IntegerSet::add(int item){
    //After added, the set should be sorted;
    assert(bufferSize>=size);
    if(has(item))return false;
    if(bufferSize==size){
        //allocate memory
        int* new_set = new int[bufferSize + bufferSize/2];
        int ind=0;
        for(int i=0;i<size;++i){
            if(set[i]<item && (i+1==size||item<set[i+1])){
                new_set[ind]=item;
                ++ind;
            }
            new_set[ind]=set[i];
            ++ind;
        }
        delete[] set;
        set = new_set;
        size++;
        return true;
    }
    // without allocation
    if(set[size-1]<item){
        set[size]=item;
        ++size;
        return true;
    }
    int ok = size-1;
    int ng = -1;
    assert(item<set[ok]);
    while(ok-ng>=1){
        int mid = (ok+ng)/2;
        assert(mid>=0);
        if(set[mid]>item)ok=mid;
        else ng = mid;
    }
    assert(item<set[ok]);
    assert(ok-1<0 || item>set[ok-1]);
    //     a, b, ok, c, d
    //to   a, b, new,ok,c,d
    // set[size-1]=>set[size], set[ok]=>set[ok+1];
    for(int i=size-1;i>ok;--i) set[i] = set[i-1];
    set[ok]=item;
    return true;
}

//O( Nlog(N) )
bool IntegerSet::add(const int sequence[], int size){
    assert(bufferSize>=size);
    bool ret=false;
    for(int i=0;i<size;++i){
        assert(bufferSize>=size);
        if(has(sequence[i]))continue;
        add(sequence[i]);
        ret=true;
    }
    return ret;
}

//O(N)
bool IntegerSet::remove(int item){
    if(!has(item))return false;
    int ok = size-1;
    int ng = -1;
    while(ok-ng>1){
        int mid=(ok+ng)/2;
        if(set[mid]>=item)ok=mid;
        else ng=mid;
    }
    //delete set[ok]
    assert(set[ok]==item);
    // left shift
    for(int i=ok;i<size-1;++i)set[i]=set[i+1];
    --size;
    return true;
}

//O( log(N) )
bool IntegerSet::has(int item) const{
    assert(bufferSize>=size);
}

//O( N )
IntegerSet IntegerSet::unionWith(const IntegerSet& anotherSet) const{
    assert(bufferSize>=size);
    
}

//O( N )
IntegerSet IntegerSet::intersectWith(const IntegerSet& anotherSet) const{
    assert(bufferSize>=size);
}
//O( 1 )
void IntegerSet::clear(){
    assert(bufferSize>=size);
}
//O( 1 )
int IntegerSet::getSize() const{
    assert(bufferSize>=size);
}
//O( 1 )
void IntegerSet::print() const{
    assert(bufferSize>=size);
}

