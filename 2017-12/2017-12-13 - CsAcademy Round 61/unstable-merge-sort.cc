#include <bits/stdc++.h>

using namespace std;

vector<vector<double>> solve(vector<int> a) {
  int l = 1, r = a.size();
  if (l == r) return {{1}};
  vector<vector<double>> ret(a.size(), vector<double>(a.size()));
  int m = (l + r) / 2;
  vector<int> vl({a.begin(), a.begin() + m});
  vector<int> vr({a.begin() + m, a.end()});
  auto r1 = solve(vl);
  auto r2 = solve(vr);
  auto b = a;
  auto bl = vl, br = vr;
  sort(b.begin(), b.end());
  sort(bl.begin(), bl.end());
  sort(br.begin(), br.end());
  map<int, int> mp1, mp2;
  for (int i = 0; i < b.size(); i++) {
    if (i == 0 || b[i] != b[i - 1]) {
      mp1[b[i]] = i;
    }
    mp2[b[i]] = i;
  }
  vector<pair<int, int>> pa;
  for (int i = 0; i < a.size(); i++) {
    pa.push_back({a[i], i});
  }
  sort(pa.begin(), pa.end());
  vector<vector<double>> f(a.size() + 1, vector<double>(a.size() + 1));
  int lS1 = -1, lS2 = -1;
  for (int i = 0; i < a.size(); i++) {
    int v = pa[i].first;
    int S1 = 0, S2 = 0;
    int p = pa[i].second;
    for (int j = 0; j < a.size(); j++) {
      if (v == a[j]) {
        ((p >= m) ^ (j >= m)) ? S2++ : S1++;
      }
    }
    if (S1 != lS1 || S2 != lS2) {
      for (int i = 0; i <= S1; i++) {
        for (int j = 0; j <= S2; j++) {
          f[i][j] = 0;
        }
      }
      lS1 = S1, lS2 = S2;
      f[0][0] = 1;
      for (int i = 0; i <= S1; i++) {
        for (int j = 0; j <= S2; j++) {
          if (i == S1 && j == S2) break;
          if (i == S1) f[i][j + 1] += f[i][j];
          else if (j == S2) f[i + 1][j] += f[i][j];
          else f[i + 1][j] += f[i][j] * 0.5, f[i][j + 1] += f[i][j] * 0.5;
        }
      }
    }
    int cnt = 0;
    for (int j = 0; j < (p >= m ? vr.size() : vl.size()); j++) {
      if (v == (p >= m ? br[j] : bl[j])) {
        int S = S2;
        int z = 0;
        int ed = mp2[v];
        for (int k = mp1[v]; k <= ed; k++) {
          if (z >= cnt && z - cnt <= S) {
            double x = f[cnt][z - cnt];
            if (z - cnt < S) x *= 0.5;
            if (p >= m) x *= r2[p - m][j];
            if (p < m) x *= r1[p][j];
            ret[p][k] += x;
          }
          z++;
        }
        cnt++;
      }
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto ret = solve(a);
  for (int i = 0; i < n; i++) {
    double ans = 0;
    for (int j = 0; j < n; j++) {
      ans += (j + 1) * ret[i][j];
    }
    printf("%.10f\n", ans);
  }
  return 0;
}
