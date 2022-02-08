#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Bank
{
private:
    int total;
    struct person
    {
        string name, address;
        int ID, cash;
        long long int contact;
    } person[100];

public:
    Bank()
    {
        total = 0;
    }
    void show();
    void AddnewUser();
    void customerlist();
    void UpdateAccount();
    void Transactions();
    void CheckDetails();
    void RemoveAccount();
    int UniqueIdentity();
};

void Bank ::show()
{
    int ch;
    while (1)
    {
        cout << "\n\nPRESS...!!" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. View Customer List" << endl;
        cout << "3. Update information of existing account" << endl;
        cout << "4. For Transactions" << endl;
        cout << "5. Check the details of an existing account" << endl;
        cout << "6. Remove existing account" << endl;
        cout << "7. Exit";

        cout << endl;

        cin >> ch;

        switch (ch)
        {
        case 1:
            AddnewUser();
            break;
        case 2:
            customerlist();
            break;
        case 3:
            UpdateAccount();
            break;
        case 4:
            Transactions();
            break;
        case 5:
            CheckDetails();
            break;
        case 6:
            RemoveAccount();
            break;
        case 7:
            exit(1);
        default:
            cout<<"Invalid Input"<<endl;
            break;
        
        }
    }
}

int main()
{

    cout << "------ OOPRA BANK --------  " << endl;
    string username, password;
    cout << "Username : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

    cout<<endl<<endl<<endl;
start:
    cout << "------ OOPRA BANK --------  " << endl;
    string us1, pas1;
    cout << "Enter your Username : ";
    cin >> us1;
    if (us1 != username)
    {
        cout << "Your Username is incorrect!!!";
        Sleep(2000);
        goto start;
    }
    cout << "Enter your Password : ";
    cin >> pas1;
    if (us1 != username)
    {
        cout << "Your Password is incorrect!!!";
        Sleep(2000);
        goto start;
    }

    if (us1 == username && pas1 == password)
    {   
        cout<<endl;
        for(int i = 0; i<20;i++){
            cout<<"*";
            Sleep(5);
        }
        cout<<endl<<endl;
        string st = "Welcome to the OOPRA BANK ";
        for(int i=0;i<st.size();i++){
            cout<<st[i];
            Sleep(50);
        }
        Sleep(2000);
        
        Bank record;
        record.show();
    }
    else
    {
        goto start;
    }

    return 0;
}

void Bank ::AddnewUser()
{

    cout << "Enter the data of the Person " << total + 1 << endl;
    cout << "Enter the Name of the Person : ";
    cin >> person[total].name;
    cout << "Enter the Address of the Person : ";
    cin >> person[total].address;
    person[total].ID = UniqueIdentity();
    cout << "Enter the cash amount : ";
    cin >> person[total].cash;
    cout << "Enter the contact no. : ";
    cin >> person[total].contact;
    total++;
}

void Bank ::customerlist()
{
    cout << "The list is : " << endl;
    for (int i = 0; i < total; i++)
    {
        cout << "The person " << i + 1 << " name is " << person[i].name << endl;
        cout << "The person " << i + 1 << " id is " << person[i].ID;
        cout << endl << endl;
    }
    if(total<4){
        Sleep(5000);
    }
    else{
        Sleep(total*1000);
    }
}

void Bank ::UpdateAccount()
{
    cout << "Enter the id of the account " << endl;
    int id;
    cin >> id;
    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "Enter the data of the Person " << i +1<< endl;
            cout << "Enter the Name of the Person : ";
            cin >> person[i].name;
            cout << "Enter the Address of the Person : ";
            cin >> person[i].address;
            cout << "Enter the ID of the person : ";
            cin >> person[i].ID;
            cout << "Enter the cash amount : ";
            cin >> person[i].cash;
            cout << "Enter the contact no. :";
            cin >> person[i].contact;
            break;
        }
    }
}

void Bank ::Transactions()
{
    cout << "Press 1 for Deposit. " << endl;
    cout << "Press 2 for Withdrawl. " << endl;
    int num;
    cin >> num;
    switch (num)
    {
    case 1:
        cout << "Enter the Id of the person" << endl;
        int id1;
        cin >> id1;
        cout << "Enter the amount : ";
        int amount;
        cin >> amount;
        for (int i = 0; i < total; i++)
        {
            if (id1 == person[i].ID)
            {

                person[i].cash += amount;
                cout<<"Your total cash is "<<person[i].cash<<endl;
                Sleep(3000);
                break;
            }
        }
        break;
    case 2:
        cout << "Enter the Id of the person" << endl;
        int id2;
        cin >> id2;
        Begin:
        cout<<endl;
        cout << "Enter the amount : ";
        
        int amount2;
        cin >> amount2;
        for (int i = 0; i < total; i++)
        {   

            if (id2 == person[i].ID)
            {
                if(amount2>person[i].cash){
                    cout<<"Your account is unable to give you amount due to insufficient balance!!"<<endl;
                    cout<<"Your total cash is "<<person[i].cash<<endl;
                    for(int i =0; i<4; i++){
                        cout<<".";
                        Sleep(1000);
                    }
                    goto Begin;
                }

                person[i].cash -= amount2;
                cout<<"Your total cash is "<<person[i].cash<<endl;
                Sleep(3000);
                break;
            }
        }
        break;
    }
}

void Bank ::CheckDetails()
{
    cout << "Enter the ID of the person you want to check details : ";
    int id;
    cin >> id;
    
    for (int i = 0; i < total; i++)
    {
        if (id == person[i].ID)
        {
            cout << "The person " << i + 1 << " name is " << person[i].name<<endl;
            cout << "The person " << i + 1 << " id is " << person[i].ID<<endl;
            cout << "The person " << i + 1 << " address is " << person[i].address<<endl;
            cout << "The person " << i + 1 << " contact is " << person[i].contact<<endl;
            cout << "The person " << i + 1 << " cash is " << person[i].cash<<endl;
            cout << endl;
            break;
        }
    }
    Sleep(12000);
}

void Bank :: RemoveAccount(){
    cout<<"Enter the Id of the account : ";
    int id;
    cin>>id;
    for(int i=0; i<total; i++){
        if(id == person[i].ID){
            for(int j = i; j<total-1; j++){
                person[j].name = person[j+1].name;
                person[j].address = person[j+1].address;
                person[j].ID = person[j+1].ID;
                person[j].contact = person[j+1].contact;
                person[j].cash = person[j+1].cash;
            }
            total--;
            break;
        }
    }
}


int Bank :: UniqueIdentity(){
    uniq:
    cout<<"Enter your id ";
    int id;
    cin>>id;
    for(int i=0; i<total; i++){
        if(id == person[i].ID){
            cout << "Enter the ID of the person : ";
            Sleep(2000);
            goto uniq;
        }
    }
    return id;
}