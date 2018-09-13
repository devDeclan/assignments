#include <iostream>
using namespace std;
int main(){
  int first, second, gcd;
  int euclide(int firstNum, int secondNum);
  int inputValidation();
  first = inputValidation();
  second = inputValidation();
    gcd = euclide( first,second);
  cout<<"The greatest common divisor of "<<first<<" and "<<second<<" is "<<gcd<<endl;
  return 0;
}

int euclide(int firstNum, int secondNum){
  int remainder;
  if(firstNum>secondNum){
    remainder = firstNum % secondNum;
  }
  else{
    remainder =secondNum % firstNum;
  }
  if(remainder == 0){
    return secondNum;
  }
  else{
    firstNum = secondNum;
    secondNum = remainder;
    return euclide(firstNum ,secondNum);
  }
}
int inputValidation(){
  int value;
  bool valid = false;
  while(!valid){
    valid = true;
    cout<<"Enter a positive number : ";
    cin>>value;
    if(cin.fail()){
      cin.clear();
      cin.ignore(200, '\n');
      cout<<"Invalid input. \n Retry"<<endl;
      valid =false;
    }
  }
  return value;
}
