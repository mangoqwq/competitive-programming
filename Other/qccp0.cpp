#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    while (n--){
        double t; cin >> t;
        if (t<34) cout << "Too cold, please try again." << '\n';
        else if (t<=35.5) cout << "Take a hot bath." << '\n';
        else if (t<=38) cout << "Rest if feeling unwell." << '\n';
        else if (t<=39) cout << "Take some medicine." << '\n';
        else if (t<=41) cout <<  "Take a cold bath and some medicine." << '\n';
        else if (t<=46.1) cout << "Go to the hospital." << '\n';
        else if (t<=50) cout << "Congrats, you have a new world record!" << '\n';
        else cout << "Too hot, please try again." << '\n';
    }
}