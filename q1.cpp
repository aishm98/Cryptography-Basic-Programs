#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
#include <algorithm>
#include <bitset>

using namespace std ;

char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
char ciphertext[] = "KQEREJEBCPPCRKIEACUZBKRVPKRBCIBQCARBJCVFCUPKRIOFKPACUZQEPBKRXPEIIEABDKPBCPFCDCCAFIEABDKPBCPFEQPKAZBKRHAIBKAPCCIBURCCDKDCCJCIDFUIXPAFFERBICZDFKABICBBENEFCUPJCVKABPCYDCCDPKBCOCPERKIVKSCPICBRKIJPKABI" ;
float prob[26] = { 0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.020, 0.061, 0.070, 0.002, 0.008, 0.040, 0.024, 0.067, 0.075, 0.019, 0.001, 0.060, 0.063, 0.091, 0.028, 0.010, 0.023, 0.001, 0.020, 0.001 } ;

void find_freq(char ctext[], int freq[]){
	for(int i=0 ; i<26 ; i++)
	    freq[i] = 0 ;
	int len = strlen(ctext) ;
	for(int i=0 ; i<len ; i++)
	    for(int j=0 ; j<26 ; j++)
	        if(ctext[i]==alpha[j])
	            freq[j] += 1 ;
}


void sort(char ctext[] , int num[] , char e_ctext[] , int e_num[] ){
	int len = strlen(ctext) ;
	for(int i=0 ; i<len ; i++){
        e_num[i] = num[i] ;
        e_ctext[i] = ctext[i] ;
	}
	 int temp ;
	 char ch ;
		
	for(int i=0 ; i<len ; i++)
		for(int j=0 ; j<len ; j++){
			if(e_num[i]>e_num[j]){
				temp = e_num[i] ;
				e_num[i] = e_num[j] ;
				e_num[j] = temp ;
				
				ch = e_ctext[i] ;
				e_ctext[i] = e_ctext[j] ;
				e_ctext[j] = ch ;
			}
		}
}

void sort_f(char ctext[] , float num[] , char e_ctext[] , float e_num[] ){
	int len = strlen(ctext) ;
	for(int i=0 ; i<len ; i++){
        e_num[i] = num[i] ;
        e_ctext[i] = ctext[i] ;
	}
	 float temp ;
	 char ch ;

	for(int i=0 ; i<len ; i++)
		for(int j=0 ; j<len ; j++){
			if(e_num[i]>e_num[j]){
				temp = e_num[i] ;
				e_num[i] = e_num[j] ;
				e_num[j] = temp ;

				ch = e_ctext[i] ;
				e_ctext[i] = e_ctext[j] ;
				e_ctext[j] = ch ;
			}
		}
}

int num(char c){
	char a = 'A' ;
	for(int i=0 ; i<25 ; i++, a++)
	    if(c==a)
	        return i ;
}

char fnum(int x){
	char a = 'A' ;
	for(int i=0 ; i<25 ; i++, a++)
	    if(x==i)
	        return a ;
}

void find_key(char ptext[], char ctext[], int &km, int &ks, int i){
	int x1 = num(ptext[i]);
	int x2 = num(ptext[0]);
	int y1 = num(ctext[i]);
	int y2 = num(ctext[0]);
	
	float m = (y2 - y1)/(x1 - x2) ;
	km = (int)ceil(m);
	if(km<0)
	    km += 26 ;
	if(km==25)
	    km = 19 ;
	float s = (y2*x1 - y1*x2)/(x1 - x2) ;
	ks = (int)ceil(s) ;
	if(ks<0)
	    ks += 26 ;
	if(ks==23||ks==22)
	    ks = 4 ;

}

int GCD(int a,int b){
	if(a<0 ){
		a=-a;
	}
	if( b<0){
		b=-b;
	}
    int q,r;
    q=a/b;
    r=a%b;
    if (r==0){
        return b;}
    else
        GCD(b,r);
    }


int muli(int a,int N){
    if(GCD(a,N)==1){
        for(int i=1;i<N;i++){
            if(GCD(i,N)==1){
                if(((((a*i) % N)+N)%N) == 1){
                    return i;
                }
            }
        }
    }
    else{
        return 0;
    }

    }


string decryptCipher(string cipher,int a,int b)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;


    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;


        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if(cipher[i]!=' ')

            msg = msg + (char) (((a_inv * ((cipher[i]+'A' - b)) % 26)) + 'A');
        else

            msg += cipher[i];
    }

    return msg;
}

int det(int a[2][2]){
	return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
}

int main(){
	int freq[26] ;
	find_freq(ciphertext,freq) ;
	cout << " Table depicting Statistics about the English Language : \n\n " ;
	cout << " Letter\t Probabibility \t\tLetter\t Probability" << endl ;
	for(int i=0 ; i<13 ; i++){
		cout << "  " << alpha[i] << "\t\t    " << prob[i] << "\t\t    " << alpha[i+13] << "\t    " << prob[i+13] << endl ;
	}
	
	cout << " \n Given ciphertext is : \n\n" << ciphertext << endl << endl ;
    cout << " Table depicting Frequencies of all the Letters in the given ciphertext : \n\n" ;
    cout << " Letter\t Frequency \t\tLetter\t Frequency" << endl ;
    for(int i=0 ; i<13 ; i++){
		cout << "  " << alpha[i] << "\t   " << freq[i] << "\t\t\t    " << alpha[i+13] << "\t    " << freq[i+13] << endl ;
	}

	int s_freq[26] ;
	char s_text[26] ;
	
	float s_prob[26] ;
	char s_txt[26] ;

	sort(alpha,freq,s_text,s_freq) ;    
	sort_f(alpha,prob,s_txt,s_prob) ;
	cout << " Table showing Frequencies of all the Letters in the ciphertext (Decreasing order) : \n\n" ;
    cout << " Letter\t Frequency \t\tLetter\t Frequency" << endl ;
    for(int i=0 ; i<13 ; i++){
		cout << "  " << s_text[i] << "\t   " << s_freq[i] << "\t\t\t    " << s_text[i+13] << "\t    " << s_freq[i+13] << endl ;
	}
	
	cout << " Table showing sorted Probabilities (Decreasing order) : \n\n" ;
    cout << " Letter\t Frequency \t\tLetter\t Frequency" << endl ;
    for(int i=0 ; i<13 ; i++){
		cout << "  " << s_txt[i] << "\t  " << s_prob[i] << "\t\t\t   " << s_txt[i+13] << "\t   " << s_prob[i+13] << endl ;
	}
	
	int km[26] , ks[26]  ;
	for(int i=1 ; i<26 ; i++)
		find_key(s_txt,s_text,km[i],ks[i],i);

	cout << "\n \n Keys obtained matching the letters with highest probability statistics(E,T,O) with the letters in the ciphertext having highest frequencies(C,B,P) : \n ";
	cout << " Multiplicative key = " << km[3] << "\t Shift key = " << ks[3] << endl << endl ;

float prob[26]={.082,.015,.028,.043,.127,.022,.020,.061,.07,.002,.008,.04,0.024,0.067,0.075,0.019,0.001,0.060,0.063,0.091,0.028,0.010,0.023,0.001,0.020,0.001};

	string cipher="KQEREJEBCPPCJCRKIEACUZBKRVPKRBCIBQCARBJCVFCUPKRIOFKPACUZQEPBKRXPEIIEABDKPBCPFCDCCAFIEABDKPBCPFEQPKAZBKRHAIBKAPCCIBURCCDKDCCJCIDFUIXPAFFERBICZDFKABICBBENEFCUPJCVKABPCYDCCDPKBCOCPERKIVKSCPICBRKIJPKABI";
	int stats[26];
	for(int i=0;i<26;i++){
		stats[i]=0;
	}
	int index;
	for(int i=0;i<cipher.size();i++){
		index=(cipher[i]-65);
		stats[index]+=1;
	}
	int high=stats[0];
	int pi=0;
	int psi=0;
	int hindex=0;
	int sindex=0;
	for(int i=1;i<26;i++){
		if(prob[i]>prob[pi]){
			psi=pi;
			pi=i;
		}
		if(prob[i]>prob[psi]&&prob[i]<prob[pi]){
			psi=i;
		}
		if(stats[i]>high){
			sindex=hindex;
			high=stats[i];
			hindex=i;
		}
		if(stats[i]>stats[sindex]&&stats[i]<stats[hindex]){
					sindex=i;
		}
	}


	int key1,key2;

	key1=(((hindex-sindex)*muli((pi-psi),26))%26+26)%26;
	key2=(((psi*hindex-sindex*pi)*muli((psi-pi),26))%26+26)%26;


	cout<<"\nDecrypted message for "<<key1<<" and "<<key2<<endl;
	cout<<decryptCipher("KQEREJEBCPPCJCRKIEACUZBKRVPKRBCIBQCARBJCVFCUPKRIOFKPACUZQEPBKRXPEIIEABDKPBCPFCDCCAFIEABDKPBCPFEQPKAZBKRHAIBKAPCCIBURCCDKDCCJCIDFUIXPAFFERBICZDFKABICBBENEFCUPJCVKABPCYDCCDPKBCOCPERKIVKSCPICBRKIJPKABI",key1,key2);

	
	
	
	getch();
	return 0 ;
}
