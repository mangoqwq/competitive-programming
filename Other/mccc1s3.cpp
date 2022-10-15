#include <bits/stdc++.h>

using namespace std;
const int seed = 97; const int seed2 = 131;
typedef long long ll;
ll hashlist[100001];
ll hashlist2[100001];
map<ll,int> m;
map<ll,int> m2;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    string s; int queries; cin >> s >> queries;
    ll temphash=0;
    ll temphash2=0;
    for (int i=0;i<s.length();++i){
        temphash=temphash*seed+s[i];
        //temphash2=temphash2*seed2+s[i];
        m.insert({temphash,1});
        //m2.insert({temphash2,1});
    }
    hashlist[1]=temphash;
    //hashlist2[1]=temphash2;
    int idx=1; int answer=-1;
    char query; int index; char add; string a;
    for (int i=0;i<queries;++i){
        temphash=0;
        //temphash2=0;
        cin >> query;
        if (query=='C'){
            cin >> index >> add;
            idx++;
            hashlist[idx]=hashlist[index]*seed+add;
            //hashlist2[idx]=hashlist2[index]*seed2+add;
            //cout << hashlist[idx] << " ";
            if (m[hashlist[idx]]==(long long)0){
                m[hashlist[idx]]=idx;
            }
            /*
            if (m2[hashlist2[idx]]==0){
                m2[hashlist2[idx]]=idx;
            }
            */
        }
        else if (query=='Q'){
            cin >> a;
            answer=-1;
            for (int i=0;i<a.length();++i){
                //cout << temphash << '\n';
                temphash=temphash*seed+a[i];
                //temphash2=temphash2*seed2+a[i];
                if (m[temphash]!=0 /*&& m2[temphash2]!=0 && m[temphash]==m2[temphash2]*/){
                    answer=m[temphash];
                }
            }
            cout << answer << '\n';
        }
    }
}