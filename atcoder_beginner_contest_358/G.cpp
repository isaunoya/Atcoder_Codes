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
  ll h, w, k;
  cin >> h >> w >> k;
  ll si, sj;
  cin >> si >> sj;
  --si, --sj;

  vc<vl> A(h, vl(w));
  rep(i, h) rep(j, w) cin >> A[i][j];

  int tot = min(h * w, k);
  ll dp[tot + 1][h][w];
  memset(dp, 0xcf, sizeof dp);
  dp[0][si][sj] = 0;

  rep(t, tot) {
    rep(i, h) {
      rep(j, w) {
        rep(dx, -1, 2) rep(dy, -1, 2) {
          if (abs(dx) + abs(dy) <= 1) {
            int a = i + dx;
            int b = j + dy;
            if (0 <= a && a < h && 0 <= b && b < w) {
              cmax(dp[t + 1][a][b], dp[t][i][j] + A[a][b]);
            }
          }
        }
      }
    }
  }

  ll ans = 0;
  rep(i, h) rep(j, w) { cmax(ans, dp[tot][i][j] + (k - tot) * A[i][j]); }

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