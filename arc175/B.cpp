#include <cstdint>
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

void solve() {
  int N, A, B;
  cin >> N >> A >> B;
  cmin(A, B * 2);
  string S;
  cin >> S;
  int a = 0, b = 0;
  rep(i, N * 2) {
    if (S[i] == '(')
      a++;
    else
      b++;
  }
  ll ans = 0;
  if (a > N) {
    for (int i = N * 2 - 1; i >= 0 && a > N; i--)
      if (S[i] == '(')
        S[i] = ')', a--, b++, ans += B;
  } else {
    for (int i = 0; i < N * 2 && b > N; i++)
      if (S[i] == ')')
        S[i] = '(', b--, a++, ans += B;
  }
  assert(a == N && b == N);
  int j = N * 2 - 1;
  int cur = 0;
  for (int i = 0; i < N * 2; i++) {
    cur += S[i] == '(' ? 1 : -1;
    while (j >= 0 && S[j] == '(') {
      j -= 1;
    }
    if (cur == -1) {
      cur += 2;
      swap(S[i], S[j]);
      ans += A;
    }
  }

  cout << ans << "\n";
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