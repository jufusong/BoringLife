#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<string> g(8);
string S;
int L, D;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<ull> vec;
vector<int> v2;

void dfs(int x, int y, int p, ull path) {
  if (p == D) {
    vec.push_back(path);
    v2.push_back(x * 8 + y);
    return;
  }
  for (int i = 0; i < 8; i++) {
    int tx = x + dx[i], ty = y + dy[i];
    int d = tx * 8 + ty;
    if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && g[tx][ty] == S[p + 1] && !((1ULL << d) & path)) {
      dfs(tx, ty, p + 1, path | (1ULL << d));
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n >> S;
  L = n / 2;
  for (int i = 0; i < 8; i++) {
    cin >> g[i];
  }
  if (n == 1) {
    int ans = 0;
    for (auto x : g) {
      for (auto c : x) {
        if (c == S[0]) {
          ans++;
        }
      }
    }
    cout << ans << endl;
    return 0;
  }
  unordered_map<ull, int> mp[8][8];
  D = (int)S.size() - 1;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      vec.clear();
      v2.clear();
      if (g[i][j] == S[L]) {
        dfs(i, j, L, 1ULL << (i * 8 + j));
      }
      for (auto p : vec) {
        for (ull x = p; x; x = (x - 1) & p) {
          mp[i][j][x]++;
        }
        mp[i][j][0]++;
      }
    }
  }
  D = L - 1;
  ll ans = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      vec.clear();
      v2.clear();
      if (g[i][j] == S[0]) {
        dfs(i, j, 0, 1ULL << (i * 8 + j));
      }
      for (int i = 0; i < (int)vec.size(); i++) {
        auto p = vec[i];
        int x = v2[i] / 8, y = v2[i] % 8;
        for (int d = 0; d < 8; d++) {
          int tx = x + dx[d], ty = y + dy[d];
          if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8) {
            ans += mp[tx][ty][0];
            for (ull x = p; x; x = (x - 1) & p) {
              if ((__builtin_popcount(x) + __builtin_popcount(x >> 32)) & 1) {
                ans -= mp[tx][ty][x];
              } else {
                ans += mp[tx][ty][x];
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
