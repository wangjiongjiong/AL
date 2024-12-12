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

class leetcode17
{

private:
    vector<string> ans;
    string s;
    const string letter_map[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};
    void
    backtracking(string digits, int start)
    {
        if (start == digits.size())
        {
            ans.push_back(s);
            return;
        }
        int letter = digits[start] - '0';
        string l = letter_map[letter];
        for (int i = 0; i <= l.size(); ++i)
        {
            s.push_back(l[i]);
            backtracking(digits, start);
            s.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return;
        }
        backtracking(digits, 0);
        return ans;
    }
};

class leetcode39
{

private:
    vector<vector<int>> ans;
    vector<int> vec;
    int sum = 0;
    void backtracking(vector<int> &candidates, int target, int start)
    {
        if (sum > target)
        {
            return;
        }
        if (vec.size() == candidates.size() && sum == target)
        {
            ans.push_back(vec);
            return;
        }

        for (int i = start; i < candidates.size(); ++i)
        {
            sum += candidates[i];
            vec.push_back(sum);
            backtracking(candidates, target, i);
            sum -= candidates[i];
            vec.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(candidates, target, 0);
        return ans;
    }
};

class leetcode40
{

private:
    vector<int> path;
    vector<vector<int>> ans;
    void backtracking(vector<int> &candidates, int target, int sum, int startindex)
    {
        if (sum > target)
        {
            return;
        }
        else if (sum == target)
        {
            ans.push_back(path);
            return;
        }

        for (int i = startindex; i < candidates.size(); ++i)
        {
            if (i > startindex && candidates[i - 1] == candidates[i])
            {
                continue;
            }

            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i + 1);
            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};

class leetcode131
{

private:
    vector<string> path;
    vector<vector<string>> ans;

    bool isPalindrome(string s, int startindex, int end)
    {
        for (int i = startindex, j = end; i < j; ++i, --j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    void backtracking(string s, int startindex)
    {
        if (startindex == s.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = startindex; i < s.size(); ++i)
        {
            if (isPalindrome(s, startindex, i))
            {
                string str = s.substr(startindex, i - startindex + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }

            backtracking(s, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return ans;
    }
};

int main()
{

    return 0;
}