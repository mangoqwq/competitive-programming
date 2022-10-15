#include <bits/stdc++.h>

using namespace std;

vector<int> graph[300001];
int has[300001];

int f(int x){
    int minimum=2*0x3f3f3f3f;
    for (auto&&a:graph[x]){
        minimum=min(minimum,f(a));
    }
    if (minimum==2*0x3f3f3f3f){
        minimum=0;
    }
    return minimum+has[x];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int foods, recipes; cin >> foods >> recipes;
    int a,b,c;
    for (int i=0;i<recipes;++i){
        cin >> a >> b;
        for (int k=0;k<b;++k){
            cin >> c;
            graph[a].push_back(c);
        }
    }
    for (int i=0;i<foods;++i){
        cin >> has[i+1];
    }
    cout << f(1) << '\n';

}