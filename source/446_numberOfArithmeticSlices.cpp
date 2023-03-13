#include <vector>
#include <unordered_map>
#include <iostream>

class Solution
{
public:
    int numberOfArithmeticSlices(std::vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        std::vector<std::unordered_map<long long, int>> f(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                long long d = 1LL * nums[i] - nums[j];
                auto it = f[j].find(d);
                int cnt = (it == f[j].end() ? 0 : it->second);
                ans += cnt;
                f[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    Solution solution;
    int ans = solution.numberOfArithmeticSlices(nums);
    std::cout << ans << std::endl;
    return 0;
}