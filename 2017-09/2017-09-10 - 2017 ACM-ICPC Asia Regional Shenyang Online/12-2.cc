#include <bits/stdc++.h>

using namespace std;

template <typename T> inline bool scan(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF)
    return 0; // EOF
  while (c != '-' && (c < '0' || c > '9')) {
    if ((c = getchar()) == EOF)
      return 0;
  }
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9')
    ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}

typedef long long ll;
int a[1000001], b[1000001];
int sa[1000001], sb[1000001];

int main(int argc, char *argv[]) {
  int n;
  while (scan(n)) {
    for (int i = 1; i <= n; i++) {
      scan(a[i]);
    }
    for (int i = 1; i <= n; i++) {
      scan(b[i]);
    }
    for (int i = 1; i <= n; i++) {
      sa[i] = sa[i - 1] + a[i];
      sb[i] = sb[i - 1] + b[i];
    }
    int ap = 0;
    int ans = sa[n] - sb[n];
    for (int i = 1; i <= n; i++) {
      if (sa[i] - sb[i] < ans) {
        ans = sa[i] - sb[i];
        ap = i;
      }
    }
    cout << ap << endl;
  }
  return 0;
}
