#include <bits/stdc++.h>

using namespace std;

int ch[5000][26], top = 1, val[5000];
vector<char> code = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
double ans = 0;

void insert(string s, int v) {
  int now = 0;
  for (auto c : s) {
    int x = c - 'A';
    if (!ch[now][x]) {
      ch[now][x] = top++;
    }
    now = ch[now][x];
  }
  val[now] = v;
}

void cal(int u, double P) {
  int cnt = 2;
  for (auto x : code) {
    if (ch[u][x - 'A']) {
      cnt += 14;
    }
  }
  double p = 1.0 / cnt;
  ans += val[u] * p * P * 2;
  for (auto x : code) {
    if (ch[u][x - 'A']) {
      cal(ch[u][x - 'A'], P * p * 14);
    }
  }
}

int main(int argc, char *argv[]) {
  for (int i = 1; i <= 999; i++) {
    string s;
    int n;
    cin >> s >> n;
    insert(s, n);
  }
  cout << top << endl;
  cal(0, 1.0);
  printf("%.8f\n", ans + .14 * 1000 / 0.86);
  return 0;
}
