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

void solve() {}

int main() {
  int n;
  cin >> n;
  string t;
  cin >> t;
  vi pref, suf;
  debug(t);
  rep(i, n) {
    string s;
    cin >> s;
    int m = sz(s);
    int k = 0;
    rep(j, m) {
      if (k < sz(t) && s[j] == t[k]) {
        k += 1;
      }
    }
    pref.pb(k);
    k = sz(t) - 1;
    for (int j = m - 1; j >= 0; j--) {
      if (k >= 0 && s[j] == t[k]) {
        k -= 1;
      }
    }
    suf.pb(k);
  }
  debug(pref, suf);
  int m = sz(t);
  vi cnt(m + 2, 0);
  for (auto x : suf) {
    cnt[x + 1] += 1;
  }
  rep(i, 1, m + 2) cnt[i] += cnt[i - 1];
  ll ans = 0;
  for (auto x : pref) {
    ans += cnt[x];
  }
  cout << ans << "\n";
  return 0;
}
