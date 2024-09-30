#include <iostream>
#include <algorithm>
#include <string>
#include <ranges>
#include <unordered_set>
#include <unordered_map>
#include "sort/sort.hpp"
#include "find/find.hpp"
#include "tree/tree.hpp"
#include "base/list.hpp"
#include "thread/thread.hpp"
#include "pointer/shared_ptr.hpp"


/**
 * @file static.cpp
 * @brief 静态数据成员
 * 静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员，但不影响类的大小。不管这个类产生了多少个实例，还是派生了多少新的类，静态数据成员只有一个实例。静态数据成员，一旦被声明，就已经存在。
 * @author 光城
 * @version v1
 * @date 2019-07-21
 */
using namespace std;

class A
{
public:
    short a;
    char c;
    int b;
    //A() {
    //    fun();
    //}
    //~A() {
    //    fun();
    //}
    //virtual void fun() {

    //}
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

int c = 1;
class MyClass
{
public:
    int& a = c;
    ~MyClass(){
        cout << "Suasidj  " << endl;
    }
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

template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

// 特化模板的基准情况
template <>
struct Factorial<0> {
    static const int value = 1;
};



int main() {
    function<int(int)> dfs = [&](int i)->int {
        if (i < 0) {
            return 0;
        }
        return dfs(i - 1) + i;
    };
    cout << dfs(5) << endl;

    treeTest();
    sortTest();
    ThreadPool pool(4);
    auto result1 = pool.push([] {return string("Hello From ThreadPool"); });
    auto result2 = pool.push([](int x, int y) {return x * y; }, 1, 5);
    cout << result1.get() << endl;
    cout << result2.get() << endl;

    // 创建SharedPtr对象
    SharedPtr<int> ptr1(new int(42));
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;  // 输出 1

    {
        // 创建SharedPtr对象的副本
        SharedPtr<int> ptr2(ptr1);
        std::cout << "ptr1 use_count after copy: " << ptr1.use_count() << std::endl;  // 输出 2
        std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;  // 输出 2
        std::cout << "ptr2 value: " << *ptr2 << std::endl;  // 输出 42
    }

    {
        SharedPtr<int> ptr2(new int(0));
        ptr2 = ptr1;
        std::cout << "ptr1 use_count after copy: " << ptr1.use_count() << std::endl;  // 输出 2
        std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;  // 输出 2
        std::cout << "ptr2 value: " << *ptr2 << std::endl;  // 输出 42
    }

    // 离开作用域，ptr2销毁
    std::cout << "ptr1 use_count after ptr2 destroyed: " << ptr1.use_count() << std::endl;  // 输出 1

    // 重置指针
    ptr1.reset(new int(84));
    std::cout << "ptr1 use_count after reset: " << ptr1.use_count() << std::endl;  // 输出 1
    std::cout << "ptr1 value: " << *ptr1 << std::endl;  // 输出 84

    return 0;

    thread_test();
    //cout << MYmax(1, 2)<<endl;
    //cout << MYmax(1.0, 2.0)<<endl;

    int result = Factorial<5>::value;  // 计算5! = 120
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
    auto tem = std::make_shared<MyClass>();
    tem.reset();
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