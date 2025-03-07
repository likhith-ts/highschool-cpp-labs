#include<iostream>
#include<conio.h>
#include<direct.h>
#include<windows.h>
#include<iomanip>
#include<stdio.h>
#include <unistd.h>
using namespace std;

char a[15][20]={"ps4","xbox","nitendo","cakes","echo","sandisk","jiofi","phones","snacks","choco","A.C's","fruits","donuts","pens","games"};
int sno[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int price[15]={2000,6000,4000,3000,4000,6000,1000,5000,7000,10000,30000,7000,5000,7000,8000};
int h[15],m=1,k=0,sum=0,qty[15],total[15];
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void menu();
void order();
void bill();
void end();
int main()
{
 system("CLS");
 char ch;int ch1;
 cout<<"\n\n\n";
 cout<<"------------------------------------------------------------------------";
 cout<<setw(50)<<"STARK DIGITAL"<<endl;
 cout<<"------------------------------------------------------------------------";
 cout<<"\n\n\n";
 cout<<"customer menu\n\n";
 cout<<"1.MENU\n2.PLACE ORDER\n3.BILLING PAGE\n4.EXIT\n\n";
 cout<<"\nenter our option (1,2,3,4):";
 cin>>ch1;
 switch(ch1)
 { case 1:
   system("CLS");
   menu();
   break;
   case 2:
   system("CLS");
   order();
   break;
   case 3:
   system("CLS");
   bill();
   break;
   case 4:
   system("CLS");
   end();
   break;
}
getch();
return 0;
}
void menu()
{system("CLS");int ch;
 cout<<"\ts.no.\t\t\tPRODUCT NAME\t\t       .M.R.P.\t"<<endl;
 for(int i=0;i<15;i++)
 {
  cout<<"\t"<<sno[i]<<"\t\t\t"<<a[i]<<"\t\t\t\t"<<price[i]<<endl; }
  order();
}
void order()
{
 char ch;
 int i;
 cout<<setw(50)<<"--ORDER YOUR PRODUCT--";
 do{

 cout<<"\nENTER YOUR PRODUCT(in no.):";
 cin>>h[m];
 for(int i=0;i<=15;i++)
 {
 if(h[m]==sno[i])
 {cout<<"product name:"<<a[i];
  cout<<"\nproduct's MRP:"<<price[i];
  cout<<"\nenter quantity:";
  cin>>qty[i];cout<<endl;}

 }
 cout<<"do you want purchase anything else[y/n]:";
 cin>>ch;
 cout<<endl;
  m++;k++;
 }while(ch=='y');
  bill();
}
void bill()
{system("CLS");
 int i,ch;
 double disk;
 cout<<"  WELCOME TO BILLING PAGE\n\n" ;
 cout<<"products that you have ordered:\n\n";
 cout<<"NAME\t\t\tPRODUCT no.\t\tQUANTITY\tPRICE\n=============================================================================\n";
 for(m=1;m<=k;m++)
 {for(i=0;i<=15;i++)
  {if(h[m]==sno[i])
   {total[m]=price[i]*qty[i];
    cout<<a[i]<<"\t\t\t"<<sno[i]<<"\t\t\t"<<qty[i]<<"\t\t"<<total[m]<<endl;
   }
  }
 }cout<<"============================================================================="<<endl;
 for(m=1;m<=k;m++)
 sum=sum+total[m];
 cout<<" GRAND TOTAL="<<sum<<endl;
 if(sum>=0&&sum<=2499)disk=0.05;
 else if((sum>=2500)&&(sum<=4999))disk=0.1;
 else if((sum>=5000)&&(sum<=14999))disk=0.15;
 else disk=0.2;
 float sum1; sum1=sum-(sum*disk);
 cout<<"discount="<<disk;
 cout<<"\namount after discount:"<<sum1<<endl;
 cout<<"select a payment option:"<<'\n';
 cout<<"1.cash\n2.card\n3.paytm"<<endl;
 cout<<"enter your choice:";
 cin>>ch;
 cout<<'\n';
 switch(ch){
 case 1://cash
system("CLS"); 
int o,n;
 cout<<"\namount="<<sum1;
 cout<<"\nkeep the cash in the e.drawer:";
 cin>>o;
 if(o>=sum1){
 cout<<"change:"<<o-sum1<<endl;
 cout<<"PAYMENT SUCCESSFULLY COMPLETED\n";
 sleep(2);
 end();
}
else {
// textcolor(RED);
SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
printf("insufficient money");
cout<<"\nplease give Rs."<<sum1-m<<"to complete the payment"<<endl;
cin>>n;
cout<<"balance or change:"<<(m+n)-sum1<<endl;
// textcolor(BLUE);
printf("payment succesful");
sleep(2);
end();}
if(n==(sum1-n)){
cout<<"payment succesful"<<endl;
sleep(2);
end();}
break;
case 2://card
int c;
system("CLS");
cout<<"\n\n\nAMOUNT="<<sum1<<endl;
cout<<"enter your card PIN:";
cin>>c;
cout<<endl;
cout<<"please wait transaction is going on...."<<endl;
sleep(5);
// textcolor(BLUE);
printf("Transaction Succesful");
sleep(2);
end();
break;
case 3: //paytm
system("CLS");
int ch,x,y;
int e[10]={1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
cout<<"1.SCAN BARCODE\n2.Transfer through BHIMPIN";
cout<<"\nselect your money tranfer option:";
cin>>ch;
if(ch==1)//barcode
{cout<<"TOTAL AMOUNT:"<<sum1<<endl;
 cout<<"scan the barcode using your patym app"<<endl;
 cout<<"|||||||||||| |||";
 cout<<"\n|||||||||||| |||";
 cout<<"\n100101011001 101";
 sleep(2);
 cout<<"\ntransaction completed!!";
 sleep(2);
 }
else if(ch==2)//bhimpin
 {cout<<"enter the your BHIMPIN(only from 1000 to 1010):";
 cin>>x;
 cout<<"\nverifiying!!";
 sleep(2);
 for(int i=0;i<=10;i++)
 {if(x==e[i])
  cout<<"\ntransaction succesful!!";}
 sleep(2);
}
end();
}
}
void end()
{system("CLS");
int x;char y;
cout<<"\nRATE US(1,2,3,4,5):";
cin>>x;
if((x>=1)&&(x<=5))
cout<<setw(55)<<"!!THANK YOU FOR RATING US!!";
else
cout<<"rate us with the given limit";
cout<<"\n";
// textcolor(RED);
cout<<setw(50)<<"                      ---THANK YOU---";
cout<<"\n"<<setw(50)<<"                      VISIT AGAIN  ";
cout<<"\n"<<setw(53)<<"               --BY STARK DIGITAL--"<<endl;
printf("FOLLOW US ON :www.starkmnc.co");cout<<"\npress any key & enter to quit of program or press M to goto main menu:";
cin>>y;
if(y=='M'||y=='m')
main();
else
exit(0);
}

