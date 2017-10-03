/*
 * =====================================================================================
 *
 *       Filename:  1236.cpp
 *        Version:  1.0
 *        Created:  07/27/2013 12:11:06 AM
 *       Revision:  none
 *       Compiler:  GNU C++
 *
 *      Just like you,wait you forever~~
 *
 * =====================================================================================
 */
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB             push_back
#define SIZE(x)        (int)x.size()
#define clr(x,y)       memset(x,y,sizeof(x))
#define MP(x,y)        make_pair(x,y)
#define RII(x,y)       scanf ("%d%d", &(x), &(y))
#define RIII(x,y,z)    scanf ("%d%d%d", &(x), &(y), &(z))
#define read(n)        scanf ("%d", & (n))
#define reads(n)       scanf ("%s", n)
#define ALL(t)         (t).begin(),(t).end()
#define FOR(i,n,m)     for (int i = n; i <= m; i ++)
#define ROF(i,n,m)     for (int i = n; i >= m; i --)
#define IT             iterator

typedef long long               ll;
typedef unsigned int            uint;
typedef unsigned long long      ull;
typedef vector<int>             vint;
typedef vector<string>          vstring;
typedef pair<int, int>		PII;

const ll mod = 1e9+7;
const ll LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;

const int N = 110000;

int pre[N];

int find (int x){
	return x == pre[x] ? x : pre[x] = find (pre[x]);
}

void Union (int x, int y){
	pre[find (x)] = find (y);
}

vint g[N];
set<PII> sset;
int sta[N], dfn[N], low[N], in[N], out[N];
stack<int> st;

void init (){
	FOR (i, 1, 10000)	pre[i] = i;
	FOR (i, 1, 10000)	g[i].clear ();
	clr (sta, 0), clr (dfn, 0), clr (low, 0), clr (in, 0);
  clr(out, 0);
	while (SIZE (st))	st.pop ();
	sset.clear ();
}

void dfs (int u, int lay, int& scc){
	sta[u] = 1;
	dfn[u] = low[u] = lay ++;
	st.push (u);
	FOR (i, 0, SIZE (g[u])-1){
		int v = g[u][i];
		if (sta[v] == 0)	dfs (v, lay, scc);
		if (sta[v] == 1)	low[u] = min (low[u], low[v]);
	} 
	if (low[u] == dfn [u]){
		scc ++;
		while (true){
			int t = st.top ();
			st.pop ();
			low[t] = scc;
			sta[t] = 2;
			if (t == u)	break;
		}
	}
}

int tarjan (int n){
	int scc = 0;
	FOR (i, 1, n){
		if (!sta[i])	dfs (i, 1, scc);
	}
	return scc;
}

int main (){
  cin.sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    init ();
    int n, m;
    cin >> n >> m;
    FOR (i, 1, m){
      int u, v;
      cin >> u >> v;
      g[u].PB(v);
      Union(u, v);
    }
    int scc = tarjan (n);
    if (scc == 1) {
      cout << 0 << endl;
      continue;
    }
    FOR (i, 1, n){
      FOR (j, 0, SIZE (g[i])-1){
        int u = low[i], v = low[g[i][j]];
        if (u!=v&&sset.find (MP (u, v))==sset.end ()){
          in[v] ++;
          out[u] ++;
          sset.insert (MP (u, v));
        }
      }
    }
    int Sin = 0, Sout = 0;
    FOR (i, 1, scc){
      if (in[i] == 0)		Sin ++;
      if (out[i] == 0)	Sout ++;
    }
    cout << max (Sin, Sout) << endl;
  }
}
