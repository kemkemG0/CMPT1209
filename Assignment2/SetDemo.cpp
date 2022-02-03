#include<iostream>
#include"MySet.h"
#include<assert.h>
using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)

void getInput(int *&arr,int sz){
    if(sz> 20)cout<<"!! Only top-20 elements will use. !!";
    sz = min(sz, 20);
    arr = new int[sz];
    int n;
    REP(i, sz) cin>>n, arr[i]=n;
    cout<<endl;
    return;
}


void testUnionAndInterSect(){
    int *first, *second;
    
    int f_sz;
    cout<<"Size of list>> "; cin>>f_sz;
    cout<<"Input first list >>";
    getInput(first, f_sz);
    cout<<endl;

    int s_sz;
    cout<<"Size of list>> "; cin>>s_sz;
    cout<<"Input second list >>";
    getInput(second, s_sz);
    cout<<endl;


    MySet firstSet(first,f_sz);
    MySet secondSet(second,s_sz);
    delete[] first, delete[] second;
    
    auto unionSet = firstSet.unionWith(secondSet);
    auto interSectSet = firstSet.intersectWith(secondSet);

    cout<<"UnionSet:"<<endl<<"  ";
    unionSet.print();

    cout<<"interSectSet:"<<endl<<"  ";
    interSectSet.print();


}


int main(){
    testUnionAndInterSect();
}