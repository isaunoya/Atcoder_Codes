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

#include <atcoder/modint>
using mint = atcoder::modint1000000007;
void solve() {
  int N; string S;
  cin >> N >> S;
  vi A(N);
  rep(i, N) A[i] = S[i] - 'A';
  rep(i, N) if (i % 2 == 1) A[i] ^= 1;

  mint ans = 1;

  for (int i = 0, j = 0; i < N; i = j) {
    while (j < N && A[i] == A[j]) {
      j += 1;
    }
    int len = j - i;
    // if (len == 1) {
    //   continue;
    // } else if (len == 2) {
    //   continue;
    // } else if (len == 3) {
    //   ans *= 2;
    // } else if (len == 4) {
    //   ans *= 2;
    // }

    ans *= (len + 1) / 2;
  }

  cout << ans.val() << "\n";
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