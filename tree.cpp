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
    bool isSymmetric(TreeNode *root)
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
    }
};

class leetcode112
{
public:
    int sum = 0;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        return getpath(root, sum, targetSum);
    }

    bool getpath(TreeNode *node, int sum, int tar)
    {
        if (!node->left && !node->right)
        {
            sum += node->val;
            if (tar == sum)
            {
                return true;
            }
        }

        if (node->left)
        {
            getpath(node->left, sum, tar);
        }
        if (node->right)
        {
            getpath(node->right, sum, tar);
        }
        return false;
    }
};