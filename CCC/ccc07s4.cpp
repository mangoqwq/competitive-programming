#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10000];
long long dp[10000];
int uwu(int node){
    if (dp[node]>=0){
        return dp[node];
    }
    int total=0;
    for (auto&&x:graph[node]){
        total+=uwu(x);
    }
    dp[node]=total;
    return total;

}

int main(){
    for (int i=0;i<10000;++i){
        dp[i]=-1;
    }
    int n, a=-1, b=-1;
    cin >> n;
    dp[n]=1;
    while (a!=0 && b!=0){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    int ee=uwu(1);
    cout << ee << '\n';
    
}