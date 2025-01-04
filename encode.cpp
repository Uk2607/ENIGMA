#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

const int N = 26;

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

vector<int> createRotor() {
    vector<int>rotor(N);
    vector<bool>v(N, false);
    int cnt = 0;
    while(cnt<N) {
        int r = rand()%26;
        if(!v[r]) {
            rotor[cnt] = r;
            cnt++;
            v[r] = true;
        }
    }
    return rotor;
}

int main() {
    srand(time(0));
    vector<int>plug_board_seq = createPlugBoard();
    vector<int>rotor1_seq = createRotor();
    vector<int>rotor2_seq = createRotor();
    vector<int>rotor3_seq = createRotor();

    int r1idx = rand()%26, r2idx = rand()%26, r3idx = rand()%26;

    ofstream file;
    file.open("mac_setting.txt");
    file<<"Plug Board:: ";
    for(int x: plug_board_seq) file<<(char)(x+'a'); file<<"\n";
    file<<"Rotor#1 <pos:"<<r1idx<<">:: ";
    for(int x: rotor1_seq) file<<(char)(x+'a'); file<<"\n";
    file<<"Rotor#2 <pos:"<<r2idx<<">:: ";
    for(int x: rotor2_seq) file<<(char)(x+'a'); file<<"\n";
    file<<"Rotor#3 <pos:"<<r3idx<<">:: ";
    for(int x: rotor3_seq) file<<(char)(x+'a'); file<<"\n";

    file.close();
    return 0;
}