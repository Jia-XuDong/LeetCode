#include <unordered_map>
#include <vector>
#include <iostream>

class Solution
{
public:
    int numberOfBoomerangs(std::vector<std::vector<int>> &points)
    {
        int ans = 0;
        for (auto &p : points)
        {
            std::unordered_map<int, int> cnt;
            for (auto &q : points)
            {
                int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
                ++cnt[dis];
            }
            for (auto &[_, m] : cnt)
            {
                ans += m * (m - 1);
            }
        }
        return ans;
    }
};

int main()
{
    std::vector<std::vector<int>> points;
    std::vector<int> v;
    int m = 2, temp;
    std::cin >> m; //平面上点的个数

    for (int i = 0; i < m; i++)
    {
        v.clear();
        for (int j = 0; j < 2; j++)
        {
            std::cin >> temp;
            v.push_back(temp);
        }
        points.push_back(v);
    }

    Solution solution;
    std::cout << solution.numberOfBoomerangs(points) << std::endl;
}