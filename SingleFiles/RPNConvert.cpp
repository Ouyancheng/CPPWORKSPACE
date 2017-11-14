#include <stack>
#include <cctype>
#include <sstream>
#include <vector>
#include <iostream>
#include <deque>
#include <fstream>
using namespace std;
class Solution {
public:
     struct token {
        bool isnum;
        int num;
        char op;
        token(char c) : isnum(false), num(0), op(c) {

        }
        token(int n) : isnum(true), num(n), op('\0') {

        }
    };

public:
    Solution() : pos(0) {

    }

    token getnexttoken(string &s) {
        while (isspace(s[pos])) pos++;
        if (s[pos] <= '9' && s[pos] >= '0') {
            string nstr;
            while ((s[pos] <= '9' && s[pos] >= '0')) {
                nstr += s[pos];
                ++pos;
            }
            ss << nstr;
            int num;
            ss >> num;
            ss.clear();
            clog << "Parsed " << num << endl;
            return token(num);
        } else {
            char c = s[pos];
            ++pos;
            clog << "Parsed " << c << endl;
            return token(c);
        }
    }

    int calculate(string s) {
        deque<char> ops;
        deque<token> rpn;

        size_t ac = s.size();
        while (s[ac - 1] == ' ') --ac;
        while (pos < ac) {
            token t = getnexttoken(s);
            if (t.isnum) {
                rpn.push_back(t);
            } else {
                if (t.op == '(') {
                    ops.push_back('(');
                } else if (t.op == ')') {
                    while (ops.back() != '(') {
                        rpn.push_back(token(ops.back()));
                        ops.pop_back();
                    }
                    ops.pop_back();
                } else {
                    while (!ops.empty() && ops.back() != '(') {
                        rpn.push_back(token(ops.back()));
                        ops.pop_back();
                    }
                    ops.push_back(t.op);
                }
            }
        }
        // clog << "converted! " << endl;

        while (!ops.empty()) {
            rpn.push_back(token(ops.back()));
            ops.pop_back();
        }

        // ofstream ofs;
        // ofs.open("LeedCodePartTest.txt", ios::out);
        for (auto &i : rpn) {
            if (i.isnum) {
                cout << i.num << endl;
            } else if (i.op == '+') {
                cout << -1 << endl;
            } else if (i.op == '-') {
                cout << -2 << endl;
            }
        }
        cout << -3 << endl;
        // ofs.close();

        deque<int> temp;
        while (!rpn.empty()) {
            token i = rpn.front();
            rpn.pop_front();
            if (i.isnum) {
                temp.push_back(i.num);
            } else if (i.op == '+') {
                int a = temp.back();
                temp.pop_back();
                int b = temp.back();
                temp.pop_back();
                temp.push_back(b + a);
            } else {
                int a = temp.back();
                temp.pop_back();
                int b = temp.back();
                temp.pop_back();
                temp.push_back(b - a);
            }

        }
        return temp.back();
    }

private:

    size_t pos;
    stringstream ss;
};

int main() {
    // ifstream ifs;
    // ifs.open("RPNFILE.txt");
    string expr;
    getline(cin, expr);
    // ifs.close();
    Solution sol;
    cout << sol.calculate(expr) << endl;
    return 0;
}
