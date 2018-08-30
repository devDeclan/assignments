#include <iostream>
using namespace std;
int main(){
	int num, i;
	bool primecheck = true, valid = false;
        while(!valid){
                valid = true;
                cout<<"Enter a positive number : ";
                cin>>num;
                if(cin.fail()){
                        cin.clear();
                        cin.ignore(200, '\n');
                        cout<<"Invalid input. \n Retry"<<endl;
                        valid =false;
                }
        }
	for(i=2;i<=num/2;i++){
		switch(num%i){
		case 0:
			primecheck=false;
			break;
		default:
			continue;
		}
		
	}
	if(primecheck){
		 cout<<num<<" is a prime number"<<endl;
	}
	else{
		 cout<<num<<" is not a prime number."<<endl;
	}

	return 0;	
}
