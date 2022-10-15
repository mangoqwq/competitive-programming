#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct uwu{
    int l, r; bool a;
};
bool cmp(uwu a, uwu b){
    if (make_pair(a.l,a.r)==make_pair(b.l,b.r)) return a.a<b.a;
    return make_pair(a.l,a.r)<make_pair(b.l,b.r);
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n, a, c; cin >> n >> a >> c;
    vector<uwu> arr; uwu temp; temp.a=true;
    for (int i=0;i<a;++i){
        cin >> temp.l >> temp.r;
        arr.push_back(temp);
    } temp.a=false;
    for (int i=0;i<c;++i){
        cin >> temp.l >> temp.r;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end(),cmp);
    temp.l=temp.r=n+5;
    arr.push_back(temp);
    int l=1,r=0,ans=0;
    for (int i=0;i<=a+c;++i){
        //cout << i << " " << l << " " << r << '\n';
        if (arr[i].a){ //anime
            if (r<arr[i].l){
                ans+=r-l+1;
                l=arr[i].l;
            }
            r=max(r,arr[i].r);
        }
        else{ //no anime ):
            if (r<l){
                if (arr[i].r>l){
                    l=r=arr[i].r+1; r--;
                }
            }
            else if (r<arr[i].l){ // --**____
                ans+=r-l+1;
                l=r=arr[i].r+1; r--;
            }
            else if (r<=arr[i].r){ // -----__**
                ans+=max(arr[i].l,l)-l;
                l=r=arr[i].r+1; r--;
            }
            else{ // ----__--**
                ans+=max(arr[i].l,l)-l;
                l=max(l,arr[i].r+1);
            }
        }
        //cout << ans << " ";
    }
    cout << ans << '\n';

}
