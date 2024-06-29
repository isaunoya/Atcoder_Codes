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
using mint = atcoder::modint1000000007;

const int N = 100;
const int M = 10;
const int shift = N * M;

int n, A[N], lst[21];
mint dp[N + 1][shift * 2 + 1], f[shift * 2 + 1];

void solve() {
  cin >> n;
  rep(n) cin >> A[i];
  memset(lst, -1, sizeof lst);

  mint ANS = 1;
  rep(i, n) {
    rep(k, shift * 2 + 1) if (k != shift) {
      dp[i][k] = f[k];
      ANS += dp[i][k];
    }
    rep(j, lst[A[i] + 11], i) {
      if (j >= 0) {
        f[A[i] + shift] += dp[j][-A[j] + shift];
      } else {
        f[A[i] + shift] += 1;
      }
    }
    lst[A[i] + 11] = i;
    rep(k, shift * 2 + 1) if (k != shift && 0 <= -A[i] + k &&
                              -A[i] + k <= shift * 2) {
      f[k] += dp[i][-A[i] + k];
    }
  }

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