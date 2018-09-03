#include <iostream>
using namespace std;
int main(){
    float score;
    bool valid = false;
    while(!valid){
                valid = true;
                cout<<"Enter your score : ";
                cin>>score;
                if(cin.fail()||(score<0||score>100)){
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout<<"Invalid input. \n Retry"<<endl;
                        valid =false;
                }
    }
    if(score>=80){
        cout<<"You had an A"<<endl;
    }
    else if(score>=75){
        cout<<"You had a B+"<<endl;
    }
    else if(score>=70){
        cout<<"You had a B"<<endl;
    }
    else if(score>=65){
        cout<<"You had a C+"<<endl;
    }
    else if(score>=60){
        cout<<"You had a C"<<endl;
    }
    else if(score>=50){
        cout<<"You had a D"<<endl;
    }
    else if(score>=40){
        cout<<"You had an E"<<endl;
    }
    else{
        cout<<"You had an F"<<endl;
    }
    return 0;    
} 
