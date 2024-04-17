#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
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

const int N = 2e5 + 5;
int f[N * 2];
int find(int x) {
  if (x == f[x]) {
    return x;
  } else {
    return f[x] = find(f[x]);
  }
}
int sz[N * 2];

const int P = 998244353;
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2 == 1) {
      res = res * x % P;
    }
    x = x * x % P;
    y /= 2;
  }
  return res;
}

long long inverse(long long x) { return power(x, P - 2); }

int ls[N * 2];
int rs[N * 2];

int n;

long long res[N * 2];
void dfs(int x, long long ans) {
  if (x < n) {
    res[x] = ans % P;
    return;
  }
  long long psb = (ll)sz[ls[x]] * inverse(sz[x]) % P;

  debug(sz[ls[x]], sz[x]);
  dfs(ls[x], ans + psb);
  dfs(rs[x], ans + P + 1 - psb);
}
void solve() {
  cin >> n;
  rep(i, 0, n * 2) f[i] = i;
  rep(i, 0, n) sz[i] = 1;
  int cnt = n;
  rep(i, 1, n) {
    int p, q;
    cin >> p >> q;
    --p, --q;
    int pp = find(p);
    int qq = find(q);
    f[pp] = cnt;
    f[qq] = cnt;
    sz[cnt] = sz[pp] + sz[qq];
    ls[cnt] = pp;
    rs[cnt] = qq;
    cnt++;
  }
  dfs(cnt - 1, 0);
  for (int i = 0; i < n; i++) {
    cout << res[i] << " \n"[i + 1 == n];
  }
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