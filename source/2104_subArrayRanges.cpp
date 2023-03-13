#include<vector>
#include<stack>
#include<iostream>

using std::vector;
using std::stack;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> minLeft(len), minRight(len), maxLeft(len), maxRight(len);
        stack<int> minStack, maxStack;
        for (int i = 0; i < len; ++i)
        {
            while (!minStack.empty() && nums[minStack.top()] > nums[i])
            {
                minStack.pop();
            }
            minLeft[i] = minStack.empty() ? -1 : minStack.top();
            minStack.emplace(i);

            while (!maxStack.empty() && nums[maxStack.top()] <= nums[i])
            {
                maxStack.pop();
            }
            maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
            maxStack.emplace(i);
        }

        minStack = stack<int>();
        maxStack = stack<int>();
        for (int i = len - 1; i >= 0; --i)
        {
            while (!minStack.empty() && nums[minStack.top()] >= nums[i])
            {
                minStack.pop();
            }
            minRight[i] = minStack.empty() ? len : minStack.top();
            minStack.emplace(i);

            while (!maxStack.empty() && nums[maxStack.top()] < nums[i])
            {
                maxStack.pop();
            }
            maxRight[i] = maxStack.empty() ? len : maxStack.top();
            maxStack.emplace(i);
        }

        long long sumMax = 0, sumMin = 0;
        for (int i = 0; i < len; i++)
        {
            sumMax += static_cast<long long>(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
            sumMin += static_cast<long long>(minRight[i] - i) * (i - minLeft[i]) * nums[i];
        }
        return sumMax - sumMin;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, -2, -3, 4, 1, 4, -2, -3, 4, 1, 4, -2, -3, 4, 14, -2, -3, 4, 14, -2, -3, 4, 1};
    std::cout << s.subArrayRanges(nums) << std::endl;

    return 0;
}