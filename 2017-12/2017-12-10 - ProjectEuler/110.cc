#include <bits/stdc++.h>

using namespace std;

vector<int> pr = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

__int128 dfs(__int128 now, __int128 val, int p, int last, int target) {
  if (val > 1e18) return 1e18;
  if ((now + 1) / 2 > target) return val;
  __int128 ret = dfs(now * 3, val * pr[p], p + 1, 1, target);
  __int128 x = val * pr[p];
  for (int i = 2; i <= last && x < 1e18; i++) {
    x *= pr[p];
    ret = min(ret, dfs(now * (2 * i + 1), x, p + 1, i, target));
  }
  return ret;
}

void solve(int n) {
  cout << (long long)dfs(1, 1, 0, 30, n) << endl;
}

int main(int argc, char *argv[]) {
  solve(1e3);
  solve(4e6);
  return 0;
}
