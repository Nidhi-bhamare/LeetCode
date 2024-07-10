class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string>direct;
        for (int i=0; i<logs.size();i++){
            if (logs [i]=="../" and direct.size()!=0){
                direct.pop_back();
            }
            else  if(logs [i]=="../" and direct.size()==0){
                
            }
            else if(logs[i]!="./"){
                direct.push_back(logs[i]);
                
            }
        }
        return direct.size();
    }
};