#include <bits/stdc++.h>

using namespace std;

int main(){
    deque<char> q;
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N; cin >> N;
    char a; cin >> a;
    q.push_front(a);
    for (int i=0;i<N-1;++i){
        cin >> a;
        if (a<=q.front()){
            q.push_front(a);
        }
        else{
            q.push_back(a);
        }
    }
    for (int i=0;i<N;++i){
        cout << q.front();
        q.pop_front();
    }
    cout << '\n';
}