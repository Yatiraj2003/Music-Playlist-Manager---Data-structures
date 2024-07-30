#include<stdio.h>
#include<string.h>

struct Node
{
    char singer_name[20];
    char song_name[50];
    float time;
    int year;
    struct Node *next;

};

typedef struct Node *node;
node prev=NULL,head=NULL,temp=NULL,cur=NULL,newnode;


node insertend(node);
node deleteend(node);
node deletefront(node);
void display(node);
void particular_singer(node);
node deletesongname(node);
void highesttime(node);
void displayyear(node);
void searchsong(node);
node sortyear(node);
int countnodes(node);

int main()
{
    int op,res;
    while(1)
    {
        printf("Choose the option\n");
        printf("1) insert at end\n 2) delete at end\n 3) delete at front\n 4) display the all songs with a given singer name\n 5) delete the given song name\n 6) highest time duration song\n 7) display details of given released year\n 8) searching based on song name\n 9) display \n 10) count the nodes\n  11) sort by year of release\n 12) exit\n");
        scanf("%d",&op);
        switch(op)
        {
             case 1: head=insertend(head);
             break;
             case 2: head=deleteend(head);
             break;
             case 3: head=deletefront(head);
             break;
             case 4: particular_singer(head);
             break;
             case 5: head=deletesongname(head);
             break;
             case 6: highesttime(head);
             break;
             case 7: displayyear(head);
             break;
             case 8: searchsong(head);
             break;
             case 9: display(head);
             break;
             case 10: res=countnodes(head);
             printf("number of node are %d\n",res);
             break;
             case 11: head=sortyear(head);
             break;
             case 12: exit(0);
             break;

        }
    }
}

node getnode()
{
    newnode=(node)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("Memory is not allocated\n");
    }
    else
    {
        return newnode;
    }
}

node read(node newnode)
{
    printf(" Enter the singer name\n song name\n released year\n duration of song\n ");
    fflush(stdin);
    gets(newnode->singer_name);
    gets(newnode->song_name);
    scanf("%d %f",&newnode->year,&newnode->time);
    newnode->next=newnode;
    return newnode;
}

node insertend(node head)
{
    newnode=getnode();
    newnode=read(newnode);
    if(head==NULL)
    {
        return newnode;
    }
    cur=head;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    cur->next=newnode;
    newnode->next=head;
    return  head;
}

node deleteend(node head)
{
    if(head==NULL)
    {
        printf("Cannot delete\n");

    }
    else
    {
        if(head->next==head)
        {
            free(head);
            head=NULL;
            return head;
        }

        else
        {
            cur=head;
            while(cur->next!=head)
            {
                prev=cur;
                cur=cur->next;
            }
            prev->next=head;
            free(cur);
            return head;
        }
    }
}

node deletefront(node head)
{
    if(head==NULL)
    {
        printf("cannot delete\n");

    }

    else
    {
    if(head->next==head)
        {
            free(head);
            head=NULL;
            return head;
        }

        else
        {
            cur=head;
            while(cur->next!=head)
            {
                cur=cur->next;
            }
            temp=head;
            cur->next=temp->next;
            head=temp->next;
            free(temp);
            return head;

        }

}

}

void display(node head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    cur=head;
    while(cur->next!=head)
    {
        fflush(stdout);
       puts(cur->singer_name);
       puts(cur->song_name);
       printf("%d\n %f\n",cur->year,cur->time);
        cur=cur->next;
    }
    fflush(stdout);
       puts(cur->singer_name);
       puts(cur->song_name);
       printf("%d\n %f\n",cur->year,cur->time);
}

node r;
void particular_singer(node head)
{
    char singer[20];
    printf("Enter the singer name to be checked\n");
    fflush(stdin);
    gets(singer);
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    if(head->next==head)
    {
        if(strcmp(head->singer_name,singer)==0)
        {
            printf("Songs sung by him are\n");
            fflush(stdout);
            puts(head->song_name);

        }
    }
    cur=head;
    while(cur->next!=head)
    {
        if(strcmp(cur->singer_name,singer)==0)
        {  r=cur;
            printf("Songs sung by him are\n");
            fflush(stdout);
            puts(r->song_name);
        }
        cur=cur->next;
    }
    r=cur;
    if(strcmp(r->singer_name,singer)==0)
    {
    printf("Songs sung by him are\n");
            fflush(stdout);
            puts(r->song_name);
    }
}
node k;
node deletesongname(node head)
{
    char song[50];
    printf("Enter the song name to be deleted\n");
    fflush(stdin);
    gets(song);
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if(head->next==head )
    {
        if(strcmp(head->song_name,song)==0)
     {
        printf("Deleted song is \n");
        fflush(stdout);
        puts(head->song_name);
        free(head);
        head=NULL;
        return head;
     }

    }
    else if(strcmp(head->song_name,song)==0)
    {

    cur=head;
    while(cur->next!=head)
    {
        cur=cur->next;
    }
    temp=head;
    head=temp->next;
    cur->next=head;
    printf("Deleted song is \n");
    fflush(stdout);
    puts(temp->song_name);
    free(temp);
    return head;
    }
    else
    {
       cur=head;
       while(cur->next!=head)
       {
           prev=cur;
           cur=cur->next;
           if(strcmp(cur->song_name,song)==0)
           {
                prev->next=cur->next;
                printf("Deleted song is \n");
                fflush(stdout);
                puts(cur->song_name);
                free(cur);
                return head;
           }
       }

    }


}
node k;

void highesttime(node head)
{
    if(head==NULL)
    {
        printf("List is empty\n");

    }
    else
    {
      cur=head;
    int high=cur->time;
    cur=cur->next;
    while(cur->next!=head)
    {
        if(high<cur->time)
        {
            high=cur->time;
            k=cur;
        }
        cur=cur->next;
    }
    if(high<cur->time)
        {
            high=cur->time;
            k=cur;
        }

        fflush(stdout);
       puts(k->singer_name);
       puts(k->song_name);
       printf("%d\n %f\n",k->year,k->time);

}}
node j;

void displayyear(node head)
{
    int y;
    printf("Enter the particular  year to be displayed\n");
    scanf("%d",&y);
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    if(head->next==head)
    {
        if(y==head->year)
            {
               printf("Songs which are released on a given year are\n");
               fflush(stdout);
               puts(head->song_name);
            }

    }
    else{

        cur=head;
        while(cur->next!=head)
        {
            if(y==cur->year)
            {
               printf("Songs which are released on a given year are\n");
               fflush(stdout);
               puts(cur->song_name);
            }
            cur=cur->next;
        }
        j=cur;
        if(y==j->year)
        {
        printf("Songs which are released on a given year are\n");
        fflush(stdout);
        puts(j->song_name);
        }

    }
}

void searchsong(node head)
{
    char song[50];
    printf("Enter the song name to be checked\n");
    fflush(stdin);
    gets(song);
    if(head==NULL)
    {
        printf("List is empty\n");
    }
    if(head->next==head)
    {
        if(strcmp(head->song_name,song)==0)
        {
            printf("%s",head->song_name);
            printf("It is found\n");

        }
    }
    else{
    cur=head;
    while(cur->next!=head)
    {
        if(strcmp(cur->song_name,song)==0)
        {   j=cur;
            printf("It is found\n");
            printf("%s",j->song_name);

        }
        cur=cur->next;
    }
    j=cur;
    if(strcmp(j->song_name,song)==0)
        {
            printf("It is found\n");
            printf("%s",j->song_name);

        }
        else
        {
            printf("Not found\n");
        }
    }
}

int countnodes(node head)
{
    int count=1;
    if(head==NULL)
    {
        count=0;
    }

    else
        {
            temp=head;
            while(temp->next!=head)
            {
                count++;
                temp=temp->next;
            }


        }
        return count;

}

node sortyear(node head)
{
     int i,j,c;
    node temp1;
    if(head==NULL)
    {
         printf("No players present\n");
         return(head);
    }

    else
    {
        if(head->next==head)
            return(head);
        else
        {
            c=countnodes(head);
            for(i=1;i<=c;i++)
            {
                temp=head;
                for(j=1;j<=c-i;j++)
                {
                    if(temp->year>temp->next->year)
                    {
                        temp1=(node)malloc(sizeof(struct Node));
                        strcpy(temp1->singer_name,temp->singer_name);
                        strcpy(temp1->song_name,temp->song_name);
                        temp1->year=temp->year;
                        temp1->time=temp->time;


                        strcpy(temp->singer_name,temp->next->singer_name);
                        strcpy(temp->song_name,temp->next->song_name);
                        temp->year=temp->next->year;
                        temp->time=temp->next->time;

                        strcpy(temp->next->singer_name,temp1->singer_name);
                        strcpy(temp->next->song_name,temp1->song_name);
                        temp->next->year=temp1->year;
                        temp->next->time=temp1->time;
                    }
                    temp=temp->next;
                }
            }
        return(head);

        }
    }

}








