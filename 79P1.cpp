#include<iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main()
{
    char stu_id[8];
    string stu_name,sub_name[10],grade[10][2];
    int sem,marks[10][2],grade_point[10][2],credit[10][2],total=0,total_credit=0,i,j,n;
    float SGPA;

    cout << "Enter student id :-";
    cin >> stu_id;

    cout << "Enter student name :-";
    cin >> stu_name;

    cout << "Enter semester :-";
    cin >> sem;

    cout << "Enter sem " << sem << " total subject :- ";
    cin >> n;

    //loop is for enter subject name

    for(int i=0;i<n;i++)
    {
        cout << "Enter " << i+1 << " subject name :- ";
        fflush(stdin);
        getline(cin,sub_name[i]);
    }

    //loop is for enter subject thory and practical marks

    for (int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(j==0)
            {
                cout << "Enter " << sub_name[i] << " thory mark :- ";
                cin >> marks[i][j];
                cout << "Enter " << sub_name[i] << " thory credit :- ";
                cin >> credit[i][j];
            }
            else
            {
                cout << "Enter " << sub_name[i] << " practical mark :- ";
                cin >> marks[i][j];
                cout << "Enter " << sub_name[i] << " practical credit :- ";
                cin >> credit[i][j];
            }
        }
    }

    //loop for count grade point & grade

    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            if(marks[i][j]>=80)
            {
                grade[i][j]={'A','A'};
                grade_point[i][j]=10;
            }
            else if (marks[i][j]<80 && marks[i][j]>=73)
            {
                grade[i][j]={'A','B'};
                grade_point[i][j]=9;
            }
            else if (marks[i][j]<73 && marks[i][j]>=66)
            {
                grade[i][j]={'B','B'};
                grade_point[i][j]=8;
            }
            else if (marks[i][j]<66 && marks[i][j]>=60)
            {
                grade[i][j]={'B','C'};
                grade_point[i][j]=7;
            }
            else if (marks[i][j]<60 && marks[i][j]>=55)
            {
                grade[i][j]={'C','C'};
                grade_point[i][j]=6;
            }
            else if (marks[i][j]<50 && marks[i][j]>=55)
            {
                grade[i][j]={'C','D'};
                grade_point[i][j]=5;
            }
            else if (marks[i][j]<50 && marks[i][j]>=45)
            {
                grade[i][j]={'D','D'};
                grade_point[i][j]=4;
            }
            else if (marks[i][j]<45)
            {
                grade[i][j]={'F','F'};
                grade_point[i][j]=0;
            }
        }
    }

    //calculating sgpa
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            total=total+(credit[i][j]*grade_point[i][j]);
            total_credit=credit[i][j]+total_credit;
        }
    }

    SGPA=(float)total/(float)total_credit;

    //printing data

    system("cls");
    cout << endl;
    fflush(stdin);
    fflush(stdout);
    cout << "Student ID   : "  << stu_id << endl;
    cout << "Student name : " << stu_name << endl;
    cout << "Semester     : " << sem << endl;
    cout << "\t\t\t\t  Theory  Practical" << endl;

    //loop for print grade and subject

    for (i=0;i<n;i++)
    {
        fflush(stdout);
        cout << left << setw(35) << sub_name[i] ;
        for(j=0;j<2;j++)

        {
            cout << left << setw(5) << grade[i][j] << "\t";
        }

        cout << endl;
    }

    cout << endl << fixed <<"SGPA : " << setprecision(2) << SGPA ;
}
