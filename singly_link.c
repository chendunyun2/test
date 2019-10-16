#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"singly_link.h"
#include<malloc.h>


/*
*�������ܣ���������
*��������
*����ֵ�������������ĵ�һ����ַ
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
		//���ֻ����һ����� ��ô����ͷ�ڵ�Ҳ��β���
		else
		{
			Node* p = (Node*)malloc(sizeof(Node));
			p->data = num;
			p->next = NULL;
			//β�巨
			/*
			if(head == NULL)
			{
				head = tail = p;
			}
			else
			{
				tail->next = p; //β�͵���һ����p
				tail = p;//�µĽڵ��Ϊ�µ�β��
			}
			*/
			//ͷ�巨
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
				//head �ͱȲ�������ݴ� ���������ݾ�����С��
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
*�������ܣ���ӡ�����ֵ
*������ָ��������
*����ֵ����
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
*�������ܣ����ҽ���Ƿ����
*������ָ��������
*����ֵ�����ص��ǽ����  û�ҵ�����0
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
	��һ�����Ȳ������ֵ 
	�ڶ������ҵ������滻
*/
/*
	int change_first_num(Node *list,Element num,Element dest)
	���ܣ������滻�����е�ֵ 
	������ 
		list ָ�����ҵ����� 
		num ָ����Ҫ�����滻������ 
		dest �滻֮������� 
	����ֵ�� �ɹ����� 0 ʧ�ܷ���-1 
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

//ɾ�����е�ĳ��Ԫ�� ��ôɾ����
//�Ȳ�����ɾ�� 

/*
	Node *delete_first_num(Node *list,Element num)
	���ܣ� ɾ�������еĵ�һ��ֵΪnum�Ľ�� 
	������ 
		list ָ��������
		num ָ��ɾ����ֵ 
	����ֵ�� ����ɾ��֮������� 
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
