#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>

struct peopledata
   {
    int id;
    int rs;
    char date[20];
    char relation[20];
    char reason[20];

   } ;
    peopledata  p1;
//************************** Function Declare **************************
void MainMenu(void);
//void ShowInf(void);
void Searchdata(void);
void showid(void);
void Add_rec(void);
//void outsc(void);
void loginpage(void);


//************************ Main Method ********************************
int n;
void main(){


    loginpage(); 
     
}

//************************ Login Page  **********************************
void loginpage(){

    printf("\n\n\n\t\t\t\t*********************************************************\n");
    printf("\t\t\t\t#      Welcome to Expences Money Project.               #\n");
    printf("\t\t\t\t#                                                       #\n");
    printf("\t\t\t\t#      Expenses: MONEY                                  #\n");
    printf("\t\t\t\t#                                                       #\n");
    printf("\t\t\t\t#      YEAR: 2021-22                                    #\n");
    printf("\t\t\t\t*********************************************************\n");

  {
 	
  	int e=0;
  	char username[20];
  	char password[30];
  	char original_username[20]="hukam2004";
  	char original_password[12]="207401";
	 
    do  
    {
   
  	 printf("\n\t\t\t\tUSERNAME:");
  	 scanf("%s",username);
     /* *********************************************/
  	 printf("\n\n\t\t\t\tPASSWORD:");
    	scanf("%s",password);
 	
    	if(strcmp(original_username,username)==0  && strcmp(original_password,password)==0)
  	  {
 		   printf("\n\n\n\t\t\t\tLogin Successful......");
       system("cls");
       MainMenu();
 		   getch();
   
 		   break;
	    }
	 
	    else
	    {
	    	printf("\n\n\n\t\t\t\tIncorrect info..\n\n");
	    	e++;
	    	getch();
	    } 	
    }while(e<=3);

   printf("\n\n\t\t\t\t--------------------------------------------------------------------------------");
	 system("cls");
  }

}

/* ************************************************** MAIN MENU *************************************** */

void MainMenu(){


 	  printf("\n\n\n\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\t\t\t\t#      COLLEGE: IIMT GROUP OF COLLEGE GREATER           #\n");
    printf("\t\t\t\t#      NAME: HUKAMSINGH                                 #\n");
    printf("\t\t\t\t#      COURSE: BCA                                      #\n");
    printf("\t\t\t\t#      YEAR: 2021-22                                    #\n");
    printf("\t\t\t\t#      Expenses: MONEY                                  #\n");
    printf("\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");  
   
   
    printf("\n\n                              \t*************** Choose an Operation : ******************\n\n");
    
    printf("\t\t\t\t01. Create New Data \t\t\t02. Show Information ");
    printf("\n");
    printf("\n\t\t\t\t03. Search Data \t\t\t04. Show id for Search \n");
    printf("\n\t\t\t\t05. Exit(0) \n\n\n");
    
    printf("\n\t\t\t\t< Press Any operation > ");
    scanf("%d",&n);
    system("cls");

    switch(n)
    {
      case 1:
      Add_rec();
      break;

      case 2:
      //ShowInf();
      break;

      case 3:
       Searchdata();
      break;

      case 4:
      showid();
      break;

      case 5:
     // outsc();
      break;

    }
  
}

/* *************************************************** ADD RECORD ******************************************** */

void Add_rec() {

      int rs;
       int id;
       char ans;
       char date[20];
       char relation[20];
       char reason[20];
         time_t t;
       t = time(NULL);
       struct tm tm = *localtime( &t );

        printf("\n\t\t\t\tYou have choosen Create new data.\n\n");
       

 	      FILE *ptr;
        ptr = fopen("Project_file.txt"," a+ ");
        if(ptr==NULL){
      
	         printf("File does not esit..");
	        return;
        }
       /*
        fprintf(ptr,"\nDate: %d-%d-%d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
         printf("\n\t\t\t\tCurrent Date: %d-%d-%d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
       */
         printf("\n\t\t\t\tID: ");
         scanf("%d",&id);
         fprintf(ptr,"\nId: %d",id);

         printf("\n\t\t\t\tDate: ");
         scanf("%s",date);
         fprintf(ptr,"\nDate: %s",date);

         fprintf(ptr,"\t  Time: %d-%d",tm.tm_hour, tm.tm_min, tm.tm_sec);
         printf("\n\t\t\t\tCurrent Time: %d-%d-%d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);

         printf("\n\t\t\t\tRupees: ");
         scanf("%d",&rs);
         fprintf(ptr,"\t  Rupees: %d",rs);

         printf("\n\t\t\t\tReason: ");
         scanf("%s",reason);
         fprintf(ptr,"\t Reason: %s",reason);

         printf("\n\t\t\t\tRelation: ");
         scanf("%s",relation);
         fprintf(ptr,"\tRelation: %s",relation);


         fclose(ptr); 
                     
        sd:
   	
         printf("\n\t\t\t\tDo you want to add more [Y/N]: ");
         scanf("%c",&ans);
         if(toupper(ans)=='Y')
         {
        	Add_rec();
         }
   
         else if(toupper(ans)=='N')
         {
          printf("\n\t\t\t\tThank You ....");
          getch();
          MainMenu();
         }
   
         else 
         {
   	      printf("\n\t\t\t\tInvalid Input..");
         }

        goto sd;
}



/* ****************************************** SEARCH NEW OPERATION ********************************************* */
        
void Searchdata()
{
  struct peopledata
   {
    int id;
    int rs;
    char date[20];
    char relation[20];
    char reason[20];

   } p;

    int id , flag = 0;

   FILE *ptr;
   ptr = fopen("Project_file.txt"," a+ ");
   if(ptr==NULL){
      
	         printf("File does not esit..");
	         return;
        }
    
    printf("Do you want to be search data:");
    scanf("%d",&id);

    while(fread(&p,sizeof(p),1,ptr)>0 && flag==0)
    {
      if(p.id == id)
      {
        flag  = 1;
        printf("Record is found\n");
        printf("%d %s %d %s %s ",p.id, p.date, p.rs, p.reason, p.relation);
      }
    }

   if(flag == 0)
   {

    printf("Record is not fount");
   }

   fclose(ptr);

}

/* **************************************** SHOW ID FOR SEARCH OPERATION ******************************************* */

void showid()
{

	printf("\n\n\n\t\t\t\t---------------------------------------------------------\n");
  printf("\t\t\t\t+      NAME: OMKAR            *  ID: 512                +\n");
  printf("\t\t\t\t+      NAME: HUKAMSINGH       *  ID: 620                +\n");
  printf("\t\t\t\t+      NAME: YOEGNDRA         *  ID: 715                +\n");
  printf("\t\t\t\t+      NAME: 2021-22          *                         +\n");
  printf("\t\t\t\t---------------------------------------------------------\n");

}