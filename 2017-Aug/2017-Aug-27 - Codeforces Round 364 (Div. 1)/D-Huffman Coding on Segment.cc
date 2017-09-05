#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace Mo {
  struct Query {
    int l, r, id;
  };
  vector<int> a;
  vector<ll> ans;
  vector<Query> b;
  int cx[100005], cy[100005];
  int BK;
  vector<int> can;
  void read() {
    int n;
    scanf("%d", &n);
    BK = 320;
    a.resize(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    for (auto e : mp) {
      if (e.second > BK) {
        can.push_back(e.first);
      }
    }
    int m;
    scanf("%d", &m);
    ans.resize(m);
    for (int i = 0, l, r; i < m; i++) {
      scanf("%d%d", &l, &r);
      b.push_back({l - 1, r - 1, i});
    }
  }
  void add(int x, int v = 1) {
    cy[cx[x]]--, cx[x] += v, cy[cx[x]]++;
  }
  void del(int x) {
    add(x, -1);
  }
  int zc[100005];
  ll cal(priority_queue<int, vector<int>, greater<int>>& q) {
    ll sum = 0, last = -1;
    for (int i = 1; i <= BK; i++) {
      if (zc[i]) {
        if (last != -1) {
          sum += last + i;
          zc[i]--;
          if (i + last > BK) {
            q.push(i + last);
          } else {
            zc[i + last]++;
          }
          last = -1;
        }
        if (zc[i] > 1) {
          sum += zc[i] / 2 * i * 2;
          if (i + i > BK) {
            for (int j = zc[i] / 2; j > 0; j--) {
              q.push(i + i);
            }
          } else {
            zc[i + i] += zc[i] / 2;
          }
          zc[i] %= 2;
        }
        if (zc[i] == 1) {
          zc[i] = 0;
          last = i;
        }
      }
    }
    if (last != -1) q.push(last);
    while (q.size() > 1) {
      int u = q.top();
      q.pop();
      int v = q.top();
      q.pop();
      sum += u + v;
      q.push(u + v);
    }
    return sum;
    for (;false;) {
      int x = q.top();
      if (zc[x] == 1 && q.size() == 1) {
        zc[x] = 0;
        break;
      }
      if (zc[x] == 0) {
        q.pop();
        continue;
      }
      if (zc[x] == 1) {
        q.pop();
        zc[x]--;
        zc[q.top()]--;
        int y = x + q.top();
        if (zc[y] == 0) {
          q.push(y);
        }
        zc[y]++;
        sum += x + q.top();
      } else {
        ll t = zc[x] / 2;
        zc[x] %= 2;
        if (zc[2 * x] == 0) {
          q.push(2 * x);
        }
        zc[2 * x] += t;
        sum += t * 2 * x;
      }
    }
    return sum;
  }
  void solve() {
    sort(b.begin(), b.end(), [](const Query& x, const Query& y){
        return x.l / BK < y.l / BK || (x.l / BK == y.l / BK && x.r < y.r);
      });
    for (int i = 0, L = 0, R = 0; i < (int)b.size(); i++) {
      while (R <= b[i].r) add(a[R++]);
      while (R - 1 > b[i].r) del(a[--R]);
      while (L < b[i].l) del(a[L++]);
      while (L > b[i].l) add(a[--L]);
      priority_queue<int, vector<int>, greater<int>> q;
      for (int i = 1; i <= BK; i++) {
        zc[i] = cy[i];
      }
      for (auto x : can) {
        if (cx[x] > BK) {
          q.push(cx[x]);
        }
      }
      ans[b[i].id] = cal(q);
    }
  }
};

int main(int argc, char *argv[]) {
  Mo::read();
  Mo::solve();
  for (auto x : Mo::ans) {
    printf("%lld\n", x);
  }
  return 0;
}
