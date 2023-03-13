#include <iostream>
#include <vector>

using std::min;
using std::vector;
static constexpr int INF = 10000 * 101 + 1;
class Solution
{
public : int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> f(k + 2, vector<int>(n, INF));
        f[0][src] = 0;
        for (int t = 1; t <= k + 1; ++t)
        {
            for (auto &&flight : flights)
            {
                int j = flight[0], i = flight[1], cost = flight[2];
                f[t][i] = min(f[t][i], f[t - 1][j] + cost);
            }
        }
        int ans = INF;
        for (int t = 1; t <= k + 1; ++t)
        {
            ans = min(ans, f[t][dst]);
        }
        return (ans == INF ? -1 : ans);
    }
};

int main()
{
    vector<vector<int>> flights;
    vector<int> v;
    int m = 3, temp;

    for (int i = 0; i < m; i++)
    {
        v.clear();
        for (int j = 0; j < m; j++)
        {
            std::cin >> temp;
            v.push_back(temp);
        }
        flights.push_back(v);
    }

    int src = 0, dst = 2, k = 1, n = 3;
    Solution solution;
    int ans = solution.findCheapestPrice(n, flights, src, dst, k);
    std::cout << ans << std::endl;
    return 0;
}
