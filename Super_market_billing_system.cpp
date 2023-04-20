#include <iostream>
// its the fstream class!
#include <fstream>
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

// this way we can access function from class
void shopping ::menu()
{
// goto label
m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t______________________________\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t    Supermarket Main Menu     \n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t______________________________\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t|   1) Administrator      |   \n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t|   2) Buyer              |   \n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t|   3) Exit               |   \n";
    cout << "\t\t\t\t                              \n";
    cout << "\n\t\t\t|  Please select!         |     ";

    cin >> choice;

    switch (choice)
    {

    case 1:
        cout << "\t\t\t Please Login " << endl;
        cout << "\t\t\t Enter Email Id " << endl;
        cin >> email;
        cout << "\t\t\t Enter the password " << endl;
        cin >> password;
        if ((email == "aaryanmehta@email.com") && (password == "aaryan123"))
        {
            administrator();
        }
        else
        {
            cout << "INVALID DETAILS";
        }
        break;
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0); // successful termination of the program
    }
    default:
    {
        cout << "please select from the given options";
    }
    }


    // goto is the jump statement it will help us to switch directly to the main menu
    goto m;
}



void shopping ::administrator()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t Adminstrator Menu";
    cout << "\n\t\t\t 1) Add the product   ";
    cout << "\n\t\t\t 2) Modify the product";
    cout << "\n\t\t\t 3) Delete the product";
    cout << "\n\t\t\t 4) back to main menu ";
    cout << "Please enter your choice      ";
    cin >> choice;

    switch (choice)
    {
    case 1 :
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
        cout << "Invalid choice! ";
        break;
    }
    goto m;

}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t    Buyer          \n";
    cout<<"\t\t\t    1) buy product \n";
    cout<<"\t\t\t    2) go back     \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;

        case 2:
            menu();
            break;
        
        default:
            cout<<"invalid choice";
    }
    goto m;
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\t\n add new product";
    cout<<"\n\n\t product code of the product";
    cin>>pcode;
    cout<<"\n\n name of the product ";
    cin>>pname;
    cout<<"\n\n\t price of the product";
    cin>>price;
    cout<<"\n\n\t discount on the product";
    cin>>dis;


    // file handling operation
    // data is the name of objet(fstream)
    //open here opens the file
    //this will open the file in reading mode and ios::out will open in write mode
    //ios::app is append mode
    data.open("database.txt",ios::in);

    //i.e if "data" file doesnot exist 
    if(!data)
    {
       data.open("database.txt",ios::app|ios::out); //opening file in writing mode
       //this way we can write inside the file
       data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
       data.close(); 
    }
    else
    {
        //intialising the file
        data>>c>>n>>p>>d;
        // end of file function
        while(!data.eof())
        {
            if(c == pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }

    if (token == 1)
        goto m;
    else{
       data.open("database.txt",ios::app|ios::out); //opening file in writing mode
       //this way we can write inside the file
       data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
       data.close();  
    }

    cout<<endl<<"record inserted"<<endl;

}   


void shopping:: edit()
{
    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<endl<<"modify the record"<<endl;
    cout<<endl<<"product code"<<endl;
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<endl<<"file does not exist "<<endl;
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>> pcode >> pname >>price >>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<endl<<"product's new code: ";
                cin>>c;
                cout<<endl<<"enter the name of the product: ";
                cin>>pname;
                cout<<endl<<"price: ";
                cin>>price;
                cout<<endl<<"discount: ";
                cin>>dis; 
                data<<" "<< c <<" "<< n <<" "<<p<<" "<< d <<endl;
                cout<<endl<<"record edited"<<endl;
            }
            else{
                data1<<" "<< pcode <<" "<< pname <<" "<< price <<" "<< dis <<endl;
            }

            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        // renaming the data1 file to data and will use 2 func in cpp one is remove another is rename function

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token == 0){
            cout<<endl<<"record not found "<<endl;
        }

    }
}

void shopping::rem(){

    fstream data , data1;
    int pkey;
    int token = 0;
    cout<<endl<<"delete product"<<endl;
    cout<<endl<<"enter product code"<<endl;
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"file does not exist"<<endl;
    }

    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode == pkey){
                cout<<"product deleted success fully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database.txr","database1.txt");

        if(token == 0){
            cout<<endl<<"record not found"<<endl;
        }
    }
}

void shopping :: list(){
    fstream data , data1;
    data.open("database.txt",ios::in);
    cout<<endl<<"product number \t name \t "<<endl;
    data>>pcode>>pname>>price>>dis;

    while(!data.eof()){
        cout<<pcode<<" "<<pname<<" "<<price<<endl;
        data>>pcode>>pname>>price>>dis; 
    }

    data.close();
}

void shopping :: receipt(){
    
    fstream data;

    //  array c means array of code 
    int arrc[100];
    int arrq[100];//quantity
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<endl<<"RECEIPT"<<endl;

    data.open("database.txr",ios::in);
    if(!data){
        cout<<"empty database"<<endl;
    }
    else{
        data.close();

        list();
        cout<<"\n_______________________________";
        cout<<endl;
        cout<<"please place the order"<<endl;
        
        do
        {
            m:
            cout<<"\n\n Enter product code : ";
            cin>>arrc[c];
            cout<<"\n\n Enter the Quantity : ";
            cin>>arrq[c];
            for (int i = 0; i < c; i++)
            {
                if(arrc[c] == arrc[i]){
                    cout<<"\n duplicate product code. please try again";
                    goto m;
                }
            }
            c++;
            cout<<endl<<"do you want to buy another product"<<endl;
            cin>>choice;
        }
        while(choice == 'y');

        cout<<endl<<"receipt"<<endl;
        cout<<endl<<"product name \t product quantity \t price \t amount \t amount with discount";
        for(int i = 0 ; i<c ; i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode == arrc[i]){
                    amount = price * arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total + dis;
                    cout<<pcode<<" "<<pname<<" "<<arrq[i]<<" "<<price<<" "<<amount<<" "<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        } 
        data.close();
    } 
    cout<<"total amount : "<<total<<endl;
};

int main(){

    shopping s;
    s.menu();
}