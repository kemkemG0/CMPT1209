#include<iostream>
#include"MySet.h"
using namespace std;

int getInput(int arr[], int max_sz){
    char p;
    int ind=0;
    char prev;
    int num=0;
    while(cin.get(p) && --max_sz){
        if(p=='\n')return ind+1;
        if(p==' ')continue;
        if(!isdigit(p)){
            cout<<"invalid input"<<endl;
            exit(1);
        }
        arr[ind]=p-'0';
        ++ind;
    }
    return min((int)max_sz,ind+1);
}
int main(){
    int first[20]={};
    int second[20]={};
    char p;
    cout<<"Input first list >> ";
    int f_sz = getInput(first,20);
    cout<<"Input first list >> ";
    int s_sz = getInput(second,20);

    IntegerSet firstSet(first,f_sz);
    IntegerSet secondSet(second,f_sz);
    
    auto unionSet = firstSet.unionWith(secondSet);
    auto interSectSet = firstSet.intersectWith(secondSet);

    cout<<"UnionSet:"<<endl;
    unionSet.print();

    cout<<"interSectSet:"<<endl;
    interSectSet.print();
}