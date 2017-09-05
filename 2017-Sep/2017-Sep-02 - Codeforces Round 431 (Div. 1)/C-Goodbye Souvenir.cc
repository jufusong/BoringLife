#include <bits/stdc++.h>

using namespace std;

int BK = 320;

typedef long long ll;

int belong(int x) {
  return x / BK;
}

int dp[505][505], MX= 500;

int lowbit(int n) {
  return n & (-n);
}

void update(int* in, int p, int val) {
  p++;
  for (int i = p; i <= MX + 1; i += lowbit(i)) {
    in[i] += val;
  }
}

int query(int* in, int p) {
  p++;
  int sum = 0;
  for (int i = p; i; i -= lowbit(i)) {
    sum += in[i];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  vector<set<int>> b(n + 1);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[a[i]].insert(i);
  }
  MX = belong(n);
  auto findnext = [&b](int x, int p) {
    if (b[x].empty()) return -1;
    auto it = b[x].upper_bound(p);
    if (it == b[x].end()) return -1;
    return *it;
  };
  auto findpre = [&b](int x, int p) {
    if (b[x].empty()) return -1;
    auto it = b[x].lower_bound(p);
    if (it == b[x].begin()) return -1;
    return *(--it);
  };
  for (int i = 0; i < n; i++) {
    int x = a[i];
    int nxt = findnext(x, i);
    if (nxt != -1) {
      update(dp[belong(i)], belong(nxt), nxt - i);
    }
  }
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int p, x;
      scanf("%d%d", &p, &x);
      p--;
      int pre = findpre(a[p], p);
      if (pre != -1) {
        update(dp[belong(pre)], belong(p), pre - p);
      }
      int nxt = findnext(a[p], p);
      if (nxt != -1) {
        update(dp[belong(p)], belong(nxt), p - nxt);
        if (pre != -1) {
          update(dp[belong(pre)], belong(nxt), nxt - pre);
        }
      }
      b[a[p]].erase(b[a[p]].find(p));
      pre = findpre(x, p);
      if (pre != -1) {
        update(dp[belong(pre)], belong(p), p - pre);
      }
      nxt = findnext(x, p);
      if (nxt != -1) {
        update(dp[belong(p)], belong(nxt), nxt - p);
        if (pre != -1) {
          update(dp[belong(pre)], belong(nxt), pre - nxt);
        }
      }

      b[x].insert(p);
      a[p] = x;
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l--, r--;
      ll ans = 0;
      if (belong(l) == belong(r)) {
        for (int i = l; i <= r; i++) {
          int x = a[i];
          int nxt = findnext(x, i);
          if (nxt != -1 && nxt <= r) {
            ans += nxt - i;
          }
        }
      } else {
        int lk = belong(l), rk = belong(r);
        for (int i = lk + 1; i <= rk - 1; i++) {
          ans += query(dp[i], rk - 1) - query(dp[i], lk);
        }
        for (int i = l; belong(i) == belong(l); i++) {
          int x = a[i];
          int nxt = findnext(x, i);
          if (nxt != -1 && nxt <= r) {
            ans += nxt - i;
          }
        }
        for (int i = r; belong(i) == belong(r); i--) {
          int x = a[i];
          int pre = findpre(x, i);
          if (pre != -1 && belong(pre) >= lk + 1) {
            ans += i - pre;
          }
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
