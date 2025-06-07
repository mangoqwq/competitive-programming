#include <bits/stdc++.h>

#ifdef _DEBUG
#include <utils/debug.h>
#else
#define debug(...) 0
#endif

using namespace std;

void send_message(std::vector<bool> M, std::vector<bool> C);
std::vector<bool> send_packet(std::vector<bool> A);
std::vector<bool> receive_message(std::vector<std::vector<bool>> R);

const int N = 31;

void send_message(vector<bool> M, vector<bool> C) {
  int S = 1025;
  M.push_back(1);
  while ((int)M.size() < S) M.push_back(0);
  int remain = S;
  auto putchar = [&]() -> bool {
    if (remain == 0) return 0;
    return M[--remain];
  };
  vector<int> nxt(N);
  int lst = 0;
  for (int i = 0; i < 2*N-1; ++i) {
    if (!C[i % N]) {
      nxt[lst % N] = (i - lst + N) % N;
      lst = i;
    }
  }

  vector<bool> A(N);
  for (int it = 0; it < 66; ++it) {
    for (int i = 0; i < N; ++i) {
      if (C[i]) continue;
      if (it < nxt[i]-1) A[i] = 0;
      else if (it == nxt[i]-1) A[i] = 1;
      else A[i] = putchar();
    }
    send_packet(A);
  }
}

vector<bool> receive_message(vector<vector<bool>> R) {
  vector<int> nxt(N);
  for (int i = 0; i < N; ++i) {
    for (int it = 0; it < 66; ++it) {
      if (R[it][i] == 1) { nxt[i] = it + 1; break; }
    }
  }
  vector<int> C(N, 1);
  for (int src = 0; src < N; ++src) {
    set<int> seq;
    int v = src;
    for (int i = 0; i < 16; ++i) {
      seq.insert(v); v = (v + nxt[v]) % N;
    }
    if (v == src && seq.size() == 16) {
      for (int x : seq) C[x] = 0;
      break;
    }
  }
  vector<bool> msg;
  for (int it = 0; it < 66; ++it) {
    for (int i = 0; i < N; ++i) {
      if (it <= nxt[i]-1) continue;
      if (C[i]) continue;
      msg.push_back(R[it][i]);
    }
  }
  reverse(msg.begin(), msg.end());
  while (true) {
    int x = msg.back(); msg.pop_back();
    if (x == 1) break;
  }
  return msg;
}
