#include <iostream>
#include <string>
#include <cstdbool>

class Solution
{
public:
    std::string reverseVowels(std::string s)
    {
        auto isVowel = [vowels = "aeiouAEIOU"s](char ch)
        {
            return vowels.find(ch) != std::string::npos;
        };
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            while ( i < n && !isVowel(s[i]) )
            {
                ++i;
            }
            while ( j > 0 && !isVowel(s[j]) )
            {
                --j;
            }
            if (i < j)
            {
                std::swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};
int main()
{
    Solution solution;
    std::string str = "aeiouAEIOU";
    std::cout << solution.reverseVowels(str) << std::endl;
}