#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"singly_link.h"
#include<malloc.h>


/*
*函数功能：创建链表
*参数：无
*返回值：创建这个链表的第一个地址
*/

Node *creat_link(void)
{
	Node* head,*tail;
	head = tail = NULL;
	Element num;
	//int number = 0;
	//scanf("%d",&num);
	while(1)
	{
		scanf("%d",&num);
		if(num == 0)
		{
			//Node.number = number;
			break;
		}
		//number++;
		//p->data = num;
		//如果只有这一个结点 那么它是头节点也是尾结点
		else
		{
			Node* p = (Node*)malloc(sizeof(Node));
			p->data = num;
			p->next = NULL;
			//尾插法
			/*
			if(head == NULL)
			{
				head = tail = p;
			}
			else
			{
				tail->next = p; //尾巴的下一个是p
				tail = p;//新的节点成为新的尾巴
			}
			*/
			//头插法
			if(head == NULL)
			{
				head = tail = p;
			}
			else
			{
				Node* r = head;
				Node* pre = NULL;
				while(r!=NULL)
				{
					if(r->data > p->data)
					{
						break;
					}
					else
					{
						pre = r;
						r = r->next;
					}
				}
				if(r == NULL)
				{
					tail->next = p;
					tail = p;
				}
				//head 就比插入的数据大 则插入的数据就是最小的
				else if(r == head)
				{
					p->next = head;
					head = p;
				}
				else
				{
					pre->next = p;
					p->next = r;
				}
			}
		}
		
	}
	return head;	
}


/*
*函数功能：打印链表的值
*参数：指定的链表
*返回值：无
*/

void print_list(Node* list)
{
	int number = 0;
	while(list != NULL)
	{
		printf("->%d",list->data);
		number++;
		list = list->next;
	}
	printf("\n");
	printf("Total number of nodes is %d\n",number);
	
}

/*
*函数功能：查找结点是否存在
*参数：指定的链表
*返回值：返回的是结点编号  没找到返回0
*/

int find_link(Node* list)
{
	printf("Please enter the node you need to find\n");
	int fid,NO;
	NO = 0;
	scanf("%d",&fid);

	while(list != NULL)
	{
		if(list->data==fid)
		{
			NO++;
			break;
		}
		else
		{
			list = list->next;
			NO++;
		}
	}
	if(list->data == fid)
	{
		return NO;
	}
	else
	{
		return 0;
	}
}
 

/*
	第一步：先查找这个值 
	第二步：找到了做替换
*/
/*
	int change_first_num(Node *list,Element num,Element dest)
	功能：查找替换链表中的值 
	参数： 
		list 指定查找的链表 
		num 指定需要查找替换的数据 
		dest 替换之后的数据 
	返回值： 成功返回 0 失败返回-1 
*/

int change_num_to_link(Node* list,Element num,Element dest)
{
	Node* r;
	r = list;
	while(r!=NULL)
	{
		if(r->data == num)
		{
			break;
		}
		r = r->next;
	}
	if(r->data==num)
	{
		r->data = dest;
		return 0;
	}
	else
	{
		return -1;
	}
}

int change_all_num_to_link(Node* list,Element num,Element dest)
{
	
	Node* r;
	r = list;
	int flag = 0;
	while(r!=NULL)
	{
		if(r->data == num)
		{
			r->data = dest;
			flag++;
		}
		r = r->next;
	}
	if(flag!=0)
	{
		//r->data = dest;
		return 0;
	}
	else
	{
		return -1;
	}
}

//删除其中的某个元素 怎么删除？
//先查找再删除 

/*
	Node *delete_first_num(Node *list,Element num)
	功能： 删除链表中的第一个值为num的结点 
	参数： 
		list 指定的链表
		num 指定删除的值 
	返回值： 返回删除之后的链表 
*/
Node *delete_num_list(Node* list,Element num)
{
	Node* r;
	Node *pre;
	pre = NULL;
	r = list;
	while(r!=NULL)
	{
		if(r->data == num)
		{
			break;
		}
		else
		{
			pre = r;
			r = r->next;
		}
	}
	if(r == NULL)
	{
		printf("The linked list does not have this data\n");
	}
	else
	{
		if(r == list)
		{
			list = r->next;
		}
		else
		{
			pre->next = r->next;
		}
		r->next = NULL;
		free(r);
		r == NULL;
	}
	return list;
}

Node *delete_all_num_list(Node* list,Element num)
{
	Node* r;
	Node *pre;
	pre = NULL;
	r = list;
	while(r!=NULL)
	{
		
		if(r->data == num)
		{
			Node* p = r->next;
			if(r == list)
			{
				list = r->next;
			}
			else
			{
				pre->next = r->next;
			}
			r->next = NULL;
			free(r);
			r = p;
		}
		else
		{
			pre = r;
			r = r->next;
		}
	}
	return list;
}
