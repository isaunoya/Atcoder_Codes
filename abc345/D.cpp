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
  cout << ([]() {
    int N, H, W;
    cin >> N >> H >> W;
    vi A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    bool ok = false;
    vc<vc<bool>> g(H, vector(W, false));
    auto dfs = [&](auto &dfs, int state, int cover) -> void {
      if (ok) {
        return;
      }
      if (cover == H * W) {
        ok = true;
        return;
      }
      int x = cover / W, y = cover % W;
      if (g[x][y]) {
        dfs(dfs, state, cover + 1);
        return;
      }
      rep(i, N) {
        if (state >> i & 1) {
          continue;
        }
        auto [a, b] = make_tuple(A[i], B[i]);
        rep(t, 2) {
          for (int p = x; p < x + a; p++) {
            for (int q = y; q < y + b; q++) {
              if (p == H || q == W || g[p][q]) {
                goto no;
              }
            }
          }
          for (int p = x; p < x + a; p++) {
            for (int q = y; q < y + b; q++) {
              g[p][q] = 1;
            }
          }
          dfs(dfs, state ^ (1 << i), cover + 1);
          for (int p = x; p < x + a; p++) {
            for (int q = y; q < y + b; q++) {
              g[p][q] = 0;
            }
          }
        no:
          swap(a, b);
        }
      }
    };
    return dfs(dfs, 0, 0), ok;
  }()
               ? "Yes"
               : "No")
       << "\n";
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