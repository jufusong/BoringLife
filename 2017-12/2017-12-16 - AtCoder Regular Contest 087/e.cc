#include <bits/stdc++.h>

using namespace std;

int ch[100005][2], val[100005], top = 1;

long long dfs(int u, long long d) {
  if (val[u]) return 0;
  long long ret = 0;
  for (int i = 0; i < 2; i++) {
    if (ch[u][i]) {
      ret ^= dfs(ch[u][i], d - 1);
    } else {
      int cnt = 1;
      long long t = d;
      while (t % 2 == 0) t /= 2, cnt++;
      ret ^= cnt;
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n;
  long long L;
  cin >> n >> L;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int now = 0;
    for (auto c : s) {
      c -= '0';
      if (!ch[now][c]) ch[now][c] = top++;
      now = ch[now][c];
    }
    val[now] = 1;
  }
  cout << (!dfs(0, L) ? "Bob" : "Alice") << endl;
  return 0;
}
