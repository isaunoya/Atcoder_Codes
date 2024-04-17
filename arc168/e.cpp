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
  ll n, k, s;
  cin >> n >> k >> s;
  vc<ll> a(n);
  rep(i, n) cin >> a[i];
  vc<ll> S(n+1);
  rep(i, n) S[i + 1] = S[i] + a[i];
  int ptr = 0;
  vi to(n);
  rep(i, n) {
    while (ptr <= n && S[ptr] - S[i] < s) {
      ptr++;
    }
    to[i] = ptr;
  }

  // debug(to);
  ll low = -1e12;
  ll high = 1e12;

  ll ans = 0;
  while (high - low > 1) {
    ll mid = (low + high) / 2;

    vector<pair<ll, int>> dp(n + 1);
    for (int i = 0; i < n; i++) {
      cmax(dp[i + 1], dp[i]);
      int nxt = to[i];
      if (nxt <= n) {
        cmax(dp[nxt], make_pair(dp[i].first - (nxt - i - 1) + mid, dp[i].second + 1));
      }
    }
    vector<pair<ll, int>> d2(n + 1);
    for (int i = 0; i < n; i++) {
      cmax(d2[i + 1], d2[i]);
      int nxt = to[i];
      if (nxt <= n) {
        cmax(d2[nxt], make_pair(d2[i].first - (nxt - i - 1) + mid, d2[i].second - 1));
      }
    }
    assert(dp[n].first == d2[n].first);
    ll l = -d2[n].second;
    ll r = dp[n].second;
    for (int i = r; i >= l; i--) {
      ll rem = n + dp[n].first - i * mid;
      if (rem >= k) {
        cmax(ans, i);
        break;
      }
    }
    ll cur = dp[n].first - r * mid;
    ll rem = n + cur;
    if (rem >= k) {
      cmax(ans, r);
      low = mid;
    } else {
      high = mid;
    }
  }

  cout << min(ans, k) << "\n";
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