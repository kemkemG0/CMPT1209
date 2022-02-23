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


/*.....................DEFINE FUNCTIONS ......................*/


/*.........................kemkemG0...........................*/
signed main() {
    __MAGIC__
    
    srand(time(0));
    
    queue<int> real_q;
    Queue<int,10> my_q;
    assert(my_q.isSame(real_q));

    int e;
    REP(i,100000){
        // e = rand()%100000000;
        e=i;
        my_q.insert(e);
        real_q.push(e);
        if(!my_q.empty() && rand()%5==0){
            int tt = my_q.remove();
            // cout<<tt<<" "<<real_q.front()<<endl;
            assert(tt == (int)real_q.front());
            real_q.pop();
        }
        if(i%10==0){
            assert(my_q.isSame(real_q));
        }
    }

    // REP(i,30)my_q.insert(i),cout<<my_q;
    // cout<<my_q;
    // REP(i,15)my_q.remove();
    // cout<<my_q;
    // REP(i,30)my_q.insert(i);
    // cout<<my_q;
    
    
    
    
    
    return 0;
}
