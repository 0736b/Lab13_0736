#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void showMatrix(const bool matrix[][N]){
for(int i = 0; i< N; i++){
	for(int j = 0 ; j<N; j++){
		cout << matrix[i][j] << " ";
	}
	cout << endl;
}
}

void inputMatrix(double input_matrix[][N]){
	for(int i = 0; i < N; i++){
			cout << "Row " << i+1 << ": ";
			for(int j = 0; j<N; j++){
				cin >> input_matrix[i][j];
			}
			}
	}

void findLocalMax(const double M_Input[][N], bool M_Output[][N]){
	
	// สมาชิกขอบบน ล่าง ซ้าย ขวา ของ B จะมีค่าเท่ากับ 0
	for(int i = 0; i < N; i++){
		M_Output[0][i] = 0;
		M_Output[N-1][i] = 0;
		
	}
	for(int j = 1 ; j < N; j++){
		M_Output[j][0] = 0;
		M_Output[j][N-1] = 0;
	}
    // เช็ค Matrix A รอบข้าง 4 ทิศ

    	for(int i = 1 ; i < N-1; i++){
		for(int j = 1 ; j< N-1; j++){
			if((M_Input[i][j] >= M_Input[i-1][j]) && (M_Input[i][j] >= M_Input[i][j+1]) && (M_Input[i][j] >= M_Input[i+1][j]) && (M_Input[i][j] >= M_Input[i][j-1])){
				M_Output[i][j] = 1;
			}
			else if((M_Input[i][j] < M_Input[i-1][j]) || (M_Input[i][j] < M_Input[i][j+1]) || (M_Input[i][j] < M_Input[i+1][j]) || (M_Input[i][j] < M_Input[i][j-1])){
				M_Output[i][j] = 0;
			}
		}
	}
}