class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string path;
        vector<string> keypad = {
            "",     "",     "abc", "def", "ghi", "jkl",
            "mno",  "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, 0, path, result, keypad);
        return result;
    }

    void backtrack(const string& digits, int index, string& path, vector<string>& result, const vector<string>& keypad) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        string letters = keypad[digits[index] - '0'];
        for (char ch : letters) {
            path.push_back(ch);
            backtrack(digits, index + 1, path, result, keypad);
            path.pop_back(); // backtrack
        }
    }
};
