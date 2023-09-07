#include <iostream>
#include <conio.h>
using namespace std;
void header();
int mainMenu();
void optionsMainMenu(int);
int loginMenu();
bool chklogin(string, string);
int adminUI();
void optionsLoginMenu(int);
void optionsAdminMenu(int);
void newCarSale();
void newCarRent();
void rmvSaleCar();
void rmvRentCar();
void editSalePrice();
void editRentPrice();
void discount();
void displaySaleCars();
void displayRentCars();
int clientUI();
void optionsClientMenu(int);
void rentaCar();
void buyaCar();
void advanceBookRent();
void advanceBookBuy();
void chkBalance();
void updatebalance();
int balance = 1000000;
const int SIZE = 50;
string saleCar[SIZE] = {"HondaCivic", "HondaCity", "ToyotaLandCruiser", "ToyotaPrado", "Chery", "Audi"};
int saleCarPrice[SIZE] = {2500000, 3500000, 4800000, 3900000, 3800000, 5000000};
string rentCar[SIZE] = {"HondaCivic", "HondaCity", "ToyotaLandCruiser", "ToyotaPrado", "Chery", "Limo"};
int rentCarPrice[SIZE] = {10000, 10000, 15000, 15000, 18000, 20000};
main()
{
    system("cls");
    int choiceMainMenu;
    choiceMainMenu = mainMenu();
    optionsMainMenu(choiceMainMenu);
}
void header()
{
    system("cls");
    cout << "***************************************************************" << endl;
    cout << "*************************CHAUDHARY CARS************************" << endl;
    cout << "***************************************************************" << endl;
    cout << endl;
}
int mainMenu()
{
    int choiceMainMenu;
    header();
    cout << "MAIN MENU" << endl;
    cout << "-------------------------" << endl;
    cout << endl;
    cout << "1. Sign in the Application" << endl;
    cout << "2. Exit the Application" << endl;
    cout << endl;
    cout << "Enter your choice : ";
    cin >> choiceMainMenu;
    return choiceMainMenu;
}
void optionsMainMenu(int choiceMainMenu)
{
    int loginOption;
    if (choiceMainMenu == 1)
    {
        loginOption = loginMenu();
        optionsLoginMenu(loginOption);
    }
    else if (choiceMainMenu == 2)
    {
        cout << "Press any key to EXIT the application " << endl;
        getch();
        system("exit");
        system("cls");
    }
    else
    {
        system("cls");
        cout << "Invalid Input" << endl;
        cout << endl;
        cout << "Press any key to continue : ";
        getch();
        choiceMainMenu = mainMenu();
    }
}
int loginMenu()
{
    string username, password;
    header();
    cout << "LOGIN MENU" << endl;
    cout << "--------------------" << endl;
    cout << endl;
    cout << "Enter Username : ";
    cin >> username;
    cout << "Enter Password : ";
    cin >> password;
    return chklogin(username, password);
}
bool chklogin(string username, string password)
{
    if (username == "admin" && password == "amd")
    {
        return true;
    }
    else if (username == "client" && password == "cil")
    {
        return false;
    }
    else
    {
        header();
        cout << "User NOT Found";
        cout << endl;
        cout << "Press any key to continue : ";
        getch();
        loginMenu();
        return 0;
    }
}
int adminUI()
{
    int adminChoice;
    header();
    cout << "ADMIN MENU" << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    cout << "1. Add New Car to Sale " << endl;
    cout << "2. Add New Car to Rent " << endl;
    cout << "3. Remove car from sale " << endl;
    cout << "4. Remove car from rent " << endl;
    cout << "5. Edit Car Prices for Sale " << endl;
    cout << "6. Edit Car Prices for Rent " << endl;
    cout << "7. Add discount percentage on the total bill " << endl;
    cout << "8. Display Sale cars list " << endl;
    cout << "9. Display Rent cars list " << endl;
    cout << "0. Log Out " << endl;
    cout << endl;
    cout << "Enter your choice : ";
    cin >> adminChoice;
    return adminChoice;
}
void optionsLoginMenu(int loginOption)
{
    int adminOption, clientOption;
    if (loginOption == 1)
    {
        while (true)
        {
            adminOption = adminUI();
            optionsAdminMenu(adminOption);
        }
    }
    else if (loginOption == 0)
    {
        while (true)
        {
            clientOption = clientUI();
            optionsClientMenu(clientOption);
        }
    }
}
void optionsAdminMenu(int adminOption)
{
    if (adminOption == 1)
    {
        newCarSale();
    }
    else if (adminOption == 2)
    {
        newCarRent();
    }
    else if (adminOption == 3)
    {
        rmvSaleCar();
    }
    else if (adminOption == 4)
    {
        rmvRentCar();
    }
    else if (adminOption == 5)
    {
        editRentPrice();
    }
    else if (adminOption == 6)
    {
        editSalePrice();
    }
    else if (adminOption == 7)
    {
        discount();
    }
    else if (adminOption == 8)
    {
        displaySaleCars();
        cout << "Press any key to go back " << endl;
        getch();
    }
    else if (adminOption == 9)
    {
        displayRentCars();
        cout << "Press any key to go back " << endl;
        getch();
    }
    else if (adminOption == 0)
    {
        loginMenu();
    }
    else
    {
        header();
        cout << "Invalid Input" << endl;
        cout << endl;
        cout << "Press any key to continue : ";
        getch();
        adminOption = adminUI();
    }
}
void newCarSale()
{
    int index = 6, cars;
    header();
    cout << "Add New Car to sale " << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << "How many cars you want to enter : ";
    cin >> cars;
    for (int i = 6; i < (6 + cars); i++)
    {
        cout << "Enter new car for sale : ";
        cin >> saleCar[i];
        cout << "Enter new car sale price : ";
        cin >> saleCarPrice[i];
        index++;
    }
}
void newCarRent()
{
    int index = 6, cars;
    header();
    cout << "Add New Car to rent " << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << "How many cars you want to enter : ";
    cin >> cars;
    for (int i = 6; i < (6 + cars); i++)
    {
        cout << "Enter new car for rent : ";
        cin >> rentCar[i];
        cout << "Enter new car sale price : ";
        cin >> rentCarPrice[i];
        index++;
    }
}
void rmvSaleCar()
{
    int car = 0;
    header();
    cout << "Remove Car from Sale list " << endl;
    cout << "------------------------------------" << endl;
    displaySaleCars();
    cout << "Enter Car number : ";
    cin >> car;
    cout << "Press Any Key To Confirm Delete : ";
    getch();
    for (int j = (car - 1); j < SIZE; j++)
    {
        saleCar[j] = saleCar[j + 1];
        saleCarPrice[j] = saleCarPrice[j + 1];
    }
}
void rmvRentCar()
{
    int car;
    header();
    cout << "Remove Car from Rent list " << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    displayRentCars();
    cout << "Enter Car number : ";
    cin >> car;
    cout << "Press Any Key To Confirm Delete : ";
    getch();
    for (int j = (car - 1); j < SIZE; j++)
    {
        rentCar[j] = rentCar[j + 1];
        rentCarPrice[j] = rentCarPrice[j + 1];
    }
}
void editSalePrice()
{
    int car;
    header();
    cout << "Edit Car Sale Price " << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    displaySaleCars();
    cout << "Enter Car number : ";
    cin >> car;
    cout << "Old price : " << saleCarPrice[(car - 1)] << endl;
    cout << "Enter new Price : ";
    cin >> saleCarPrice[(car - 1)];
    cout << "Press Any Key To Confirm Change : ";
    getch();
}
void editRentPrice()
{
    int car;
    header();
    cout << "Edit Car Rent Price " << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    displayRentCars();
    cout << "Enter Car number : ";
    cin >> car;
    cout << "Old price : " << rentCarPrice[(car - 1)] << endl;
    cout << "Enter new Price : ";
    cin >> rentCarPrice[(car - 1)];
    cout << "Press Any Key To Confirm Change : ";
    getch();
}
void discount()
{
    header();
    cout << "Adding Discount Percentage " << endl;
    cout << "-------------------------------------------" << endl;
    cout << endl;
    int discount;
    cout << "Add discount percentage on total bill : ";
    cin >> discount;
}
void displaySaleCars()
{
    int i = 0;
    header();
    cout << "Cars on sale " << endl;
    cout << endl;
    while (saleCarPrice[i] != 0)
    {
        cout << i + 1 << "." << saleCar[i] << "  ( " << saleCarPrice[i] << " )" << endl;
        i++;
    }
    cout << endl;
}
void displayRentCars()
{
    int i = 0;
    header();
    while (rentCarPrice[i] != 0)
    {
        cout << i + 1 << "." << rentCar[i] << "  ( " << rentCarPrice[i] << " )" << endl;
        i++;
    }
    cout << endl;
}
int clientUI()
{
    int ClientChoice;
    header();
    cout << "CLIENT MENU" << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "1. Rent a car " << endl;
    cout << "2. Buy a car " << endl;
    cout << "3. Advance book a car for rent " << endl;
    cout << "4. Advance book a car for buying " << endl;
    cout << "5. Check Your Balance " << endl;
    cout << "6. Update Your Balance " << endl;
    cout << "0. LOG OUT" << endl;
    cout << endl;
    cout << "Enter your choice : ";
    cin >> ClientChoice;
    return ClientChoice;
}
void optionsClientMenu(int clientOption)
{
    if (clientOption == 1)
    {
        rentaCar();
    }
    else if (clientOption == 2)
    {
        buyaCar();
    }
    else if (clientOption == 3)
    {
        advanceBookRent();
    }
    else if (clientOption == 4)
    {
        advanceBookBuy();
    }
    else if (clientOption == 5)
    {
        chkBalance();
    }
    else if (clientOption == 6)
    {
        updatebalance();
    }
    else if (clientOption == 0)
    {
        loginMenu();
    }
    else
    {
        header();
        cout << "Invalid Input" << endl;
        cout << endl;
        cout << "Press any key to continue : ";
        getch();
        clientOption = clientUI();
    }
}
void rentaCar()
{
    int rent, bill;
    string car;
    displayRentCars();
    cout << "Rent A Car" << endl;
    cout << endl;
    cout << "Your Account Balance is : " << balance << endl;
    cout << endl;
    cout << "Enter your choice : ";
    cin >> rent;
    car = rentCar[rent];
    bill = rentCarPrice[rent];
    header();
    if (bill <= balance)
    {
        cout << "Congratulations you rented a car " << endl;
        cout << "Car name : " << car << endl;
        cout << "Total bill is : " << bill << endl;
        cout << endl;
        cout << "Your remaining balance : " << (balance - bill) << endl;
        cout << endl;
    }
    else
    {
        cout << "Sorry You DONT have enough balance " << endl;
        cout << endl;
        cout << "Your Account Balance is : " << balance << endl;
        cout << endl;
        cout << "Car Rent Price is : " << bill << endl;
        cout << endl;
        cout << "You Need " << (bill - balance) << " more " << endl;
    }
    cout << "Press any key to go back : ";
    getch();
}
void buyaCar()
{
    int buy, bill;
    string car;
    displaySaleCars();
    cout << "Buy A Car" << endl;
    cout << endl;
    cout << "Your Account Balance is : " << balance << endl;
    cout << endl;
    cout << "Enter your choice : ";
    cin >> buy;
    car = saleCar[buy];
    bill = saleCarPrice[buy];
    header();
    if (bill <= balance)
    {
        cout << "Congratulations you bought a car " << endl;
        cout << "Car name : " << car << endl;
        cout << "Total bill is : " << bill << endl;
        cout << endl;
        cout << "Your remaining balance : " << (balance - bill) << endl;
        cout << endl;
    }
    else
    {
        cout << "Sorry You DONT have enough balance " << endl;
        cout << endl;
        cout << "Your Account Balance is : " << balance << endl;
        cout << endl;
        cout << "Car Price is : " << bill << endl;
        cout << endl;
        cout << "You Need " << (bill - balance) << " more " << endl;
    }
    cout << "Press any key to go back : ";
    getch();
}
void advanceBookRent()
{
    int fee = 5000, bookRent, bill;
    string car;
    displayRentCars();
    cout << "Advance book  A Car for Rent" << endl;
    cout << endl;
    cout << "Your Account Balance is : " << balance << endl;
    cout << endl;
    cout << "Booking fee : Rs. " << fee;
    cout << endl;
    cout << "Enter your choice : ";
    cin >> bookRent;
    car = rentCar[bookRent];
    bill = rentCarPrice[bookRent];
    bill = bill + fee;
    header();
    if (bill <= balance)
    {
        cout << "Congratulations You Advance booked a car to rent " << endl;
        cout << "Car name : " << car << endl;
        cout << "Total bill is : " << bill << endl;
        cout << endl;
        cout << "Your remaining balance : " << (balance - bill) << endl;
        cout << endl;
    }
    else
    {
        cout << "Sorry You DONT have enough balance " << endl;
        cout << endl;
        cout << "Your Account Balance is : " << balance << endl;
        cout << endl;
        cout << "Car Rent Price + Booking Fee is : " << bill << endl;
        cout << endl;
        cout << "You Need " << (bill - balance) << " more " << endl;
    }
    cout << "Press any key to go back : ";
    getch();
}
void advanceBookBuy()
{
    int fee = 50000, bookBuy, bill;
    string car;
    displaySaleCars();
    cout << "Advance book  A Car to Buy" << endl;
    cout << endl;
    cout << "Your Account Balance is : " << balance << endl;
    cout << endl;
    cout << "Booking fee : Rs. " << fee;
    cout << endl;
    cout << "Enter your choice : ";
    cin >> bookBuy;
    car = saleCar[bookBuy];
    bill = saleCarPrice[bookBuy];
    bill = bill + fee;
    header();
    if (bill <= balance)
    {
        cout << "Congratulations You Advance booked a car to buy " << endl;
        cout << "Car name : " << car << endl;
        cout << "Total bill is : " << bill << endl;
        cout << endl;
        cout << "Your remaining balance : " << (balance - bill) << endl;
        cout << endl;
    }
    else
    {
        cout << "Sorry You DONT have enough balance " << endl;
        cout << endl;
        cout << "Your Account Balance is : " << balance << endl;
        cout << endl;
        cout << "Car Price + Booking Fee is : " << bill << endl;
        cout << endl;
        cout << "You Need " << (bill - balance) << " more " << endl;
    }
    cout << "Press any key to go back : ";
    getch();
}
void chkBalance()
{
    header();
    cout << "Your balance is : " << balance;
    cout << endl;
    cout << "Press any key to go back : ";
    getch();
}
void updatebalance()
{
    int updatebalance;
    header();
    cout << "Your balance is : " << balance;
    cout << endl;
    cout << "How much rechage you want to add : ";
    cin >> updatebalance;
    balance = balance + updatebalance;
    cout << "Press any key to go back : ";
    getch();
}
