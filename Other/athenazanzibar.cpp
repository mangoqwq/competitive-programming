#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef long long ll;
const ll t=1e7;
map<int,int> m;

bool cmp(pii a,pii b){
    return make_pair(abs(a.first),a.second)<=make_pair(abs(b.first),b.second);
}


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<pii> uwu;
    pair<int,pii> ans{INT_MAX,{INT_MAX,INT_MAX}};
    for (int i=1,a;i<=n;++i){
        cin >> a;
        if (m[a]!=0){
            piii temp={abs(2*a),{m[a],i}};
            if (ans>temp){
                ans=temp;
            }
            continue;
        } 
        m[a]=i;
        uwu.push_back({a,i});
    }
    sort(begin(uwu),end(uwu),cmp);
    
    for (int i=0;i<uwu.size()-1;++i){
        //cout << uwu[i].first << " " << uwu[i].second << '\n';
        int temp=abs(uwu[i+1].first+uwu[i].first);
        pii index={min(uwu[i+1].second,uwu[i].second),max(uwu[i+1].second,uwu[i].second)};
        //cout << index.first << " " << index.second << '\n';
        if (temp<ans.first){
            ans={temp,index};
        }
        else if (temp==ans.first){
            if (index<ans.second){
                ans={temp,index};
            }
        }
    }
    if (uwu.size()==1){
        cout << 2*uwu[0].first << '\n' << 1 << " " << 2 << '\n';
        return 0;
    }
    cout << ans.first << '\n' << ans.second.first << " " << ans.second.second << '\n';
}