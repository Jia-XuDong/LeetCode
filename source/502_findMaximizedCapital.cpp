#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using std::pair;
using std::priority_queue;
using std::vector;

class Solution
{
public:
    int findMaximizedCapital(long unsigned int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> vec;
        for (long unsigned int i = 0; i < capital.size(); ++i)
        {
            vec.push_back({capital[i], profits[i]});
        }
        sort(vec.begin(), vec.end());
        priority_queue<int, vector<int>, std::less<int>> prique;
        long unsigned int curr = 0;
        for (long unsigned int i = 0; i < k && i < profits.size(); ++i)
        {
            while (vec[curr].first <= w && curr < profits.size())
            {
                prique.push(vec[curr].second);
                curr++;
            }
            if (!prique.empty())
            {
                w += prique.top();
                prique.pop();
            }
            else
            {
                break;
            }
        }
        return w;
    }
};

int main()
{
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    Solution solution;
    std::cout << solution.findMaximizedCapital(k, w, profits, capital) << std::endl;
}