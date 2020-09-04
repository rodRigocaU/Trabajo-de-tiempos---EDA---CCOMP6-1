#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <math.h>
using namespace std;

double diste(vector<int> a, vector<int> b)
{
    int sum = 0;
    for(int i = 0; i < a.size(); i++)
    {
        sum += pow(a[i] - b[i],2);
    }
    return sqrt(sum);

}


int main()
{
    srand(time(NULL));
    /*LAS VARIABLES QUE USAREMOS PARA IDENTIFICAR LAS DIMENSIONES Y EL TAMAÑO DEL ARRAY*/
    int tam = 25000;
    int dimen = 20;
    /**/
    vector<vector<int>> arr1;
    vector<int> aux;

    
    for(int i = 0; i < tam;i++)
    {
        for (int j = 0; j < dimen; j++)
        {
            aux.push_back(rand()%1000 + 1);
        }
        arr1.push_back(aux);
        aux.clear();
    }
    
    /*PRUEBA DE TIEMPO*/
    unsigned t0, t1;
    t0=clock();

    for(int i = 0; i < tam;i++)
    {
        for ( int j = 0; j < tam; j++)
        {
            diste(arr1[i], arr1[j]);
        } 
    }    

    t1 = clock();
    
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "El tiempo con " << tam << " y " << dimen << " dimensiones: " << time << endl;

    arr1.clear();
    aux.clear();




    return 0;
}
