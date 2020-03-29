/**
 * EJERCICIO DEL FONTANERO
 * RODRIGO QUIROZ REYES - A01026546
 * 27/04/2020
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <tuple>

using namespace std;

void mostrarSatisfacion(vector <tuple<int,int,int>> & obj) {
    cout<<"TABLA DE SATISFACCIÓN DE CLIENTES"<<endl;
    cout<<"No. Cliente"<<"   "<<"Tiempo de Espera(min)"<<"    " << "Satisfacción"<<endl;
    string satisfaccion="a";
    for(int i=0; i<obj.size(); i++) {
         if(get<2>(obj[i])==1){
             satisfaccion="ALTA";
         }else if(get<2>(obj[i])==2){
             satisfaccion="MEDIA";
         }else if(get<2>(obj[i])==3){
             satisfaccion="BAJA";
         }
        cout<<"     "<<get<0>(obj[i])<<"                "<<get<1>(obj[i])<<"                 "<<satisfaccion<<endl;
    }
}

// El muestreo de las órdenes del fontanero del día
void mostrar(vector <tuple<int,int,int>> & obj) {
    cout<<"TABLA DE PENDIENTES DEL FONTANERO"<<endl;
    cout<<"No. Cliente"<<"   "<<"Tiempo de Reparación"<<endl;

    for(int i=0; i<obj.size(); i++) {
        cout<<"     "<<get<0>(obj[i])<<"                "<<get<1>(obj[i])<<endl;
    }
    cout<<endl;
}


bool sortbysec(const tuple<int, int, int>& a,  
               const tuple<int, int, int>& b) 
{ 
    return (get<1>(a) < get<1>(b)); 
} 

//Método tanto para calcular los tiempos de reparación como para indicar la stisfacción del cliente (1-Satisfecho, 2- Medianamente Satisfecho y 3 No Satisfecho)
void atencionCliente(vector <tuple<int,int,int>> & obj,int size) {
    int tiempoTranscurrido=0;
    float incrementoTasa=1.5;
    float comparacion=0;

    vector <tuple<int,int,int>> temp = obj;

    for(int i=0;i<size;i++){
        tiempoTranscurrido+=get<1>(obj[i]);
        get<1>(temp[i])=tiempoTranscurrido;
        
        if(tiempoTranscurrido-5<=(get<1>(obj[i])*incrementoTasa)){
            get<2>(temp[i])=1;            
        } else if(tiempoTranscurrido-20<=(get<1>(obj[i])*incrementoTasa)){
           get<2>(temp[i])=2;
        } else{
            get<2>(temp[i])=3;
        }

        if(i+1>=size){
            break;
        }

        if(get<1>(obj[i+1])>20){
            incrementoTasa+=.3;               
        } else if(get<1>(obj[i+1])>15){
            incrementoTasa+=.2;               
        } else if(get<1>(obj[i+1])>10){
            incrementoTasa+=.1;
        }              
        
    }
        mostrarSatisfacion(temp);
}



int main(){
    int noClientes = 5;
    //No. de cliente , tiempo de reparación
    vector <tuple<int,int,int>> clientes; 

    for(int i=0; i<noClientes; i++) {
        clientes.push_back(make_tuple(i+1,(rand()%30)+1,0));
    }

    mostrar(clientes);

    sort(clientes.begin(),clientes.end(),sortbysec);

    atencionCliente(clientes,noClientes);


}