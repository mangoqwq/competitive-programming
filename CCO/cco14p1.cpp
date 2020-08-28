#include <bits/stdc++.h>

using namespace std;
char grid[2001][2001];
int val[2001][2001];

int f(int x){return (x+1)/2;}

int main(){
    int n; cin >> n;
    for (int x=1;x<n+1;++x){
        for (int y=1;y<n+1;++y){
            cin >> grid[x][y];
        }
    }
    int troyangles=0;
    int count=0;
    for (int x=1;x<n+1;++x){
        count=0;
        for (int y=1;y<n+1;++y){
            if (grid[x][y]=='#'){
                count++;
                val[x][y]=min(f(count),val[x-1][y-1]+1);
                troyangles+=val[x][y];
            }
            else{
                count=0;
            }
        }
    }
    cout << troyangles << '\n';
}