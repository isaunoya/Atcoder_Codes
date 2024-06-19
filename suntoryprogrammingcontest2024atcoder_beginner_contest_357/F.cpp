#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
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
template <typename T> using vc = vector<T>;
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
#endif

#include <atcoder/lazysegtree>
#include <atcoder/modint>
using mint = atcoder::modint998244353;

using S = array<mint, 4>;
using F = array<mint, 2>;
S e() { return S{0, 0, 0, 0}; }
S op(S a, S b) {
  S c;
  rep(4) c[i] = a[i] + b[i];
  return c;
}

S mapping(F add, S a) {
  S c = a;
  c[2] += add[0] * c[1] + add[1] * c[0] + add[0] * add[1] * c[3];
  c[0] += add[0] * c[3];
  c[1] += add[1] * c[3];
  return c;
}

F composition(F a, F b) {
  F c;
  rep(2) c[i] = a[i] + b[i];
  return c;
}
F id() { return F{0, 0}; }
void solve() {
  int N, Q;
  cin >> N >> Q;
  vi A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vi B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  vc<S> a(N);
  for (int i = 0; i < N; i++) {
    a[i] = S{A[i], B[i], 1ll * A[i] * B[i] % 998244353, 1};
  }
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> st(a);
  while (Q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      st.apply(l, r, {x, 0});
    } else if (op == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      st.apply(l, r, {0, x});
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      cout << st.prod(l, r)[2].val() << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}