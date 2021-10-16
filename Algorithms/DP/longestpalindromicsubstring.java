// problem statement:- https://leetcode.com/problems/longest-palindromic-substring/


    public String longestPalindrome(String s) {
        int best_len = 0 ;
        String best_str = "";
        int n = s.length();

        //for even length string
        for(int mid = 0; mid < n; mid++) {
        	for(int x = 0; (mid-x) >=0 && (mid+x) < n; x++ ) {
        		if(s.charAt(mid-x) != s.charAt(mid+x)) {
        			break;
        		}
        		int len = (2*x) +1 ;
        		if(len > best_len) {
        			best_len = len;
        			best_str = s.substring(mid-x, mid-x+len);
        		}

        	}
        }
        //for odd length string
        for(int mid = 0; mid < n-1; mid++) {
        	for(int x = 1; (mid-x+1) >=0 && (mid+x) < n; x++ ) {
        		if(s.charAt(mid-x+1) != s.charAt(mid+x)) {
        			break;
        		}
        		int len = (2*x);
        		if(len > best_len) {
        			best_len = len;
        			best_str = s.substring(mid-x+1, mid-x+1+len);
        		}

        	}
        }
        return best_str;
    }
