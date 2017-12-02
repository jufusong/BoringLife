#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int A, B, cnt = 0;
  cin >> A >> B;
  for (int i = 0; i < 1000; i++) {
    cnt += (i * i >= A && i * i <= B);
  }
  cout << cnt << endl;
  return 0;
}
