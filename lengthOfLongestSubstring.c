#include "common.h"

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
int lengthOfLongestSubstring(char * s){
	int i = 0;//用于遍历字符串
	int j = 0;//用于遍历子串
	int n = 0;//用于保存最大长度
	int index = 0;//用于指向子串的第一个元素
	while(s[i]!='\0'){
		for (j = index; j < i; ++j)
		{
			if (s[j] == s[i])
			{
				break;
			}
		}
		if (j != i)//代表遇到了重复元素
		{
			n = (i-index) > n?(i-index):n;
			index = j+1;
		}
		++i;
	}
	n = (i-index) > n?(i-index):n;
	return n;
}

int main()
{
	char str[] = "abcaccbb";
	int count = lengthOfLongestSubstring(str);
	printf("%d\n", count);
	return 0;
}