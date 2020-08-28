#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
struct cowstruct{
    int cf,cs;
    bool f,s;
};
queue<pii> q[100001];
cowstruct cow[100001];
bool visited[100001];
int cnt=0;

void push(int box){
    if (visited[box]||q[box].empty()) return;
    visited[box]=1;
    int temp,choice;
    while (!q[box].empty()){
        temp=q[box].front().first; choice=q[box].front().second;
        if (choice==1){
            cow[temp].f=true;
            cow[temp].s=false;
            push(cow[temp].cs);
            
            return;
        }
        if (choice==2){
            if (cow[temp].f){
                q[box].pop();
            }
            else{
                cow[temp].s=true;
                return;
            }
        }
    }
    cnt--;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("cereal.in","r",stdin);
    //freopen("cereal.out","w",stdout);
    int n,m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        cin >> cow[i].cf >> cow[i].cs;
        if (q[cow[i].cf].empty()){
            cnt++;
            q[cow[i].cf].push({i,1});
            cow[i].f=true;
            continue;
        }
        q[cow[i].cf].push({i,1});
        if (q[cow[i].cs].empty()){
            cnt++;
            cow[i].s=true;
        }
        q[cow[i].cs].push({i,2});
    }
    cout << cnt << '\n';
    for (int i=1;i<n;++i){
        memset(visited,false,sizeof visited);
        q[cow[i].cf].pop();
        if (q[cow[i].cf].empty()){
            cnt--;
        }
        push(cow[i].cf);
        cout << cnt << '\n';
    }
    
}