#include <vector>
#include <iostream>

class Solution
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        int n = nums.size();

        // 辅助函数，输入下标 i，返回一个二元组 (0/1, nums[i])
        // 方便处理 nums[-1] 以及 nums[n] 的边界情况
        auto get = [&](int i) -> std::pair<int, int>
        {
            if (i == -1 || i == n)
            {
                return {0, 0};
            }
            return {1, nums[i]};
        };

        int left = 0, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1))
            {
                ans = mid;
                break;
            }
            if (get(mid) < get(mid + 1))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 5, 4, 3, 4, 1};
    Solution solution;
    std::cout << solution.findPeakElement(nums) << std::endl;
}