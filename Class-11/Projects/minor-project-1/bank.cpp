#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;
vector<int> acc_no,amount;
vector<string> name,branch;
int n;
void details();
void display();
void persons_detail();
void withdraw();
void deposit();
int main(){
    system("CLS");
    int ch;
    char wish='y';
    details();
    while(wish=='y'){
        system("CLS");
        cout<<"----------------Welcome to KDFC Bank----------------\n";
        cout<<"-------------------Banking Portal----------------\n";
        cout<<"1. Display all accounts\n2. Display a particular account\n3. Withdraw\n4. Deposit\n5. Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                display();
                break;
            case 2:
                persons_detail();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                deposit();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Invalid choice\n";
        }
        cout<<"Do you want to continue(y/n): ";
        cin>>wish;
    }
    system("CLS");
    cout<<"Thank you for using our services!\n";
    return 0;
}
void details(){
    cout<<"-----------------Management__Portal----------------\n";
    cout<<"Insert details of new customers\n";
    cout<<"Enter number of customers: ";
    cin>>n;
    int acc,amt;
    string nam,bran;
    for(int i=0;i<n;i++){
        cout<<"Enter account number: ";
        cin>>acc;
        acc_no.push_back(acc);
        cout<<"Enter name: ";
        cin>>nam;
        name.push_back(nam);
        cout<<"Enter branch: ";
        cin>>bran;
        branch.push_back(bran);
        cout<<"Enter balance: ";
        cin>>amt;
        amount.push_back(amt);
    }
}
void display(){
    system("CLS");
    cout<<"----------------Customer Portal----------------\n";
    cout<<acc_no.size()<<endl;
    cout<<"Account number\tName\t\tBranch\t\tBalance\n";
    for(int i=0;i<n;i++){
        cout<<acc_no[i]<<"\t\t"<<name[i]<<"\t\t"<<branch[i]<<"\t\t"<<amount[i]<<endl;
    }
}
void persons_detail(){
    system("CLS");
    cout<<"----------------Customer Portal----------------\n";
    int acc;
    cout<<"Enter account number: ";
    cin>>acc;
    for(int i=0;i<n;i++){
        if(acc==acc_no[i]){
            cout<<"Account number: "<<acc_no[i]<<endl;
            cout<<"Name: "<<name[i]<<endl;
            cout<<"Branch: "<<branch[i]<<endl;
            cout<<"Balance: "<<amount[i]<<endl;
        }
    }
}
void deposit(){
    system("CLS");
    cout<<"----------------Deposit Portal----------------\n";
    int acc,dep_amt;
    cout<<"Enter account number: ";
    cin>>acc;
    cout<<"Enter deposit amount: ";
    cin>>dep_amt;
    for(int i=0;i<n;i++){
        if(acc==acc_no[i]){
            amount[i]+=dep_amt;
            cout<<"Amount deposited successfully\n";
            cout<<"Updated balance: "<<amount[i]<<endl;
        }
    }
}
void withdraw(){
    system("CLS");
    cout<<"----------------Withdraw Portal----------------\n";
    int acc,with_amt;
    cout<<"Enter account number: ";
    cin>>acc;
    retry:
    cout<<"Enter withdraw amount: ";
    cin>>with_amt;
    for(int i=0;i<n;i++){
        if(acc==acc_no[i]){
            if(amount[i]>=with_amt){
                amount[i]-=with_amt;
                cout<<"Amount withdrawn successfully\n";
                cout<<"Updated balance: "<<amount[i]<<endl;
            }
            else{
                cout<<"Insufficient balance\n";
                cout<<"Retry again!\n";
                goto retry;
            }
        }
    }
}