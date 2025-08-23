#include <stdio.h>
#include <string.h>

// Utility function to get max of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to compute LCS length using DP
int lcs(char *X, char *Y, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int main()
{
    char X[100], Y[100];

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of Longest Common Subsequence = %d\n", lcs(X, Y, m, n));

    return 0;
}