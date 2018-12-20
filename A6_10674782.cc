#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int item) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == item){
            return mid;
        }
        else if (arr[mid] > item){
            return binarySearch(arr, left, mid - 1, item);
        }
        else{
            return binarySearch(arr, mid + 1, right, item);
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    int temp;
    int searchItem;
    int numbers[10]={23,34,93,3,43,12,3,98,34,0};
    for (int i = 0; i < 10-1; i++) {
        for (int j = 0; j < 10-1; j++) {
            if(numbers[j]>numbers[j+1]){
                temp=numbers[j];
                numbers[j]=numbers[j+1];
                numbers[j+1]=temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    cout<<"ENTER NUMBER YOU ARE SEARCHING FOR :";
    cin>>searchItem;
    int needle = binarySearch(numbers,0,10,searchItem);
    if (needle==-1) {
        cout<<searchItem<<" is not in the list"<<endl;
    } else {
        cout<<searchItem<<" can be found at index "<<needle<<endl;
    }
    return 0;
}
