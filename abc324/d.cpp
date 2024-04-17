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
  string s;
  cin >> s;
  vi cnt(10, 0);
  rep(i, n) cnt[s[i] - '0'] += 1;
  debug(cnt);
  vi c(10, 0);
  int ans = 0;
  ll R = pow(10, n);
  for (int i = 0; i <= 3200000; i++) {
    rep(j, 10) c[j] = 0;
    long long x = 1ll * i * i;

    if (x >= R) {
      continue;
    }
    rep(j, n) {
      c[x % 10] += 1;
      x /= 10;
    }
    if (c == cnt) {
      ans += 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
