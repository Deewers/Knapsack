#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

vector < vector<int64_t> > matrix;
//vector<int64_t> line_prev;
//vector<int64_t> line;
vector<int64_t> w;
vector<bool> choosen;




set<int64_t> knapsack(int64_t i, int64_t j)
{

    if (i==0)
    {
        set<int64_t> res;
        return res;
    }

    if (matrix[i][j] > matrix[i-1][j]) //(line[j] > line_prev[j])
    {
        set<int64_t> res1;
        res1 = knapsack(i-1, j - w[i]);
        res1.insert(i);
        return res1;
    }
    else
    {
        set<int64_t>res2;
        res2 = knapsack(i-1, j);
        return res2;
    }

}



int main()
{
    string buf;

    cout << "Knapsack problem!" << endl;


    ifstream file("data/ks_1000_0");
    getline(file, buf);

    int i_space = buf.find(' ');
    int64_t N = stoi(buf.substr(0, i_space));
    int64_t K = stoi(buf.substr(i_space+1));

    cout << "N=" << N << ", K=" << K << endl;

    vector<int64_t> v(N);

    w.resize(N);
    choosen.resize(N, false);

    for (int64_t i=0; i < N; i++)
    {
        getline(file, buf);
        i_space = buf.find(' ');
        v[i] = stoi(buf.substr(0, i_space));
        w[i] = stoi(buf.substr(i_space+1));
    }




    file.close();


    /////////////////////

    matrix.resize(N, vector<int64_t>(K+1,0));
    //line_prev.resize(K+1, 0);
    //line.resize(K+1, 0);


    for (int64_t i=1; i<N; i++)
    {
        for (int64_t j=0; j<K+1; j++)
        {

            if (w[i] > j)
                matrix[i][j] = matrix[i-1][j]; //line[j] = line_prev[j];

            else
                matrix[i][j] = max(matrix[i-1][j], matrix[i-1][j-w[i]] + v[i]);
                //line[j] = max(line_prev[j], line_prev[j-w[i]]+v[i]);

        }
        //for (int64_t j=0; j<K+1; j++)
        //    line_prev[j] = line[j];


    }

    cout << "matrix M has been formed" << endl;


    int k = K;
    for (int i=N-1; i>0; i--)
        if (matrix[i][k] != matrix[i-1][k])
        {
            choosen[i] = true;
            k -= w[i];

        }



    cout << matrix[N-1][K] << "\t" << k  << endl;


    for (int i=0; i<N; i++)
        cout << choosen[i] << " ";
    cout << endl;



    return 0;
}
