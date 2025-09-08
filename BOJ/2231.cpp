#include <cstdlib>
#include <iostream>

int main (void)
{
    int num;
    std::cin >> num;
    int sum;
    int c = 0;
    int i;
    for (i = 1; i <= num ;i*=10)
        c++;
    for (int k = num - (c*9) ; k <= num - 1; k++)
    {
        sum = k;
        int tmp = k;
        for (int j = i ; j >= 1; j/=10)
        {
            sum += tmp / j;
            tmp = tmp - ((tmp/j) * j);
        }
        if (sum == num)
        {
            std::cout << k;
            return (0);
        }
    }
    std::cout << 0;
    return (0);
}
