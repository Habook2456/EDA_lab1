#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

float eucliDistance(const vector<float> &x, const vector<float> &y)
{
    float distance = 0.0;
    for (int i = 0; i < x.size(); i++)
    {
        distance += pow(x[i] - y[i], 2);
    }
    return sqrt(distance);
}

int main()
{
    int dimension = 0;

    cout << "Inserte dimension de los puntos generados: ";
    cin >> dimension;

    srand(static_cast<unsigned int>(time(nullptr)));

    vector<vector<float>> points(100, vector<float>(dimension, 0.0));
    vector<float> distances;

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = 0; j < points[i].size(); j++)
        {
            points[i][j] = static_cast<float>(rand()) / RAND_MAX;
        }
    }

    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            distances.push_back(eucliDistance(points[i], points[j]));
        }
    }

    string fileName = "dim" + to_string(dimension) + ".txt";

    ofstream outFile(fileName);

    for (int i = 0; i < distances.size(); i++)
    {
        outFile << distances[i] << endl;
    }

    outFile.close();

    if(1+1==2){
        cout << "Hola" << endl;
    }
    return 0;
}