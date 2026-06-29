#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    // Always binary search on the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;

    int low = 0, high = m;

    while (low <= high) {

        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        int maxLeftX  = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        int maxLeftY  = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        // Correct partition
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {

            // Even number of elements
            if ((m + n) % 2 == 0) {
                int leftMax = (maxLeftX > maxLeftY) ? maxLeftX : maxLeftY;
                int rightMin = (minRightX < minRightY) ? minRightX : minRightY;

                return (leftMax + rightMin) / 2.0;
            }

            // Odd number of elements
            return (maxLeftX > maxLeftY) ? maxLeftX : maxLeftY;
        }

        // Move left
        if (maxLeftX > minRightY) {
            high = partitionX - 1;
        }
        // Move right
        else {
            low = partitionX + 1;
        }
    }

    return 0.0;
}