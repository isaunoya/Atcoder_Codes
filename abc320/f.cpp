#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...)
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


template <class... T> void read() {}
template <class T> void read(T &x) { cin >> x; }
template <class T, class S> void read(pair<T, S> &v) {
  read(v.first, v.second);
}
template <class T> void read(vector<T> &v) {
  for (T &x : v)
    read(x);
}
template <class T, class... Ts> void read(T &a, Ts &...b) {
  read(a), read(b...);
}

void solve() {
  int N, H;
  cin >> N >> H;
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i];
  }
  int lst = 0;
  vector<vector<int>> dp(H + 1, vector<int>(H + 1, 0));
  for (int i = 0; i < N; i++) {
    int d = X[i] - lst;
    lst = X[i];

    vector<vector<int>> g(H + 1, vector<int>(H + 1, inf));
    for (int x = d; x <= H; x++) {
      for (int y = d; y <= H; y++) {
        cmin(g[x - d][y], dp[x][y - d]);
      }
    }
    dp = move(g);
    if (i < N - 1) {
      int P, F;
      cin >> P >> F;
      g = dp;
      for (int x = 0; x <= H; x++) {
        for (int y = 0; y <= H; y++) {
          cmin(g[min(x + F, H)][y], dp[x][y] + P);
          cmin(g[x][y], dp[x][min(y + F, H)] + P);
        }
      }
      dp = move(g);
    }
  }
  int ans = inf;
  for (int i = 0; i <= H; i++) {
    cmin(ans, dp[i][i]);
  }

  cout << (ans == inf ? -1 : ans) << "\n";
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