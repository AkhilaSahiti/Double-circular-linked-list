#include<stdio.h>
/*#include<iostream.h>*/
#include<stdlib.h>
typedef struct dbcrl
{
   int data;
   struct dbcrl *plnk;
   struct dbcrl *nlnk;
}dbcrl;
dbcrl *strt,*lst,*tmp;
void create();
void display();
void redisplay();
void search();
void insert();
void deletion();
int n,i,elm,pos;
/*void*/ main()
 {
   int ch;
   while(1)
   {
    printf("\n\n--LIST OF OPERATIONS--\n");
    printf("1. Create\n");
    printf("2. Search\n");
    printf("3. Display\n");
    printf("4. Insert\n");
    printf("5. Delete\n");
    printf("6. Reverse Display\n");
    printf("7. Exit\n");
    printf("Choose your Choice");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: create();
	          break;
      case 2: search();
	          break;
      case 3: display();
	          break;
      case 4: insert();
	           break;
      case 5: deletion();
              break;
      case 6: redisplay();
	          break;
      case 7: free(strt);
	          free(lst);
	          exit(0);
      default:printf("An Invalid Choice.");
    }
  }
}
void create()
{
  strt=NULL;
  printf("Enter the Range.\t");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    tmp=(dbcrl*)malloc(sizeof(dbcrl));
    printf("Data\t");
    scanf("%d",&tmp->data);
    tmp->plnk=NULL;
    tmp->nlnk=NULL;
    if((strt==NULL)&&(lst==NULL))
    {
     strt=tmp;
     lst=tmp;
    }
    else
    {
     tmp->plnk=lst;
     lst->nlnk=tmp;
     lst=tmp;
     lst->nlnk=strt;
     strt->plnk=lst;
    }
  }
 printf("List is created successfully!");
}
void display()
{
 dbcrl *dsp;
 if((lst==NULL)||(strt==NULL))
 {
  printf("Empty list");
 }
 else
 {
  printf("The created list is:\n");
  dsp=lst->nlnk;
  printf("%d\t",dsp->data);
  dsp=strt->nlnk;
  while(dsp!=lst->nlnk)
  {
   printf("%d\t",dsp->data);
   dsp=dsp->nlnk;
  }
 }
}
void redisplay()
{
 dbcrl *rdsp;
 if((strt==NULL)||(lst==NULL))
 {
  printf("Empty list");
 }
  else
 {
  rdsp=strt->plnk;
  printf("The Reverse of the created list is:\n");
  printf("%d\t",rdsp->data);
  rdsp=lst->plnk;
  while(rdsp!=strt->plnk)
  {
   printf("%d\t",rdsp->data);
   rdsp=rdsp->plnk;
  }
 }
}
/*else
{
  for(rdsp=lst,i=0;i<n;i++,rdsp=rdsp->plnk)
  {
    printf("%d\t",rdsp->data);
  }
}
} */
void search()
{
  int flag=0;
  dbcrl *srch;
  if((strt==NULL)||(lst==NULL))
   {
    printf("Empty list");
   }
  else
  {
    printf("Enter element to search.\t");
    scanf("%d",&elm);
    srch=lst->nlnk;
    pos=1;
    if(elm==srch->data)
    {
      printf("%d found at position %d",elm,pos);
      flag++;
    }
    srch=srch->nlnk;
    pos=2;
    while(srch!=lst->nlnk)
    {
      if(elm==srch->data)
      {
       printf("%d found at position %d",elm,pos);
       flag++;
      }
      srch=srch->nlnk;
      pos++;
    }
    if(flag==0)
    {
      printf("Not present in the list.");
    }
  }
}
void insert()
{
    dbcrl *ins=strt;
   if((strt==NULL)||(lst==NULL))
   {
     printf("Empty List");
     return;
   }
   printf("Enter the position to insert the desired element.\t");
   scanf("%d",&pos);
   if(pos<1 || pos>n+1)
    printf("%d is out of range",pos);
   else
   {
    printf("Enter the desired element to insert.\t");
    scanf("%d",&elm);
    tmp=(dbcrl*)malloc(sizeof(dbcrl));
    tmp->data=elm;
    /*ins=strt;*/

    if(pos==1)
    {
      tmp->nlnk=strt;
      tmp->plnk=lst;
      strt->plnk=tmp;
      lst->nlnk=tmp;
      strt=tmp;
    }
    else if(pos==n+1)
    {
      lst->nlnk=tmp;
      tmp->plnk=lst;
      tmp->nlnk=strt;
      strt->plnk=tmp;
      lst=tmp;
    }
    else
    {
      for(i=1;i<pos-1;i++)
       ins=ins->nlnk;

      tmp->plnk=ins;
      tmp->nlnk=ins->nlnk;
      ins->nlnk->plnk=tmp;
      ins->nlnk=tmp;
     }
    n++;
    printf("%d is inserted successfully at position %d.\t",elm,pos);
   }
}

/*{
 if((strt==NULL)&&(lst==NULL))
   {
     printf("Empty list");
   }
 else
  {
    tmp=(dbcrl*)malloc(sizeof(dbcrl));
    printf("New value and pos");
    scanf("%d%d",&elm,&pos);
    if(pos<1||pos>n+1)
    {
      printf("Out of range");
    }
    else
    {
      tmp->data=elm;
      tmp->plnk=NULL;
      tmp->nlnk=NULL;
      if(pos==1)
      {
	tmp->nlnk=strt;
	tmp->plnk=lst;
	strt->plnk=tmp;
	lst->nlnk=tmp;
	strt=tmp;
	printf("%d inserted at pos 1",elm);
      }
      else if(pos==n+1)
      {
	tmp->plnk=strt->plnk;
	tmp->nlnk=lst->nlnk;
	lst->nlnk=tmp;
	strt->plnk=lst->nlnk;
	lst=tmp;
	printf("%d inserted at pos %d",elm,pos);
      }
      else
      {
	dbcrl *ins=strt;
	tmp->data=elm;
	ins=lst->nlnk;
	for(i=1;i<pos-1;i++)
	{
	    ins=ins->nlnk;
	    tmp->plnk=ins;
	    tmp->nlnk=ins->nlnk;
	    ins->nlnk->plnk=tmp;
	    ins->nlnk=tmp;
	}
	n++;
	printf("%d inserted at pos %d",elm,pos);
      }
    }
  }
 }*/
void deletion()
{
 dbcrl *del=strt;
 int flag=0;
 if((strt==NULL)||(lst==NULL))
   {
     printf("Empty list.");
   }
   else
  {
    printf("Enter element to delete from the List.\t");
    scanf("%d",&elm);
    del=lst->nlnk;
    if(strt->data==elm)
    {
        tmp=strt;
        strt=tmp->nlnk;
      strt->plnk=tmp->plnk;
     lst->nlnk=strt;
      /*free(tmp);*/
      flag++;
    }
    else if(lst->data==elm)
    {

        tmp=lst;
        lst=tmp->plnk;
        lst->nlnk=tmp->nlnk;
        strt->plnk=lst;
        flag++;
    }
    else
    {
     while(del->nlnk!=lst->nlnk)
     {
       if(del->nlnk->data==elm)
       {
            tmp=del->nlnk;
            del->nlnk=tmp->nlnk;
            tmp->nlnk->plnk=del;
            /*free(tmp);*/
            flag++;
       }
       if(tmp==lst)
       {
	      lst=del;
       }
       del=del->nlnk;
     }
    }
    if(flag==0)
    {
     printf("%d is not present in the List.\t",elm);
    }
    else
    {
        free(tmp);
            printf("%d deleted successfully.\n",elm);
    /*}*/
     n--;
    if(n==0)
   {

    lst=NULL;
    printf("Now its an Empty list.");
   }
  }
}
}
 /*else
 {
  printf("Enter pos to delete");
  scanf("%d",&pos);
  for(del=strt,i=1;i<=pos-1;i++)
  {
    tmp=del;
    del=del->nlnk;
    if(pos==1)
    {
      n--;
      lst->nlnk=tmp->nlnk;
      del->plnk=tmp->plnk;
      strt=del;
      printf("%d dleted",tmp->data);
      free(tmp);
      break;
    }
    else if(i==pos-1)
    {
     n--;
     tmp->nlnk=del->nlnk;
     del->nlnk->plnk=tmp;
     printf("%d deleted",del->data);
     free(del);
     break;
     }
   }
  }
 }*/
