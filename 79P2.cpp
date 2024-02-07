#include<iostream>
#include<stdlib.h>
#include<string>
#include<iomanip>

using namespace std;


struct employee
{

private:
    int id;
    string  name,quali;
    float expe=0;
    char number[10];
public:

    int id_temp;
    void getdata()
    {
        cout << "Enter an employee id :- ";
        cin >> id;

        cout << "Enter an employee name :- ";
        fflush(stdin);
        getline(cin,name);

        cout << "Enter an employee qualification :- ";
        fflush(stdin);
        getline(cin,quali);

        cout << "Enter an employee experience  :- ";
        cin >> expe;

        cout << "Enter an employee contect number :- ";
        cin >> number;

    }
    void putdata()
    {
        cout << endl << "Employee id    : " << id;
        cout << endl << "-------------------------------" << endl;
        cout << endl << "Employee Name  : " << name << endl;
        cout << endl << "Qualification  : " << quali << endl;
        cout << endl << "Experience     : " << expe << " year" << endl;
        cout << endl << "Contact number : " << number << endl;
        cout << endl << "------------------------------" << endl ;
    }
    int findid(int id_temp,int a)
    {
        a=0;
        if(id==id_temp)
        {
            return 1;

        }
        else
        {
            return 0;
        }
    }
} employee[10000];

int main()
{
    int i=0,n,id_temp;
    int a=0;
    char ch;

    cout << "Enter number of emploee : ";
    cin >> n;

    //Enter employee data

    for(i; i<n; i++)
    {
        cout << endl << "Enter "<< i+1 <<" employee detail \n" << endl ;
        employee[i].getdata();
        flushall;
    }
    system("cls");



label:
    cout << "Enter an employee id : ";
    cin >> id_temp;

    //Find the employee according to entered id
    for(i=0; i<n; i++)
    {
        a=employee[i].findid(id_temp , a);
        if(a==1)
        {
            employee[i].putdata();
            break;
        }
    }

    if(a==0)
    {
        cout << endl << "******************************" << endl;
        cout << endl << "ERROR : ENTERED EMPLOYEE ID DOES NOT EXIST " << endl ;
        cout << endl <<"******************************" << endl;
    }
    cout << endl << "Press Y to get another employee detail , Press N to exit : ";
    fflush(stdin);
    cin >> ch;

    if(ch=='y' || ch=='Y')
    {
        goto label;
    }
}
