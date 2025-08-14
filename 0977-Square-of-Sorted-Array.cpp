class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        vector<int> ans(nums.size());
        int pos = nums.size() - 1;

        while(start <= end){
            int leftsq = nums[start]*nums[start];
            int rightsq = nums[end]*nums[end];
            if(leftsq < rightsq){
                ans[pos--] = rightsq;
                end--;
            } else{
                ans[pos--] = leftsq;
                start++;
            }
        }
        return ans;
    }
};
