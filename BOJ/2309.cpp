#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>

int main (void)
{
    std::set<int> s;
    int num;
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        std::cin >> num;
        s.insert(num);
        sum += num;
    }
    std::vector<int> arr(s.begin(), s.end());
    for (int i = 0; i < 8; i++)
    {
        for (int k = i + 1; k < 9; k++)
        {
            if ((sum - (arr[i] + arr[k])) == 100)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (j != i && j != k)
                        std::cout << arr[j] << std::endl;
                }
                return (0);
            }
        }
    }
    return (0);
}
