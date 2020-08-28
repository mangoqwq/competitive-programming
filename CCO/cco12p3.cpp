#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define f first
#define s second
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

vector<pii> rv[26];
vector<int> vars;
bool rt[26][26];
bool dp[26][30][30];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int cv,ct,r1,r2; cin >> cv >> ct;
    char ca,cb,cc,start;
    cin >> start; start-='A'; vars.push_back(start);
    for (int i=2;i<=cv;++i) cin >> ca, vars.push_back(ca-'A');
    for (int i=1;i<=ct;++i) cin >> ca;
    cin >> r1;
    for (int i=1;i<=r1;++i){
        cin >> ca >> cb;
        rt[ca-'A'][cb-'a']=1;
    }
    cin >> r2;
    for (int i=1;i<=r2;++i){
        cin >> ca >> cb >> cc;
        rv[ca-'A'].push_back({cb-'A',cc-'A'});
    }
    int t; cin >> t;
    while (t--){
        ms(dp,0);
        string uwu; cin >> uwu;
        for (int i=0;i<uwu.size();++i){
            for (int j=0;j<26;++j){
                dp[j][i][0]=rt[j][uwu[i]-'a'];
            }
        }
        for (int len=1;len<uwu.size();++len){
            for (int pl=0,pr=len;pr<uwu.size();++pl,++pr){
                for (int i:vars){
                    for (pii x:rv[i]){
                        for (int j=pl;j<pr;++j){
                            dp[i][pl][len]|=dp[x.f][pl][j-pl]&&dp[x.s][j+1][pr-j-1];
                        }
                    }
                }
            }
        }
        cout << dp[start][0][uwu.size()-1] << '\n';
    }

}