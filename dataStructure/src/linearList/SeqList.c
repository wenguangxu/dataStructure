//线性表——顺序表

#include <stdio.h>
#include <stdlib.h>

/**
 * 定义顺序表
 */
#define ListSize 100 //表空间的大小
typedef int DataType;  //DataType的类型可根据实际情况而定
typedef struct {
	DataType data[ListSize];  //data用来存放表结点
	int length;		//线性表的当前表长(实际存储元素的个数)
}SeqList;

//遍历表
void printSeqList(SeqList L){
	int i;
	for(i=0;i<L.length;i++) {
		printf("%d\t",L.data[i]);
	}
	printf("\n");
}

//置空表
void initList(SeqList *L) {
	L->length = 0;
}

//访问第i个节点
int getNode(SeqList L,int i) {
	return L.data[i-1];
}

/**
 * 插入运算
 * 在顺序表L中第i个位置之前插入一个新元素x
 */
void insertList(SeqList *L,int i,DataType x){
	int j;
	if(i<1 || i>L->length+1) {
		printf("position error");
		return;
	}
	if(L->length >= ListSize) {
		printf("overflow");
		return;
	}
	for(j=L->length-1; j>=i-1; j--)
		L->data[j+1] = L->data[j];
	L->data[i-1] = x;
	L->length++;
}

/**
 * 删除运算
 * 在顺序表L中删除第i个元素，并返回被删除元素
 */
DataType deleteList(SeqList *L,int i) {
	int j;
	DataType x;
	if(i<1 || i>L->length) {
		printf("position error");
		exit(0);	//非正常退出
	}
	x = L->data[i];
	for(j=i;j<=L->length;j++)
		L->data[j-1] = L->data[j];
	L->length--;
	return x;
}

/**
 * 逆置顺序表
 * 实现思想：先以表长的一半为循环控制次数，将表中最后一个元素同顺数第一个元素交换，将倒数第二个元素同顺数第二个元素交换，依此类推。
 */
SeqList converts(SeqList L) {
	DataType x;
	int i,k;
	k = L.length/2;
	for (i = 0; i < k; i++) {
		x = L.data[i];
		L.data[i] = L.data[L.length-i-1];
		L.data[L.length-i-1] = x;
	}
	return L;
}

/**
 * 找出顺序表中最大值和最小值及其所在的位置
 * 在算法中要求求得最大值和最小值元素及其所在位置，可用4个指针变量参数间接得到，也可以用外部变量实现，因为函数本身只可返回一个值。
 */
void maxmin(SeqList L,DataType *max,DataType *min,int *k, int *j){
	int i;
	*max = L.data[0]; *min = L.data[0];
	*k = *j = 1;
	for(i=1;i<L.length;i++){
		if(L.data[i] > *max) {
			*max = L.data[i]; *k = i+1;
		}else if(L.data[i] < *min){
			*min = L.data[i]; *j = i+1;
		}
	}
}

/*main() {
	SeqList L = {{17,33,55,44,13,99},6};
	//initList(&L);
	//int x = getNode(L,2);
	//printf("%d",x);
	printSeqList(L);
	int x = 99;
	insertList(&L,6,x);
	printSeqList(L);
	printSeqList(L);
	deleteList(&L,3);
	printSeqList(L);
	printSeqList(L);
	SeqList res = converts(L);
	printSeqList(res);
	printSeqList(L);
	int max,min,k,j;
	maxmin(L,&max,&min,&k,&j);
	printf("max:%dmin:%dk:%dj:%d",max,min,k,j);
}*/
