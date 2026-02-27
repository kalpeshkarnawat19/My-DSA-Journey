#include <iostream>

class answer
{
public:
    double myPow(double x, int n)
    {
        long binaryform = n;
        // corner cases
        if (n == 0)
            return 1;
        if (x == 0)
            return 0.0;
        if (x == 1)
            return 1.0;
        if (x == (-1) && n % 2 == 0)
            return 1.0;
        if (x == (-1) && n % 2 != 0)
            return -1.0;
        if (n < 0)
        {
            x = 1 / x;
            binaryform = -binaryform;
        }
        double ans = 1;

        while (binaryform > 0)
        {
            if (binaryform % 2 == 1)
            {
                ans *= x;
            }
            x *= x;
            binaryform /= 2;
        }
        return ans;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    double x;
    std::cin >> n;
    std::cin >> x;
    answer a;
    a.myPow(x, n);
    return 0;
}
