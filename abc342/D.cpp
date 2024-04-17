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

map<vector<int>, int> mp;
void solve() {
  int N;
  cin >> N;
  ll ans = 0;
  int zero = 0;
  rep(N) {
    int x;
    cin >> x;
    if (x == 0) {
      zero++;
      continue;
    }
    vi t;
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        int c = 0;
        while (x % j == 0) {
          c++;
          x /= j;
        }
        if (c % 2 == 1) {
          t.pb(j);
        }
      }
    }
    if (x > 1) {
      t.pb(x);
    }
    ans += mp[t]++;
  }
  cout << ans + 1ll * zero * (N - zero) + 1ll * zero * (zero - 1) / 2 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}