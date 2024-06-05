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

const int P = 998244353;

void solve() {
  int M, N;
  cin >> M >> N;
  vi X(M);
  for (auto &xi : X) {
    cin >> xi;
    --xi;
  }
  vi offset(M);
  for (int i = 0; i < M; i++) {
    offset[X[i]] |= 1 << i;
  }

  vector<vector<int>> f(N + 1, vector<int>(1 << M));

  f[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 1 << M; j++) {
      for (int k = 0; k < M; k++) {
        if (~j >> k & 1) {
          int nj = (j | (1 << k)) & (~(offset[k]));
          f[i + 1][nj] += f[i][j];
          if (f[i + 1][nj] >= P) {
            f[i + 1][nj] -= P;
          }
        }
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < 1 << M; j++) {
    ans += f[N][j];
    if (ans >= P) {
      ans -= P;
    }
  }
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