//线性表——单链表

#include <stdio.h>

/**
 * 定义链表
 */
typedef char DataType;

typedef struct node{	//结点类型定义
	DataType data;		//结点数据域
	struct node *next;	//结点指针域
}ListNode;

typedef ListNode* LinkList;
ListNode *p;		//定义一个指向结点的指针变量
LinkList head;		//定义指向单链表的头指针

/**
 * 建立单链表(头插法)
 * 假设线性表中结点的数据域为字符型
 */
LinkList CreateListF() {
	LinkList head;
	ListNode *p;
	char ch;
	head = NULL; //置空单链表
	head->data = getchar();	//读入第一个字符
	while(ch != '\n') {	//读入字符不是结束标识符时作循环
		p = (ListNode*)malloc(sizeof(ListNode));	//申请新节点
		p->data = ch;	//数据域赋值
		p->next = head;	//指针域赋值
		head = p;	//头指针指向新节点
		ch = getchar();	//读入下一个字符
	}

	return head;	//返回链表的头指针
}

void printLinkList(LinkList L) {
	printf("%c",L->data);
	LinkList ob = L->next;
	while(ob!=NULL) {
		printf("%c ",ob->data);
		ob = ob->next;
	}
}
main() {
	LinkList L = CreateListF();
	printLinkList(L);
}

