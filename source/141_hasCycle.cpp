#include <forward_list>
#include <iterator>
#include <iostream>
using std::forward_list;

class Solution
{
public:
    bool hasCycle(forward_list<int> listnode)
    {
        if (distance(begin(listnode), end(listnode)) == 0 || distance(begin(listnode), end(listnode)) == 1)
        {
            return false;
        }
        std::forward_list<int>::iterator slow = listnode.begin();
        std::forward_list<int>::iterator fast = listnode.begin();
        std::advance(fast, 1);
        while (slow != fast)
        {
            if (fast == listnode.end())
            {
                return false;
            }
            ++slow;
            ++(++fast);
        }
        return true;
    }
};
int main()
{
    Solution solution;
    forward_list<int> ListNode{1, 2, 3, 4, 5};
    bool ans = solution.hasCycle(ListNode);
    std::cout << ans << std::endl;
    return 0;
}