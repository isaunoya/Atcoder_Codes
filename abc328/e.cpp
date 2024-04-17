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

unordered_map<ll, bool> mp[1 << 8];
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vc<array<ll, 3>> e(m);
  rep(i, m) {
    ll x, y, z;
    cin >> x >> y >> z;
    --x;
    --y;
    e[i] = array<ll, 3>{x, y, z};
  }
  rep(i, n) mp[1 << i][0] = 1;
  rep(s, 1 << n) {
    rep(i, m) {
      auto [x, y, z] = e[i];
      if (s >> x & 1) {
        if (~s >> y & 1) {
          int ns = s | (1 << y);
          for (auto [t, b] : mp[s]) {
            mp[ns][(t + z) % k] = 1;
          }
        }
      }
      swap(x, y);
      if (s >> x & 1) {
        if (~s >> y & 1) {
          int ns = s | (1 << y);
          for (auto [t, b] : mp[s]) {
            mp[ns][(t + z) % k] = 1;
          }
        }
      }
    }
  }
  ll mn = k - 1;
  int ed = 1 << n;
  --ed;
  for (auto [t, b] : mp[ed]) {
    cmin(mn, t);
  }

  cout << mn << "\n";
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