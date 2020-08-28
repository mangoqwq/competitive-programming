#include <bits/stdc++.h>

using namespace std;
vector<int> cows;
vector<int> period;
vector<int> ans;

int main(){
    //freopen("swap.in","r",stdin);
    //freopen("swap.out","w",stdout);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    cows.resize(n); ans.resize(n);
    for (int i=0;i<n;++i){
        cows[i]=i+1;
    }
    
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        reverse(cows.begin()+a-1,cows.begin()+b);
    }
    int temp,per;
    for (int i=1;i<n+1;++i){
        period.clear();
        if (ans[i-1]){
            continue;
        }
        temp=cows[i-1];
        period.push_back(i);
        per=k;
        for (int e=2;e<=k+n;++e){
            period.push_back(temp);
            temp=cows[temp-1];
            if (temp==i){
                per=e;
                break;
            }
        }
        /*
        for (auto&&x:period){
            cout << x << " ";
        }
        */
        //cout << "- " << per << '\n';
        for (int e=0;e<per;++e){
            ans[period[e]-1]=period[(e+(k%per))%per];
            //cout << period[e]-1 << " : " <<  period[(e+(k%per))%per] << '\n';
        }
    }
    for (auto&&x:ans){
        cout << x << '\n';
    }
}