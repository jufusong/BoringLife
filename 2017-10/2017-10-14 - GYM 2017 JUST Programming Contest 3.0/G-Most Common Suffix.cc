#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int ch[N][26], val[N], ans[N], top;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    memset(ch[0], 0, sizeof(ch[0]));
    memset(val, 0, sizeof(val));
    memset(ans, 0, sizeof(ans));
    top = 0;
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      string s;
      int now = 0;
      cin >> s;
      reverse(s.begin(), s.end());
      for (int j = 0; j < s.size(); j++) {
        int x = s[j] - 'a';
        if (!ch[now][x]) {
          ch[now][x] = ++top;
          memset(ch[top], 0, sizeof(ch[top]));
        }
        now = ch[now][x];
        val[now]++;
        ans[j + 1] = max(ans[j + 1], val[now]);
      }
    }
    while (q--) {
      int x;
      cin >> x;
      cout << ans[x] << endl;
    }
  }
  return 0;
}
