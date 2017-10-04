#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

class InterleavingParenthesis {
public:
  int countWays(string s1, string s2) {
    vector<int> a(s1.size() + 1), b(s2.size() + 1);
    for (int i = 1; i <= s1.size(); i++) {
      a[i] = a[i - 1] + (s1[i - 1] == '(');
    }
    for (int i = 1; i <= s2.size(); i++) {
      b[i] = b[i - 1] + (s2[i - 1] == '(');
    }
    auto add = [](int& x, int y) {
      x += y;
      if (x >= mod) x -= mod;
    };
    vector<vector<int>> f(s1.size() + 1, vector<int>(s2.size() + 1));
    f[0][0] = 1;
    for (int i = 0; i <= s1.size(); i++) {
      for (int j = 0; j <= s2.size(); j++) {
        if ((a[i] + b[j]) * 2 >= i + j) {
          if (i) add(f[i][j], f[i - 1][j]);
          if (j) add(f[i][j], f[i][j - 1]);
        }
      }
    }
    if ((a[s1.size()] + b[s2.size()]) * 2 == s1.size() + s2.size()) {
      return f[s1.size()][s2.size()];
    }
    return 0;
  }
};

// CUT begin
ifstream data("InterleavingParenthesis.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(string s1, string s2, int __expected) {
    time_t startClock = clock();
    InterleavingParenthesis *instance = new InterleavingParenthesis();
    int __result = instance->countWays(s1, s2);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string s1;
        from_stream(s1);
        string s2;
        from_stream(s2);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s1, s2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507120595;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "InterleavingParenthesis (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
