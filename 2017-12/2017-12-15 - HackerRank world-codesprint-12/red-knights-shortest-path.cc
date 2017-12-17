#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  int x1, y1, x2, y2;
  cin >> n >> y1 >> x1 >> y2 >> x2;
  int dx = abs(x2 - x1), dy = abs(y1 - y2);
  if (dy % 2 || (dx - dy / 2) % 2) {
    cout << "Impossible" << endl;
  } else {
    int cnt = dy / 2;
    cnt += (dx - dy / 2 > 0 ? (dx - dy / 2) / 2 : 0);
    cout << cnt << endl;
    vector<string> vec;
    while (x1 != x2 || y1 != y2) {
      if (y1 != y2) {
        string x = (x1 < x2 ? "R" : "L");
        string y = (y1 < y2 ? "L" : "U");
        vec.push_back(y + x);
        x1 < x2 ? x1++ : x1--;
        y1 < y2 ? y1 += 2 : y1 -= 2;
      } else {
        if (x1 < x2) vec.push_back("R"), x1 += 2;
        else vec.push_back("L"), x1 -= 2;
      }
    }
    sort(vec.begin(), vec.end(), greater<string>());
    for (auto x : vec) {
      cout << x << " ";
    }
  }
  return 0;
}
