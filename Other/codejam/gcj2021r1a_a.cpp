#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int _=1;_<=t;++_){
        cout << "Case #" << _ << ": ";
        int n; cin >> n;
        string last="0", curr;
        int ans=0;
        for (int i=1;i<=n;++i){
            cin >> curr;
            if (last.size()<curr.size()){
            }
            else if (last.size()==curr.size()){
                if (stoll(curr)<=stoll(last)) ans++, curr+="0";
            }
            else if (last.size()>curr.size()){
                string tmp=last.substr(0,curr.size());
                if (stoll(curr)<stoll(tmp)){
                    while (curr.size()<=last.size()) ans++, curr+="0";
                }
                else if (stoll(curr)==stoll(tmp)){
                    bool bad=1;
                    for (int j=curr.size();j<last.size();++j) bad&=last[j]=='9';
                    if (bad){
                        while (curr.size()<=last.size()) ans++, curr+="0";
                    }
                    else{
                        for (int j=last.size()-1;;--j){
                            if (last[j]=='9') last[j]='0';
                            else { last[j]++; break; }
                        }
                        ans+=last.size()-curr.size();
                        curr=last;
                    }
                }
                else{
                    while (curr.size()<last.size()) ans++, curr+="0";
                }
            }
            last=curr;
        }
        cout << ans << '\n';
    }
}