#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
void header();
void clear();
int mainmenu();
bool signup(string user_name, string Password, string Role);
string signin(string user_name, string Password);
int signin_student();
int signin_admin();
void viewinformation();
void validationofdata();
void aggegratecalculator();
void aggegratecalculatordisplay();
void deleteyourdata();
void displayroomNO();
void inputdata();
void updatadata();
void help();
void feedback();
const int student = 50;
const int count = 100;
string name[count];
string password[count];
string role[count];
int inter_marks[student];
string stud_name[student];
float aggegrate[student];
int users_count = 0;
int studs_count = 0;
main()
{
    system("cls");
    header();
    string Name, Password, Role;
    int option;
    int choice;
    int choice1;
    while (option != 3)
    {

        clear();
        option = mainmenu();
        if (option == 1)
        {
            cout << "Please enter your name : " << endl;
            cin >> Name;
            cout << "Please enter your password : " << endl;
            cin >> Password;
            cout << "Enter your role(admin/student) : " << endl;
            cin >> Role;
            bool result = signup(Name, Password, Role);
            if (result)
            {
                cout << "Successfully signed up " << endl;
                clear();
            }
            else if (!result)
            {
                cout << "User already registered" << endl;
                clear();
            }
        }
        if (option == 2)
        {
            string signin_name, signin_pass;
            cout << "Please enter your name : " << endl;
            cin >> signin_name;
            cout << "Please enter your password : " << endl;
            cin >> signin_pass;
            string result = signin(signin_name, signin_pass);
            if (result == "student" || result == "admin")
            {
                cout << "Signed in successfully " << endl;

                if (result == "student")
                {

                    while (choice != 6)
                    {
                        clear();
                        choice = signin_student();
                        if (choice == 1)
                        {
                            inputdata();
                        }
                        if (choice == 2)
                        {
                            updatadata();
                        }
                        if (choice == 3)
                        {
                            help();
                        }
                        if (choice == 4)
                        {
                            feedback();
                        }
                        if (choice == 5)
                        {
                            deleteyourdata();
                        }
                        if (choice == 6)
                        {
                            break;
                        }
                    }
                }

                else if (result == "admin")
                {

                    while (choice1 != 6)
                    {
                        clear();
                        choice1 = signin_admin();
                        if (choice1 == 1)
                        {
                            viewinformation();
                        }
                        if (choice1 == 2)
                        {
                            deleteyourdata();
                        }
                        if (choice1 == 3)
                        {
                            aggegratecalculator();
                        }
                        if (choice1 == 4)
                        {
                            aggegratecalculatordisplay();
                        }
                        if (choice1 == 5)
                        {
                            displayroomNO();
                        }
                        if (choice1 == 6)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Invalid entity" << endl;
                    clear();
                }
            }
        }
        if (option == 3)
        {

            system("cls");
            header();
            break;
        }
        // if (option >= 4)
        // {
        //     cout << " invalid operand " << endl;
        //     clear();
        // }
    }
}
void header()
{
    cout << " ******************************************************************************************************************************************************************** " << endl;
    cout << " * *  *   **   ***** ******* ****** *        *      *   *   *     *   *     ******  ***** *     * *****  *     * *******  ***** *   * *****  ***** *****  *       * * " << endl;
    cout << " * *  * *    *  *       *    *      *        * *  * *  * *  * *   *  * *    *       *     * * * * *      * *   *    *      *     * *   *       *   *      * *   * * * " << endl;
    cout << " * **** *    *   *      *    ****** *        *  **  * ***** *  *  * *****   *  **** ***** *  *  * *****  *  *  *    *       *     *     *      *   *****  *   *   * * " << endl;
    cout << " * *  * *    *    *     *    *      *        *      * *   * *   * * *   *   *     * *     *     * *      *   * *    *        *    *      *     *   *      *       * * " << endl;
    cout << " * *  *   **   *****    *    ****** ******   *      * *   * *     * *   *   ******* ***** *     * *****  *     *    *     *****   *   *****    *   *****  *       * * " << endl;
    cout << " ******************************************************************************************************************************************************************** " << endl;
}
void clear()
{
    cout << "Press any key to continue....";
    getch();
    system("cls");
}
int mainmenu()
{
    int result;
    header();
    cout << "         MAIN MENU " << endl;
    cout << "*************************" << endl;
    cout << "LOGIN MANU " << endl;
    cout << "1.               SIGN UP  to create your account " << endl;
    cout << "2.               SIGN IN to login into your account " << endl;
    cout << "3.               EXIT " << endl;
    cout << "Please enter your choice : " << endl;
    cin >> result;
    return result;
}

bool signup(string user_name, string Password, string Role)
{
    bool flag = false;
    for (int i = 0; i < users_count; i++)
    {
        if (name[i] == user_name && password[i] == Password)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        return 0;
        cout << "User already exsist ";
    }
    else if (users_count < count)
    {
        name[users_count] = user_name;
        password[users_count] = Password;
        role[users_count] = Role;
        users_count++;
        return true;
    }
    else
    {
        return false;
    }
    return 0;
}

int signin_student()
{
    header();
    int choice;
    cout << "choice1.         inputdata()" << endl;
    cout << "choice2.         updatadata()" << endl;
    cout << "choice3.         help()" << endl;
    cout << "choice4.         feedback()" << endl;
    cout << "choice5.         deletethedata()" << endl;
    cout << "choice6.         Exit " << endl;
    cout << "Enter your choice for student  " << endl;
    cin >> choice;
    return choice;
}
int signin_admin()
{
    header();
    int option1;

    cout << "choice1.          viewinformation()" << endl;
    cout << "choice2.          deletethedata()" << endl;
    cout << "choice3.          calculateaggegrate()" << endl;
    cout << "choice4.          displayaggegrate()" << endl;
    cout << "choice5.          roomallotment()" << endl;
    cout << "choice6.          Exit " << endl;
    cout << "enter your option for admin :  " << endl;
    cin >> option1;
    return option1;
}
string signin(string user_name, string Password)
{
    for (int i = 0; i < users_count; i++)
    {
        if (name[i] == user_name && password[i] == Password)
        {
            return role[i];
        }
    }
    return "undefined";
}

void inputdata()
{
    int Inter_marks;
    string Stud_name;
    cout << "Enter student name ";
    cin >> Stud_name;
    cout << "Enter your inter marks ";
    cin >> Inter_marks;
    if (Inter_marks > 1100)
    {
        cout << "you have enter an invalid marks :" << endl;
        clear();
    }
    else
    {
        stud_name[studs_count] = Stud_name;
        inter_marks[studs_count] = Inter_marks;
        studs_count++;
    }
}
void updatadata()
{
    int j = -1;
    string name;
    cout << "Please enter your name " << endl;
    cin >> name;
    for (int i = 0; i < studs_count; i++)
    {
        if (stud_name[i] == name)
        {
            j = i;
        }
    }
    string new_name;
    int new_marks;
    cout << "Enter new name " << endl;
    cin >> new_name;
    cout << "Enter new Fsc marks " << endl;
    cin >> new_marks;
    stud_name[j] = new_name;
    inter_marks[j] = new_marks;
    // if (inter_marks[1] > 1100)
    // {
    //     cout << "you have enter an invalid marks :" << endl;
    //     clear();
    // }
}
void help()
{
    cout << "If you sign in successfully then please enter  inter marks in correct form .If  " << endl;
    cout << "you want to updata the data then click on the updata function by which you can updata your data .if  " << endl;
    cout << "if you want to cancel application then click on the cancellation by which you can cancel out your    " << endl;
    cout << "application .You can also give the feedback " << endl;
}
void feedback()
{
    cout << "feedbak" << endl;
}
void viewinformation()
{
    cout << "Name               Inter Marks" << endl;
    for (int i = 0; i < studs_count; i++)
    {
        cout << stud_name[i] << "               " << inter_marks[i] << endl;
    }
}
void validationofdata()
{
    if (inter_marks[1] > 1100)
    {
        inter_marks[1] = 0;
        cout << "you have enter an invalid marks :" << endl;
        // signin();
    }
    else
    {
        cout << "The student obtained " << inter_marks[1] << "marks " << endl;
    }
}
void aggegratecalculator()
{
    aggegrate[1] = (inter_marks[1] / 1100) * 100;
}
void aggegratecalculatordisplay()
{
    cout << "The student which  applay for the hostel in the university is  " << name[1] << endl;
    ;
    cout << "he got  " << inter_marks[1] << " out of 1100 in intermediate " << endl;
    cout << "he has the aggegrate " << aggegrate[1] << endl;
}

void deleteyourdata()
{
    string name1;
    int j = -1;
    cout << "Enter you name : ";
    cin >> name1;
    for (int i = 0; i < studs_count; i++)
    {
        if (stud_name[i] == name1)
        {
            j = i;
        }
    }
    if (j != -1)
    {
        stud_name[j] = stud_name[j + 20];
        inter_marks[j] = inter_marks[j + 20];
    }
    else
    {
        cout << "Student not found" << endl;
        getch();
    }
}
void displayroomNO()
{
    cout << "Room No is 56 " << endl;
}
