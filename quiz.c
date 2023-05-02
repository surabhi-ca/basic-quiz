#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

struct quiz
{
    int qn;
    char ans;
    char q[200];
    char opt[4][200];
    char hint[200];
};


int main()
{
    struct quiz q1;
    int  a[5]={0,0,0,0,0},num;
    int play=0;
    int equals=1;
    char username[20];
    char password[20];
    srand(time (0));
    
    a[0]=(rand()%8)+1;


    printf("WELCOME TO THE GAME\n\n");
     
    printf("PLEASE ENTER THE FOLLOWING DETAILS TO CREATE ACCOUNT\n");
    printf("ENTER YOUR USERNAME\n");
    scanf("%s",username);
    printf("ENTER YOUR PASSWORD\n");
    scanf("%s",password);
    FILE * f=fopen(username,"w");
    fputs("username:  ",f);
    fputs(username,f);
    fputs("\n",f);
    fputs("password:  ",f);
    fputs(password,f);
    fclose(f);
    
    printf("///////////////////////////////////////////////");
    printf("\n=>PRESS 1 TO START THE GAME\n");
    printf("=>PRESS 0 TO QUIT THE GAME\n");

    scanf("%d",&play);


    if(play==1)

    {
        int choice;
        for(int i=1;i<=5;i++)

    {
        num=rand()%8;      //num of q
        for (int n=0;n<i;n++)
        {
        
         
            if ((num+1)==a[n])
            {
                equals=0;     //num is duplicate
                i=i-1;
                break;
     
            }
            else
            {equals=1;}

            
        
        }
        if (equals==1)
        {
            a[i]=num +1;
            
            }     
        
   
        }
     char ch,c,b,s[250],choose,chooseb;
    chooseb='z';
    int i,score=0;



    FILE *fp;    //file pointer
    
    do 
       {
           int level;
            printf("\n\n CHOOSE YOUR TOPIC\n 1:Topic 1: COMPUTERS \n 2:Topic 2: ELECTRONICS\n 3:Topic 3: BIOLOGY\n\n");
            scanf("%d",&choice);
            
            switch(choice)
            {
                case 1:printf("\nTopic 1 choosen\nchoose level:\n");
                    printf("1: EASY\n2: HARD\n");
                    scanf("%d",&level);
                    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
                    switch(level)
                    {
                        case 1:printf("\nLevel Easy choosen!\n\n");
                              ;
                                fp=fopen("topic1a.txt","r");
                               
                                
                                break;
                        
                        case 2:printf("\nLevel Hard choosen!\n\n");
                             
                                fp=fopen("topic1b.txt","r");
                           
                                break;
                        default:
                        printf("\n!!! INVALID NUMBER !!!\n");            
                    }

            
                    break;
                case 2:printf("\nTopic 2 choosen\nchoose level:\n");
                    printf("1: EASY\n2: HARD\n");
                    scanf("%d",&level);
                    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
                    switch(level)
                    {
                        case 1:printf("\nLevel Easy choosen!\n\n");
                               
                                fp=fopen("topic2a.txt","r");
                              
                                break;
                  
                        case 2:printf("\nLevel Hard choosen!\n\n");
                       
                                fp=fopen("topic2b.txt","r");
                         
                                

                                

                                break; 
                        default:
                        printf("\n!!! INVALID NUMBER !!!\n");}             
                

                    break;
                case 3:printf("\nTopic 3 choosen\nchoose level:\n");                
                    printf("1: EASY\n2: HARD\n");
                    scanf("%d",&level);
                    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
                    switch(level)
                    {
                        case 1:printf("\nLevel Easy choosen!\n\n");
                                
                                fp=fopen("topic3a.txt","r");
                          
                                break;
                    
                        case 2:printf("\nLevel Hard choosen!\n\n");
                     
                                fp=fopen("topic3b.txt","r");
                          
                                break;
                        default:
                        printf("\n!!! INVALID NUMBER !!!\n");                    
                    }
                    break;
                default:
                        printf("\n!!! INVALID NUMBER !!!\n");                    

            }

    
    

    int n,m;
    char data[300];
    clock_t t;
    
    for (int j=0;j<=4;j++)
    
    {
            n=a[j];
        
        
            for (int line=1;line<=((n-1)*7);line++)
        {
            fgets(data,300,fp);
            }
           

            fscanf(fp,"%d %c",&q1.qn,&q1.ans);
           
            getc(fp);
            fgets(q1.q,250,fp);
           printf("\n%d. %s",j+1,q1.q);

           for (int k=0;k<=3;k++)
               {
                fgets(q1.opt[k],250,fp);
           printf("%s",q1.opt[k]);                    //
           }
             fgets(q1.hint,200,fp);

            printf("\n\n-----INSTRUCTIONS-----");
            printf("\nType 'h' for hint\n");
            printf("Type 'q' to quit\n");
            printf("---------------------");
            
        
        
    


    printf("\n\nEnter your option _______ ");
    scanf(" %c",&choose);
    choose=toupper(choose);

    if (choose=='H')
    {printf("%s",q1.hint);
    printf("\nEnter your option again ____ ");

    scanf(" %c",&chooseb);

    
   

    chooseb=toupper(chooseb);
    if (chooseb==q1.ans)
    {score++;}
    }

    else if (choose=='Q')
    {   printf("\n***************** %s's SCORE IS %d *****************\n\n",username,score);
        exit(0);}

    else if (choose==q1.ans)
    {score+=1;}
  
    printf("\n***************** %s's SCORE IS %d *****************\n\n",username,score);
    printf("NEXT QUESTION...\n\n");
    

        
            rewind(fp);

    }


    fclose(fp);
    }while (play!=0);
    }

      else if(play==0)
    {
        printf("*******/THE GAME HAS ENDED/*******\n\n");

    }
    
    else
    {
        printf("*******/INVALID INPUT/*******\n\n");
    }
    return 0;

}

