#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;
 
int dp[55][55];
 
int doit(string a, string b) {
  for (int i = 0; i <= a.size(); i++) for (int j = 0; j <= b.size(); j++) dp[i][j] = 1e9 + 7;
  dp[0][0] = 0;
  
  for (int i = 0; i <= a.size(); i++) for (int j = 0; j <= b.size(); j++) {
    if (i < a.size()) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
    if (j < b.size()) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
    if (i < a.size() && j < b.size()) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (a[i] != b[j]));
  }
  return dp[a.size()][b.size()];
}

class RepeatString {
    public:
    int minimalModify(string s) {
        int ans = 1e9 + 7;
        for (int i = 0; i <= s.size(); ++i) ans = min(ans, min(ans, doit(s.substr(0, i), s.substr(i))));
        return ans;
    }
};

// CUT begin
ifstream data("RepeatString.sample");

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

bool do_test(string s, int __expected) {
    time_t startClock = clock();
    RepeatString *instance = new RepeatString();
    int __result = instance->minimalModify(s);
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
        string s;
        from_stream(s);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1474417826;
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
        cout << "RepeatString (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
