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

void solve() {
  int N;
  cin >> N;
  string s;
  cin >> s;
  vi c(N);
  rep(i, N) {
    cin >> c[i];
  }
  vector<array<ll, 2>> pref(N + 1);
  vector<array<ll, 2>> suf(N + 1);
  rep(i, N) {
    pref[i + 1] = pref[i];
    if (s[i] - '0' != i % 2) {
      pref[i + 1][0] = pref[i][0] + c[i];
    } else {
      pref[i + 1][1] = pref[i][1] + c[i];
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    suf[i] = suf[i + 1];
    if (s[i] - '0' != i % 2) {
      suf[i][0] = suf[i + 1][0] + c[i];
    } else {
      suf[i][1] = suf[i + 1][1] + c[i];
    }
  }
  ll ans = LNF;
  for (int i = 0; i + 1 < N; i++) {
    for (int j = 0; j < 2; j++) {
      ll cost = 0;
      if (s[i] - '0' != (i + j) % 2) {
        cost += c[i];
      }
      if (s[i + 1] - '0' != (i + j) % 2) {
        cost += c[i + 1];
      }
      cmin(ans, cost + pref[i][j] + suf[i + 2][j ^ 1]);
    }
  }
  cout << ans << "\n";
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