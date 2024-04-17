#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
#define rp(i, n) rep(i, 0, n)
#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
using ll = long long;
using vi = vector<ll>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

void solve() {
  int N;
  cin >> N;
  vi X(N), L(N);
  rp(i, N) cin >> X[i];
  rp(i, N) cin >> L[i];
  vi p;
  rp(i, N) rp(j, N) {
    p.pb(X[i] - L[j]);
    p.pb(X[i] + L[j]);
    p.pb(X[i] - L[j] - 1);
    p.pb(X[i] + L[j] + 1);
  }
  sort(all(p));
  p.resize(unique(all(p)) - begin(p));
  auto check = [&](ll pos) {
    vi c;
    for (int i = 0; i < N; i++) {
      c.pb(abs(X[i] - pos));
    }
    sort(all(c));
    for (int i = 0; i < N; i++) {
      if (c[i] > L[i]) {
        return false;
      }
    }
    return true;
  };
  ll ans = 0;
  vi ok(p.size());
  for (int i = 0; i < p.size(); i++) {
    ok[i] = check(p[i]);
  }
  for (int i = 0, j; i < p.size(); i = j + 1) {
    j = i;
    if (!ok[i]) {
      continue;
    }
    debug(i, p[i]);
    while (j < p.size() && ok[j]) {
      j += 1;
    }
    debug(p[j], p[i]);
    ans += p[j] - p[i];
  }
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