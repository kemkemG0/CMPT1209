#include<iostream>
#include<set>
#include"MySet.h"
#include<assert.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);i++)

void compare(const MySet& is,const set<int>& st){
    set<int> newSt;
    auto isSt = is.st();
    for(int i=0;i<is.getSize();++i){
        newSt.insert(isSt[i]);
    }
    assert(st==newSt);
}

void test(){
    srand(time(0));
    set<int> st;
    MySet mySt;
    REP(i,10000){
        int a = rand()%100000000;
        st.insert(a), mySt.add(a);
        a = rand()%100;
        st.erase(a), mySt.remove(a);
        assert(mySt.getSize()==st.size());
    }
    cout<<"..OK!\n";
    compare(mySt,st);
    cout<<"..OK!\n";
    set<int> stB;
    MySet myStB;
    int N=1000000;
    auto  bb = new int[N]; 
    REP(i,N){
        int a = rand()%10000000;
        bb[i]=a;
        stB.insert(a);
    }
    myStB.add(bb,N);
    assert(myStB.getSize()==stB.size());
    compare(myStB,stB);
    cout<<"..OK!\n";
    auto myInterSect = mySt.intersectWith(myStB);
    set<int> interSect;
    for(auto e:st){
        if(stB.find(e)!=stB.end())interSect.insert(e);
    }
    assert(myInterSect.getSize()==interSect.size());
    compare(myInterSect,interSect);
    cout<<"..OK!\n";

    auto myUnionSet = mySt.unionWith(myStB);
    set<int> unionSet;
    for(auto e:st)unionSet.insert(e);
    for(auto e:stB)unionSet.insert(e);
    assert(myUnionSet.getSize()==unionSet.size());
    compare(myUnionSet,unionSet);
    cout<<"..OK!\n";
}

int main(){
    test();
    return 0;
}