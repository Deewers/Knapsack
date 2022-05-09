#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;



int main()
{
    string buf;

    cout << "Knapsack problem!" << endl;

    //ofstream fout;
   // fout.open("ks_19_0");

    ifstream file("data/ks_100_0");
    getline(file, buf);
    cout << buf << endl;
}
