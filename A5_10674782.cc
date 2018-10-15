#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
struct 	person{
	int id;
	string name;
	int age;
	char gender;
	float score;
};
char genGrade(float mark);
int main(){
	person student[5];
	ofstream ou;
	int male=0,female=0;
	float totAge=0, totScore=0;
	ou.open("A5_10674782.txt");
	ou<<left<<setw(10)<<"ID"<<left<<setw(30)<<"NAME"<<left<<setw(10)<<"AGE"<<left<<setw(10)<<"GENDER"<<left<<setw(10)<<"SCORE"<<left<<setw(10)<<"GRADE"<<endl;
	for(int i=0;  i<5; i++){
		cout<<"STUDENT "<<i+1<<endl;
		cout<<"Enter your ID :";
		cin>>student[i].id;
		ou<<left<<setw(10)<<student[i].id;
		cout<<"Enter your Name :";
		cin>>student[i].name;
		ou<<left<<setw(30)<<student[i].name;
		cout<<"Enter your Age :";
		cin>>student[i].age;
		ou<<left<<setw(10)<<student[i].age;
		cout<<"Enter your Gender :";
		cin>>student[i].gender;
		ou<<left<<setw(10)<<student[i].gender;
		cout<<"Enter your score :";
		cin>>student[i].score;
		ou<<left<<setw(10)<<student[i].score;
		ou<<left<<setw(10)<<genGrade(student[i].score);
		ou<<endl;
		cout<<endl<<endl;
		totScore+=student[i].score;
		totAge+=student[i].age;
		if(student[i].gender=='m'||student[i].gender=='M'){
			male+=1;
		}
		else{
			female+=1;
		}
	}
	ou<<endl<<endl<<endl;
	ou<<setw(20)<<"AVERAGE AGE: "<<totAge/5<<endl;
	ou<<setw(20)<<"AVERAGE SCORE: "<<totScore/5<<endl;
	ou<<setw(20)<<"MALE COUNT: "<<male<<endl;
	ou<<setw(20)<<"FEMALE COUNT: "<<female<<endl;
	cout<<"DONE COLLECTING DETAILS"<<endl;
return 0;
}
char genGrade(float mark){
	if(mark>=80&&mark<=100){
		return 'A';
	}
	else if(mark>=70&&mark<80){
		return 'B';
	}
	else if(mark>=60&&mark<70){
		return 'C';
	}
	else if(mark>=50&&mark<60){
		return 'D';
	}
	else if(mark>=40&&mark<50){
		return 'E';
	}
	else{
		return 'F';
	}
}
