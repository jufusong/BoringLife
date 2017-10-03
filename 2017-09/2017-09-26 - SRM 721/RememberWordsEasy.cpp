#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class RememberWordsEasy {
public:
  pair<ll, ll> cal(ll d, ll w) {
    ll l1 = 1e18, l2 = -1;
    for (ll i = max(0LL, w / d - 1000000); i <= w / d + 1000000; i++) {
      ll x1 = d * i + d * (d - 1) / 2;
      ll y1 = 0;
      if (d >= i) y1 = (1 + i) * i / 2;
      else y1 = d * i - d * (d - 1) / 2;
      if (x1 >= w && y1 <= w) {
        l1 = min(l1, i);
        l2 = max(l2, i);
      }
    }
    //        cout << l1 << " " << l2 << endl;
    return {l1, l2};
  }

  string isPossible(int d1, int d2, int w1, int w2) {
    auto x1 = cal(d1, w1), x2 = cal(d2, w2);
    return max(x1.first, x2.first) - 1 <= min(x2.second, x1.second) ? "Possible" : "Impossible";
  }
};

// CUT begin
ifstream data("RememberWordsEasy.sample");

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

bool do_test(int d1, int d2, int w1, int w2, string __expected) {
    time_t startClock = clock();
    RememberWordsEasy *instance = new RememberWordsEasy();
    string __result = instance->isPossible(d1, d2, w1, w2);
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
        int d1;
        from_stream(d1);
        int d2;
        from_stream(d2);
        int w1;
        from_stream(w1);
        int w2;
        from_stream(w2);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d1, d2, w1, w2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1506474478;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "RememberWordsEasy (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
