#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int rodCutting(int price[], int n)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int max_val = -1;
        for (int j = 1; j <= i; j++)
        {
            max_val = max(max_val, price[j - 1] + dp[i - j]);
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main()
{
    int n;
    printf("Enter length of rod: ");
    scanf("%d", &n);

    int price[n];
    printf("Enter prices of pieces of length 1 to %d:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &price[i]);
    }

    int maxRevenue = rodCutting(price, n);
    printf("Maximum obtainable value = %d\n", maxRevenue);

    return 0;
}
