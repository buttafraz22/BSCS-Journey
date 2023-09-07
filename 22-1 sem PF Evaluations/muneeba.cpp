#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
int feedback_count = 0;

string signin(string userName, string Password);
bool isvalidusername(string userName_);
bool isvalidpassword(string Password_);
void signup(string userName_, string Password_, string rolee_);
void storeinfile(string userName_, string Password_, string rolee_);
string takechoice();
void viewusers();
void readdatafromfile();
void admininterface();
void customer_interface();
void header();
void showlist();
void selected_items();
void add_medicine();
void store_newmedicineinfile(string new_medicine, int price_of_medicine, int stock_of_medicine);
string previous_record(string record, int field);
void delete_medicine();
void readmedicinefromfile();
void search_medicine();
void A_feedback();
void storeBills(int finalBill);
void deleteFromCart();
void viewCart();
void calculateBill();
// void read_feedback();
void C_feedback();
// void store_feedback(string feedback_name[feedback_count], string feedback_number[feedback_count], string feedback_comment[feedback_count])

// feedback arrays://////////////////////////
string feedback_name[100];
string feedback_number[100];
string feedback_comment[100];
string finalBills[1000];
int billCount = 0;

void update_stock();
string userName_;
string Password_;
string rolee_;

void updatefilefromarray();
int count_of_products = 0;
int usercount = 0;
int count = 0;
int medCount = 0;
int selected_medicine_price[1000];
string selected_medicine_name[1000];

string record;
int field;
// signup arrays/////////////////////////////////
string username[100];
string password[100];
string role[100];
string medicine[100];
string orderedMedicine[100];
string orderedPrice[100];
int quantity[100];
int Price[100];
int stock[100];
int bill,final_bill;
// string company[7]={""}
main()
{
    header();
string choice;
string choice1;

    readdatafromfile();
    readmedicinefromfile();
    // read_feedback();

    previous_record(record, field);

    bool decision, decision1;
    string result;
    choice = takechoice();

    while (choice != "0")
    {
        if (choice == "1")
        {
            system("cls");
            header();

            cout << "enter your username :";
            cin >> userName_;

            cout << "enter your password :";
            cin >> Password_;
            decision1 = isvalidpassword(Password_);
            cout << "enter your role :";
            cin >> rolee_;
            decision = isvalidusername(userName_);
            if (decision == true && decision1 == true)
            {
                signup(userName_, Password_, rolee_);
                storeinfile(userName_, Password_, rolee_);
                cout << "user created successfully" << endl;
                cout << "press any key to see the signin option" << endl;
            }
            else
            {
                cout << "user already exists or invalid password" << endl;
                cout << "press any key to go back" << endl;
            }
        }
        else if (choice == "2")
        {
            system("cls");
            header();

            cout << "enter your username :";
            cin >> userName_;
            cout << "enter your password :";
            cin >> Password_;

            result = signin(userName_, Password_);
            if (result == "admin")
            {
                while (choice != "0")
                {
                    cin.ignore();
                    admininterface();
                    cout << "enter your choice:" << endl;
                    cin >> choice;

                    if (choice == "1")
                    {

                        showlist();
                    }
                    else if (choice == "2")
                    {

                        add_medicine();
                    }
                    else if (choice == "3")
                    {

                        delete_medicine();
                    }
                    else if (choice == "4")
                    {
                        update_stock();
                    }
                    else if (choice == "5")
                    {
                        search_medicine();
                    }
                    else if (choice == "6")
                    {
                        A_feedback();
                    }
                    else if (choice == "0")
                    {
                        takechoice();
                    }
                }
            }
            else if (result == "customer")
            {
                while (choice1 != "0")

                {
                    cin.ignore();
                    customer_interface();
                    cout << "enter your choice:" << endl;
                    cin >> choice1;

                    if (choice1 == "1")
                    {

                        C_feedback();
                    }
                    else if (choice == "2")
                    {

                        showlist();
                    }
                    else if (choice == "3")
                    {
                        selected_items();
                    }
                    else if (choice == "5")
                    {
                        viewCart();
                    }
                    else if (choice == "6")
                    {
                        deleteFromCart();
                    }
                    else if(choice=="8")
                    {
                        calculateBill();
                    }
                    else if (choice == "0")
                    {
                        break;
                    }
                }
            }
        }

        else if (choice == "3")
        {
            system("cls");
            header();

            viewusers();
        }
        else
        {
            cout << "invalid choice!" << endl;
            cout << "press any key to signup again" << endl;
        }
    }
}

void header()
{

    cout << "     __       __  ________  _______   ______   ______    ______   __               ______   ________  ______   _______   ________ " << endl;
    cout << "     / \\     /  |/        |/      \\ /      | /     \\  /     \\ /  |             /     \\ /        |/     \\ /      \\ /        |" << endl;
    cout << "     $$ \\   /$$ |$$$$$$$$/ $$$$$$$  |$$$$$$/ /$$$$$$  |/$$$$$$  |$$ |            /$$$$$$  |$$$$$$$$//$$$$$$  |$$$$$$$  |$$$$$$$$/ " << endl;
    cout << "     $$$ \\ /$$$ |$$ |__    $$ |  $$ |  $$ |  $$ |  $$/ $$ |__$$ |$$ |            $$\\__$$/    $$ |  $$ |  $$ |$$ |__$$ |$$ |__    " << endl;
    cout << "     $$$$  /$$$$ |$$    |   $$ |  $$ |  $$ |  $$ |      $$    $$ |$$ |            $$     \\    $$ |  $$ |  $$ |$$    $$< $$    |   " << endl;
    cout << "     $$ $$ $$/$$ |$$$$$/    $$ |  $$ |  $$ |  $$ |   __ $$$$$$$$ |$$ |             $$$$$$  |   $$ |  $$ |  $$ |$$$$$$$  |$$$$$/    " << endl;
    cout << "     $$ |$$$/ $$ |$$ |_____ $$ |__$$ | _$$ |_ $$ \\_/  |$$ |  $$ |$$ |_____       /  \\__$$|   $$ |  $$\\__$$ |$$ |  $$ |$$ |_____ " << endl;
    cout << "     $$ | $/  $$ |$$       |$$    $$/ / $$   |$$    $$/ $$ |  $$ |$$       |      $$    $$/    $$ |  $$    $$/ $$ |  $$ |$$       |" << endl;
    cout << "     $$/      $$/ $$$$$$$$/ $$$$$$$/  $$$$$$/  $$$$$$/  $$/   $$/ $$$$$$$$/        $$$$$$/     $$/    $$$$$$/  $$/   $$/ $$$$$$$$/ " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "                        __       __   ______   __    __   ______    ______   ________  __       __  ________  __    __  ________   " << endl;
    cout << "                       / \\     /  | /     \\ / \\  /  | /     \\  /     \\ /        |/ \\     /  |/        |/ \\  /  |/        |  " << endl;
    cout << "                       $$ \\   /$$ |/$$$$$$  |$$ \\ $$ |/$$$$$$  |/$$$$$$  |$$$$$$$$/ $$ \\   /$$ |$$$$$$$$/ $$ \\ $$ |$$$$$$$$/   " << endl;
    cout << "                       $$$ \\ /$$$ |$$ |__$$ |$$$ \\$$ |$$ |__$$ |$$ | _$$/ $$ |__    $$$ \\ /$$$ |$$ |__    $$$ \\$$ |   $$ |     " << endl;
    cout << "                       $$$$  /$$$$ |$$    $$ |$$$$  $$ |$$    $$ |$$ |/    |$$    |   $$$$  /$$$$ |$$    |   $$$$  $$ |   $$ |     " << endl;
    cout << "                       $$ $$ $$/$$ |$$$$$$$$ |$$ $$ $$ |$$$$$$$$ |$$ |$$$$ |$$$$$/    $$ $$ $$/$$ |$$$$$/    $$ $$ $$ |   $$ |     " << endl;
    cout << "                       $$ |$$$/ $$ |$$ |  $$ |$$ |$$$$ |$$ |  $$ |$$ \\__$$|$$ |_____ $$ |$$$/ $$ |$$ |_____ $$ |$$$$ |   $$ |     " << endl;
    cout << "                       $$ | $/  $$ |$$ |  $$ |$$ | $$$ |$$ |  $$ |$$    $$/ $$       |$$ | $/  $$ |$$       |$$ | $$$ |   $$ |     " << endl;
    cout << "                       $$/      $$/ $$/   $$/ $$/   $$/ $$/   $$/  $$$$$$/  $$$$$$$$/ $$/      $$/ $$$$$$$$/ $$/   $$/    $$/      " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "                                                                                                                                   " << endl;
    cout << "                                           ______   __      __  ______   ________  ________  __       __                           " << endl;
    cout << "                                          /     \\ / \\    /  |/     \\ /        |/        |/ \\     /  |                          " << endl;
    cout << "                                         /$$$$$$  |$$ \\  /$$//$$$$$$  |$$$$$$$$/ $$$$$$$$/ $$ \\   /$$ |                          " << endl;
    cout << "                                         $$\\__$$/  $$ \\/$$/ $$\\__$$/    $$ |   $$ |__    $$$ \\ /$$$ |                          " << endl;
    cout << "                                         $$     \\   $$  $$/  $$     \\    $$ |   $$    |   $$$$  /$$$$ |                          " << endl;
    cout << "                                          $$$$$$  |   $$$$/    $$$$$$  |   $$ |   $$$$$/    $$ $$ $$/$$ |                          " << endl;
    cout << "                                         / \\__$$ |    $$ |   / \\__$$ |   $$ |   $$ |_____ $$ |$$$/ $$ |                          " << endl;
    cout << "                                         $$    $$/     $$ |   $$    $$/    $$ |   $$       |$$ | $/  $$ |                          " << endl;
    cout << "                                          $$$$$$/      $$/     $$$$$$/     $$/    $$$$$$$$/ $$/      $$/                           " << endl;
}

void signup(string userName_, string Password_, string rolee_)
{
    username[usercount] = userName_;

    password[usercount] = Password_;
    role[usercount] = rolee_;
    usercount++;
}
string signin(string userName_, string Password_)
{

    for (int i = 0; i < usercount; i++)
    {
        cout << role[i] << endl;
        if (userName_ == username[i] && Password_ == password[i])
        {
            return role[i];
        }
    }

    return "undefined";
}

bool isvalidusername(string userName_)
{
    bool flag = true;
    for (int i = 0; i < usercount; i++)
    {
        if (username[i] == userName_)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
bool isvalidpassword(string Password)
{
    int flag = false;
    int length;
    length = Password.length();

    if (length == 8)
    {
        flag = true;
    }
    return flag;
}

void storeinfile(string userName_, string Password_, string rolee_)
{
    fstream file;
    file.open("users.txt", ios::app);

    file << userName_ << ","
         << Password_ << ","
         << rolee_ << endl;
    file.close();
}
string takechoice()
{
    system("cls");
    header();
    string choice;
    cout << " " << endl;
    cout << "Choose your choice :" << endl;
    cout << "1. for signup: " << endl;
    cout << "2. for signin: " << endl;
    cout << "3. view users " << endl;
    cout << "0. for exit " << endl;
    cout << "enter choice:" << endl;
    cin >> choice;

    return choice;
    // getch();
}
void viewusers()
{
    cout << "username"
         << "\t\t"
         << "passwords"
         << "\t\t"
         << "role" << endl;

    for (int i = 0; i < usercount; i++)
    {
        cout << username[i] << "\t\t\t" << password[i] << "\t\t\t" << role[i] << endl;
    }
}

void readdatafromfile()
{
    string word;
    fstream file;
    file.open("users.txt", ios::in);
    while (!file.eof())
    {
        getline(file, word);
        username[usercount] = previous_record(word, 1);
        password[usercount] = previous_record(word, 2);
        // cout<<username[usercount]<< "  " << username[usercount].length() << endl;
        role[usercount] = previous_record(word, 3);
        usercount++;
    }
    // getch();
    file.close();
}
void admininterface()
{
    system("cls");
    header();

    cout << "****admin control screen*****" << endl;
    cout << "1. Check list" << endl;
    cout << "2. Add the medicine" << endl;
    cout << "3. Delete medicine" << endl;
    cout << "4.Update stock " << endl;
    cout << "5. search  the company of medicine" << endl;
    cout << "6. Change company of medicine" << endl;
    // cout << "7. Update stock" << endl;
    cout << "8. Can search specific medicine and the price of that medicine with stock" << endl;
    cout << "9. feedback" << endl;
    cout << "10. discount" << endl;
    cout << "11 . logout" << endl;
    cout << "press any key to continue:" << endl;
    cout << "press 0 to go back" << endl;
    getch();
}
void customer_interface()
{
    system("cls");
    header();
    cout << " 1.give feedback               " << endl;
    cout << " 2.Show medicine list          " << endl;
    cout << " 4.can select medicine         " << endl;
    cout << " 5.view cart                   " << endl;
    cout << " 6.delete medicine from cart   " << endl;
    cout << " 7. Add new medicine in cart   " << endl;
    cout << " 8.pay bill                    " << endl;
    cout << " 9.discount                    " << endl;
    cout << " 10.Logout                     " << endl;
    cout << "press any key to continue " << endl;
    getch();
}
void showlist()
{
    system("cls");
    header();

    cout << "medicine name"
         << '\t' << '\t'
         << "stock"
         << '\t' << '\t'
         << "Price"
         << '\t' << '\t' << endl;

    for (int i = 0; i < count_of_products; i++)
    {

        cout << medicine[i] << "\t\t" << Price[i] << "\t\t" << stock[i] << "\t\t" << endl;
    }
    cout << "press any key to continue:";
    getch();
}

void add_medicine()
{
    int integer_price, integer_stock;

    string new_medicine;
    string price_of_medicine, stock_of_medicine;
    cout << "enter the name of the Medicin you want to add :";
    cin >> new_medicine;
    cout << "enter the price of that medicine :";
    cin >> price_of_medicine;
    cout << "enter the stock of that medicine :";
    cin >> stock_of_medicine;
    integer_price = atoi(price_of_medicine.c_str());
    integer_stock = atoi(stock_of_medicine.c_str());

    medicine[count_of_products] = new_medicine;
    Price[count_of_products] = integer_price;
    stock[count_of_products] = integer_stock;

    count_of_products++;
    store_newmedicineinfile(new_medicine, integer_price, integer_stock);
    //  updatefilefromarray();
    cout << "press any key to continue:";
    getch();
}

void store_newmedicineinfile(string new_medicine, int price_of_medicine, int stock_of_medicine)
{
    fstream file;
    file.open("add_product.txt", ios::app);
    file << new_medicine << "," << price_of_medicine << "," << stock_of_medicine << endl;
    file.close();
}
void readmedicinefromfile()
{
    string word;
    fstream file;

    file.open("add_product.txt", ios::in);
    while (!file.eof())
    {
        getline(file, word);
        if (word == "")
        {
            continue;
        }
        medicine[count_of_products] = previous_record(word, 1);
        Price[count_of_products] = atoi(previous_record(word, 2).c_str());
        stock[count_of_products] = atoi(previous_record(word, 3).c_str());
        count_of_products++;
    }
    file.close();
}
string previous_record(string record, int field)
{
    int commacount = 1;
    string item = "";
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commacount = commacount + 1;
        }
        else if (commacount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
void delete_medicine()
{
    system("cls");
    header();
    string deletedMedicine;
    cout << "enter the name of the product you want to delete :";
    cin >> deletedMedicine;
    for (int i = 0; i < count_of_products; i++)
    {

        if (deletedMedicine == medicine[i])
        {

            for (int j = i; j < count_of_products; j++)
            {
                medicine[j] = medicine[j + 1];
                Price[j] = Price[j + 1];
                stock[j] = stock[j + 1];
            }
            count_of_products--;
        }
        updatefilefromarray();
    }
    cout << "press any key to continue:";
    getch();
}

void updatefilefromarray()
{
    fstream file;
    file.open("add_product.txt", ios::out);
    for (int i = 0; i < count_of_products; i++)
    {
        file << medicine[i] << "," << Price[i] << "," << stock[i] << endl;
    }

    file.close();
}
void update_stock()
{
    system("cls");
    header();

    string medicine_name;
    cout << "enter the name of the medicine whose stock you want to update:";
    cin >> medicine_name;

    int new_stock;
    cout << "enter the new stock of selected medicine:";
    cin >> new_stock;

    int new_price;
    cout << "enter the new price of medicine:";
    cin >> new_price;

    for (int i = 0; i < count_of_products; i++)
    {
        if (medicine_name == medicine[i])
        {
            stock[i] = new_stock;
            Price[i] = new_price;

            cout << medicine_name << " " << Price[i] << " " << stock[i] << endl;
        }
    }
    updatefilefromarray();
    cout << "press any key to continue:";
    getch();
}

void search_medicine()
{
    system("cls");
    header();
    string search_Medicine;
    cout << "enter the name of the Medicin you want to search :";
    cin >> search_Medicine;
    cout << "medicine name"
         << "\t\t"
         << "stock"
         << "\t\t"
         << "Price"
         << "\t\t" << endl;
    for (int i = 0; i < count_of_products; i++)
    {
        if (search_Medicine == medicine[i])
        {
            cout << medicine[i] << "\t\t" << Price[i] << "\t\t" << stock[i] << "\t\t" << endl;
        }
    }
    updatefilefromarray();

    cout << "press any key to continue:";
    getch();
}
void A_feedback()
{
    system("cls");
    header();

    for (int i = 0; i < feedback_count; i++)
    {
        cout << i + 1 << ".";
        cout << "NAME: " << feedback_name[i] << endl;
        cout << "PHONE_NUMBER: " << feedback_number[i] << endl;
        cout << "" << endl;
        cout << "     " << feedback_comment[i] << endl;
        cout << " " << endl;
        // getch();
    }
    // void store_newmedicineinfile()
    cout << endl;

    cout << "press any key to continue :";
    getch();
}

void C_feedback()
{
    system("cls");
    header();

    while (true)
    {
        int choice;
        cout << "enter your name: ";
        cin.ignore();
        getline(cin, feedback_name[feedback_count]);
        cout << "enter your phone_number: ";
        // cin.ignor();
        getline(cin, feedback_number[feedback_count]);
        cout << "enter your comment: ";
        // cin.ignor();
        getline(cin, feedback_comment[feedback_count]);
        feedback_count++;
        cout << "respond/comment added successfully!!!!!!";
        cout << endl;
        cout << "enter 1 to give another respond and press any key to go back:";
        cin >> choice;
        if (choice == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
    // store_feedback(feedback_name[feedback_count], feedback_number[feedback_count], feedback_comment[feedback_count]);
}

// void store_feedback(string feedback_name[feedback_count], string feedback_number[feedback_count], string feedback_comment[feedback_count])
// {
//     fstream file;
//     file.open("feedback.txt", ios::out);
//     file << feedback_name[feedback_count] << endl;
//     file << feedback_number[feedback_count] << endl;
//     file << feedback_comment[feedback_count] << endl;
//     file.close();
// }
// void read_feedback()
// {
//     string word;
//     fstream file;
//     file.open("feedback.txt", ios::in);
//     while (!file.eof())
//     {
//         getline(file, word);
//         if (word == "")
//         {
//             break;
//         }
//         medicine[count_of_products] = previous_record(word, 1);
//         Price[count_of_products] = atoi(previous_record(word, 2).c_str());
//         stock[count_of_products] = atoi(previous_record(word, 3).c_str());
//         count_of_products++;
//     }
//     file.close();
// }

// void store_customermedicineinfile(string name_of_medicine, int num_of_medicine)
// {
//     fstream file;
//     file.open("customerproduct.txt", ios::app);
//     file << new_medicine << "," << price_of_medicine << "," << stock_of_medicine << endl;
//     file.close();
// }
// void readcustomermedicinefromfile()
// {
//     string word;
//     fstream file;

//     file.open("customerproduct.txt", ios::in);
//     while (!file.eof())
//     {
//         getline(file, word);
//         if (word == "")
//         {
//             continue;
//         }
//         medicine[count_of_products] = previous_record(word, 1);
//         Price[count_of_products] = atoi(previous_record(word, 2).c_str());
//         stock[count_of_products] = atoi(previous_record(word, 3).c_str());
//         count_of_products++;
//     }
//     file.close();
// }
// void updatecustomerfilefromarray()
// {
//     fstream file;
//     file.open("customerproduct.txt", ios::out);
//     for (int i = 0; i < count_of_products; i++)
//     {
//         file << medicine[i] << "," << Price[i] << "," << stock[i] << endl;
//     }

//     file.close();
// }
void selected_items()
{
    system("cls");
    header();
    int choice = 1;

    int position_of_medicine;
    while (choice != 0)
    {
        cout << "enter number of medicines you want to buy:" << endl;
        cin >> choice;
        orderedMedicine[medCount] = medicine[choice - 1];
        orderedPrice[medCount] = Price[choice - 1];
        // selected_medicine_price[count]=quantity;
        if (choice <= 5)
        {
            if (choice != 0)
            {
                cout << "enter quantity of medicine you want to buy:" << endl;
                cin >> quantity[medCount];
                medCount++;
            }
        }
        cout << "press any key to go back:";
        getch();
    }
}
void viewCart()
{
    for (int idx = 0; idx < medCount; idx++)
    {
        cout << orderedMedicine[idx] << '\t' << '\t' << orderedPrice[idx] << endl
             << 't' << '\t' << quantity[idx] << endl;
    }
    getch();
}
void totalBill()
{
    int bill;
    int finalBill;
    for (int idx = 0; idx < medCount; idx++)
    {
        bill = quantity[idx] * stoi(orderedPrice[idx]);
        finalBill = finalBill + bill;
        storeBills(finalBill);
    }
    getch();
}
void storeBills(int finalBill)
{
    fstream file;
    file.open("bill.txt", ios::app);
    file << finalBill << endl;
    file.close();
}
void loadBills()
{
    fstream file;
    string word;
    file.open("bill.txt", ios::in);
    while (!file.eof())
    {
        getline(file, word);
        if (word == "")
            break;
        finalBills[billCount] = previous_record(word, 1);
        billCount = billCount + 1;
    }
    file.close();
}
void addItemToCart()
{
    int choice;
    cout << "Enter the medicine you want to add:" << endl;
    cin >> choice;
    cout << "Enter quantity:";
    cin >> quantity[medCount];
    orderedMedicine[medCount] = medicine[choice];
    orderedPrice[medCount] = Price[choice];
}
void deleteFromCart()
{
    system("cls");
    for(int idx=0;idx<medCount;idx++)
    {
        cout<<orderedMedicine[idx]<<'\t'<<'\t'<<orderedPrice[idx]<<'\t'<<'\t'<<quantity[idx]<<endl;
    }
    int num;
    cout << "Enter the number of medicine you want to delete:";
    cin >> num;
    if (num <= medCount)
    {
        medCount=medCount-1;
        for (int idx = num-1; idx < medCount; idx++)
        {
            orderedMedicine[idx] = orderedMedicine[idx + 1];
            orderedPrice[idx] = orderedPrice[idx + 1];
            quantity[idx] = quantity[idx + 1];
        }
        cout<<"Enter any key to return to previos section";
        getch();
    }
}
void calculateBill()
{
    for (int idx = 0; idx < medCount; idx++)
    {
        bill = stoi(orderedPrice[idx]) * quantity[idx];
        final_bill = final_bill + bill;
    }
    final_bill=final_bill*20/100;
    cout<<"You are given 20% discount"<<endl;
    cout<<"Your bill is:"<<final_bill<<endl;
}