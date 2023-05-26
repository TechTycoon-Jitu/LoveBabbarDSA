#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sortedarray(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
               /* temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;*/
                swap(arr[j],arr[i]);
            }
        }
    }
   
}
int main()
{
    int n;
    cout<<"Enter a number :"<<endl;
    cin>>n;
    int num[100];
    for(int i = 0;i<n;i++){
        cin>>num[i];
    }
    sortedarray(num,n);
    printArray(num,n);
   /* int arr[5] = {2,3,1,6,5};
    sortedarray(arr,5);
    printArray(arr,5);*/
    

  
    return 0;
}