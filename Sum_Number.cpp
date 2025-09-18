// #include<iostream>
// using namespace std ;
//    int sumOfNumber( int arr){
//         int count = 0 ; 
//         for (int i = 0 ; i < arr.size() ; i++){
//             count = arr[i] + arr[i + 1];
//         }
//    return count;
//    }
        

// int main(){
//     int arr[] = { 1 , 2 , 3 , 4 , 5};
//     sumOfNumber(arr);
// return 0;
//  }
 #include<iostream>
using namespace std;

int sumOfNumber(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + sumOfNumber(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = sumOfNumber(arr, n);
    cout << "Sum of array: " << sum <<endl;

    return 0;
}