#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;


int main()
{

    cout << "Knapsack problem!" << endl;


    string buff; // буфер промежуточного хранения считываемого из файла текста
        ifstream fin("/Users/nikpav/Desktop/c++/Yandex/Yandex/fki/fki/fki 2kurs/knapsback/knapsback/ks_19_0"); // открыли файл для чтения
     
        fin >> buff; // считали первое слово из файла
        cout << buff << endl; // напечатали это слово
     



    return 0;
}
