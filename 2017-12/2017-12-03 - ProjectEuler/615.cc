#include <bits/stdc++.h>

using namespace std;

const int mod = 123454321;

void solve(int n, int k) {
  vector<bool> vv(10000001);
  vector<int> pr;
  for (int i = 2; i <= 10000000; ++i) {
    if (!vv[i]) {
      pr.push_back(i);
      for (int j = i + i; j <= 10000000; j += i) {
        vv[j] = true;
      }
    }
  }
  set<vector<pair<int, int>>> se;
  priority_queue<pair<double, vector<pair<int, int>>>> q;
  vector<pair<int, int>> st{{n, 0}};
  double val = -log(pr[0]) * n;
  q.push({val, st});
  se.insert(st);

  while (--k) {
    auto u = q.top();
    q.pop();
    for (int i = 0; i < u.second.size(); ++i) {
      auto nx = u.second;
      if (i + 1 < nx.size() && nx[i + 1].second == nx[i].second + 1) {
        nx[i + 1].first++;
        nx[i].first--;
      } else {
        nx[i].first--;
        nx.insert(nx.begin() + i + 1, {1, nx[i].second + 1});
      }
      double val = u.first + log(pr[nx[i].second]) - log(pr[nx[i + 1].second]);
      if (nx[i].first == 0) {
        nx.erase(nx.begin() + i);
      }
      if (!se.count(nx)) {
        se.insert(nx);
        q.push({val, nx});
      }
    }
    auto nx = u.second;
    if (nx[0].second == 0) {
      nx[0].first++;
    } else {
      nx.insert(nx.begin(), {1, 0});
    }
    double val = u.first - log(pr[0]);
    if (!se.count(nx)) {
      se.insert(nx);
      q.push({val, nx});
    }
  }
  auto vec = q.top().second;
  long long ans = 1;
  for (auto e: vec) {
    for (int j = 0; j < e.first; ++j) {
      ans = ans * pr[e.second] % mod;
    }
  }
  cout << ans << endl;
}

int main(int argc, char *argv[]) {
  for (int i = 1; i <= 6; i++) {
    solve(5, i);
  }
  solve(1000000, 1000000);
  return 0;
}
