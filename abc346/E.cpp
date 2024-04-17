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
  int H, W, M;
  cin >> H >> W >> M;
  vector<tuple<int, int, int>> q(M);
  for (auto &[x, y, z] : q) {
    cin >> x >> y >> z;
    --x, --y;
  }
  vi ban_0(H), ban_1(W);
  map<int, ll> ans;
  vector<set<int>> t(2);
  for (int i = M - 1; i >= 0; i--) {
    auto [x, y, z] = q[i];
    if (x == 0) {
      if (ban_0[y]) {
        continue;
      }
      if (W - t[1].size())
        ans[z] += W - t[1].size();
      t[0].emplace(y);
      ban_0[y] = 1;
    } else {
      if (ban_1[y]) {
        continue;
      }
      if (H - t[0].size())
        ans[z] += H - t[0].size();
      t[1].emplace(y);
      ban_1[y] = 1;
    }
  }
  ll all = 0;
  for (auto [x, y] : ans) {
    if (x != 0)
      all += y;
  }
  if (1ll * H * W != all)
    ans[0] = 1ll * H * W - all;
  cout << ans.size() << "\n";
  for (auto [x, y] : ans) {
    cout << x << " " << y << "\n";
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