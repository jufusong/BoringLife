#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> K;
    vector<pair<int, int>> vec(K);
    for (int i = 0; i < K; ++i) {
      cin >> vec[i].first >> vec[i].second;
    }
    int N;
    cin >> N;
    vector<pair<double, double>> a(N);
    for (int i = 0; i < N; ++i) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<double, double> x, pair<double, double> y){
        return x.second > y.second;
      });
    int ans = inf;
    for (int i = 1; i < 1 << K; i++) {
      vector<double> cand;
      int sa = 0;
      for (int j = 0; j < K; j++) {
        if ((1 << j) & i) {
          cand.push_back(vec[j].first);
          sa += vec[j].second;
        }
      }
      sort(cand.begin(), cand.end(), greater<double>());
      auto b = a;
      vector<double> left;
      for (int i = 0; i < b.size(); i++) {
        left.push_back(b[i].first);
        double d = b[i].second - (i + 1 != b.size() ? b[i + 1].second : 0);
        sort(left.begin(), left.end(), greater<double>());
        for (int j = 0; j < left.size(); j++) {
          if (j < cand.size()) {
            left[j] -= cand[j] * d;
          }
          double sum = left[j], V = 0;
          int p = j;
          while (p && left[p - 1] < left[j]) {
            p--;
            sum += left[p];
          }
          for (int k = p; k <= j; k++) {
            left[k] = sum / (j - p + 1);
          }
        }
      }
      bool flag = true;
      for (auto x : left) {
        flag &= (x <= 0);
      }
      if (flag) {
        ans = min(ans, sa);
      }
    }
    cout << (ans == inf ? -1 : ans) << endl;
  }
  return 0;
}
