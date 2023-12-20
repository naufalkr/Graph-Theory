#include <bits/stdc++.h>
#define N 8
using namespace std;
// Mengatur jumlah kotak board dengan array 2D
int board[N][N];	
// Representasi pergerakan kuda (+) pada row menandakan pergerakan ke kanan, pada col menandakan pergerakan ke bawah.
// Representasi pergerakan kuda (-) pada row menandakan pergerakan ke kiri, pada col menandakan pergerakan ke atas.
int row[N] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[N] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int r,int c){
	// Mengecek apakah koordinat (r,c) berada pada board, dan board[r][c] == -1
	return (r>=0 && c>=0 && r<N && c<N && board[r][c] == -1); 
}
bool openTour(int r,int c,int move){
	// Jika sudah mencapai N*N maka ada solusi
	if(move == N*N) 
		return true; 

	int move_x, move_y;

	// Mengecek semua kemungkinan
	for(int k = 0;k<N;k++){
		// Koordinat x dan y yang sesuai
		move_x = r + row[k]; 
		move_y = c + col[k];
		if(isValid(move_x,move_y)){
			// board dengan koordinat move_x dan move_y akan diisi dengan move + 1, yang sebelumnya berisi -1
			board[move_x][move_y] = move + 1; 
			// Cek apakah ada solusi
			if(openTour(move_x,move_y,move + 1) == 1)return true;
			else board[move_x][move_y] = -1; // Backtracking
		}
	}
	//jika tidak ada solusi maka return false
	return false; 
}
int main() {
	// Inisiasi board dengan -1
	for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        board[i][j] = -1;
    }
}
	// koordinat awal
	board[0][3] = 1; 
	if(openTour(0,3,1)){
	for(int i = 0;i<N;i++)
			{
			for(int j = 0;j<N;j++)
				cout<<board[i][j]<<"  ";
			cout<<endl;
		}
	}
	else cout<<"Tidak Ada Cara\n";
	return 0;
}