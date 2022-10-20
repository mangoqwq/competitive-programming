#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
	string src = "";
	string tmp; getline(cin, tmp);
	map<string, vector<string>> adj;
	map<string, int> dist;
	for (int i = 0; i < N; ++i){
		string line;
		getline(cin, line);
		istringstream iss(line);
		string to; iss >> to;
		if (src == "") src = to;
		dist[to] = 1e9;
		string allows, travellers, from;
		iss >> allows >> travellers >> from;
		while (iss >> from){
			dist[from] = 1e9;
			adj[from].push_back(to);
		}
	}
	queue<string> q;
	q.push(src);
	dist[src] = 1;
	while (!q.empty()){
		string v = q.front(); q.pop();
		for (string to : adj[v]){
			if (dist[to] > dist[v] + 1){
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}
	for (auto [s, d] : dist){
		cout << (d == 1e9 ? 0 : d) << '\n';
	}
}
