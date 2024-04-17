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

void solve() {
  int N;
  cin >> N;
  vi A(N);
  rp(i, N) cin >> A[i], --A[i];
  // ll ans = 0;
  // rp(i, N) rep(j, i + 1, N) rep(k, j + 1, N){
  //   if (A[i] == A[k] && A[i] != A[j])
  //     ans += 1;
  // }
  // debug(ans);

  vc<vi> v(N);
  ll ans = 0;
  rp(i, N) v[A[i]].pb(i);
  rp(val, N) {
    int cnt = 0;
    ll sum = 0;
    for (int x : v[val]) {
      ans += 1LL * (x - 1) * cnt - sum;
      sum += x;
      cnt += 1;
    }
  }
  vc<ll> C3(N + 1);
  for (int i = 3; i <= N; i++) {
    C3[i] = 1LL * i * (i - 1) * (i - 2) / 6;
  }
  rp(val, N) {
    ans -= C3[sz(v[val])];
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