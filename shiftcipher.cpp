/*
	Nama    : Rahma Batari
	NPM     : 140810180027
	Kelas   : A
	Program : Shift Cipher
*/

#include<iostream> 
#include<string.h>

using namespace std;

void enkripsi(){
    string plaintext, ciphertext;
    int i, k; char c;
    
    cout << "Masukan pesan atau plaintext : ";
    cin.ignore(); getline (cin, plaintext);
    cout << "Masukan jumlah pergeseran : "; cin >> k;
    ciphertext = " "; 
    
    for (i=0; i < plaintext.length(); i++) {
        c = plaintext[i];
        if (isalpha(c)) {
            c = toupper(c); 
            c = c - 65; 
            c = (c + k) % 26;
            c = c + 65;
        } ciphertext = ciphertext + c; 
    } cout << "ciphertext : " << ciphertext <<endl; 
}

void dekripsi(){
    string plaintext, ciphertext;
    int i, k; char c;
    
    cout << "Masukan ciphertext : ";
    cin.ignore(); getline (cin, ciphertext);
    cout << "Masukan jumlah pergeseran : "; cin >> k;
    plaintext = ""; 
    
    for (i=0; i<ciphertext.length(); i++) {
        c = ciphertext[i];
        if (isalpha(c)) {
            c = toupper(c); 
            c = c - 65; 
            if (c - k < 0) 
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65; 
            c = tolower(c); 
        } plaintext = plaintext + c; 
    } cout << "plaintext : " << plaintext <<endl; 
}

int main (){ 
    int pil;
    bool stop;
    stop = false;
    
    while (!stop) {
        cout << "Menu : " <<endl;
        cout << "1. Encryption " <<endl;
        cout << "2. Decryption " <<endl;
        cout << "3. Exit " <<endl;
        cout << "Choose menu : "; cin >> pil;
        switch(pil){
            case 1 : 
			enkripsi();
			break;
            case 2 : 
			dekripsi();
			break;
            case 3 : 
			stop = true;
			break;
        }
    }
}

