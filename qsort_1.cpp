#include <iostream>  // serve per includere le definizioni della libreria
#include <cmath>
#include <iomanip>

// bubble sort

using namespace std;  // permette di usare gli oggetti e le funzioni 

template <class X>
void qsort(X * array , int ini , int fin,int (*cmp)(X& ,X &));// dichiarazione: e' prima di main
template <class X>  
void stampa(X dati[], int ini , int fin);

template <class X>  
int compara_numeri(X & a,X & b) // ><=0 a segìconda che a>b a>b a==b
 {if (a-b > 0) return 1;
  if (a-b < 0) return -1;
  return 0;
  }

int main()
  {
  double  lista[]={33, 4.5, 2, 5., 6,23.8,43,88, 9, 5,34,23,33,55};
  // dim array :  dimensione in bytes dell'array / dimensione dell'elemento
  qsort (lista, 0,sizeof(lista) / sizeof(lista[0]) -1 , compara_numeri); // dim dell'array
  stampa(lista,0,sizeof(lista) / sizeof(lista[0] ) -1 );
  
  }
template <class X>  
void stampa(X dati[], int ini , int fin)
  {
  for (int i=0;i<=fin;i++)
    {
    cout << setw(6);
    if (i>=ini)   cout<< dati[i]; else cout<< "";
    }
  cout << endl;
  }  

template <class X>
void qsort(X * array , int ini , int fin,int (*cmp)(X& ,X &))
  {
  X pivot; X temp;
  int temp_ini,temp_fin;
  temp_ini=ini;temp_fin=fin;
  pivot= array[ (temp_ini+temp_fin) /2 ] ; // valore a meta'
  //printf("pivot: %d  ini: %d  fin: %d\n",pivot,temp_ini,temp_fin);
  stampa(array,ini,fin) ; 
  while (temp_ini <= temp_fin)
    {
    while (cmp( array[temp_ini] , pivot)<0   && temp_ini < fin )   // array[temp_ini] < pivot 
      temp_ini++;
    while (cmp( pivot , array[temp_fin])<0   && temp_fin >ini  )
      temp_fin--;
    if (temp_ini <= temp_fin)
      {
      temp=array[temp_ini];
      array[temp_ini]=array[temp_fin];
      array[temp_fin]=temp;
      temp_ini++;
      temp_fin--;
      }
      
    }
    stampa(array,ini,fin) ; 
    //printf("%5d %5d\n",temp_ini,temp_fin);
    //return;
    printf("   blocco1: %d-%d  blocco2: %d-%d\n",ini,temp_fin,temp_ini,fin);
    //if (temp_fin<temp_ini) 
    if (ini < temp_fin ) qsort(array,ini,temp_fin,cmp);  
    if (temp_ini < fin ) qsort(array,temp_ini,fin,cmp);  
    //stampa(array,ini,fin) ; 
    }
      
      
