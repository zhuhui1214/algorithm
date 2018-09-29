class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double result = 0.0;
        vector<int> nums(m+n);//把两个数组合并起来
        if(m<n){return findMedianSortedArrays(nums2,nums1);}//保证前面的数组比后面的大，其实可以不用这一步
        for(int i=0;i<m;i++){
            nums[i]=nums1[i];
        }
        for(int i=m;i<m+n;i++){
            nums[i]=nums2[i-m];
        }//2个for循环，把两个数组的元素放进去，合并成一个数组
        //插入排序
        for(int i=m;i<m+n;i++){
            while(nums[i]<nums[i-1]&&i>0){
                int tmp=nums[i];
                nums[i]=nums[i-1];
                nums[i-1]=tmp;
                i--;
            }
        }
        if((m+n)%2!=0){
            result = nums[(m+n-1)/2];
        }//大数组基数的情况，只需要找到中间的值
        else{
            result = ((nums[(m+n)/2-1])+(nums[(m+n)/2]))/2.0;
        }//大数组偶数的情况，需要找到中间的数
        return result;
    }
};
