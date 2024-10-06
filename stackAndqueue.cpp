#include <bits/stdc++.h>

using namespace std;

// leetcode 232
class MyQueue
{
public:
    // 要想使用栈来模拟队列
    // 很显然只使用一个栈是远远不够的
    // 我们可以使用两个栈来模拟队列
    // 一个栈是输入栈，一个栈是输出栈
    stack<int> stackIn;
    stack<int> stackOut;
    MyQueue()
    {
    }

    // 入队列直接往输入栈里面push即可
    void push(int x)
    {
        stackIn.push(x);
    }

    // 出队列，需要使用输出栈，首先判断一下输出栈是否是空的
    // 如果输出栈是空的话，将输入栈中的所有元素push进输出栈
    // 再从输出栈栈顶取元素即可
    int pop()
    {
        if (!stackOut.empty())
        {
            int x = stackOut.top();
            stackOut.pop();
            return x;
        }
        else
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
            int x = stackOut.top();
            stackOut.pop();
            return x;
        }
    }

    int peek()
    {
        // 实现思路与pop基本一致
        // 可以直接使用已经写好的pop
        int x = this->pop();
        stackOut.push(x);
        return x;
    }

    bool empty()
    {
        return stackIn.empty() && stackOut.empty();
    }
};

// leetcode 225
class MyStack
{
public:
    queue<int> stack;
    queue<int> help_stack;
    MyStack()
    {
    }

    void push(int x)
    {
        stack.push(x);
    }

    int pop()
    {
        while (!stack.empty() && stack.size() != 1)
        {
            help_stack.push(stack.front());
            stack.pop();
        }
        int x = stack.front();
        stack.pop();
        while (!help_stack.empty())
        {
            stack.push(help_stack.front());
            help_stack.pop();
        }
        return x;
    }

    int top()
    {
        int x = this->pop();
        stack.push(x);
        return x;
    }

    bool empty()
    {
        if (stack.empty())
        {
            return true;
        }
        return false;
    }
};

class MyStack_2
{
public:
    queue<int> que;
    MyStack_2()
    {
    }

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        int len = que.size();
        len--;
        while (len--)
        {
            que.push(que.front());
            que.pop();
        }
        int x = que.front();
        que.pop();
        return x;
    }

    int top()
    {
        int x = this->pop();
        que.push(x);
        return x;
    }

    bool empty()
    {
        return que.empty();
    }
};

// leetcode 20
class leetcode20
{
public:
    bool isValid(string s)
    {
        stack<char> sat;
        int string_len = s.size();
        if (string_len % 2 == 1)
        {
            return false;
        }
        for (int i = 0; i < string_len; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                sat.push(s[i]);
            }
            else if (s[i] == ')' && !sat.empty())
            {
                if (sat.top() == '(')
                {
                    sat.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == '}' && !sat.empty())
            {
                if (sat.top() == '{')
                {
                    sat.pop();
                }
                else
                {
                    return false;
                }
            }
            else if (s[i] == ']' && !sat.empty())
            {
                if (sat.top() == '[')
                {
                    sat.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return sat.empty() ? true : false;
    }
};

// leetcode 1047
class leetcode1047
{
public:
    string removeDuplicates(string s)
    {
        stack<char> sat;
        string ans;
        for (auto &a : s)
        {
            if (sat.empty() || sat.top() != a)
            {
                sat.push(a);
            }
            else
            {
                sat.pop();
            }
        }
        while (!sat.empty())
        {
            ans += sat.top();
            sat.pop();
        }
        ans.reserve();
        return ans;
    }
};

// leetcode 150
class leetcode150
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> sat;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] >= "1" && tokens[i] <= "9")
            {
                sat.push(stoi(tokens[i]));
            }
            else if (tokens[i] == "+")
            {
                int x = sat.top();
                sat.pop();
                int y = sat.top();
                sat.pop();
                sat.push(x + y);
            }
            else if (tokens[i] == "-")
            {
                int x = sat.top();
                sat.pop();
                int y = sat.top();
                sat.pop();
                sat.push(x - y);
            }
            else if (tokens[i] == "*")
            {
                int x = sat.top();
                sat.pop();
                int y = sat.top();
                sat.pop();
                sat.push(x * y);
            }
            else if (tokens[i] == "/")
            {
                int x = sat.top();
                sat.pop();
                int y = sat.top();
                sat.pop();
                sat.push(x / y);
            }
        }
        return sat.top();
    }
};

// leetcode239
class leetcode239
{
public:
    class Myqueue
    {
    public:
        deque<int> que;
        Myqueue()
        {
        }
        void pop(int value)
        {
            if (!que.empty() && que.front() == value)
            {
                que.pop_front();
            }
        }
        void push(int value)
        {
            while (!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front()
        {
            return que.front();
        }
    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        Myqueue que;
        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
            que.push(nums[i]);
        }
        ans.push_back(que.front());
        for (int j = k; j < nums.size(); ++j)
        {
            que.pop(nums[j - k]);
            que.push(nums[j]);
            ans.push_back(que.front());
        }
        return ans;
    }
};

// leetcode347
class leetcode347
{
public:
    // 小顶堆
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        // 优先级队列配合map解决问题
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i)
        {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> que;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it)
        {
            que.push(*it);
            if (que.size() > k)
            {
                que.pop();
            }
        }
        for (int i = k; i > 0; --i)
        {
            ans.push_back(que.top().first);
            que.pop();
        }
        return ans;
    }

    vector<int> topKFrequent2(vector<int> &nums, int k)
    {
        // 计数排序
        unordered_map<int, int> map;
        for (auto &a : nums)
        {
            map[a]++;
        }
        vector<int> f(nums.size() + 1, 0);
        for (auto &b : map)
        {
            f[b.second]++;
        }
        int count = 0, i = nums.size();
        while (count < k)
        {
            count += f[i--];
        }
        vector<int> ans;
        for (auto &c : map)
        {
            if (c.second > i)
            {
                ans.push_back(c.first);
            }
        }
        return ans;
    }
};
