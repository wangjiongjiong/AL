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

class leetcode1049
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        // 最后一块石头的重量
        // 类似于整数分割
        // 数组分割其实是求背包容量已知了看看是否能装满
        // 但这个题目其实求一个背包的最大容量
        // 我们的目的是想把石头分成两堆
        // 然后让他们相减求一个最小值
        // 那么最优的算法就是让这两堆石头尽可能相等
        // 那么我们就先求出来sum 显然target = sum/2
        // 那么我们背包的容量就是target我们要求的就是背包容量target看看能装多少
        // 1.定义dp数组 ，dp[j] 就是背包容量为j的情况下所装的最大价值也就是最大容量
        // 这里stone的价值就是他的容量
        // 2.确定递推公式
        // 对于背包问题递推公式有点公式
        // dp[j] = max(dp[j],dp[j-weight[i]] + value[i])]
        // 3.初始化dp数组
        // dp = 0即可 因为对于dp[0]始终是没有意义的但是后面也要初始化0不然有可能会覆盖dp数组
        // 4.遍历顺序，遍历顺序对于一维数组一定是先物品再背包，并且背包一定要倒叙遍历

        // 先求和
        int sum = 0;
        for (auto &a : stones)
        {
            sum += a;
        }
        int target = sum / 2;
        int *dp = new int[target + 1]{0};

        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = target; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        int ans = dp[target];
        return sum - ans - ans;
    }

    int lastStoneWeightII2(vector<int> &stones)
    {
        // 使用二维数组实现一下
        // 一维数组有时候不好理解
        // 二维dp数组比较基础，还是要练习一下
        int sum = 0, target = 0;
        for (auto &a : stones)
        {
            sum += a;
        }
        target = sum / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));
        for (int i = 0; i <= target; ++i)
        {
            if (i < stones[0])
            {
                continue;
            }
            else
            {
                dp[0][i] = stones[0];
            }
        }

        for (int i = 1; i < stones.size(); ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                if (j < stones[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
                }
            }
        }

        int ans = dp[stones.size() - 1][target];
        return sum - ans - ans;
    }
};

class leetcode494
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        // 这个题目其实也是背包问题的变式
        // 经过上面三道题目你会发现背包问题类型的
        // 都是求和找中间数作为背包容量
        // 其本质就是求一个最大值的问题
        // 这个题目也是如此
        // 在每个数前添加+，-其实就是将nums分成两堆
        // 一堆为+ 一堆为-
        // 这里用left代替+，用right代替-
        // 因此left+right = sum（nums）
        // left - right = target
        // 这样的话就可以求出来 left = （target + sum）/ 2
        // 因此直接在 target + sum 进行判断如果%2 ！= 1就可以直接返回0
        int sum = 0;
        int left = 0;
        for (auto &a : nums)
        {
            sum += a;
        }
        if ((target + sum) % 2 != 0)
        {
            return 0;
        }
        left = (target + sum) / 2;
        // 1.dp数组定义 dp[j] 背包容量为j的情况下，一共有dp[j] 种方法
        int *dp = new int[left + 1]{0};
        // 2.初始化dp[0] = 1;
        dp[0] = 1;
        // 3.递推公式
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = left; j >= nums[i]; --j)
            {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[left];
    }

    int findTargetSumWays2(vector<int> &nums, int target)
    {
        // 使用二维数组再做一遍
        //  感觉二维数组更加好理解
        int sum = 0;
        int left = 0;
        for (auto &a : nums)
        {
            sum += a;
        }
        if (sum < abs(target))
        {
            return 0;
        }
        if (((sum + target) / 2) % 2 != 0)
        {
            return 0;
        }
        int left = (sum + target) / 2;
        vector<vector<int>> dp(nums.size(), (left + 1, 0));
        dp[0][0] = 1;
        if (nums[0] < left)
        {
            dp[0][nums[0]] = 1;
        }
        int zero = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                zero++;
            }
            else
            {
                dp[i][0] = (int)pow(2.0, zero);
            }
        }

        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j <= left; ++j)
            {
                if (j < nums[i])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
                }
            }
        }

        return dp[nums.size()][left];
    }
};

class leetcode518
{
public:
    int change(int amount, vector<int> &coins)
    {
        // 这个题目有点类似于将背包装满一共有多少种方法
        // 但是这个题目与之前的不同这个题目的要求是
        // 物品可以重复使用这就是完全背包的概念了
        // 1.dp数组含义
        // dp[j]的含义就是当背包容量为j时装满背包的方法就是dp[j]个
        int n = coins.size();
        vector<uint64_t> dp(amount + 1, 0);
        // 初始化dp数组
        dp[0] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};

class leetcode377
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // 其实这个是不是就是将背包装满一共有多少种方法
        // 并且框架是完全背包
        vector<int> dp(target + 1, 0);

        dp[0] = 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = nums[i]; j <= target; ++j)
            {
                dp[j] = dp[j] + dp[j - nums[i]];
            }
        }

        return dp[target];
    }
};

class leetcode322
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 这个题目就是背包问题的框架题目
        // 其本质就是求如何将背包装满用最少的物品
        // 定义dp[j] 含义就是当背包容量为j是dp[j]就是将背包装满的最少物品数目
        vector<int> dp(amount + 1, 100000);

        dp[0] = 0;

        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }

        return dp[amount] == 100000 ? -1 : dp[amount];
    }
};

class Solution
{
public:
    int numSquares(int n)
    {
        // 有点类似背包问题中背包容量装满的情况下数目最少是多少
        vector<int> dp(n + 1, 999999);

        dp[0] = 0;

        int count = n / 2;

        for (int i = 1; i <= count; ++i)
        {
            for (int j = pow(i, 2); j <= n; ++j)
            {
                dp[j] = min(dp[j], dp[j - pow(i, 2)] + 1);
            }
        }

        return dp[n];
    }
};

class leetcode198
{
public:
    int rob(vector<int> &nums)
    {
        // 打家劫舍
        // 有点类似于爬楼梯
        // 当前房间偷与不偷其实是依赖于前两个房间的状态
        // 当前房间不偷其实就是回退到前一个房间
        // 当前房间偷就是回退到前两个房间然后加上当前房间的价值
        if (nums.size() == 0)
        {
            // 只有一个元素就是直接返回
            return nums[0];
        }
        if (nums.size() == 2)
        {
            // 有两个元素就直接返回 最大值
            return max(nums[0], nums[1]);
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};

class leetcode213
{
public:
    int rob(vector<int> &nums)
    {
        // 打家劫舍2
        // 这个题目限制了第一个房间与最后一个房间是相邻的
        // 就是将所有房间连成环考虑
        // 这个题目如果陷入环的思路就会很容易陷进去
        // 正确的想法是进行拆解
        // 很显然有三种情况
        // 1. 不考虑首元素也不考虑尾元素
        // 2. 只考虑首元素
        // 3. 只考虑尾元素
        // 2，3这两种就可以涵盖1
        // 这样就把环形的房间问题拆分成线性的两组
        // 这样只需要最后求max两种情况就可以了
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }

        int ans1 = rob_linear(nums, 0, nums.size() - 2);
        int ans2 = rob_linear(nums, 1, nums.size() - 1);
        return max(ans1, ans2);
    }

    int rob_linear(vector<int> &nums, int start, int end)
    {
        if (start == end)
        {
            return nums[start];
        }
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[end];
    }
};

/**
  Definition for a binary tree node.
  **/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class leetcode337
{
public:
    int rob(TreeNode *root)
    {
        // 树形dp的题目
        // 这个题目的思路是在遍历树的过程中
        // 加入dp的思想
        // 这里的dp含义与之前的题目都有所不同
        // 你可以这样想，现在我们的结构是一个树
        // 那么对于一个树的节点是不是只有偷与不偷两种状态
        // 因此我们的dp数组也就是一个只含有两个元素的数组就可以

        vector<int> ans = robtree(root);
        return max(ans[0], ans[1]);
    }

    vector<int> robtree(TreeNode *node)
    {
        if (node == nullptr)
        {
            return {0, 0};
        }

        vector<int> leftdp = robtree(node->left);
        vector<int> rightdp = robtree(node->right);
        // 对于每一个节点都有偷与不偷两种情况
        // 1.偷
        int result1 = node->val + leftdp[0] + rightdp[0];
        // 2.不偷
        int result2 = max(leftdp[1], leftdp[0]) + max(rightdp[1], rightdp[0]);

        return {result2, result1};
    }
};

class leetcode121
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 买卖股票最佳时机
        // 买卖股票其实是有两个状态
        // 1第i天持有股票所获取的最大利润
        // 2第i天不持有股票所获取的最大利润

        if (prices.size() == 1)
        {
            return 0;
        }

        // 定义dp数组含义
        // dp[i][0] 第i天持有股票的最大利润
        // dp[i][1] 第i天不持有股票的最大利润
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        // 初始化
        // 第0天dp[0][0] 就是买入当天的股票
        // 第0天dp[0][1] 就是0
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        // 递推公式
        // dp[i][0] = max(dp[i-1][0],-prices[i])
        // dp[i][1] = max(dp[i-1][1],dp[i-1][0] + prices[i])
        for (int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};

class leetcode122
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 买卖股票2
        // 与买卖股票1，不同之处在于
        // 这次可以多次买入卖出
        // 但是dp数组的定义与含义是不变的
        int size = prices.size();
        vector<vector<int>> dp(size, vector(2, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < size; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }

        return max(dp[size - 1][0], dp[size - 1][1]);
    }
};

class leetcode123
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 买卖股票3
        // 在买卖股票2的基础上增加至多买卖两次
        // 这就要求我们的状态要增多不能只有两个状态了
        // dp[i][0]  第i天第一次持有股票
        // dp[i][1]  第i天第一次不持有股票
        // dp[i][2]  第i天第二次持有股票
        // dp[i][3]  第i天第二次不持有股票
        int size = prices.size();
        if (size == 1)
        {
            return 0;
        }
        vector<vector<int>> dp(size, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;

        for (int i = 1; i < size; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }

        return max(dp[size - 1][2], dp[size - 1][3]);
    }
};

class leetcode188
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        // 至多买卖k次
        // dp[i][0]  不操作
        // dp[i][2m-1]  第i天第m次持有股票
        // dp[i][2m] 第i天第m次不持有股票
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2 * k + 1, 0));

        for (int i = 1; i < 2 * k; i += 2)
        {
            dp[0][i] = -prices[0];
        }

        for (int i = 1; i < size; ++i)
        {
            for (int j = 1; j <= (2 * k) - 1; j += 2)
            {
                // 先是持有股票的情况 j
                // 再是不持有股票的情况 j+1
                if (j == 0)
                {
                    dp[i][0] = max(dp[i - 1][0], -prices[i]);
                    dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                    dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
                }
            }
        }

        return dp[size - 1][2 * k];
    }
};

class leetcode309
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 买卖股票，包含冷冻期
        // dp含义是买卖股票系列的关键
        // dp[i][0] 第i天持有股票
        // dp[i][1] 第i天保持卖出状态也就是冷冻期之后
        // dp[i][2] 第i天卖出股票这里是必须当天卖出
        // dp[i][3] 冷冻期状态
        int size = prices.size();
        if (size == 0)
        {
            return 0;
        }
        vector<vector<int>> dp(size, vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < size; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][3];
        }

        return max(dp[size - 1][3], max(dp[size - 1][1], dp[size - 1][2]));
    }
};

class leetcode714
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {

        // 买卖股票带手续费
        // 是不是就是每次买入的时候-一个手续费即可
        // dp状态定义
        // dp[i][0] 第i天不操作
        // dp[i][1] 第i天持有股票
        // dp[i][2] 第i天不持有股票
        int size = prices.size();
        if (size == 0)
        {
            return 0;
        }

        vector<vector<int>> dp(size, vector(3, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < size; ++i)
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i] - fee);
        }

        return max(dp[size - 1][1], dp[size - 1][2]);
    }
};

class leetcode300
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // 最长递增子序列
        // 主要是递推公式
        // dp数组定义含义
        // dp[i] nums[i]的最长递增子序列长度为dp[i]
        // 遍历顺序用i一定要从大到小
        // 内部顺序遍历采用从小到大和从大到小两种都可以
        // 初始化都是1因为最少你也有一个数作为子序列
        int size = nums.size();
        if (size == 1)
        {
            return 1;
        }
        vector<int> dp(size, 1);
        int ans = 0;
        for (int i = 1; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }

                if (ans < dp[i])
                {
                    ans = dp[i];
                }
            }
        }
        return ans;
    }
};

class leetcode674
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        // 最长递增连续子序列的长度
        // 这个题目感觉已经没有dp的含义了
        // 其实就是从小到大遍历
        // 然后在自增的序列中求即可
        // 最后只要求dp数组里面的最大值即可
        int size = nums.size();
        if (size == 1)
        {
            return 1;
        }
        vector<int> dp(size, 1);
        int ans = 0;
        for (int i = 1; i < size; ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            if (dp[i] > ans)
            {
                ans = dp[i];
            }
        }

        return ans;
    }
};

class leetcode718
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        // 最长重复子数组的长度
        // dp数组的定义
        // dp[i][j] 表示 nums1 i-1 结尾和nums2 j-1结尾的最长重复子数组
        vector<vector<int>> dp(nums1.size() + 1, vector(nums2.size() + 1, 0));
        int ans = 0;
        for (int i = 1; i <= nums1.size(); ++i)
        {
            for (int j = 1; j <= nums2.size(); ++j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (ans < dp[i][j])
                {
                    ans = dp[i][j];
                }
            }
        }

        return ans;
    }
};

class leetcode1143
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        // 最长公共子序列
        //  这个和最长重复数组有点类似
        int size1 = text1.size();
        int size2 = text2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 1; i <= size1; ++i)
        {
            for (int j = 1; j <= size2; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[size1][size2];
    }
};

class leetcode1035
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        // 与最长公共子序列一致
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        for (int i = 1; i <= size1; ++i)
        {
            for (int j = 1; j <= size2; ++j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[size1][size2];
    }
};

class leetcode53
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 最大数组和
        // 两种状态，一种状态就是当前nums[i]>dp[i-1] + nums[i]
        // 一种状态就是 nums[i]<dp[i-1] + nums[i]
        // 取两种状态最大值就行
        if (nums.size() == 1)
        {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

class leetcode392
{
public:
    bool isSubsequence(string s, string t)
    {
        // 可以考虑使用双指针来解题
        int s_point = 0;
        int t_point = 0;
        while (s_point < s.size())
        {
            if (s[s_point] == t[t_point])
            {
                s_point++;
                t_point++;
            }
            else
            {
                t_point++;
            }
            if (t_point == t.size())
            {
                return false;
            }
        }
        return true;
    }

    bool isSubsequence2(string s, string t)
    {
        // 动态规划解决问题
        int s_size = s.size();
        int t_size = t.size();
        vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1, 0));

        for (int i = 1; i <= s_size; ++i)
        {
            for (int j = 1; j <= t_size; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[s_size][t_size] == s.size() ? true : false;
    }
};

class leetcode115
{
public:
    int numDistinct(string s, string t)
    {
        int s_size = s.size();
        int t_size = t.size();
        vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1, 0));
        for (int i = 0; i < s_size + 1; ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s_size; ++i)
        {
            for (int j = 1; j <= t_size; ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s_size][t_size];
    }
};

class letcode583
{
public:
    int minDistance(string word1, string word2)
    {
        int s_size = word1.size();
        int t_size = word2.size();

        vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1, 0));

        for (int i = 0; i < s_size + 1; ++i)
        {
            dp[i][0] = i;
        }
        for (int i = 0; i < t_size + 1; ++i)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= s_size; ++i)
        {
            for (int j = 1; j <= t_size; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }
        return dp[s_size][t_size];
    }
};

class leetcode72
{
public:
    int minDistance(string word1, string word2)
    {
        // 编辑距离
        int word1_size = word1.size();
        int word2_size = word2.size();

        vector<vector<int>> dp(word1_size + 1, vector<int>(word2_size + 1, 0));

        for (int i = 1; i < word1_size + 1; ++i)
        {
            dp[i][0] = i;
        }

        for (int i = 1; i < word1_size + 1; ++i)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i < word1_size + 1; ++i)
        {
            for (int j = 1; j < word2_size + 1; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }

        return dp[word1_size][word2_size];
    }
};

int main()
{
}