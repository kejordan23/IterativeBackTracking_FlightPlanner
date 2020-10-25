#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    ofstream output;
    ifstream input1;
    ifstream input2;
    input1.open(argv[1]);
    input2.open(argv[2]);
    output.open(argv[3]);
    if (!output.is_open() || !input1.is_open() || !input2.is_open())
        cout << "unable to open file" << endl;
    output<<"Hello World!"<<endl;
    return 0;
}

