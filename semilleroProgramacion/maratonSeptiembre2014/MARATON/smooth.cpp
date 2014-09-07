using namespace std;

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <iterator>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <cassert>

const int MAXN = 100005;

int main () {
    int dpclean[MAXN][2];
     int iniclean [MAXN];
    int n, m;
    while(cin >> n){
        vector<int> vec;
        for(int i=0; i<n;++i){
            cin >> m;
            vec.push_back(m);
        }
        int dp [MAXN][2];
        int ini [MAXN];
        int res = 1;
        for(int i=n-1; i>=0;--i){
            dp [n-1][2]=0;
            ini [i]=n-i+1;
        }
        bool entro = false;
        for(int i=n-2; i>=0;--i){
            dp[i][1]=0;
            if(vec[i]>=vec[i+1]){dp[i+1][1]=1;}
            for(int j=i+2; j<(n-1);j++){
                dp[j][1]=dp[j][0]+dp[j-1][1]-dp[j-1][0];
                //cout << dp[j][1]<< endl;
                ini[i]= j-i+1;
                //cout << "aquello "<<j-i<< endl;
                if(dp[j][1]==2&&(dp[j-1][1]<2)){
                    ini[i]= j-i+1;
                    //cout << "esto "<<j-i<< endl;
                    if(ini[i]>res)res=ini[i];
                    entro = true;
                }
            }
            for(int h=n-1; h>=i+1;--h){
                dp[h][0]=dp[h][1];
            }
            if(i==0&&(!entro)){
                res=n;
                //cout << "WI "<< endl;
            }
        }
        /*
        for(int i=0; i<n-1;++i){
            if(vec[i]>=vec[i+1])dp[i][i+1]=1;
            ini[i] = n-i;
        }
        bool entro = false;
        for(int i=2;i<n;++i){
                //cout << "entre "<< endl;
            for(int j=0; j<(n-i)-1;++j){
                //cout << "dp"<< endl;
                dp[j][i+j]=(dp[j+1][i+j]+dp[j][i+j-1]-dp[j+1][i+j-1]);
                if(dp[j][i+j]==2&&(dp[j][i+j-1]<2)){
                    ini[j]= i+1;
                    cout << i<< endl;
                    if(ini[j]>res)res=ini[j];
                    entro = true;  //cout << "LOL "<< endl;
                }
            }
            if(i==n-1&&(!entro)){
                res=n;
                //cout << "WI "<< endl;
            }
        }*/
        cout << res << endl;
        vec.clear();
        for(int w=n-1; w>=0;--w){
            ini[w]=0;
            dp[w][0]=0;
            dp[w][1]=0;
        }
        res = 1;
        entro = false;
    }
    return 0;
}
