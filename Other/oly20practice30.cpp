
#include <bits/stdc++.h>

using namespace std;

string solve(deque<char> q){
    string ans="";
    char temp;
    if (q.size()==1){
        cout << "AAAAAAAAAAAA" << q.front() << '\n';
        ans+=q.front();
        return ans;
    }
    if (q.front()<q.back()){
        ans+=q.front();
        q.pop_front();
        ans+=solve(q);
    }
    else if (q.back()>q.front()){
        ans+=q.back();
        q.pop_back();
        ans+=solve(q);
    }
    else{
        string owo;
        temp=q.front();
        ans+=temp;
        q.pop_front();
        owo=solve(q);
        q.push_front(temp);
        q.pop_back();
        owo=max(owo,solve(q));
        ans+=owo;
    }
    return ans;
}

int main(){
    int n; cin >> n;
    deque<char> q;
    char uwu;
    for (int i=0;i<n;++i){
        cin >> uwu;
        q.push_back(uwu);
    }
    cout << solve(q) << '\n';

}
