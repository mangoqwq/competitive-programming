#include <iostream>

using namespace std;


int x[8]={14,1,2,4,7,8,11,13};

int main(){
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    int N; cin >> N;
    cout << ((N-1)/8)*15+x[N%8] << '\n';

}
