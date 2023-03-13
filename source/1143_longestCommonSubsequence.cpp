#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        int m = text1.length();
        int n = text2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
        {
            char c1 = text1.at(i - 1);
            for (int j = 1; j <= n; ++j)
            {
                char c2 = text2.at(j - 1);
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
        return dp[m][n];
    }
};

int main()
{
    std::string text1, text2;
    std::cin >> text1;
    std::cin >> text2;
    Solution solution;
    std::cout << solution.longestCommonSubsequence(text1, text2) << std::endl;
}
