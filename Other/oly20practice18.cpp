#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    deque<pii> q; q.push_back({n,s[n-1]});
    bool back=true;
    for (int i=n-2;i>=0;--i){
        if (s[i]==s[i+1]){
            if (back) q.push_back({i+1,s[i]});
            else q.push_front({i+1,s[i]});
        }
        else if (s[i]<s[i+1]){
            q.push_back({i+1,s[i]});
            back=true;
        }
        else{
            q.push_front({i+1,s[i]});
            back=false;
        }
    }
    vector<int> ans; stack<int> owo; int temp=-1;
    while (!q.empty()){
        //cout << q.front().first << " ";
        if (q.front().second==temp&&q.front().first+1==owo.top()){
            owo.push(q.front().first);
            q.pop_front();
            continue;
        }
        while (!owo.empty()){
            ans.push_back(owo.top());
            owo.pop();
        }
        owo.push(q.front().first);
        temp=q.front().second;
        q.pop_front();
    }
    //cout << '\n';
    while (!owo.empty()){
        ans.push_back(owo.top());
        owo.pop();
    }
    for (auto&&x:ans){
        cout << x << " ";
    }
}