#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
/*--------------------------------------------*/
struct members
{
	char id[10];
	char name[10];
	char mdate[10];
	char d[10];
	char fee[10];
	char dob[10];
	char bid[10];
	char bname[10];
	int qt;
};
/********************************************/

void screen();
void gotoxy(short x, short y);
void Main_Menu(void);
void password(void);
void Member(void);
void Display(void);
void Stock(void);
void BDisplay(void);
void BIssue(void);
void BReturn(void);
void BScrape(void);
void Memberone(void);
void Bookone(void);
void Remove(void);
void BISummary(void);
void RSummary(void);

void main()
{
	system("cls");
	int n;
	while(1)
	{
		system("cls");
		screen();
		gotoxy(18,12);
		printf("W><E><L><C><O><M><E  T^O  P><R><O><J><E><C><T");
		gotoxy(23,14);
		printf(">>-Project By: SAMIR KUMAR DUBEY-<<");
		gotoxy(30,24);
		printf("@Copyright Reserved");
		gotoxy(28,15);
		printf("Hit Any Key To Continue...");
		getch();
		system("cls");
		screen();
		gotoxy(26,11);
		system("color 12");
		printf("1. Login");
		gotoxy(26,12);
		printf("2. Exit");
		gotoxy(26,13);
		printf("Enter Choice :");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				system("cls");
				password();
				break;
			case 2:
				exit(0);
				break;
			default :
				gotoxy(26,15);
				printf("INVALIED CHOICE...TRY AGAIN");
				getch();
				system("cls");
		}
	}
}

/*********************************************************/
void Main_Menu()      /*Main Menu Function*/
{
	int n;
	while(1)
	{
		screen();
		gotoxy(35,7);
		system("color 6");
		printf("MAIN MENU");
		gotoxy(35,8);
		printf("---------");
		gotoxy(20,9);
		printf("1. New Member Creation");
		gotoxy(20,10);
		printf("2. Book Issue");
		gotoxy(20,11);
		printf("3. Book Return");
		gotoxy(20,12);
		printf("4. Member List");
		gotoxy(20,13);
		printf("5. Member Details By ID");
		gotoxy(20,14);
		printf("6. Stock Entry");
		gotoxy(20,15);
		printf("7. Scrap Book Entry");
		gotoxy(20,16);
		printf("8. Remove Member");
		gotoxy(20,17);
		printf("9. Stack Summary(All)");
		gotoxy(20,18);
		printf("10. Stack Summary(Book ID)");
		gotoxy(20,19);
		printf("11. Issue Summary");
		gotoxy(20,20);
		printf("12. Return Summary");
		gotoxy(20,21);
		printf("13. Exit");
		gotoxy(20,22);
		printf("Enter Choice :");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				Member();
				break;
			case 2:
				BIssue();
				break;
			case 3:
				BReturn();
				break;
			case 4:
				Display();
				break;
			case 5:
				Memberone();
				break;
			case 6:
				Stock();
				break;
			case 7:
				BScrape();
				break;
			case 8:
				Remove();
				break;
			case 9:
				BDisplay();
				break;
			case 10:
				Bookone();
				break;
			case 11:
				BISummary();
				break;
			case 12:
				RSummary();
				break;
			case 13:
				exit(0);
				break;
			default :
				gotoxy(20,23);
				printf("INVALIED CHOICE...TRY AGAIN");
				getch();
				system("cls");
		}
	}
}

/**************************************************/
void screen(void)     /*screen layout function*/
{
	int i;
	for(i=3;i<=75;i+=2)
	{
		gotoxy(i,1);
		printf("*");
		gotoxy(i,25);
		printf("*");
		gotoxy(i,6);
		printf("=");
	}
	for(i=1;i<=25;i++)
	{
		gotoxy(3,i);
		printf("*");
		gotoxy(75,i);
		printf("*");
	}
	gotoxy(27,3);
	printf("LIBRARY MANAGEMENT SYSTEM");
	gotoxy(29.5,4);
	printf("Sinha Library Chapra");
}

/*************************************************************/
void password()           /*function of password*/
{
	screen();
	system("color 21");
	char pass[10];
	char pass1[10]="samir123";
	char user[10];
	char user1[10]="Samir";
	int i=0 ;
	gotoxy(26,7);
	printf("LOGIN SCREEN");
	gotoxy(26,8);
	printf("------------");
	gotoxy(23,9);
	printf("User Name: ");
	gotoxy(23,11);
	printf("password: ");
	gotoxy(34,9);
	scanf("%s",user);
	gotoxy(33,11);
	do
	{
		pass[i]=getch();
		if(pass[i]!='\r')
		{
			printf("*");
		}
		i++;
	}while(pass[i-1]!='\r');
		pass[i-1]='\0';
		if(strcmp(pass1,pass)==0&&strcmp(user1,user)==0)
		{
			system("cls");
			Main_Menu();
		}
		else
		{
			gotoxy(23,13);
			printf("Invalied User or Password....");
			getch();
		}

}

/*****************************************************************/
void Member()			/*Member List Entry Function*/
{
	system("color 31");
	screen();
	FILE *fp;
	struct members m;
	char id[10];
	int f=0;
	fp=fopen("Member.db","rb");
	if(fp==NULL)
	{
		gotoxy(17,9);
		printf("Unable to open/creat Member database");
		getch();
		system("cls");
		return;
	}
	system("cls");
	screen();
	gotoxy(26,7);
	printf("MEMBER ENTRY");
	gotoxy(26,8);
	printf("------------");
	gotoxy(17,9);
	printf("ID :");
	gotoxy(45,9);
	printf("Name :");
	gotoxy(17,11);
	printf("DOB(DD-MM-YY) :");
	gotoxy(45,11);
	printf("MDate :");
	gotoxy(17,13);
	printf("Duration(M) :");
	gotoxy(45,13);
	printf("Fee :");
	gotoxy(22,9);
	scanf("%s",id);
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		if(strcmpi(id,m.id)==0)
		{
			f=1;
			break;
		}
	}
	if (f==1)
	{
		gotoxy(17,15);
		printf("This Member ID is already exist...");
		getch();
		system("cls");
		fclose(fp);
		return;
	}
	else
	{
		fp=fopen("Member.DB","ab");
		strcpy(m.id,id);
	}
	gotoxy(52,9);
	scanf("%s",&m.name);
	gotoxy(33,11);
	scanf("%s",&m.dob);
	gotoxy(52,11);
	scanf("%s",&m.mdate);
	gotoxy(31,13);
	scanf("%s",&m.d);
	gotoxy(52,13);
	scanf("%s",&m.fee);
	fwrite(&m,sizeof(m),1,fp);
	gotoxy(17,15);
	printf("RECORD SUCCESSFULLY SAVED...");
	getch();
	system("cls");
	fclose(fp);
}
/**********************************************************************/
void Display()					/*Member List Display Function*/
{
	system("color 41");
	screen();
	int i=12;
	FILE *fp;
	struct members m;
	fp=fopen("Member.db","rb");
	if(fp==NULL)
	{
		gotoxy(24,10);
		printf("Unable to open/creat member database");
		getch();
		system("cls");
		return;
	}
	system("cls");
	screen();
	gotoxy(24,8);
	printf("MEMBER LIST");
	gotoxy(24,9);
	printf("-----------");
	gotoxy(18,10);
	printf("ID\tName\tDOB\tMDATE");
	gotoxy(18,11);
	printf("-----------------------------------");
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		gotoxy(18,i);
		sleep(1);
		printf("%s\t%s\t%s\t%s",m.id,m.name,m.dob,m.mdate);
		i++;
	}
	getch();
	system("cls");
	fclose(fp);
}

/**************************************************************************/
void Stock()			/*Book Stock Entry Function*/
{
	char bid[10];
	int f;
	FILE *fp;
	struct members b;
	fp=fopen("book.db","rb");
	if(fp==NULL)
	{
		fp=fopen("book.db","ab");
	}
	system("cls");
	screen();
	gotoxy(26,7);
	printf("BOOK ENTRY");
	gotoxy(26,8);
	printf("----------");
	gotoxy(17,9);
	printf("BID :");
	gotoxy(40,9);
	printf("BName :");
	gotoxy(17,11);
	printf("BQTY :");
	gotoxy(23,9);
	scanf("%s",bid);
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		if(strcmpi(bid,b.bid)==0)
		{
			f=1;
			break;
		}
	}
	if (f==1)
	{
		gotoxy(17,15);
		printf("This Member ID is already exist...");
		getch();
		system("cls");
		fclose(fp);
		return;
	}
	else
	{
		fp=fopen("book.DB","ab");
		strcpy(b.bid,bid);
	}
	gotoxy(48,9);
	scanf("%s",&b.bname);
	gotoxy(24,11);
	scanf("%d",&b.qt);
	fwrite(&b,sizeof(b),1,fp);
	gotoxy(17,12);
	printf("RECORD SUCCESSFULLY SAVED...");
	getch();
	system("cls");
	fclose(fp);
}
/**********************************************************************/
void BDisplay()			/*Stock Record Display Function*/
{
	system("color 61");
	int i=12;
	FILE *fp;
	struct members b;
	fp=fopen("book.db","rb");
	if(fp==NULL)
	{
		gotoxy(22,9);
		printf("Unable to open/creat book database");
		getch();
		system("cls");
		return;
	}
	system("cls");
	screen();
	gotoxy(22,8);
	printf("BOOKS STOCK");
	gotoxy(22,9);
	printf("-----------");
	gotoxy(18,10);
	printf("BID\tBNAME\tBQTY");
	gotoxy(18,11);
	printf("-----------------------");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		gotoxy(18,i);
		sleep(1);
		printf("%s\t%s\t%d",b.bid,b.bname,b.qt);
		i++;
	}
	getch();
	system("cls");
	fclose(fp);
}

/******************************************************************************/
void BIssue()			/*Book Issue Entry Function*/
{
	system("color 51");
	FILE *fp,*fp1;
	struct members m;
	struct members a;
	struct members b;
	char r[10];
	int f=0;
	char bk[10];
	char bn[10];
	fp=fopen("Issue.db","ab");

	if(fp==NULL)
	{
		gotoxy(17,9);
		printf("Unable to open/creat Issue database");
		getch();
		system("cls");
		return;
	}
	system("cls");
	screen();
	gotoxy(26,7);
	printf("BOOK ISSUE");
	gotoxy(26,8);
	printf("----------");
	gotoxy(17,9);
	printf("MID :");
	gotoxy(40,9);
	printf("IDate :");
	gotoxy(17,11);
	printf("BID :");
	gotoxy(40,11);
	printf("BName :");
	fp=fopen("Member.db","rb");
	gotoxy(23,9);
	scanf("%s",&r);
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		if(strcmpi(r,m.id)==0)
		{
		f=1;
		}
	}
	if(f==0)
	{
		gotoxy(17,13);
		printf("Member ID does not exit....");
		getch();
		system("cls");
		return;
	}
	else
	{
		fp=fopen("Issue.DB","ab");
		strcpy(b.id,r);
	}
	f=0;
	gotoxy(48,9);
	scanf("%s",&b.mdate);
	gotoxy(24,11);
	fp=fopen("book.db","rb");
	scanf("%s",&bk);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		if(strcmpi(bk,a.bid)==0)
		{
			gotoxy(48,11);
			printf("%s",a.bname);
			strcpy(bn,a.bname);
			f=1;
		}
	}
	if(f==0)
	{
		gotoxy(17,12);
		printf("Book ID does not exit....");
		getch();
		system("cls");
		fclose(fp);
		return;
	}
	else
	{
		fp=fopen("Issue.DB","ab");
		strcpy(b.bid,bk);
		strcpy(b.bname,bn);
	}
	getch();
	fwrite(&b,sizeof(b),1,fp);
	gotoxy(17,13);
	printf("RECORD SUCCESSFULLY SAVED...");
	_fcloseall();
	fp=fopen("Book.db","rb");
	fp1=fopen("temp.db","wb");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
	if(strcmpi(b.bid,bk)==0)
	{
	b.qt= b.qt-1;
	}
	fwrite(&b,sizeof(b),1,fp1);
	}
	_fcloseall();
	remove("Book.db");
	rename("temp.db","Book.db");
	getch();
	system("cls");
	fclose(fp);
}

/*****************************************************************************/
void BReturn()					/*Book Return Enry Function*/
{
	FILE *fp,*fp1;
	char r[10];
	int f=0, found=0;
	char bk[10];
	struct members b;
	struct members m;
	struct members a;

	fp=fopen("Bret.db","ab");
	if(fp==NULL)
	{
		gotoxy(17,9);
		printf("Unable to open/creat Bret database");
		getch();
		system("cls");
		return;
	}
	system("cls");
	screen();
	gotoxy(26,7);
	printf("BOOK RETURN");
	gotoxy(26,8);
	printf("----------");
	gotoxy(17,9);
	printf("MID :");
	gotoxy(40,9);
	printf("RDate :");
	gotoxy(17,11);
	printf("BID :");
	gotoxy(23,9);
	fp=fopen("Member.db","rb");
	scanf("%s",&r);
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		if(strcmpi(r,m.id)==0)
		{
		f=1;
		}
	}
	if(f==0)
	{
		gotoxy(17,13);
		printf("Member ID does not exit....");
		getch();
		system("cls");
		return;
	}
	else
	{
		fp=fopen("Bret.DB","ab");
		strcpy(b.id,r);
	}
	gotoxy(48,9);
	scanf("%s",&b.mdate);
	gotoxy(24,11);
	fp=fopen("book.db","rb");
	scanf("%s",&bk);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		if(strcmpi(bk,a.bid)==0)
		{
			found=1;
		}
	}
	if(found==0)
	{
		gotoxy(17,12);
		printf("Book ID does not exit....");
		getch();
		system("cls");
		fclose(fp);
		return;
	}
	else
	{
		fp=fopen("Bret.DB","ab");
		strcpy(b.bid,bk);
	}

	fwrite(&b,sizeof(b),1,fp);
	gotoxy(17,12);
	printf("RECORD SUCCESSFULLY SAVED...");
	getch();
	_fcloseall();
	fp=fopen("Book.db","rb");
	fp1=fopen("temp.db","wb");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
	if(strcmpi(b.bid,bk)==0)
	{
	b.qt= b.qt+1;
	}
	fwrite(&b,sizeof(b),1,fp1);
	}
	_fcloseall();
	remove("Book.db");
	rename("temp.db","Book.db");
	system("cls");
	fclose(fp);
}

/********************************************************************/
void BScrape()			/*Scrape Entry Function*/
{
	FILE *fp;
	struct members b;
	struct members a;
	char bk[10];
	int found=0;
	fp=fopen("Scrape.db","ab");
	if(fp==NULL)
	{
		gotoxy(17,9);
		printf("Unable to open/creat Member database");
		getch();
		system("cls");
		return;
	}
	system("cls");
	screen();
	gotoxy(26,7);
	printf("SCRAPE ENTRY");
	gotoxy(26,8);
	printf("------------");
	gotoxy(17,9);
	printf("BID :");
	gotoxy(42,9);
	printf("BName :");
	gotoxy(17,11);
	printf("Scrape Date :");
	gotoxy(42,11);
	printf("BPrice :");
	gotoxy(23,9);
	fp=fopen("book.db","rb");
	scanf("%s",&bk);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
		if(strcmpi(bk,a.bid)==0)
		{
			gotoxy(50,9);
			printf("%s",&a.bname);
			found=1;
		}
	}
		if(found==0)
		{
			gotoxy(17,12);
			printf("Book ID does not exit....");
			getch();
			system("cls");
			fclose(fp);
			return;
		}
	getch();
	gotoxy(31,11);
	scanf("%s",&b.mdate);
	gotoxy(51,11);
	scanf("%s",&b.fee);
	fwrite(&b,sizeof(b),1,fp);
	gotoxy(17,12);
	printf("RECORD SUCCESSFULLY SAVED...");
	getch();
	system("cls");
	fclose(fp);
}

/**********************************************************************/
void Memberone(void)		/*Member by ID function*/
{
	system("cls");
	system("color 36");
	screen();
	FILE *fp;
	struct members m;
	char r[10];
	int found=0;
	fp=fopen("Member.db","rb");
	if(fp==NULL)
	{
		gotoxy(22,8);
		printf("Unable to open Member database... ");
		getch();
		system("cls");
		return;
	}
	gotoxy(22,8);
	printf("Enter Member ID:");
	scanf("%s",&r);
	gotoxy(18,8);
	printf("ID\tName\tDOB\tMDATE");
	gotoxy(18,9);
	printf("-----------------------------------");
	gotoxy(18,11);
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		if(strcmpi(r,m.id)==0)
		{
		printf("%s\t%s\t%s\t%s",m.id,m.name,m.dob,m.mdate);
		found=1;
		}
	}
	if(found==0)
	{
		gotoxy(18,8);
		printf("Member ID does not exit....");
	}
	getch();
	system("cls");
	fclose(fp);
}

/***************************************************************************************/
void Bookone(void)						/*Book by book id function*/
{
	system("cls");
	system("color 46");
	screen();
	FILE *fp;
	struct members b;
	char bk[10];
	int found=0;
	fp=fopen("book.db","rb");
	if(fp==NULL)
	{
		gotoxy(18,9);
		printf("Unable to open book database... ");
		getch();
		system("cls");
		return;
	}
	gotoxy(18,7);
	printf("Enter Book ID:");
	scanf("%s",&bk);
	gotoxy(18,9);
	printf("BookID\tBName\tQTY");
	gotoxy(18,10);
	printf("------------------------");
	gotoxy(18,11);
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		if(strcmpi(bk,b.bid)==0)
		{
			printf("%s\t%s\t%d",b.bid,b.bname,b.qt);
			found=1;
		}
	}
	if(found==0)
	{
		gotoxy(18,9);
		printf("Book ID does not exit....");
	}
	getch();
	system("cls");
	fclose(fp);
}

/**********************************************************************************/
void Remove(void)		/*Remove Member function*/
{
	system("color 26");
	system("cls");
	screen();
	FILE *fp,*fp1;
	struct members m;
	char r[10];
	char n;
	int found=0;
	fp=fopen("Member.db","rb");
	fp1=fopen("temp.db","wb");
	if(fp==NULL)
	{
		gotoxy(18,9);
		printf("Unable to open Member database... ");
		getch();
		system("cls");
		return;
	}
	gotoxy(24,8);
	printf("REMOVE MEMBER");
	gotoxy(24,9);
	printf("-------------");
	gotoxy(22,10);
	printf("Enter Member ID:");
	scanf("%s",&r);
	gotoxy(18,12);
	printf("ID\tName\tDOB\tMDATE");
	gotoxy(18,13);
	printf("-----------------------------------");
	gotoxy(18,14);
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		if(strcmpi(r,m.id)==0)
		{
		printf("%s\t%s\t%s\t%s",m.id,m.name,m.dob,m.mdate);
		found=1;
		}
	}
	if(found==0)
	{
		gotoxy(18,14);
		printf("Member ID does not exit....");
		getch();
		system("cls");
		_fcloseall();
		return;
	}
	gotoxy(18,16);
	printf("Do you want to remove member (y/n): ");
	fflush(stdin);
	n=getchar();
	rewind(fp);
	if(n=='y'||n=='Y')
	{
	while(fread(&m,sizeof(m),1,fp)==1)
	{
	if(strcmpi(r,m.id)!=0)
	{
	fwrite(&m,sizeof(m),1,fp1);
	}
	}
	gotoxy(18,18);
	printf("Record Removed Successfully...");
	_fcloseall();
	remove("Member.db");
	rename("temp.db","Member.db");
	}

	getch();
	system("cls");
	fclose(fp);
}

/********************************************************************************************/
void BISummary(void)			/*Issue book Display Function*/
{
	system("color 51");
	int i=12;
	FILE *fp;
	struct members b;
	fp=fopen("Issue.db","rb");
	if(fp==NULL)
	{
		gotoxy(17,9);
		printf("Unable to open/creat book database");
		getch();
		system("cls");
		return;
	}
	system("cls");
	screen();
	gotoxy(24,8);
	printf("ISSUE SUMMARY");
	gotoxy(24,9);
	printf("-------------");
	gotoxy(18,10);
	printf("MID\tIDATE\t\tBID\tBNAME");
	gotoxy(18,11);
	printf("-----------------------------------");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		gotoxy(18,i);
		sleep(1);
		printf("%s\t%s\t%s\t%s",b.id,b.mdate,b.bid,b.bname);
		i++;
	}
	getch();
	system("cls");
	fclose(fp);
}

/*********************************************************************************************/
void RSummary(void)			/*Return Issue Book Display Function*/
{
	system("color 15");
	int i=12;
	FILE *fp;
	struct members b;
	fp=fopen("Bret.db","rb");
	if(fp==NULL)
	{
		gotoxy(24,9);
		printf("Unable to open/creat book database");
		getch();
		system("cls");
		return;
	}
	system("cls");
	screen();
	gotoxy(24,8);
	printf("RETURN SUMMARY");
	gotoxy(24,9);
	printf("--------------");
	gotoxy(18,10);
	printf("MID\tRDATE\t\tBID");
	gotoxy(18,11);
	printf("-----------------------------------");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		gotoxy(18,i);
		sleep(1);
		printf("%s\t%s\t%s",b.id,b.mdate,b.bid);
		i++;
	}
	getch();
	system("cls");
	fclose(fp);
}
void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
