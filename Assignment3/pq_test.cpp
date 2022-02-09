#include<iostream>
#include"pq.h"
#include<string>

using namespace std;

int main(){
    PriorityQueue<int,30> pq_int;
    for(int i=0;i<=20;i++){
        pq_int.insert(i);
    }
    for(int i=0;i<=20;i++){
        cout<< pq_int.remove() <<" : size = ";
        cout<< pq_int.getSize() <<endl;
    }

    cout<<"\n\n\n"<<endl;

    PriorityQueue<string,30> pq_string;
    pq_string.insert("");
    pq_string.insert("abc");
    pq_string.insert("testtest");
    pq_string.insert("zzzabc");
    pq_string.insert("a");
    for(int i=0;i<5;i++){
        cout<< pq_string.remove() <<" : size = ";
        cout<< pq_string.getSize() <<endl;
    }

    cout<<"\n\n\n"<<endl;

    PriorityQueue<char,30> pq_char;
    pq_char.insert('a');
    pq_char.insert('b');
    pq_char.insert('d');
    pq_char.insert('z');
    pq_char.insert('e');
    pq_char.insert('f');
    for(int i=0;i<6;i++){
        cout<< pq_char.remove() <<" : size = ";
        cout<< pq_char.getSize() <<endl;
    }
    cout<<"\n\n\n"<<endl;


    return 0;
}


