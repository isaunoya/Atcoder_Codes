#include <algorithm>
#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
#define rp(i, n) rep(i, 0, n)
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

void solve() {
  int N;
  cin >> N;
  vc<vi> D(N, vi(N));
  rp(i, N) {
    for (int j = i + 1; j < N; j++) {
      cin >> D[i][j];
      D[j][i] = D[i][j];
    }
  }
  int T = 10000000;
  ll ans = 0;
  vi p(N);
  iota(all(p), 0);
  while (T--) {
    ll res = 0;
    shuffle(all(p), rng);
    for (int i = 0; i + 1 < N; i += 2) {
      int x = p[i];
      int y = p[i + 1];
      res += D[x][y];
    }
    cmax(ans, res);
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}