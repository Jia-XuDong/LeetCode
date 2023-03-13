#include <vector>
#include <numeric>
#include <iostream>

using std::vector;

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long total = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= total;
        if (k == 0)
        {
            return 0;
        }
        int ans = -1;
        while (k >= 0)
        {
            k -= chalk[++ans];
        }
        return ans;
    }
};

int main()
{
    //初始化chalk
    vector<int> chalk;
    int count, temp; //chalk中的元素个数
    std::cin >> count;
    for (int i = 0; i < count; ++i)
    {
        std::cin >> temp;
        chalk.emplace_back(temp);
    }

    int k;
    std::cin >> k;

    Solution solution;
    std::cout << solution.chalkReplacer(chalk, k) << std::endl;
}