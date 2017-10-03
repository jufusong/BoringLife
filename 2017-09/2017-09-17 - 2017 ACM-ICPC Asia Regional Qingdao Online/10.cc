#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N * 4];

void update(int l, int r, int p, int P, int val) {
  if (l == r) {
    a[p] += val;
    return;
  }
  int m = (l + r) / 2;
  if (m >= P) update(l, m, p * 2, P, val);
  else update(m + 1, r, p * 2 + 1, P, val);
  a[p] = a[p * 2] + a[p * 2 + 1];
}

int query(int l, int r, int p, int L, int R) {
  if (l >= L && r <= R) {
    return a[p];
  }
  int m = (l + r) / 2, ret = 0;
  if (m >= L) ret += query(l, m, p * 2, L, R);
  if (m + 1 <= R) ret += query(m + 1, r, p * 2 + 1, L, R);
  return ret;
}

int query1(int l, int r, int p, int sum) {
  if (l == r) {
    return l;
  }
  int m = (l + r) / 2;
  if (a[p * 2] < sum) return query1(m + 1, r, p * 2 + 1, sum - a[p * 2]);
  return query1(l, m, p * 2, sum);
}

namespace IO {
    const int MT = 20 * 1024 * 1024;  /// 10MB 请注意输入数据的大小！！！
    char IO_BUF[MT];
    int IO_PTR, IO_SZ;
    /// 要记得把这一行添加到main函数第一行！！！
    void begin() {
        IO_PTR = 0;
        IO_SZ = fread (IO_BUF, 1, MT, stdin);
    }
    template<typename T>
    inline bool scan_d (T & t) {
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != '-' && (IO_BUF[IO_PTR] < '0' || IO_BUF[IO_PTR] > '9'))
            IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        bool sgn = false;
        if (IO_BUF[IO_PTR] == '-') sgn = true, IO_PTR ++;
        for (t = 0; IO_PTR < IO_SZ && '0' <= IO_BUF[IO_PTR] && IO_BUF[IO_PTR] <= '9'; IO_PTR ++)
            t = t * 10 + IO_BUF[IO_PTR] - '0';
        if (sgn) t = -t;
        return true;
    }
    inline bool scan_s (char s[]) {
        while (IO_PTR < IO_SZ && (IO_BUF[IO_PTR] == ' ' || IO_BUF[IO_PTR] == '\n') ) IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        int len = 0;
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != ' ' && IO_BUF[IO_PTR] != '\n')
            s[len ++] = IO_BUF[IO_PTR], IO_PTR ++;
        s[len] = '\0';
        return true;
    }
    template<typename T>
    void print(T x) {
        static char s[33], *s1; s1 = s;
        if (!x) *s1++ = '0';
        if (x < 0) putchar('-'), x = -x;
        while(x) *s1++ = (x % 10 + '0'), x /= 10;
        while(s1-- != s) putchar(*s1);
    }
    template<typename T>
    void println(T x) {
        print(x); putchar('\n');
    }
};

int main(int argc, char *argv[]) {
  IO::begin();
  int T;
  IO::scan_d(T);
  while (T--) {
    memset(a, 0, sizeof(a));
    int n;
    IO::scan_d(n);
    //    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      update(1, n, 1, i, 1);
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      IO::scan_d(b[i]);
      //      scanf("%d", &b[i]);
    }
    vector<int> q[2];
    vector<bool> vis(n + 1);
    int now = 0;
    for (int i = 1; i <= n; i++) {
      if (i != 1 && b[i] < b[i - 1] && !vis[i]) {
        q[now].push_back(i);
        vis[i] = true;
      }
      if (i != n && b[i] > b[i + 1] && !vis[i]) {
        q[now].push_back(i);
        vis[i] = true;
      }
    }
    while (!q[now].empty()) {
      for (auto x : q[now]) {
        update(1, n, 1, x, -1);
      }
      for (auto x : q[now]) {
        int sum = query(1, n, 1, 1, x);
        int p1 = -1, p2 = -1;
        if (sum != 0) {
          p1 = query1(1, n, 1, sum);
        }
        if (sum != a[1]) {
          p2 = query1(1, n, 1, sum + 1);
        }
        //        cout << x << " " << p1 << " " << p2 << endl;
        if (p1 != -1 && p2 != -1 && b[p1] > b[p2]) {
          if (!vis[p1]) {
            q[now ^ 1].push_back(p1);
            vis[p1] = true;
          }
          if (!vis[p2]) {
            q[now ^ 1].push_back(p2);
            vis[p2] = true;
          }
        }
      }
      q[now].clear();
      now ^= 1;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        ans.push_back(i);
      }
    }
    printf("%d\n", (int)ans.size());
    for (auto x : ans) {
      printf("%d ", b[x]);
    }
    puts("");
  }
  return 0;
}
