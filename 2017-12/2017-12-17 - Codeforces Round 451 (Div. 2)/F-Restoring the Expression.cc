#include <bits/stdc++.h>

template <int T> struct StringHash {
  std::vector<std::vector<int>> ha, pw;
  std::vector<int> M;
  
  StringHash(const std::vector<int>& vec, long long CC = -1, long long MM = -1) {
    pw = ha = std::vector<std::vector<int>>(T, std::vector<int>(vec.size() + 1));
    std::vector<int> C(T, CC);
    M.assign(T, MM);
    for (int i = 0; i < T; i++) {
      pw[i][0] = 1;
      if (C[i] == -1) C[i] = randomInt();
      if (M[i] == -1) M[i] = randomInt();
    }
    for (int z = 0; z < T; z++) {
      for (int i = 0; i < vec.size(); ++i) {
        ha[z][i + 1] = ((long long)ha[z][i] * C[z] + vec[i]) % M[z], pw[z][i + 1] = (long long)pw[z][i] * C[z] % M[z];  
      }
    }
  }
  
  std::vector<int> hashInterval(int a, int b) {
    std::vector<int> ret(T);
    for (int z = 0; z < T; z++) {
      ret[z] = (ha[z][b] - (long long)ha[z][a] * pw[z][b - a] % M[z] + M[z]) % M[z];
    }
    return ret;
  }

  static int randomInt() {
    static std::mt19937 gen((std::random_device())());
    static std::uniform_int_distribution<int> uid(1e8, 1e9);
    return uid(gen);
  }
};

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  vector<int> a = {s.begin(), s.end()};
  for (auto& c : a) {
    c -= '0';
  }
  StringHash<1 << 2> sh(a, 10);
  int n = a.size();
  for (int i = 0; i < a.size(); i++) {
    auto cal = [&](int x, int y) {
      auto v1 = sh.hashInterval(0, x + 1), v2 = sh.hashInterval(x + 1, y + 1), v3 = sh.hashInterval(y + 1, n);
      bool ok = true;
      for (int i = 0; i < v1.size(); i++) {
        ok &= ((v1[i] + v2[i]) % sh.M[i] == v3[i]);
      }
      if (ok) {
        cout << s.substr(0, x + 1) << "+" << s.substr(x + 1, y - x) << "=" << s.substr(y + 1) << endl;
        exit(0);
      }
    };
    for (int j = n - i - 2; j < n - i + 2; j++) {
      if (j > i && j < n - 1 && (s[i + 1] != '0' || j - i == 1) && (s[j + 1] != '0' || n - 1 - j == 1)) {
        cal(i, j);
      }
    }
    for (int j = n - (n - i - 1) / 2 - 2; j < n - (n - i - 1) / 2 + 2; j++) {
      if (j > i && j < n - 1 && (s[i + 1] != '0' || j - i == 1) && (s[j + 1] != '0' || n - 1 - j == 1)) {
        cal(i, j);
      }
    }
  }
  return 0;
}
