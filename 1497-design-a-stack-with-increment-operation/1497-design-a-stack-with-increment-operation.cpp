class CustomStack {
public:
    vector<int> st;  // Stack simulation using vector
    vector<int> inc; // To store increments
    int count;

    // Constructor to initialize max size
    CustomStack(int maxSize) {
        count = maxSize;
        st.resize(0);  // Initialize empty stack
        inc.resize(0); // Initialize increments array
    }

    // Push function
    void push(int x) {
        if (st.size() < count) {
            st.push_back(x);       // Push element to stack
            inc.push_back(0);      // Push 0 increment for new element
        }
    }

    // Pop function
    int pop() {
        if (st.empty()) return -1; // If stack is empty, return -1
        int idx = st.size() - 1;   // Get the top element index
        int result = st[idx] + inc[idx]; // Apply any pending increment to the top element

        if (idx > 0) {
            inc[idx - 1] += inc[idx];  // Carry over increment to the next element below
        }

        st.pop_back();   // Remove the top element
        inc.pop_back();  // Remove the corresponding increment
        return result;   // Return the popped value
    }

    // Increment bottom k elements by val
    void increment(int k, int val) {
        int idx = min(k, (int)st.size()) - 1;  // Limit k to the stack size
        if (idx >= 0) {
            inc[idx] += val;  // Add val to the k-th element's increment
        }
    }
};
