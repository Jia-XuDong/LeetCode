#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    int longestCommonSubsequence(std::string word1, std::string word2)
    {
        int m = word1.length();
        int n = word2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
        {
            char c1 = word1.at(i - 1);
            for (int j = 1; j <= n; ++j)
            {
                char c2 = word2.at(j - 1);
                if (c1 == c2)
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
};

int main()
{
    std::string word1, word2;
    std::cin >> word1;
    std::cin >> word2;
    Solution solution;
    std::cout << solution.longestCommonSubsequence(word1, word2) << std::endl;
}