#include <iostream>

using namespace std;

int calc(int length, int value, int arr[]){
	int sum = 0;
	int max = 0;
	for(int i = 0; i < length; i++){
		sum = sum + arr[i];
	}
	for(int i = 0; i < length; i++){
		for(int j = i; j < length; j++){
			for(int k = j; k < length; k++){
				if (i == j || i == k || j == k){
				}
				else{
					sum = arr[i] + arr[j] + arr[k];
					if (sum <= value){
						if (sum >= max){
							max = sum;
						}
					}
				}
			}
		}
	}
	cout << max << endl;
	return max;
}

int main(int argc, char* argv[]) {
	int length;
	cin >> length;
	int* arr = new int[length];

	int value;
	cin >> value;
	for(int i = 0; i < length; i++){
		cin >> arr[i];
	}
	calc(length, value, arr);
	delete[] arr;
	return 0;
}