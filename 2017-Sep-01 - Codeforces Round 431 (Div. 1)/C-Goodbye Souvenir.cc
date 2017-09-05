#include <bits/stdc++.h>

using namespace std;

int BK = 2;

typedef long long ll;

int belong(int x) {
  return x / BK;
}

int dp[505][1001], MX= 500;

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
  for (int i = 0; i < n; i++) {
    int x = a[i];
    auto op = b[x].upper_bound(i);
    if (op != b[x].end()) {
      int p = *op;
      update(dp[belong(i)], belong(p), p - i);
      //      dp[belong(i)][belong(p)] += p - i;
    }
  }
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int p, x;
      scanf("%d%x", &p, &x);
      p--;
      int px = a[p], pre = -1;
      auto it = b[px].lower_bound(p);
      if (it != b[px].begin()) {
        auto t2 = it;
        --t2;
        int tp = *t2;
        pre = tp;
        update(dp[belong(tp)], belong(p), tp - p);
        //        dp[belong(tp)][belong[p]] -= p - tp;
      }
      it = b[px].upper_bound(p);
      if (it != b[px].end()) {
        int tp = *it;
        update(dp[belong(p)], belong(tp), p - tp);
        if (pre != -1) {
          update(dp[belong(pre)], belong(tp), tp - pre);
        }
      }
      b[px].erase(b[px].find(p));
      
      it = b[x].lower_bound(p);
      if (it != b[x].begin()) {
        auto t2 = it;
        --t2;
        int tp = *t2;
        pre = tp;
        update(dp[belong(tp)], belong(p), p - tp);
      }
      if (it != b[px].end()) {
        int tp = *it;
        update(dp[belong(p)], belong(tp), tp - p);
        if (pre != -1) {
          update(dp[belong(pre)], belong(tp), pre - tp);
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
          auto it = b[x].upper_bound(i);
          if (it != b[x].end() && *it <= r) {
            ans += *it - i;
          }
        }
      } else {
        int lk = belong(l), rk = belong(r);
        for (int i = lk + 1; i <= rk - 1; i++) {
          ans += query(dp[i], rk - 1) - query(dp[i], i - 1);
        }
        for (int i = l; belong(i) == belong(l); i++) {
          int x = a[i];
          auto it = b[x].upper_bound(i);
          if (it != b[x].end() && *it <= r) {
            ans += *it - i;
          }
        }
        for (int i = r; belong(i) == belong(r); i--) {
          int x = a[i];
          auto it = b[x].lower_bound(i);
          if (it != b[x].begin()) {
            it--;
            if (*it >= l) {
              ans += i - *it;
            }
          }
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
