#include "common.h"

/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定数组 nums = [1,1,2], 

函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,2,2,3,3,4],

函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。

你不需要考虑数组中超出新长度后面的元素。
*/
int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= 0){
        return 0;
    }
    int j = 0;
    for(int i = 1;i < numsSize;++i){
        if(nums[j]!=nums[i]){
            nums[++j] = nums[i];
        }
    }
    return j+1;
}

int main()
{
	int array[] = {1,2,2,3,4,4,5,6,6,6,7,8};
	int length;
	GET_ARRAY_LENGTH(array,length);
	int newLength = removeDuplicates(array,length);
	printf("%d\n", newLength);
	return 0;
}