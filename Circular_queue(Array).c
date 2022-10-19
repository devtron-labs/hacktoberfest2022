
#include<stdio.h>
#include<stdlib.h>
#define m 5
typedef struct
{
	int data[m];
	int r,f;
}queue;
int insert(queue *q,int n)
{
	if((q->r==m-1 && q->f==0) || q->f==q->r+1)
	{
		printf("Insertion Not Possible.\n");
		return 1;
	}
	if(q->r==-1)
	{
		q->f=q->r=0;
		q->data[q->r]=n;
	}
	else
	{
		q->r=(q->r+1)%m;
		q->data[q->r]=n;
	}
	return 0;
}
int delete(queue *q, int *n)
{
	if(q->f==-1)
	{
		printf("Deletion Note Possible.\n");
		return 1;
	}
	if(q->r==q->f)
	{
		*n=q->data[q->f];
		q->f=q->r=-1;
	}
	else
	{
		*n=q->data[q->f];
		q->f=(q->f+1)%m;
	}
	return 0;
}
int main()
{
	queue q;
	q.f=q.r=-1;
	int n,x,y;
	for(int i=0; i<m-2;i++)
	{
		scanf("%d",&n);
		x=insert(&q,n);
	}
	y=delete(&q,&n);
	y=delete(&q,&n);
	for(int i=0; i<m-1; i++)
	{
		scanf("%d",&n);
		x=insert(&q,n);
	}
	for(int i=0; i<m; i++)
	{
		y=delete(&q,&n);
		printf("%d ",n);
	}
	printf("\n");
}
