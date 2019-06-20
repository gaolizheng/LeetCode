#include "common.h"


/*
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
*/
int maximumProduct(int* nums, int numsSize){
	/*
		如果数组内全是负数或者全是正数，则最大值就是最大的三个数的乘积,如果有正数有负数，有可能是最大的三个数乘积，
		也有可能是最小两个数和最大一个数的乘积,所以只需遍历找出最大的三个数和最小的两个数，计算出两种可能的结果，比较一下
	*/
	int max1 = -1000;//最大值
	int max2 = -1000;//第二大
	int max3 = -1000;//第三大
	int min1 = 1000;//最小值
	int min2 = 1000;//第二小
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = nums[i];
		}else if(nums[i] > max2){
			max3 = max2;
			max2 = nums[i];
		}else if(nums[i] > max3){
			max3 = nums[i];
		}
		if (nums[i]<min1)
		{
			min2 = min1;
			min1 = nums[i];
		}else if(nums[i] < min2){
			min2 = nums[i];
		}
	}
	int result1 = max1*max2*max3;
	int result2 = min1*min2*max1;
	return result1 > result2?result1:result2;
}

int main()
{
	int array[] = {-4,-3,-2,-1,60};
	printf("%d\n",maximumProduct(array,5));
	return 0;
}