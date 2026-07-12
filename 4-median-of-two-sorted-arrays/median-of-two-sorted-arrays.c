double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    // Make nums1 the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;

    int left = 0;
    int right = m;

    while (left <= right) {

        int cut1 = (left + right) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {

            if ((m + n) % 2 == 0) {
                return (double)(fmax(left1, left2) +
                                fmin(right1, right2)) / 2;
            }
            else {
                return fmax(left1, left2);
            }
        }

        else if (left1 > right2) {
            right = cut1 - 1;
        }
        else {
            left = cut1 + 1;
        }
    }

    return 0.0;
}