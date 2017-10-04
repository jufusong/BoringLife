#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 777777777;

namespace IO {
    const int MT = 10 * 1024 * 1024;  /// 10MB 请注意输入数据的大小！！！
    char IO_BUF[MT];
    int IO_PTR, IO_SZ;
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

int a[4][4][100005 * 4];
int b[4][4];

void pushup(int p) {
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      a[i][j][p] = 0;
      for (int k = 1; k <= 3; k++) {
        for (int h = 1; h <= 3; h++) {
          if (b[k][h]) {
            a[i][j][p] = (a[i][j][p] + (ll)a[i][k][p * 2] * a[h][j][p * 2 + 1]) % mod;
          }
        }
      }
    }
  }
}

void build(int l, int r, int p) {
  if (l == r) {
    for (int i = 1; i <= 3; i++) {
      a[i][i][p] = 1;
    }
    return;
  }
  int m = (l + r) / 2;
  build(l, m, p * 2);
  build(m + 1, r, p * 2 + 1);
  pushup(p);
}

void update(int l, int r, int p, int P, int val) {
  if (l == r) {
    if (val == 0) {
      for (int i = 1; i <= 3; i++) {
        a[i][i][p] = 1;
      }
    } else {
      for (int i = 1; i <= 3; i++) {
        a[i][i][p] = 0;
      }
      a[val][val][p] = 1;
    }
    return;
  }
  int m = (l + r) / 2;
  if (P <= m) update(l, m, p * 2, P, val);
  else update(m + 1, r, p * 2 + 1, P, val);
  pushup(p);
}

int main(int argc, char *argv[]) {
  IO::begin();
  int n, m;
  IO::scan_d(n);
  IO::scan_d(m);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      IO::scan_d(b[i][j]);
    }
  }
  build(1, n, 1);
  for (int z = 0; z < m; z++) {
    int v, t;
    IO::scan_d(v);
    IO::scan_d(t);
    update(1, n, 1, v, t);
    int ans = 0;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        ans = (ans + a[i][j][1]) % mod;
      }
    }
    IO::println(ans);
  }
  return 0;
}
