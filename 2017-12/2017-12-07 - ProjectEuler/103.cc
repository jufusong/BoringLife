#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> a;

bool check(vector<int> vec) {
  int m = (vec.size() + 2) / 2;
  if (accumulate(vec.begin(), vec.begin() + m, 0) <= accumulate(vec.end() - m + 1, vec.end(), 0)) {
    return false;
  }
  set<int> se;
  for (int i = 0; i < 1 << vec.size(); ++i) {
    int sum = 0;
    for (int j = 0; j < vec.size(); ++j) {
      if ((1 << j) & i) sum += vec[j];
    }
    if (se.count(sum)) return false;
    se.insert(sum);
  }
  int sz = vec.size();
  if (a[sz].empty() || accumulate(vec.begin(), vec.end(), 0) < accumulate(a[sz].begin(), a[sz].end(), 0)) {
    a[sz] = vec;
  }
  return true;
}

void dfs (vector<int> vec, int d) {
  if (d == 0) return;
  for (int i = (vec.empty() ? 1 : vec.back() + 1); i <= 50; i++) {
    vec.push_back(i);
    if (check(vec)) {
      dfs(vec, d - 1);
    }
    vec.pop_back();
  }
}

int main(int argc, char *argv[]) {
  a.resize(8);
  dfs({}, 7);
  for (int i = 1; i <= 7; ++i) {
    for (auto x: a[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
