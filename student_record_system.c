#include<stdio.h>
#include<conio.h>
#include<windows.h>

#define ESC 27

void gotoxy(int x,int y);
void textcolor(int ForgC);
void ClearConsoleToColors(int ForgC,int BackC);
void set_password();
char* username();
void menu();
void add_student();
void clear_window();
void list_record();
void search_student();
void update_record();
void delete_record();

struct student
{
	 char id[15];
     char name[20];
     char par_name[20];
     char Class[15];
     char mob[15];
     char addr[50];
  
};

struct student s;

/************************************** main start ************************************/
int main()
{
	SetConsoleTitle("STUDENT RECORD SYSTEM");
    ClearConsoleToColors(10,15);
    system("cls");
    set_password();
    menu();
    return 0;
}

/************************************* main ends ***************************************/

COORD coord={0,0};
int pwdcounter=0;


void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hStdOut,coord);
}

void textcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    } 
    return;
}

void ClearConsoleToColors(int ForgC,int BackC)
{
    WORD wColor=((BackC & 0x0F)<<4) + (ForgC & 0x0F);
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,wColor);
    DWORD count;   //This is a structure containing all the console info
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        FillConsoleOutputCharacter(hStdOut,(TCHAR)32,csbi.dwSize.X * csbi.dwSize.Y,coord,&count);
        FillConsoleOutputAttribute(hStdOut,csbi.wAttributes,csbi.dwSize.X * csbi.dwSize.Y,coord,&count);
        SetConsoleCursorPosition(hStdOut,coord);
    }
}


void set_password()
{
	char user[15];
    int x=12,y=14;
    char ps[10];

	int pass[20];
	int i=0;
    system("cls");     
    textcolor(18);
    gotoxy(15,8);printf("The database is password protected.");
    gotoxy(15,9);printf(" Enter Valid username and password");
    textcolor(12);
    gotoxy(20,x);printf("USERNAME :- ");
    gotoxy(20,y);printf("PASSWORD :- ");
    gotoxy(32,x);strcpy(user,username());
    gotoxy(32,y);
     
    while(1)
    {
        ps[i]=getch();
        if(ps[i]==13) { break; }
        else if(ps[i]==32)
		{
		    printf(" \b \b");
			
	   }
        else if(ps[i]==8)
        {
            if(i!=0)
            {
	            printf("\b \b");
	            i--;
	        }  
	        else
	        {
                printf("\a");
            }
        }
        else
        {
            printf("*");
            i++;
        }
    }
    ps[i]='\0';
     
    if(strcmp(ps,"ghostgonemad2")==0 && strcmp(user,"girishrawat")==0)
    {
     	textcolor(18);
     	gotoxy(34,17);printf("Login successfull.");
     	gotoxy(34,19);printf("Press any key to contd...");getch();	
    }
    else 
    {
        gotoxy(34,17);printf("Invalid username and password");
		gotoxy(34,19);printf("Press any key to contd...");
		getch();
		pwdcounter++;
     	if(pwdcounter==3)
        {
         	textcolor(12);
            gotoxy(34,21);printf("You attempts too much.");getch();
            exit(0);
        }
	    else
		{
		 	set_password();
		}
		 
    }
}


char* username()
{
	char *username;
	char usr[15],temp[15];
	int i=0;
	while(1)
     {
         usr[i]=getche();
         if(usr[i]==13) { break; }
         else if(usr[i]==32)
         {
         	printf("\b \b");
         	
         }
         else if(usr[i]==8)
         {
             if(i!=0)
             {
	             printf(" \b \b");
	             i--;
	         } 
			 else
			 {
			 	printf(" \a");
			 	gotoxy(35,10);printf(":");
		     }
	         
         }
         else
         {
         	temp[i]=usr[i];
             i++;
         }
     }
     temp[i]='\0';
     username=temp;
     return username;
}

void menu()
{
	char choice;
    int x=5;
	system("cls");
	gotoxy(28,3);
    textcolor(13);
    printf("STUDENT RECORD SYSTEM");
    while(1)
    {
        clear_window();
        textcolor(12);
        gotoxy(x,6);printf("1. Add Student");
        gotoxy(x,8);printf("2. Search Student");
        gotoxy(x,10);printf("3. Update Records");
        gotoxy(x,12);printf("4. Delete Records");
        gotoxy(x,14);printf("5. List Records");
        gotoxy(x,16);printf("0. For Exit");
        gotoxy(x,18);printf("Enter Your Choice :");
  
        choice=getche();
        switch(choice)
        {
            case '1':
                add_student();
                break;
            case '2':
                search_student();
                break;
            case '3':
                update_record();
                break;
            case '4':
                delete_record();
                break;
            case '5':
                list_record();
                break;
            case '0':
                exit(0);
        }
    }
}

void add_student()
{
	clear_window();
    int y=30;
    char id[15];
    char name[20];
    int flag=0;
    char c,d;
    char iid[15];
    int g;
    FILE *fp;
    textcolor(12);
    gotoxy(40,6);printf("ADD STUDENTS");
    textcolor(12);
    fp=fopen("record.dat","ab+");
    if(fp==NULL)
    {
        system("cls");printf("Error in opening file");getch();exit(1);
    } 
    
    
    
	textcolor(17); 
    fflush(stdin);
    gotoxy(y,8);printf("ID :");gets(id);
    
    
    while(fread(&s.id,sizeof(s.id),1,fp)==1)
    {
        if(strcmp(id,s.id)==0)
        {
        	flag=1;
        }
    }
    
    
    
    if(flag==1)
    {
    	gotoxy(y,10);printf("ID already exist, Please enter another ID");
        gotoxy(y,12);printf("Press any key to contd...");getch();add_student();
    }
    else
    {
    	strcpy(s.id,id);
        gotoxy(y,10);printf("Name :");gets(s.name);
        gotoxy(y,12);printf("Parents Name :");gets(s.par_name);
        gotoxy(y,14);printf("Class :");gets(s.Class);
        gotoxy(y,16);printf("Mobile No :");gets(s.mob);
        gotoxy(y,18);printf("Address :");fflush(stdin);gets(s.addr);
        textcolor(18);
        gotoxy(y,21);printf("Press Enter to save the record.");
        gotoxy(y,23);printf("Press 'E' for exit.");
        
        c=getch();
        
        if(c==13)
        {   
            fwrite(&s,sizeof(s),1,fp);
            textcolor(18);
            gotoxy(y,21);printf("                                  ");gotoxy(y,21);printf("The Record Is Successfully Added.");
		
        }
		 
        else goto g;
    }
         
     g:
     fclose(fp);
}

void clear_window()
{
    int y=30;     
    gotoxy(y,6);  printf("                                                     ");
    gotoxy(y,8);  printf("                                                     ");
    gotoxy(y,10); printf("                                                     ");
    gotoxy(y,12); printf("                                                     ");
    gotoxy(y,14); printf("                                                     ");
    gotoxy(y,16); printf("                                                     ");
    gotoxy(y,18); printf("                                                     ");
    gotoxy(y,20); printf("                                                     ");
    gotoxy(y,21); printf("                                                     ");
    gotoxy(y,22); printf("                                                     ");
    gotoxy(y,23); printf("                                                     ");
    gotoxy(y,24); printf("                                                     ");
    gotoxy(y,25);printf("                                                      ");
    gotoxy(y,26); printf("                                                     ");     
    gotoxy(24,18);printf(" ");                     
}

void list_record()
{
    FILE *fp;
    char ch;
    int g;
    int y=30;
    int check=0;
    fp=fopen("record.dat","rb");
    if(fp==NULL)
    {
     	clear_window();
     	textcolor(18);
     	gotoxy(y,6);printf("List Records");
     	textcolor(12);
     	gotoxy(y,8);printf("Sorry There Are no Record");getch();
     	return;
     	
    }
    while(1)
    { 
        fread(&s,sizeof(s),1,fp);
        if(feof(fp))
        {
        	clear_window();
            textcolor(18);
            gotoxy(y,6);printf("LIST RECORDS");
            textcolor(12);
            gotoxy(y,8);printf("There are no more records");
            gotoxy(y,10);printf(" Press any key to contd.");
	        getch();
	        break;
        	
        }
        clear_window();         
        textcolor(18);
        gotoxy(y,6);printf("LIST RECORDS");
        textcolor(17);
        gotoxy(y,8);printf("ID :%s",s.id);
        gotoxy(y,10);printf("Name :%s",s.name);
        gotoxy(y,12);printf("Parents Name :%s",s.par_name);
        gotoxy(y,14);printf("Class :%s",s.Class);
         
        gotoxy(y,16);printf("Mobile No :%s",s.mob);
        gotoxy(y,18);printf("Address :%s",s.addr);
        textcolor(18);
		gotoxy(y,20);printf("Press any key to see next record");
		gotoxy(y,22);printf("Press 'E' for exit");
		ch=getch();
		if(ch==69 || ch==101) return;
    }
    fclose(fp);    
}

void search_student()
{
    char id[15];
    int y=30;
    int g,n;
    int found=0;
    clear_window();
    textcolor(18);
    gotoxy(y,6);printf("Search Record");
    textcolor(12);
    gotoxy(y,8);printf("1. Search By ID :");
    fflush(stdin);gets(id);
    FILE *fp;
    fp=fopen("record.dat","rb");
    while(fread(&s.id,sizeof(s.id),1,fp)==1)
    { 
        if(strcmp(id,s.id)==0)
        {
            found=1;
	        break;
        }
    }
    if(found==1)
    {
    
        clear_window();
        textcolor(18);
        gotoxy(y,6);printf("Search is Successfull");
        textcolor(17);
	    gotoxy(y,8);printf("ID :%s",s.id);
        gotoxy(y,10);printf("Name :%s",s.name);
        gotoxy(y,12);printf("Parents Name :%s",s.par_name);
        gotoxy(y,14);printf("Class :%s",s.Class);
        gotoxy(y,16);printf("Mobile No :%s",s.mob);
        gotoxy(y,18);printf("Address :%s",s.addr);
        getch();
    }
    else
    {
    	gotoxy(y,10);printf("Sory, No record found in the database");
	    gotoxy(y,12);printf("Press any key to contd...");
	    getch();
    }
    fclose(fp);
}

void update_record()
{
    FILE *fp;
    FILE *fpp;
    char c;
    int flag=0;
    int y=30;
    int g,n;
    char ID[15];
    textcolor(18);
    gotoxy(y,6);printf("Update Record");
    textcolor(12);
    fp=fopen("record.dat","rb");
    if(fp==NULL)
    {
    	system("cls");printf("Error in opening file");getch();exit(1);
    }
    
    remove("temp.dat");
    
    fpp=fopen("temp.dat","wb+");
    
    if(fpp==NULL)
    {
    	system("cls");printf("Error in opening file");getch();exit(1);
    }
    
    
    gotoxy(y,8);printf("Enter Id To modify :");gets(ID);    
    while(1)
    {
     	fread(&s,sizeof(s),1,fp);
     	if(feof(fp)) break;
        if(strcmp(ID,s.id)==0)
        {
            flag=1;
            clear_window();  
            textcolor(18);
            gotoxy(y,6);printf("Student Record exist with the folowing details");
            textcolor(17);
            gotoxy(y,8);printf("ID :%s",s.id);
            gotoxy(y,10);printf("Name :%s",s.name);
            gotoxy(y,12);printf("Parents Name :%s",s.par_name);
            gotoxy(y,14);printf("Class :%s",s.Class);
            gotoxy(y,16);printf("Mobile No :%s",s.mob);
            gotoxy(y,18);printf("Address :%s",s.addr);
            textcolor(18);
            gotoxy(y,20);printf("Update Menu- Press N for name,P for Parents name");
            gotoxy(y,22);printf("      C for class,M for Mobile,A for address");
            gotoxy(y,24);printf("      S for Save,X without Save");
            g:
            textcolor(12);
            gotoxy(y+23,26);printf(" ");
            gotoxy(y,26);printf("Plz enter Your choice :");
            c=getche();
            textcolor(17);
            if(c==78 || c==110)//N=78  n=110
            {
	            gotoxy(y+6,10);printf("                              ");
	            gotoxy(y+6,10);fflush(stdin);gets(s.name);
              	goto g;
            }
            if(c==80 || c==112)//P=80  p=112
            {
	            gotoxy(y+14,12);printf("                               ");
	            gotoxy(y+14,12);fflush(stdin);gets(s.par_name);
	            goto g;
            }
            if(c==67 || c==99)//C=67  c=99
            {
             	gotoxy(y+7,14);printf("                                ");
	            gotoxy(y+7,14);fflush(stdin);gets(s.Class);
	            goto g;
            }
            if(c==77 || c==109)//M=77 m=109
            { 
	            gotoxy(y+11,16);printf("                                  ");
	            gotoxy(y+11,16);gets(s.mob);
	             goto g;
            }
            if(c==65 || c==97)//A=65  a=97
            {
            	gotoxy(y+9,18);printf("                                   ");
	            gotoxy(y+9,18);fflush(stdin);gets(s.addr);
	            goto g;
            } 
	        if(c==83 || c==115)//S==83  s=115
            {  
				fwrite(&s,sizeof(s),1,fpp); 
            }
        }
        else
        {
            fwrite(&s,sizeof(s),1,fpp);
		}
    }
  
  fclose(fp);
  fclose(fpp);
  if (flag==1)
  {
   remove("record.dat");
   rename("temp.dat","record.dat");
   }
   else
   {
   	 textcolor(18);
   	 clear_window();
   	gotoxy(y,8);printf("ID not valid");
   	getch();
   	
   }
 
}

void delete_record()
{
    int y=30;
    int flag=0;
    char c[15];
    FILE *fp;
    FILE *fpp;
    fp=fopen("record.dat","rb");
	fpp=fopen("temp.dat","wb");
    textcolor(18);
    gotoxy(34,6);printf("Delete Record");
    textcolor(12);gotoxy(34,8);printf("Enter ID to delete record :");gets(c);
    while(1)
    {
     	fread(&s,sizeof(s),1,fp);
     	if(feof(fp)) break;
        if(strcmp(c,s.id)==0)
        	flag=1;
        else
            fwrite(&s,sizeof(s),1,fpp);
    }
    fclose(fp);
    fclose(fpp);
    if(flag==1)
    {
        textcolor(18);
        gotoxy(y,10);printf("Student Record Successfully deleted."); getch();
        remove("record.dat");
        rename("temp.dat","record.dat");
    }
    else
    {
        textcolor(20);
        gotoxy(y,10);printf("Sorry, Student record not found");getch();
        remove("temp.dat");
    }
}

