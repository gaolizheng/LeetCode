#include "common.h"

/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
(
中位数，统计学中的专有名词，代表一个样本、种群或概率分布中的一个数值，其可将数值集合划分为相等的上下两部分。
对于有限的数集，可以通过把所有观察值高低排序后找出正中间的一个作为中位数。如果观察值有偶数个，通常取最中间的两个数值的平均数作为中位数。
)

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	#ifndef INT_MAX
		#define INT_MAX ((unsigned)(-1)>>1)
		#define INT_MIN (~INT_MAX)
	#endif
	if (nums1Size > nums2Size)//确保nums1是短的那个数组,这样可以保证二分遍历时效率更高
	{
		return findMedianSortedArrays(nums2,nums2Size,nums1,nums1Size);
	}
	int lMax1,lMax2 = 0;//两个数组切分后左侧的最大值
	int rMin1,rMin2 = 0;//两个数组切分后右侧的最小值
	int c1,c2 = 0;//两个数组切分的位置
	int low = 0;//二分左侧索引
	int hig = 2*nums1Size;//二分右侧索引，为了保证两个数组的总个数为偶数，我们从概念上填充每个数组到2*n+1长度，所以最右侧的索引就是2*nums1Size
	int k = nums1Size+nums2Size;//k就是最终结果里被切割的位置,如何确定的k的值呢，扩充后的总长度是2*nums1Size+2*nums2Size+2,中位数就是nums1Size+nums2Size和nums1Size+nums2Size+1两个数的平均值，即切割位置为nums1Size+nums2Size
	while(low <= hig){

		c1 = (low+hig)/2;
		c2 = k - c1;

		lMax1 = c1 == 0 ? INT_MIN : nums1[(c1-1)/2];
		rMin1 = c1 == 2*nums1Size ? INT_MAX : nums1[c1/2];
		lMax2 = c2 == 0 ? INT_MIN : nums2[(c2-1)/2];
		rMin2 = c2 == 2*nums2Size ? INT_MAX :nums2[c2/2];

		if (lMax1 > rMin2)
		{
			hig = c1 -1;
		}else if (lMax2 > rMin1){
			low = c1+1;
		}else{
			break;
		}
	}
	return ((lMax1 >= lMax2 ? lMax1:lMax2)+(rMin1 <= rMin2? rMin1:rMin2))/2.0;//左侧的最大值与右侧最小值的平均值就是中位数
}

int main()
{
	int nums1[] = {100001};
	int nums2[] = {100000};
	printf("%f\n",findMedianSortedArrays(nums1,1,nums2,1));
	return 0;
}