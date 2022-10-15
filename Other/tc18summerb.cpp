#include <iostream>
using namespace std;
int c, d, e;

int main(){
    cin >> c >> d >> e;
    if ((c ^ d) != e) cout << 0;
    else cout << (1<<__builtin_popcount(e));
    return 0;
}