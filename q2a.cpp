#include<iostream>
#include<string.h>
#include<conio.h>
#include<algorithm>
#include<time.h>
#include<windows.h>
#include <bitset>

using namespace std;

string decryptOTP(string cipher,int seed){
	string cipher_bits="";
	string key="";
	srand(seed);
	for (size_t i = 0; i < cipher.size(); ++i)
	{
		key+= bitset<5>(rand()%26).to_string();
		cipher_bits+= bitset<5>(cipher.c_str()[i]-65).to_string() ;
	}
	string bits="";
	string plaintext="";
	for(int i =0;i<cipher_bits.size();i++){
	
		bits+= char(((int(cipher_bits.c_str()[i])-48)^(int(key.c_str()[i])-48))+48);
	 }
	cout<<" Keystream (in bits):"<<key<<endl;
	cout<<" Ciphertext(in bits):"<<cipher_bits<<endl;
	cout<<" Plaintext (in bits):"<<bits<<endl;
	
	for(int i=0;i<bits.size();i+=5){
		bitset<5> b1(bits.substr(i,5));
		plaintext+=((((int)(b1.to_ulong()))%26+26)%26 +97);
	
	}
	return plaintext;
}	



string encryptOTP(string text,int seed){

	string bits="";
	string key="";
	srand(seed);
	for (size_t i = 0; i < text.size(); ++i)
	{
		key+= bitset<5>(rand()%26).to_string();
		bits+= bitset<5>(text.c_str()[i]-97).to_string() ;
	}
	string cipher="";
	string cipher_bits="";
	for(int i =0;i<bits.size();i++){
	
		cipher_bits+= char(((int(bits.c_str()[i])-48)^(int(key.c_str()[i])-48))+48);
	 }
	cout<<" Keystream  (in bits):"<<key<<endl;
	cout<<" Plaintext  (in bits):"<<bits<<endl;
	cout<<" Ciphertext (in bits):"<<cipher_bits<<endl;
	//std::string bit_string = "110010";
	//std::bitset<8> b3(bit_string);       // [0,0,1,1,0,0,1,0]
	
	//std::cout << b3.to_string() << std::endl ;
	for(int i=0;i<cipher_bits.size();i+=5){
		bitset<5> b1(cipher_bits.substr(i,5));
		cipher+=((((int)(b1.to_ulong()))%26+26)%26 +65);
	
	}
	return cipher;
}

int main(){
	int seed=3;
	//cout<<"The seed for the PRNG is :"<<seed<<endl;
	//cin>>seed;
	
	string text="";
	cout<<"Input the plaintext : " ;
	cin>>text;

	
	cout<<"Encrypted text : "<<encryptOTP(text,seed)<<endl;
	
	string cipher="";
	cout<<"Ciphertext to decrypt : ";
	cin>>cipher;
	int seed1=3;
	//cout<<endl<<"Enter the seed\n"<<endl;
	//cin>>seed1;
	
	cout<<"Decrypted text : "<<decryptOTP(cipher,seed1)<<endl;

	getch();
	
}
