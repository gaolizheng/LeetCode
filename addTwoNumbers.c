#include "common.h"

struct ListNode {
    int val;
    struct ListNode *next;
}l1[3],l2[3];

/*
	给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
	如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
	您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
	示例：
	输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
	输出：7 -> 0 -> 8
	原因：342 + 465 = 807


	执行结果:
	执行用时 :28 ms, 在所有 C 提交中击败了82.07%的用户
	内存消耗 :8.5 MB, 在所有 C 提交中击败了97.29%的用户
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int k = 0;
	struct ListNode* tempL1 = l1;
	struct ListNode* tempL2 = l2;
	struct ListNode* temp;
	while(tempL1){
		int a = tempL1?tempL1->val:0;
		int b = tempL2?tempL2->val:0;
		int total = a+b+k;
		k = 0;
		if (total >= 10)
		{
			k = 1;
			total -= 10;
		}
		tempL1->val = total;
		temp = tempL1;//temp始终指向上一个节点
		tempL1 = tempL1->next;
		if (tempL2)
		{
			tempL2 = tempL2->next;
		}
		if (tempL1 == NULL && tempL2 != NULL)//当l1短时，把l2的后续部分接到l1上
		{
			temp->next = tempL2;
			tempL1 = tempL2;
			tempL2 = NULL;
		}
		
	}
	if (k == 1)//溢出了，补一个节点
	{
		struct ListNode* extra = (struct ListNode*)malloc(sizeof(struct ListNode));
		extra->val = 1;
		extra->next = NULL;
		temp->next = extra;
	}
	return l1;
}

int main()
{
	l1[0].val = 2;
	l1[0].next = l1+1;
	l1[1].val = 4;
	l1[1].next = l1+2;
	l1[2].val = 3;
	l1[2].next = NULL;

	l2[0].val = 5;
	l2[0].next = l2+1;
	l2[1].val = 6;
	l2[1].next = l2+2;
	l2[2].val = 4;
	l2[2].next = NULL;
	
	struct ListNode* result = addTwoNumbers(l1,l2);
	while(result){
		printf("%d\n", result->val);
		result = result->next;
	}
	return 0;
}