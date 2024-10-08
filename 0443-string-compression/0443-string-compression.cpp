class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char>s;
        map<char,int>st;
        for(char i:chars){
            st[i]++;
        }
        int i=0;
        int n=chars.size();
        while(i<n){
            char cu=chars[i];
            int c=0;
            while(i<n&&chars[i]==cu){
                i++;
                c++;
            }
            s.push_back(cu);
            if(c>1){
                string b=to_string(c);
                for(char i:b){
                    s.push_back(i);
                } 
            }
        }
        chars.clear();
        for(char i:s){
            chars.push_back(i);
        }
        return chars.size();
    }
    
};