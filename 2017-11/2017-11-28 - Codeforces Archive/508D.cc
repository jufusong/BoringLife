#include <bits/stdc++.h>

using namespace std;

struct Euler {
  std::vector<std::vector<int>> g;
  std::vector<int> path;

  Euler(const std::vector<std::vector<int>> &graph, int start) : g(graph) {
    find(start);
    reverse(path.begin(), path.end());
  }

  void find(int u) {
    while (!g[u].empty()) {
      int v = g[u].back();
      g[u].pop_back();
      find(v);
    }
    path.push_back(u);
  }
};

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  map<string, int> mp;
  vector<string> vec(70 * 70);
  vector<vector<int>> g(70 * 70);
  auto index = [&mp, &vec](string s) {
    if (mp.count(s)) {
      return mp[s];
    }
    int sz = mp.size();
    vec[sz + 1] = s;
    return mp[s] = sz + 1;
  };
  vector<int> in(70 * 70, 0), out(70 * 70, 0);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int u = index(s.substr(0, 2)), v = index(s.substr(1));
    g[u].push_back(v);
    in[v]++;
    out[u]++;
  }
  int start1 = -1, start2 = -1, cnt0 = 0, cnt2 = 0;
  for (int i = 0; i < 70 * 70; ++i) {
    if (abs(in[i] - out[i]) == 1) {
      if (in[i] < out[i]) start1 = i;
      cnt0++;
    } else if (in[i] == out[i]) {
      if (in[i] > 0) start2 = i;
    } else {
      cnt2++;
    }
  }
  if (cnt0 <= 2 && !cnt2) {
    int start = (start1 == -1 ? start2 : start1);
    auto euler = Euler(g, start);
    if (euler.path.size() == n + 1) {
      cout << "YES" << endl;
      cout << vec[start][0];
      for (auto x: euler.path) {
        cout << vec[x][1];
      }      
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
