#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;

class Solution
{
    // blank 返回长度为 n 的由空格组成的字符串
    string blank(int n)
    {
        return string(n, ' ');
    }

    // join 返回用 sep 拼接 [left, right) 范围内的 words 组成的字符串
    string join(vector<string> &words, int left, int right, string sep)
    {
        string s = words[left];
        for (int i = left + 1; i < right; ++i)
        {
            s += sep + words[i];
        }
        return s;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true)
        {
            int left = right; // 当前行的第一个单词在 words 的位置
            int sumLen = 0;   // 统计这一行单词长度之和
            // 循环确定当前行可以放多少单词，注意单词之间应至少有一个空格
            while (right < n && sumLen + words[right].length() + right - left <= maxWidth)
            {
                sumLen += words[right++].length();
            }

            // 当前行是最后一行：单词左对齐，且单词之间应只有一个空格，在行末填充剩余空格
            if (right == n)
            {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            // 当前行只有一个单词：该单词左对齐，在行末填充剩余空格
            if (right - left == 1)
            {
                ans.emplace_back(words[left] + blank(maxWidth - sumLen));
                continue;
            }

            // 当前行不只一个单词
            int avgSpaces = (maxWidth - sumLen) / (right - left - 1);
            int extraSpaces = (maxWidth - sumLen) % (right - left - 1);
            string s_left = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1));
            string s_right = join(words, left + extraSpaces + 1, right, blank(avgSpaces));
            ans.emplace_back(s_left + blank(avgSpaces) + s_right);
        }
    }
};

int main()
{
    Solution solution;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> ans = solution.fullJustify(words, maxWidth);
    for (auto i : ans)
    {
        std::cout << i << std::endl;
    }
}
