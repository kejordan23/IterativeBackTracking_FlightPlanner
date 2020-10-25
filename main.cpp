#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    ofstream output;
    output.open(argv[3]);
    if (!output.is_open())
        cout << "unable to open file" << endl;
    output<<"Hello World!"<<endl;
    return 0;
}

