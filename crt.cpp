#include<bits/stdc++.h>
using namespace std;

int inverse(int n , int b){
	for(int i=1 ; i<n ; i++)
	    if((b*i)%n == 1)
	        return i ;
}

int main(){
	int n ;
	cout << "Enter no. of equations in the set : " ;
	cin >> n ;

	int a[n] ;
	int m[n] ;
	int _M = 1  ;
	int M[n] ;
	int invM[n] ;
	cout << " For the each equation, of form x = a mod m, enter the values of x,a and m \n" ;
	for(int i=0 ; i<n ; i++){
		cout << " For equation " << i+1 << " : \n" ;
		cout <<" a = " ;
		cin >> a[i] ;
		cout <<" m = " ;
		cin >> m[i] ;
		_M = _M * m[i] ;
	}
	cout << " Obtained value of M = " << _M << endl ;
	cout << " Thus , \n" ;
	for(int i=0 ; i<n ; i++){
		M[i] = _M / m[i] ;
		invM[i] = inverse(m[i],M[i]);
		cout << " Inverse of " << M[i] << " = " << invM[i] << endl ;
	}
	
	int x = 0 ;
	for(int i=0 ; i<n ; i++){
		x = x + a[i] * M[i] * invM[i] ;
	}
	
	cout << " Thus, the required solution = " << x%_M << " mod " << _M << endl ;

    system("pause");
	return 0 ;
}
