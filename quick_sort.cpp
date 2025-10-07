#include <iostream>
using namespace std;
const int MAX=100;
int v[100];

int Partitionare(int st, int dr)
{
    int i=0, j=-1;
    while(st<dr)
    {
        if(v[st]>v[dr])
        {
            swap(v[st],v[dr]);
            int k=i;
            i=-j;
            j=-k;
        }
        st+=i; dr+=j;
    }
    return st;
}

void Qsort(int st, int dr)
{
    if(st<dr)
    {
        int p=Partitionare(st,dr);
        Qsort(st,p-1);
        Qsort(p+1,dr);
    }
}

int main()
{
    int n;
    cout << "Introduceti numarul de elemente din vector";
    cin>>n;
    cout << "Introduceti elementele vectorului: ";
    for(int i=0; i<n; i++)
        cin>>v[i];
    Qsort(0,n-1);
    cout << "Acesta este vectorul sortat:\n";
    for(int i=0; i<n; i++)
        cout<<v[i]<<' ';
}
