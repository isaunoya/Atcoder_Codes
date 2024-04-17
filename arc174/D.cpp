#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
#include <bits/stdc++.h>
#define debug(...) 42
#define rep1(a) for (auto i = 0; i < a; i++)
#define rep2(i, a) for (auto i = 0; i < a; i++)
#define rep3(i, a, b) for (auto i = a; i < b; i++)
#define rep4(i, a, b, c) for (auto i = a; i < b; i += c)
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
template <typename T> using vc = vector<T>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif

ll ten[11];
void solve() {
  ll N;
  cin >> N;
  ll ans = 0;
  rep(n, 10) {
    rep(d, 3) {
      ll y = ten[n] - d;
      if (y <= 0) {
        continue;
      }
      ll lo = y * y;
      ll hi = (y + 1) * (y + 1) - 1;
      cmax(lo, y * ten[n]);
      cmin(hi, (y + 1) * ten[n] - 1);
      cmin(hi, N);
      if (lo <= hi) {
        ans += hi - lo + 1;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ten[0] = 1;
  rep(i, 10) {
    ten[i + 1] = ten[i] * 10;
  }
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}