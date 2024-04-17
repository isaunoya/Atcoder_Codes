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

void solve() {
  int n, q;
  cin >> n >> q;
  vi f(n);
  rep(i, n) f[i] = i;
  vc<ll> w(n, 0);
  vi ans;
  vc<vi> t(n);
  rep(i, n) t[i] = {i};
  rep(i, q) {
    int a, b, d;
    cin >> a >> b >> d;
    --a;
    --b;
    // debug(f[a],f[b]);
    if (f[a] == f[b]) {
      if (w[a] - w[b] == d) {
        ans.pb(i);
      }
    } else {
      ans.pb(i);
      ll wa = w[a];
      ll wb = w[b];
      int sza = t[f[a]].size();
      int szb = t[f[b]].size();
      if (sza < szb) {
        ll dt = wb + d - wa;
        int ff = f[b];
        int ff2 = f[a];
        for (auto x : t[ff2]) {
          f[x] = ff;
          w[x] += dt;
          t[ff].pb(x);
        }
        t[ff2].clear();
      } else {
        ll dt = wa - wb - d;
        int ff = f[a];
        int ff2 = f[b];
        for (auto y : t[ff2]) {
          f[y] = ff;
          w[y] += dt;
          t[ff].pb(y);
        }
        t[ff2].clear();
      }
    }
  }
  for (int x : ans)
    cout << x + 1 << " ";
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