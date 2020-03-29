/**
 * EJERCICIO DE LA MOCHILA
 * RODRIGO QUIROZ REYES - A01026546
 * 27/04/2020
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

//Ordeno los elementos conforme a su densidad del beneficio
void ordenar(vector <pair<float,float> > & obj) {
    int j;
    pair<float,float> temp;
    for(int i=1; i<obj.size(); i++) {
        temp=obj[i];
        j=i-1;
        while((obj[j].first/obj[j].second<temp.first/temp.second) && (j>=0) ) {
            obj[j+1]=obj[j];
            j--;
        }
        obj[j+1]=temp;

    }
}

vector <pair<float,float> > genera(int n) {
    vector <pair<float,float> > obj(n);

    for(int i=0; i<n; i++) {
        obj[i].first=(rand()%75)+1;
        obj[i].second=(rand()%75)+1;
    }
    return obj;
}

bool sortrev(const pair<int,int> &a,  const pair<int,int> &b) 
{ 
  return (a.first > b.first); 
}


void mostrar(vector <pair<float,float> > & obj) {
    cout<<"BENEFICIO"<<"   "<<"PESO"<<endl;

    for(int i=0; i<obj.size(); i++) {
        cout<<"   "<<obj[i].first<<"        "<<obj[i].second<<endl;
    }
    cout<<endl;
}


vector <pair<float,float> >  mochila(vector <pair<float,float> > & objetos ,int mochilaSize) {
    vector <pair<float,float> >  s;
    float pesoRestante=mochilaSize;
    int i=0;
    while(objetos[i].second<=pesoRestante) {
        s.push_back(objetos[i]);
        pesoRestante-=objetos[i].second;
        i++;
    }

    return s;
}


int main() {
    
    int n = 10;
    int mochilaSize=200;
    //Beneficio , Peso
    vector <pair<float,float> > objetos; 

    objetos=genera(n);
    ordenar(objetos);
    cout<<"Objetos genereados de manera random"<<endl;
    mostrar(objetos);

    vector <pair<float,float> >  objetosEnMochila;
    objetosEnMochila=mochila(objetos,mochilaSize);
    cout<<"Objetos seleccionados"<<endl;
    mostrar(objetosEnMochila);

    return 0;
}