#include<iostream>
#include<string>
#include<stdlib.h>
#include<iomanip>

using namespace std;

int i=1;
class TATA_motars
{
    string name,fual_type;
    int seating;
    char airbags[3];
    float showroom_price,mileage,tank_capacity;
    char transmission[5];

public:

    void getdata()
    {
        cout << "Enter car name : ";
        fflush(stdin);
        getline(cin,name);

        cout << "Enter fual type : ";
        fflush(stdin);
        cin >> fual_type;

        cout << "Enter showroom price : ";
        cin >> showroom_price;

        cout << "Enter mileage price : ";
        cin >> mileage;

        cout << "Enter transmission type : ";
        fflush(stdin);
        cin >> transmission;



        cout << "Enter tank capacity : ";
        cin >> tank_capacity;

        cout << "Enter  seating : ";
        cin >> seating;

        cout << "Airbags are present or not  : ";
        cin >> airbags;
    }

    void modalname()
    {
        cout << name << endl;
    }

    void putdata()
    {

        cout << left << setw(7) << name ;
        cout << left << setw(7) << fual_type ;
        cout << left << setw(13) << showroom_price;
        cout << left << setw(14) << mileage;
        cout << left << setw(13) << transmission;
        cout << left << setw(22) << tank_capacity;
        cout << left << setw(17) << seating ;
        cout << left << setw(8) <<  airbags ;
    }

    void fualputdata(int choice)
    {
        if(choice==1 && fual_type=="petrol")
        {
            putdata();
        }
        if(choice==2 && fual_type=="diesel")
        {
            putdata();
        }
        if(choice==3 && fual_type=="cng")
        {
            putdata();
        }
        if(choice==4 && fual_type=="electric")
        {
            putdata();
        }
    }

    void ch_3_putdata(float max_range)
    {
        if(showroom_price <= max_range)
        {
            putdata();
        }
    }
}cars[100];


int main()
{
    int n,choice;
    float range;

    cout << "Enter number of cars : ";
    cin >> n;

    //Enter car data

    for (i=1;i<=n;i++)
    {
        cars[i].getdata();
    }

    system("cls");

    cout << "WELCOME TO TATA MOTORS" << endl;
    cout << "GET THE CAR DETAIL AS PER YOUR PREFERENCE" << endl;
    cout << "1 - Modal Name \n2 - Fual Type\n3 - Price Range" << endl;

    cout << "ENTER YOUR OPTION : ";
    cin >> choice ;
    cout << "--------------------------------------------" << endl;

    switch(choice)
    {
    case 1:

        // printing car modal name

        for(i=1;i<=n;i++)
        {
            cout <<"("<<i<<")" ;
            cars[i].modalname();
        }
        cout << "CHOOSE YOUR CAR TO GET DETAILS : ";
        cin >> choice;

        cout << "Model  Fual   Price(lakhs) Mileage(km/L) Transmission Tank capacity(liters) seating capacity Airbags " << endl ;

        //Printing data of choose car

        cars[choice].putdata();
        break;
    case 2:

            cout << "TATA MOTARS ARE AVAILABLE WITH FUAL OPTION " << endl;
            cout << "1 - Petrol \n2 - Diesel \n3 - CNG \n4 - Electric " << endl;
            cout << "ENTER YOUR FUAL PREFERENCE : ";
            cin >> choice;

            cout << "Model  Fual  Price(lakhs) Mileage(km/L) Transmission Tank capacity(liters) seating capacity Airbags " << endl ;

            //finding fual type car and print it

            for(i=1;i<=n;i++)
            {
                cars[i].fualputdata(choice);
            }
            break;

    case 3:
        cout << "ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS : ";
        cin >> range;

        cout << "Model  Fual  Price(lakhs) Mileage(km/L) Transmission Tank capacity(liters) seating capacity Airbags " << endl ;

        //printing according to range

        for (i=1;i<=n;i++)
        {
            cars[i].ch_3_putdata(range);
        }
        break;
    default:
        cout << "Invalid choice ";
    }

}
