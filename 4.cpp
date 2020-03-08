class Solution {
public:
    double findHelper(vector<int>& nums1, int idx1, int len1, vector<int>& nums2, int idx2, int len2, int median){

        if(len1 > len2)
            return findHelper(nums2, idx2, len2, nums1, idx1,len1, median);
        else if(len1 <= 0)
            return nums2[idx2 + median -1];
        else if(median == 1)
            return min(nums1[idx1], nums2[idx2]);

        int mid1, mid2, temp1, temp2;
        temp1 = min(median/2, len1);
        mid1 = idx1 + temp1 - 1;
        temp2 = median - temp1;
        mid2 = idx2 + temp2 - 1;

        if(nums1[mid1] == nums2[mid2])
            return nums1[mid1];
        else if(nums1[mid1] < nums2[mid2])
            return findHelper(nums1, mid1 + 1, len1 - temp1, nums2, idx2, len2, median - temp1);
        else
            return findHelper(nums1, idx1, len1, nums2, mid2 + 1, len2 - temp2, median - temp2);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > 0 || nums2.size() > 0){
            int items = nums1.size() + nums2.size();
            if(items % 2 == 1){
                return findHelper(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (item2/2) + 1);
            }else{
                return (
                    findHelper(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (item2/2)) +
                    findHelper(nums1, 0, nums1.size(), nums2, 0, nums2.size(), (item2/2) + 1)
                    ) / 2;
            }
        }else{
            return 0;
        }
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > 0 || nums2.size() > 0){
            vector<int> *temp1, *temp2;
            int len1, len2;
            if(nums1.size() < nums2.size()){
                temp1 = &nums1;
                temp2 = &nums2;
                len1 = nums1.size();
                len2 = nums2.size();
            }else{
                temp1 = &nums2;
                temp2 = &nums1;
                len1 = nums2.size();
                len2 = nums1.size();
            }
            //perform BS on the shorter array
            int left = 0, right = len - 1;
            while(left < right){
                int index = left + (right - left) / 2;
                if(nums1->at(index) < nums2->at(len2 - idx - 1) && nums1->at(index + 1) > nums2->at(len2 - idx - 2)){
                    if((len1 + len2) % 2 == 0){
                        return  (max(nums1->at(index), nums2->at(len2 - idx - 2)) + min(nums1->at(index + 1), nums2->at(len2 - idx - 2))) / 2;
                    }else{
                        return max(nums1->at(index), nums2->at(len2 - idx - 2));
                    }
                }
            }
        }
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tatalLength = nums1.size() + nums2.size();
        if(tatalLength % 2){
            return (findKthSortedArrays(nums1, 0, nums2, 0, tatalLength/2) + findKthSortedArrays(nums1, 0, nums2, 0, tatalLength/2 - 1))/2;
        }else{
            return findKthSortedArrays(nums1, 0, nums2, 0, tatalLength/2);
        }
    }

    int findKthSortedArrays(vector<int>& nums1, int index1, vector<int>& nums2, int index2, int k){
        int length1 = nums1.size() - index1, length2 = nums2.size() - index2;
        if(length1 > length2){
            return findKthSortedArrays(nums2, index2, nums1, index1, k);
        }else if(k == 0){
            return min(nums1[index1], nums2[index2]);
        }else if(length1 <= 0){
            return nums2[index2 + k];
        }

        int tempIdx = min(length1, k / 2);
        int mid1 = index1 + tempIdx;
        int mid2 = index2 + k - tempIdx;

        if(nums1[mid1] == nums2[mid2]){
            return nums1[mid1];
        }else if(nums1[mid1] > nums2[mid2]){
            return findKthSortedArrays(nums1, index1, nums2, index2 + mid2, k - mid2);
        }else{
            return findKthSortedArrays(nums1, index1 + mid1, nums2, index2, k - mid1);
        }
    }
};
