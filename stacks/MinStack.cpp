class MinStack {
public:
    stack< pair<int,int> > st;
    MinStack() {
        
    }
    
    void pop(){
        if(st.empty())
            return;
        st.pop();
    }

    void push(int val){
        pair<int,int> p;
        int minYet;
        if( st.empty() != 1 && st.top().second < val )
                minYet = st.top().second;
        else
                minYet = val;

        p = make_pair(val,minYet);
        st.push(p);
    }

    int top(){
        if(st.empty())
            return 0;

        return st.top().first;
    }

    int getMin(){
        if(st.empty())
            return 0;

        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */