
//Accepted	20 ms	cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return (int)nums.size();
        
        vector<int>::iterator iter = nums.begin()+1;
        int count = 1;
        int num = *(nums.begin());
        
        for(;iter < nums.end() ; iter++){
            if(num == *iter){
                count++;
                if(count == 3){
                    nums.erase(iter);
                    iter--;
                    count--;
                }
            }
            else{
                num = *iter;
                count = 1;
            }
        }
        return (int)nums.size();
    }
};
