class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int max_len = 0;

        st.push(-1); //base index;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();

                if(st.empty()){
                    st.push(i);
                }
                else{
                    max_len = max(max_len, i-st.top());
                }
            }
        }
        return max_len;
    }
};