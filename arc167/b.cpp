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

const int P = 998244353;
void solve() {
  ll A, B;
  cin >> A >> B;
  vc<pair<ll,ll>> fac;
  for (int i = 2; i <= sqrt(A); i++) {
    if (A % i == 0) {
      int c = 0;
      while (A % i == 0) {
        A /= i;
        c += 1;
      }
      fac.pb(i, c);
    }
  }
  if (A > 1) {
    fac.pb(A, 1);
  }
  B %= P;
  ll ans = B;
  bool all_odd = B % 2;
  for (auto [x, y] : fac) {
    ans = 1ll * ans * (1ll * y * B % P + 1) % P;
    all_odd &= (y % 2 * B + 1) % 2;
  }
  if (all_odd) {
    ans--;
  }
  ans = 1ll * ans * ((P + 1) / 2) % P;
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