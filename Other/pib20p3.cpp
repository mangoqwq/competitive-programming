#include <bits/stdc++.h>

using namespace std;
bool ans[100001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int block=0,count=0,rules=0;
    int q; cin >> q;
    for (int _=1,a,b;_<q+1;++_){
        cin >> a;
        if (a==1){
            rules++;
            for (int i=block;i<rules;++i){
                ans[i]=(((i-block+1)+count)%2);
            }
            block=rules;
            count=0;
        }
        else if (a==2){
            rules++;
            count++;
        }
        else{
            cin >> b;
            if (b<block){
                cout << ans[b] << '\n';
            }
            else{
                cout << (((b-block+1)+count)%2) << '\n';
            }
        }
    }
    
}