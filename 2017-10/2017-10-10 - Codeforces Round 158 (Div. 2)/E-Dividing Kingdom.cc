#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

namespace fw {
  int in[N];

  int lowbit(int n) {return n & (-n);}

  void update(int p, int val) {
    for (int i = p; i < N; i += lowbit(i)) {
      in[i] += val;
    }
  }

  int query(int p) {
    int sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    b[i] = {a[i].second, a[i].first};
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> c(9);
  for (int i = 0; i < 9; i++) {
    cin >> c[i];
  }
  vector<pair<int, int>> Q;
  auto cal = [](const vector<pair<int, int>>& a, int n) {
    return a[n].first == a[n - 1].first ? -1 : a[n - 1].first;
  };
  auto calL = [&cal, &a, &b](const vector<int>& c) {
    int x = c[0] + c[1] + c[2];
    vector<int> vec;
    vec.push_back(cal(a, x));
    x += c[3] + c[4] + c[5];
    vec.push_back(cal(a, x));
    x = c[0] + c[3] + c[6];
    vec.push_back(cal(b, x));
    x += c[1] + c[4] + c[7];
    vec.push_back(cal(b, x));
    return vec;
  };
  vector<int> d;
  for (auto x : a) {
    d.push_back(x.second);
  }
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  auto getIndex = [&d](int x) {
    return lower_bound(d.begin(), d.end(), x) - d.begin() + 1;
  };
  int NN = 1;
  for (int i = 2; i <= 9; i++) {
    NN *= i;
  }
  for (int z = 0; z < NN; z++) {
    auto vec = calL(c);
    bool flag = true;
    for (auto x : vec) {
      flag &= (x != -1);
    }
    if (flag) {
      for (int i = 0; i < 2; i++) {
        for (int j = 2; j < 4; j++) {
          Q.push_back({vec[i], vec[j]});
        }
      }
    }
    next_permutation(c.begin(), c.end());
  }
  map<pair<int, int>, int> mp;
  sort(Q.begin(), Q.end());
  int h = 0;
  for (auto e : Q) {
    while (h < a.size() && a[h].first <= e.first) {
      fw::update(getIndex(a[h].second), 1);
      h++;
    }
    mp[e] = fw::query(getIndex(e.second));
  }
  for (int z = 0; z < NN; z++) {
    auto vec = calL(c);
    bool flag = true;
    for (auto x : vec) {
      flag &= (x != -1);
    }
    if (flag && mp[{vec[0], vec[2]}] == c[0] && mp[{vec[0], vec[3]}] == c[0] + c[1] && mp[{vec[1], vec[2]}] == c[0] + c[3]
        && mp[{vec[1], vec[3]}] == c[0] + c[1] + c[3] + c[4]) {
      printf("%.10f %.10f\n%.10f %.10f\n", vec[0] + 0.5, vec[1] + 0.5, vec[2] + 0.5, vec[3] + 0.5);
      return 0;
    }
    next_permutation(c.begin(), c.end());
  }
  cout << -1 << endl;
  return 0;
}
