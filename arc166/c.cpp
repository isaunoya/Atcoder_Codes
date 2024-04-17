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

const int N = 2048576;
int fib[N];
const int P = 998244353;
int pre[N];

int power(int x, int y) {
  int r = 1;
  while (y) {
    if (y % 2 == 1) {
      r = 1ll * r * x % P;
    }
    y /= 2;
    x = 1ll * x * x % P;
  }
  return r;
}

void solve() {
  int h, w;
  cin >> h >> w;
  if (h > w) {
    swap(h, w);
  }
  cout << 1ll * pre[h] * pre[h] % P * power(fib[2 * h + 1], w - h) % P << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  fib[0] = 1;
  fib[1] = 1;
  rep(i, 2, N) {
    fib[i] = fib[i - 1] + fib[i - 2];
    if (fib[i] >= P) {
      fib[i] -= P;
    }
  }
  pre[0] = 1;
  rep(i, 1, N / 2) {
    pre[i] = 1ll * pre[i - 1] * fib[i * 2] % P;
  }
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}