/*******************************************************
	   HEADER FILES USED IN PROJECT
********************************************************/

#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
void aas(int x, int j, char g[], int k=7, float belay=0.5)
{int i;  randomize();
for(i=0;i<x;i++)
{
if(i==0)
{gotoxy(1,1);
cout<<" "  ; }
gotoxy(i,j);
cprintf(" ");
if(i!=x-1)
textcolor(random(15));
else
textcolor(k);
cprintf(g);
if(i==0)
{
gotoxy(1,1);
cout<<"                                                               " ;
}
delay(15);

}
textcolor(WHITE);
delay(belay*1000);
}
void esc()
{
gotoxy(60,1);
cout<<"Press Esc to exit";
gotoxy(1,1);
}


void lol(int h, int hh, char goh[],int c=15,int del=21)
{
char ch;
int i,j=0;
randomize();
while(goh[j]!='\0')
{
for(i=0;i<random(25);i++)
{gotoxy(h,hh);
 delay(del);
 ch=65+random(40);textcolor(random(10)+1);
 cprintf("%c",ch);}
gotoxy(h,hh);
textcolor(c);cprintf("%c",goh[j]);
j++;h++;
if(h==81)
{h=1;hh++;}
}
}


void exiting()
{

clrscr();
cout<< "\n\t\t\tTHOUGHT OF THE EXECUTION\n\n\n";
randomize();
int i = random(7);
delay(80);

if(i==0)
lol(1,5," You can do anything, but not everything.    -David Allen \0");
if(i==1)
lol(1,5," Perfection is achieved, not when there is nothing more to add,  but when there is nothing left to take away.   -Antoine de Saint-Exupry\0");
if(i==2)
lol(1,5," The richest man is not he who has the most, but he who needs the least.   -Unknown Author\0");
if(i==3)
lol(1,5," Courage is not the absence of fear, but rather the judgement that something else is more important than fear.    -Ambrose Redmoon\0");
if(i==4)
lol(1,5," When hungry, eat your rice; when tired,close your eyes. Fools may laugh at me, but wise men will know what I mean.   -Lin-Chi\0");
if(i==5)
lol(1,5," To the man who only has a hammer,everything he encounters begins to look like a nail. -Abraham Maslow\0");
if(i==6)
lol(1,5," We are what we repeatedly do; excellence, then, is not an act but a habit.   -Aristotle\0");
delay(1500);
lol(3,10," The Program is Exiting  \0");
delay(500);
for(int D=0;D<3;D++)
{cout<<". "; delay(444);}
delay(2000);
exit(1);

}

int exiti()
{
 clrscr();
 char filana;
 aas(5,7,"ARE YOU SURE YOU WANT TO EXIT ? ",14,0.001);
 aas(15,9,"Yes",7,0); aas(15,9,"Y",14,0);
 aas(15,10,"No",7,0); aas(15,10,"N",14,0);
 filana=getche();
 if(filana=='n'||filana=='N')
 return 1;
 return 0;
}
void exit()
{
if(exiti()==0)
exiting();
}

//***************************************************************
//                   CLASS 1 USED IN PROJECT
//***************************************************************

class element
{

 char ename[15];
 int eno, eper, egrp,x;

   void valcalculate()
   {
    x=0;
    if(egrp<3 || egrp>12 && egrp!=18)
    {
     x=egrp;
     if(x>=13)
      x-=10;
     if(x>4)
      x=8-x ;
    }
   }
  void remarks()
  {
	 cout<<" \t\tRemarks : ";
	 textcolor(CYAN+BLACK);
	 if(egrp==18)
	 cprintf("noble gas");
	 else if(egrp==1&&eno!=1)
	 cprintf("alkali metal")         ;
	 else if(egrp==2)
	 cprintf("alkaline earth metal");
	 else if(egrp==17)
	 cprintf("halogen")          ;
	 else if(egrp>2 &&egrp<13)
	 cprintf("transition element");
  }
 public:
	char esym[3];
	void getdata()
	{
	 cout<<"\n Enter The atomic number of Element :";
	 cin>>eno;
	 cout<<"\n Enter The Name of The Element : ";
	 gets(ename);
	 cout<<"\n Enter The Symbol : ";
	 gets(esym);
	 cout<<"\n Enter The Period No. : ";
	 cin>>eper;
	 cout<<"\n Enter The Group No. : ";
	 cin>>egrp;
	 valcalculate();
	 }
	void disp_config();
	void showdata()
	{

	 textcolor(WHITE);
	  cprintf("\n");
	 cout<<"\n \t\tAtomic number     : "<<eno;
	 cout<<"\n \t\tName              : "<<ename;
	 cout<<"\n \t\tAtomic Symbol     : "<<esym;
	 cout<<"\n \t\tBelongs to Period : "<<eper ;
	 cout<<"\n \t\tBelongs to Group  : "<<egrp;
	 cout<<"\n \t\tIts Valency is    : " ;
	 if(x>0&&x<5)
	 cout<<x<<'\n';
	 else
	 cout<<"undeterminable or 0 \n";
	 remarks();
	textcolor(WHITE);

	 }

       //	 void show_t()
	 //{ cprintf(); }


  int reteper()
  {return eper;}

  int retegrp()
  {return egrp;}

  int  reteno()
  {return eno;}

};
/**********************************************
	  class1 ends here
**********************************************/

void element::disp_config()
	 {
	 int at , n, l ;
	 at=eno ;
	 char a;
	 cout<<" \t\tElectronic conifig.:" ;
	 for(n=1;n<5;n++)
	  {
	  if(at==0)
	  break;
	   for(l=0;l<n&&at!=0;l++)
	    {
	     cout<<'\t';
	     if(l==0)
	     a='s';
	      else if(l==1)
	       a='p';
	       else if(l==2)
		a='d';
	     if(l==0)
	     {
	       if(at/2>=1)
		{
		 cout<<n<<a<<2;
		 at-=2;
		 }
		 else
		 {
		 cout<<n<<a<<at ;
		 at=0;
		 break;
		 }
		}
	      else if(l==1)
	      {
	       if(at/6>=1)
		{
		 cout<<n<<a<<6;
		 at-=6;
		 if(n==3)
		 cout<<"\t \t" ;
		 }
	       else
	       {
		cout<<n<<a<<at;
		at=0;
		break;
	       }
	     }
	    else if(l==2)
	     {
	       if(at/10>=1)
	       {
	       cout<<n<<a<<10;
	       at-=10;
	       }
	       else
	       {
	       cout<<n<<a<<at;
	       at=0;
	       break;
	       }
	     }
	   }
	  cout<<" ;";
	  }
	 }
//**********************************************************
// CLASS 2 USED IN PROJECT  FOR STRUCTURES OF HYDROCARBONS
//**********************************************************
class organic
{
	int d1,p1[100];
public:
	int func_alkane();
	int func_alkene();
	int func_alkyne();
}cobj;
//*********************************
//        CLASS2 ENDS HERE
//*********************************

int organic::func_alkane()
{
   clrscr();
   int n;

   cout<<"\n\n\t\tENTER THE NO. OF  CARBON ATOMS : ";
   cin>>n;
   if(n<=0)
   {	cout<<"\nNo of Carbon atoms should be greater 0. ";
	return(1);
   }
   else if(n==1)
   {
	gotoxy(31,6);
	cout<<"H";
	gotoxy(31,7);
	cout<<"³";
	gotoxy(28,8);
	cout<<"HÄÄCÄÄH";
	gotoxy(31,9);
	cout<<"³";
	gotoxy(31,10);
	cout<<"H";
	return(0);
   }
   gotoxy(11,6);
   cout<<"H";
   gotoxy(11,7);
   cout<<"³";
   gotoxy(8,8);
   cout<<"HÄÄC";
   gotoxy(11,9);
   cout<<"³";
   gotoxy(11,10);
   cout<<"H";
   int l=0;
   for(int i=1,j=12;i<n-1;i++,j=j+4)
   {
      if(i%15==0)
      {
	j=8;
	l=l+7;
       }
      if(i%45==0)
      {
	cout<<"\n\n\t\t\tPress any key to continue.....";
	getch();
	clrscr();
	j=8;
	l=0;
      }
      gotoxy(j,l+8);
      cout<<"ÄÄ";
      gotoxy(j+3,l+8);
      cout<<"C";
      gotoxy(j+3,l+7);
      cout<<"³";
      gotoxy(j+3,l+9);
      cout<<"³";
      gotoxy(j+3,l+6);
      cout<<"H";
      gotoxy(j+3,l+10);
      cout<<"H";
   delay(80);
   }
   gotoxy(j,l+8);
   cout<<"ÄÄ";
   gotoxy(j+3,l+8);
   cout<<"C";
   gotoxy(j+3,l+7);
   cout<<"³";
   gotoxy(j+3,l+9);
   cout<<"³";
   gotoxy(j+3,l+6);
   cout<<"H";
   gotoxy(j+3,l+10);
   cout<<"H";
   gotoxy(j+4,l+8);
   cout<<"ÄÄ";
   gotoxy(j+6,l+8);
   cout<<"H";
   return(0);
}

int organic::func_alkene()
{
     clrscr();
     int n;
     cout<<"\n\n\t\tENTER THE NUMBER OF CARBON ATOMS : ";
     cin>>n;
     if(n<2)
     {
	cout<<"\n\tAlkene Less Than 2 Carbon Atoms Is Not Possible!!";
	getch();
	return(1);
     }
     else if(n==2)
     {
	gotoxy(32,6);
	cout<<"H";
	gotoxy(32,7);
	cout<<"³";
	gotoxy(28,8);
	cout<<"HÄÄ C Í C ÄÄ H";
	gotoxy(36,7);
	cout<<"³";
	gotoxy(36,6);
	cout<<"H";
	return(0);
     }
     cout<<"\n\t\tHOW MANY DOUBLE BONDS DO YOU REQUIRE?  ";
     cin>>d1;
     if(d1>=n)
     {
      cout<<"\n Double Bonds More Than No. Of Carbon Atoms Is Impossible!!";
      getch();
      return(1);
     }
     cout<<"\n\t\tENTER THE POSITIONS OF DOUBLE BONDS: ";
     for(int i=0;i<d1;)
     {
	cin>>p1[i];
	if(p1[i]<=0 || p1[i]>=n)
	   cout<<"\n Position should be > Zero & < the no of C atoms(Enter Again) : ";
	else
	   i++;
      }
     //Sorting of the double bonds array
     int stemp;
     for(int a=0;a<d1;a++)
     {
	for(int b=a+1;b<d1;b++)
	{
		if(p1[a]>p1[b])
		{
			stemp=p1[a];
			p1[a]=p1[b];
			p1[b]=stemp;
		}
	}
     }
     clrscr();
     int test=0,temp=0;
     if(p1[0]==1)
	  {
	     gotoxy(12,6);
	     cout<<"H";
	     gotoxy(12,7);
	     cout<<"³";
	     gotoxy(8,8);
	     cout<<"H Ä C Í";
	     temp=1;
	     test=1;
	   }
     else if(p1[0]!=1)
	   {
	     gotoxy(12,6);
	     cout<<"H";
	     gotoxy(12,7);
	     cout<<"³";
	     gotoxy(	8,8);
	     cout<<"H Ä C Ä";
	     gotoxy(12,9);
	     cout<<"³";
	     gotoxy(12,10);
	     cout<<"H";
	   }

     int flag,pos,j,k=0,l=0;
     for(j=14,i=1;i<n-1;i++,j=j+4)
      {
	   flag=pos=0;
	   if(temp==1)     k=1;
	   else            k=0;
	   //Linear Search for the position of Double Bond
	   for(;k<d1;k++)
	   {
		if(i+1==p1[k])
		{
		     flag=1;
		     pos=k;
		     break;
		}
	   }
	   //Per Page Shift
	   if(i%15==0)
	   {
		j=10;
		l=l+7;
	   }
	   if(i%45==0)
	   {
		cout<<"\n\n\n\t\t\tPress any key to continue.....";
		getch();
		clrscr();
		j=10;
		l=0;
	   }
	  if(p1[pos]-1==p1[pos-1]&&pos>-1)
	   {
		gotoxy(j+2,l+8);
		cout<<"C =";
		test=1;

	   }
	 else if(test==1)
	  {
		gotoxy(j+2,l+6);
		cout<<"H";
		gotoxy(j+2,l+7);
		cout<<"³";
		gotoxy(j+2,l+8);
		cout<<"C Ä";
		test=0;
	  }
	  else if(flag==1)
	  {
		gotoxy(j+2,l+6);
		cout<<"H";
		gotoxy(j+2,l+7);
		cout<<"³";
		gotoxy(j+2,l+8);
		cout<<"C =";
		test=1;
	   }
	   else if(flag==0)
	   {
		 gotoxy(j+2,l+6);
		 cout<<"H";
		 gotoxy(j+2,l+7);
		 cout<<"³";
		 gotoxy(j+2,l+8);
		 cout<<"C Ä";
		 gotoxy(j+2,l+9);
		 cout<<"³";
		 gotoxy(j+2,l+10);
		 cout<<"H";
	   }
	  delay(80);
      }
      gotoxy(j+2,l+6);
      cout<<"H";
      gotoxy(j+2,l+7);
      cout<<"³";
      gotoxy(j+2,l+8);
      cout<<"C Ä H";
      gotoxy(j+2,l+9);
      if(test!=1)
      {
	 cout<<"³";
	 gotoxy(j+2,l+10);
	 cout<<"H";
      }
      return(0);
}

int organic::func_alkyne()
{
     clrscr();

     int n;
     cout<<"\n\n\t\tENTER THE NUMBER OF CARBON ATOMS : ";
     cin>>n;
     if(n<2)
     {
	cout<<"\n\tAlkyne Less Than 2 Carbon Atoms Is Not Possible!!";
	getch();
	return(1);
     }
     else if(n==2)
     {
	gotoxy(28,8);
	cout<<"HÄÄ C ð C ÄÄ H";
	getch();
	return(0);
     }
     cout<<"\n\t\tHOW MANY TRIPLE BONDS DO YOU REQUIRE:";
     cin>>d1;
     if(d1>=n)
     {
      cout<<"\n\t\tTRIPLE BONDS MORE THAN NO.OF CARBON ATOMS IS IMPOSSIBLE!!!";
      getch();
      return(0);
     }
     cout<<"\n\t\tENTER THE POSITION OF TRIPLE BOND   :";
     for(int i=0;i<d1;)
     {
	cin>>p1[i];
	if(p1[i]<=0 || p1[i]>=n)
	   cout<<"\n Position should be > Zero & < the no of C atoms(Enter Again) : ";
	else
	   i++;
      }
     //Sorting of the array
     int stemp;
     for(int a=0;a<d1;a++)
     {
	for(int b=a+1;b<d1;b++)
	{
		if(p1[a]>p1[b])
		{
			stemp=p1[a];
			p1[a]=p1[b];
			p1[b]=stemp;
		}
	}
     }
     for(i=0;i<d1;i++)
     {
	if(p1[i-1]==p1[i]-1)
	{
	      cout<<"\n Triple bond at the consective positions are not allowed";
	      cout<<"\n Enter for the "<<i+1<<" positions";
	      cin>>p1[i];
	}
     }
     clrscr();
     int temp=0,test=0;
     if(p1[0]==1)
     {
	gotoxy(8,8);
	cout<<"HÄÄCð";
	temp=1;
	test=1;
      }
     else if(p1[0]!=1)
     {
	gotoxy(11,6);
	cout<<"H";
	gotoxy(11,7);
	cout<<"³";
	gotoxy(8,8);
	cout<<"HÄÄCÄÄ";
	gotoxy(11,9);
	cout<<"³";
	gotoxy(11,10);
	cout<<"H";
     }
     int k=0,flag,j,l=0;
     for(i=1,j=12;i<n-1;i++,j=j+4)
     {
	   flag=0;
	   if(temp==1)
		k=1;
	   else
		k=0;
	   //Linear Search for the position of Triple Bond
	   for(;k<d1;k++)
	   {
		if(i+1==p1[k])
		 {
			flag=1;
			break;
		 }
	   }
	  //Per Page Shift
	  if(i%15==0)
	  {
		j=10;
		l=l+7;
	  }
	  if(i%45==0)
	  {
		cout<<"\n\n\n\t\t\tPress any key to continue.....";
		getch();
		clrscr();
		j=10;
		l=0;
	  }
	  if(test==1)
	  {
		gotoxy(j+2,l+8);
		cout<<"C Ä";
		test=0;
	  }
	  else if(flag==1)
	  {
		gotoxy(j+2,l+8);
		cout<<"C ð ";
		test=1;
	   }
	  else if(flag==0)
	  {
		gotoxy(j+2,l+6);
		cout<<"H";
		gotoxy(j+2,l+7);
		cout<<"³";
		gotoxy(j+2,l+8);
		cout<<"C Ä";
		gotoxy(j+2,l+9);
		cout<<"³";
		gotoxy(j+2,l+10);
		cout<<"H";
	    }
       delay(80);
      }
      gotoxy(j+2,l+8);
      cout<<"C Ä H";
      gotoxy(j+2,l+9);
      if(test!=1)
      {
	 gotoxy(j+2,l+6);
	 cout<<"H";
	 gotoxy(j+2,l+7);
	 cout<<"³";
	 gotoxy(j+2,l+9);
	 cout<<"³";
	 gotoxy(j+2,l+10);
	 cout<<"H";
      }
      return(1);
}

 void arrange();

//***********************************************
// global declaration for stream object, object
//***********************************************
 fstream fp;
 element et;
//***********************************************
//     f u n c t i o n  to write in  f i l e
//***********************************************

void write_element()
   {
    fp.open("per.dat",ios::out|ios::app|ios::binary);
    et.getdata();
    fp.write((char*)&et,sizeof(element));
    fp.close();
    cout<<"\n\n  DONE!!! ";
    arrange();
    getch();
   }


//***************************************************************
//    	function to read all records from file
//****************************************************************


void display_all()
{
     clrscr();
    char choice;
    float dely;
    esc();
    cout<<"\n\tDisplay All Elements with Details\n\t  1. Automatically \n\t  2. User driven  \n\t  3. Back \n\t\t  ";
    choice=getch();
      if(choice=='1'&&choice!=27)
       { clrscr();
       cout<<"\n\t Please note that Automatic mode once initiated cannot be paused/\n\tstopped till all the elements' details are displayed";
       cout<<"\n\n\n\t PRESS 1 for Auto driven,  2 for User driven\n\t\t\t\t";
       choice=getche();
       if(choice=='1')
	{cout<<"\n\n\n\t ENTER number of seconds(correct upto 3 decimal places) for which \n\ta record should be displayed\t";
	cin>>dely;
	dely*=1000; }
       }
    if(choice!='3'&& choice!=27)
    {
    clrscr();
    fp.open("per.dat",ios::in|ios::binary);
    char gh=5 ;
    while(fp.read((char*)&et,sizeof(element)))
	{
	if (gh==8||gh==27)
	break;
	 cprintf("\n");
	 et.showdata();
	 cout<<'\n';
	 et.disp_config();
	 cout<<'\n';
	 cout<<"__________________________________________________________________________";
	 cprintf("\n");

	 if(choice=='1'){delay(dely);}
	 else{gh=getch();}
	 clrscr();
	 }
    fp.close();
    cout<<"\n Press any key to go to menu" ; getch();}
    else if(choice==27)
    exit();
}


//*************************************************
//   functions to read specific record from file
//*************************************************
//Search by ATOMIC NO.
 void display_sp(int n)
{
    int flag=0;
    fp.open("per.dat",ios::in|ios::binary);
    while(fp.read((char*)&et,sizeof(element)))
	{
	 if(et.reteno()==n)
		{
		 clrscr();
		 et.showdata();
		 cout<<'\n';
		 et.disp_config();
		 flag=1;
		}
	}
    fp.close();
if(flag==0)
 cout<<"\n\n\t\tRecord does NOT exist";
    getch();
}
//Search by ATOMIC SYMBOL
void display_sp2(char a[3])
{
    int flag=0;
    textbackground(MAGENTA);
    cprintf("\n");
    clrscr();
    fp.open("per.dat",ios::in|ios::binary);
    while(fp.read((char*)&et,sizeof(element)))
	{
	 if(strcmpi(et.esym,a)==0)
		{
		 clrscr();
		 et.showdata();
		 cout<<'\n';
		 et.disp_config();
		 flag=1;
		}
	}
    fp.close();
    if(flag==0)
      cout<<"\n\n\t\tRecord does NOT exist";
    getch();
}


//function to ARRANGE ELEMENTS BY ATOMIC NO. BEFORE DISPLAYING
void arrange()
{

int n,i=0,g,j,k[50];
fp.open("per.dat",ios::in|ios::binary);
fp.seekg(0,ios::end);
n=fp.tellg()/sizeof(element);
fp.seekg(0,ios::beg);
    while(fp.read((char*)&et,sizeof(element)) )
	   {  k[i]=et.reteno(); i++;   }
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  if(k[i]<k[j])
   {g=k[i];
    k[i]=k[j];
    k[j]=g;}
  }
}
i=0;
fp.close();
fp.open("per.dat",ios::in|ios::binary);
fstream t;
t.open("temporay.dat",ios::out|ios::binary);
    while(fp.read((char*)&et,sizeof(element))   )
      {
	    if(et.reteno()==k[i])
	    {
	     t.write((char*)&et,sizeof(element));
	     i++;
	     fp.seekg(0,ios::beg);
	    }
      }
t.close();
fp.close();
remove("per.dat");
rename("temporay.dat","per.dat");

}
//function used by delete_element and modify_element to perform their jobs
void DELETE(int del)
{
    fp.open("per.dat",ios::in|ios::binary);
    fstream fp2;
    fp2.open("temporay.dat",ios::out|ios::binary);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&et,sizeof(element)))
	{
	 if(et.reteno()!=del)
		{
		 fp2.write((char*)&et,sizeof(element));
		 }
	 }
    fp2.close();
    fp.close();
    remove("per.dat");
    rename("temporay.dat","per.dat");
    }
//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_element()
{
    int no,found=0;
    clrscr();
    cout<<"\n\tPlease Enter The Atomic Number of The Element To Be Modded : ";
    cin>>no;
    fp.open("per.dat",ios::in|ios::binary);
    while(fp.read((char*)&et,sizeof(element)) && found==0)
	   {
	    if(et.reteno()==no)
	      {et.showdata();  found=1;}
	   }


     fp.close();
     DELETE(no);
      if(found==0)
    cout<<"\n\n Record Not Found ";
     else
     {
     write_element();
      }
    getch();
}


//**************************************
// function to add P a s s w o r d
//**************************************
void pa_ss()
{
char str[20];
int k,i=0;
for(k=0;k<3;k++)
{
  clrscr();
  cout<<"\n\t\t\t\t\t\t\tPress Esc to exit\n\t\t\t\t\t\t\tPress Enter to cont. ";
  cout<<"\n\n Enter the P a s s w o r d : ";
  randomize();

  while(1)
   {
    char ch;
    int x=random(10)+random(-5);
    str[i]=getch();
    if(str[i]!=8)
      {
       ch=str[i]+x;
       if(str[i]==13 || str[i]==27)
	 break;
       i++;
       cout<<ch;
      }
    else
     {
      i--;
      gotoxy(i+30,5) ;
      cout<<" ";
      gotoxy(i+30,5);
     }

   }
  if(str[i]==27)
  {k=3;break;}


   str[i]='\0';
   if (strcmp(str,"godblessme")==0)
   { cout<<"\n  <<<<< You are authorised user >>>>>>>";
    k=4;
    delay(800);
   break;
   }
   else
   {cout<<"\n  <<<<  Invalid P A S S W O R D  >>>>>>>";
    getch();
    i=0;
    if(k==1)
     {clrscr();
      cout<<"\n\tLAST chance";}
      delay(1250)  ;}

  }
if(k==3)
{
if (str[i]!=27)
cout<<"\n\n\n  Get the KEY of the LOCK,";
cout<<"\n  Program will EXIT ";
delay(1000);
for(int D=0;D<4;D++)
{cout<<". "; delay(333);}
exiting();}
}

//**********************************************
//    	function to delete record of file
//**********************************************

void delete_element()
   {
    int no;
    clrscr();
    cout<<"\n\n\n\t DELETE ELEMENT RECORD";
    cout<<"\n\n Please Enter The Atomic Number of The Element You Want To Delete \n\t";
    cin>>no;
    DELETE(no);
    cout<<"\n\n\t\t\tRecord Deleted ..";
    getch();
    }


//************************************************
//    function to display the periodic table
//************************************************

 void periodic_table()
  {
     textbackground(MAGENTA);
     int W,Z;
     char A[3],xx;
     clrscr();
     fp.open("per.dat",ios::in|ios::binary);
     if(!fp)
     {
       cout<<"\n ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
       cout<<"\n\n\n Program will close. Press any key!";
       getch();
       exit();
     }
     textcolor(MAGENTA+YELLOW+WHITE+WHITE+BLINK)     ;
     cout<<"\n\t\t\t\t";
     cprintf("THE PERIODIC TABLE ");

       while(fp.read((char*)&et,sizeof(element)))
	 {

	   Z=3*et.reteper()+2;
	   W=4*et.retegrp();

	   lol(W,Z,et.esym,1,50);
	}
     fp.close();
     delay(50);
     textcolor(YELLOW);
     gotoxy(5,21);
     cprintf("Do you want to know specific element details?(y,n) ");
     cout<<"\n\n\t\t\t\t\t";
     xx=getch();
     if(xx=='y'||xx=='Y')
     {
     gotoxy(7,23);
     cout<<"\t\t\t\t\t\t";
     gotoxy(7,23);
     cprintf("Enter element symbol   ");
      cin>>A;
      display_sp2(A);
      }
     textcolor(WHITE);
     textbackground(BLACK);
  }

//declaration of function to show hydrocarbons menu
void game();

//**********************************************
//   function to display the DISPLAY menu
//**********************************************

   void display()
   {
    textcolor(WHITE);
    int rno;
    char ch,ans;
    clrscr();
    esc();
    cout<<"\n\n\n\tDISPLAY MENU";
    cout<<"\n\n\n\t1. PERIODIC TABLE \n\n\t2. Display SINGLE ELEMENT \n\n\t3. Structures of HYDROCARBONS ";
    cout<<"\n\n\t4. Display ALL ELEMENTS \n\n\t5. Back To MAIN MENU ";

cout<<"\n\n\n\t\t\t  Enter Choice (1-5)? ";
    ans=getch();
    switch(ans)
    {
     case '1' : periodic_table();break;
     case '2' : {
		clrscr();
		char g, A[3];
		esc();
		cout<<"\n\n\t SEARCH by \n\t\t 1. Atomic Number\n\t\t 2. Atomic Symbol\n\t\t 3. Back";
		g=getch();
		clrscr();
		if(g=='1')
		{
		 cout<<"\n\n Enter Atomic Number Of Element : ";
		 cin>>rno;
		 display_sp(rno);
		 display();
		}
		else if (g=='2')
		{ cout<<"\n\n Enter Atomic Symbol Of Element : ";
		 cin>>A;
		 display_sp2(A);
		 textbackground(BLACK);
		 display(); }
		else if(g==27)exit();
		}
	       break;
     case '4': arrange();
	       display_all();break;

     case '3': game();break;

     case 27:exit();
     default:  cout<<'\a';
    }
   textcolor(WHITE);
 }

//*********************************
//    	INTRODUCTION FUNCTION
//*********************************

void intro()
{
 clrscr();
  textcolor(YELLOW);
  aas(61,5,"Ankur Arora",12,.3);
  aas(72,7,"&",9,0.01);
  aas(59,9,"xxxxxxxxxxxxxx",10,.3);
  aas(59,11,"PROUDLY PRESENT",11);
  aas(55,15,"Computer Project on",7,0.2);
  aas(25,17,"Modern Periodic Table & Structure Of Hydrocarbons",14,0.03);
  aas(15,21,"Under benign guidance of our respected teacher Diwaker Mishra",7,0.001);
  aas(57,22,"PGT COMPUTER SCIENCE",7,2);getch(); //exit(1);
 textbackground(BROWN+CYAN);
 clrscr();
 lol(30,7,"Modern Periodic Table\0",14);
 lol(39,10,"&\0",14);
 lol(28,13,"Structures of Hydrocarbons\0",14);
 textcolor(WHITE);
 delay(1500);
 getch();
 cout<<"\n\n\n\n  MADE BY :  \n\t   ";
 lol(10,18,"Ankur ARORA    915xxxx\0");
 lol(10,20,"ankursmooth@gmail.comx\0");
 lol(1,22,"  SCHOOL :  Oxford Sr. Sec School \0");
 cout<<" \n  Don't press any key program is loading (: ";
 delay(200);
 for(int i=1;i<9;i++)
  {delay(350);   cprintf(". . ");delay(100);}
 delay(100);
 cout<<"\n  \t\t\t\t\t   PROGRAM LOADED  "  ;
 delay(1500);
 textbackground(BLACK);

}

//**********************************************
//    	ORGANIC FAMILY/HYDEOCARBONS MENU
//**********************************************

void game()
{
 char ch;
 do
  {
	textbackground(BROWN+CYAN);
	cprintf("\n");
	clrscr();
	aas(32,6,"O R G A N I C  F A M I L Y",14);
	gotoxy(31,7);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	esc();
	gotoxy(32,9);
	cout<<"1: ALKANE";
	gotoxy(32,11);
	cout<<"2: ALKENE";
	gotoxy(32,13);
	cout<<"3: ALKYNE";
	gotoxy(32,15);
	cout<<"0: Back to Main Menu";
	gotoxy(32,17);
	cout<<"Enter Choice : ";
	ch=getch();
	switch(ch)
	{
	   case '1':
		cobj.func_alkane();getch();
		break;
	   case '2':
		cobj.func_alkene(); getch();
		break;
	   case '3':
		cobj.func_alkyne(); getch();
		break;
	   case '0':
		break;
	   case 27:exit();
	   default:
		 cout<<"\n\n\t\t\t\t  Wrong Choice";
	 }


  }while(ch!='0');
 textbackground(BLACK);
}


//***************************************************************
//    	ENTRY / EDIT MENU FUNCTION
//****************************************************************
void entry_menu()
{
  clrscr();
  char ch2;
  esc();
  cout<<"\n\n\n\t CHANGING DATA FILES";
  cout<<"\n\n\t1.CREATE ELEMENT RECORD";
  cout<<"\n\n\t2.MODIFY ELEMENT RECORD";
  cout<<"\n\n\t3.DELETE ELEMENT RECORD";
  cout<<"\n\n\t4.BACK TO MAIN MENU";
  cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
  ch2=getch();
  switch(ch2)
  {
    case '1': clrscr();
	      write_element();
	      break;
      case '2': modify_element();break;
      case '3': delete_element();break;
      case '4': break;
      case 27:exit();
      default:cout<<"\a";entry_menu();
   }
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

void main()
{
  char ch;
  intro();
  pa_ss();
    do
    {
	  clrscr();
	  esc();
	  cout<<"\n\n\n\tMAIN MENU";
	  cout<<"\n\n\t 1. DISPLAY MENU";
	  cout<<"\n\n\t 2. CREATE/EDIT/DELETE MENU";
	  cout<<"\n\n\t 3. EXIT";
	  cout<<"\n\n\tPlease Select Your Option (1-3) ";
	  ch=getch();
	  esc();
	  switch(ch)
	  {
		 case '1': clrscr();
			   display();
			   break;
		  case '2': entry_menu();
			    break;
		  case '3':exit();
		  case 27:exit();
		  default :cout<<"\a";
	}
    }while(1);
}

//*********************************
//    	   END OF PROJECT
//*********************************
