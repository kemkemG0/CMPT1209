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

#define YESNO(T) cout<<((T)?"YES":"NO")<<endl;
#define yesno(T) cout<<((T)?"yes":"no")<<endl;
#define YesNo(T) cout<<((T)?"Yes":"No")<<endl;

#define DDD fixed<<setprecision(10)
#define endl "\n"

#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

const int dh[]={0,1,0,-1};
const int dw[]={1,0,-1,0};

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}

template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){
    for(auto e:vec)os<<e<<" ";os<<endl;
    return os;
}
template<typename T>
ostream& operator << (ostream& os, vector<vector<T>>& vec) {
    for(auto v:vec){for(auto ele:v)os<<ele<<", ";os<<endl;}
    return os;
}
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
    REP(i,100000){
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
    REP(i,100000){
        e = createString();
        my_q.insert(e);
        real_q.push(e);
        if(!my_q.empty() && rand()%5==0){
            string tt = my_q.remove();
            assert(tt == (string)real_q.front());
            real_q.pop();
        }
        if(i%10==0){
            assert(my_q.isSame(real_q));
        }
    }
    cout<<"ok"<<endl;
}

void chainTest(){
    Queue<int,10> my_q1;
    Queue<int,10> my_q2;
    REP(i,10)my_q1+=i;
    FOR(i,50,60)my_q2+=i;
    cout<< --(my_q2 + (my_q1+my_q2));// test chain

    Queue<string,10> my_q1_str;
    Queue<string,10> my_q2_str;
    REP(i,10)my_q1_str+=createString();
    FOR(i,50,60)my_q2_str+=createString();
    cout<< --(my_q2_str + (my_q1_str+my_q2_str));// test chain 
}

/*.........................kemkemG0...........................*/
signed main() {
    __MAGIC__
    
    srand(time(0));
    
    randomIntTest();
    chainTest();
    
    
    
    return 0;
}
