class Solution {
public:
    /*
     1) Merge them as a sorted array, then pick the median -> O(m+n)
     2) Binary search based?
     
        Say for nums1, we cut at location i: i elements at left, m - i at right (i: 0 ~ m)
        then, j:= (m+n+1)/2 - i needs to be at the left, and n - j at right 
        Also, the following condition must be met:
        A[i] >= B[j-1]
        B[j] >= A[i-1]
        
        Otherwise, need to search for different i. 
        If A[i] < B[j-1], search for range larger than current i (ascending assumed)
        If B[j] < A[i-1], search for range less than current i. 
        
        To make j non-negative, let's pick min (m,n) for i. 
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        if (size1 > size2) {
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            
            size1 = nums1.size();
            size2 = nums2.size();
        }
        
        if (size1 == 0 && size2 == 0)
            return (0.0);
        
        if (size1 == 0) {
            if (size2%2)
                return nums2[size2/2];
            else
                return (nums2[size2/2] + nums2[size2/2-1])/2.0;
        }
        
        cout << "Now general case!" << endl;
        
        int imin = 0;
        int imax = size1;
        int i, j;
        
        while (imin <= imax) {
            i = (imin + imax)/2;
            j = (size1+size2+1)/2 - i; // so, the lower half could have 1 more element than upper half. 
            
            if (i < size1 && nums1[i] < nums2[j-1]) // j > 0 enough for i < m? => Doesn't work for [1], [2,3]
                imin = i+1;
            else if (i > 0 && nums1[i-1] > nums2[j]) // i > 0 enough for j < n
                imax = i-1;
            else {// the right i!
                cout << "i,j: " << i << " " << j << endl;
                
                int maxLeft, minRight;
                if (j == 0)
                    maxLeft = nums1[i-1];
                else if (i == 0)
                    maxLeft = nums2[j-1];
                else
                    maxLeft = max(nums1[i-1],nums2[j-1]);
                    
                if ((size1+size2)%2) 
                    return maxLeft;
                
                if (j == size2)
                    minRight = nums1[i];
                else if (i == size1)
                    minRight = nums2[j];
                else
                    minRight = min(nums1[i],nums2[j]);
                
                return (maxLeft + minRight)/2.0;
            }
        }
        
        return (0.0); // shouldn't happen.
    }
};
