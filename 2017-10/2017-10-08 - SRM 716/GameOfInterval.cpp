#include <bits/stdc++.h>

using namespace std;

class GameOfInterval {
public:
  string construct(int n) {
    string S;
    auto add = [&S](int x, int y) {
      auto code = [](int v) {
        if (v < 10) return string(1, (char)(v + '0'));
        else return string(1, (char)(v + 'A' - 10));
      };
      S += code(x / 36) + code(x % 36) + code(y / 36) + code(y % 36);
    };
    for (int i = 0; i < n; i += 6) {
      int r = min(i + 5, n - 1);
      for (int j = i + 1; j <= r; j++) {
        add(i, j);
      }
      for (int j = r - 1; j > i; j--) {
        add(j, r);
      }
    }
    for (int d = 2; d <= n; d *= 2) {
      for (int i = 0; i + d * 6 - 1 < n; i += 6) {
        add(i, i + d * 6 - 1);
      }
    }
    return S;
  }
};

// CUT begin
ifstream data("GameOfInterval.sample");

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

bool do_test(int n, string __expected) {
    time_t startClock = clock();
    GameOfInterval *instance = new GameOfInterval();
    string __result = instance->construct(n);
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
        int n;
        from_stream(n);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1507395235;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "GameOfInterval (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
