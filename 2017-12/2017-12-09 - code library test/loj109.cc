#include <bits/stdc++.h>
#include <sys/mman.h>

using namespace std;

const int mod = 998244353;

struct DisjointSet {
  std::vector<int> pre;

  DisjointSet(int n) {
    pre.assign(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      pre[i] = i;
    }
  }
  int find(int u) { return pre[u] == u ? pre[u] : pre[u] = find(pre[u]); }
  void merge(int u, int v) { pre[find(u)] = find(v); }
};

struct buf{
  char*s;
  buf():s((char*)mmap(0,9<<24,1,2,0,0)){}
  operator int(){
    int x=0;
    while(*s<48)++s;
    while(*s>32)
      x=x*10+*s++-48;
    return x;
  }
}it;

int main(int argc, char *argv[]) {
  int n = it, Q = it, ans = 0;
  DisjointSet ds(n);
  while (Q--) {
    int op = it, u = it, v = it;
    if (op == 0) {
      ds.merge(u, v);
    } else {
      ans = ans * 2 + (ds.find(u) == ds.find(v));
      if (ans >= mod) ans -= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
