#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    int v[61];
    int dp[61][32001];
    int q[61];
    int vp[61];
    int N,m;
    while(cin >> N >> m)
    {
        for(int i=0;i<61;i++)
            memset(dp[i], 0, sizeof(dp[i]));
        int tmpw;
        for(int i=1;i<=m;i++)
        {
            cin >> v[i] >> tmpw >> q[i];
            vp[i] = v[i] * tmpw;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(q[i] == 0)
                {
                    if(v[i]<=j)
                    {
                        dp[i][j] = max(dp[i-1][j-v[i]]+vp[i], dp[i-1][j]);
                    }
                }
                else
                {
                    if(v[i] + v[q[i]] <= j)
                    {
                        dp[i][j] = max(dp[i-1][j-v[i]]+vp[i], dp[i-1][j]);
                    }
                }
            }
        }
        cout << dp[m][N] << endl;
    }
    return 0;
}