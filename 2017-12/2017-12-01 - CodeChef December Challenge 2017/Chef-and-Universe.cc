#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int solve(int X, int Y, int Z, int A, int B, int C) {
  vector<vector<vector<int>>> a(X + 1, vector<vector<int>>(Y + 1, vector<int>(Z + 1, inf)));
  vector<vector<vector<bool>>> vis(X + 1, vector<vector<bool>>(Y + 1, vector<bool>(Z + 1)));
  a[0][0][0] = 0;
  vis[0][0][0] = true;
  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  while (!q.empty()) {
    int x, y, z;
    tie(x, y, z) = q.front();
    q.pop();
    vis[x][y][z] = false;
    auto update = [&](int x, int y, int z, int d) {
      if (x > X || y > Y || z > Z) return;
      if (a[x][y][z] > d) {
        a[x][y][z] = d;
        if (!vis[x][y][z]) {
          vis[x][y][z] = true;
          q.push({x, y, z});
        }
      }
    };
    update(x + 1, y, z, a[x][y][z] + A);
    update(x, y + 1, z, a[x][y][z] + A);
    update(x, y, z + 1, a[x][y][z] + A);
    update(x + 1, y + 1, z, a[x][y][z] + B);
    update(x, y + 1, z + 1, a[x][y][z] + B);
    update(x + 1, y, z + 1, a[x][y][z] + B);
    update(x + 1, y + 1, z + 1, a[x][y][z] + C);
  }
  return a[X][Y][Z];
}

int solve2(int X, int Y, int Z, int A, int B, int C) {
  B = min(B, A * 2);
  C = min(C, A * 3);
  C = min(C, A + B);
  int D = min(2 * C, 3 * B);
  if (X > Y) swap(X, Y);
  if (X > Z) swap(X, Z);
  if (Y > Z) swap(Y, Z);
  auto cal = [&](int x, int y, int z) {
    if (x + y + 1 >= z) {
      return (x + y + z) / 2 * B + (x + y + z) % 2 * A;
    }
    return (x + y) * B + (z - x - y) * A;
  };
  auto calr = [&](int l, int r) {
    int ret = inf;
    for (int i = max(0, l); i <= min(X, r); i++) {
      ret = min(ret, i * C + cal(X - i, Y - i, Z - i));
    }
    return ret;
  };
  int ans = calr(0, 5);
  ans = min(ans, calr(X + Y - Z - 5, X + Y - Z + 5));
  ans = min(ans, calr(X - 10, X));
  return ans;
}

int main(int argc, char *argv[]) {
  /*  while (true) {
    int d1 = 100;
    int X = rand() % d1 + 1, Y = rand() % d1 + 1, Z = rand() % d1 + 1;
    int A = rand() % 1000 + 1, B = rand() % 1000 + 1, C = rand() % 1000 + 1;
    int v1 = solve(X, Y, Z, A, B, C);
    int v2 = solve2(X, Y, Z, A, B, C);
    if (v1 != v2) {
      cout << X << " " << Y << " " << Z << " " << A << " " << B << " " << C << endl;
      cout << v1 << " " << v2 << endl;
    }
    }*/
  int T;
  cin >> T;
  while (T--) {
    int X, Y, Z, A, B, C;
    cin >> X >> Y >> Z >> A >> B >> C;
    cout << solve2(X, Y, Z, A, B, C) << endl;
  }
  return 0;
}
