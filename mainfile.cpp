#include<iostream>
#include<fstream>
using namespace std;

//Shopping Class is made 
class shopping{
    private:
        int productcode;
        float price;
        float discount;
        string pname;
    public:
        void menu();
        void admin();
        void buyer();
        void add();
        void rem();
        void edit();
        void list();
        void receipt();
};
//Menu fucntion is created to show Menu
 void shopping:: menu(){
    m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t_____________________________________\n";
    cout<<"\t\t\t\t                                     \n";
    cout<<"\t\t\t\t          SuperMarket Menu           \n";
    cout<<"\t\t\t\t                                     \n";
    cout<<"\t\t\t\t_____________________________________\n";
    cout<<"\t\t\t\t                                     \n";
    cout<<"\t\t\t\t|  1) Admininstrator    |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|  2) Buyer             |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|  3) Exit              |\n";
    cout<<"\t\t\t\t Plese Selcet! ";
    cin>>choice;

    switch(choice)
    {
        case 1:{
           cout<<"\t\t\t\t Please Login \n";
           cout<<"\t\t\t\t Enter your E-mail";
           cin>>email;
           cout<<"\t\t\t\t Enter the Password";
           cin>>password;

           if(email=="admin@gmail.com" && password=="password"){
               admin();
           }
           else{
            cout<<"Invalid credentials";
           }
           break;
     }

    case 2:{
        buyer();
    }

    case 3:{
        exit(0);
    }

    default:{
        cout<<"Please Select From Given Optioin";
    }
}
goto m;

}
//Admin Fuction 
void shopping:: admin(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t     Admin Menu   ";
    cout<<"\n\t\t\t\t\t  1) Add the Product ";
    cout<<"\n\t\t\t\t\t  2) Modify the Product ";
    cout<<"\n\t\t\t\t\t  3) Delete the PRoduct ";
    cout<<"\n\t\t\t\t\t  4) Back to Main Menu  ";
    
    cout<<"\n\n\t\t Please Enter the choice ";
    cin>>choice;

    switch(choice){
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
        cout<<"\t\t In valid Choice ";
    }
    goto m;
}

//Buyer Fuction Here 

void shopping :: buyer(){
    m:
    int choice;
    cout<<"\t\t\t\t Buyer  ";
    cout<<"\n\t\t\t        ";
    cout<<"\n\t\t\t 1) Buy Product ";
    cout<<"\n\t\t\t        ";
    cout<<"\n\t\t\t 2) Go Back     ";
    cout<<"\n\t\t\t        ";
    cout<<"\n\t\t\t  Enter your Choice ";
    cin>>choice;
    switch(choice){
        case 1:
           receipt();
           break;
        case 2:
           menu();
           break; 
        default:
           cout<<"Invalid Choice ";     
    }
    goto m;

}

//Add Fuction 
 void shopping:: add(){
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<" \n\t\t\t\t Add New Product  ";
    cout<<" \n\t\t\t\t PRoduct Code of the Product ";
    cin>>productcode;
    cout<<"\n\t\t\t\t Name of the product ";
    cin>>pname;
    cout<<"\n\t\t\t\t Price of the Product";
    cin>>price;
    cout<<"\n\t\t\\t Discount on the Product ";
    cin>>discount;

    data.open("database.txt");
    data.open("database.txt",ios::in);
    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<"  "<<productcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof()){
            if(c==productcode){
                token++;

            }
            data>>c>>n>>p>>d;
        }
        data.close();

    if(token==1){
        goto m;
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<"  "<<productcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
}

  cout<<"\n\t Record Inserted !";
}

// Edit fuction 
void shopping::edit(){
    fstream data,data1;
    int pkey;
    int token;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the Record  ";
    cout<<"\n\t\t\t Product Key :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\t\t\t File Doesn't Exist ";

    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>productcode>>pname>>price>>discount;
        while(!data.eof()){
            if(pkey==productcode){
                cout<<"\n\t\t\t Product New Code :";
                cin>>c;
                cout<<"\n\t\t\t Name of the Product :";
                cin>>pname;
                cout<<"\n\t\t\t Price of Product ";
                cin>>p;
                cout<<"\n\t\t\t Discount ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"Record Edited";
                token++;

            }
            else{
                data1<<" "<<productcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>productcode>>pname>>price>>discount;

        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\n Record Not Fount !";
        }
    }
}
///Remove Function 
void shopping::rem(){
    fstream data,data1;
    int pkey,token=0;
    cout<<"\n\t\t\t Delete Product ";
    cout<<"\n\t\t\t\t Enter the Product Code ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\tt\t File Doesn't Exist ";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>productcode>>pname>>price>>discount;
        while(!data.eof()){
            if(productcode==pkey){
                cout<<"\n\t\\t\t Product Deleted Successfully  ";
                token++;
            }
            else{
                data1<<" "<<productcode<<" "<<pname<< " "<<price<<" "<<discount<<"\n";
            }
            data>>productcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0){
            cout<<"\n\t\t\t Record not Found ";
        }
    }
}

//List Function to show list to customer 

void shopping ::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n |___________________________\n";
    cout<<"product No \t\t Name \t\t Price \n";
    cout<<"\n\n |___________________________\n";
    data>>productcode>>pname>>price>>discount;
    while(!data.eof()){
        cout<<productcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<discount<<"\n";
        data>>productcode>>pname>>price>>discount;

    }
    data.close();
}

//receipt Function

void shopping::receipt(){
    m:
    fstream data;
    int arcode[100];
    int arquantity[100];
    char choice;
    int count=0;
    float discount=0;
    float amount=0;
    float total=0;


    cout<<"\n\n\t\t Receipt   \n";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n\t\t Empty Database   ";

    }
    else{
        data.close();
        list();
        cout<<" \n_____________________________________\n";
        cout<<"\n                                       \n";
        cout<<"\n      Please place the order           \n";
        cout<<"\n                                       \n";
        cout<<" \n_____________________________________\n";
        do{
            cout<<"\n\n\t\t Enter Product Code";
            cin>>arcode[count];
            cout<<"\n\n\t\t Enter the Quantity ";
            cin>>arquantity[count];
            for(int i=0;i<count;i++){
                if(arcode[count]==arcode[i]){
                    cout<<"\n\t\t Dulpicate Product Code Please try again ";
                    goto m;

                }
            }
            count++;
            cout<<" \n\n\t\t Do you want to but another product? if yes the press y else no ";
            cin>>choice;
        }
        while(choice=='y');
            cout<<"\n\n\t\t ___________________RECEIPT_____________________";
            cout<<"\n Product Number \t Product Name \t Product Quantity \t Price \t Amount \t Amount with discount ";
            for(int i=0;i<count;i++){
                data.open("database.txt",ios::in);
                data>>productcode>>pname>>price>>discount;
                while(!data.eof()){
                    if(arcode[i]==productcode){
                        amount=price*arquantity[i];
                        discount=amount-(amount*discount/100);
                        total=total+discount;
                        cout<<"\n"<<productcode<<"\t"<<pname<<"\t"<<arquantity[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<discount;
                    }
                    data>>productcode>>pname>>price>>discount;
                }
            }
            data.close();


        }

        cout<<"\n\n\t\t_______________________________";
        cout<<"\n\n\t\t Total Amount :"<<total;

    }
int main(){
    shopping s;
    s.menu();

}