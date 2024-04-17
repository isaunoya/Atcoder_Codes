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
  int N;
  cin>>N;
  vc<vi>g(N);
  rep(i,N-1){
    int x,y;
    cin>>x>>y;
    --x;
    --y;
    g[x].pb(y);
    g[y].pb(x);
  }
  vi c(N),d(N);
  rep(i,N){
    cin>>c[i];
  }
  vl s(N);
  auto dfs = [&](auto &dfs,int u,int p)->void{
    s[u]=c[u];
    for(auto v:g[u])if(v!=p)d[v]=d[u]+1,dfs(dfs,v,u),s[u]+=s[v];
  };
  dfs(dfs,0,-1);
  vl f(N,0);
  rep(i,N)f[0]+=1ll*c[i]*d[i];
  auto dfs2=[&](auto &dfs2,int u,int p)->void{
    for(auto v:g[u])if(v!=p){
      f[v]=f[u]+s[0]-2*s[v];
      dfs2(dfs2,v,u);
    }
  };
  dfs2(dfs2,0,-1);
  cout<<*min_element(all(f))<<"\n";
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