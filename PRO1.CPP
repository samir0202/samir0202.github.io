#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
/*--------------------------------------------*/
struct members
{
	char id[10];
	char name[10];
	char mdate[10];
	char d[10];
	char dob[10];
	char bid[10];
	char bname[10];
	int qt;
	float fee;
};
/********************************************/

void screen();
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
	clrscr();
	int n;
	while(1)
	{
		clrscr();
		screen();
		gotoxy(18,12);
		textattr(130+10);
		cprintf("W><E><L><C><O><M><E  T^O  P><R><O><J><E><C><T");
		gotoxy(23,14);
		textcolor(CYAN);
		cprintf(">>-Project By: SAMIR KUMAR DUBEY-<<");
		gotoxy(30,24);
		textcolor(125);
		cprintf("@Copyright Reserved");
		gotoxy(28,15);
		textcolor(BROWN);
		cprintf("Hit Any Key To Continue...");
		getch();
		clrscr();
		screen();
		gotoxy(12,14);
		cprintf("Enter <Samir> for User Name and <samir123> for Password.");
		gotoxy(26,15);
		textcolor(BROWN);
		cprintf("Hit Again Any Key To Continue...");
		getch();
		clrscr();
		screen();
		textcolor(BROWN);
		gotoxy(26,11);
		cprintf("1. Login");
		gotoxy(26,12);
		cprintf("2. Exit");
		gotoxy(26,13);
		textcolor(CYAN);
		cprintf("Enter Choice :");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				clrscr();
				password();
				break;
			case 2:
				exit(0);
				break;
			default :
				gotoxy(26,15);
				printf("INVALIED CHOICE...TRY AGAIN");
				getch();
				clrscr();
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
		textcolor(BROWN);
		gotoxy(35,7);
		cprintf("MAIN MENU");
		gotoxy(35,8);
		cprintf("---------");
		gotoxy(20,9);
		textcolor(CYAN);
		cprintf("1. New Member Creation");
		gotoxy(20,10);
		cprintf("2. Book Issue");
		gotoxy(20,11);
		cprintf("3. Book Return");
		gotoxy(20,12);
		cprintf("4. Member List");
		gotoxy(20,13);
		cprintf("5. Member Details By ID");
		gotoxy(20,14);
		cprintf("6. Stock Entry");
		gotoxy(20,15);
		cprintf("7. Scrap Book Entry");
		gotoxy(20,16);
		cprintf("8. Remove Member");
		gotoxy(20,17);
		cprintf("9. Stack Summary(All)");
		gotoxy(20,18);
		cprintf("10. Stack Summary(Book ID)");
		gotoxy(20,19);
		cprintf("11. Issue Summary");
		gotoxy(20,20);
		cprintf("12. Return Summary");
		gotoxy(20,21);
		cprintf("13. Exit");
		gotoxy(20,22);
		textcolor(BLUE);
		cprintf("Enter Choice :");
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
				clrscr();
				screen();
				gotoxy(23,14);
				cprintf(">-Project By: SAMIR KUMAR DUBEY-<");
				gotoxy(28,15);
				textcolor(BROWN);
				cprintf("Thank You! To Using Me.");
				delay(1500);
				exit(0);
				break;
			default :
				gotoxy(20,23);
				printf("INVALIED CHOICE...TRY AGAIN");
				getch();
				clrscr();
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
		textattr(132+10);
		cprintf("@");
		gotoxy(i,25);
		cprintf("@");
	}
	for(i=1;i<=25;i++)
	{
		gotoxy(3,i);
		textattr(133+10);
		cprintf("@");
		gotoxy(75,i);
		cprintf("@");
	}

	 for(i=6;i<=71;i+=2)
	{
		gotoxy(i,2);
		textcolor(CYAN);
		cprintf("*");
		gotoxy(i,24);
		cprintf("*");
		gotoxy(i,5);
		textcolor(BLUE);
		cprintf("=");
	}
	for(i=2;i<=24;i++)
	{
		gotoxy(6,i);
		textcolor(BROWN);
		cprintf("*");
		gotoxy(72,i);
		cprintf("*");
	 }
	gotoxy(27,3);
	textcolor(RED);
	cprintf("LIBRARY MANAGEMENT SYSTEM");
	gotoxy(29.5,4);
	textcolor(GREEN);
	cprintf("Sinha Library Chapra");
}

/*************************************************************/
void password()           /*function of password*/
{
	screen();
	char pass[10];
	char pass1[10]="samir123";
	char user[10];
	char user1[10]="Samir";
	int i=0 ;
	gotoxy(32,7);
	textcolor(GREEN);
	cprintf("LOGIN SCREEN");
	gotoxy(32,8);
	cprintf("------------");
	gotoxy(29,10);
	textcolor(BROWN);
	cprintf("User Name: ");
	gotoxy(29,12);
	cprintf("Password: ");
	gotoxy(40,10);
	scanf("%s",user);
	gotoxy(39,12);
	do
	{
		pass[i]=getch();
		if(pass[i]!='\r')
		{
			textcolor(CYAN);
			cprintf("*");
		}
		i++;
	}while(pass[i-1]!='\r');
		pass[i-1]='\0';
		if(strcmp(pass1,pass)==0&&strcmp(user1,user)==0)
		{
			clrscr();
			Main_Menu();
		}
		else
		{
			gotoxy(29,14);
			cprintf("Invalied User or Password....");
			getch();
		}

}

/*****************************************************************/
void Member()			/*Member List Entry Function*/
{
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
		clrscr();
		return;
	}
	clrscr();
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
		cprintf("This Member ID is already exist...");
		getch();
		clrscr();
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
	scanf("%f",&m.fee);
	fwrite(&m,sizeof(m),1,fp);
	gotoxy(17,15);
	printf("RECORD SUCCESSFULLY SAVED...");
	getch();
	clrscr();
	fclose(fp);
}
/**********************************************************************/
void Display()					/*Member List Display Function*/
{
	screen();
	int i=13;
	FILE *fp;
	struct members m;
	fp=fopen("Member.db","rb");
	if(fp==NULL)
	{
		gotoxy(24,10);
		printf("Unable to open/creat member database");
		getch();
		clrscr();
		return;
	}
	clrscr();
	screen();
	gotoxy(34,8);
	textcolor(CYAN);
	cprintf("MEMBER LIST");
	gotoxy(34,9);
	cprintf("-----------");
	gotoxy(21,11);
	textcolor(GREEN);
	printf("ID\t Name\t DOB\t\tMDATE");
	gotoxy(21,12);
	cprintf("----------------------------------------");
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		gotoxy(21,i);
		textcolor(BROWN);
		delay(100);
		printf("%s\t %s\t%s\t%s",m.id,m.name,m.dob,m.mdate);
		i++;
	}
	getch();
	clrscr();
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
	clrscr();
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
		printf("This Book ID is already exist...");
		getch();
		clrscr();
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
	clrscr();
	fclose(fp);
}
/**********************************************************************/
void BDisplay()			/*Stock Record Display Function*/
{
	int i=12;
	FILE *fp;
	struct members b;
	fp=fopen("book.db","rb");
	if(fp==NULL)
	{
		gotoxy(22,9);
		printf("Unable to open/creat book database");
		getch();
		clrscr();
		return;
	}
	clrscr();
	screen();
	gotoxy(29,8);
	textcolor(GREEN);
	cprintf("BOOKS STOCK");
	gotoxy(29,9);
	cprintf("-----------");
	gotoxy(24,10);
	printf("BID\tBNAME\tBQTY");
	gotoxy(24,11);
	textcolor(BROWN);
	cprintf("----------------------");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		gotoxy(24,i);
		delay(100);
		printf("%s\t%s\t%\d",b.bid,b.bname,b.qt);
		i++;
	}
	getch();
	clrscr();
	fclose(fp);
}

/******************************************************************************/
void BIssue()			/*Book Issue Entry Function*/
{
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
		clrscr();
		return;
	}
	clrscr();
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
		clrscr();
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
		clrscr();
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
	fcloseall();
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
	fcloseall();
	remove("Book.db");
	rename("temp.db","Book.db");
	getch();
	clrscr();
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
		clrscr();
		return;
	}
	clrscr();
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
		clrscr();
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
		clrscr();
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
	fcloseall();
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
	fcloseall();
	remove("Book.db");
	rename("temp.db","Book.db");
	clrscr();
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
		clrscr();
		return;
	}
	clrscr();
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
			clrscr();
			fclose(fp);
			return;
		}
	getch();
	gotoxy(31,11);
	scanf("%s",&b.mdate);
	gotoxy(51,11);
	scanf("%f",&b.fee);
	fwrite(&b,sizeof(b),1,fp);
	gotoxy(17,12);
	printf("RECORD SUCCESSFULLY SAVED...");
	getch();
	clrscr();
	fclose(fp);
}

/**********************************************************************/
void Memberone(void)		/*Member by ID function*/
{
	clrscr();
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
		clrscr();
		return;
	}
	gotoxy(26,8);
	textcolor(CYAN);
	cprintf("Enter Member ID:");
	cscanf("%s",&r);
	gotoxy(20,10);
	printf("ID\t  Name\t DOB\t\t  MDATE");
	gotoxy(20,11);
	cprintf("------------------------------------------");
	gotoxy(20,12);
	while(fread(&m,sizeof(m),1,fp)==1)
	{
		if(strcmpi(r,m.id)==0)
		{
		printf("%s\t%s\t%s\t%s",m.id,m.name,m.dob,m.mdate);
		found=1;
		getch();
		}
	}
	if(found==0)
	{
		gotoxy(22,13);
		printf("Member ID does not exit....");
		getch();
	}
	getch();
	clrscr();
	fclose(fp);
}

/***************************************************************************************/
void Bookone(void)						/*Book by book id function*/
{
	clrscr();
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
		clrscr();
		return;
	}
	gotoxy(22,8);
	textcolor(GREEN);
	cprintf("Enter Book ID:");
	scanf("%s",&bk);
	gotoxy(20,10);
	printf("BookID\tBName\tQTY");
	gotoxy(20,11);
	printf("------------------------");
	gotoxy(20,12);
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		if(strcmpi(bk,b.bid)==0)
		{
			printf("%s\t\t%s\t%d",b.bid,b.bname,b.qt);
			found=1;
		}
	}
	if(found==0)
	{
		gotoxy(20,13);
		printf("Book ID does not exit....");
	}
	getch();
	clrscr();
	fclose(fp);
}

/**********************************************************************************/
void Remove(void)		/*Remove Member function*/
{
	clrscr();
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
		clrscr();
		return;
	}
	gotoxy(28,8);
	textcolor(BROWN);
	cprintf("REMOVE MEMBER");
	gotoxy(28,9);
	cprintf("-------------");
	gotoxy(26,10);
	textcolor(CYAN);
	cprintf("Enter Member ID:");
	scanf("%s",&r);
	gotoxy(18,12);
	printf("ID\t Name\t DOB\t\t  MDATE");
	gotoxy(18,13);
	cprintf("---------------------------------------");
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
		clrscr();
		fcloseall();
		return;
	}
	gotoxy(18,16);
	cprintf("Do you want to remove member (y/n): ");
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
	cprintf("Record Removed Successfully...");
	fcloseall();
	remove("Member.db");
	rename("temp.db","Member.db");
	}
	getch();
	clrscr();
	fclose(fp);
}

/********************************************************************************************/
void BISummary(void)			/*Issue book Display Function*/
{
	int i=12;
	FILE *fp;
	struct members b;
	fp=fopen("Issue.db","rb");
	if(fp==NULL)
	{
		gotoxy(17,9);
		printf("Unable to open/creat book database");
		getch();
		clrscr();
		return;
	}
	clrscr();
	screen();
	gotoxy(31,8);
	textcolor(CYAN);
	cprintf("ISSUE SUMMARY");
	gotoxy(31,9);
	cprintf("-------------");
	gotoxy(21,10);
	printf("MID\t   IDATE\tBID\tBNAME");
	gotoxy(21,11);
	cprintf("----------------------------------");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		gotoxy(21,i);
		delay(100);
		printf("%s\t %s\t%s\t%s",b.id,b.mdate,b.bid,b.bname);
		i++;
	}
	getch();
	clrscr();
	fclose(fp);
}

/*********************************************************************************************/
void RSummary(void)			/*Return Issue Book Display Function*/
{
	int i=12;
	FILE *fp;
	struct members b;
	fp=fopen("Bret.db","rb");
	if(fp==NULL)
	{
		gotoxy(24,9);
		printf("Unable to open/creat book database");
		getch();
		clrscr();
		return;
	}
	clrscr();
	screen();
	gotoxy(32,8);
	textcolor(BROWN);
	cprintf("RETURN SUMMARY");
	gotoxy(32,9);
	cprintf("--------------");
	gotoxy(23,10);
	printf("MID\tRDATE\t\tBID");
	gotoxy(23,11);
	cprintf("------------------------------");
	while(fread(&b,sizeof(b),1,fp)==1)
	{
		gotoxy(23,i);
		delay(100);
		printf("%s\t%s\t%s",b.id,b.mdate,b.bid);
		i++;
	}
	getch();
	clrscr();
	fclose(fp);
}