bool dfs(char* s,char* p,int i,int j,int dp[25][25]){

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(p[j]=='\0')
        return dp[i][j]=(s[i]=='\0');

    bool match=(s[i] &&
               (s[i]==p[j] || p[j]=='.'));

    if(p[j+1]=='*'){

        return dp[i][j]=
            dfs(s,p,i,j+2,dp) ||
            (match && dfs(s,p,i+1,j,dp));
    }

    return dp[i][j]=
        match && dfs(s,p,i+1,j+1,dp);
}

bool isMatch(char* s,char* p){

    int dp[25][25];

    memset(dp,-1,sizeof(dp));

    return dfs(s,p,0,0,dp);
}