#include <iostream>
using namespace std;

/*
 * 
 */
void bubbleSort(int* s, int size){
    for(int i = 0; i<size-1;i++ ){
        for(int j = 0; j<size-1-i;j++){
            if(s[j]>s[j+1]){
                int temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}
int main() {
    cout<<"Enter the size of the array:"<<endl;
    int size;
    cin>>size;
    int* arr = new int[size];
    int* mode = new int[size/2];
    cout<<"Enter the content of the array:"<<endl;
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    //Sort the array first to find the mode easier.
    bubbleSort(arr, size);
    /* cur is used to store the current element
     * number is used to count the apperances of an element, 
     * count is used to record how many modes.
     * The initial condition means the first element appears once.
     */
    int cur = arr[0], number = 1, count = 0, max = 0;
    for(int i = 1; i<size; i++){
        if(cur == arr[i]){
            number++;
        }else{
            if(number>1 && number>max ){
                max = number;
                count = 1;
                mode[count-1] = cur;
            }else if(number == max){
                mode[count++] = cur;
            }
            number = 1;
            cur = arr[i];
        }
    }
    if(count == 0){
        cout<<"The array does not have a mode."<<endl;
    }else if(count == 1){
        cout<<"The mode of the array is "<<mode[0]<<endl;
    }else{
        cout<<"The modes of the array are:"<<endl;
        for(int i = 0 ; i< count; i++)
            cout<<mode[i]<<endl;
    }
    delete[] arr;
    delete[] mode;
    return 0;
}

