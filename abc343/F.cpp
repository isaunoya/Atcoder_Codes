#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
#include <bits/stdc++.h>
#define debug(...) 42
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
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
template<class T> using vc = vector<T>;
#endif

struct number {
  int x, c;
  number() { x = 0, c = 0; }
  number(int X) { x = X, c = 1; }
  number(int X, int C) { x = X, c = C; }
};

using node = array<number, 2>;
void solve() {
  int N, Q;
  cin >> N >> Q;

  vi A(N);
  rep(i, N) cin >> A[i];

  vc<node> T(N * 2);
  auto merge = [&](node x, node y) {
    vi v;
    for (auto X : x) {
      v.pb(X.x);
    }
    for (auto X : y) {
      v.pb(X.x);
    }
    sort(all(v), greater<>());
    v.resize(unique(all(v)) - v.begin());

    int mx = v[0];
    int nmx = v[1];

    int c0 = 0;
    int c1 = 0;

    for (auto X : x) {
      if (X.x == mx) {
        c0 += X.c;
      } else if (X.x == nmx) {
        c1 += X.c;
      }
    }

    for (auto X : y) {
      if (X.x == mx) {
        c0 += X.c;
      } else if (X.x == nmx) {
        c1 += X.c;
      }
    }

    return array<number, 2>{number(mx, c0), number(nmx, c1)};
  };

  auto query = [&](int l, int r) {
    array<number, 2> res;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        res = merge(res, T[l++]);
      }
      if (r & 1) {
        res = merge(res, T[--r]);
      }
    }
    return res;
  };

  for (int i = N - 1; i >= 0; i--) {
    T[i] = merge(T[i * 2], T[i * 2 + 1]);
  }


  auto update = [&](int x, int v) {
    x += N, T[x] = array<number, 2>{number(v, 1), number()};
    while (x >>= 1) {
      T[x] = merge(T[x * 2], T[x * 2 + 1]);
    }
  };

  rep(i, N) {
    update(i, A[i]);
  }
  rep(q, Q) {
    int op;
    cin >> op;
    if (op == 1) {
      int p, x;
      cin >> p >> x;
      --p;
      A[p] = x;
      update(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      cout << query(l, r)[1].c << "\n";
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