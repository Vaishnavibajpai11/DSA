class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        int ans = 0;
        int start = -1;


        for(int i=0;i<s.size();i++){

            if(s[i]=='(')
                st.push(i);

            else{

                if(st.empty())
                    start=i;

                else{

                    st.pop();

                    if(st.empty())
                        ans=max(ans,i-start);

                    else
                        ans=max(ans,i-st.top());
                }
            }
        }

        return ans;
    }
};