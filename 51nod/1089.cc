#include <bits/stdc++.h>

using namespace std;

struct PalindromicTree {
  vector<vector<int>> ch;
  vector<int> fail, len, S;
  int n, p, last;
  PalindromicTree(int N) {
    ch.assign(N, vector<int>(52));
    fail.assign(N, 0);
    len.assign(N, 0);
    S.assign(N, 0);
    
    last = n = p = 0;
    newNode(0);
    newNode(-1);
    S[n] = -1;
    fail[0] = 1;
  }
  int newNode(int l) {
    len[p] = l;
    return p++;
  }
  int getFail(int x) {
    while (S[n - len[x] - 1] != S[n]) x = fail[x];
    return x;
  }
  void add(int c) {
    S[++n] = c;
    int cur = getFail(last);
    if (!ch[cur][c]) {
      int now = newNode(len[cur] + 2);
      fail[now] = ch[getFail(fail[cur])][c];
      ch[cur][c] = now;
    }
    last = ch[cur][c];
  }
}pt(100005);

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  int mx = 0;
  for (auto c : s) {
    if (c >= 'a' && c <= 'z') c = (c ^ 32) + 26;
    pt.add(c - 'A');
    mx = max(mx, pt.len[pt.last]);
  }
  cout << mx << endl;
  return 0;
}
