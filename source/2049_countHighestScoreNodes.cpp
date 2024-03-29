#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

class Solution
{
public:
    long maxScore = 0;
    int cnt = 0;
    int n;
    vector<vector<int>> children;

    int dfs(int node)
    {
        long score = 1;
        int size = n - 1;
        for (int c : children[node])
        {
            int t = dfs(c);
            score *= t;
            size -= t;
        }
        if (node != 0)
        {
            score *= size;
        }
        if (score == maxScore)
        {
            cnt++;
        }
        else if (score > maxScore)
        {
            maxScore = score;
            cnt = 1;
        }
        return n - size;
    }

    int countHighestScoreNodes(vector<int> &parents)
    {
        this->n = parents.size();
        this->children = vector<vector<int>>(n);
        for (int i = 0; i < n; i++)
        {
            int p = parents[i];
            if (p != -1)
            {
                children[p].emplace_back(i);
            }
        }
        dfs(0);
        cout << maxScore << endl;
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> parents = {-1, 0, 0, 1, 1, 2, 2};
    cout << s.countHighestScoreNodes(parents) << endl;
    return 0;
}
