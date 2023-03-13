#include <queue>
#include <iostream>

class Solution
{
public:
    Solution(){};
    ~Solution(){};
    std::priority_queue<int, std::vector<int>, std::less<int>> queMin;
    std::priority_queue<int, std::vector<int>, std::greater<int>> queMax;

    int addNum(int num)
    {
        if (queMin.empty() || num <= queMin.top())
        {
            queMin.push(num);
            if (queMax.size() + 1 < queMin.size())
            {
                queMax.push(queMin.top());
                queMin.pop();
            }
        }
        else
        {
            queMax.push(num);
            if (queMax.size() > queMin.size())
            {
                queMin.push(queMax.top());
                queMax.pop();
            }
        }
        return 0;
    }

    double findMedian()
    {
        if (queMin.size() > queMax.size())
        {
            return queMin.top();
        }
        else
        {
            return (queMin.top() + queMax.top()) / 2.0;
        }
    }
} MedianFinder;

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5,6};
    int count = vec.size();
    Solution MedianFinder;
    for (auto i : vec)
    {
        MedianFinder.addNum(i);
    }
    std::cout << MedianFinder.findMedian() << std::endl;
    return 0;
}