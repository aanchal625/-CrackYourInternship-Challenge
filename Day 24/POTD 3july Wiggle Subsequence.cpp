A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

Given an integer array nums, return the length of the longest wiggle subsequence of nums.
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> up(n,1);
        vector<int> down(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }
            else if(nums[i]<nums[i-1]){
                down[i]=up[i-1]+1;
                up[i]=up[i-1];
            }
            else{
                up[i]=up[i-1];
                down[i]=down[i-1];
            }
        }
        return max(up[n-1],down[n-1]);
        
    }
};

//little bit optimized
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int up=1;
        int down=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
               up=down+1;
            }
            else if(nums[i]<nums[i-1]){
                down=up+1;
            }
        }
        return max(up,down);
        
    }
};