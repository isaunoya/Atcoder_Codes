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

#include <atcoder/convolution>

using namespace atcoder;
using mint = modint998244353;
void solve() {
  int K;
  cin >> K;
  vc<mint> fact(K + 1);
  vc<mint> inv(K + 1);
  fact[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= K; i++) {
    fact[i] = fact[i - 1] * i;
    inv[i] = 1 / fact[i];
  }
  vi C(26);
  for (int i = 0; i < 26; i++) {
    int x;
    cin >> x;
    C[i] = int(x);
  }
  vc<vc<mint>> f(26);
  for (int i = 0; i < 26; i++) {
    int L = min(C[i], K);
    f[i].resize(L + 1);
    for (int j = 0; j <= L; j++) {
      f[i][j] = inv[j];
    }
  }

  vc<mint> ans(K + 1);
  ans[0] = 1;
  for (int i = 0; i < 26; i++) {
    ans = convolution(ans, f[i]);
  }
  mint ANS = 0;
  for (int i = 1; i <= K; i++) {
    ANS += ans[i] * fact[i];
  }
  cout << ANS.val() << "\n";
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