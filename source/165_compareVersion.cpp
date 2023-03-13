#include <string>
#include <iostream>

class Solution
{
public:
    int compareVersion(std::string version1, std::string version2)
    {
        int length1 = version1.size();
        int length2 = version2.size();
        int i = 0, j = 0;
        while (i < length1 || j < length2)
        {
            int x = 0;
            for (; i < length1 && version1[i] != '.'; ++i)
            {
                x = x * 10 + version1[i] - '0';
            }
            ++i; // 跳过点号
            int y = 0;
            for (; j < length2 && version2[j] != '.'; ++j)
            {
                y = y * 10 + version2[j] - '0';
            }
            ++j; // 跳过点号
            if (x != y)
            {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};

int main()
{
    std::string version1, version2;
    std::cin >> version1;
    std::cin >> version2;
    Solution solution;
    int ans = solution.compareVersion(version1, version2);
    std::cout << ans << std::endl;
    return 0;
}