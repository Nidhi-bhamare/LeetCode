class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> atomCount = parseFormula(formula);
        string result;
        for (const auto &elem : atomCount) {
            result += elem.first;
            if (elem.second > 1) {
                result += to_string(elem.second);
            }
        }
        return result;
    }

private:
    map<string, int> parseFormula(const string &formula) {
        stack<map<string, int>> stk;
        stk.push({});
        int n = formula.size();
        
        for (int i = 0; i < n;) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                map<string, int> top = stk.top();
                stk.pop();
                i++;
                int i_start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int multiplicity = (i_start < i) ? stoi(formula.substr(i_start, i - i_start)) : 1;
                for (const auto &elem : top) {
                    stk.top()[elem.first] += elem.second * multiplicity;
                }
            } else {
                int i_start = i;
                i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string elem = formula.substr(i_start, i - i_start);
                i_start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int multiplicity = (i_start < i) ? stoi(formula.substr(i_start, i - i_start)) : 1;
                stk.top()[elem] += multiplicity;
            }
        }
        return stk.top();
    }
};
