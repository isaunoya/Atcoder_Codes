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


int n, m;
int dp[505][505];
bool cov[505][505][505];
void solve() {
  cin >> n >> m;
  while (m--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    for (int i = l; i <= r; i++) {
      cov[i][l][r] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int l = i; l >= 0; l--) {
      for (int r = i; r < n; r++) {
        if (cov[i][l][r]) {
          if (l > 0) {
            cov[i][l - 1][r] = 1;
          }
          if (r + 1 < n) {
            cov[i][l][r + 1] = 1;
          }
        }
      }
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      for (int k = i; k <= j; k++) {
        if (cov[k][i][j]) {
          cmax(dp[i][j], 1 + dp[i][k - 1] + dp[k + 1][j]);
        }
      }
    }
  }
  int ans = 0;
  rep(i, n) rep(j, n) cmax(ans, dp[i][j]);
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