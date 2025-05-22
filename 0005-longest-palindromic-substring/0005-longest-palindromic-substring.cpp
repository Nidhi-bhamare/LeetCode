class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return"" ;

        int maxLen=1;
        int start =0;

        for(int i=0;i<n;++i){
            for (int j=i;j<n;++j){
                if(isPalindrome(s,i,j)){
                    int len =j-i+1;
                    if(len>maxLen){
                        maxLen=len;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);


    }
    private:
    bool isPalindrome (string&s, int left,int right)
{
    while(left<right){
      if (s[left]!=s[right])return false;
     
      left++;
      right--;  
    } 
    return true;
}
};