#include<iostream>
#include<fstream>

using namespace std;

int firstCompleteMismatchedString(string enc, string str) {
    int idx = -1;
    for(int i=0;i<=enc.length()-str.length();i++) {
        bool flag = true;
        for(int j=0;j<str.length();j++) {
            if(enc[i+j] == str[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(idx!=-1) return -1;
            idx = i;
        }
    }
    return idx;
}

int main() {
    // Bombe machine
    ifstream fin("encoded.txt");
    string enc;
    fin>>enc;
    cout<<enc<<"\n";
    enc = "OMYYGNRNONEOXFD";

    // cout<<"Enter the known part of the decrypted string: ";
    string known_str = "NAMEIS";
    // cin>>known_str;

    if(enc.length()<20 || known_str.length()<10) {
        cout<<"Length of string is very small.\n";
        return 0;
    } else if(enc.length()<=known_str.length()) {
        cout<<"Known string is longer than encoded string.\n";
        return 0;
    }
    int idx = firstCompleteMismatchedString(enc, known_str);
    if(idx == -1) {
        cout<<"Multiple matches for mismatch string.\n";
        return 0;
    } else {
        cout<<idx<<"\n";
    }

    return 0;
}