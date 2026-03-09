class MinStack {
public:
    stack<long long> st;
    long long min;

    // Constructor: initialize minimum as very large value
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int val) {
        long long x = (long long)val;

        // If stack is empty, first element becomes the minimum
        if (st.size() == 0) {
            st.push(x);
            min = x;
        }
        // If new value is greater than or equal to current minimum
        // simply push it normally
        else if (x >= min) {
            st.push(x);
        }
        // If new value is smaller than current minimum
        // we store a "fake encoded value" instead of the real value
        else {
            /*
            Intuition:
            We need to remember the previous minimum without using
            another stack.

            So we push an encoded value = 2*x - min

            This encoded value will always be smaller than the new minimum.
            Later when we pop it, we can detect that it is encoded and
            recover the previous minimum.
            */
            st.push(2 * x - min);
            min = x; // update current minimum
        }
    }
    
    void pop() {
        /*
        If top element is smaller than current minimum,
        it means it is an encoded value and represents
        the point where the minimum was updated.
        */
        if (st.top() < min) {

            /*
            Intuition:
            encoded = 2*x - previousMin
            currentMin = x

            previousMin = 2*currentMin - encoded
            */
            long long oldMin = 2 * min - st.top();
            min = oldMin; // restore previous minimum
        }

        st.pop();
    }
    
    int top() {

        /*
        If top < min, it means top is an encoded value.
        In that case the real value stored at this position
        is the current minimum.
        */
        if (st.top() < min)
            return (int)min;
        else
            return st.top();
    }
    
    int getMin() {
        // Always store current minimum in variable min
        return (int)min;
    }
};

/*
Key Intuition:

Instead of using two stacks (one for values and one for minimum),
we encode values when the minimum changes.

Encoded value = 2 * newMin - oldMin

This allows us to:
1. Detect when the minimum changed
2. Recover the previous minimum during pop

Time Complexity: O(1) for all operations
Space Complexity: O(N) using only one stack
*/