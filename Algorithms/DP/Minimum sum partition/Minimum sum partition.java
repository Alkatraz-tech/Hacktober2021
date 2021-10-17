class Solution
{

	public int minDifference(int arr[], int n) 
	{ 
	    // Your code goes here
	    if (n==1)
	        return arr[0];
	    int summing = Arrays.stream(arr).sum();
	    int sum = summing/2;
	    boolean dp[][] = new boolean [n+1][sum+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j =0;j<= sum; j++)
	        {
	            if(j==0)
	                dp[i][j] = true;
	            else if(i==0)
	                dp[i][j] = false;
	            else if(arr[i-1]> j)
	                dp[i][j] = dp[i-1][j];
	            else
	                dp[i][j] = dp[i-1][j]|| dp[i-1][j-arr[i-1]];
	        }
	    }
	    for (int i = sum; i>0;i--)
	    {
	        if(dp[n][i] == true)
	            return summing - (2*i);
	    }
	    
	    return 0;
	} 
}
