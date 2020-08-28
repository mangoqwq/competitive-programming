#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef long long ll;
const int mod=1000000007;
pii owo[100001];
vector<ppii> x;
vector<ppii> y;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin >> n;
    x.resize(n); y.resize(n);
    for (int i=0,a,b;i<n;++i){
        cin >> a >> b;
        x[i]={{b,a},i};
        y[i]={{a,b},i};
    }
    sort(x.begin(),x.end()); sort(y.begin(),y.end());
    cout << '\n';
    int row,end,before=0,after=0; 
    for (int start=0;start<n-1;){
        before=0;after=0;
        row=x[start].first.first;
        for (int i=start;i<n;++i){
            if (x[i].first.first!=row){
                end=i-1;
                break;
            }
        }
        if (end<start){
            end=n-1;
        }
        for (int i=start;i<=end;++i){
            after+=x[i].first.second-x[start].first.second;
        }
        owo[x[start].second].first=before+after;
        for (int i=start+1;i<=end;++i){
            before+=(i-start)*(x[i].first.second-x[i-1].first.second);
            after-=(end-i+1)*(x[i].first.second-x[i-1].first.second);
            owo[x[i].second].first=after+before;
        }
        start=end+1;
    }
    int column;
    for (int start=0;start<n-1;){
        //cout << start << " - " << end << '\n';
        before=0;after=0;
        column=y[start].first.first;
        //cout << column << " - ";
        for (int i=start;i<n;++i){
            if (y[i].first.first!=column){
                end=i-1;
                break;
            }
        }
        if (end<start){
            end=n-1;
        }
        for (int i=start;i<=end;++i){
            after+=y[i].first.second-y[start].first.second;
        }
        owo[y[start].second].second=before+after;
        for (int i=start+1;i<=end;++i){
            before+=(i-start)*(y[i].first.second-y[i-1].first.second);
            after-=(end-i+1)*(y[i].first.second-y[i-1].first.second);
            owo[y[i].second].second=before+after;
        }
        start=end+1;
    }
    ll total=0;
    //cout << '\n';
    for (int i=0;i<n;++i){
        //cout << owo[i].first << " " << owo[i].second<<'\n';
        total+=(ll)owo[i].first*(ll)owo[i].second;
    }
    cout << total%mod << '\n';
}