#include <vector>
#include <iostream>

using std::vector;

class Solution
{
public:
    static vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> nums(n);
        for (auto &booking : bookings)
        {
            nums[booking[0] - 1] += booking[2];
            if (booking[1] < n)
            {
                nums[booking[1]] -= booking[2];
            }
        }
        for (int i = 1; i < n; i++)
        {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

int main()
{
    vector<vector<int>> bookings;
    vector<int> v;
    int m, temp;
    std::cin >> m; //bookings中有多少条记录

    for (int i = 0; i < m; ++i)
    {
        v.clear();
        for (int j = 0; j < 3; ++j)
        {
            std::cin >> temp;
            v.push_back(temp);
        }
        bookings.push_back(v);
    }

    Solution solution;
    int n = 5;
    static vector<int> nums = solution.corpFlightBookings(bookings, n);
    for (auto i : nums)
    {
        std::cout << i << " ";
    }
    return 0;
}
