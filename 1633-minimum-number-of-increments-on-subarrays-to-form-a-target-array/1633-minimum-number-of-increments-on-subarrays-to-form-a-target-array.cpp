class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int operations=target[0];
        for (int i=1;i<target.size();++i){
            if (target[i]>target[i-1]){
                operations+= (target[i]-target[i-1]);
            }
        }
        return operations;
        
    }
};

// //[3,1,5,4,2]


// 1 0000
// 20000
// 30000

// 31111
// 31221
// 31331
// 31441



// 11111
// 20000
// 11111
// 31111
// 31221
// 31331
// 31441
