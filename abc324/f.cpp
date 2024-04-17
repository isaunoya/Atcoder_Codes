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

const double eps = 1e-10;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<array<int, 4>> e(m);
  rep(i, m) {
    int u, v, b, c;
    cin >> u >> v >> b >> c;
    --u;
    --v;
    e[i] = array<int, 4>{u, v, b, c};
  }
  sort(all(e));
  double l = 0., r = 10000.;
  while (r - l > eps) {
    double mid = (l + r) / 2.;
    vc<double> dp(n, -inf);
    dp[0] = 0;
    int j = 0;
    rep(i, n) {
      while (j < m && e[j][0] == i) {
        int k = e[j][1];
        double value = e[j][2] - e[j][3] * mid;
        cmax(dp[k], dp[i] + value);
        j += 1;
      }
    }
    if (dp.back() >= 0) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(10) << l << "\n";
  return 0;
}
