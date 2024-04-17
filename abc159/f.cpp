#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
#define eb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  if (x > y)
    x = y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  if (x < y)
    x = y;
}
using ll = long long;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

const int P = 998244353;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  vector<int> dp(m + 1);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i];
    if (x > m) {
      continue;
    }
    for (int j = m; j >= x; j--) {
      dp[j] += dp[j - x];
      if (dp[j] >= P)
        dp[j] -= P;
    }
    (dp[x] += i + 1) %= P;
    ans += (ll)dp[m] * (n - i) % P;
    if (ans >= P) {
      ans -= P;
    }
    dp[m] = 0;
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