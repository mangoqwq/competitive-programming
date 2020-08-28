#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll money[100001];
vector<pair<ll,int>> uwu;
int owo[100001];


int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int people, queries; cin >> people >> queries;
    for (int i=1;i<people+1;++i){
        cin >> money[i];
    }
    for (int i=1,a;i<people+1;++i){
        cin >> a;
        money[i]+=money[a];
        uwu.push_back({money[i],i});
    }
    sort(uwu.begin(),uwu.end());
    int mininum=0x3f3f3f3f;
    for (int i=people-1;i>=0;--i){
        mininum=min(mininum,uwu[i].second);
        owo[i]=mininum;
    }
    for (int i=0;i<queries;++i){
        ll cost, has; cin >> has >> cost;
        if (cost<=has||cost-has>uwu[people-1].first){
            cout << -1 << '\n';
            continue;
        }
        else{
            int bot=0, top=people-1, mid;
            while (bot<=top){
                mid=(bot+top+1)/2;
                //cout << uwu[mid].first << " AA " << cost-has << " AA " << uwu[mid].second << " AA " << owo[mid] << '\n';
                if (mid==0){
                    cout << owo[0] << '\n';
                    break;
                }
                
                if (uwu[mid].first>=(cost-has) && uwu[mid-1].first<cost-has){
                    cout << owo[mid] << '\n';
                    break;
                }
                else if (uwu[mid-1].first>=cost-has){
                    top=mid-1;
                }
                else{
                    bot=mid+1;
                }
            }
        }

    }
    
    

}