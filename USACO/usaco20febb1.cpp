#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
vector<int> x[20001]; //x[0] is -10000, x[10000] is 0, x[20000] is 10000;
vector<int> y[20001]; //y[0] is -10000, y[10000] is 0, y[20000] is 10000;

int main(){
    //freopen("triangles.in","r",stdin);
    //freopen("triangles.out","w",stdout);
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0,xi,yi;i<n;++i){
        cin >> xi >> yi;
        x[xi+10000].push_back(yi+10000);
        y[yi+10000].push_back(xi+10000);
    }
    int uwu=0;
    for (int i=0;i<20001;++i){
        for (auto&&point1:x[i]){
            for (auto&&point2:x[i]){
                for (auto&&point3:y[point1]){
                    uwu=max(uwu,abs(point1-point2)*abs(i-point3));
                }
            }
        }
    }
    cout << uwu << '\n';
}