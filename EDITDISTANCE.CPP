Question
Given two strings s and t. Return the minimum number of operations required to convert s to t.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
  
  
  
  Solution
   int editDistance(string s, string t) {
        // Code here
         
        int DP[2][t.size()+1];
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=t.size();j++){
                if(j==0){
                    DP[i%2][j]=i;
                }
                else if(i==0){
                    DP[i%2][j]=j;
                }
                else if(s[i-1]==t[j-1]){
                    DP[i%2][j]=DP[(i-1)%2][j-1];
                }
                else{
                    DP[i%2][j]=1+min(DP[(i-1)%2][j-1],
                    min(DP[(i-1)%2][j],DP[i%2][j-1]));
                }
            }
        }
        return DP[s.size()%2][t.size()];
    
    }
