class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string &s, string &p, int i, int j){

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(j==p.size())
            return dp[i][j]=(i==s.size());

        bool match=(i<s.size() &&
                   (s[i]==p[j] || p[j]=='.'));

        if(j+1<p.size() && p[j+1]=='*'){

            return dp[i][j]=
                solve(s,p,i,j+2) ||
                (match && solve(s,p,i+1,j));
        }

        return dp[i][j]=
            match && solve(s,p,i+1,j+1);
    }

    bool isMatch(string s, string p) {

        dp.assign(s.size()+1,
                  vector<int>(p.size()+1,-1));

        return solve(s,p,0,0);
    }
};