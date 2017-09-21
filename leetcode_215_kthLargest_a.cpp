class Solution {
public:
    /*
     * 1) Sort the array in descending order then pick the kth one. => nlogn
     * 2) Do a quick-sort based approach then as soon as finding the kth index, return!
     * 3) Using an extra data structure... e.g., heap... nlogk
     */
    
    int findKthLargestImpl(vector<int>& nums, int left, int right, int k) {
        int pivot = nums[right];
        int temp, idxl = left, idxr = right;
        while (true) {
            while (nums[idxl] > pivot && idxl < idxr)
                idxl++;
            
            while (nums[idxr] <= pivot && idxl < idxr)
                idxr--;
            
            if (idxl == idxr)
                break;
            
            temp = nums[idxl];
            nums[idxl] = nums[idxr];
            nums[idxr] = temp;
        }
        
        temp = nums[idxl];
        nums[idxl] = pivot;
        nums[right] = temp;
        
        if (idxl+1 == k)
            return nums[idxl];
        else if (idxl+1 < k) 
            return findKthLargestImpl(nums, idxl+1, right, k);
        
        return findKthLargestImpl(nums, left, idxl-1, k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        // assume k is valid for now.
        return findKthLargestImpl(nums, 0, nums.size()-1, k);
    }
};
