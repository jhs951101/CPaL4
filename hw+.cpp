#include <iostream>
#include <cmath>

using namespace std;

void generatePoints(double** points, const int n){

	double number;

	for(int x=0; x<n; x++)
		for(int y=0; y<2; y++){
			number = 0.1 + (1.0 - 0.1) * rand() * (1.0 / RAND_MAX);
			number *= 10.0;
			points[x][y] = (int)number;
			points[x][y] /= 10.0;
		}

}

void findLongestDistance(double** const points, const int n){

	double step1, step2, step3;
	double distance;
	double max = 0;
	double p1, p2;
	double q1, q2;

	for(int x=0; x<n-1; x++)
		for(int a=x+1; a<n; a++){

			step1 = pow( points[x][0] - points[a][0] ,2);
			step2 = pow( points[x][1] - points[a][1] ,2);
			step3 = step1 + step2;
			distance = sqrt(step3);

			if(max < distance){
				max = distance;
				p1 = points[x][0];
				q1 = points[a][0];
				p2 = points[x][1];
				q2 = points[a][1];
			}
		}

	cout << "Two points with the longest distance are (" << p1 << "," << p2 << ")" << " and " << "(" << q1 << "," << q2 << ")" << endl;
	
	/*double a = distance;
	a *= 100.0;
	double distance_f2 = (int)a;
	distance_f2 /= 100.0;

	cout << "Longest distance is " << distance_f2 << endl;*/

}

double** initializeMemory(const int n){

	double** num = new double*[n];
	for(int i=0; i<n; i++)
		num[i] = new double[2];

	return num;

}

void releaseMemory(double** points, const int n){

	for(int i=0; i<=n; i++)
		delete[] points[i];
	delete[] points;

}

int main(){

	int n;
	cout << "Generating N random two-dimensional points. n=";
	cin >> n;

	if( !(n>0 && n<1000000) ) return 0;

	double **num = initializeMemory(n);

	generatePoints(num, n);

	findLongestDistance(num, n);

	//releaseMemory(num, n);

	return 0;
}