#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=366;

string suf[MAXN];
deque<string> q;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<MAXN;++i) suf[i]="th";
    for (int i=1;i<MAXN;i+=10) if (i%100!=11) suf[1]=suf[i]="st";
    for (int i=2;i<MAXN;i+=10) if (i%100!=12)suf[i]="nd";
    for (int i=3;i<MAXN;i+=10) if (i%100!=13) suf[i]="rd";
    getline(cin,suf[0]);
    for (int i=1;i<=n;++i){
        string a; getline(cin,a);
        q.push_back(a);
        printf("On the %d%s day of Christmas my true love sent to me:\n", i, suf[i].c_str());
        for (int j=q.size()-1;j>=0;--j){
            if (i!=1&&j==0) printf("and ");
            printf("%d %s\n", j+1, q[j].c_str());
        }
        if (i!=n) printf("\n");
    }

}