class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<int> dp(n+1, 0);
        int dp_is1_js1;
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                int tmp = dp[j];
                if(i == 0 && j == 0){
                    dp[j] = 0;
                }else if(j == 0){
                    dp[j] = i;
                }else if(i == 0){
                    dp[j] = j;
                }else if(word1[i-1] == word2[j-1]){
                    dp[j] = dp_is1_js1;
                }else{
                    dp[j] = min({
                        dp[j],
                        dp[j-1],
                        dp_is1_js1
                        }) + 1;
                }
                dp_is1_js1 = tmp;
            }
        }
        
        return dp[n];
    }
};
