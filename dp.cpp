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

class leetcode63
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector(n, 0));
        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) // 如果在起点或终点出现了障碍，直接返回0
            return 0;
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
            dp[0][j] = 1;

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else
                {
                    continue;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

class leetcode343
{
public:
    int integerBreak(int n)
    {
        // 这个题目的递推公式有点难
        // 一个数n 进行拆分如何乘积最大
        // dp[i]的含义 很显然就是i这个数的拆分乘积最大
        // 对i 进行拆分
        //  i = j  +（i-j）
        // 那么dp[i] = j * dp[i-j]
        // 为什么不拆j呢，其实我们需要遍历从 1到 i-1
        // 我们如果对 1拆分，那么后面如果拆分j一定会拆分成比j小是吧
        // 但是比j小的我们已经在前面拆分过了，因此这是重复的计算
        // 所以只需要拆分 i-j即可
        // 并且在拆分遍历的时候可以只遍历i/2
        vector<int> dp(n + 1, 0);
        dp[0] = 0; // 0无法拆分没意义
        dp[1] = 0; // 1也没法拆分没意义
        dp[2] = 1; // 2只能拆分成1+1
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                // 其实就是三种情况选最高
                // 拆分成两个数，拆分成多个数，不拆分
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]);
            }
        }

        return dp[n];
    }
};

class leetcode96
{
public:
    int numTrees(int n)
    {
        // 动态规划的题目刚开始确实折磨人
        // 因为这类题目接触的少所以对于递推公式没有那么敏感
        // 这类题目还是需要多做找感觉的
        // 这道题目就是典型的递推公式有点难
        // 给一个n要求出所有可能的二叉搜索树种类
        // 一个思路是你可以这么想就是所有的数都当一次头节点
        // 然后种类相加就是所有的可能
        // 当然你一个数作为头节点，左子树的数目其实是固定的，右子树的数目也是固定的
        // 因为这是一个二叉搜索树有了这个思路其实就很好做了

        // dp数组含义，dp[i]就是i为数目的二叉搜索树种类
        if (n < 2)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        vector<int> dp(n + 1, 0);
        // 确定dp数组初始化
        dp[0] = 1; // 空树也是1种
        dp[1] = 1; // 只有一个节点的话种类就是1
        dp[2] = 2; // 两个节点的话种类就是2

        // 遍历顺序
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        for (std::vector<int>::iterator it = dp.begin(); it != dp.end(); it++)
        {
            cout << *it << " ";
        }
        return dp[n];
    }
};

class leetcode416
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto &a : nums)
        {
            sum += a;
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        // 这个就相当于01背包中的背包容量
        sum = sum / 2;
        // 相当于物品数目
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        for (int i = 0; i <= sum; ++i)
        {
            if (i < nums[0])
            {
                continue;
            }
            else
            {
                dp[0][i] = nums[0];
            }
        }

        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= sum; ++j)
            {
                if (j < nums[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
            }
        }

        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < dp[0].size(); ++j)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }

        return dp[n - 1][sum] == sum ? true : false;
    }
};

int main()
{
    leetcode416 leet;
    vector<int> ans = {1, 5, 11, 5};
    cout << leet.canPartition(ans) << "\n";
}