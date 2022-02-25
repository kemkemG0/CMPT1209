#include<bits/stdc++.h>
#include"Queue.h"

using ll= long long;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define ALL(x) x.begin(),x.end()

#define INF (ll)1e9
#define LLINF (ll)1e15
#define MOD (ll)(1e9+7)
#define PI 3.141592653589

#define endl "\n"

#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr);


const int dh[]={0,1,0,-1};
const int dw[]={1,0,-1,0};

using namespace std;
/*..................DEFINE GLOBAL VARIABLES...................*/
string createString(){
    string s;
    REP(i,rand()%20){
        s.push_back('a'+rand()%26);
    } 
    return s;
}

/*.....................DEFINE FUNCTIONS ......................*/
void randomIntTest(){
    queue<int> real_q;
    Queue<int,10> my_q;
    assert(my_q.isSame(real_q));

    int e;
    REP(i,10000){
        e = rand()%100000000;
        my_q.insert(e);
        real_q.push(e);
        if(!my_q.empty() && rand()%5==0){
            int tt = my_q.remove();
            assert(tt == (int)real_q.front());
            real_q.pop();
        }
        if(i%10==0){
            assert(my_q.isSame(real_q));
        }
    }
    cout<<"ok"<<endl;
}

void randomStringTest(){
    queue<string> real_q;
    Queue<string,10> my_q;
    assert(my_q.isSame(real_q));

    string e;
    REP(i,1000){
        e = createString();
        my_q.insert(e);
        real_q.push(e);
        if(!my_q.empty() && rand()%5==0){
            my_q--;
            real_q.pop();
        }
        if(i%10==0){
            assert(my_q.isSame(real_q));
        }
    }
    cout<<"ok"<<endl;
}

void chainTest(){
    vector<int> v;
    queue<int> real_q;


    Queue<int,10> my_q1;
    Queue<int,10> my_q2;
    REP(i,10)my_q1+=i, v.push_back(i);
    FOR(i,50,60)my_q2+=i, v.push_back(i);
    for(int vv:v)real_q.push(vv);
    Queue<int,10> my_q3(my_q1+my_q2);
    
    assert(my_q3.isSame(real_q));

    REP(i,20){
        my_q3+=i*i;
        real_q.push(i*i);
    }
    assert(my_q3.isSame(real_q));
    
    cout<< my_q1+my_q2;// test chain

    vector<string> vs;
    queue<string> real_q_str;
    Queue<string,10> my_q1_str;
    Queue<string,10> my_q2_str;
    REP(i,10){
        string s = createString();
        my_q1_str+= s;
        vs.push_back(s);
    }
    FOR(i,50,60){
        string s = createString();
        my_q2_str+= s;
        vs.push_back(s);
    }
    for(auto s:vs)real_q_str.push(s);
    Queue<string,10> my_q3_str(my_q1_str+my_q2_str);
    assert(my_q3_str.isSame(real_q_str));
    
    cout << my_q1_str+my_q2_str;// test chain 
    
    cout<<"ok"<<endl;
}



void operatorsTest(){
    Queue<int,10> my_q1;
    Queue<int,10> my_q2;
    REP(i,10)my_q1+=i;
    REP(i,10)my_q2+=i;
    assert(my_q1==my_q2);
    my_q1.insert(10);
    assert(my_q1!=my_q2);
    my_q1--;
    assert(my_q1==my_q2);

    cout<<"ok"<<endl;
}


void selfAssignmentTest(){
    Queue<int,10> my_q1;
    Queue<int,10> my_q2;
    my_q1.insert(1);
    my_q1.insert(1);
    my_q1.insert(1);
    my_q2 = my_q1;
    cout<< my_q2;
    my_q2 = my_q2;
    cout<< my_q2;
}
/*.........................kemkemG0...........................*/
signed main() {
    __MAGIC__
    
    srand(time(0));
    
    randomIntTest();
    randomStringTest();
    chainTest();
    operatorsTest();
    
    int a=10,b=5,c=6;
    int d = a--;
    
    
    
    return 0;
}
