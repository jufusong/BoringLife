#include <bits/stdc++.h>

using namespace std;

const int N = 2000005;
const int MXB = 938;
struct BS {
  int a[MXB];
  BS() {
    memset(a, 0, sizeof(int) * MXB);
  };

  void set(int p) {
    int x = p / 32, y = p % 32;
    a[x] |= (1 << y);
  }

  void ex(BS* o) {
    for (int i = 0; i < MXB; i++) {
      a[i] &= o->a[i];
    }
  }

  int count(int p) {
    int x = p / 32, y = p % 32;
    int ans = 0;
    for (int i = y; i < 32; i++) {
      if ((1 << i) & a[x]) {
        ans++;
      }
    }
    for (int i = x + 1; i < MXB; i++) {
      ans += __builtin_popcount(a[i]);
    }
    return ans;
  }
};

struct Trie {
  vector<vector<int>> ch;
  vector<BS*> b;
  void init() {
    ch = vector<vector<int>>(1, vector<int>(26, 0));
    if (b.empty()) {
      b = vector<BS*>(2000001, 0);
    } else {
      for (int i = 0; i <= 2000000; i++) {
        if (b[i]) delete b[i];
        b[i] = 0;
      }
    }
  }
  void insert(char *s) {
    int now = 0;
    for (int i = 0; s[i]; i++) {
      int c = s[i] - 'a';
      if (!ch[now][c]) {
        ch[now][c] = ch.size();
        ch.push_back(vector<int>(26, 0));
      }
      now = ch[now][c];
    }
    if (!b[now]) {
      b[now] = new BS();
    }
  }
  void process(string& s, int val) {
    int now = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = s[i] - 'a';
      if (!ch[now][c]) return;
      now = ch[now][c];
      if (b[now]) {
        b[now]->set(val);
      }
    }
  }

  BS* find(string& s) {
    int now = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      int c = s[i] - 'a';
      now = ch[now][c];
    }
    return b[now];
  }
}trie[4];

char s[5][N];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < 4; i++) {
      trie[i].init();
    }
    int Q;
    scanf("%d", &Q);
    vector<pair<string, int>> a1;
    vector<tuple<string, string, string, string>> b;
    for (int z = 0; z < Q; z++) {
      int op;
      scanf("%d", &op);
      if (op == 1) {
        scanf("%s", s[0]);
        a1.push_back({s[0], z});
        b.push_back(make_tuple(s[0], "", "", ""));
      } else {
        for (int i = 1; i <= 4; i++) {
          scanf("%s", s[i]);
        }
        reverse(s[2], s[2] + strlen(s[2]));
        reverse(s[4], s[4] + strlen(s[4]));
        b.push_back(make_tuple(s[1], s[2], s[3], s[4]));
        for (int i = 0; i < 4; i++) {
          trie[i].insert(s[i + 1]);
        }
      }
    }
    sort(a1.begin(), a1.end(), [](const pair<string, int>& x, const pair<string, int>& y){
        return x.first.size() < y.first.size();
      });
    vector<int> c(Q), d(a1.size());
    for (int i = 0; i < (int)a1.size(); i++) {
      c[a1[i].second] = i;
      d[i] = a1[i].first.size();
    }
    for (int z = 0; z < Q; z++) {
      string as, bs, cs, ds;
      tie(as, bs, cs, ds) = b[z];
      if (bs.size() == 0) {
        int len = as.size();
        string s = as.substr(0, len / 2);
        string t = as.substr(len / 2);
        trie[0].process(s, c[z]);
        reverse(s.begin(), s.end());
        trie[1].process(s, c[z]);
        trie[2].process(t, c[z]);
        reverse(t.begin(), t.end());
        trie[3].process(t, c[z]);
      } else {
        BS x = *trie[0].find(as);
        x.ex(trie[1].find(bs));
        x.ex(trie[2].find(cs));
        x.ex(trie[3].find(ds));
        int len = max(as.size() + bs.size(), cs.size() + ds.size()) * 2;
        int p = lower_bound(d.begin(), d.end(), len) - d.begin();
        printf("%d\n", x.count(p));
      }
    }
  }
  return 0;
}
