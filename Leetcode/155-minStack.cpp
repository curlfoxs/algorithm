class MinStack {
public:
    stack<array<int, 2>> st;
    MinStack() {
        st=stack<array<int, 2>>();
    }

    void push(int val) {
        if(st.size())
            st.push({min(val, st.top()[0]), val});
        else
            st.push({val, val});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top()[1];
    }

    int getMin() {
        return st.top()[0];
    }
};
