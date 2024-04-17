#include <atcoder/maxflow>
#include <bits/stdc++.h>

#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep1(a) for (int i = 0; i < a; i++)
#define rep2(i, a) for (int i = 0; i < a; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
const int INF = 1000000000;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  vector<int> A(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i];
  }
  vector<vector<int>> L(M, vector<int>(N));
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> L[i][j];
    }
  }
  atcoder::mf_graph<int> G(N * 4 + M + 2);
  int s = N * 4 + M;
  int t = N * 4 + M + 1;
  for (int i = 0; i < N * 4; i++) {
    G.add_edge(s, i, C[i / 4]);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      G.add_edge(i * 4 + j, i * 4 + j + 1, INF);
    }
  }
  for (int i = 0; i < M; i++) {
    G.add_edge(N * 4 + i, t, A[i]);
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (L[i][j] >= 2) {
        G.add_edge(j * 4 + L[i][j] - 2, N * 4 + i, INF);
      }
    }
  }
  int ans = G.flow(s, t);
  for (int i = 0; i < M; i++) {
    ans -= A[i];
  }
  cout << -ans << endl;
}