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

#include <atcoder/segtree>
using S = ll;
S op(S a, S b) { return max(a, b); }
S e() { return -LNF; }

void solve() {
  ll N, C;
  cin >> N >> C;
  atcoder::segtree<S, op, e> st1(N), st2(N);
  st1.set(0, 0);
  st2.set(0, 0);
  int M;
  cin >> M;
  // dp[t] = max(dp[x]-(t-x)*C+P), t>=x
  // dp[t] = max(dp[x]-(x-t)*C+P), t<=x
  ll ANS = 0;
  while (M--) {
    ll T, P;
    cin >> T >> P;
    --T;
    ll ans = -LNF;
    cmax(ans, st1.prod(0, T) - T * C + P);
    cmax(ans, st2.prod(T, N) + T * C + P);
    // debug(ans);
    cmax(ANS, ans);
    st1.set(T, ans + T * C);
    st2.set(T, ans - T * C);
  }
  cout << ANS << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}