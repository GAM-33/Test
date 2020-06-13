#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int value;
    LNode *next;
};


LNode *Combine(LNode *a, LNode *b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	LNode *l1 = a;
	LNode *l2 = b;
	LNode *head = (LNode*)malloc(sizeof(LNode));
	head->value = 0;
	head->next = NULL;
	LNode *temp = head;
	while(l1&&l2)
	{
		if(l1->value < l2->value)
		{
			temp->next = l1;
			l1 = l1->next;
		}
		else
		{
			temp->next = l2;
			l2 = l2->next;
		}
		temp = temp->next;
	}
	if(l1)
	{
		temp->next = l1;
	}
	if(l2)
	{
		temp->next = l2;
	}
	return head->next;
}

int main()
{
	int n1, n2;
	int i;
	LNode *l1 = (LNode*)malloc(sizeof(LNode));
	LNode *l2 = (LNode*)malloc(sizeof(LNode));
	LNode *head1 = l1;
	LNode *head2 = l2;
	LNode *tail = NULL;
	printf("Please input the length of the first List:\n");
	scanf("%d",&n1);
	printf("Please input the elements of the first List:\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&l1->value);
		tail = l1;
		l1->next = (LNode*)malloc(sizeof(LNode));
		l1 = l1->next;
	}
	tail->next = NULL;
	printf("Please input the length of the second List:\n");
	scanf("%d",&n2);
	printf("Please input the elements of the second List:\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&l2->value);
		tail = l2;
		l2->next = (LNode*)malloc(sizeof(LNode));
		l2 = l2->next;
	}
	tail->next = NULL;
	
	LNode *combine = Combine(head1,head2);
	printf("The combined List is:\n");
	while(combine!=NULL)
	{
		printf("%d ", combine->value);
		combine = combine->next;
	}
}


