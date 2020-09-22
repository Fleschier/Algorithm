/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    int myStack[1000];          //栈不能太小,有的案例会报错
    int stackTop;           //下一个数要放的位置

    MinStack() {
        stackTop = 0;
    }
    
    void push(int x) {
        if(stackTop == 999) return;          //溢出
        myStack[stackTop] = x;
        stackTop++;
    }
    
    void pop() {
        if(stackTop == 0) return;        //空栈
        stackTop--;
    }
    
    int top() {
        return myStack[stackTop - 1];
    }
    
    int getMin() {
        int min = 2147483647;           //md测试案例真NB
        for(int i  = 0; i < stackTop; i++){
            if(myStack[i] < min) min = myStack[i];
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

