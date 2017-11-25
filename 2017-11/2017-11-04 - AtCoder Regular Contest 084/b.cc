#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n, inf);
  vector<bool> vis(n, false);
  queue<int> q;
  for (int i = 1; i <= 9; i++) {
    if (!vis[i % n]) {
      vis[i % n] = true;
      a[i % n] = i;
      q.push(i % n);
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;
    for (int i = 0; i < 10; i++) {
      int v = (u * 10 + i) % n;
      if (a[u] + i < a[v]) {
        a[v] = a[u] + i;
        if (!vis[v]) {
          vis[v] = true;
          q.push(v);
        }
      }
    }
  }
  cout << a[0] << endl;
  return 0;
}
