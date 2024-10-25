#include <bits/stdc++.h>

using namespace std;

int backpack01_2()
{
    /* 0-1背包问题 */
    // 使用dp[i][j]二维数组解决
    // 1. 确定dp数组含义这一步非常关键
    // 这里可以定义为从0-i个物品中选取背包容量为j的最大价值
    // 2.计算递推公式
    // 其实dp的题目大多数都是由前面的状态推算得来的因此这个也叫做
    // 状态转移方程
    // 对于0-1背包 当我们走到了i这个位置是不是有放i这个物品到背包的情况
    // 和不放i到背包的情况
    // 如果我们不放i 那么最大价值是不是就是dp[i-1][j],这很显然
    // 如果我们放i 那么最大的价值是不是就是 dp[i-1][j-weight[i]] + value[i]
    // 这两种情况的最大值是不是就是我们要求的价值
    // 因此状态递推公式就是dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]] + value[i])
    // 3.对dp数组初始化对于i=0 整个一列很显然j=0背包容量是0那么就全初始化0即可
    // 对于i=0哪一行，要看背包的容量如果大于第一个物品的重量就赋值给第一个物品的价值
    // 其他位置的初始化是无所谓的，因为对于当前状态来说是从正上方和左上方得来得因此初始化任何数值最后都会被覆盖
    // 我们只要保证第一行和第一列初始化正确即可
    // 4.遍历顺序
    // 对于二维数组得解法我们先遍历物品，还是先遍历背包都无所谓，但是对于一维数组得解法是有不同得

    int n, packweight;
    cin >> n >> packweight;

    vector<int> value(n, 0);
    vector<int> weight(n, 0);
    for (int i = 0; i < value.size(); ++i)
    {
        cin >> value[i];
    }
    for (int i = 0; i < weight.size(); ++i)
    {
        cin >> weight[i];
    }

    vector<vector<int>> dp(n, vector<int>(packweight + 1, 0));

    for (int i = 0; i <= packweight; ++i)
    {
        if (weight[0] > i)
        {
            continue;
        }
        else
        {
            dp[0][i] = value[0];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= packweight; ++j)
        {
            if (j < weight[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    cout << dp[n - 1][packweight];

    return dp[n - 1][packweight];
}

int backpack01_1()
{

    int n, packweight;
    cin >> n >> packweight;

    vector<int> value(n, 0);
    vector<int> weight(n, 0);
    for (int i = 0; i < value.size(); ++i)
    {
        cin >> value[i];
    }
    for (int i = 0; i < weight.size(); ++i)
    {
        cin >> weight[i];
    }

    vector<int> dp(packweight + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = packweight; j > weight[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    return dp[packweight];
}

int main(int agrc, char *argv[])
{

    return 0;
}
