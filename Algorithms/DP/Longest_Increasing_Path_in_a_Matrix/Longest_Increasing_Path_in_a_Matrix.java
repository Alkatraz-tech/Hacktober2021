// Problem Description:- Longest_Increasing_Path_in_a_Matrix
// Link:- https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


class Solution {
    boolean flag[][];   //to block way 
    int arr[][];        //matrix
    int dp[][];         //dp
    int m,n,max=1;      
    public int longestIncreasingPath(int[][] matrix) {
        
        m=matrix.length;
        n=matrix[0].length;
        
        arr=matrix;
        dp=new int[m][n];
        flag=new boolean[m][n];
        
        //longestPath(0,0,-1);
        //exploring each indices and find the max path 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                longestPath(i,j,-1);
            }
        }
        return max;
    }
    
    private int longestPath(int i,int j,int prev){
        //base conditions
        if(i<0 || j<0 || i>=m || j>=n || flag[i][j] || arr[i][j]<=prev){
            return 0;
        }
        
        //if already solved then return it
        if(dp[i][j]!=0)
            return dp[i][j];
        
        int around[][]=new int[][]{{-1,0},{1,0},{0,-1},{0,1}};
        
        //for (i,j) travese neighbours ugind DFS and find the max path
        int tempMax=0;
        flag[i][j]=true;  //bloacking way 
        for(int k=0;k<around.length;k++){
            //dfs
            tempMax=Math.max(tempMax,longestPath(i+around[k][0],j+around[k][1],arr[i][j]));
        }
        flag[i][j]=false;   //unblocking way
        max=Math.max(max,1+tempMax);
        return dp[i][j]=1+tempMax;
    }
    
}
