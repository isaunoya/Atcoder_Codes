#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
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
  int n, d;
  cin >> n >> d;
  int tar = n * n * d / 2;
  int a[n][n], b[n][n];
  rep(i, n) rep(j, n) cin >> a[i][j], a[i][j] += 1000;
  rep(rot, 2) {
    rep(i, n) rep(j, n) {
      int D = d * 2;
      int down = a[i][j] / D * D;
      int up = down + D;
      if ((i + j) % 2 == rot) {
        if (abs(down - a[i][j]) < abs(up - a[i][j])) {
          b[i][j] = down;
        } else {
          b[i][j] = up;
        }
      } else {
        b[i][j] = down + d;
      }
    }
    int sum = 0;
    rep(i, n) rep(j, n) sum += abs(a[i][j] - b[i][j]);
    if (sum <= tar) {
      rep(i, n) rep(j, n) { cout << b[i][j] - 1000 << " \n"[j + 1 == n]; }
      return;
    }
  }
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