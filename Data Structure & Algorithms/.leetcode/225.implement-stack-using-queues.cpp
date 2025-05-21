/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
public:
    stack<int> st;

public:
    MyStack()
    {
        st = stack<int>();
    }

    void push(int x)
    {
        st.push(x);
    }

    int pop()
    {
        int tmp = st.top();
        st.pop();
        return tmp;
    }

    int top()
    {
        return st.top();
    }

    bool empty()
    {
        return st.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
