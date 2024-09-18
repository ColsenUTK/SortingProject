#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// this script just generates testing files with different numbers of random ints. 
// It also generates a sorted version of that file. 


void gen_sorted(string input, string output, int N);
void gen_random(string output, int N);

int main (int argc, char *argv[]) {
    int N = stoi(argv[1]);

    // cout << "Num Elements:  ";
    // cin >> N;

    string inputFilename = "input_lists/input" + to_string(N);
    string outputFilename = "sorted_lists/sorted" + to_string(N);

    gen_random(inputFilename, N);
    gen_sorted(inputFilename, outputFilename, N);
    
    return 0;

}

void gen_sorted(string input, string output, int N) {

    ifstream fin(input);
    ofstream fout(output);
    string line;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        getline(fin, line);
        arr[i] = stoi(line);
    }

    sort(arr.begin(), arr.end()); 

    for (int i = 0; i < N; i++) {
        fout << arr[i];
        if (i < N-1)
            fout << '\n';
    }

}

void gen_random(string output, int N) {
    
    ofstream fout(output);

    srand(time(0));

    for (int i = 0; i < N; i++) {
        fout << (rand() % (10*N - 0 + 1)) + 0;
        if (i < N - 1)
            fout << '\n';
    }

}
