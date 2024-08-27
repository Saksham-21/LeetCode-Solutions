class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int x = n1 + n2;

        // If the total length is odd
        if (x % 2 == 1) {
            int cnt = x / 2;
            int i = 0, j = 0;
            int val;
            
            while (i < n1 && j < n2) {
                if (nums1[i] < nums2[j]) {
                    val = nums1[i];
                    i++;
                } else {
                    val = nums2[j];
                    j++;
                }
                if (cnt == 0) {
                    return (double)val;
                }
                cnt--;
            }

            // If nums1 is exhausted
            while (i < n1) {
                val = nums1[i];
                i++;
                if (cnt == 0) {
                    return (double)val;
                }
                cnt--;
            }

            // If nums2 is exhausted
            while (j < n2) {
                val = nums2[j];
                j++;
                if (cnt == 0) {
                    return (double)val;
                }
                cnt--;
            }

        } else { // If the total length is even
            int index1 = x / 2;
            int index2 = index1 - 1;
            int i = 0, j = 0;
            int val1 = 0, val2 = 0;

            while (i < n1 && j < n2) {
                int val;
                if (nums1[i] < nums2[j]) {
                    val = nums1[i];
                    i++;
                } else {
                    val = nums2[j];
                    j++;
                }
                
                if (index2 == 0) {
                    val1 = val;
                }
                if (index1 == 0) {
                    val2 = val;
                    return (val1 + val2) / 2.0;
                }
                index1--;
                index2--;
            }

            // If nums1 is exhausted
            while (i < n1) {
                int val = nums1[i];
                i++;
                if (index2 == 0) {
                    val1 = val;
                }
                if (index1 == 0) {
                    val2 = val;
                    return (val1 + val2) / 2.0;
                }
                index1--;
                index2--;
            }

            // If nums2 is exhausted
            while (j < n2) {
                int val = nums2[j];
                j++;
                if (index2 == 0) {
                    val1 = val;
                }
                if (index1 == 0) {
                    val2 = val;
                    return (val1 + val2) / 2.0;
                }
                index1--;
                index2--;
            }
        }

        return (double)0; // This line should not be reached with correct input
    }
};