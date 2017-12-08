#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void gotoxy(int x, int y);
void theme();
void login();
void info();
void add();
void search();
void theme(void);
void list();
void delete();
void modify();
char U_name[15], P_word[10], P_input;
int wrong=3, count;
int i=0, valid=0;
char choice=0;
char Esc=0x1b;
int target, searchA=0, found=0;
void rectangle(int x,int y,int l,int b);
void gotoxy(int x,int y);
struct staff
{
	int id;
	char name[30];
	char location[20];
	char gender;
	int age;
	char phn[20];
}s;
void gotoxy(int x, int y)
{
	COORD CR;
	CR.X=x;
	CR.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CR);
}

void main()
{
  theme();
	login();
}
void login()
{
	sleep(2);
	system("cls");
	char Org_username[15]="Manchester";
	char Org_password[10]="Darmian36";
	get1:
	rectangle(1,6,80,30);
	gotoxy(5,10);
   	printf("**********************    BATMAN LOGIN SYSTEM    **********************\n");
   	gotoxy(10,12);
	printf("****************      BATMAN LOGIN PAGE    ******************\n");
	gotoxy(32,14);
	printf("Enter your username and password: ");
	gotoxy(32,16);
	printf("Username: ");
	gotoxy(32,18);
	printf("Password: ");
	gotoxy(32,24);
	printf("<any 9 characters>");
	gotoxy(42,16);
	scanf("%s", U_name);
	gotoxy(42,18);
	for(count=0;count<9;count++)
	{
		P_input=getch();
		P_word[count] = P_input;
	  	P_input = '*' ;
	  	printf("%c", P_input);
	}	
	if (strcmp(U_name, Org_username) == 0 && strcmp(P_word, Org_password) == 0)
	{
		system("cls");
		gotoxy(25,10);
		printf("***********************  Login successful  ************************");
		sleep(3);
		info();
	}
	else
	{
		if(wrong<=1)
		{
			goto finish;
		}
		wrong--;
		system("cls");
		gotoxy(38,30);
		printf("Invalid username and password.");
		gotoxy(38,22);
		printf("You have %i chances left",wrong);
		goto get1;
	}
	finish:
	system("cls");
	gotoxy (40,12);
	printf("Sorry, fail to log in.");		
}
void info()
{
	system("cls");
	A1:
	rectangle(12,6,70,30);
	gotoxy(13,8);
	printf("*************** BATMAN LOGIN SYSTEM ********************\n\n");
	gotoxy(13,10);
	printf("________________________________________________________\n\n");
	gotoxy(13,11);
	printf("\t\t\t BATMAN LOGIN MENU\n\n");
	gotoxy(13,12);
	printf("________________________________________________________\n\n");
	gotoxy(14,14);
	printf("A.  ADD:");
	gotoxy(14,16);
	printf("B.  SEARCH:");
	gotoxy(14,18);
	printf("C.  LIST:");
	gotoxy(14,20);
	printf("D.  DELETE:");
	gotoxy(14,22);
	printf("E.  MODIFY:");
	gotoxy(14,28);
	printf("Press Esc to exit..");
	S:
	gotoxy(14,24);
	printf("****Enter your choice[A-E]: ");
	choice=getch();
	if(choice == Esc)
	{
		system("cls");
		exit(0);
	}
	switch(choice)
	{
		case 'a':
		case 'A':
			add();
			break;
		case 'b':
		case 'B':
			search();		
			break;
		case 'c':
		case 'C':
			list();
			break;
		case 'd':
		case 'D':
			delete();
			break;
		case 'e':
		case 'E':
			modify();
			break;
		default:
			system("cls");
			gotoxy(20,8);
			printf("***INVALID DATA. PLEASE, ENTER VALID INPUT**.");
			goto A1;
			break;
	}
}
void add()
{
	system("cls");
	int id;
    FILE *sfile;
	sfile = fopen("D:\\project.txt","r+");
		rectangle(1,4,70,30);
	gotoxy(3,6);
	printf("******************   BATMAN LOGIN SYSTEM   *********************\n\n");
	gotoxy(2,7);
	printf("___________________________________________________________________\n\n");
	gotoxy(20,8);
	printf("Enter the Details Below");
	gotoxy(2,9);
	printf("___________________________________________________________________\n\n");
	I:
	if((sfile = fopen("D:\\project.txt","r+"))!=NULL)
	{
		 gotoxy(13,10);
		printf("ID: ");
		scanf("%d",&id);
		while(fscanf(sfile,"%i %s %s %c %i %s\n",&s.id, s.name, s.location, &s.gender, &s.age, s.phn)!=EOF)
		{
			if(id == s.id)
			{
				 gotoxy(13,11);
				printf("THE ID ALREADY EXIST.");
				goto I;
			}
		}
		s.id = id;
	}
	else
	{
		 gotoxy(13,10);
		printf("ID: ");
		scanf("%d",&s.id);	
	}
	do
	{
			gotoxy(13,12);
		printf("NAME: ");
		fflush(stdin);
		gets(s.name);
		s.name[0]=toupper(s.name[0]);
		for (i=0;i<strlen(s.name); ++i)
		{
			if(isalpha(s.name[i]))
			{
				valid = 1;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
				gotoxy(13,13);
			printf("Name contain invalid character. Please enter again.");
		}
	}while(!valid);
	do
	{
	    gotoxy(13,14);
		printf("Location: ");
		fflush(stdin);
		gets(s.location);
		s.location[0]=toupper(s.location[0]);
		for (i=0;i<strlen(s.location); ++i)
		{
			if(isalpha(s.location[i]))
				valid = 1;
			else
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
				gotoxy(13,15);
			printf("Location contain invalid character. Please enter again.");
		}
	}while(!valid);
	A:
			gotoxy(13,16);
	printf("GENDER[M or F]: ");
	scanf(" %c",&s.gender);
	s.gender=toupper(s.gender);
	switch(s.gender)
	{
		case 'm':
		case 'M':
			break;
		case 'f':
		case 'F':
			break;
		default:
				gotoxy(13,17);
			printf("Please,enter valid Character[M or F].");
			goto A;
			break;
	}
	do
	{
			gotoxy(13,18);
		printf("AGE: ");
		scanf("%i",&s.age);
		if(s.age<18 || s.age>30)
		{
				gotoxy(13,19);
			printf(" Please, enter you age.Above 18 and Below 30");
		}
	}while(s.age<18 || s.age>30);
	
	do
	{
		C:
				gotoxy(13,20);
		printf("PHONE NUMBER: ");
		fflush(stdin);
		scanf("%s",s.phn);
		if (strlen(s.phn)!=10 || strlen(s.phn)>10)
		{
				gotoxy(13,21);
			printf("Please, Enter 10 digit number.");
			goto C;
		}
		for(i=0;i<strlen(s.phn); i++) 
		{
			if(!isalpha(s.phn[i]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
				gotoxy(13,21);
			printf("The phone number entered is invalid. Please, give a valid phone number.");
		}
	}while(!valid);
	fprintf(sfile,"%i %s %s %c %i %s\n",s.id, s.name, s.location, s.gender, s.age, s.phn);
	fclose(sfile);
		gotoxy(13,25);
	printf("SUCCESFULLY RECORDED.\n");
	getch();
	system("cls");
	S:
	gotoxy(10,15);
		gotoxy(13,26);
	printf("Press esc key to go back to staff menu....");
	choice=getch();
	if(choice == Esc)
	{
		info();
	}
	else
	{
		gotoxy(25,13);
		printf("****Invalid key.****");
		goto S;
	}
}
void search()
{
	system("cls");
	FILE *sfile;
	sfile = fopen("d:\\project.txt","r");
	rectangle(1,6,100,30);
    gotoxy(13,8);
	printf("************************* BATMAN LOGIN SYSTEM *************************\n\n");
	gotoxy(2,10);
	printf("_________________________________________________________________________________________________\n\n");
	gotoxy(13,11);
	printf("\t\t\t\t   Search TABLE\n");
	gotoxy(2,12);
	printf("_________________________________________________________________________________________________\n\n");
	gotoxy(3,14);
	printf("Enter the ID: ");
	scanf("%i",&target);
	while(fscanf(sfile,"%i %s %s %c %i %s\n",&s.id,s.name,s.location,&s.gender,&s.age,s.phn)!=EOF)
	{
		if(target==s.id)
		{
			gotoxy(3,16);
			printf("Record Found.");
			gotoxy(3,18);
			printf("ID: %i",s.id);
			gotoxy(3,20);
			printf("NAME: %s",s.name);
			gotoxy(3,22);
			printf("LOCATION: %s",s.location);
			gotoxy(3,24);
			printf("GENDER: %c",s.gender);
			gotoxy(3,26);
			printf("AGE: %i",s.age);
			gotoxy(3,28);
			printf("CONTACT NUMBER: %s",s.phn);
			break;
		}
	}
	if(target!=s.id)
	{
		gotoxy(15,15);
		printf("NO RECORD.");
	}
	fclose(sfile);
	getch();
	system("cls");
	S:
	gotoxy(10,15);
	printf("\n\tPress esc key to go back to staff menu....");
	choice=getch();
	if(choice == Esc)
	{
		info();
	}
	else
	{
		gotoxy(25,13);
		printf("****Invalid key.****");
		goto S;
	}
}
void list()
{
	system("cls");
	FILE *sfile;
	sfile = fopen("d:\\project.txt","r");
	rectangle(1,6,100,30);
    gotoxy(13,8);
	printf("************************** BATMAN LOGIN SYSTEM ****************************\n\n");
	gotoxy(2,10);
	printf("_________________________________________________________________________________________________\n\n");
	gotoxy(13,11);
	printf("\t\t\t\t   RECORD TABLE\n");
	gotoxy(2,12);
	printf("_________________________________________________________________________________________________\n\n");
	printf("  %-10s","ID");
	printf("%-20s","NAME");
	printf("%-20s","LOCATION");
	printf("%-10s","GENDER");
	printf("%-10s","AGE");
	printf("%-10s","PHONE NUMBER");
	printf("\n");
	while(fscanf(sfile,"%d %s %s %c %i %s\n",&s.id,s.name,s.location,&s.gender,&s.age,s.phn)!=EOF)
	{
		printf("  %-10i", s.id);
		printf("%-20s", s.name);
		printf("%-20s", s.location);
		printf("%-10c", s.gender);
		printf("%-10i", s.age);
		printf("%-10s", s.phn);
		printf("\n");
	}
	fclose(sfile);
	getch();
	system("cls");
	S:
	gotoxy(10,2);
	printf("Press esc to go back to staff menu.... ");
	choice=getch();
	if(choice == Esc)
	{
		info();
	}
	else
	{
		gotoxy(25,1);
		printf("****Invalid key.*****");
		goto S;
	}
}
void delete()
{

	system("cls");
	FILE *sfile, *tfile;
	sfile = fopen("d:\\project.txt", "r");
		rectangle(1,6,70,30);
    gotoxy(5,8);
	printf("****************** BATMAN LOGIN SYSTEM *****************\n\n");
		gotoxy(2,10);
	printf("___________________________________________________________________\n\n");
	gotoxy(13,11);
	printf("\t\t   RECORD TABLE\n");
	gotoxy(2,12);
	printf("___________________________________________________________________\n\n");
	gotoxy(3,14);
	printf("Enter the ID: ");
	scanf("%i",&target);
	tfile = fopen("d:\\temp1.txt", "w+");
	if(sfile==NULL)
	{
		printf("\n Cannot open file");
		getch();
		info();
	}
	else
	{
		while(fscanf(sfile,"%i %s %s %c %i %s\n",&s.id,s.name,s.location,&s.gender,&s.age,s.phn)!=EOF)
		{
			if(target!=s.id)
			{
				fprintf(tfile,"%i %s %s %c %i %s\n",s.id,s.name,s.location,s.gender,s.age,s.phn);
			}
			else
			{
				found = 1;
			}
		}
		if (!found)
		{
				gotoxy(3,16);
			printf("Record not found.");
		}
		else
		{
				gotoxy(3,15);
			printf("Record deleted.");
		}
		fclose(sfile);
		fclose(tfile);
		remove("d:\\project.txt");
		rename("d:\\temp1.txt","d:\\project.txt");
	}
	getch();
	system("cls");
	S:
	gotoxy(10,2);
	printf("Press esc to go back to staff menu.... ");
	choice=getch();
	if(choice == Esc)
	{
		info();
	}
	else
	{
		gotoxy(25,1);
		printf("****Invalid key.*****");
		goto S;
	}
}
void modify()
{
	char ch;
	system("cls");
	FILE *sfile, *modify;
   	sfile=fopen("d:\\project.txt","rb+");
   	rectangle(1,6,100,30);
    gotoxy(13,6);
	printf("ENTER THE INFO NO OF THE PERSON WHOSE ACCOUNT IS TO BE UPDATED\n");
   	if(sfile==NULL)
   	{
   		gotoxy(13,7);
		printf("Cannot open file!! ");
		getch();
		info();
	}
	gotoxy(13,9);
   	printf("Modifying Record ");
   	gotoxy(13,11);
   	printf("Enter the ID : ");
   	scanf("%i",&target);
   	gotoxy(13,13);
	modify=fopen("d:\\temp1.txt","a+");
	if(modify==NULL)
	{
		gotoxy(13,14);
		printf("Cannot open file");
		getch();
		info();
	}
	else
	{
		while(fscanf(sfile,"%i %s %s %c %i %s\n",&s.id,s.name,s.location,&s.gender,&s.age,s.phn)!=EOF)
		{
			if(s.id==target)
			{
				found =1;
				gotoxy(13,15);
				printf("********************** Existing Record *********************\n");
					gotoxy(13,16);
				printf("%i\t %s\t %s\t %c\t %i\t %s\t\n",s.id,s.name,s.location,s.gender,s.age,s.phn);
				do
				{
					gotoxy(13,17);
					printf("Enter New NAME: ");
					scanf("%s", s.name);
					s.name[0]=toupper(s.name[0]);
					for (i=0;i<strlen(s.name); ++i)
					{
						if(isalpha(s.name[i]))
						{
							valid = 1;
						}
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid) 
					{
						gotoxy(13,18);
						printf("Name contain invalid character. Please enter again.");
					}
				}while(!valid);
				do
				{
					gotoxy(13,19);
					printf("Enter New LOCATION: ");
					scanf("%s", s.location);
					s.location[0]=toupper(s.location[0]);
					for (i=0;i<strlen(s.location); ++i)
					{
						if(isalpha(s.location[i]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						gotoxy(13,20);
						printf("Location contain invalid character. Please enter again.");
					}
				}while(!valid);
				
				do 
				{
					gotoxy(13,22);
					printf("Enter New AGE: ");
					scanf("%i", &s.age);
					if(s.age<18 || s.age>30)
					{
						gotoxy(13,23);
						printf("Age should be from 18 to 30. Please, enter you age.");
					}
				}while(s.age<18 || s.age>30);
				
			
				do
				{
					C:
						gotoxy(13,25);
					printf("Enter New PHONE NUMBER: ");
					scanf("%s",s.phn);
					if (strlen(s.phn)!=10 || strlen(s.phn)>10)
					{
						gotoxy(13,26);
						printf("Please, Enter 10 digit number.");
						goto C;
					}
					for(i=0;i<strlen(s.phn); i++)
					{
						if(!isalpha(s.phn[i]))
						{
							valid=1;
						}
						else
						{
							valid=0;
							break;
						}
					}
					if(!valid)
					{
						gotoxy(13,27);
						printf("The contact number entered is invalid. Please, give a valid contact number.");
					}
				}while(!valid);
				gotoxy(13,28);
				printf("Press 'U'' to UPDATE and other key to cancel...");
				ch=getche(); 
				if(ch=='u' || ch=='U')
					{
						fprintf(modify,"%i %s %s %c %i %s\n",s.id,s.name,s.location,s.gender,s.age,s.phn);
						fflush(stdin);
						gotoxy(13,29);
						printf("Record updated successfully...");
					}					
			}
			else
			{
				fprintf(modify,"%i %s %s %c %i %s\n",s.id,s.name,s.location,s.gender,s.age, s.phn);
				fflush(stdin);
			}
		}
	if (!found) printf("\nNo Record found!!");
	fclose(modify);
	fclose(sfile);
	remove("d:\\project.txt");
	rename("d:\\temp1.txt","d:\\project.txt");	
	}
	getch();
	system("cls");
	S:
	gotoxy(10,2);
	printf("Press esc to go back to staff menu.... ");
	choice=getch();
	if(choice == Esc)
	{
		info();
	}
	else
	{
		gotoxy(25,1);
		printf("****Invalid key.*****");
		goto S;
	}
}
void theme()
{
    rectangle(12,6,70,30);
	gotoxy(15,10);
    time_t t;
	time(&t);
	system("COLOR 1F");
	printf("\t**************** BATMAN LOGIN SYSTEM **************\n\n");
	gotoxy(18,12);
	printf("\t*************************************\n");
	gotoxy(24,14);
	printf("\tWELCOME TO LOGIN SYSTEM\n");
	gotoxy(19,17);
	printf("Current date and time : %s",ctime(&t));
	gotoxy(16,20);
	printf("LOADING\n");
	gotoxy(22,24);
	printf("Created by NISCHAL KHADGI");
	Sleep(1000);
	system("cls");
	}
void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);
    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }
        }
    }
    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}


