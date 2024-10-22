#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class leetcode509
{
public:
    int fib(int n)
    {

        if (n < 1)
        {
            return 0;
        }
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }
};

class leetcode70
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

class letcode746
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1);

        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= cost.size(); ++i)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};

class leetcode62
{
public:
    int uniquePaths(int m, int n)
    {

        // 这个题目第一次练习在初始化的位置踩坑了
        // 很明显对于这个矩阵第一行和第一列都是1就行了这样会保证
        // 初始化的数组都有值
        // 因为你移动的话只能是向左和向右
        // 定义dp数组
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化，很重要
        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = 1;
        }
        // 遍历以及确定递推公式
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main()
{
    leetcode509 leet;
    cout << leet.fib(5) << endl;
}