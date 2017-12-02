#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  srand(time(0));
  cout << 1 << endl;
  int n = 1002, Q = 10000;
  cout << n << " " << Q << endl;
  for (int i = 2; i <= n; i++) {
    //    cout << rand() % (i - 1) + 1 << " " << i << endl;
    cout << i - 1 << " " << i << endl;
  }
  for (int i = 0; i < Q / 2; i++) {
    printf("1 %d %d %d %d\n", rand() % n + 1, rand() % (n + 1), 0, 1);
    printf("2 %d\n", rand() % n + 1);
  }
  return 0;
}
