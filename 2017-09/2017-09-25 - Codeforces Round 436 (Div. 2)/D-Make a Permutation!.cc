#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 1), b(n + 1);
  vector<bool> c(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[a[i]]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 0) {
      q.push(i);
    }
  }
  printf("%d\n", (int)q.size());
  for (int i = 1; i <= n; i++) {
    if (b[a[i]] > 1) {
      int v = q.front();
      if (!c[a[i]] && v > a[i]) {
        c[a[i]] = 1;
      } else {
        b[a[i]]--;
        a[i] = v;
        q.pop();
      }
    }
    printf("%d ", a[i]);
  }
  return 0;
}
