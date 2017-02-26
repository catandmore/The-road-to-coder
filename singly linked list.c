#include <stdio.h>
#include <stdlib.h>
struct p 
{
	int date;
	struct p *next;
};
//增加成员至尾部 
void Addmem(struct p *head,int a)
{
	struct p *vstr=head;
	struct p *nstr=NULL; 
	while(vstr->next != NULL)
		vstr=vstr->next;
	nstr=(struct p *)malloc(sizeof(struct p));
	vstr->next=nstr;
	nstr->next=NULL;
	nstr->date=a;
}
//删除制定成员 
void Delmem(struct p *head,int a)
{
	struct p *vstr1=head;
	struct p *vstr2=head;
	for (int i = 1; i < a; ++i)
		{
			vstr2=vstr1;
			vstr1=vstr1->next;
		}
	if (vstr1==head)
	{
		printf("无法删除首表\n");
	}
	else
	{
		vstr2->next=vstr1->next;
	}

}

int main()
{
	struct p str;
	int add,del;
	str.date=0;
	str.next=NULL;

	printf("输入新加表数量\n");
	scanf("%d",&add);
	for (int i = 0; i < add; ++i)
	{
		int date;
		printf("输入新加表数据\n");
		scanf("%d",&date);
		Addmem(&str,date);
	}

	printf("输入删除表数量\n");
	scanf("%d",&del);
	for (int i = 0; i < del; ++i)
	{
		int num;
		printf("输入删除表的序号\n");
		scanf("%d",&num);
		Delmem(&str,num);
	}
	
	printf("%d\n",str.date);
	while(str.next!=NULL)
	{
		str=*str.next;
		printf("%d\n",str.date);
	 } 
	return 0;
}
