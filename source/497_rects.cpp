#include<vector>
#include <random>
#include<algorithm>

using std::random_device;
using std::vector;

class Solution
{
public:
    Solution(std::vector<std::vector<int>> &rects) : rects{rects}
    {
        this->arr.emplace_back(0);
        for (auto &rect : rects)
        {
            this->arr.emplace_back(arr.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }
    }

    std::vector<int> pick()
    {
        std::uniform_int_distribution<int> dis(0, arr.back() - 1);
        int k = dis(gen) % arr.back();
        int rectIndex = upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1;
        k = k - arr[rectIndex];
        int a = rects[rectIndex][0], b = rects[rectIndex][1];
        int y = rects[rectIndex][3];
        int col = y - b + 1;
        int da = k / col;
        int db = k - col * da;
        return {a + da, b + db};
    }

private:
    vector<int> arr;
    vector<vector<int>> &rects;
    std::mt19937 gen{random_device{}()};
};

int main()
{
    return 0;
}