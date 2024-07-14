class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        unordered_map<string, int> result_counter;
        stack<unordered_map<string, int>> parenthesis_stack;
        int cur_ind = 0;

        while (cur_ind < n) {
            char cur_char = formula[cur_ind];

            if (cur_char == '(') {
                cur_ind++;
                parenthesis_stack.push(unordered_map<string, int>());
                continue;
            }

            if (cur_char == ')') {
                string mult_str = "";
                cur_ind++;

                while (cur_ind < n && isdigit(formula[cur_ind])) {
                    mult_str += formula[cur_ind];
                    cur_ind++;
                }

                int mult = mult_str.empty() ? 1 : stoi(mult_str);
                unordered_map<string, int> last_counter = parenthesis_stack.top();
                parenthesis_stack.pop();
                unordered_map<string, int>& target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();
                
                for (const auto& [elem, counter] : last_counter) {
                    target[elem] += counter * mult;
                }
                continue;
            }

            string cur_elem = "";
            string cur_counter_str = "";
            unordered_map<string, int>& target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();

            while (cur_ind < n && formula[cur_ind] != '(' && formula[cur_ind] != ')') {
                if (isalpha(formula[cur_ind])) {
                    if (isupper(formula[cur_ind]) && !cur_elem.empty()) {
                        target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
                        cur_elem = "";
                        cur_counter_str = "";
                    }
                    cur_elem += formula[cur_ind];
                } else {
                    cur_counter_str += formula[cur_ind];
                }
                cur_ind++;
            }

            target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
        }

        vector<string> parts;
        for (const auto& [elem, counter] : result_counter) {
            parts.push_back(elem + (counter == 1 ? "" : to_string(counter)));
        }
        sort(parts.begin(), parts.end());

        string result;
        for (const auto& part : parts) {
            result += part;
        }

        return result;
    }
};
