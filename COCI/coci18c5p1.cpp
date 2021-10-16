#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 31;

struct Time{
    int hour, minute, second, milisecond;
    Time() = default;
    Time(string s){
        hour = stoi(s.substr(0, 2));
        minute = stoi(s.substr(3, 2));
        second = stoi(s.substr(6, 2));
        milisecond = stoi(s.substr(9, 3));
    }
    void inc(int t){
        milisecond += t;
        while (milisecond >= 1000){
            milisecond -= 1000;
            second++;
        }
        while (second >= 60){
            second -= 60;
            minute++;
        }
        while (minute >= 60){
            minute -= 60;
            hour++;
        }
        while (milisecond < 0){
            milisecond += 1000;
            second--;
        }
        while (second < 0){
            second += 60;
            minute--;
        }
        while (minute < 0){
            minute += 60;
            hour--;
        }
    }
    void print(){
        printf("%02d:%02d:%02d,%03d", hour, minute, second, milisecond);
    }
};
int num[MN];
Time starting[MN], ending[MN];
vector<string> talk[MN];
int T;

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    string ln;
    while (true){
        ++T;
        cin >> num[T];
        string a, b; cin >> a >> ln >> b;
        starting[T] = Time(a); ending[T] = Time(b);
        getline(cin, ln);
        while (true){
            getline(cin, ln);
            talk[T].push_back(ln);
            if (ln == "" || ln == "#"){
                break;
            }
        }
        if (ln == "#") break;
    }
    int t; cin >> t;
    for (int i = 1; i <= T; ++i){
        starting[i].inc(t);
        ending[i].inc(t);
        printf("%d\n", num[i]);
        starting[i].print();
        printf(" --> ");
        ending[i].print();
        printf("\n");
        for (string s : talk[i]){
            cout << s << '\n';
        }
    }
}
