#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using std::vector;
using std::string;
using std::tuple;
using std::cout;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<tuple<int, char>> arr = { {a, 'a'}, {b, 'b'}, {c, 'c'} };

        while (true) {
            sort(arr.begin(), arr.end(), [](const tuple<int, char>& p1, const tuple<int, char>& p2) {
                return std::get<0>(p1) > std::get<0>(p2);
                });
            bool hasNext = false;
            for (auto & [freq, ch] : arr) {
                int m = res.size();
                if (freq <= 0) {
                    break;
                }
                if (m >= 2 && res[m - 2] == ch && res[m - 1] == ch) {
                    continue;
                }
                hasNext = true;
                res.push_back(ch);
                freq--;
                break;
            }
            if (!hasNext) {
                break;
            }
        }

        return res;
    }
};

int main() {

    Solution s;
    cout << s.longestDiverseString(6, 4, 5) << "\n";
    return 0;
}