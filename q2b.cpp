#include<iostream>
#include<string.h>
#include<conio.h>
#include <algorithm>
#include<time.h>
#include <bitset>

using namespace std;
int det(int a[2][2]){
	return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
}
int main(){
	
	string plaintext="",cipher="",keybits="",seed="";
	cout<<"Given are the 15 bit known plain text : \n";
	cin>>plaintext;
	cout<<"\nEnter the first 15 bit of the known ciphertext\n";
	cin>>cipher;
	
	for(int i =0;i<15;i++){
	
		keybits+= char(((int(plaintext.c_str()[i])-48)^(int(cipher.c_str()[i])-48))+48);
	 }
	 
	bitset<5> b1(keybits.substr(0,5));
	bitset<5> b2(keybits.substr(5,5));
	bitset<5> b3(keybits.substr(10,5));
	int s0=(int)(b1.to_ulong());
	int s1=(int)(b2.to_ulong());
	int s2=(int)(b3.to_ulong());
	
	
	int D[2][2]={{s0,1},{s1,1}};
	int Dx[2][2]={{s1,1},{s2,1}};
	int Dy[2][2]={{s0,s1},{s1,s2}};
	
	int A,B;
	cout << "\n\n S0 = seed \n S(i+1) = (AS(i)+B)mod26 \n\n Values of seed, A and B thus obtained : \n\n " ;
	A=(((det(Dx)/det(D))%26)+26)%26;
	B=(((det(Dy)/det(D))%26)+26)%26;
	cout<<"A:"<<A<<"\n "<<"B:"<<B<<endl;
	cout<<"\n S0 :"<<s0<<"   "<<"S1 :"<<s1<<"   "<<"S2 :"<<s2;
	getch() ;
}
