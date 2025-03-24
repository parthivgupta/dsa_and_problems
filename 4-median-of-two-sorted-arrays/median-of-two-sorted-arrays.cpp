class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        int n = a + b;
        int ind2 = n / 2;
        int ind1 = n / 2 - 1;
        int cnt = 0;
        int aEl = -1, bEl = -1;
        int i = 0, j = 0;
        while(i < a && j < b) {
            if(nums1[i] < nums2[j]) {
                if(cnt == ind1) aEl = nums1[i];
                if(cnt == ind2) bEl = nums1[i];
                cnt++;
                i++;
            }
            else {
                if(cnt == ind1) aEl = nums2[j];
                if(cnt == ind2) bEl = nums2[j];
                cnt++;
                j++;
            }
        }

        // copy the left out elements
        while(i < a) {
            if(cnt == ind1) aEl = nums1[i];
            if(cnt == ind2) bEl = nums1[i];
                cnt++;
                i++;
        }
        while(j < b) {
            if(cnt == ind1) aEl = nums2[j];
            if(cnt == ind2) bEl = nums2[j];
                cnt++;
                j++;
        }

        if(n % 2 == 1) return (double)bEl;

        return (double)((double)(aEl + bEl)) / 2.0;
    }
};