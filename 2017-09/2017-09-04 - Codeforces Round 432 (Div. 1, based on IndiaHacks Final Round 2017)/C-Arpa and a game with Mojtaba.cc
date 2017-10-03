#include <bits/stdc++.h>

using namespace std;

map<int, int> dp;

int dfs(int sta) {
  if (sta == 0) return 0;
  if (dp.count(sta)) return dp[sta];
  vector<int> vec;
  for (int i = 1; i <= 30; i++) {
    int newsta = 0;
    for (int j = 1; j <= 30; j++) {
      if ((1 << j) & sta) {
        if (j < i) newsta |= (1 << j);
        if (j > i) newsta |= (1 << (j - i));        
      }
    }
    if (newsta != sta) vec.push_back(dfs(newsta));
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  for (int i = 0; i < (int)vec.size(); i++) {
    if (i != vec[i]) return dp[sta] = i;
  }
  return dp[sta] = vec.size();
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    for (int j = 2; j * j <= t; j++) {
      if (t % j == 0) {
        int cnt = 0;
        while (t % j == 0) {
          t /= j;
          cnt++;
        }
        mp[j] |= (1 << cnt);
      }
    }
    if (t > 1) mp[t] |= (1 << 1);
  }
  int sg = 0;
  for (auto e : mp) {
    sg ^= dfs(e.second);
  }
  cout << (sg != 0 ? "Mojtaba" : "Arpa") << endl;
  return 0;
}
