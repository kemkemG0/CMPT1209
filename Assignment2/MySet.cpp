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
    assert(bufferSize>=size);
    if(has(item))return false;
    assert(bufferSize>=size);
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

//O( Nlog(N) )
bool IntegerSet::remove(int item){
    assert(bufferSize>=size);
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

