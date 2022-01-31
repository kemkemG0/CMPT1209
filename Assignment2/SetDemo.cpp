#include<iostream>
#include"MySet.h"
#include<assert.h>
using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)

int getInput(int arr[]){
    char cur, prev;
    int buff=0,ind=0;
    while(cin.get(cur)){
        if(cur=='\n'){
            if(isdigit(prev))
                arr[ind++]=buff;
            break;
        }
        if(ind>=20)continue; //for consume all characters
        if(cur==' '){
            if(isdigit(prev))
                arr[ind++]=buff, buff=0;
            prev=cur;
            continue;
        }
        buff = 10*buff + (cur-'0');
        prev = cur;
    }
    return ind;
}


void testUnionAndInterSect(){
    int first[20]={};
    int second[20]={};
    char p;
    cout<<"Input first list >> ";
    int f_sz = getInput(first);
    cout<<"Input second list >> ";
    int s_sz = getInput(second);

    IntegerSet firstSet(first,f_sz);
    IntegerSet secondSet(second,s_sz);
    
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