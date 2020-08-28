#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<13);

int r,c,ef1,ef2;
vector<int> adj[13];
double dp[1594324][2];

double solve(int mask1, int mask2, int cnt, int p){
    int mask=0;
    for (int i=0,temp=1;i<13;++i,temp*=3){
        if (1&(mask1>>i)) mask+=temp*2;
        if (1&(mask2>>i)) mask+=temp;
    }
    if (dp[mask][p]!=-1) return dp[mask][p];
    vector<double> pool;
    for (int i=0;i<r*c;++i){
        for (int j:adj[i]){
            if ((1&(mask1>>i))&&(1&(mask2>>j))) {
                pool.push_back(1-solve(mask2-(1<<j),mask1-(1<<i)+(1<<j),cnt-1,!p));
            }
            else if ((1&(mask1>>i))&&(1&(mask1>>j))) {
                pool.push_back(1-solve(mask2,mask1-(1<<i),cnt-1,!p));
            }
        }
    }
    if (pool.empty()) return dp[mask][p]=0;
    sort(pool.begin(),pool.end());
    reverse(pool.begin(),pool.end());
    int num=min((int)pool.size(),(p==0?ef1:ef2));
    double val=0;
    for (int i=0;i<num;++i) val+=pool[i]/num;
    return dp[mask][p]=val;
}

int main(){
    cin >> r >> c;
    char a;
    int mask1=0,mask2=0;
    int uwu=(int)pow(3,r*c);
    for (int i=1;i<=uwu;++i) dp[i][0]=dp[i][1]=-1;
    for (int i=0;i<r;++i){
        for (int j=0;j<c;++j){
            cin >> a;
            if (a=='J') mask1+=(1<<i*c+j);
            if (a=='D') mask2+=(1<<i*c+j);
            if (i!=0) adj[i*c+j].push_back((i-1)*c+j), adj[(i-1)*c+j].push_back(i*c+j);
            if (j!=0) adj[i*c+j].push_back(i*c+(j-1)), adj[i*c+(j-1)].push_back(i*c+j);
        }
    }
    cin >> ef1 >> ef2;
    printf("%.3f\n",solve(mask1, mask2, r*c, 0));
}