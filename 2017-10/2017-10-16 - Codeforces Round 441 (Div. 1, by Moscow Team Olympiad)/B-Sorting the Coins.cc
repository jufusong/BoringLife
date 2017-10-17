#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

namespace fw {
  int in[N];

  int lowbit(int n) {return n & (-n);}

  void update(int p, int val) {
    for (int i = p; i < N; i += lowbit(i)) {
      in[i] += val;
    }
  }

  int query(int p) {
    int sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("1");
  for (int i = 0, last = n; i < n; i++) {
    int p;
    scanf("%d", &p);
    fw::update(p, 1);
    while (last && fw::query(last) - fw::query(last - 1)) last--;
    printf(" %d", fw::query(last) + 1);
  }
  return 0;
}
