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

int dp[22][2000001];

int main(int argc, char *argv[]) {
  vector<int> lg(2000001);
  for (int i = 1, j = 0; i <= 2000000; i++) {
    if (i == (1 << (j + 1))) j++;
    lg[i] = j;
  }
  int n;
  while (scan(n)) {
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
      scan(a[i]);
    }
    for (int i = 1; i <= n; i++) {
      scan(b[i]);
    }
    vector<ll> sa(2 * n + 1), sb(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
      sa[i] = sa[i - 1] + (i > n ? a[i - n] : a[i]);
      sb[i] = sb[i - 1] + (i > n ? b[i - n] : b[i]);
    }
    for (int i = 1; i <= 2 * n; i++) {
      dp[0][i] = sa[i] - sb[i];
    }
    for (int j = 1; (1 << j) <= 2 * n; j++) {
      for (int i = 1; i + (1 << j) - 1 <= 2 * n; i++) {
        dp[j][i] = min(dp[j - 1][i], dp[j - 1][i + (1 << (j - 1))]);
      }
    }
    auto query = [&lg](int l, int r) {
      int j = lg[r - l + 1];
      return min(dp[j][l], dp[j][r - (1 << j) + 1]);
    };
    ll ans = 0;
    int ap = 0;
    for (int i = 1; i <= n; i++) {
      int low = i, high = i + n - 1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (query(i, mid) - sa[i - 1] + sb[i - 1] < 0) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      if (low == i + n) {
        ap = i - 1;
        break;
      }
      ll xx = sa[low] - sa[i - 1];
      if (xx > ans) {
        ans = xx;
        ap = i - 1;
      }
    }
    cout << ap << endl;
  }
  return 0;
}
