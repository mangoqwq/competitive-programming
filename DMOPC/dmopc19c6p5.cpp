#include <bits/stdc++.h>

using namespace std;
int width[100001];
int height[100001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> height[i];
    }
    for (int i=1;i<=n;++i){
        cin >> width[i];
    }
    for (int i=0,l,r;i<q;++i){
        cin >> l >> r;
        if (r==l){
            cout << (width[r]+height[r])*2 << '\n';
        }
        else if (r-l==1){
            cout << (width[r]+height[r]+width[l]+height[l])*2-min(height[l],height[r]) << '\n';
        }
    }
}