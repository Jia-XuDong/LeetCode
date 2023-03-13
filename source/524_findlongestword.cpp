#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>

using std::pair;
using std::string;
using std::vector;

class Solution
{
    struct
    {
        bool operator()(const pair<int, string> a, const pair<int, string> b)
        {
            return a.first > b.first; //自定义的比较函数
        }
    } cmp;

public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        vector<pair<int, string>> vec;
        for (auto i : dictionary)
        {
            string str = i;
            int n = 0, m = 0;
            if (s.length() >= str.length())
            {
                for (; m < s.length() && n < str.length(); ++m)
                {
                    if (str[n] == s[m])
                    {
                        ++n;
                    }
                }
            }
            if (n == str.length())
            {
                vec.push_back({n, str});
            }
        }
        if (vec.size() == 0)
        {
            string ans = "";
            return ans;
        }
        sort(vec.begin(), vec.end(), cmp);
        std::priority_queue<string, std::vector<string>, std::greater<string>> que;
        int len = vec[0].first;
        for (auto j : vec)
        {
            if (j.first == len)
            {
                que.push(j.second);
            }
        }

        return que.top();
    }
};

int main()
{
    vector<string> dictionary;
    string temp;
    int count; //dictionary中的字符串个数
    std::cin >> count;

    for (int i = 0; i < count; ++i)
    {
        std::cin >> temp;
        dictionary.push_back(temp);
    }

    string s;
    std::cin >> s;

    Solution solution;
    std::cout << solution.findLongestWord(s, dictionary) << std::endl;
}