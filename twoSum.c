#include "common.h"

/*
	给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
	你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
	示例:
	给定 nums = [2, 7, 11, 15], target = 9
	因为 nums[0] + nums[1] = 2 + 7 = 9
	所以返回 [0, 1]
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	
	// 第一种方式，时间复杂度O(n*n)
	*returnSize = 2;
	int* result = (int*)malloc(2*sizeof(int));
	for (int i = 0; i < numsSize-1; ++i)
	{
		for (int j = i+1; j < numsSize; ++j)
		{
			if (nums[i]+nums[j] == target)
			{
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	return result;
	
}

int main(int argc,char* argv[])
{
	int nums[] =  {2, 7, 11, 15};
	int target = 9;
	int returnSize;
	int numsSize;
	GET_ARRAY_LENGTH(nums,numsSize)
	int* result = twoSum(nums,numsSize,target,&returnSize);
	printf("[%d,%d]\n", result[0],result[1]);
    return 0;
}