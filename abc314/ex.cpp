#include <bits/stdc++.h>
#include <iomanip>
#ifndef LOCAL
#define debug(...) 42
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
#define rp(i, N) rep(i, 0, N)
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
template <class T> using vc = vector<T>;

void solve() {
  int N;
  cin >> N;
  vc<array<double, 4>> seg(N);
  rp(i, N) rp(j, 4) cin >> seg[i][j];
  using sg = array<double, 4>;
  using pt = array<double, 2>;
  auto dis = [&](pt A, pt B) -> double {
    auto [x, y] = A;
    auto [z, w] = B;
    return sqrt(pow(x - z, 2) + pow(y - w, 2));
  };
  auto dis1 = [&](sg A, pt B) -> double {
    auto [a, b, c, d] = A;
    auto [x, y] = B;
    if ((c - a) * (x - a) + (d - b) * (y - b) < 0)
      return dis(pt{a, b}, pt{x, y});
    swap(a, c), swap(b, d);
    if ((c - a) * (x - a) + (d - b) * (y - b) < 0)
      return dis(pt{a, b}, pt{x, y});
    return abs((c - a) * (y - b) - (x - a) * (d - b)) / dis(pt{a, b}, pt{c, d});
  };
  auto minimize = [&](const pt &p) -> double {
    double res = 0.0;
    for (auto s : seg)
      cmax(res, dis1(s, p));
    return res;
  };
  const double eps = 1e-9;
  auto minimize_function = [&](double L, double R, auto &&function) {
    while (R - L > eps) {
      double M1 = (L * 2 + R) / 3.;
      double M2 = (L + R * 2) / 3.;
      if (function(M1) < function(M2)) {
        R = M2;
      } else {
        L = M1;
      }
    }
    return function(L);
  };
  cout << fixed << setprecision(10) << minimize_function(0, 1000, [&](auto x) {
    return minimize_function(0, 1000, [&](auto y) {
      return minimize(pt{x, y});
    });
  }) << "\n";
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