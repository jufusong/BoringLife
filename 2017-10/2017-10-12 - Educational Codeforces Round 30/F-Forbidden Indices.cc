#include <bits/stdc++.h>

using namespace std;

#define maxn 250007
#define SIGMA_SIZE 26
typedef long long ll;

int N;
string str, t;

struct SAM {
  int sz, last;
  int g[maxn << 1][SIGMA_SIZE], pre[maxn << 1], step[maxn << 1];
  int cnt[maxn << 1], pos[maxn << 1], len[maxn << 1];

  void init() {
    sz = 0;
    last = 1;
    newNode(0);
  }

  void newNode(int s) {
    pre[++sz] = 0;
    step[sz] = s;
    memset(g[sz], 0, sizeof(g[sz]));
  }

  int idx(char ch) { return ch - 'a'; }

  void Insert(char ch);
  void topoSort();
  ll getCnt();
  void solve(int Q, int *op, int K);
} sam;

void SAM::Insert(char ch) {
  newNode(step[last] + 1);
  len[sz] = len[last] + 1;
  int v = idx(ch), np = sz, p = last;
  while (p && !g[p][v]) {
    g[p][v] = np;
    p = pre[p];
  }

  if (p) {
    int q = g[p][v];
    if (step[q] == step[p] + 1)
      pre[np] = q;
    else {
      newNode(step[p] + 1);
      len[sz] = len[p] + 1;
      int nq = sz;
      for (int i = 0; i < SIGMA_SIZE; i++)
        g[nq][i] = g[q][i];

      pre[nq] = pre[q];
      pre[q] = pre[np] = nq;
      while (p && g[p][v] == q)
        g[p][v] = nq, p = pre[p];
    }
  } else
    pre[np] = 1;
  last = np;
}

void SAM::topoSort() {
  for (int i = 0; i <= sz; i++)
    cnt[i] = 0;
  for (int i = 1; i <= sz; i++)
    cnt[step[i]]++;
  for (int i = 1; i <= sz; i++)
    cnt[i] += cnt[i - 1];
  for (int i = 1; i <= sz; i++)
    pos[cnt[step[i]]--] = i;
}

ll SAM::getCnt() {
  for (int i = 0; i <= sz; i++)
    cnt[i] = 0;
  for (int p = 1, i = 0; i < N; i++) {
    int v = idx(str[i]);
    p = g[p][v];
    cnt[p] = (t[i] == '0');
  }
  ll ans = 0;
  for (int i = sz; i; i--) {
    int p = pos[i];
    cnt[pre[p]] += cnt[p];
    ans = max(ans, (ll)len[p] * cnt[p]);
  }
  return ans;
}



int main(int argc, char *argv[]) {
  sam.init();
  cin >> N >> str >> t;
  for (int i = 0; i < N; i++) {
    sam.Insert(str[i]);
  }
  sam.topoSort();
  cout << sam.getCnt() << endl;
  return 0;
}
