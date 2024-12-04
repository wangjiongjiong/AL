#include <bits/stdc++.h>

using namespace std;

class leetcode77
{

private:
    std::vector<int> path;
    std::vector<vector<int>> ans;
    void backtracking(int n, int k, int start)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return ans;
    }
};

class leetcode216
{

private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(int k, int n, int start, int sum)
    {
        if (path.size() == k && n == sum)
        {
            ans.push_back(path);
            return;
        }
        for (int i = start; i <= 9; ++i)
        {
            path.push_back(i);
            sum += i;
            backtracking(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtracking(k, n, 1, 0);
        return ans;
    }
};

int main()
{

    return 0;
}