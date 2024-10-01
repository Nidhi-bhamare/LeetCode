class Solution {
public:
    static bool canArrange(vector<int>& arr, int k) {
        const int h=k/2;
        vector<int> freq(h+1, 0);
        for(int x: arr){
            x%=k;
            if (x<0) x+=k;
            (x>h)?freq[k-x]--:freq[x]++;
        }

        if (k%2==0 && freq[h]%2!=0) return 0;
        int k2=h-(k%2==0);
        return !any_of(freq.begin()+1, freq.begin()+k2+1,
        [](int x){return x!=0;});
    }
};