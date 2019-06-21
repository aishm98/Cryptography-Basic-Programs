#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<conio.h>

using namespace std;

char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
char subs[16] = {'E', '4', 'D', '1', '2', 'F', 'B', '8', '3', 'A', '6', 'C', '5', '9', '0', '7'};
char invSubs[16] = {'E', '3', '4', '8', '1', 'C', 'A', 'F', '7', 'D', '9', '6', 'B', '2', '0', '5'};
int perm[8] = {0, 3, 4, 6, 2, 5, 1, 7};
int invPerm[8] = {0, 6, 4, 1, 2, 5, 3, 7};

string generate(int n) {
    string res = "";
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int p = rand() % 16;
        res += hexa[p];
    }
    cout<<"\nRandom 24 bit key : "<<res<<endl;;
    return res;
}

string XOR(string x, string y) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        int a = lower_bound(hexa, hexa + 16, x[i]) - hexa;
        int b = lower_bound(hexa, hexa + 16, y[i]) - hexa;
        res += hexa[a ^ b];
    }
    cout<<"\nAfter XOR : "<<res;
    cout << "\n_________________________________" << endl ;
    return res;
}

string SBOX(string x) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        int c = lower_bound(hexa, hexa + 16, x[i]) - hexa;
        res += subs[c];
    }
    cout<<"\nAfter Substitution : "<<res;
    return res;
}

string PBOX(string x) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        res += x[perm[i]];
    }
    cout<<"\nAfter Permutation : "<<res;
    return res;
}

string encode(string plain, string key) {
    string cipher = plain;
    for (int r = 1; r <= 5; r++) {
    	cout<<"\nRound "<<r<<" key : ";
        string roundKey = "";
        for (int i = 4 * r - 3 - 1; i < 4 * r + 4; i++) {
            roundKey += key[i];
        }
        cout<<roundKey;
        cipher = XOR(cipher, roundKey);
        cipher = SBOX(cipher);
        if (r != 5) cipher = PBOX(cipher);
        cout<<endl;
    }
    return cipher;
}

string invPBOX(string x) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        res += x[invPerm[i]];
    }
    cout<<"\nAfter Permutation : "<<res;
    return res;
}

string invSBOX(string x) {
    int n = (int)x.length();
    string res = "";
    for (int i = 0; i < n; i++) {
        int c = lower_bound(hexa, hexa + 16, x[i]) - hexa;
        res += invSubs[c];
    }
    cout<<"\nAfter Substitution : "<<res;
    return res;
}

string decode(string cipher, string key) {
    string plain = cipher;
    for (int r = 5; r >= 1; r--) {
    	cout<<"\nRound "<<r<<" key : ";
        string roundKey = "";
        for (int i = 4 * r - 3 - 1; i < 4 * r + 4; i++) {
            roundKey += key[i];
        }
        cout<<roundKey;
        if (r != 5) plain = invPBOX(plain);
        plain = invSBOX(plain);
        plain = XOR(plain, roundKey);
        cout<<endl;
    }
    return plain;
}

int main() {
    string plain;
    
    cout<<"-----ENCRYPTION-----";
    cout << "\nEnter plain text:\t";
    cin >> plain;
    
    string key = generate(24);
    string cipher = encode(plain, key);
    cout << "\nEncrypted text is: " << cipher << "\n\n\t --x-- \n";
    
    cout<<"\n\n\n-----DECRYPTION-----\n";
    string decipher = decode(cipher, key);
    cout << "\nDecrypted text is: " << decipher << "\n";
        getch();
    return 0;

}
