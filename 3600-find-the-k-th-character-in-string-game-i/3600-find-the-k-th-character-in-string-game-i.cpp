class Solution {
public:
    char kthCharacter(int k) {
        string word ="a";

        while (word.length()<k){
            string nextPart="";
            for(char ch:word){
                if(ch=='z')
                   nextPart+='a';
                else
                   nextPart +=ch+1;

            }
            word +=nextPart;

        }
        return word[k-1];
        
    }
};