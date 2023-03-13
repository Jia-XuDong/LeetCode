#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int n = security.size();
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 1; i < n; i++)
        {
            if (security[i] <= security[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            if (security[n - i - 1] <= security[n - i])
            {
                right[n - i - 1] = right[n - i] + 1;
            }
        }

        vector<int> ans;
        for (int i = time; i < n - time; i++)
        {
            if (left[i] >= time && right[i] >= time)
            {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> security (10,5);
    vector<int> ans = s.goodDaysToRobBank(security, 2);
    for (auto i : ans)
    {
        cout << i << " " << endl;

    }

    return 0;
}