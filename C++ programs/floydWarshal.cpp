#include <bits/stdc++.h>

using namespace std;

const int N = 501;
#define INF 1LL<<60

long long dp[N][N]; // min distance from i to j 

void floydWarshal()
{
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<N;j++)
        {
            dp[i][j] = INF;
            if(i==j)dp[i][j]=0;
        }
    }
    int n,m;
    cin>>n>>m;

    for(int i = 0;i<n;i++)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        dp[a][b] = min(dp[a][b],(long long) wt);
        // dp[b][a] = min(dp[b][a],wt); // ifdouble path
    }
    for(int k = 1;k<=n;k++)
    {
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(dp[i][k]!=INF && dp[k][j]!=INF)
                    dp[i][j] = min(dp[i][k]+dp[k][j],dp[i][j]);
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(dp[i][j]==INF)cout<<-1;
            else cout<<dp[i][j];

            cout<<" ";
        }
        cout<<endl;
    }
   
}

int main()
{
    std::ios::sync_with_stdio(false), cin.tie(__null), cout.tie(__null);

    floydWarshal();
}

