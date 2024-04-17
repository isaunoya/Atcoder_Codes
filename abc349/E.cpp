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
  vl a(9);
  for (auto &ai : a) {
    cin >> ai;
  }
  vc<array<int, 3>> p;
  auto get = [&](int id) {
    return make_pair(id / 3, id % 3);
  };

  rep(i, 9) rep(j, i + 1, 9) rep(k, j + 1, 9) {
    auto [xi, yi] = get(i);
    auto [xj, yj] = get(j);
    auto [xk, yk] = get(k);
    if (xi + xk == xj * 2 && yi + yk == yj * 2) {
      p.emplace_back(array<int, 3>{i, j, k});
    }
  }

  ll s = 0;
  vi c(9);
  auto dfs = [&](auto &dfs) -> bool {
    int cnt = 0;
    for (auto &ci : c) {
      ci = -ci;
      if (ci == 0) {
        cnt++;
      }
    }
    bool ans = false;
    rep(i, 9) {
      if (c[i]) continue;
      c[i] = 1;
      for (auto [x, y, z] : p) {
        if (c[x] == 1 && c[y] == 1 && c[z] == 1) {
          ans = true;
        }
      }
      s = a[i] - s;
      if (cnt == 1) {
        ans = s > 0;
      } else if (!dfs(dfs)) {
        ans = true;
      }
      c[i] = 0;
      s = a[i] - s;
    }
    for (auto &ci : c) {
      ci = -ci;
    }
    return ans;
  };
  if (dfs(dfs)) {
    cout << "Takahashi\n";
  } else {
    cout << "Aoki\n";
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