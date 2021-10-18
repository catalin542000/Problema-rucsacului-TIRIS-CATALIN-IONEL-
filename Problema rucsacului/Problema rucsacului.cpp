#include "pch.h"
#include <fstream>
using namespace std;

ifstream in("rucsacin.txt");
ofstream out("rucsacout.txt");

int main()
{

    int n, i, t, sortat;
    float c[101], g[101], e[101], C, Gmax, p;
    int nr[101];
    in >> n >> Gmax;
    for (i = 1; i <= n; i++)
        in >> g[i];
    for (i = 1; i <= n; i++)
        in >> c[i];
    for (i = 1; i <= n; i++)
    {
        e[i] = c[i] / g[i];
        nr[i] = i;
    }
    do
    {
        sortat = 0;
        for (i = 1; i < n; i++)
            if (e[i] < e[i + 1])
            {
                t = g[i]; g[i] = g[i + 1]; g[i + 1] = t;
                t = c[i]; c[i] = c[i + 1]; c[i + 1] = t;
                t = e[i]; e[i] = e[i + 1]; e[i + 1] = t;
                t = nr[i]; nr[i] = nr[i + 1]; nr[i + 1] = t;
                sortat = 1;
            }
    } while (sortat == 1);

    C = 0; i = 1;
    while (Gmax > 0 && i <= n)
    {
        if (g[i] <= Gmax)
        {
            out << nr[i] << ' ' << 1 << '\n';
            Gmax = Gmax - g[i];
            C = C + c[i];
        }
        else
        {
            p = Gmax / g[i];
            out << nr[i] << ' ' << p << '\n';
            C = C + c[i] * p;
            Gmax = 0;
        }
        i++;
    }
    out << C;
    in.close();
    out.close();
    return 0;
}