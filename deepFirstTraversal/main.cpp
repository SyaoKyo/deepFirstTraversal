/************************
 *                      *
 *  二叉树深度优先遍历  *
 *                      *
 ************************/
#include <iostream>
using namespace std;

struct BTNode
{
	int data;
	BTNode *lChild;
	BTNode *rChild;
};
void testTree(BTNode *root);
void visit(BTNode *p);//访问结点
void r(BTNode *p);//深度优先遍历（递归）
void preorderNoneRecursion(BTNode *bt);//先序深度优先遍历（非递归）
void inorderNoneRecursion(BTNode *bt);//中序深度优先遍历（非递归）
void postorderNoneRecursion(BTNode *bt);//后序深度优先遍历（非递归）

const int maxSize = 1000;
int arr[maxSize];
int arri = 0;

int main()
{
	BTNode *root=new BTNode();
	testTree(root);
	r(root);//递归
	cout << endl;
	preorderNoneRecursion(root);//非递归
	cout << endl;
	return 0;
}

void testTree(BTNode *root)
{
	root->data = 1;
	root->lChild = NULL;
	root->rChild = NULL;
	BTNode *newp1=new BTNode();
	newp1->data = 2;
	newp1->lChild = NULL;
	newp1->rChild = NULL;
	root->lChild = newp1;
	BTNode *newp2 = new BTNode();
	newp2->data = 3;
	newp2->lChild = NULL;
	newp2->rChild = NULL;
	root->rChild = newp2;
	BTNode *newp3 = new BTNode();
	newp3->data = 4;
	newp3->lChild = NULL;
	newp3->rChild = NULL;
	newp1->lChild = newp3;
	BTNode *newp4 = new BTNode();
	newp4->data = 5;
	newp4->lChild = NULL;
	newp4->rChild = NULL;
	newp1->rChild = newp4;
	BTNode *newp5 = new BTNode();
	newp5->data = 6;
	newp5->lChild = NULL;
	newp5->rChild = NULL;
	newp2->lChild = newp5;
	BTNode *newp6 = new BTNode();
	newp6->data = 7;
	newp6->lChild = NULL;
	newp6->rChild = NULL;
	newp2->rChild = newp6;
	BTNode *newp7 = new BTNode();
	newp7->data = 8;
	newp7->lChild = NULL;
	newp7->rChild = NULL;
	newp3->lChild = newp7;
	BTNode *newp8 = new BTNode();
	newp8->data = 9;
	newp8->lChild = NULL;
	newp8->rChild = NULL;
	newp3->rChild = newp8;
	BTNode *newp9 = new BTNode();
	newp9->data = 10;
	newp9->lChild = NULL;
	newp9->rChild = NULL;
	newp4->lChild = newp9;
	BTNode *newp10 = new BTNode();
	newp10->data = 11;
	newp10->lChild = NULL;
	newp10->rChild = NULL;
	newp5->rChild = newp10;
	BTNode *newp11 = new BTNode();
	newp11->data = 12;
	newp11->lChild = NULL;
	newp11->rChild = NULL;
	newp6->lChild = newp11;
	BTNode *newp12 = new BTNode();
	newp12->data = 13;
	newp12->lChild = NULL;
	newp12->rChild = NULL;
	newp6->rChild = newp12;
}

void visit(BTNode *p)
{
	//可打印
	cout << p->data << " -> ";
	//可存入数组
	//arr[arri++] = p->data;
}

void r(BTNode *p)
{
	if (p != NULL)
	{
		//先序遍历
		visit(p);
		r(p->lChild);
		//中序遍历
		//visit(p);
		r(p->rChild);
		//后序遍历
		//visit(p);
	}
}

void preorderNoneRecursion(BTNode *bt)
{
	if (bt != NULL)
	{
		BTNode *Stack[maxSize];
		int top = -1;
		BTNode *p = NULL;
		Stack[++top] = bt;
		while (top != -1)
		{
			p = Stack[top--];
			visit(p);
			if (p->rChild != NULL)
				Stack[++top] = p->rChild;
			if (p->lChild != NULL)
				Stack[++top] = p->lChild;
		}
	}
}

void inorderNoneRecursion(BTNode *bt)
{
	if (bt != NULL)
	{
		BTNode *Stack[maxSize];
		int top = -1;
		BTNode *p = NULL;
		p = bt;
		while (top != -1 || p != NULL)
		{
			while (p != NULL)
			{
				Stack[++top] = p;
				p = p->lChild;
			}
			if (top != -1)
			{
				p = Stack[top--];
				visit(p);
				p = p->rChild;
			}
		}
	}
}

void postorderNoneRecursion(BTNode *bt)
{
	if (bt != NULL)
	{
		BTNode *Stack1[maxSize], *Stack2[maxSize];
		int top1 = -1, top2 = -1;
		BTNode *p = NULL;
		Stack1[++top1] = bt;
		while (top1 != -1)
		{
			p = Stack1[top1--];
			Stack2[++top2] = p;
			if (p->lChild != NULL)
				Stack1[++top1] = p->lChild;
			if (p->rChild != NULL)
				Stack1[++top1] = p->rChild;
		}
		while (top2 != -1)
		{
			p = Stack2[top2--];
			visit(p);
		}
	}
}