#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

const int N = 26;
int r1idx, r2idx, r3idx;
vector<int>plug_board;
vector<pair<int,int>>rotor1, rotor2, rotor3;

vector<int> createPlugBoardSeq() {
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

vector<int> createRotorSeq() {
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

vector<pair<int,int>> createRotorMapping(vector<int>rotor_seq) {
    vector<pair<int,int>>rotor(N);
    for(int i=0;i<N;i++) {
        rotor[i].first = rotor_seq[i];
        rotor[rotor_seq[i]].second = i;
    }
    return rotor;
}

void encodeFromPlugBoard(char &c) {
    c = (char)(plug_board[c-'A']+'A');
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

void encodeFromRotors(char &c) {
    r1idx = (r1idx+1)%N;
    rotateRotor(rotor1);
    if(r1idx == 0) {
        r2idx = (r2idx+1)%N;
        rotateRotor(rotor2);
    }
    if(r2idx == 0) {
        r3idx = (r3idx+1)%N;
        rotateRotor(rotor3);
    }
    c = rotor1[c-'a'].first + 'a';
    c = rotor2[c-'a'].first + 'a';
    c = rotor3[c-'a'].first + 'a';
    c = (25-(c-'a'))+'a'; // Reflector we can made custom reflector
    c = rotor3[c-'a'].second + 'a';
    c = rotor2[c-'a'].second + 'a';
    c = rotor1[c-'a'].second + 'a';
}

char simulateEnigma(char c) {
    encodeFromPlugBoard(c);
    encodeFromRotors(c);
    encodeFromPlugBoard(c);
    return c;
}

string encodeString(string str) {
    string enc = "";
    for(char c: str) enc += simulateEnigma(c);
    return enc;
}

int main() {
    srand(time(0));
    vector<int>plug_board_seq = createPlugBoardSeq();
    vector<int>rotor1_seq = createRotorSeq();
    vector<int>rotor2_seq = createRotorSeq();
    vector<int>rotor3_seq = createRotorSeq();

    r1idx = rand()%26, r2idx = rand()%26, r3idx = rand()%26;

    ofstream file;
    file.open("mac_setting.txt");
    file<<"Plug Board:: ";
    for(int x: plug_board_seq) file<<(char)(x+'A'); file<<"\n";
    file<<"Rotor#1 <pos:"<<r1idx<<">:: ";
    for(int x: rotor1_seq) file<<(char)(x+'A'); file<<"\n";
    file<<"Rotor#2 <pos:"<<r2idx<<">:: ";
    for(int x: rotor2_seq) file<<(char)(x+'A'); file<<"\n";
    file<<"Rotor#3 <pos:"<<r3idx<<">:: ";
    for(int x: rotor3_seq) file<<(char)(x+'A'); file<<"\n";

    file.close();

    plug_board = plug_board_seq;
    rotor1 = createRotorMapping(rotor1_seq);
    rotor2 = createRotorMapping(rotor2_seq);
    rotor3 = createRotorMapping(rotor3_seq);

    cout<<"Enter your string without spaces: ";
    string ip, enc;
    cin>>ip;

    for(char &c: ip) c = toupper(c);

    enc = encodeString(ip);
    cout<<"Encoded string:: "<<enc<<"\n";

    return 0;
}