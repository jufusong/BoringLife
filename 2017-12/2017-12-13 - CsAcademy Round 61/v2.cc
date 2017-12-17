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
  vector<vector<double>> f(a.size() + 1, vector<double>(a.size() + 1));
  for (int i = 0; i < a.size(); i++) {
    f[0][0] = 1;
    int v = a[i];
    int S1 = 0, S2 = 0;
    for (int j = 0; j < a.size(); j++) {
      if (v == a[j]) {
        ((i >= m) ^ (j >= m)) ? S2++ : S1++;
      }
    }
    for (int i = 0; i <= S1; i++) {
      for (int j = 0; j <= S2; j++) {
        f[i][j] = 0;
      }
    }
    for (int i = 0; i <= S1; i++) {
      for (int j = 0; j <= S2; j++) {
        
        if (i == S1 && j == S2) break;
        if (i == S1) f[i][j + 1] += f[i][j];
        else if (j == S2) f[i + 1][j] += f[i][j];
        else f[i + 1][j] += f[i][j] * 0.5, f[i][j + 1] += f[i][j] * 0.5;
      }
    }
    //    cout << f[S1][S2] << endl;
    int cnt = 0;
    for (int j = 0; j < (i >= m ? vr.size() : vl.size()); j++) {
      if (v == (i >= m ? br[j] : bl[j])) {
        int S = S2;;
        int z = 0;
        for (int k = 0; k < b.size(); k++) {
          if (v == b[k]) {
            if (z >= cnt && z - cnt <= S) {
              double x = f[cnt][z - cnt];
              if (z - cnt < S) x *= 0.5;
              if (i >= m) x *= r2[i - m][j];
              if (i < m) x *= r1[i][j];
              ret[i][k] += x;
            }
            z++;
          }
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
