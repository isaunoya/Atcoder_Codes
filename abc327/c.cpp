#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep1(a) for (int i = 0; i < a; i++)
#define rep2(i, a) for (int i = 0; i < a; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
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
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second

int a[10][10];
const int full = 511;
void solve() {
  rep(i, 9) rep(j, 9) cin >> a[i][j], --a[i][j];
  bool ok = true;
  rep(i, 9) {
    int u = 0;
    rep(j, 9) u |= 1 << a[i][j];
    if (u ^ full)
      ok = false;
  }
  rep(j, 9) {
    int u = 0;
    rep(i, 9) u |= 1 << a[i][j];
    if (u ^ full)
      ok = false;
  }
  rep(i, 3) {
    rep(j, 3) {
      int u = 0;
      rep(k1, 3) {
        rep(k2, 3) { u |= 1 << a[i * 3 + k1][j * 3 + k2]; }
      }
      if (u ^ full) {
        ok = false;
      }
    }
  }
  if (ok) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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