#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


void convertOctalNumber()
{

	int n;  // n: 입력받을 양의 정수(10진수)

	do{
		
		cout << "Input the number: ";
		cin >> n;  // 10진수를 입력받음

		if( !(n>0 && n<1000000) ) break;  // 입력받은 값이 조건을 만족하지 않을 경우 프로그램 종료

		int i = 1;  // i: 보조변수
		int size;  // size: 8진수가 들어갈 배열의 크기

		while(n >= pow(8,(double)i))
			i++;
			  // 최적의 크기의 메모리를 할당하기 위해 사용(N < 8^i 를 이용)

		int* num = new int[i];   // num[]: 8진수로 변환된 값을 넣기 위한 배열
								 // 메모리 생성 및 할당

		i = 0;
		while(n > 1){
			num[i] = n%8;
			n = n/8;
			i++;
		}
		if(n == 1) num[i] = n;       // 10진수를 8진수로 바꿈

		int k;  // k: 보조변수
		bool stop = false;  // stop: 값이 true일 경우 while문 중단
		while(stop == false){

			if(num[i] > 0){  // 최적화된 출력을 위해 사용(ex: 0025 → 25 를 출력시킴)

				stop = true;
				k = i;
			}
			else i--;
		}

		cout << "The converted octal number is ";
		while(k > -1){
			cout << num[k];
			k--;
		}              // 8진수로 변환된 값을 출력

		cout << endl;
		cout << endl;

		delete[] num;  // 메모리 제거

		n = 1;  // do_while 루프가 잘 돌아가게 하기위해 사용

	}while(n > 0);

}

void unionTwoSets()
{

	int n1, n2;  // n1, n2: 각 집합의 원소의 개수(입력받을 값)

	cout << "Input the size of the first set: ";
	cin >> n1;  // 첫번째 집합의 원소의 개수를 입력받음

	cout << "Input the size of the second set: ";
	cin >> n2;  // 두번째 집합의 원소의 개수를 입력받음


	if( (n1>=0 && n1<=20) && (n2>=0 && n2<=20) ){  // 입력받은 값이 조건믈 만족할 경우에만 실행

		bool same = false;  // same: 두 수가 서로 같을 경우 true, 아니면 false
		int *num1 = new int[n1];  // num1[]: 첫번째 집합의 원소들을 저장할 배열
		int *num2 = new int[n2];  // num2[]: 두번째 집합의 원소들을 저장할 배열
		int *uni_1 = new int[n1+n2];  // uni_1[]: 두 집합의 합집합(중복값 정리 X)
		int *uni_2 = new int[n1+n2];  // uni_2[]: 두 집합의 진짜 합집합(중복값 정리)
									  // 메모리 생성 및 할당

		do{                 // (첫 번째 집합)
			same = false;

			for(int i=0; i<n1; i++)
				num1[i] = rand() % 100 +1;  // 0~100 사이의 임의의 숫자를 원소로 지정해서 넣음

			for(int a=0; a<n1-1; a++)
				for(int b=a+1; b<n1; b++)
					if(num1[a] == num1[b]) same = true;  // 집합 안에 서로 같은 값이 있는지 조사

		}while(same == true);  // 집합 안에 서로 같은 값이 없을 경우 루프를 빠져나옴

		do{                 // (두 번째 집합)
			same = false;

			for(int i=0; i<n2; i++)
				num2[i] = rand() % 100 +1;  // 0~100 사이의 임의의 숫자를 원소로 지정해서 넣음

			for(int a=0; a<n2-1; a++)
				for(int b=a+1; b<n2; b++)
					if(num2[a] == num2[b]) same = true;  // 집합 안에 서로 같은 값이 있는지 조사

		}while(same == true);  // 집합 안에 서로 같은 값이 없을 경우 루프를 빠져나옴

		int i = 0, k = 0;   // i: 배열 num1[], num2[]의 보조변수, k: 배열 uni_1[]의 보조변수

		while(k < n1){
			uni_1[k] = num1[i];  // 첫번째 집합의 원소들을 합집합 안에 넣음
			i++;
			k++;
		}

		i = 0;  // 두번째 집합의 원소들을 합집합 안에 넣기 위해 사용
		while(k < n1+n2){
			uni_1[k] = num2[i];  // 두번째 집합의 원소들을 합집합 안에 넣음
			i++;
			k++;
		}

		for(int i=0; i<n1+n2; i++)
			uni_2[i] = -1;  // -1: 합집합 배열의 빈칸(Null)

		for(int a=0; a<n1+n2; a++){  // 합집합에서 중복값을 정리하는 부분 (ex: {2,5,5,7} → {2,5,7})
			same = false;

			for(int b=0; b<n1+n2; b++){
				if(uni_1[a] == uni_2[b]) same = true;  // 중복값이 있는지 조사
			}

			if(same == false) uni_2[a] = uni_1[a];  // 중복값이 정리될수 있음
		}
		

		cout << endl;
		cout << "The first set is { ";

		for(int a=0; a<n1; a++)
			cout << num1[a] << " ";  // 첫번째 집합 출력
		cout << "}";

		cout << endl;
		cout << "The second set is { ";

		for(int a=0; a<n2; a++)
			cout << num2[a] << " ";  // 두번째 집합 출력
		cout << "}";

		cout << endl;
		cout << "The union set is { ";

		for(int a=0; a<n1+n2; a++)
			if(uni_2[a] > -1) cout << uni_2[a] << " ";  // 합집합 출력 (배열의 빈칸(-1)은 출력하지않음)
		cout << "}";
		cout << endl;

		delete[] num1;
		delete[] num2;
		delete[] uni_1;
		delete[] uni_2;  // 메모리 삭제

	}

}

void findSameNumbers()
{

	char c;  // c: 게임 진행 여부를 저장하기 위한 변수(y/n)

	do{

		cout << "Do you want to play /finding the same number/ game? (y/n) ";
		cin >> c;  // 게임 진행 여부를 입력받음

		if(c == 'n') break;  // 게임 진행 여부가 'n'일 경우 Stop

		int w, h;

		do{
			cout << "Input the width: ";
			cin >> w;  // w: width의 값을 저장하기 위한 변수

			cout << "Input the height: ";
			cin >> h;  // h: height의 값을 저장하기 위한 변수
			           // width와 height을 입력받음

			if( !(w>=1 && w<=10) || !(h>=1 && h<=10) || ((w*h)%2 == 1) )
				cout << "Input the width and height again!" << endl << endl;
					      // 입력받은 값이 조건과 안맞을 경우 재입력 창을 띄움

		}while( !(w>=1 && w<=10) || !(h>=1 && h<=10) || ((w*h)%2 == 1) );
						  // 입력받은 값이 조건과 안맞을 경우 재입력을 요구함

		cout << endl;

		int* num = new int[w*h];  // num[]: 화면에 출력할 숫자들을 모두 저장하는 배열
		int n = 1;  // n: 화면에 출력할 숫자

		for(int k=0; k<=(w*h)-1; k=k+2){
			num[k] = n;
			num[k+1] = n;
			n++;
		}  // 출력할 숫자들을 배열에 모두 저장 (num[] = 0,0,1,1,2,2,...)

		for(int x=1; x<=w; x++){  // x: 행을 제어, y: 열을 제어
			for(int y=0; y<=h-1; y++){

				int z;  // z: 임의의 값을 저장하는 변수
				do{
					z = rand() % (w*h);  // 배열의 값을 무작위로 출력하기 위해 z에 임의의 값을 저장함

				}while(num[z] == 0);  // 중복 추출을 방지를 위해 사용 (밑의 'ㄱ' 참고)

				cout << setw(5) << num[z];  // 배열에 저장된 임의의 값을 출력
				num[z] = 0;  /* (ㄱ) 한 번 추출된 값이 다시 추출되지 않도록 하기 위해
					               해당 배열의 값을 추출했을 경우 그 배열의 값을 0으로 함 */
			}
			cout << endl;
		}

		cout << endl;		
		delete[] num;

	}while(c == 'y');  // 게임 진행 여부가 'y'일 경우 프로그램 실행

}

void matrixArithmetic()
{

	srand((unsigned)time(NULL));  // initialize a random seed

	int n, m;
	cout << "matrix size n m : ";
	cin >> n >> m;  // n: 행렬의 행, m: 행렬의 열

	if( (m>0 && m<=10)&&(n>0 && n<=10) ){ // 행렬의 행과 열이 범위 내일 경우에만 진행

		int** matrix1 = new int*[n];  // matrix1[][]: 행렬 A
		int** matrix2 = new int*[n];  // matrix2[][]: 행렬 B
		int** sum_matrix = new int*[n];  // sum_matrix[][]: 행렬 A + 행렬 B
		int** time_matrix = new int*[n];  // time_matrix[][]: 행렬 A * 행렬 B ^T
		int** matrix2_turn = new int*[m];  // matrix2_turn[][]: 행렬 B의 행,열을 서로 바꾼 행렬
			                         // 메모리 생성 및 할당(1)
		for(int i=0; i<n; i++){
			matrix1[i] = new int[m];
			matrix2[i] = new int[m];
			sum_matrix[i] = new int[m];
			time_matrix[i] = new int[n];
		}                       // 메모리 생성 및 할당(2)
		for(int i=0; i<m; i++)
			matrix2_turn[i] = new int[n];  // 메모리 생성 및 할당(3)


		for(int x=0; x<n; x++)      // x: 배열의 행 제어, y: 배열의 열 제어
			for(int y=0; y<m; y++){
				matrix1[x][y] = rand() % 29 +1;
				matrix2[x][y] = rand() % 29 +1;  // 행렬 A,B에 1~29 사이의 임의의 숫자를 넣음
			}

		for(int x=0; x<n; x++)
			for(int y=0; y<m; y++)
				sum_matrix[x][y] = matrix1[x][y] + matrix2[x][y];  // "행렬 A + 행렬 B" 를 구함

		for(int x=0; x<n; x++)
			for(int y=0; y<m; y++)
				matrix2_turn[y][x] = matrix2[x][y];  // 행렬 B의 행,열을 서로 바꿈

		for(int x=0; x<n; x++)
			for(int y=0; y<n; y++)
				time_matrix[x][y] = 0;  // "행렬 A * 행렬 B ^T"를 구하기 위해 사용

		for(int x=0; x<n; x++)
			for(int y=0; y<n; y++)
				for(int a=0; a<m; a++)
					time_matrix[x][y] = time_matrix[x][y] + ( matrix1[x][a] * matrix2_turn[a][y] );
																	// "행렬 A + 행렬 B ^T" 를 구함


		cout << "+++++++ RANDOM MATRIX A +++++++" << endl;
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++)
				cout << setw(4) << matrix1[x][y];  // 행렬 A 출력
			cout << endl;
		}

		cout << "+++++++ RANDOM MATRIX B +++++++" << endl;
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++)
				cout << setw(4) << matrix2[x][y];  // 행렬 B 출력
			cout << endl;
		}

		cout << "+++++++ A+B MATRIX +++++++" << endl;
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++)
				cout << setw(4) << sum_matrix[x][y];  // "행렬 A + 행렬 B" 출력
			cout << endl;
		}

		cout << "+++++++ A*B^T MATRIX +++++++" << endl;
		for(int x=0; x<n; x++){
			for(int y=0; y<n; y++)
				cout << setw(6) << time_matrix[x][y];  // "행렬 A * 행렬 B ^T" 출력
			cout << endl;
		}


		for(int i=0; i<m; i++)
			delete[] matrix2_turn[i];  // 메모리 삭제(1)
		for(int i=0; i<n; i++){
			delete[] matrix1[i];
			delete[] matrix2[i];
			delete[] sum_matrix[i];
			delete[] time_matrix[i];
		}                       // 메모리 삭제(2)
		delete[] matrix1;
		delete[] matrix2;
		delete[] matrix2_turn;
		delete[] sum_matrix;
		delete[] time_matrix;  // 메모리 삭제(3)

	}

}

void longestPath()
{

	srand((unsigned)time(NULL));  // initialize a random seed

	int m;  // m: 행렬의 크기(행=열)
	cout << "Input matrix size m : ";
	cin >> m;  // 행렬의 크기를 입력받음

	if( m>0 && m<=20 ){  // 행렬의 크기가 범위를 만족해야만 진행
		
		int** num = new int*[m];  // num[]: 행렬
			// 메모리 생성 및 할당(1)
		for(int i=0; i<m; i++)
			num[i] = new int[m];  // 메모리 생성 및 할당(2)

		for(int x=0; x<m; x++)      // x: 배열의 행 제어, y: 배열의 열 제어
			for(int y=0; y<m; y++)
				num[x][y] = rand() % 29 +1;  // 행렬에 1~29 사이의 숫자를 임의로 저장


		int sum = 0, max = 0;  // sum: longest path(결과값), max: 각 행마다 최대값을 저장
		int point_y;  // point_y: 포인터를 저장(열)
		int max_length = 0;  // max_length: 최종 결과값(longest path)

		for(int y=0; y<m; y++){
			point_y = y;  // 1행의 숫자를 포인터로 지정
			sum = num[0][y];  // 1행의 숫자를 sum에 누적
		
			for(int x=1; x<m; x++){  // 행렬의 2행부터 최대값을 찾아나감

				int a, b;  // a→b: num[][a]부터 num[][b]까지 최대값 조사(a < b)
				max = 0;  // 한 행의 최대값을 누적했을 때마다 항상 최대값을 다시 0으로 초기화

				if(point_y == 0){  // 포인터가 왼쪽 끝자리일경우
					a = 0;
					b = 1;  // "↓,↘" 수색
				} else if(point_y == m-1){  // 포인터가 오른쪽 끝자리일경우
					a = (m-1)-1;
					b = m-1;  // "↙,↓" 수색
				} else{  // 포인터가 끝자리가 아닌 숫자 사이일 경우
					a = point_y -1;
					b = point_y +1;  // "↙,↓,↘" 수색
				}

				for(int k=a; k<=b; k++)  // num[][a]부터 num[][b]까지 최대값 조사
					if(max < num[x][k]){
						max = num[x][k];
						point_y = k;  // 최대값이 있는 부분을 포인터로 지정
					}

				sum = sum + max;  // 각 행마다 찾은 최대값을 sum에 누적
			}

			if(max_length < sum) max_length = sum;  // longest path를 구함
		}


		cout << "+++++++ RANDOM MATRIX +++++++" << endl;
		for(int x=0; x<m; x++){
			for(int y=0; y<m; y++)
				cout << setw(4) << num[x][y];
			cout << endl;
		}						// 임의의 행렬을 출력하는 부분

		cout << endl;
		cout << "The longest path is " << max_length << endl;  // longest path 출력

		for(int i=0; i<m; i++)
			delete[] num[i];  // 메모리 삭제(1)

		delete[] num;  // 메모리 삭제(2)

	}

}


int main()
{
	convertOctalNumber();
	unionTwoSets();

	findSameNumbers();
	matrixArithmetic();
	longestPath();

	return 0;
}