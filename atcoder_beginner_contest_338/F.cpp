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

void solve() {
  int N,M;cin>>N>>M;
  vc<vl> A(N,vl(N,LNF));
  rep(i,M){
    int a,b,c;
    cin>>a>>b>>c;
    --a;
    --b;
    cmin(A[a][b],c);
  }
  rep(i,N)A[i][i]=0;
  rep(k,N)rep(i,N)rep(j,N)cmin(A[i][j],A[i][k]+A[k][j]);
  vc<vl>dp(1<<N,vl(N,LNF));
  rep(i,N)dp[1<<i][i]=0;
  rep(s,1<<N){
    rep(i,N){
      if(s>>i&1 && dp[s][i]!=LNF){
        rep(j,N)if(~s>>j&1 && A[i][j]!=LNF){
          int ns=s|(1<<j);
          cmin(dp[ns][j],dp[s][i]+A[i][j]);
        }
      }
    }
  }

  ll ANS=*min_element(all(dp.back()));
  if(ANS==LNF)cout<<"No\n";
  else cout<<ANS<<"\n";
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