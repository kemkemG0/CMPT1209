#include<iostream>
#include<set>
#include"MySet.h"
#include<assert.h>
using namespace std;
#define REP(i,n) for(int i=0;i<int(n);i++)


void test(){
    srand(time(0));

    //single add, remove
    set<int> st;
    MySet mySt;
    REP(i,1000){
        int a = rand()%100000000;
        st.insert(a), mySt.add(a);
        a = rand()%100;
        st.erase(a), mySt.remove(a);
        assert(mySt.isSameSet(st));
    }
    cout<<"..OK!\n";


    //bulk add(check first enough)
    set<int> stB;
    MySet myStB;
    int N=1000000;
    auto  bb = new int[N]; 
    REP(i,N){
        int a = rand()%10000000;
        bb[i]=a;
        stB.insert(a);
    }
    myStB.add(bb, N);
    assert(myStB.isSameSet(stB));
    cout<<"..OK!\n";

    //intersect
    auto myInterSect = mySt.intersectWith(myStB);
    set<int> interSect;
    for(auto e:st) if(stB.find(e)!=stB.end())interSect.insert(e);
    assert(myInterSect.isSameSet(interSect));
    cout<<"..OK!\n";

    //union
    auto myUnionSet = mySt.unionWith(myStB);
    set<int> unionSet;
    for(auto e:st)unionSet.insert(e);
    for(auto e:stB)unionSet.insert(e);
    assert(myUnionSet.isSameSet(unionSet));
    cout<<"..OK!\n";
}

int main(){
    test();
    return 0;
}