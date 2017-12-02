#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n, -1), b(n, -1);
  a[k % n] = 0;
  b[k % n] = 1;
  queue<int> q;
  q.push(k % n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int tu = u * 10 % n;
    if (a[tu] == -1) {
      a[tu] = u;
      q.push(tu);
    }
    tu = (u * 10 + k) % n;
    if (a[tu] == -1) {
      a[tu] = u;
      b[tu] = 1;
      q.push(tu);
    }
  }
  string s;
  for (int i = 0; ; i = a[i]) {
    s += (b[i] == 1 ? (char)(k + '0') : '0');
    if (a[i] == 0) break;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
  return 0;
}
