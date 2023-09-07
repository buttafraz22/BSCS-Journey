#include <iostream>
#include <conio.h>
#include <fstream>

// First we add libararies

using namespace std;

// Giving prototypes for application Decoration functions
void welcomeScreen();
void header2();
void homepage();

// To ensure if the person entering the app is a user or an admin
void person();

// Giving prototypes For the admin

string startupAdmin();          // start up menu for admin
bool signInAdmin(string userName, string password); // sign in for admin
bool isValidUsernameAdmin(string userName);     // validate admin username
void signUpArrayAdmin(string userName, string password);    // ... do this for all before main
void viewUsersAdmin();
void mainMenuAdmin();
void mainMenuAdminInput();
void booklist(int number);
void booklistWelcome();
void bookaddition(string book);
void booksAfterAddition();
void bookUpdate();
void booksAfterUpdation();
void bookDelete();
void booksAfterDeletion();

// Giving prototypes For the users

string startupUser();
bool signInUser(string userName, string password);
bool isValidUsernameUser(string userName);
void signUpArrayUser(string userName, string password);
void viewUsersUser();
void mainMenuUser();
void mainMenuUserInput();
void purchase();
void purchaseCalculate();
void reserve();

// Giving prototypes for file handling for both user and admin

void userstore(string userName, string password);
void adminstore(string userName, string password);
void userRead();
void adminRead();
void bookload();
void bookstore();
void bookReserveWrite();
void bookReserveRead();
string parsItems(string itemName, int itemRate);

// Declaring the Global Variables

int siz = 17;
string password_arrayA[17];
string username_arrayA[17];

string password_arrayU[17];
string username_arrayU[17];
int userCount = 0;
int adminCount = 0;
int reservebookcount = 0;
const int SIZE = 10;

// Declaring the Global arrays

string books[SIZE] = {"The_Alchemist", "The_Red_Pot", "Peer_e_Kaamil", "Jannat_k_pattay", "Harry_Potter_The_Series", "Forty_Rules_of_love", "", "", "", ""};
string reserveBooks[SIZE] = {"", "", "", "", "", "", "", "", "", ""};

main()
{
    userRead();
    adminRead();
    bookReserveRead();
    bookload();
    system("cls");
    welcomeScreen();
    header2();
    cout << "Press any number to continue......." << endl;
    getch();
    bool decision = 0;
    string choice1 = "0";
    string choice2 = "0";
    string username;
    string password;
    string choice = "0";

    // here 1 is to signUp , 2 is to signIn, 3 is to view , and 4 is to exit
    while (choice != "3")

    {
        person();
        cout << "Enter your choice: ";
        cin >> choice;

        // this will give an option to choose between using the application as an admin or as a user

        system("cls");
        welcomeScreen();
        header2();

        if (choice == "1")
        {
            while (choice1 != "4")

            {
                choice1 = startupAdmin();
                system("cls");
                welcomeScreen();
                header2();
                string userName, password;

                if (choice1 == "1")

                // which is for signup

                {
                    cout << "Enter your username: ";
                    cin >> userName;

                    cout << "Enter your password: ";
                    cin >> password;

                    decision = isValidUsernameAdmin(userName);

                    if (decision == true)
                    {
                        adminstore(userName, password);
                        signUpArrayAdmin(userName, password);
                        cout << "User Created Successfully" << endl;
                        adminstore(userName, password);
                    }
                    else
                    {
                        cout << "Username already exists, Try Again!" << endl;

                        // The admin cannot sign up using the name that already exists in the application
                        cout << "Press any number to continue......." << endl;
                        getch();
                    }
                }

                else if (choice1 == "2")

                // which is for login

                {
                    cout << "Enter your username: ";
                    cin >> userName;

                    cout << "Enter your password: ";
                    cin >> password;

                    decision = signInAdmin(userName, password);

                    if (decision == true)
                    {
                        cout << "Login is Successful" << endl;
                        system("cls");
                        homepage();
                        cout << "Press any number to continue......." << endl;
                        getch();
                        mainMenuAdmin();
                    }

                    else

                    {
                        cout << "Invalid Credentials, Try again!" << endl;

                        // this appears if the entered credentials are invalid
                    }
                }

                else if (choice1 == "3")
                {
                    viewUsersAdmin();
                }

                else if (choice1 == "4")
                {
                    choice1 = "0";
                    break;
                }
            }
        }

        else if (choice == "2")

        // **************************** which is for the USER **********************************
        {

            system("cls");
            welcomeScreen();

            while (choice2 != "4")
            {

                choice2 = startupUser();
                system("cls");
                welcomeScreen();
                header2();
                string userName, password;
                if (choice2 == "1") // for signup
                {
                    cout << "Enter your username: ";
                    cin >> userName;

                    cout << "Enter your password: ";
                    cin >> password;

                    decision = isValidUsernameUser(userName);

                    if (decision == true)
                    {
                        signUpArrayUser(userName, password);

                        cout << "User Created Successfully" << endl;
                        userstore(userName, password);
                    }
                    else
                    {
                        cout << "Username already exists, Try Again!" << endl;

                        // The admin cannot sign up using the name that already exists in the application
                    }
                }

                else if (choice2 == "2") // for signin
                {
                    cout << "Enter your username: ";
                    cin >> userName;

                    cout << "Enter your password: ";
                    cin >> password;

                    decision = signInUser(userName, password);

                    if (decision == true)
                    {
                        cout << "Login is Successful" << endl;
                        system("cls");
                        homepage();
                        cout << "Press any number to continue......." << endl;
                        getch();
                        mainMenuUser();
                    }

                    else

                    {
                        cout << "Invalid Credentials, Try again!" << endl;

                        // this appears if the entered credentials are invalid
                    }
                }

                else if (choice2 == "3") // to view present users
                {
                    viewUsersUser();
                }
                else if (choice2 == "4")
                {
                    choice2 = "0";
                    break;
                }
            }
        }
        else if (choice == "3")
        {
            break;
        }
    }
}

// ****************************** ADMIN FUNCTIONS**************************************

void person()
{

    cout << "Press (1) for admin: " << endl;

    // if 1 is entered as the choice, the admin will use the application.

    cout << "Press (2) for user: " << endl;

    // if 2 is entered as the choice, the user will use the application.
}
string startupAdmin()
{

    string choice1;

    cout << "Press (1) to Sign UP: " << endl;

    // When 1 is entered, it shows the menu for login.

    cout << "Press (2) to Login: " << endl;

    // When 2 is entered, it shows the menu for signup.

    cout << "Press (3) to View users: " << endl;

    // When 3 is entered, it shows the list of our present admins.

    cout << "Press (4) to go back" << endl;

    // When 0 is entered, it exits the application.

    cout << "Enter your choice: ";
    cin >> choice1;

    return choice1;
}

bool signInAdmin(string userName, string password) // The function of sign in for the admin
{

    bool result = false;

    for (int x = 0; x < userCount; x++)
    {
        if (username_arrayA[x] == userName && password_arrayA[x] == password)

        {
            result = true;
            break;
        }
    }
    return result;
}

bool isValidUsernameAdmin(string userName) // The function to check if the username is valid, i.e it doesn't already exists
{
    bool result = true;

    for (int x = 0; x < userCount; x++)
    {
        if (username_arrayA[x] == userName)

        {
            result = false;
            break;
        }
    }
    return result;
}

void signUpArrayAdmin(string userName, string password) // The function for sign up for the admin
{
    username_arrayA[userCount] = userName;
    password_arrayA[userCount] = password;

    userCount++;
}

void viewUsersAdmin() // The function to view the admins that are currently signed up in our application

{
    cout << "Username"
         << "\t"
         << "Password" << endl
         << endl;

    for (int x = 0; x < siz; x++)
    {
        cout << username_arrayA[x] << "\t\t" << password_arrayA[x] << endl;
    }
}

void mainMenuAdmin() // The function to show the main menu of the admin
{
    string choicee = "0"; // for the mainmenu
    int number;
    string book;
    while (choicee != "5")
    {
        system("cls");
        welcomeScreen();
        header2();

        mainMenuAdminInput();

        cout << "Enter your choice: " << endl;
        cin >> choicee;

        if (choicee == "1")
        {
            system("cls");
            welcomeScreen();
            header2();
            booklist(number);
            cout << "Press any number to continue......." << endl;
            getch();
        }
        else if (choicee == "2")
        {
            system("cls");
            welcomeScreen();
            header2();
            bookaddition(book);
            bookstore();
            cout << "Press any number to continue......." << endl;
            getch();
        }
        else if (choicee == "3")
        {
            system("cls");
            welcomeScreen();
            header2();
            bookUpdate();
            bookstore();
            cout << "Press any number to continue......." << endl;
            getch();
        }
        else if (choicee == "4")
        {
            system("cls");
            welcomeScreen();
            header2();
            bookDelete();
            bookstore();
            cout << "Press any number to continue......." << endl;
            getch();
        }
        else if (choicee == "5")
        {
            break;
        }
    }
}
void mainMenuAdminInput() // Function that displays the admin's menu on the console
{
    cout << "Press (1) to View list of books" << endl;
    cout << "Press (2) to Add a book" << endl;
    cout << "Press (3) to Update a book" << endl;
    cout << "Press (4) to Delete a book" << endl;
    cout << "Press (5) to Logout" << endl;
}

void booklist(int number) // Function that displays the list of books already present in the library
{
    int count = 6;
    // there are already 6 books present in the library

    booklistWelcome();

    cout << "the lists of books is " << endl;
    for (int x = 0; x < SIZE; x++)
    {
        if (books[x] != "")
        {
            cout << x + 1 << ": " << books[x] << endl;
        }
    }
}

void booklistWelcome()
{
    cout << "                       WELCOME TO THE LIBRARY!                                   " << endl;
    cout << "The following is the list of the books present in our library: " << endl;
}

void bookaddition(string book) // Function that adds the books in the library
{
    int NumOfBookAdd;
    int count = 6;

    cout << "Enter the number of books you want to add: ";
    cin >> NumOfBookAdd;

    if (count > NumOfBookAdd && (count + NumOfBookAdd) < 10)
    {
        for (int x = count; x < (count + NumOfBookAdd); x++)
        {
            cout << "ADD the name of the book you want to add" << endl;
            cin >> book;
            // book added without spaces

            books[x] = book;
            cout << "A new book " << book << "\t"
                 << "has been add to the library." << endl;
        }
    }

    else if ((count + NumOfBookAdd) > 10)

    {
        cout << "  only 10 books can be added to the library" << endl;
    }

    booksAfterAddition();
    getch();
}
void booksAfterAddition() // Function that displays the list of the books after the new book has been added to the library
{
    for (int x = 0; x < SIZE; x++)
    {
        cout << x + 1 << ":" << books[x] << endl;
    }
}

void bookUpdate() // Function that updates the books in the library according to the admin
{
    string book, newbook;

    int count = 6;

    cout << "the lists of books is " << endl;
    for (int x = 0; x < SIZE; x++)
    {
        if (books[x] != "")
        {
            cout << x + 1 << ": " << books[x] << endl;
        }
    }

    cout << "Enter the book you want to update: " << endl;
    cin >> book;

    for (int x = 0; x < SIZE; x++)
    {
        if (books[x] == book)
        {
            cout << "enter the updated name of the book" << endl;
            cin >> newbook;
            books[x] = newbook;
            cout << "the name has been updated" << endl;
            break;
        }
        else
        {
            if (x == SIZE)
            {
                cout << "The book doesn't exist in the library!";
                bookUpdate();
            }
            else
            {
                continue;
            }
        }
    }

    booksAfterUpdation();
    getch();
}

void booksAfterUpdation() // Function that displays the books after updation
{
    int count = 6;
    cout << "the lists of books is " << endl;
    for (int x = 0; x < SIZE; x++)
    {
        if (books[x] != "")
        {
            cout << x + 1 << ": " << books[x] << endl;
        }
    }
}

void bookDelete() // Function that deletes the books present in the library according to the admin
{
    string book, deletebook;

    int count = 6;

    cout << "the lists of books is " << endl;
    for (int x = 0; x < count; x++)
    {

        cout << x << ": " << books[x] << endl;
    }

    cout << "enter the name of the book you want to delete: " << endl;
    cin >> deletebook;

    for (int x = 0; x < SIZE; x++)
    {
        if (books[x] == deletebook)
        {
            books[x] = "";
            cout << "the name has been deleted" << endl;
            break;
        }
        else
        {
            if (x == SIZE)
            {
                cout << "The book doesn't exist in the library!";
                bookUpdate();
            }
            else
            {
                continue;
            }
        }
    }
    booksAfterDeletion();
    getch();
}

void booksAfterDeletion() // function that displays the books after deletion
{
    int count = 6;

    cout << "the list of books after deleting the book is" << endl;

    for (int x = 0; x < count; x++)
    {
        if (books[x] != "")
        {
            cout << x << ": " << books[x] << endl;
        }
    }
}

// ********************************* USER FUNCTIONS *****************************************

string startupUser()
{
    string choice1;

    cout << "Press (1) to Sign Up: " << endl;

    // When 1 is entered, it shows the menu for signup.

    cout << "Press (2) to Login: " << endl;

    // When 2 is entered, it shows the menu for login.

    cout << "Press (3) to View users: " << endl;

    // When 3 is entered, it shows the list of our present users.

    cout << "Press (4) to go back" << endl;

    // When 0 is entered, it exits the application.

    cout << "Enter your choice: ";
    cin >> choice1;

    return choice1;
}

bool signInUser(string userName, string password) // Function for signing in for the user
{

    bool result = false;

    for (int x = 0; x < userCount; x++)
    {
        if (username_arrayU[x] == userName && password_arrayU[x] == password)

        {
            result = true;
            break;
        }
    }
    return result;
}

bool isValidUsernameUser(string userName) // Function to check if the username entered is valid i.e it doesn't already exist
{
    bool result = true;

    for (int x = 0; x < userCount; x++)
    {
        if (username_arrayU[x] == userName)

        {
            result = false;
            break;
        }
    }
    return result;
}

void signUpArrayUser(string userName, string password) // Function to sign up for the user
{
    username_arrayU[userCount] = userName;
    password_arrayU[userCount] = password;

    userCount++;
}

void viewUsersUser() // Function to view users that are currently using the application

{
    cout << "Usernames"
         << "\t"
         << "Passwords" << endl
         << endl;

    for (int x = 0; x < siz; x++)
    {
        if (username_arrayU[x] != " " && password_arrayU[x] != " ")
        {
            cout << username_arrayU[x] << "\t\t" << password_arrayU[x] << endl;
        }
    }
}

void mainMenuUser() // Function that displays the main menu for the user
{
    string choice3 = "0"; // used in mainmenu for user
    int number;

    while (choice3 != "4")
    {
        mainMenuUserInput();
        cout << "Enter your choice: " << endl;
        cin >> choice3;

        if (choice3 == "1")
        {
            system("cls");
            welcomeScreen();
            header2();
            booklist(number);
        }
        else if (choice3 == "2")
        {
            system("cls");
            header2();
            purchase();
        }
        else if (choice3 == "3")
        {
            system("cls");
            header2();
            reserve();
        }
        else if (choice3 == "4")
        {
            break;
        }
    }
}
void mainMenuUserInput() // Function that displays the user's menu on console
{
    cout << "Press (1) if you want to see the books list" << endl;
    cout << "Press (2) if you want to Purchase a book from the library" << endl;
    cout << "Press (3) if you want to Reserve a book from the library" << endl;
    cout << "Press (4) to go back....." << endl;
}

void purchase() // Function for the user to purchase a book
{
    int number;
    string book;
    int count = 6;

    booklist(number);
    purchaseCalculate();
    cout << "Press any number to continue......." << endl;
    getch();
}
void purchaseCalculate() // Function that calculates the price
{
    string purchaseBook;
    float price, number;
    cout << "PRICE FOR EACH BOOK IS 120$." << endl;

    cout << "Enter the number of books you want to purchase: " << endl;
    cin >> number;

    for (int x = 0; x < number; x++)
    {
        cout << "enter the name of the book you want to Purchase: " << endl;
        cin >> purchaseBook;
    }

    price = number * 120;

    cout << "YOUR BOOK HAS BEEN PURCHASED FOR: " << price << "$" << endl;
}

void reserve() // Function to reserve the book
{
    string book;
    int number;

    cout << "Enter the number of books you want to reserve: " << endl;
    cin >> number;

    booklist(number);
    for (int x = 0; x < number; x++)
    {
        cout << "Enter the name of the book you want to reserve: " << endl;
        cin >> book;
        reserveBooks[reservebookcount] = book;
        reservebookcount++;
    }
    bookReserveWrite();
    cout << "Your book has been reserved!" << endl;
}

void welcomeScreen() // Function that displays the header1 on the console as needed
{

    cout << " __| |__________________________________________________________________________________| |__     " << endl;
    cout << "(__   __________________________________________________________________________________   __)    " << endl;
    cout << "   | |                                                                                  | |       " << endl;
    cout << "           __...--~~~~~-._  _.-~~~~~--...__                                                       " << endl;
    cout << "         //               `V'              \\            LIBRARY                                  " << endl;
    cout << "        //                 |                \\          MANAGEMENT                                " << endl;
    cout << "       //__...--~~~~~~-._  | _.-~~~~~~--...__\\           SYSTEM                                  " << endl;
    cout << "      //__.....----~~~~._  |  _.~~~~----....._\\                                                  " << endl;
    cout << "     ====================\\|//====================                                                " << endl;
    cout << "                         `---`                                                                    " << endl;
    cout << " __| |__________________________________________________________________________________| |__     " << endl;
    cout << "(__   __________________________________________________________________________________   __)    " << endl;
    cout << "   | |                                                                                  | |       " << endl << endl;
}

void header2() // Function that displays the header2 on the console as needed
{

    cout << " ***************************************************************************************************  " << endl;
    cout << " ***************************************************************************************************  " << endl;
    cout << " *                                                                                                 *  " << endl;
    cout << " *                                 Library Management System                                       *  " << endl;
    cout << " *                                                                                                 *  " << endl;
    cout << " ***************************************************************************************************  " << endl;
    cout << " ***************************************************************************************************  " << endl << endl << endl;
}

void homepage() // Function that displays the header3 on the console
{

    cout << "  __       __  ________  __         ______    ______   __       __  ________   " << endl;
    cout << " /  |  _  /  |/        |/  |       /      |  /      | /  |     /  |/        |  " << endl;
    cout << " $$ | | | $$ |$$$$$$$$/ $$ |      /$$$$$$  |/$$$$$$  |$$  |   /$$ |$$$$$$$$/   " << endl;
    cout << " $$ |/$  $$$ |$$ |__    $$ |      $$ |  $$/ $$ |  $$ |$$$  | /$$$ |$$ |__      " << endl;
    cout << " $$ /$$$  $$ |$$    |   $$ |      $$ |      $$ |  $$ |$$$$  /$$$$ |$$    |     " << endl;
    cout << " $$ $$/$$ $$ |$$$$$/    $$ |      $$ |   __ $$ |  $$ |$$ $$ $$/$$ |$$$$$/      " << endl;
    cout << " $$$$/  $$$$ |$$ |_____ $$ |_____ $$ |__/  |$$ |__$$ |$$ |$$$/ $$ |$$ |_____   " << endl;
    cout << " $$$/    $$$ |$$       |$$       |$$    $$/ $$    $$/ $$ | $/  $$ |$$       |  " << endl;
    cout << " $$/      $$/ $$$$$$$$/ $$$$$$$$/  $$$$$$/   $$$$$$/  $$/      $$/ $$$$$$$$/   " << endl << endl;

    cout << " ***************************************************************************************************  " << endl;
    cout << " ***************************************************************************************************  " << endl;
    cout << " *    *     *                                                                          *     *     *  " << endl;
    cout << " *       *    *   *                                                              *   *    *        *  " << endl;
    cout << " *          *   *   *                      LIBRARY                             *   *   *           *  " << endl;
    cout << " *             *  *  *                    MANAGEMENT                          *  *  *              *  " << endl;
    cout << " *                 *  *                     SYSTEM                           *  *                  *  " << endl;
    cout << " *                   **                                                      **                    *  " << endl;
    cout << " *                    *                                                      *                     *  " << endl;
    cout << " *                                                                                                 *  " << endl;
    cout << " ***************************************************************************************************  " << endl;
    cout << " ***************************************************************************************************  " << endl << endl << endl;
}

// *************************************** File handling functions for both user and admin *********************************************

void userstore(string userName, string password)
{
    fstream user;
    user.open("user1.txt", ios::app);
    user << userName << ',' << password << endl;
    user.close();
}

void adminstore(string userName, string password)
{
    fstream admin;
    admin.open("admin.txt", ios::app);
    admin << userName << ',' << password << endl;
    admin.close();
}

void userRead()
{
    string word;
    fstream user;
    user.open("user1.txt", ios::in);
    while (!user.eof())
    {
        getline(user, word);
        if (word == "")
            break;
        username_arrayU[userCount] = parsItems(word, 1);
        password_arrayU[userCount] = (parsItems(word, 2));
        userCount = userCount + 1;
    }
    user.close();
}

void adminRead()
{
    string word;
    fstream admin;
    admin.open("admin1.txt", ios::in);
    while (!admin.eof())
    {
        getline(admin, word);
        if (word == "")
            break;
        username_arrayA[adminCount] = parsItems(word, 1);
        password_arrayA[adminCount] = (parsItems(word, 2));
        adminCount = adminCount + 1;
    }
}

string parsItems(string itemName, int itemRate)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < itemName.length(); x++)
    {
        if (itemName[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == itemRate)
        {
            item = item + itemName[x];
        }
    }
    return item;
}

void bookstore()
{
    string word;
    fstream book;
    book.open("book.txt", ios::out);
    for (int x = 0; x < SIZE; x++)
    {
        book << books[x] << endl;
    }
}

void bookload()
{
    int x = 0;
    string word;
    fstream book;
    book.open("book.txt", ios::in);
    while (!book.eof())
    {
        getline(book, word);
        if (word == "")
        {
            break;
        }
        books[x] = word;
        x++;
    }
}

void bookReserveWrite()
{
    string word;
    fstream reserveBook;
    reserveBook.open("reserveBook.txt", ios::out);
    for (int x = 0; x < SIZE; x++)
    {
        reserveBook << reserveBooks[x] << endl;
    }
}

void bookReserveRead()
{
    int x = 0;
    string word;
    fstream reserveBook;
    reserveBook.open("reserveBook.txt", ios::in);
    while (!reserveBook.eof())
    {
        getline(reserveBook, word);
        if (word == "")
        {
            break;
        }
        reserveBooks[x] = word;
        x++;
    }
}