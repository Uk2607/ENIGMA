#include<iostream>
#include<vector>
#include<string>
#include<assert.h>

using namespace std;

const int N = 26;

void showPlugBoard(vector<int>&plug_board) {
    cout<<"Plugboard Configuration::\n";
    for(int i=0;i<N;i++) {
        cout<<"[["<<(char)(i+'a')<<" <-> "<<(char)(plug_board[i]+'a')<<"]] ";
        if((i+1)%7==0) cout<<"\n";
    } cout<<"\n\n";
}

void showRotorState(int r1idx, int r2idx, int r3idx, vector<pair<int, int>>&rotor1, vector<pair<int, int>>&rotor2, vector<pair<int, int>>&rotor3) {
    cout<<"Rotor #1 Configuration with current index <"<<r1idx<<"> ::\n";
    for(int i=0;i<N;i++) {
        cout<<"[["<<(char)(i+'a')<<" <-> "<<(char)(rotor1[i].first+'a')<<"],["<<(char)(i+'a')<<" <-> "<<(char)(rotor1[i].second+'a')<<"]] ";
        if((i+1)%4==0) cout<<"\n";
    } cout<<"\n\n";
    cout<<"Rotor #2 Configuration with current index <"<<r2idx<<"> ::\n";
    for(int i=0;i<N;i++) {
        cout<<"[["<<(char)(i+'a')<<" <-> "<<(char)(rotor2[i].first+'a')<<"],["<<(char)(i+'a')<<" <-> "<<(char)(rotor2[i].second+'a')<<"]] ";
        if((i+1)%4==0) cout<<"\n";
    } cout<<"\n\n";
    cout<<"Rotor #3 Configuration with current index <"<<r3idx<<"> ::\n";
    for(int i=0;i<N;i++) {
        cout<<"[["<<(char)(i+'a')<<" <-> "<<(char)(rotor3[i].first+'a')<<"],["<<(char)(i+'a')<<" <-> "<<(char)(rotor3[i].second+'a')<<"]] ";
        if((i+1)%4==0) cout<<"\n";
    } cout<<"\n\n";
}

char encodeFromPlugBoard(char c, vector<int>&plugboard) {
    return (char)(plugboard[c-'a']+'a');
}

vector<int> createPlugBoard() {
    vector<int>plugboard(N);
    for(int i=0;i<N;i++) plugboard[i] = i;
    vector<bool>v(N, false);
    vector<int>idxs;
    int cnt = 0;
    while(cnt<20) {
        int r = rand()%26;
        if(!v[r]) {
            cnt++;
            idxs.push_back(r);
            v[r] = true;
        }
    }
    for(int i=0;i<idxs.size();i+=2) {
        plugboard[idxs[i]] = idxs[i+1];
        plugboard[idxs[i+1]] = idxs[i];
    }
    return plugboard;
}

vector<pair<int, int>> createRotor() {
    vector<pair<int, int>>rotor(N);
    vector<bool>v(N, false);
    int cnt = 0;
    while(cnt<N) {
        int r = rand()%26;
        if(!v[r]) {
            rotor[cnt].first = r;
            rotor[r].second = cnt;
            cnt++;
            v[r] = true;
        }
    }
    return rotor;
}

void rotateRotor(vector<pair<int, int>>&rotor) {
    int t = rotor[N-1].first;
    for(int i=N-1;i>0;i--)
        rotor[i].first = rotor[i-1].first;
    rotor[0].first = t;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(rotor[j].first == i) {
                rotor[i].second = j;
                break;
            }
        }
    }
}

char encodeFromRotors(char c, vector<pair<int, int>>&rotor1, vector<pair<int, int>>&rotor2, vector<pair<int, int>>&rotor3, int &r1idx, int &r2idx, int &r3idx) {
    r1idx = (r1idx+1)%N;
    rotateRotor(rotor1);
    if(r1idx == 0) {
        r2idx = (r2idx+1)%N;
        rotateRotor(rotor2);
    }
    if(r2idx == 0) {
        r3idx = (r3idx+1)%N;
        rotateRotor(rotor1);
    }
    c = rotor1[c-'a'].first + 'a';
    c = rotor2[c-'a'].first + 'a';
    c = rotor3[c-'a'].first + 'a';
    c = (25-(c-'a'))+'a'; // Reflector we can made custom reflector
    c = rotor3[c-'a'].second + 'a';
    c = rotor2[c-'a'].second + 'a';
    c = rotor1[c-'a'].second + 'a';
    return c;
}

char codeChar(char c, vector<int>&plug_board, vector<pair<int, int>>&rotor1, vector<pair<int, int>>&rotor2, vector<pair<int, int>>&rotor3, int &r1idx, int &r2idx, int &r3idx) {
    c = encodeFromPlugBoard(c, plug_board);
    c = encodeFromRotors(c, rotor1, rotor2, rotor3, r1idx, r2idx, r3idx);
    c = encodeFromPlugBoard(c, plug_board);
    return c;
}

string runEnigma(string str, vector<int>&plug_board, vector<pair<int, int>>rotor1, vector<pair<int, int>>rotor2, vector<pair<int, int>>rotor3, int r1idx, int r2idx, int r3idx) {
    string enc = "";
    for(char c: str) enc+=codeChar(tolower(c), plug_board, rotor1, rotor2, rotor3, r1idx, r2idx, r3idx);
    return enc;
}

int main() {
    srand(time(0));
    vector<int>plug_board = createPlugBoard();
    vector<pair<int,int>>rotor1 = createRotor();
    vector<pair<int,int>>rotor2 = createRotor();
    vector<pair<int,int>>rotor3 = createRotor();
    int r1idx = rand()%26, r2idx = rand()%26, r3idx = rand()%26;
    showPlugBoard(plug_board);
    showRotorState(r1idx, r2idx, r3idx, rotor1, rotor2, rotor3);
    cout<<"Enter your string:: ";
    string ip;
    cin>>ip;
    string enc = runEnigma(ip, plug_board, rotor1, rotor2, rotor3, r1idx, r2idx, r3idx);
    cout<<"Encoded string:: "<<enc<<"\n";

    string dec = runEnigma(enc, plug_board, rotor1, rotor2, rotor3, r1idx, r2idx, r3idx);
    cout<<"Decoded string:: "<<dec<<"\n";

    assert(ip == dec);
    return 0;
}