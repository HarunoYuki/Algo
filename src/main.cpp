#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "sort/sort.hpp"
#include "find/find.hpp"
#include "tree/tree.hpp"
#include "base/list.hpp"


/**
 * @file static.cpp
 * @brief 静态数据成员
 * 静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员，但不影响类的大小。不管这个类产生了多少个实例，还是派生了多少新的类，静态数据成员只有一个实例。静态数据成员，一旦被声明，就已经存在。
 * @author 光城
 * @version v1
 * @date 2019-07-21
 */
#include<iostream>
using namespace std;

class A
{
public:
    double b;
    A() {
        fun();
    }
    ~A() {
        fun();
    }
    virtual void fun() {

    }
};

class B :A {
public:
    B():A() {
        fun();
    }
    void fun() {
        cout << " B " << endl;
    }
};

int maxArea(vector<int>& height) {
    int l = 0, r = height.size()-1;
    int ans = 0;
    while (l<r)
    {
        ans = max(ans, int((r - l) * min(height[l], height[r])));
        if (height[l] < height[r]) {
            l++;
        }
        else {
            r--;
        }
    }
    return ans;
}

bool check(string& str) {
    int n = str.size();
    int l = 0, r = n - 1;
    while (l < r) {
        if (str[l] != str[r]) {
            return false;
        }
        l++; r--;
    }
    return true;
}

void backtrack(vector<string>& state, int s,string& ori, vector<vector<string>>& res) {
    if (s == ori.size()) {
        res.push_back(state);
        return;
    }
    for (size_t i = s; i < ori.size(); i++)
    {
        string str = ori.substr(s, i - s+1);
        if (!check(str)) {
            continue;
        }
        state.push_back(str);
        backtrack(state, i+1,ori, res);
        state.pop_back();
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> state;
    backtrack(state, 0, s, res);
    return res;
}


int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) { return 0; }
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++) {
        for (int a = 1; a <= amount; a++) {
            if (coins[i] <= a) {
                dp[a] = min(dp[a], dp[a - coins[i]] + 1);
            }
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st;
    for (size_t i = 0; i < wordDict.size(); i++)
    {
        st.insert(wordDict[i]);
    }
    return true;
}

void simulator() {
    unordered_map<int, int> mp;
    queue<int> que;
    int n = 0;
    cin >> n;
    while (n--)
    {
        int type = 0;
        cin >> type;
        if (type == 1) {
            string s;
            cin >> s;
            int val = static_cast<int>(*s.c_str());
            que.push(val);
            mp[val]++;
        }
        else if (type == 2) {
            int val = que.front();
            que.pop();
            mp[val]--;
        }
        else if (type == 3) {
            int num = 0;
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                if (it->second > 0) {
                    num++;
                }
            }
            cout << num << endl;
        }
    }
}

void jumpStones() {
    int stones = 0, jd = 0;
    cin >> stones >> jd;
    vector<int> dis(stones);
    vector<int> nums(jd);
    for (size_t i = 0; i < stones; i++)
    {
        cin >> dis[i];
    }
    for (size_t i = 0; i < jd; i++)
    {
        cin >> nums[i];
    }
    int ans = 0;
    for (size_t i = 0; i < stones; i++)
    {
        if (dis[i] > jd) {
            break;
        }
        else {
            int idx = dis[i] - 1;
            if (nums[idx]>0) {
                ans += 30;
                nums[idx] -= 1;
            }
            else {
                break;
            }
        }
    }
    cout << ans << endl;
}

class SnapshotArray {
private:
    vector<int> nums;
    unordered_map<int, vector<int>> mp;
public:
    SnapshotArray(int length) {
        nums.resize(length);
    }

    void set(int index, int val) {
        nums[index] = val;
    }

    int snap() {
        static int id = -1;
        id++;
        mp[id] = nums;
        return id;
    }

    int get(int index, int snap_id) {
        return mp[snap_id][index];
    }
};

struct C
{
    virtual void print();
};

struct D : C
{
    int a;
    bool b;
};

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    auto matches = [&](int i, int j) {
        if (i == 0) {
            return false;
        }
        if (p[j - 1] == '.') {
            return true;
        }
        return s[i - 1] == p[j - 1];
        };

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (matches(i, j - 1)) {
                    dp[i][j] |= dp[i - 1][j];
                }
            }
            else if (p[j - 1] == '?') {
                if (matches(i, j - 1)) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - 2];
                }
            }
            else {
                if (matches(i, j)) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }
    return dp[m][n];
}

class MyClass
{
};

class MyClass2: MyClass
{
};

int qpow(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1)        //如果n的当前末位为1
            ans *= a;  //ans乘上当前的a
        a *= a;        //a自乘
        n >>= 1;       //n往右移一位
    }
    return ans;
}

struct Matrix {
    long long m[2][2];
    Matrix() {
        m[0][0] = m[0][1] = m[1][0] = 1;
        m[1][1] = 0;
    }
    Matrix operator*(const Matrix& b) {
        Matrix res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.m[i][j] += this->m[i][k] * b.m[k][j];
                }
            }
        }
        return res;
    }
};

long long qpow(long long n) {
    Matrix ans;
    Matrix base;
    while (n) {
        if (n & 1) {
            ans = ans * base;
        }
        base = base * base;
        n >>= 1;
    }
    return ans.m[0][0];
}

int main() {
    int* b = (int*)malloc(0);
    int* a = new int[0];
    cout << a << endl;
    cout << a[0] << endl;
    cout << b << endl;
    cout << b[0] << endl;
    delete[] a;
    qpow(2,10);
    cout << qpow(5 - 2) << endl;;

    //vector<A> a;
    //A val;
    //a.push_back(val);
    //a.emplace_back(val);
    //cout<< sizeof(MyClass) <<endl;
    //cout<< sizeof(MyClass2) <<endl;

    int i = 0x12345678;

    if (*((char*)&i) == 0x12)
        cout << "大端" << endl;
    else
        cout << "小端" << endl;

	treeTest();
    sortTest();
	return 0;
}