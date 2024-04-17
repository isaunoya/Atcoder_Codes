#include <algorithm>
#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
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
  int h, w;
  cin >> h >> w;
  vc<vi> a(h, vi(w));

  rep(i, h) rep(j, w) cin >> a[i][j];

  vc<vi> b(h, vi(w));
  rep(i, h) rep(j, w) cin >> b[i][j];

  vi p1(h);
  iota(all(p1), 0);
  int ans = 1e9;
  do {
    vi p2(w);
    iota(all(p2), 0);
    do {

      bool match = 1;
      rep(i, h) rep(j, w) match &= (a[p1[i]][p2[j]] == b[i][j]);

      if (match) {
        int cnt = 0;
        rep(i, h) rep(j, i + 1, h) cnt += (p1[i] > p1[j]);
        rep(i, w) rep(j, i + 1, w) cnt += (p2[i] > p2[j]);
        cmin(ans, cnt);
      }
    } while (next_permutation(all(p2)));
  } while (next_permutation(all(p1)));

  if (ans == 1e9)
    ans = -1;

  cout << ans << "\n";
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