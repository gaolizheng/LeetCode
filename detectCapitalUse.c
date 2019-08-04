#include "common.h"

/**
给定一个单词，你需要判断单词的大写使用是否正确。
我们定义，在以下情况时，单词的大写用法是正确的：
1.全部字母都是大写，比如"USA"。
2.单词中所有字母都不是大写，比如"leetcode"。
3.如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。
示例 1:
输入: "USA"
输出: True
示例 2:
输入: "FlaG"
输出: False
注意: 输入是由大写和小写拉丁字母组成的非空单词。
 */
int detectCapitalUse(char * word){
    int sCount = 0;
    int bCount = 0;
    int index = 0;
    int firstLoc = -1;
    while(word[index]!='\0')
    {
        if(word[index]<97){
            ++bCount;
            if(firstLoc == -1){
                firstLoc = index;
            }
        }else{
            ++sCount;
        }
        ++index;
    };
    if(sCount == 0){
        return 1;
    }else if(bCount == 0){
        return 1;
    }else if(bCount == 1 && firstLoc == 0){
        return 1;
    }else{
        return 0;
    }
}


int main()
{
    if(detectCapitalUse("aHello") == 1){
        printf("符合规范\n");
    }else{
        printf("不符合规范\n");
    }
	return 0;
}