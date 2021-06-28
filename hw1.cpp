#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


void convertOctalNumber()
{

	int n;  // n: �Է¹��� ���� ����(10����)

	do{
		
		cout << "Input the number: ";
		cin >> n;  // 10������ �Է¹���

		if( !(n>0 && n<1000000) ) break;  // �Է¹��� ���� ������ �������� ���� ��� ���α׷� ����

		int i = 1;  // i: ��������
		int size;  // size: 8������ �� �迭�� ũ��

		while(n >= pow(8,(double)i))
			i++;
			  // ������ ũ���� �޸𸮸� �Ҵ��ϱ� ���� ���(N < 8^i �� �̿�)

		int* num = new int[i];   // num[]: 8������ ��ȯ�� ���� �ֱ� ���� �迭
								 // �޸� ���� �� �Ҵ�

		i = 0;
		while(n > 1){
			num[i] = n%8;
			n = n/8;
			i++;
		}
		if(n == 1) num[i] = n;       // 10������ 8������ �ٲ�

		int k;  // k: ��������
		bool stop = false;  // stop: ���� true�� ��� while�� �ߴ�
		while(stop == false){

			if(num[i] > 0){  // ����ȭ�� ����� ���� ���(ex: 0025 �� 25 �� ��½�Ŵ)

				stop = true;
				k = i;
			}
			else i--;
		}

		cout << "The converted octal number is ";
		while(k > -1){
			cout << num[k];
			k--;
		}              // 8������ ��ȯ�� ���� ���

		cout << endl;
		cout << endl;

		delete[] num;  // �޸� ����

		n = 1;  // do_while ������ �� ���ư��� �ϱ����� ���

	}while(n > 0);

}

void unionTwoSets()
{

	int n1, n2;  // n1, n2: �� ������ ������ ����(�Է¹��� ��)

	cout << "Input the size of the first set: ";
	cin >> n1;  // ù��° ������ ������ ������ �Է¹���

	cout << "Input the size of the second set: ";
	cin >> n2;  // �ι�° ������ ������ ������ �Է¹���


	if( (n1>=0 && n1<=20) && (n2>=0 && n2<=20) ){  // �Է¹��� ���� ���ǹ� ������ ��쿡�� ����

		bool same = false;  // same: �� ���� ���� ���� ��� true, �ƴϸ� false
		int *num1 = new int[n1];  // num1[]: ù��° ������ ���ҵ��� ������ �迭
		int *num2 = new int[n2];  // num2[]: �ι�° ������ ���ҵ��� ������ �迭
		int *uni_1 = new int[n1+n2];  // uni_1[]: �� ������ ������(�ߺ��� ���� X)
		int *uni_2 = new int[n1+n2];  // uni_2[]: �� ������ ��¥ ������(�ߺ��� ����)
									  // �޸� ���� �� �Ҵ�

		do{                 // (ù ��° ����)
			same = false;

			for(int i=0; i<n1; i++)
				num1[i] = rand() % 100 +1;  // 0~100 ������ ������ ���ڸ� ���ҷ� �����ؼ� ����

			for(int a=0; a<n1-1; a++)
				for(int b=a+1; b<n1; b++)
					if(num1[a] == num1[b]) same = true;  // ���� �ȿ� ���� ���� ���� �ִ��� ����

		}while(same == true);  // ���� �ȿ� ���� ���� ���� ���� ��� ������ ��������

		do{                 // (�� ��° ����)
			same = false;

			for(int i=0; i<n2; i++)
				num2[i] = rand() % 100 +1;  // 0~100 ������ ������ ���ڸ� ���ҷ� �����ؼ� ����

			for(int a=0; a<n2-1; a++)
				for(int b=a+1; b<n2; b++)
					if(num2[a] == num2[b]) same = true;  // ���� �ȿ� ���� ���� ���� �ִ��� ����

		}while(same == true);  // ���� �ȿ� ���� ���� ���� ���� ��� ������ ��������

		int i = 0, k = 0;   // i: �迭 num1[], num2[]�� ��������, k: �迭 uni_1[]�� ��������

		while(k < n1){
			uni_1[k] = num1[i];  // ù��° ������ ���ҵ��� ������ �ȿ� ����
			i++;
			k++;
		}

		i = 0;  // �ι�° ������ ���ҵ��� ������ �ȿ� �ֱ� ���� ���
		while(k < n1+n2){
			uni_1[k] = num2[i];  // �ι�° ������ ���ҵ��� ������ �ȿ� ����
			i++;
			k++;
		}

		for(int i=0; i<n1+n2; i++)
			uni_2[i] = -1;  // -1: ������ �迭�� ��ĭ(Null)

		for(int a=0; a<n1+n2; a++){  // �����տ��� �ߺ����� �����ϴ� �κ� (ex: {2,5,5,7} �� {2,5,7})
			same = false;

			for(int b=0; b<n1+n2; b++){
				if(uni_1[a] == uni_2[b]) same = true;  // �ߺ����� �ִ��� ����
			}

			if(same == false) uni_2[a] = uni_1[a];  // �ߺ����� �����ɼ� ����
		}
		

		cout << endl;
		cout << "The first set is { ";

		for(int a=0; a<n1; a++)
			cout << num1[a] << " ";  // ù��° ���� ���
		cout << "}";

		cout << endl;
		cout << "The second set is { ";

		for(int a=0; a<n2; a++)
			cout << num2[a] << " ";  // �ι�° ���� ���
		cout << "}";

		cout << endl;
		cout << "The union set is { ";

		for(int a=0; a<n1+n2; a++)
			if(uni_2[a] > -1) cout << uni_2[a] << " ";  // ������ ��� (�迭�� ��ĭ(-1)�� �����������)
		cout << "}";
		cout << endl;

		delete[] num1;
		delete[] num2;
		delete[] uni_1;
		delete[] uni_2;  // �޸� ����

	}

}

void findSameNumbers()
{

	char c;  // c: ���� ���� ���θ� �����ϱ� ���� ����(y/n)

	do{

		cout << "Do you want to play /finding the same number/ game? (y/n) ";
		cin >> c;  // ���� ���� ���θ� �Է¹���

		if(c == 'n') break;  // ���� ���� ���ΰ� 'n'�� ��� Stop

		int w, h;

		do{
			cout << "Input the width: ";
			cin >> w;  // w: width�� ���� �����ϱ� ���� ����

			cout << "Input the height: ";
			cin >> h;  // h: height�� ���� �����ϱ� ���� ����
			           // width�� height�� �Է¹���

			if( !(w>=1 && w<=10) || !(h>=1 && h<=10) || ((w*h)%2 == 1) )
				cout << "Input the width and height again!" << endl << endl;
					      // �Է¹��� ���� ���ǰ� �ȸ��� ��� ���Է� â�� ���

		}while( !(w>=1 && w<=10) || !(h>=1 && h<=10) || ((w*h)%2 == 1) );
						  // �Է¹��� ���� ���ǰ� �ȸ��� ��� ���Է��� �䱸��

		cout << endl;

		int* num = new int[w*h];  // num[]: ȭ�鿡 ����� ���ڵ��� ��� �����ϴ� �迭
		int n = 1;  // n: ȭ�鿡 ����� ����

		for(int k=0; k<=(w*h)-1; k=k+2){
			num[k] = n;
			num[k+1] = n;
			n++;
		}  // ����� ���ڵ��� �迭�� ��� ���� (num[] = 0,0,1,1,2,2,...)

		for(int x=1; x<=w; x++){  // x: ���� ����, y: ���� ����
			for(int y=0; y<=h-1; y++){

				int z;  // z: ������ ���� �����ϴ� ����
				do{
					z = rand() % (w*h);  // �迭�� ���� �������� ����ϱ� ���� z�� ������ ���� ������

				}while(num[z] == 0);  // �ߺ� ������ ������ ���� ��� (���� '��' ����)

				cout << setw(5) << num[z];  // �迭�� ����� ������ ���� ���
				num[z] = 0;  /* (��) �� �� ����� ���� �ٽ� ������� �ʵ��� �ϱ� ����
					               �ش� �迭�� ���� �������� ��� �� �迭�� ���� 0���� �� */
			}
			cout << endl;
		}

		cout << endl;		
		delete[] num;

	}while(c == 'y');  // ���� ���� ���ΰ� 'y'�� ��� ���α׷� ����

}

void matrixArithmetic()
{

	srand((unsigned)time(NULL));  // initialize a random seed

	int n, m;
	cout << "matrix size n m : ";
	cin >> n >> m;  // n: ����� ��, m: ����� ��

	if( (m>0 && m<=10)&&(n>0 && n<=10) ){ // ����� ��� ���� ���� ���� ��쿡�� ����

		int** matrix1 = new int*[n];  // matrix1[][]: ��� A
		int** matrix2 = new int*[n];  // matrix2[][]: ��� B
		int** sum_matrix = new int*[n];  // sum_matrix[][]: ��� A + ��� B
		int** time_matrix = new int*[n];  // time_matrix[][]: ��� A * ��� B ^T
		int** matrix2_turn = new int*[m];  // matrix2_turn[][]: ��� B�� ��,���� ���� �ٲ� ���
			                         // �޸� ���� �� �Ҵ�(1)
		for(int i=0; i<n; i++){
			matrix1[i] = new int[m];
			matrix2[i] = new int[m];
			sum_matrix[i] = new int[m];
			time_matrix[i] = new int[n];
		}                       // �޸� ���� �� �Ҵ�(2)
		for(int i=0; i<m; i++)
			matrix2_turn[i] = new int[n];  // �޸� ���� �� �Ҵ�(3)


		for(int x=0; x<n; x++)      // x: �迭�� �� ����, y: �迭�� �� ����
			for(int y=0; y<m; y++){
				matrix1[x][y] = rand() % 29 +1;
				matrix2[x][y] = rand() % 29 +1;  // ��� A,B�� 1~29 ������ ������ ���ڸ� ����
			}

		for(int x=0; x<n; x++)
			for(int y=0; y<m; y++)
				sum_matrix[x][y] = matrix1[x][y] + matrix2[x][y];  // "��� A + ��� B" �� ����

		for(int x=0; x<n; x++)
			for(int y=0; y<m; y++)
				matrix2_turn[y][x] = matrix2[x][y];  // ��� B�� ��,���� ���� �ٲ�

		for(int x=0; x<n; x++)
			for(int y=0; y<n; y++)
				time_matrix[x][y] = 0;  // "��� A * ��� B ^T"�� ���ϱ� ���� ���

		for(int x=0; x<n; x++)
			for(int y=0; y<n; y++)
				for(int a=0; a<m; a++)
					time_matrix[x][y] = time_matrix[x][y] + ( matrix1[x][a] * matrix2_turn[a][y] );
																	// "��� A + ��� B ^T" �� ����


		cout << "+++++++ RANDOM MATRIX A +++++++" << endl;
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++)
				cout << setw(4) << matrix1[x][y];  // ��� A ���
			cout << endl;
		}

		cout << "+++++++ RANDOM MATRIX B +++++++" << endl;
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++)
				cout << setw(4) << matrix2[x][y];  // ��� B ���
			cout << endl;
		}

		cout << "+++++++ A+B MATRIX +++++++" << endl;
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++)
				cout << setw(4) << sum_matrix[x][y];  // "��� A + ��� B" ���
			cout << endl;
		}

		cout << "+++++++ A*B^T MATRIX +++++++" << endl;
		for(int x=0; x<n; x++){
			for(int y=0; y<n; y++)
				cout << setw(6) << time_matrix[x][y];  // "��� A * ��� B ^T" ���
			cout << endl;
		}


		for(int i=0; i<m; i++)
			delete[] matrix2_turn[i];  // �޸� ����(1)
		for(int i=0; i<n; i++){
			delete[] matrix1[i];
			delete[] matrix2[i];
			delete[] sum_matrix[i];
			delete[] time_matrix[i];
		}                       // �޸� ����(2)
		delete[] matrix1;
		delete[] matrix2;
		delete[] matrix2_turn;
		delete[] sum_matrix;
		delete[] time_matrix;  // �޸� ����(3)

	}

}

void longestPath()
{

	srand((unsigned)time(NULL));  // initialize a random seed

	int m;  // m: ����� ũ��(��=��)
	cout << "Input matrix size m : ";
	cin >> m;  // ����� ũ�⸦ �Է¹���

	if( m>0 && m<=20 ){  // ����� ũ�Ⱑ ������ �����ؾ߸� ����
		
		int** num = new int*[m];  // num[]: ���
			// �޸� ���� �� �Ҵ�(1)
		for(int i=0; i<m; i++)
			num[i] = new int[m];  // �޸� ���� �� �Ҵ�(2)

		for(int x=0; x<m; x++)      // x: �迭�� �� ����, y: �迭�� �� ����
			for(int y=0; y<m; y++)
				num[x][y] = rand() % 29 +1;  // ��Ŀ� 1~29 ������ ���ڸ� ���Ƿ� ����


		int sum = 0, max = 0;  // sum: longest path(�����), max: �� �ึ�� �ִ밪�� ����
		int point_y;  // point_y: �����͸� ����(��)
		int max_length = 0;  // max_length: ���� �����(longest path)

		for(int y=0; y<m; y++){
			point_y = y;  // 1���� ���ڸ� �����ͷ� ����
			sum = num[0][y];  // 1���� ���ڸ� sum�� ����
		
			for(int x=1; x<m; x++){  // ����� 2����� �ִ밪�� ã�Ƴ���

				int a, b;  // a��b: num[][a]���� num[][b]���� �ִ밪 ����(a < b)
				max = 0;  // �� ���� �ִ밪�� �������� ������ �׻� �ִ밪�� �ٽ� 0���� �ʱ�ȭ

				if(point_y == 0){  // �����Ͱ� ���� ���ڸ��ϰ��
					a = 0;
					b = 1;  // "��,��" ����
				} else if(point_y == m-1){  // �����Ͱ� ������ ���ڸ��ϰ��
					a = (m-1)-1;
					b = m-1;  // "��,��" ����
				} else{  // �����Ͱ� ���ڸ��� �ƴ� ���� ������ ���
					a = point_y -1;
					b = point_y +1;  // "��,��,��" ����
				}

				for(int k=a; k<=b; k++)  // num[][a]���� num[][b]���� �ִ밪 ����
					if(max < num[x][k]){
						max = num[x][k];
						point_y = k;  // �ִ밪�� �ִ� �κ��� �����ͷ� ����
					}

				sum = sum + max;  // �� �ึ�� ã�� �ִ밪�� sum�� ����
			}

			if(max_length < sum) max_length = sum;  // longest path�� ����
		}


		cout << "+++++++ RANDOM MATRIX +++++++" << endl;
		for(int x=0; x<m; x++){
			for(int y=0; y<m; y++)
				cout << setw(4) << num[x][y];
			cout << endl;
		}						// ������ ����� ����ϴ� �κ�

		cout << endl;
		cout << "The longest path is " << max_length << endl;  // longest path ���

		for(int i=0; i<m; i++)
			delete[] num[i];  // �޸� ����(1)

		delete[] num;  // �޸� ����(2)

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