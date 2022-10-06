#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class shopping
{
private:
    int pcode;
    int price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
// m is a label for goto
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t-------------------------------\n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t    SUPERMARKET MAIN MENU      \n";
    cout << "\t\t\t\t                               \n";
    cout << "\t\t\t\t-------------------------------\n";

    cout << "\t\t\t\t|----------------------|\n";
    cout << "\t\t\t\t|  1) ADMINISTRATOR    |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t|  1) BUYER            |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t|  3) EXIT             |\n";
    cout << "\t\t\t\t|                      |\n";
    cout << "\t\t\t\t|----------------------|\n";

    cout << "\n\t\t\t PLEASE SELECT";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t PLEASE LOGIN \n";
         cout << "\t\t\t\t-------------\n";
        cout << "\t\t\t\t ENTER  EMail \n";
        cin >> email;
        cout << "\t\t\t\t PASSWORD     \n";
        cin >> password;

        if (email == "shubh123@gmail.com" && password == "shubh@123")
        {
            administrator();
        }
        else
        {
            cout << " INVALID EMAIL/PASSWORD";
        }
        break;
    case 2:
    {
        buyer();
    }
    break;
    case 3:
    {
        exit(0);
    }

    default:
    {
        cout << "PLEASE SELECT FROM THE GIVEN OPTIONS";
    }
    }
    //  goto is a jump statment it help to jumping to the main section
    goto m;
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\n\t\t\t ADMINISTRATOR MENU";
    cout << "\n\t\t\t|-------1) ADD THE PRODUCT-------|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|-------2) MODIFY THE PRODUCT----|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|-------3) DELETE THE PRODUCT----|";
    cout << "\n\t\t\t|                                |";
    cout << "\n\t\t\t|-------4) BACK TO MAIN MENU-----|";

    cout << "\n\n\t PLEASE ENTER YOUR CHOICE ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "INVALID CHOICE";
    }
    goto m;
}

void shopping ::buyer()
{
m:
    int choice;
    cout << "\t\t\t|-----------------|\n";
    cout << "\t\t\t|      BUYER      |\n";
    cout << "\t\t\t|-----------------|\n";
    cout << "\t\t\t|                 |\n";
    cout << "\t\t\t|  1) BUY PRODUCT |\n";
    cout << "\t\t\t|                 |\n";
    cout << "\t\t\t|  2) GO BACK     |\n";
    cout << "\t\t\t|-----------------|\n";

    cout << "\t\t\t ENTER YOUR CHOICE : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << " INVALID CHOICE \n";
    }
    goto m;
}

void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t ADD NEW PRODUCT ";
    cout << "\n\n\t PRODUCT CODE OF THE PRODUCT";
    cin >> pcode;
    cout << "\n\n\t NAME OF THE PRODUCT ";
    cin >> pname;
    cout << "\n\n\t PRICE OF THE PRODUCT ";
    cin >> price;
    cout << "\n\n\t DISCOUNT ON THE PRODUCT ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        // here we are initializing the file
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }

    cout << "\n\n\t\t RECORD  INSERTED !";
}

void shopping ::edit()
{
    fstream data, data1;
    // pkey is the key that will enter administrator if its match we have to add new code and name of the product
    int pkey;
    int token;
    int c;
    float p;
    float d;
    string n;
    cout << "\n\t\t\t MODIFY THE RECORD";
    cout << "\n\t\t\t  ENTER THE PRODUCT CODE: ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n FILE DOSEN'T EXIT! ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t PRODUCT NEW CODE :";
                cin >> c;
                cout << "\n\t\t NAME OF THE PRODUCT :";
                cin >> n;
                cout << "\n\t\t PRICE :";
                cin >> p;
                cout << "\n\t\t DISCOUNT ON THE PRODUCT :";
                cin >> d;
                // now all the updated data will be entered through data1 object
                data1 << " " << c << " " << n << " " << p << " "
                      << "\n";
                cout << "\n\t\t RECORD EDITED ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            // this is for increment purpose
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n RECORD NOT FOUND SORRY!";
        }
    }
}

void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t DELETE PRODUCT";
    cout << "\n\n\t ENTER THE PRODUCT CODE :";
    cin >> pkey;
    data.open("database,txt", ios::in);
    if (!data)
    {
        cout << "\n\t FILE DOESN'T EXIST";
    }
    else
    {
        data1.open("database.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t PRODUCT DELETE SUCESSFULLY";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n RECORD NOT FOUND";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|--------------------------------------\n";
    cout << "PRONO\t\tNAME\t\tPRICE\n";
    cout << "\n\n|--------------------------------------\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping ::receipt()
{

    fstream data;

    int arrcode[100];
    int arrquantity[100];
    string choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;

    cout << "\n\n\t\t\t RECEIPT ";
    data.open("database,txt", ios::in);
    if (!data)
    {
        cout << "\n\n EMPTY DATABASE";
    }
    else
    {
        data.close();

        list();
        cout << "\n|-------------------------------|\n";
        cout << "\n|                               |\n";
        cout << "\n|   PLEASE PLACE THE ORDER      |\n";
        cout << "\n|                               |\n";
        cout << "\n|-------------------------------|\n";

        do
        {
        m:
            cout << "\n\n ENTER THE PRODUCT CODE :";
            cin >> arrcode[c];
            cout << "\n\n ENTER THE PRODUCT QUANTITY :";
            cin >> arrquantity[c];
            for (int i = 0; i < c; i++)
            {
                if (arrcode[c] == arrcode[i])
                {
                    cout << "\n\n DUPLICATE PRODUCT CODE. PLEASE TRY AGAIN! ";
                    goto m;
                }
            }
            c++;
            cout << "\n\n DO YOU WANT TO BUY ANOTHER PRODUCT IF YES PRESS YES ELSE NO";
            cin >> choice;
        } while (choice == "yes");

        cout << "\n\n\t\t\t---------------------------RECEIPT---------------------------\n";
        cout << "\n PRODUCT NO \t PRODUCT NAME \t PRODUCT QANTITY \t PRICE \t AMOUNT WITH DISCOUNT\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrcode[i])
                {
                    amount = price * arrquantity[i];
                    discount = amount - (amount * discount / 100);
                    total = total + discount;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrquantity[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << discount;
                }
                data >> pcode >> pname >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\n------------------------------------------------------";
    cout << "\n TOTAL AMOUNT :" << total;
}

int main()
{
    shopping s;
    s.menu();
}