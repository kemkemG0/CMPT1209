#include<iostream>
#include<assert.h>
#include"MySet.h"


IntegerSet::IntegerSet(){
    set = new int[10];
    size=0;
    bufferSize=10;
    assert(bufferSize>=size);
}


IntegerSet::IntegerSet(const int sequence[], int size){
    this->set = new int[10];
    this->size=0;
    this->bufferSize=10;
    add(sequence,size);
    assert(bufferSize>=this->size);
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
    if(size==0){
        set[0]=item, ++size;
        return true;
    }
    if(has(item))return false;
    if(bufferSize==size){
        std::cout<<"allocate"<<std::endl;
        //allocate memory
        int* new_set = new int[bufferSize + bufferSize/2];
        int new_ind=0;
        for(int old_ind=0;old_ind<size;++old_ind,++new_ind){
            new_set[new_ind]=set[old_ind];
        }
        delete[] set;
        set = new_set;
        bufferSize = bufferSize + bufferSize/2;
    }
    assert(bufferSize>=size);
    //add to the tail
    assert(size-1>=0);
    if(set[size-1]<item){
        set[size]=item;
        ++size;
        return true;
    }
    //insert to middle
    int ok = size-1;
    int ng = -1;
    assert(item<set[ok]);
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        assert(mid>=0);
        if(set[mid]>item)ok=mid;
        else ng = mid;
        assert(item<set[ok]);
    }
    assert(ok-1<0 || item>set[ok-1]);
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
    if(size==0 || set[size-1]<item)return false;
    bool ret = false;
    // set[ok]>=item is always true
    int ok=size-1;
    int ng = -1;
    assert(set[ok]>=item);
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        if(set[mid]>=item)ok=mid;
        else ng = mid;
        assert(set[ok]>=item);
    }
    return set[ok]==item;
}


//O( NlogN )
IntegerSet IntegerSet::unionWith(const IntegerSet& anotherSet) const{
    auto ano_set = anotherSet.set;
    auto ano_size = anotherSet.size;
    int self_ind=0, ano_ind=0;
    auto ret = IntegerSet();
    while(ano_ind<ano_size || self_ind<size){
        if(self_ind>=size)ret.add(ano_set[ano_ind]),++ano_ind;
        else if(ano_ind>=ano_size)ret.add(set[self_ind]),++self_ind;
        else{
            if(ano_set[ano_ind]==set[self_ind]){
                ret.add(set[self_ind]);
                ++ano_ind,++self_ind;
            }
            else if(ano_set[ano_ind]>set[self_ind]){
                ret.add(set[self_ind]);
                ++self_ind;
            }
            else{
                ret.add(ano_set[ano_ind]);
                ++ano_ind;
            }
        }
    }
    ano_set = nullptr;
    return ret;
}


//O( N )
IntegerSet IntegerSet::intersectWith(const IntegerSet& anotherSet) const{
    assert(bufferSize>=size);
    auto ano_set = anotherSet.set;
    auto ano_size = anotherSet.size;
    auto ret = IntegerSet();
    for (int i = 0; i < ano_size; i++){
        if(!has(ano_set[i]))continue;
        ret.add(ano_set[i]);
    }
    return ret;
}


//O( 1 )
void IntegerSet::clear(){
    assert(bufferSize>=size);
    delete[] set;
    set = new int[10];
    size=0;
    bufferSize=10;
    return;
}


//O( 1 )
int IntegerSet::getSize() const{
    return size;
}


//O( 1 )
void IntegerSet::print() const{
    assert(bufferSize>=size);
    for (int i = 0; i < size; i++) std::cout<< set[i]<<" ";
    std::cout<<std::endl;
}

