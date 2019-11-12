#include <iostream>

using namespace std;

void seRepite(string cadena)
{
    int indice = 0;
    int n = cadena.size();
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < i; j++)
            if (cadena[i] == cadena[j])
            {
                cadena[i] = (char)95;
                break;
            }
        if (j == i)
            cadena[indice++] = cadena[i];
        cout << cadena[i];
    }
}

int main()
{
    seRepite("universidad blas pascal");
    return 0;
}