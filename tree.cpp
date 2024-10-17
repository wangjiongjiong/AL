#include <bits/stdc++.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Tree
{
    int val;
    Tree *left;
    Tree *right;
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class leetcode144
{
public:
    // leetcode144、145
    void preTraversal(TreeNode *root, vector<int> &vec)
    { // 先序遍历
        if (root == nullptr)
        {
            return;
        }
        vec.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preTraversal(root, ans);
        return ans;
    }
    vector<int> preorderTraversal2(TreeNode *root)
    {
        // 迭代法，利用栈这种数据结构模拟递归法
        vector<int> ans;
        stack<TreeNode *> st;
        // 栈的思想是先进后出，前序遍历，中左右，因此先将右孩子入栈这样才能保证先出左再出右
        if (root == nullptr)
        {
            return ans;
        }
        else
        {
            st.push(root);
        }

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);
            if (root->right != nullptr)
            {
                st.push(node->right);
            }
            if (root->left != nullptr)
            {
                st.push(node->left);
            }
        }
        return ans;
    }

    vector<int> postorderTraversal2(TreeNode *root)
    {
        // 后续遍历迭代方法
        // 后续遍历是左右中，而前序遍历是中左右，如果稍加修改变为中右左，然后反转这个
        // 不就是后续遍历的左右中
        stack<TreeNode *> st;
        vector<int> ans;
        if (root == nullptr)
        {
            return ans;
        }
        else
        {
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            ans.push_back(node->val);
            if (node->left != nullptr)
            {
                st.push(node->left);
            }
            if (node->right != nullptr)
            {
                st.push(node->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> postorderTraversal3(TreeNode *root)
    {
        // 后续遍历迭代方法,使用栈数据结构辅助
        stack<TreeNode *> st;
        vector<int> ans;
        TreeNode *curr = root;
        TreeNode *pre = nullptr;
        while (curr != nullptr || !st.empty())
        {
            while (curr->left || curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            if (curr->right != nullptr || curr->right != pre)
            {

                st.pop();
                ans.push_back(curr->val);
                pre = curr;
                curr = nullptr;
            }
            else
            {
                curr = curr->right;
            }
        }
        return ans;
    }

    vector<int> inorderTraversal2(TreeNode *root)
    {
        // 中序遍历迭代法
        stack<TreeNode *> st;
        vector<int> ans;
        TreeNode *curr = root;
        while (curr != nullptr || !st.empty())
        {
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            if (curr->right == nullptr)
            {
                st.pop();
                ans.push_back(curr->val);
                curr = nullptr;
            }
            else
            {
                st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }

    vector<int> inorderTraversal6(TreeNode *root)
    {
        // 中序遍历迭代法
        stack<TreeNode *> st;
        vector<int> ans;
        TreeNode *curr = root;
        while (curr != nullptr || !st.empty())
        {
            if (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }

    vector<int> inorder2(TreeNode *root)
    {
        // 中序遍历 迭代法统一风格
        // 使用null做标记，将访问节点直接放入，同时待处理节点也放入但是要加入null做标记
        stack<TreeNode *> st;
        vector<int> ans;
        if (root != nullptr)
        {
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();
                // 按照右中左的顺序入栈，这样弹出的话就是左中右
                if (node->right)
                {
                    st.push(node->right);
                }
                st.push(node);
                st.push(nullptr);
                if (node->left)
                {
                    st.push(node->left);
                }
            }
            else
            {
                st.pop(); // 空节点出栈
                node = st.top();
                st.pop();
                ans.push_back(node->val);
            }
        }
        return ans;
    }
    vector<int> postorder2(TreeNode *root)
    {
        // 后序遍历 迭代法统一风格
        // 使用null做标记，将访问节点直接放入，同时待处理节点也放入但是要加入null做标记
        stack<TreeNode *> st;
        vector<int> ans;
        if (root != nullptr)
        {
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();
                st.push(node);
                st.push(nullptr);
                // 按照中右左的顺序入栈，这样弹出的话就是左右中
                if (node->right)
                {
                    st.push(node->right);
                }

                if (node->left)
                {
                    st.push(node->left);
                }
            }
            else
            {
                st.pop(); // 空节点出栈
                node = st.top();
                st.pop();
                ans.push_back(node->val);
            }
        }
        return ans;
    }
    vector<int> preorder2(TreeNode *root)
    {
        // 前序遍历 迭代法统一风格
        // 使用null做标记，将访问节点直接放入，同时待处理节点也放入但是要加入null做标记
        stack<TreeNode *> st;
        vector<int> ans;
        if (root != nullptr)
        {
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();

                // 按照右左中的顺序入栈，这样弹出的话就是左右中
                if (node->right)
                {
                    st.push(node->right);
                }

                if (node->left)
                {
                    st.push(node->left);
                }
                st.push(node);
                st.push(nullptr);
            }
            else
            {
                st.pop(); // 空节点出栈
                node = st.top();
                st.pop();
                ans.push_back(node->val);
            }
        }
        return ans;
    }
};

class leetcode102
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // 二叉树层序遍历
        // 也就是广度优先遍历
        queue<TreeNode *> que;
        vector<vector<int>> ans;

        if (root != nullptr)
        {
            que.push(root);
        }
        int size = 0;
        while (!que.empty())
        {
            size = que.size();
            vector<int> vec;
            while (size--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                vec.push_back(node->val);
            }
            ans.push_back(vec);
        }
        return ans;
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        // 二叉树的层序遍历自底向上
        // 有一种思路可不可以这样呢我先按自顶向下
        // 然后我将结果反转这样不就得到反转的遍历顺序
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        int size = 0;
        if (root != nullptr)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            vector<int> vec;
            size = que.size();
            while (size--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                vec.push_back(node->val);
            }
            ans.push_back(vec);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class leetcode199
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        // 这道题相当于层序遍历的变式
        // 从右边看进行遍历
        // 还是使用队列这种数据结构
        queue<TreeNode *> que;
        vector<int> ans;
        if (root != nullptr)
        {
            que.push(root);
        }
        int size = 0;
        while (!que.empty())
        {
            size = que.size();
            TreeNode *node1 = que.front();
            ans.push_back(node1->val);
            while (size--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->right)
                {
                    que.push(node->right);
                }
                if (node->left)
                {
                    que.push(node->left);
                }
            }
        }
        return ans;
    }
};

class leetcode637
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        // 求每一行的平均值
        // 其实就是层序遍历
        queue<TreeNode *> que;
        vector<double> result;
        if (root != nullptr)
        {
            que.push(root);
        }
        int size, size_average = 0;
        double average = 0;
        while (!que.empty())
        {
            // size, size_average = que.size(); // error
            size = que.size();
            size_average = que.size();
            average = 0;
            while (size--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                average += node->val;
            }
            if (size_average != 0)
            {
                average = average / size_average;
                result.push_back(average);
            }
        }
        return result;
    }
};

// Definition for a Node.
class Node1
{
public:
    int val;
    vector<Node1 *> children;

    Node1() {}

    Node1(int _val)
    {
        val = _val;
    }

    Node1(int _val, vector<Node1 *> _children)
    {
        val = _val;
        children = _children;
    }
};

class leetcode429
{
public:
    vector<vector<int>> levelOrder(Node1 *root)
    {
        vector<vector<int>> result;
        queue<Node1 *> que;
        if (root != nullptr)
        {
            que.push(root);
        }
        int size = 0;
        while (!que.empty())
        {
            size = que.size();
            vector<int> vec;
            while (size--)
            {
                Node1 *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (!(node->children).empty())
                {
                    for (auto &a : node->children)
                    {
                        que.push(a);
                    }
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};

class leetcode515
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> que;
        vector<int> result;
        if (root != nullptr)
        {
            que.push(root);
        }
        int size = 0;
        int Max;
        while (!que.empty())
        {
            size = que.size();
            Max = INT_MIN;
            while (size--)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                Max = max(Max, node->val);
            }
            result.push_back(Max);
        }
        return result;
    }
};

// Definition for a Node.
class Node2
{
public:
    int val;
    Node2 *left;
    Node2 *right;
    Node2 *next;

    Node2() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node2(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node2(int _val, Node2 *_left, Node2 *_right, Node2 *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class leetcode116117
{
public:
    Node2 *connect(Node2 *root)
    {
        queue<Node2 *> que;
        if (root != nullptr)
        {
            que.push(root);
        }
        int size = 0;
        while (!que.empty())
        {
            size = que.size();
            for (int i = 0; i < size; ++i)
            {
                Node2 *node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                if (i != size - 1)
                {
                    node->next = que.front();
                }
                else
                {
                    node->next = nullptr;
                }
            }
        }
        return root;
    }
};

class Solution104
{
public:
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root != nullptr)
        {
            que.push(root);
        }
        int size = 0;
        int count = 0;
        while (!que.empty())
        {
            size = que.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            count++;
        }
        return count;
    }

    int maxDepth2(TreeNode *root)
    {
        // 递归的思想，深度就是根节点到这个节点的距离。
        // 最大深度也就是跟节点到最下面的叶子节点的距离
        // 高度的概念就是从叶子节点到当前节点的距离就是高度
        // 对于根节点来讲，是不是最大高度就是最大深度呢
        // 对于高度，高度相当于是是从下往上找，是不是就是左右中
        // 的遍历感觉，因此是不是可以考虑后序遍历的方式
        // 递归的中止条件就是当遇到null的时候是不是就是可以返回0
        if (root == nullptr)
        {
            return 0;
        }
        // 左
        int left_hight = maxDepth2(root->left);
        // 右
        int right_hight = maxDepth2(root->right);
        // 中
        // 左右子树的高度 +1 就是当前节点的高度
        int hight = 1 + max(left_hight, right_hight);
        return hight;
    }
};

class leetcode111
{
public:
    int minDepth(TreeNode *root)
    {
        queue<TreeNode *> que;
        if (root != nullptr)
        {
            que.push(root);
        }
        int size = 0;
        int count = 0;
        while (!que.empty())
        {
            size = que.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left == nullptr && node->right == nullptr)
                {
                    count++;
                    return count;
                }
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
            count++;
        }
        return count;
    }
    int minDepth2(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }
        int left_hight = minDepth2(root->left);
        int right_hight = minDepth2(root->right);
        if (root->left == nullptr && root->right)
        {
            return 1 + right_hight;
        }
        if (root->right == nullptr && root->left)
        {
            return 1 + left_hight;
        }

        int hight = min(left_hight, right_hight);
        return hight + 1;
    }
};

class leetcode226
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        TreeNode *node = root->left;
        root->left = root->right;
        root->right = node;

        invertTree(node->left);
        invertTree(node->right);
        return root;
    }

    TreeNode *invertTree2(TreeNode *root)
    {
        stack<TreeNode *> st;
        if (root == nullptr)
        {
            return root;
        }
        else
        {
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            TreeNode *temp = node->left;
            node->left = node->right;
            node->right = temp;

            if (node->right)
            {
                st.push(node->right);
            }
            if (node->left)
            {
                st.push(node->left);
            }
        }
        return root;
    }
};

class leetcode101
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right != nullptr)
        {
            return false;
        }
        else if (left != nullptr && right == nullptr)
        {
            return false;
        }
        else if (left->val != right->val)
        {
            return false;
        }
        else if (left == nullptr && right == nullptr)
        {
            return true;
        }

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool result = outside && inside;
        return result;
    }
    bool isSymmetric(TreeNode *root)
    {
        // 递归的思想
        if (root == nullptr)
        {
            return true;
        }
        return compare(root->left, root->right);
    }
    bool isSymmetric2(TreeNode *root)
    {
        // 迭代的思想
        if (root == nullptr)
        {
            return true;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *left = que.front();
            que.pop();
            TreeNode *right = que.front();
            que.pop();

            if (left == nullptr && right == nullptr)
            {
                continue;
            }

            if (left != nullptr || right != nullptr || (left->val != right->val))
            {
                return false;
            }

            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class leetcode559
{
public:
    int maxDepth(Node *root)
    {
        // 递归的思想
        int depth = 0;
        if (root == nullptr)
        {
            return 0;
        }
        for (int i = 0; i < root->children.size(); ++i)
        {
            depth = max(depth, maxDepth(root->children[i]));
        }
        return 1 + depth;
    }

    int maxDepth2(Node *root)
    {
        // 递归的思想
        int depth = 0;
        if (root == nullptr)
        {
            return 0;
        }
        for (int i = 0; i < root->children.size(); ++i)
        {
            depth = max(depth, maxDepth(root->children[i]));
        }
        return 1 + depth;
    }
};

class leetcode222
{
public:
    int countNodes(TreeNode *root)
    {
        // 首先就想到了层序遍历
        queue<TreeNode *> que;
        int size = 0;
        if (root == nullptr)
        {
            return 0;
        }
        que.push(root);
        int count = 0;
        while (!que.empty())
        {
            size = que.size();
            while (size--)
            {
                TreeNode *node = que.front();
                que.pop();
                count++;
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }
        return count;
    }

    int countNodes2(TreeNode *root)
    {
        // 不使用层序遍历
        // 考虑到完全二叉树的特性
        // 可以看一下左侧深度和右侧深度是不是相等的呢？
        // 如果相等了，是不是左侧和右侧都是满二叉树了
        // 如果是满二叉树直接可以用公式来解决了 2^k - 1
        // 总体的思想还是可以使用递归，也是后序遍历,但是递归中止条件会复杂一点
        if (root == nullptr)
        {
            return 0;
        }
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int left_depth = 0;
        int right_depth = 0;
        int depth = 0;
        while (left != nullptr)
        {
            left = left->left;
            left_depth++;
        }
        while (right != nullptr)
        {
            right = right->right;
            right_depth++;
        }
        if (left_depth == right_depth)
        {
            return depth = (2 << left_depth) - 1;
        }
        int left_lenth = countNodes2(root->left);
        int right_lenth = countNodes2(root->right);
        int result = left_lenth + right_lenth + 1;
        return result;
    }
};

class leetcode110
{
public:
    bool isBalanced(TreeNode *root)
    {
        // 求高度，递归的方法
        return get_height(root) == -1 ? false : true;
    }

    int get_height(TreeNode *root)
    {
        // 确定递归结束条件
        if (root == nullptr)
        {
            return 0;
        }

        int left_height = get_height(root->left);
        if (left_height == -1)
        {
            return -1;
        }
        int right_height = get_height(root->right);
        if (right_height == -1)
        {
            return -1;
        }

        int result = 0;
        if (abs(left_height - right_height) > 1)
        {
            return -1;
        }

        result = max(left_height, right_height) + 1;
    }
};

class leetcode257
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        // 二叉树的所有路径
        vector<int> path;
        vector<string> result;
        get_path(root, path, result);
        return result;
    }
    void get_path(TreeNode *node, vector<int> &path, vector<string> &result)
    {
        // 递归三部曲
        // 在这里进行中间操作
        path.push_back(node->val);
        // 递归中止条件
        // 我们需要找到每一条到叶子节点的路径，因此只需要找到叶子节点就可以结束
        if (!node->left && !node->right)
        {
            // path添加到result中
            string p = "";
            for (vector<int>::iterator it = path.begin(); it != path.end(); ++it)
            {
                if (it != path.end() - 1)
                {
                    p = p + to_string(*it) + "->";
                }
                else
                {
                    p = p + to_string(*it);
                }
            }
            result.push_back(p);
            return;
        }
        // 左
        if (node->left)
        {
            get_path(node->left, path, result);
            path.pop_back();
        }
        // 右
        if (node->right)
        {
            get_path(node->right, path, result);
            path.pop_back();
        }
    }
};

class leetcode100
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 对于空节点做判断
        if (left == nullptr && right != nullptr)
        {
            return false;
        }
        else if (left != nullptr && right == nullptr)
        {
            return false;
        }
        else if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if (left->val != right->val)
        {
            return false;
        }
        //
        bool left_node = compare(left->left, right->left);
        bool right_node = compare(left->right, right->right);
        bool result = left_node && right_node;
        return result;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return compare(p, q);
    }
};

class leetcode572
{
public:
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 对于空节点做判断
        if (left == nullptr && right != nullptr)
        {
            return false;
        }
        else if (left != nullptr && right == nullptr)
        {
            return false;
        }
        else if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if (left->val != right->val)
        {
            return false;
        }
        //
        bool left_node = compare(left->left, right->left);
        bool right_node = compare(left->right, right->right);
        bool result = left_node && right_node;
        return result;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        compare(p, q);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr || subRoot == nullptr)
        {
            return false;
        }
        if (isSameTree(root, subRoot))
        {
            return true;
        }

        bool result = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        return result;
    }
};

class leetcode404
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        // 左叶子节点的和
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }
        // 左叶子节点如何判断是无法通过自己得知得看父节点
        // 父节点的左孩子不为空并且左孩子的左右孩子都为空节点
        // 这样我们就得到了左叶子节点
        int leftvale = sumOfLeftLeaves(root->left);
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        {
            leftvale = root->left->val;
        }

        return leftvale + sumOfLeftLeaves(root->right);
    }

    int sumOfLeftLeaves2(TreeNode *root)
    {
        // 迭代法就是在左这块加一个判断如果是左叶子节点就操作一下
        stack<TreeNode *> st;
        int sum = 0;
        if (root == nullptr)
        {
            return 0;
        }
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();
                st.push(node);
                st.push(nullptr);
                if (node->right)
                {
                    st.push(node->right);
                }
                if (node->left)
                {
                    st.push(node->left);
                }
            }
            else
            {
                st.pop();
                node = st.top();
                if (node->left != nullptr && node->left->left == nullptr && node->left->right)
                {
                    sum += node->left->val;
                }
            }
        }
        return sum;
    }
};

class leetcode513
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        // 找到树最底层 最左边 节点的值。
        queue<TreeNode *> que;
        if (root == nullptr)
        {
            return 0;
        }
        que.push(root);
        int size = 0;
        int ans = 0;
        while (!que.empty())
        {
            size = que.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->right)
                    que.push(node->right);
                if (node->left)
                    que.push(node->left);
                if (i == 0)
                {
                    ans = node->val;
                }
            }
        }
        return ans;
    }
    int maxdepth = INT_MIN;
    int result = 0;
    void traversal(TreeNode *node, int depth)
    {
        // 递归的中止条件
        // 碰到叶子节点就先判断当前深度是不是大于最大深度如果
        // 大于最大深度就更新最大深度同时更新结果
        if (!node->left && !node->right)
        {
            if (depth > maxdepth)
            {
                maxdepth = depth;
                result = node->val;
            }
        }

        if (node->left)
        {
            depth++;
            traversal(node->left, depth);
            depth--;
        }
        if (node->right)
        {
            depth++;
            traversal(node->right, depth);
            depth--;
        }
    }

    int findBottomLeftValue2(TreeNode *root)
    {
        // 递归的思想，其实这个题目不需要考虑
        // 前中后序使用哪一个因为我们的目的找到
        // 最后一层的第一个节点
        // 因此只要保证左在右前面操作即可
        int depth = 1;
        traversal(root, depth);

        return result;
    }
};

class leetcode112
{
public:
    int sum = 0;
    bool flag = false;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        getpath(root, sum, targetSum);
        return flag;
    }

    void getpath(TreeNode *node, int sum, int tar)
    {
        if (!node->left && !node->right)
        {
            sum += node->val;
            if (tar == sum)
            {
                flag = true;
            }
        }
        else
        {
            sum += node->val;
        }

        if (node->left)
        {
            getpath(node->left, sum, tar);
        }
        if (node->right)
        {
            getpath(node->right, sum, tar);
        }
    }
};

class leetcode112_2
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        return traveles(root, targetSum);
    }
    bool traveles(TreeNode *node, int count)
    {
        // 这里用count，最开始赋值为tar的值，每次递归对count-node->val这样我们只需要判断
        // 最后count是不是0就可以知道有没有目标的路径
        if (node->left == nullptr && node->right == nullptr && count == 0)
        {
            return true;
        }

        // 碰到叶子节点但是没有符合的路径就直接返回
        if (!node->left && !node->right)
        {
            return false;
        }

        // 递归主体
        if (node->left)
        {
            if (traveles(node->left, count - node->left->val))
            {
                return true;
            }
        }
        if (node->right)
        {
            if (traveles(node->right, count - node->right->val))
            {
                return true;
            }
        }

        return false;
    }
};

class leetcode112_3
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        // 最后用迭代的方法处理
        // 树的迭代这个题目很明显不能用层序遍历会很麻烦
        // 就使用正常的遍历方式
        if (root == nullptr)
        {
            return false;
        }
        // 这里用的栈存的是一个pair 存放treenode和一个int
        // int就是当前根节点到当前节点路径的和
        stack<pair<TreeNode *, int>> st;
        st.push(pair<TreeNode *, int>(root, root->val));
        while (!st.empty())
        {
            pair<TreeNode *, int> node = st.top();
            st.pop();
            if (node.first->right)
            {
                st.push(pair<TreeNode *, int>(node.first->right, node.second + node.first->right->val));
            }
            if (node.first->left)
            {
                st.push(pair<TreeNode *, int>(node.first->left, node.second + node.first->left->val));
            }
            if (!node.first->left && !node.first->right && node.second == targetSum)
            {
                return true;
            }
        }
        return false;
    }
};

class leetcode113
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        // 这个题目根112路径之和类似，只是那个题目只需返回
        // 是否有满足的路径即可
        // 这个题目需要返回满足的路径
        vector<vector<int>> result;
        vector<int> path;
        if (root == nullptr)
        {
            return result;
        }
        path.push_back(root->val);
        traveles(root, targetSum - root->val, result, path);
        return result;
    }
    void traveles(TreeNode *node, int count, vector<vector<int>> &res, vector<int> &path)
    {
        if (!node->left && !node->right && count == 0)
        {
            res.push_back(path);
        }
        if (!node->left && !node->right)
        {
            return;
        }

        if (node->left)
        {
            path.push_back(node->left->val);
            traveles(node->left, count - node->left->val, res, path);
            path.pop_back();
        }

        if (node->right)
        {
            path.push_back(node->right->val);
            traveles(node->right, count - node->right->val, res, path);
            path.pop_back();
        }
    }
};

class leetcode106
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 从后序与中序构建二叉树
        // 主要思想就是分割中序与后序
        // 很明显后序最后的一个节点就是中节点
        // 找到了中节点然后就可以根据中序进行分割
        // 总体思想如下
        // 1.如果后序数组为0的话，就返回空节点
        // 2.后序数组的最后一个就是中间节点
        // 3.在中序数组找到中间节点
        // 4.分割中序数组
        // 5.分割后序数组
        // 6.递归左中序，左后序
        // 7.递归右中序，右后序

        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return nullptr;
        }
        return build(inorder, postorder);
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
        {
            return nullptr;
        }
        int nodeval = postorder[postorder.size() - 1];
        TreeNode *node = new TreeNode(nodeval);

        // 叶子节点
        if (postorder.size() == 1)
            return node;
        int index = 0;
        for (index = 0; index < inorder.size(); ++index)
        {
            if (inorder[index] == nodeval)
            {
                break;
            }
        }
        // 后序最后一个得删除
        postorder.pop_back();
        //  分割中序
        //  左子树为[0,index) ,右子树为(index,inorder.size]
        vector<int> leftinorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightinorder(inorder.begin() + index + 1, inorder.end());

        // 分割后序
        // 分割后序可以利用中序，因为后序和中序长度应该一致否则就是错误的
        vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftinorder.size());
        vector<int> rightpostorder(postorder.begin() + leftinorder.size(), postorder.end());

        // 左子树递归构建
        node->left = build(leftinorder, leftpostorder);
        // 右子树递归构建
        node->right = build(rightinorder, rightpostorder);

        return node;
    }
};

class leetcode105
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // 和后序、中序构建二叉树类似
        // 1.前序数组如果为空就证明访问到叶子节点返回空
        // 2.前序数组的第一个数就是中间节点
        // 3.利用中序数组找到中间节点的位置
        // 4.分割中序数组
        // 5.分割前序数组
        // 6.递归处理左子树
        // 7.递归处理右子树
        // 分割一定是先分割中序，因为只有分割出来中序我们才能知道左右到底是什么
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return nullptr;
        }
        return build(preorder, inorder);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
        {
            return nullptr;
        }
        int nodeval = preorder[0];
        TreeNode *node = new TreeNode(nodeval);
        if (preorder.size() == 1)
        {
            return node;
        }
        int index = 0;
        for (index = 0; index < inorder.size(); ++index)
        {
            if (inorder[index] == nodeval)
            {
                break;
            }
        }
        // 中序分割
        vector<int> leftinorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightinorder(inorder.begin() + index + 1, inorder.end());
        // 首先要删除前序最前面的元素
        preorder.erase(preorder.begin(), preorder.begin() + 1);
        //  前序分割
        vector<int> leftpreorder(preorder.begin(), preorder.begin() + leftinorder.size());
        vector<int> rightpreorder(preorder.begin() + leftinorder.size(), preorder.end());

        // 左子树构建
        node->left = build(leftinorder, leftpreorder);
        // 右子树构建
        node->right = build(rightpreorder, rightinorder);
        return node;
    }
};

class leetcode654
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        return build(nums);
    }

    TreeNode *build(vector<int> &vec)
    {
        if (vec.size() == 0)
        {
            return nullptr;
        }
        int max = INT_MIN;
        int index = 0;
        for (int i = 0; i < vec.size(); ++i)
        {
            if (max < vec[i])
            {
                max = vec[i];
                index = i;
            }
        }
        TreeNode *node = new TreeNode(max);
        if (vec.size() == 1)
        {
            return node;
        }
        // 分割左数组
        vector<int> left_vec(vec.begin(), vec.begin() + index);
        // 分割右数组
        vector<int> right_vec(vec.begin() + index + 1, vec.end());
        // 递归构建左子树
        node->left = build(left_vec);
        // 递归构建右子树
        node->right = build(right_vec);
        return node;
    }
};

class leetcode617
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        // 这个题目我看到的第一瞬间就是同时遍历两个树
        if (root1 == nullptr && root2 == nullptr)
        {
            return nullptr;
        }
        else if (root1 == nullptr && root2 != nullptr)
        {
            return root2;
        }
        else if (root1 != nullptr && root2 == nullptr)
        {
            return root1;
        }

        return build(root1, root2);
    }

    TreeNode *build(TreeNode *node1, TreeNode *node2)
    {
        TreeNode *node = new TreeNode();
        if (node1 != nullptr && node2 == nullptr)
        {
            return node1;
        }
        else if (node1 == nullptr && node2 != nullptr)
        {
            return node2;
        }
        node->val = node1->val + node2->val;
        node->left = build(node1->left, node2->left);
        node->right = build(node1->right, node2->right);
        return node;
    }
};

class leetcode700
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // 直接用最简单遍历
        TreeNode *node = new TreeNode();
        if (root == nullptr)
        {
            return root;
        }
        if (root->val == val)
        {
            return root;
        }
        else if (root->val > val)
        {
            node = searchBST(root->left, val);
        }
        else
        {
            node = searchBST(root->right, val);
        }
        return node;
    }

    TreeNode *searchBST2(TreeNode *root, int val)
    {
        // 直接用最简单遍历
        // 也可以用迭代法
        if (root == nullptr)
        {
            return root;
        }
        while (root != nullptr)
        {
            if (root->val == val)
            {
                return root;
            }
            else if (root->val > val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return nullptr;
    }
};

class leetcode98
{
public:
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode *root)
    {
        // 判断这个二叉搜索树是不是正确得
        // 中序遍历可以解决
        // 中序遍历是左中右，因此中序遍历得结果就是一个递增得序列
        // 其实就是在中序中判断每次判断一下当前节点是否大于前一个节点
        // 这样就可以解决二叉搜索树是否正确
        if (root == nullptr)
        {
            return true;
        }

        // 左
        bool left = isValidBST(root->left);
        // 中
        if (pre != nullptr && pre->val > root->val)
        {
            return false;
        }
        else
        {
            pre = root;
        }
        // 右
        bool right = isValidBST(root->right);

        return right && left;
    }

    bool isValidBST2(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();
                // 左
                if (node->left)
                {
                    st.push(node->left);
                }
                st.push(node);
                st.push(nullptr);

                //  右
                if (node->right)
                {
                    st.push(node->right);
                }
            }
            else
            {
                st.pop();
                node = st.top();
                st.pop();
                // 中
                if (pre != nullptr && pre->val >= node->val)
                {
                    return false;
                }
                else
                {
                    pre = node;
                }
            }
        }
        return true;
    }
};

class leetcode530
{
public:
    int result = INT_MAX;
    TreeNode *pre = nullptr;
    int getMinimumDifference(TreeNode *root)
    {
        // 二叉搜索树感觉应用最多就是中序遍历
        if (root == nullptr)
        {
            return 0;
        }
        searchmin(root);
        return result;
    }

    void searchmin(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        // 左
        searchmin(node->left);
        // 中
        if (pre != nullptr)
        {
            result = min(result, abs(node->val - pre->val));
        }
        pre = node;
        // 右
        searchmin(node->right);
    }

    int getMinimumDifference2(TreeNode *root)
    {
        // 二叉搜索树感觉应用最多就是中序遍历
        // 迭代法也是可以的
        int result = INT_MAX;
        if (root == nullptr)
        {
            return 0;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();
                if (node->right)
                {
                    st.push(node->right);
                }
                st.push(node);
                st.push(nullptr);
                if (node->left)
                {
                    st.push(node->left);
                }
            }
            else
            {
                st.pop();
                node = st.top();
                if (pre != nullptr)
                {
                    result = min(result, abs(node->val - pre->val));
                }
                pre = node;
                st.pop();
            }
        }
        return result;
    }
};

class leetcode501
{
public:
    TreeNode *pre = nullptr;
    int maxcount = 0, count = 0;
    vector<int> result;
    vector<int> findMode(TreeNode *root)
    {
        // 众数
        // 常规思路就是先遍历一遍二叉树记录最大的出现次数
        // 然后再遍历一遍二叉树将出现次数等于最大出现次数的数放入数组
        // 这样的思路可以解决这个问题
        // 但是可以利用一个前置指针来解决这个问题
        // 这个在二叉搜索树里面比较常见
        // 因此遇到二叉搜索树需要思考到这个方法

        traversal(root);
        return result;
    }

    void traversal(TreeNode *node)
    {
        // 递归中止条件
        if (node == nullptr)
        {
            return;
        }
        // left
        traversal(node->left);
        // mid
        if (pre == nullptr)
        {
            count = 1;
        }
        else if (pre->val == node->val)
        {
            count++;
        }
        else
        {
            if (count > maxcount)
            {
                maxcount = count;
                result.clear();
                result.push_back(node->val);
            }
            count = 1;
        }
        pre = node;
        if (count == maxcount)
        {
            result.push_back(node->val);
        }

        // right
        traversal(node->left);
    }

    vector<int> findMode2(TreeNode *root)
    {
        // 众数
        // 常规思路就是先遍历一遍二叉树记录最大的出现次数
        // 然后再遍历一遍二叉树将出现次数等于最大出现次数的数放入数组
        // 这样的思路可以解决这个问题
        // 但是可以利用一个前置指针来解决这个问题
        // 这个在二叉搜索树里面比较常见
        // 因此遇到二叉搜索树需要思考到这个方法
        // 迭代法也可以的
        stack<TreeNode *> st;
        if (root == nullptr)
        {
            return result;
        }
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != nullptr)
            {
                st.pop();
                if (node->right)
                {
                    st.push(node->right);
                }
                st.push(node);
                st.push(nullptr);
                if (node->left)
                {
                    st.push(node->left);
                }
            }
            else
            {
                st.pop();
                node = st.top();
                st.pop();
                if (pre == nullptr)
                {
                    count = 1;
                }
                else if (pre->val == node->val)
                {
                    count++;
                }
                else
                {
                    count = 1;
                }
                pre = node;
            }
            if (count == maxcount)
            {
                result.push_back(node->val);
            }
            else if (count > maxcount)
            {
                maxcount = count;
                result.clear();
                result.push_back(node->val);
            }
        }

        return result;
    }
};

class leetcode236
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 最近父节点
        // 其实利用得是一个回溯得思想
        // 有递归就有回溯
        // 回溯其实就是把下层得返回给上层处理
        // 这个题目就是利用这个思路，因为我们要找最近父节点，正常来讲是要
        // 从下往上遍历得，但是我们所经历得遍历都是从上往下遍历
        // 因此这种回溯得思路是非常好用得
        /* 递归中止条件，遇到空节点就返回空，遇到p或者q就把q或p返回 */
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (root == p || root == q)
        {
            return root;
        }
        // 左
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // 右
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        /* 中，中处理主要考虑，如果左和右同时不返回空那么此时root节点就是最近公共父节点返回即可
            如果此时左不为空那就返回左，右不为空就返回右，都为空就返回空 */
        if (left && right)
        {
            return root;
        }
        else if (left && !right)
        {
            return left;
        }
        else if (!left && right)
        {
            return right;
        }
        else
        {
            return root;
        }
    }
};

class leetcode235
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 利用二叉搜索树的特点
        // 如果p和q在根节点两侧那么不就直接返回根节点就行了吧

        return traversal(root, p, q);
    }

    TreeNode *traversal(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (node == nullptr)
        {
            return node;
        }

        // 左
        if (node->val > p->val && node->val > q->val)
        {
            TreeNode *left = traversal(node->left, p, q);
            if (left)
            {
                return left;
            }
        }

        // 右
        if (node->val < p->val && node->val < q->val)
        {
            TreeNode *right = traversal(node->right, p, q);
            if (right)
            {
                return right;
            }
        }

        // 证明此时节点就是中间节点直接返回即可
        return node;
    }

    TreeNode *traversal2(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        // 迭代法感觉更简单
        if (node == nullptr)
        {
            return nullptr;
        }

        while (node)
        {
            // 左
            if (node->val > p->val && node->val > q->val)
            {
                node = node->left;
            }
            // 右
            else if (node->val < p->val && node->val < q->val)
            {
                node = node->right;
            }
            else
            {
                return node;
            }
        }
    }
};

class leetcode701
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 确定递归中止条件
        // 当遇到null的时候其实就是该插入的节点的地方了
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }

        // 左
        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }

        // 右
        if (root->val < val)
        {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }

    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // 迭代法
        // 需要有一个pre指针记录因为最后我们也是找到了null才知道
        // 需要插入但是此时以及丢失父节点信息因此需要一个pre来记录
        if (root == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        TreeNode *cur = root;
        TreeNode *pre = root;
        while (cur)
        {
            pre = cur;
            if (cur->val > val)
            {
                cur = cur->left;
            }
            else if (cur->val < val)
            {
                cur = cur->right;
            }
        }
        TreeNode *node = new TreeNode(val);
        if (pre->val > val)
        {
            pre->left = node;
        }
        else
        {
            pre->right = node;
        }
        return root;
    }
};
