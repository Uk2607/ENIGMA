#include<iostream>

using namespace std;

int firstCompleteMismatchedString(string enc, string str) {
    if(enc.length()<=str.length()) return -1;
    for(int i=0;i<=enc.length()-str.length();i++) {
        bool flag = true;
        for(int j=0;j<str.length();j++) {
            if(enc[i+j] == str[j]) {
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
}

int main() {
    // Bombe machine
    // cout<<"Enter encrypted strng: ";
    string enc = "ORYMBXBKKHTMKTB";
    // cin>>enc;
    // cout<<"Enter the known part of the decrypted string: ";
    string known_str = "NAMEIS";
    // cin>>known_str;

    int idx = firstCompleteMismatchedString(enc, known_str);
    if(idx == -1) {
        cout<<"Invalid known string\n";
        return 0;
    } else {
        cout<<idx;
    }

    return 0;
}