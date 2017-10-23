
//Head Files

#ifndef RBTREE_H
#define RBTREE_H


void function_RBtree();

enum Color {RED, BLACK};

typedef struct RBNode
{
	Color color;
	int value;
	RBNode *right;
	RBNode *left;
	RBNode *parent;
	// color true = red , false = black.
	RBNode(int value):value(value),right(NULL),left(NULL),parent(NULL),color(RED){}
}RBNode;


class RBTree
{
public:
	RBNode *root;
	RBTree(void):root(NULL){}
	void left_rotation(RBNode *node);
	void right_rotation(RBNode *node);
	void insert_fixup(RBNode *node);
	void insert_value(int value);
	void print_tree();
	void in_order_print_tree();

};




#endif



#include "stdafx.h"
#include "RBtree.h"
#include <iostream>
#include <stack>
#include <queue>
#include <time.h>
#include <stdlib.h>
using namespace std;

/*
	RBTree的一些特性：
	1. 每个节点或者是黑色，或者是红色
	2.根节点必须是黑色
	3.每个叶子节点必须是黑色（这里的叶子节点是值 为空的叶子节点）
	4.如果一个节点是红色的，则它的子节点必须是黑色的
	5.从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点 （确保了没有一条路径会比其他路径长出两倍，因此，红黑树是相对接近平衡的二叉树。

	红黑树的应用比较广泛，在STL中的Map、Set等等，主要是用来存储有序的数据，时间复杂度是0(lgn)
*/

/*红黑树主要有左旋、右旋两种方式调整*/


void RBTree::right_rotation(RBNode *node)
{
	RBNode *temp = node->right;    
	node->right = temp->left;
	if(temp->left != NULL)                        //若temp->left == NULL 则temp->left->parent会出现内存ERROR
		temp->left->parent = node;
	temp->parent = node->parent;
	if(node->parent == NULL)    //根节点
	{
		root = temp;
	}
	else if( node == node->parent->left)
	{
		node->parent->left = temp;
	}
	else
		node->parent->right = temp;
	
	temp->left = node;
	node->parent = temp;
}

void RBTree::left_rotation(RBNode *node)
{
	RBNode *temp = node->left;      

	node->left = temp->right;
	if(temp->right != NULL)             //若temp->right == NULL 则temp->right->parent会出现内存ERROR
		temp->right->parent = node;
	temp->parent = node->parent;
	if(node->parent == NULL)        //根节点
	{
		root = temp;
	}
	else if(node = node->parent->left)
	{
		node->parent->left = temp;
	}
	else
		node->parent->right = temp;

	node->parent = temp;
	temp->right = node;
}


void RBTree::insert_value(int value)
{
	if(root == NULL)
	{
		root = new RBNode(value);
		root->parent = NULL;
		root->color = BLACK;                       //根节点的color必须是黑色的
		return;
	}
	RBNode *insert_node = new RBNode(value);
	RBNode *temp = root->parent;
	RBNode *node = root;
	while(node != NULL)
	{
		temp = node;
		if(value < node->value)
		{
			node = node->left;
		}
		else
			node = node->right;
	}
	
	insert_node->parent = temp;

	if(value < temp->value)
		temp->left = insert_node;
	else
		temp->right = insert_node;

	insert_node->color = RED;
	insert_fixup(insert_node);
}


void RBTree::insert_fixup(RBNode *node)
{
	while(node->parent != NULL && node->parent->color == RED )
	{
		if(node->parent == node->parent->parent->left)
		{
				RBNode *temp = node->parent->parent->right;  //temp为祖父节点的右孩子
				if(temp != NULL && temp->color == RED)
				{
					node->parent->color = BLACK;
					temp->color =BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}
				else
				{
					if(node == node->parent->right)
					{
						node = node->parent;
						right_rotation(node);
					}
				
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					left_rotation(node->parent->parent);
				}
		}
		else
		{
			   RBNode *temp = node->parent->parent->left;
				if( temp != NULL && temp->color )     //if temp == NULL  temp->color ERROR.
				{
					node->parent->color = BLACK;
					temp->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}
			/*	else if(node = node->parent->left)
				{
					node = node->parent;
					right_rotation(node);
				}
				*/
				else
				{
					if(node == node->parent->left)
					{
						node = node->parent;
						left_rotation(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					right_rotation(node->parent->parent);
				}
		}
	}
	root->color = BLACK;
}
//中序非递归
void RBTree::in_order_print_tree()
{
	if(root == NULL)
	{
		cout<<"Tree is not exist"<<endl;
		exit(0);
	}
	RBNode *node = root;
	stack<RBNode *>s;
	while(node != NULL || !s.empty())
	{
		while(node != NULL)
		{
			s.push(node);
			node = node->left;
		}
		RBNode *temp = s.top();
		cout<< temp->value<<"\t";
		s.pop();
		if(temp->right)
			node = temp->right;
	}
	cout<<endl;
}

void RBTree::print_tree()
{
	if(root == NULL)
	{
		cout<<"tree is not exist "<<endl;
		exit(0);
	}
	RBNode *temp = root;
	queue<RBNode*>q;
	q.push(temp);
	while(!q.empty() )
	{
		RBNode *node = q.front();
		cout<<node->value<<"-->";
		q.pop();
		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);
	}
	cout<<endl;
}
void function_RBtree()
{
	int a[] = {1,2,3,4,5,6,34,232,234,123,7,8};
	RBTree t;
	for(int i = 0; i < sizeof(a)/sizeof(int); i++)
	{
		//t.insert_value(a[i]);
		int v = int(rand());
		cout<<v<<"\t";
	    t.insert_value( v );
	}
	cout<<endl;

	t.print_tree();
	cout<<endl;
	//t.in_order_print_tree();
}
