#include <iostream>
#include <queue>

using namespace std;


int main(){
    int vertices,edges,a,b;
    long long total=0;
    cin >> vertices >> edges;
    vector<int> graph[vertices+1];
    pair<long long,long long> dp[vertices+1];
    int in[vertices+1]={0};

    for (int i=0;i<edges;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        in[b]+=1;
    }
    for (int i=vertices;i>0;--i){
        if (graph[i].size()==0){
            dp[i]=make_pair(0,1);
        }
        else{
            dp[i]=make_pair(0,0);
            for (auto&&x:graph[i]){
                dp[i].first+=dp[x].first+dp[x].second;
                dp[i].second+=dp[x].second;
                dp[i].first%=1000000007;
                dp[x].second%=1000000007;
            }
        }
        //cout << dp[i].first << " " << dp[i].second << '\n';
        if (in[i]==0){
            total+=dp[i].first;
        }

    }
    cout << total%1000000007 << '\n';


}