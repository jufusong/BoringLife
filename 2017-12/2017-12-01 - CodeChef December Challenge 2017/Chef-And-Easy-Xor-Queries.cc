#include <bits/stdc++.h>

using namespace std;

namespace IO {
const int MT = 10 * 1024 * 1024; //modify size
char IO_BUF[MT];
int IO_PTR, IO_SZ;

//init
void begin() {
  IO_PTR = 0;
  IO_SZ = fread(IO_BUF, 1, MT, stdin);
}
template <typename T> inline bool scan_d(T &t) {
  while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != '-' &&
         (IO_BUF[IO_PTR] < '0' || IO_BUF[IO_PTR] > '9'))
    IO_PTR++;
  if (IO_PTR >= IO_SZ)
    return false;
  bool sgn = false;
  if (IO_BUF[IO_PTR] == '-')
    sgn = true, IO_PTR++;
  for (t = 0; IO_PTR < IO_SZ && '0' <= IO_BUF[IO_PTR] && IO_BUF[IO_PTR] <= '9';
       IO_PTR++)
    t = t * 10 + IO_BUF[IO_PTR] - '0';
  if (sgn)
    t = -t;
  return true;
}
inline bool scan_s(char s[]) {
  while (IO_PTR < IO_SZ && (IO_BUF[IO_PTR] == ' ' || IO_BUF[IO_PTR] == '\n')) IO_PTR++;
  if (IO_PTR >= IO_SZ) return false;
  int len = 0;
  while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != ' ' && IO_BUF[IO_PTR] != '\n') s[len++] = IO_BUF[IO_PTR], IO_PTR++;
  s[len] = '\0';
  return true;
}
template <typename T> void print(T x) {
  static char s[33], *s1;
  s1 = s;
  if (!x) *s1++ = '0';
  if (x < 0) putchar('-'), x = -x;
  while (x) *s1++ = (x % 10 + '0'), x /= 10;
  while (s1-- != s) putchar(*s1);
}
template <typename T> void println(T x) {
  print(x);
  putchar('\n');
}
}; // namespace IO

struct HashMap {
  vector<vector<pair<int, int>>> a;
  int mod = 59997;
  
  HashMap() {
    a.resize(mod);
  }

  int key(int x) {
    return (long long)x * 123456789 % mod;
  }

  void add(int x, int d = 1) {
    int k = key(x);
    for (auto& e : a[k]) {
      if (e.first == x) {
        e.second += d;
        return;
      }
    }
    a[k].push_back({x, d});
      //    a[key(x)] += d;
  }

  void del(int x) {
    add(x, -1);
  }

  int get(int x) {
    int k = key(x);
    for (auto& e : a[k]) {
      if (e.first == x) {
        return e.second;
      }
    }
    return 0;
    //    return a[key(x)];
  }
};

int main(int argc, char *argv[]) {
  IO::begin();
  int n, q;
  IO::scan_d(n);
  IO::scan_d(q);
  vector<int> a(n, 0), b(n);
  for (int i = 0, now = 0; i < n; ++i) {
    IO::scan_d(a[i]);
    now ^= a[i];
    b[i] = now;
  }
  const int BK = 320;
  vector<int> lazy(350);
  vector<HashMap> mp(350);
  for (int i = 0; i < n; i++) {
    mp[i / BK].add(b[i]);
  }
  while (q--) {
    int tp, p, x;
    IO::scan_d(tp);
    IO::scan_d(p);
    IO::scan_d(x);
    //    scanf("%d%d%d", &tp, &p, &x);
    p--;
    int bk = p / BK;
    if (tp == 1) {
      int v = (p > 0 ? (b[p] ^ b[p - 1] ^ lazy[bk] ^ lazy[(p - 1) / BK]) : b[p] ^ lazy[bk]);
      v ^= x;
      for (int j = p; j < (bk + 1) * BK && j < n; j++) {
        mp[bk].del(b[j]);
        b[j] ^= v;
        mp[bk].add(b[j]);
      }
      for (int j = bk + 1; j <= (n - 1) / BK; j++) {
        lazy[j] ^= v;
      }
    } else {
      int ans = 0;
      for (int i = 0; i < bk; i++) {
        ans += mp[i].get(lazy[i] ^ x);
      }
      for (int i = bk * BK; i <= p; i++) {
        if ((b[i] ^ lazy[bk]) == x) {
          ans++;
        }
      }
      //printf("%d\n", ans);
      IO::println(ans);
    }
  }
  return 0;
}
