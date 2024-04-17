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

const int base = 37;

struct monoid {
  array<unsigned long long, 3> a;
  monoid() {
    a[0] = a[1] = 0;
    a[2] = 1;
  }
  monoid(int val) { a = array<unsigned long long, 3>{val, val, base}; }
  unsigned long long &operator[](int x) {
    assert(0 <= x && x < 3);
    return a[x];
  }
};

monoid merge(monoid x, monoid y) {
  monoid z;
  z[0] = x[0] + y[0] * x[2];
  z[1] = x[1] * y[2] + y[1];
  z[2] = x[2] * y[2];
  return z;
}

void solve() {
  int N, Q;
  cin >> N >> Q;
  string s;
  cin >> s;
  vi a(N);
  rep(i, N) a[i] = s[i] - 'a';
  int t = 0;
  while ((1 << t) < N)
    t += 1;
  int M = 1 << t;
  vc<monoid> T(M * 2);
  auto upd = [&](int x, monoid v) {
    x += M;
    T[x] = v;
    while (x >>= 1)
      T[x] = merge(T[x * 2], T[x * 2 + 1]);
  };
  auto query = [&](int l, int r) {
    monoid L, R;
    for (l += M, r += M; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        L = merge(L, T[l++]);
      }
      if (r & 1) {
        R = merge(T[--r], R);
      }
    }
    return merge(L, R);
  };
  rep(i, N) upd(i, monoid(a[i]));
  // debug(T[1][0], T[1][1]);
  while (Q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      char c;
      cin >> x >> c;
      --x;
      a[x] = c - 'a';
      upd(x, monoid(a[x]));
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      auto m = query(l, r);
      auto a = m[0];
      auto b = m[1];
      // debug(a, b);
      if (a == b) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
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