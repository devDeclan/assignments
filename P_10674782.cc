/*___________________________________________________________________
|                       SCHOOL MANAGEMENT SYSTEM                     |
|                     -----------------------------                  |
|       >STUDENT :                                                   |
|           >Register Courses                                        |
|           >View Results                                            |
|                                                                    |
|       >STAFF :                                                     |
|           >Record Students Results                                 |
|           >Edit Students Results                                   |
|                                                                    |
|       >MANAGEMENT :                                                |
|           >Add Student                                             |
|           >Edit Student                                            |
|           >Delete Student                                          |
|           >Add Staff                                               |
|           >Edit Staff                                              |
|           >Delete Staff                                            |
|           >Add Course                                              |
|           >Edit Course                                             |
|           >Delete Course                                           |
|                                                                    |
|       >ADMIN :                                                     |
|       >Add Managers                                                |
|                   NB: Admin Password is "admin"                    |
|                    developed by @dev_declan                        |
|____________________________________________________________________|
*/

#include <iostream>
#include <string>
#include <iomanip>
void clean() {
    #if defined(_WIN32)||defined(_WIN64)
    system("cls");
    #elif defined(__linux__)
    system("clear");
    #endif
}

using namespace std;

int studentLen=0;
int staffLen=0;
int manageLen=0;
int courseLen=0;

enum level{L100,L200,L300,L400};
enum program{COMPUTER_SCIENCE, STATISTICS, MATHEMATICS, ACTURIAL_SCIENCE, IT};
enum depart {COMPUTER_SCIENCE_DEPARTMENT, STATISTICS_DEPARTMENT, MATHEMATICS_DEPARTMENT};
struct course{
    string title;
    string code;
    float score;
    int creditHours;
    depart Department;
    int lecturerID;
    string grade;
};
struct person{
    string name;
    int ID;
    int PIN;
    depart department;
};
struct student{
    string name;
    int ID;
    int PIN;
    level LEVEL;
    course courses[6];
    program programme;
    float gpa;
    int courseCounter=0;
};

student students[10000];
course totalCourses[10000];
person staff[10000];
person management[10000];

void studentMenu();
void displayResult(int index);
void staffMenu();
void managementMenu();
void addStudent();
void addStaff();
void addCourse();
void adminMenu();
void addManager();
void displayCourses();

int main(int argc, char const *argv[]) {
    for ( ; ; ){
        int selection;
        cout<<"WELCOME TO THE UNIVERSITY OF GHANA MIS WEB"<<endl<<endl;
        cout<<"1 : STUDENT"<<endl;
        cout<<"2 : STAFF"<<endl;
        cout<<"3 : MANAGEMENT"<<endl;
        cout<<"4 : EXIT"<<endl;
        cout<<"404 : ADMIN"<<endl<<endl;
        cout<<"Enter OPTION : ";
        cin>>selection;
        clean();
        if (selection==1) {
            studentMenu();
            continue;
        }
        else if (selection==2) {
            staffMenu();
            continue;
        }
        else if (selection==3) {
            managementMenu();
            continue;
        }
        else if (selection==4) {
            beg:
            int option;
            cout<<"ARE YOU SURE YOU WANT TO EXIT?"<<endl;
            cout<<"1 : YES"<<endl;
            cout<<"2 : NO"<<endl;
            cout<<"Enter OPTION : ";
            cin>>option;
            if (option==1) {
                clean();
                cout<<"GOODBYE"<<endl;
                break;
            }
            else if (option==2) {
                clean();
                continue;
            } else {
                clean();
                cout<<"Invalid Option"<<endl;
                goto beg;
            }
        }
        else if (selection==404) {
            adminMenu();
            clean();
            continue;
        }
        else {
            clean();
            cout<<"INVALID SELECTION try again"<<endl;
            continue;
        }
    }
    return 0;
}

void studentMenu() {
    int id;
    int i;
    int pin;
    bool exists=false;
    bag:
    cout<<"STUDENT"<<endl<<endl;
    if (studentLen==0) {
        clean();
        cout<<"NO STUDENTS IN DATABASE\nADD SOME"<<endl<<endl;
    }
    else{
        cout<<"Enter ID : ";
        cin>>id;
        cout<<"Enter PIN : ";
        cin>>pin;
        for (i = 0; i < studentLen ; i++) {
            if (students[i].ID==id && students[i].PIN==pin) {
                exists=true;
            }
        }
        if (exists==true) {
            bug:
            clean();
            int selection;
            cout<<"WELCOME "<<students[i].name<<endl<<endl;
            cout<<"1 : VIEW RESULT"<<endl;
            cout<<"2 : REGISTER COURSES"<<endl;
            cout<<"3 : LOGOUT"<<endl;
            clean();
            if (selection==1) {
                displayResult(i);
            }
            else if (selection==2) {
                int dumb;
                displayCourses();
                cout<<"SELECT THE COURSE YOU WANT : ";
                cin>>dumb;
                if(dumb<=courseLen){
                    students[i].courses[students[i].courseCounter]=totalCourses[dumb-1];
                    cout<<"COURSE ADDED SUCCESSFULLY"<<endl;
                    students[i].courseCounter+=1;
                }
                else{
                    cout<<"INVALID SELECTION."<<endl;
                }
            }
            else if (selection==3) {
                //do nothing
            }
            else {
                cout<<"Invalid Selection. Try again"<<endl;
                goto bug;
            }
        }
        else {
            clean();
            cout<<"ID and PIN does not match our database"<<endl;
            cout<<"Try again"<<endl;
            goto bag;
        }
    }
}
void displayResult(int index) {
    int len = 6, ct;
    float cgp=0.0, gp = 0.0;
    cout<<"This is my results"<<endl;
    cout<<"NAME : "<<students[index].name<<"\t\t\tLEVEL : "<<students[index].LEVEL<<endl<<endl;
    cout<<setw(15)<<"COURSE CODE"<<setw(20)<<"COURSE TITLE"<<setw(10)<<"SCORE"<<setw(10)<<"GRADE"<<endl;
    for (int i=0;i < len ;i++) {
        if (students[index].courses[i].score<40 ) {
            students[index].courses[i].grade="F";
            gp = 0.0;
        } else if (students[index].courses[i].score>=40 && students[index].courses[i].score<50) {
            students[index].courses[i].grade="E";
            gp = 1.0;
        } else if (students[index].courses[i].score>=50 && students[index].courses[i].score<60) {
            students[index].courses[i].grade="D";
            gp = 1.5;
        } else if (students[index].courses[i].score>=60 && students[index].courses[i].score<65) {
            students[index].courses[i].grade="C";
            gp = 2.0;
        } else if (students[index].courses[i].score>=65 && students[index].courses[i].score<70) {
            students[index].courses[i].grade="C+";
            gp = 2.5;
        } else if (students[index].courses[i].score>=70 && students[index].courses[i].score<75) {
            students[index].courses[i].grade="B";
            gp = 3.0;
        } else if (students[index].courses[i].score>=75 && students[index].courses[i].score<80) {
            students[index].courses[i].grade="B+";
            gp = 3.5;
        } else {
            students[index].courses[i].grade="A";
            gp = 4.0;
        }
        cgp += (gp*students[index].courses[i].creditHours);
        ct += students[index].courses[i].creditHours;
        cout<<setw(15)<<students[index].courses[i].code<<setw(20)<<students[index].courses[i].title<<setw(10)<<students[index].courses[i].score<<setw(10)<<students[index].courses[i].grade<<endl;
    }
    students[index].gpa=cgp/ct;
    cout<<endl<<endl<<"GPA : "<<students[index].gpa<<endl;
}
void staffMenu() {
    bool exists;
    bool isthere;
    int id;
    int i;
    int pin;
    cout<<"STAFF"<<endl<<endl;
    bag:
    if (staffLen==0) {
        clean();
        cout<<"NO STAFF FOUND IN DATABASE\nADD SOME"<<endl<<endl;
    } else {
        cout<<"Enter ID : ";
        cin>>id;
        cout<<"Enter PIN : ";
        cin>>pin;
        for (i = 0; i < staffLen; i++) {
            if (staff[i].ID==id && staff[i].PIN==pin) {
                exists=true;
                break;
            }
        }
        if (exists==true) {
            bug:
            clean();
            int selection;
            cout<<"WELCOME "<<staff[i].name<<endl<<endl;
            cout<<"1 : EDIT STUDENTS RESULTS"<<endl;
            cout<<"2 : LOGOUT"<<endl;
            if (selection==1) {
                int id1;
                bog:
                clean();
                cout<<"EDIT RESULTS"<<endl<<endl;
                cout<<"Enter Students ID : ";
                cin>>id1;
                    int selection;
                    int index;
                    for (index = 0; index < studentLen; index++) {
                        if (students[index].ID==id1) {
                            isthere=true;
                        }
                    }
                    clean();
                    if (isthere==true) {
                        int len = 6;
                        cout<<"NAME : "<<students[index].name<<"\t\t\tLEVEL : "<<students[index].LEVEL<<endl<<endl;
                        beg:
                        cout<<setw(10)<<"OPTION"<<setw(15)<<"COURSE CODE"<<setw(20)<<"COURSE TITLE"<<setw(10)<<"SCORE"<<endl;
                        for (int i=0;i < len ;i++) {
                            cout<<setw(10)<<i+1<<setw(15)<<students[index].courses[i].code<<setw(20)<<students[index].courses[i].title<<setw(10)<<students[index].courses[i].score<<endl;
                        }
                        cout<<"Enter Option You Wish To Edit(enter 0 to cancel) : ";
                        cin>>selection;
                        if (selection>=1&&selection<len) {
                            cout<<setw(15)<<students[index].courses[selection-1].code<<setw(20)<<students[index].courses[selection-1].title<<endl;
                            cout<<"Old Score : "<<students[index].courses[selection-1].score<<endl;
                            cout<<"Enter New Score : ";
                            cin>>students[index].courses[selection-1].score;
                            clean();
                            cout<<"Score recorded Successfully"<<endl;
                            goto beg;
                        }
                        else if (selection==0) {
                            clean();
                            goto bog;
                        }
                        else{
                            clean();
                            cout<<"Invalid Selection"<<endl;
                            goto beg;
                        }
                    }
                    else{
                        clean();
                        cout<<"ID NOT FOUND"<<endl;
                        goto bog;
                    }
            }
            else if (selection==2) {
                clean();
                //do nothing
            }
            else {
                clean();
                cout<<"Invalid Selection. Try again"<<endl;
                goto bug;
            }
        }
        else {
            clean();
            cout<<"ID and PIN does not match our database"<<endl;
            cout<<"Try again"<<endl;
            goto bag;
        }
    }
}
void managementMenu() {
    int ID;
    int PIN;
    int i;
    bool isAvailable=false;
    bag:
    cout<<"MANAGEMENT"<<endl<<endl;
    if (manageLen==0) {
        clean();
        cout<<"NO MANAGERS FOUND\nADD SOME"<<endl<<endl;
        //----------------------------------------------------------------------INSERT PAUSE
    } else {
        cout<<"Enter ID : ";
        cin>>ID;
        cout<<"Enter PIN : ";
        cin>>PIN;
        clean();
        for (i = 0; i <manageLen; i++) {
            if (management[i].ID==ID && management[i].PIN==PIN) {
                isAvailable=true;
                break;
            }
        }
        if (isAvailable==true) {
            bug:
            int selection;
            cout<<"WELCOME "<<management[i].name<<endl<<endl;
            cout<<"1 : MANAGE STUDENT"<<endl;
            cout<<"2 : MANAGE STAFF"<<endl;
            cout<<"3 : MANAGE COURSE"<<endl;
            cout<<"4 : LOGOUT"<<endl;
            cout<<"Enter Option : ";
            cin>>selection;
            clean();
            if (selection==1) {
                int option;
                booog:
                cout<<"MANAGE STUDENTS"<<endl<<endl;
                cout<<"1 : ADD STUDENT"<<endl;
                cout<<"2 : EDIT STUDENT"<<endl;
                cout<<"3 : DELETE STUDENT"<<endl;
                cout<<"4 : BACK"<<endl;
                cout<<"Enter OPTION : ";
                cin>>option;
                clean();
                if (option==1) {
                    addStudent();
                    clean();
                    goto booog;
                }
                else if (option==2) {
                    int ID1, ID2;
                    bog:
                    cout<<"EDIT STUDENT"<<endl<<endl;
                    cout<<"Enter Student's ID : ";
                    cin>>ID1;
                    cout<<"Repeat Student's ID : ";
                    cin>>ID2;
                    if (ID1==ID2) {
                        int selection;
                        bool mid=false;
                        int index;
                        for (index = 0; index < studentLen; index++) {
                            if (students[index].ID==ID1) {
                                mid=true;
                                break;
                            }
                        }
                        clean();
                        if (mid==true) {
                            int select;
                            string Level;
                            string Prog;
                            boog:
                            cout<<"1.NAME    : "<<students[index].name<<endl;
                            cout<<"2.ID      : "<<students[index].ID<<endl;
                            cout<<"3.PIN     : "<<students[index].PIN<<endl;
                            cout<<"4.LEVEL   : "<<students[index].LEVEL<<endl;
                            cout<<"5.PROGRAM : "<<students[index].programme<<endl;
                            cout<<"0 to Save"<<endl<<endl;
                            cout<<"Enter option : ";
                            cin>>select;
                            switch (select) {
                                case 1:
                                    cout<<"Enter New Name : ";
                                    cin>>students[index].name;
                                    goto boog;
                                case 2:
                                    cout<<"Enter New ID : ";
                                    cin>>students[index].ID;
                                    goto boog;
                                case 3:
                                    cout<<"Enter New PIN : ";
                                    cin>>students[index].PIN;
                                    goto boog;
                                case 4:
                                    dog:
                                    cout<<"Enter New LEVEL : ";
                                    cin>>Level;
                                    if (Level=="100") {
                                        students[index].LEVEL=L100;
                                    } else if (Level=="200") {
                                        students[index].LEVEL=L200;
                                    } else if (Level=="300") {
                                        students[index].LEVEL=L300;
                                    } else if (Level=="400") {
                                        students[index].LEVEL=L400;
                                    }
                                    else{
                                        cout<<"Invalid Input"<<endl;
                                        goto dog;
                                    }
                                    goto boog;
                                case 5:
                                    pig:
                                    cout<<"Enter New Programme : ";
                                    cin>>Prog;
                                    if (Prog=="CSCD") {
                                        students[index].programme=COMPUTER_SCIENCE;
                                    } else if (Prog=="STAT") {
                                        students[index].programme=STATISTICS;
                                    } else if (Prog=="MATH") {
                                        students[index].programme=MATHEMATICS;
                                    } else if (Prog=="ACTU") {
                                        students[index].programme=ACTURIAL_SCIENCE;
                                    } else if (Prog=="CSIT") {
                                        students[index].programme=IT;
                                    }
                                    else{
                                        cout<<"Invalid Input"<<endl;
                                        goto pig;
                                    }
                                    goto boog;
                                case 0:
                                    goto booog;
                                default:
                                    cout<<"Invalid Option. Try again"<<endl;
                                    goto boog;
                            }
                        } else {
                            cout<<"ID NOT FOUND. TRY AGAIN"<<endl;
                            goto bog;
                        }
                    }else{
                        clean();
                        cout<<"ID's do not match. Try again"<<endl;
                        goto bog;
                    }
                }
                else if (option==3) {
                    int ID1, ID2;
                    baag:
                    cout<<"DELETE STUDENT"<<endl<<endl;
                    cout<<"Enter Student's ID : ";
                    cin>>ID1;
                    cout<<"Repeat Student's ID : ";
                    cin>>ID2;
                    if (ID1==ID2) {
                        int selection;
                        clean();
                        for (int index = 0; index < studentLen; index++) {
                            if (students[index].ID==ID1) {
                                baaag:
                                cout<<"NAME    : "<<students[index].name<<endl;
                                cout<<"ID      : "<<students[index].ID<<endl;
                                cout<<"LEVEL   : "<<students[index].LEVEL<<endl;
                                cout<<"PROGRAM : "<<students[index].programme<<endl<<endl;
                                cout<<"Are you sure you want to delete?"<<endl;
                                cout<<"1 : YES"<<endl;
                                cout<<"2 : NO"<<endl<<endl;
                                cout<<"Enter option : ";
                                int select;
                                cin>>select;
                                clean();
                                switch (select) {
                                    case 1:
                                        for (int i = index; i < studentLen-1; i++) {
                                            students[i].name=students[i+1].name;
                                            students[i].ID=students[i+1].ID;
                                            students[i].PIN=students[i+1].PIN;
                                            students[i].LEVEL=students[i+1].LEVEL;
                                            for (int j = 0; i < 6/*sizeof(students[i].courses)/sizeof(course)*/; i++) {
                                                students[i].courses[j]=students[i+1].courses[j];
                                            }
                                            students[i].programme=students[i+1].programme;
                                        }
                                        cout<<"COURSE is DELETED"<<endl;
                                        //------------------------------------------------------------------------------------------------------------------------ADD PAUSE
                                        clean();
                                        studentLen-=1;
                                        goto booog;
                                    case 2:
                                        clean();
                                        goto booog;
                                    default:
                                        clean();
                                        cout<<"Invalid Input. Try again"<<endl;
                                        goto baaag;
                                }
                            }
                        }
                    }else{
                        clean();
                        cout<<"ID's do not match. Try again"<<endl;
                        goto baag;
                    }
                }
                else if (option==4) {
                    clean();
                    goto bug;
                }
                else {
                    clean();
                    cout<<"Invalid Selection. Try again"<<endl;
                    goto booog;
                }
            }
            else if (selection==2) {
                int option;
                boooog:
                cout<<"MANAGE STAFF"<<endl<<endl;
                cout<<"1 : ADD STAFF"<<endl;
                cout<<"2 : EDIT STAFF"<<endl;
                cout<<"3 : DELETE STAFF"<<endl;
                cout<<"4 : BACK"<<endl;
                cout<<"Enter OPTION : ";
                cin>>option;
                clean();
                if (option==1) {
                    addStaff();
                    clean();
                    goto boooog;
                }
                else if (option==2) {
                    int ID1, ID2;
                    boag:
                    cout<<"EDIT STAFF"<<endl<<endl;
                    cout<<"Enter Staff's ID : ";
                    cin>>ID1;
                    cout<<"Repeat Staff's ID : ";
                    cin>>ID2;
                    if (ID1==ID2) {
                        int selection;
                        clean();
                        for (int index = 0; index < staffLen; index++) {
                            if (staff[index].ID==ID1) {
                                int select;
                                string dep;
                                biig:
                                cout<<"1.NAME         : "<<staff[index].name<<endl;
                                cout<<"2.ID           : "<<staff[index].ID<<endl;
                                cout<<"3.PIN          : "<<staff[index].PIN<<endl;
                                cout<<"4.DEPARTMENT   : "<<staff[index].department<<endl;
                                cout<<"0 to Save"<<endl<<endl;
                                cout<<"Enter option : ";
                                cin>>select;
                                switch (select) {
                                    case 1:
                                        cout<<"Enter New NAME : ";
                                        cin>>staff[index].name;
                                        goto biig;
                                    case 2:
                                        cout<<"Enter New ID : ";
                                        cin>>staff[index].ID;
                                        goto biig;
                                    case 3:
                                        cout<<"Enter New PIN : ";
                                        cin>>staff[index].PIN;
                                        goto biig;
                                    case 4:
                                        cow:
                                        cout<<"Enter New DEPARTMENT : ";
                                        cin>>dep;
                                        if (dep=="CSCD") {
                                            staff[index].department=COMPUTER_SCIENCE_DEPARTMENT;
                                        }
                                        else if (dep=="MATH") {
                                            staff[index].department=MATHEMATICS_DEPARTMENT;
                                        }
                                        else if (dep=="STAT") {
                                            staff[index].department=STATISTICS_DEPARTMENT;
                                        }
                                        else{
                                            cout<<"Invalid Input"<<endl;
                                            goto cow;
                                        }
                                        goto biig;
                                    case 0:
                                        clean();
                                        goto boooog;
                                    default:
                                        clean();
                                        cout<<"Invalid Option. Try again"<<endl;
                                        goto biig;
                                }
                            }
                        }
                    }else{
                        clean();
                        cout<<"ID's do not match. Try again"<<endl;
                        goto boag;
                    }
                }
                else if (option==3) {
                    int ID1, ID2;
                    basag:
                    cout<<"DELETE STAFF"<<endl<<endl;
                    cout<<"Enter Staff's ID : ";
                    cin>>ID1;
                    cout<<"Repeat Staff's ID : ";
                    cin>>ID2;
                    if (ID1==ID2) {
                        int selection;
                        clean();
                        for (int index = 0; index < staffLen; index++) {
                            if (staff[index].ID==ID1) {
                                biaaag:
                                cout<<"NAME         : "<<staff[index].name<<endl;
                                cout<<"ID           : "<<staff[index].ID<<endl;
                                cout<<"DEPARTMENT   : "<<staff[index].department<<endl;
                                cout<<"Are you sure you want to delete?"<<endl;
                                cout<<"1 : YES"<<endl;
                                cout<<"2 : NO"<<endl<<endl;
                                cout<<"Enter option : ";
                                int select;
                                cin>>select;
                                switch (select) {
                                    case 1:
                                        for (int i = index; i < staffLen-1; i++) {
                                            staff[i].name=staff[i+1].name;
                                            staff[i].ID=staff[i+1].ID;
                                            staff[i].PIN=staff[i+1].PIN;
                                            staff[i].department=staff[i+1].department;
                                        }
                                        cout<<"LECTURER DELETED SUCCESSFULLY"<<endl;
                                        //--------------------------------------------------------------------------------ADD PAUSE
                                        clean();
                                        staffLen-=1;
                                        goto boooog;
                                    case 2:
                                        clean();
                                        goto boooog;
                                    default:
                                        clean();
                                        cout<<"Invalid Input. Try again"<<endl;
                                        goto biaaag;
                                }
                            }
                        }
                    }else{
                        clean();
                        cout<<"ID's do not match. Try again"<<endl;
                        goto basag;
                    }
                }
                else if (option==4) {
                    clean();
                    goto bug;
                }
                else {
                    clean();
                    cout<<"Invalid Selection. Try again"<<endl;
                    goto boooog;
                }

            }
            else if (selection==3) {
                int option;
                bioooog:
                cout<<"MANAGE COURSES"<<endl<<endl;
                cout<<"1 : ADD COURSE"<<endl;
                cout<<"2 : EDIT COURSE"<<endl;
                cout<<"3 : DELETE COURSE"<<endl;
                cout<<"4 : BACK"<<endl;
                cout<<"Enter OPTION : ";
                cin>>option;
                clean();
                if (option==1) {
                    addCourse();
                    clean();
                    goto bioooog;
                }
                else if (option==2) {
                    string CODE1, CODE2;
                    bogo:
                    cout<<"EDIT COURSE"<<endl<<endl;
                    cout<<"Enter COURSE CODE : ";
                    cin>>CODE1;
                    cout<<"Repeat COURSE CODE : ";
                    cin>>CODE2;
                    if (CODE1==CODE2) {
                        int selection;
                        clean();
                        for (int index = 0; index < courseLen; index++) {
                            if (totalCourses[index].code==CODE1) {
                                int select;
                                string deip;
                                bool exist;
                                biiig:
                                cout<<"1.CODE         : "<<totalCourses[index].code<<endl;
                                cout<<"2.TITLE        : "<<totalCourses[index].title<<endl;
                                cout<<"3.CREDIT HOURS : "<<totalCourses[index].creditHours<<endl;
                                cout<<"4.DEPARTMENT   : "<<totalCourses[index].Department<<endl;
                                cout<<"5.LECTURER ID  : "<<totalCourses[index].lecturerID<<endl;
                                cout<<"0 to Save"<<endl<<endl;
                                cout<<"Enter option : ";
                                cin>>select;
                                switch (select) {
                                    case 1:
                                        cout<<"Enter New CODE : ";
                                        cin>>totalCourses[index].code;
                                        goto biiig;
                                    case 2:
                                        cout<<"Enter New TITLE : ";
                                        cin>>totalCourses[index].title;
                                        goto biiig;
                                    case 3:
                                        cout<<"Enter Number of Credit Hours : ";
                                        cin>>totalCourses[index].creditHours;
                                        goto biiig;
                                    case 4:
                                        crow:
                                        cout<<"Enter New DEPARTMENT : ";
                                        cin>>deip;
                                        if (deip=="CSCD") {
                                            totalCourses[index].Department=COMPUTER_SCIENCE_DEPARTMENT;
                                        }
                                        else if (deip=="MATH") {
                                            totalCourses[index].Department=MATHEMATICS_DEPARTMENT;
                                        }
                                        else if (deip=="STAT") {
                                            totalCourses[index].Department=STATISTICS_DEPARTMENT;
                                        }
                                        else{
                                            cout<<"Invalid Input"<<endl;
                                            goto crow;
                                        }
                                        goto biiig;
                                    case 5:
                                        piid:
                                        cout<<"Enter New LECTURER id : ";
                                        int newID;
                                        cin>>newID;
                                        exist = false;
                                        for (int i = 0; i < staffLen; i++) {
                                            if (newID==staff[i].ID) {
                                                exist = true;
                                            }
                                        }
                                        if (exist==true) {
                                            totalCourses[index].lecturerID=newID;
                                        }
                                        else{
                                            cout<<"LECTURER DOES NOT EXIST"<<endl;
                                            goto piid;
                                        }
                                        goto biiig;
                                    case 0:
                                        clean();
                                        goto bioooog;
                                    default:
                                        clean();
                                        cout<<"Invalid Option. Try again"<<endl;
                                        goto biiig;
                                }
                            }
                        }
                    }else{
                        clean();
                        cout<<"CODE's do not match. Try again"<<endl;
                        goto bogo;
                    }
                }
                else if (option==3) {
                    string CODE1, CODE2;
                    baoag:
                    cout<<"DELETE COURSE"<<endl<<endl;
                    cout<<"Enter COURSE CODE : ";
                    cin>>CODE1;
                    cout<<"Repeat COURSE CODE : ";
                    cin>>CODE2;
                    if (CODE1==CODE2) {
                        int selection;
                        clean();
                        for (int index = 0; index < courseLen; index++) {
                            if (totalCourses[index].code==CODE1) {
                                baaago:
                                cout<<"COURSE CODE    : "<<totalCourses[index].code<<endl;
                                cout<<"COURSE TITLE   : "<<totalCourses[index].title<<endl;
                                cout<<"DEPARTMENT     : "<<totalCourses[index].Department<<endl;
                                cout<<"Are you sure you want to delete?"<<endl;
                                cout<<"1 : YES"<<endl;
                                cout<<"2 : NO"<<endl<<endl;
                                cout<<"Enter option : ";
                                int select;
                                cin>>select;
                                switch (select) {
                                    case 1:
                                        for (int i = index; i < courseLen-1; i++) {
                                            totalCourses[index].code=totalCourses[index+1].code;
                                            totalCourses[index].title=totalCourses[index+1].title;
                                            totalCourses[index].creditHours=totalCourses[index+1].creditHours;
                                            totalCourses[index].Department=totalCourses[index+1].Department;
                                            totalCourses[index].lecturerID=totalCourses[index+1].lecturerID;
                                        }
                                        cout<<"COURSE DELETED SUCCESSFULLY"<<endl;
                                        //--------------------------------------------------------------------------------------ADD PAUSE
                                        clean();
                                        courseLen-=1;
                                        goto bioooog;
                                    case 2:
                                        clean();
                                        goto bioooog;
                                    default:
                                        clean();
                                        cout<<"Invalid Input. Try again"<<endl;
                                        goto baaago;
                                }
                            }
                        }
                    }else{
                        clean();
                        cout<<"CODE's do not match. Try again"<<endl;
                        goto baoag;
                    }
                }
                else if (option==4) {
                    goto bug;
                }
                else {
                    clean();
                    cout<<"Invalid Selection. Try again"<<endl;
                    goto bioooog;
                }
            }
            else if (selection==4) {
                clean();
                //do nothing
            }
            else {
                clean();
                cout<<"Invalid Selection. Try again"<<endl;
                goto bug;
            }
            goto bug;
        }
        else {
            clean();
            cout<<"ID and PIN does not match our database"<<endl;
            cout<<"Try again"<<endl;
            goto bag;
        }
    }
}
void addStudent(){
    cout<<"STUDENTS : "<<studentLen<<endl;
    int pin, pinc;
    string Level, Prog, name;
    cout<<"NEW STUDENT"<<endl<<endl;
    cout<<"Enter Name : ";
    cin>>name;
    students[studentLen].name=name;
    dog:
    cout<<"Enter Level : ";
    cin>>Level;
    if (Level=="100") {
        students[studentLen].LEVEL=L100;
    } else if (Level=="200") {
        students[studentLen].LEVEL=L200;
    } else if (Level=="300") {
        students[studentLen].LEVEL=L300;
    } else if (Level=="400") {
        students[studentLen].LEVEL=L400;
    }
    else{
        cout<<"Invalid Input"<<endl;
        goto dog;
    }
    pig:
    cout<<"Enter Programme : ";
    cin>>Prog;
    if (Prog=="CSCD") {
        students[studentLen].programme=COMPUTER_SCIENCE;
    } else if (Prog=="STAT") {
        students[studentLen].programme=STATISTICS;
    } else if (Prog=="MATH") {
        students[studentLen].programme=MATHEMATICS;
    } else if (Prog=="ACTU") {
        students[studentLen].programme=ACTURIAL_SCIENCE;
    } else if (Prog=="CSIT") {
        students[studentLen].programme=IT;
    }
    else{
        cout<<"Invalid Input"<<endl;
        goto pig;
    }
    cout<<"Enter ID : ";
    cin>>students[studentLen].ID;
    pid:
    cout<<"Enter PIN : ";
    cin>>pin;
    cout<<"Enter PIN again : ";
    cin>>pinc;
    if (pin==pinc) {
        clean();
        students[studentLen].PIN=pinc;
        cout<<endl<<"Details collected Successfully!"<<endl;
        cout<<"NAME    : "<<students[studentLen].name<<endl;
        cout<<"ID      : "<<students[studentLen].ID<<endl;
        cout<<"PIN     : "<<students[studentLen].PIN<<endl;
        cout<<"LEVEL   : "<<students[studentLen].LEVEL<<endl;
        cout<<"PROGRAM : "<<students[studentLen].programme<<endl;
        //----------------------------------------------------------------------INSERT PAUSE
    }
    else{
        cout<<"Pins dont match. Try again"<<endl;
        goto pid;
    }
    studentLen+=1;
}
void addStaff(){
    int pin, pinc;
    string dep,name;
    cout<<"NEW STUDENT"<<endl<<endl;
    cout<<"Enter Name : ";
    cin>>name;
    staff[staffLen].name=name;
    cow:
    cout<<"Enter DEPARTMENT : ";
    cin>>dep;
    if (dep=="CSCD") {
        staff[staffLen].department=COMPUTER_SCIENCE_DEPARTMENT;
    }
    else if (dep=="MATH") {
        staff[staffLen].department=MATHEMATICS_DEPARTMENT;
    }
    else if (dep=="STAT") {
        staff[staffLen].department=STATISTICS_DEPARTMENT;
    }
    else{
        cout<<"Invalid Input"<<endl;
        goto cow;
    }
    cout<<"Enter ID : ";
    cin>>staff[staffLen].ID;
    pid:
    cout<<"Enter PIN : ";
    cin>>pin;
    cout<<"Enter PIN again : ";
    cin>>pinc;
    if (pin==pinc) {
        clean();
        staff[staffLen].PIN=pin;
        cout<<endl<<"Details collected Successfully!"<<endl;
        cout<<"NAME       : "<<staff[staffLen].name<<endl;
        cout<<"ID         : "<<staff[staffLen].ID<<endl;
        cout<<"PIN        : "<<staff[staffLen].PIN<<endl;
        cout<<"DEPARTMENT : "<<staff[staffLen].department<<endl;
        //----------------------------------------------------------------------INSERT PAUSE
    }
    else{
        cout<<"Pins dont match. Try again"<<endl;
        goto pid;
    }
    staffLen+=1;
}
void addCourse(){
    string deip;
    int id;
    cout<<"NEW COURSE"<<endl<<endl;
    cout<<"Enter Course Code : ";
    cin>>totalCourses[courseLen].code;
    cout<<"Enter Title : ";
    cin>>totalCourses[courseLen].title;
    cout<<"Enter Credit Hours : ";
    cin>>totalCourses[courseLen].creditHours;
    crow:
    cout<<"Enter Department : ";
    cin>>deip;
    if (deip=="CSCD") {
        totalCourses[courseLen].Department=COMPUTER_SCIENCE_DEPARTMENT;
    }
    else if (deip=="MATH") {
        totalCourses[courseLen].Department=MATHEMATICS_DEPARTMENT;
    }
    else if (deip=="STAT") {
        totalCourses[courseLen].Department=STATISTICS_DEPARTMENT;
    }
    else{
        cout<<"Invalid Input"<<endl;
        goto crow;
    }    piid:
    cout<<"Enter Lecturer ID : ";
    cin>>id;
    bool exist = false;
    int i;
    for (i = 0; i < staffLen; i++) {
        if (id==staff[i].ID) {
            exist = true;
            break;
        }
    }
    if (exist==true) {
        clean();
        totalCourses[courseLen].lecturerID=id;
        cout<<endl<<"Details collected Successfully!"<<endl;
        cout<<"COURSE CODE     : "<<totalCourses[courseLen].code<<endl;
        cout<<"COURSE TITLE    : "<<totalCourses[courseLen].title<<endl;
        cout<<"CREDIT HOURS    : "<<totalCourses[courseLen].creditHours<<endl;
        cout<<"DEPARTMENT      : "<<totalCourses[courseLen].Department<<endl;
        cout<<"LECTURER ID     : "<<totalCourses[courseLen].lecturerID<<endl;
        cout<<"LECTURER NAME   : "<<staff[i].name<<endl;
        //----------------------------------------------------------------------INSERT PAUSE
    }
    else{
        cout<<"LECTURER DOES NOT EXIST"<<endl;
        goto piid;
    }
    courseLen+=1;
}
void adminMenu(){
    string Password;
    stat:
    cout<<"ADMINISTRATOR"<<endl;
    cout<<"Enter Password"<<endl;
    cin>>Password;
    if (Password=="admin") {
        clean();
        cout<<"WELCOME ADMIN"<<endl;
        addManager();
    }
    else{
        clean();
        cout<<"Invalid Password. Try again"<<endl;
        goto stat;
    }
}
void addManager(){
    cout<<"MANAGERS : "<<manageLen+1<<endl;
    int pin, pinc;
    string dep;
    cout<<"NEW MANAGER"<<endl<<endl;
    cout<<"Enter Name : ";
    string name;
    cin>>name;
    management[manageLen].name=name;
    cout<<"Enter ID : ";
    cin>>management[manageLen].ID;
    pid:
    cout<<"Enter PIN : ";
    cin>>pin;
    cout<<"Enter PIN again : ";
    cin>>pinc;
    if (pin==pinc) {
        clean();
        management[manageLen].PIN=pin;
        cout<<endl<<"Details collected Successfully!"<<endl;
        cout<<"NAME       : "<<management[manageLen].name<<endl;
        cout<<"ID         : "<<management[manageLen].ID<<endl;
        cout<<"PIN        : "<<management[manageLen].PIN<<endl;
        //----------------------------------------------------------------------INSERT PAUSE
    }
    else{
        cout<<"Pins dont match. Try again"<<endl;
        goto pid;
    }
    manageLen+=1;
}
void displayCourses() {
    cout<<setw(5)<<"INDEX"<<setw(15)<<"COURSE CODE"<<setw(30)<<"COURSE TITLE"<<setw(10)<<"CREDIT HOURS"<<endl;
    for (int i=0;i < courseLen ;i++) {
        cout<<setw(5)<<i+1<<setw(15)<<totalCourses[i].code<<setw(30)<<totalCourses[i].title<<setw(10)<<totalCourses[i].creditHours<<endl;
    }
}
