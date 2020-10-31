class Solution {
public:
    string parseExp(const string& exp, int l, int r) {
        if (l == r) return exp.substr(l, 1);
        int n1 = 0;
        int n2 = 0;
        int i = l;
        for (; i <= r; ++i) {
            if (exp[i] == '?') {
                ++n1;
            } else if (exp[i] == ':') {
                ++n2;
            }
            if (n1 > 0 && n1 == n2) {
                break;
            }
        }
        return (exp[l] == 'T') ? parseExp(exp, l + 2, i - 1) : parseExp(exp, i + 1, r);
    }
    string parseTernary(string expression) {
        return parseExp(expression, 0, expression.size() - 1);
    }
};