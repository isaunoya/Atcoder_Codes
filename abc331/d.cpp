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
  int N, Q;
  cin >> N >> Q;
  vc<vi> a(N, vi(N));
  rep(i, N) {
    string s;
    cin >> s;
    rep(j, N) a[i][j] = (s[j] == 'B');
  }
  // debug(a);
  vc<vi> s(N + 1, vi(N + 1));
  rep(i, N) { rep(j, N) s[i + 1][j + 1] = s[i + 1][j] + a[i][j]; }
  rep(j, N + 1) { rep(i, N) s[i + 1][j] += s[i][j]; }
  auto query = [&](int a, int b, int c, int d) {
    // [a, c) [b, d)
    return s[c][d] - s[c][b] - s[a][d] + s[a][b];
  };
  auto F = [&](ll x, ll y) {
    long long ANS = 0;
    long long full_x = x / N;
    long long full_y = y / N;
    long long rem_x = x - full_x * N;
    long long rem_y = y - full_y * N;
    ANS += query(0, 0, N, N) * full_x * full_y;
    ANS += query(0, 0, rem_x, N) * full_y;
    ANS += query(0, 0, N, rem_y) * full_x;
    ANS += query(0, 0, rem_x, rem_y);
    return ANS;
  };
  debug(F(N, N));
  while (Q--) {
    ll ANS = 0;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    c += 1;
    d += 1;
    ANS = F(c, d) - F(c, b) - F(a, d) + F(a, b);
    cout << ANS << "\n";
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