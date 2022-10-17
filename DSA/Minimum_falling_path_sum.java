
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int min = Integer.MAX_VALUE;
        int dp[][] = new int[matrix.length][matrix[0].length];
        for(int[] m :dp){
            Arrays.fill(m,-1);
        }
         for(int j=0; j<matrix[0].length; j++){
        min =  Math.min(min,helper(0,j,matrix,dp));
         }
        return min;
    }
    public int helper(int i,int j,int[][] matrix,int[][] dp){
        if(j<0 || j>=matrix[0].length)
            return (int)Math.pow(10,9);
        if(i == matrix.length-1)
            return matrix[i][j];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
       int down = matrix[i][j] + helper(i+1 , j ,matrix,dp);
     int leftdiag = matrix[i][j] + helper(i+1,j-1,matrix,dp);
      int rightdiag = matrix[i][j] + helper(i+1,j+1,matrix,dp);
                                              
        return dp[i][j] = Math.min(down,Math.min(leftdiag,rightdiag));
    }
}
