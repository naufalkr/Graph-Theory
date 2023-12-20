#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

	int arr[t];
	int lis[t];
    for(int i = 0; i < t; i++ ){
        cin >> arr[i];
    }

	// inisiasi lis menjadi 1 semua
	for(int i = 0; i < t; i++)
		lis[i] = 1;

	// mencari LIS dengan mengecek setiap elemen dengan start pada arr[1]
	for (int i = 1; i < t; i++) {
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1) // Jika arr[i] > arr[j] dan lis[i] < lis[j] + 1 maka lis[i] yang berisi 1 akan ditambah 1
				lis[i] = lis[j] + 1;
	}

    cout << "Panjang LIS " << *max_element(lis, lis + t) << endl; // max_element(array, array + size)
	return 0;
}

//Gambaran cara kerja

// Iterator			j	i		
// arr			    50	3	10	7	40	80
// lis 				1	1	1	1	1	1
