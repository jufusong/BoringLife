#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int in[N];

int lowbit(int n) {return n & (-n);}

void update(int p, int val) {
  for (int i = p; i < N; i += lowbit(i)) {
    in[i] += val;
  }
}

int query(int p) {
  int sum = 0;
  for (int i = p; i; i -= lowbit(i)) {
    sum += in[i];
  }
  return sum;
}

char s[110005];
char t[1004], op[10];

bool cmp(int p) {
  for (int i = 0; t[i]; i++) {
    if (t[i] != s[p++]) return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));
    memset(in, 0, sizeof(in));
    int n;
    scanf("%d%s%s", &n, s, t);
    int len2 = strlen(s);
    int len = strlen(t);
    for (int i = len - 1; i < len2; i++) {
      if (cmp(i - len + 1)) {
        update(i + 1, 1);
      }
    }
    for (int i = 0; i < n; i++) {
      scanf("%s", op); 
      if (op[0] == 'Q') {
        int l, r, ans;
        scanf("%d%d", &l, &r);
        if (l + len - 1 > r) {
          ans = 0;
        } else {
          ans = query(r) - query(l + len - 2);
        }
        printf("%d\n", ans);
      } else {
        int p;
        scanf("%d%s", &p, op);
        if (s[p - 1] == op[0]) continue;
        s[p - 1] = op[0];
        for (int i = max(p - 1, len - 1); i <= p - 1 + len - 1 && i < len2; i++) {
          int x = cmp(i - len + 1);
          int y = query(i + 1) - query(i);
          if (x == 0 && y == 1) update(i + 1, -1);
          if (x == 1 && y == 0) update(i + 1, 1);
        }
      }
    }
    puts("");
  }

  return 0;
}



