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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
mint dp[1005][1 << 10];
int vis[1 << 10];
void solve() {
  int N, K;
  cin >> N >> K;
  rep(s, 1 << K) {
    vi c;
    rep(i, K) c.pb(s >> i & 1);
    vi d = c;
    reverse(all(d));
    if (c == d)
      vis[s] = 1;
  }
  // rep(i,1<<K)debug(i,vis[i]);
  int MX = (1 << K) - 1;
  dp[0][0] = 1;
  string S;
  cin >> S;
  rep(N) {
    // rep(j,1<<K)if(dp[i][j].val())debug(i,j,dp[i][j].val());
    if (S[i] == 'A' || S[i] == '?') {
      rep(j, 1 << K) {
        int nj = (j << 1) & MX;
        dp[i + 1][nj] += dp[i][j];
      }
    }
    if (S[i] == 'B' || S[i] == '?') {
      rep(j, 1 << K) {
        int nj = (j << 1 | 1) & MX;
        dp[i + 1][nj] += dp[i][j];
      }
    }
    if (i + 1 >= K)
      rep(j, 1 << K) {
        if (vis[j])
          dp[i + 1][j] = 0;
      }
  }
  mint ANS = 0;
  rep(j, 1 << K) ANS += dp[N][j];
  cout << ANS.val() << "\n";
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