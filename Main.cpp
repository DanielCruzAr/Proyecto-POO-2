/*
Daniel Cruz Arciniega
A01701370

Trascend
Trascend es un grupo estudiantil que estoy planeando junto con otros compañeros.
Es un grupo enfocado en actividades al aire libre y tematicas como la superacion
personal y la inteligencia emocional.
El grupo está actualmente activo, sin embargo el TEC no lo reconocerá como tal hasta
febrero del año entrante.
Mi programa enseña toda la estructura del grupo e informacion del mismo.
*/
#include<iostream>
#include<stdio.h>
#include "Miembro.h"
#include "trascend.h"

using namespace std;

void menu(){
 cout <<"\n";
 cout << "Opcion 1: agregar fondos \n";
 cout << "Opcion 2: ver integrantes de transcend por tipo \n";
 cout << "Opcion 3: agregar integrante de mesa \n";
 cout << "Opcion 4: agregar integrante de comite tecnico \n";
 cout << "Opcion 5: agregar colaborador \n";
 cout << "Opcion 6: cambiar el cargo de mesa de una persona \n";
 cout << "Opcion 7: cambiar el cargo de comite tecnico de una persona \n";
 cout << "Opcion 8: cambiar el nivel de colaborador de una persona \n";
 cout << "Opcion 9: ver informacion de mesa, comite tecnico y colaboradores \n";
 cout << "Opcion 10: salir \n"; cout << "NOTA: 6,7 y 8 estan temporalmente deshabilitados \n";
}

int main(){
   Trascend trascend; //Se construye el objeto trascend con valores por default
   //Ejemplo de miembro de mesa
   cout << "\n ¿Quiénes somos?"; trascend.informacion();
   cout << "\n Misión del grupo"; trascend.mision();
   cout << "\n Visión del grupo"; trascend.vision();
   cout << "\n Fondos: " << trascend.getFondos() << endl;

   /*El grupo ya cuenta con miembros en la mesa directiva y en el comite tecnico
   por lo que la lista se llena automaticamente con los miembros existentes*/
   trascend.llenaMiembros();

   int opcion=0;
   float fond;
   string nom,apellido,mat,carg,member,tm;
   string lvl="C"; //Todos empiezan en el nivel C;

   while(opcion <7 && opcion >-1){
      menu();
      cin >> opcion;

      switch(opcion){

         case 1:
             cout << "Introduce cantidad que desee agregar " << endl;
             cin >> fond;
             trascend.agregaFondos(fond);
             cout << "Los fondos ahora son $" << trascend.getFondos() << endl;
             break;

         case 2:
             cout << "Introduce el tipo de miembro (mesa ,CT o colaborador) \n";
             cin >> member;
             cout << "NOMBRE|MATRICULA|CARGO o NIVEL" << endl;
             trascend.printMiembro(member);
             break;

         case 3:
             tm="mesa";
             cout << "Introduce los datos de la persona";
             cout <<"\n Nombre: "; cin >> nom;
             cout <<"\n Apellido: "; cin >> apellido;
             cout << "\n Matricula: "; cin >> mat;
             cout << "\n Cargo de mesa: "; cin >> carg;
             nom=nom+" "+apellido;
             trascend.agregaMesa(nom,mat,tm,carg);
             cout << "Se ha registrado un nuevo miembro de mesa \n";
             break;

        case 4:
             tm="CT";
             cout << "Introduce los datos de la persona";
             cout <<"\n Nombre: "; cin >> nom;
             cout <<"\n Apellido: "; cin >> apellido;
             cout << "\n Matricula: "; cin >> mat;
             cout << "\n Cargo de comite tecnico: "; cin >> carg;
             nom=nom+" "+apellido;
             trascend.agregaCT(nom,mat,tm,carg);
             cout << "Se ha registrado un nuevo miembro del comite tecnico \n";
             break;

        case 5:
             tm="colaborador";
             cout << "Introduce los datos de la persona";
             cout <<"\n Nombre: "; cin >> nom;
             cout <<"\n Apellido: "; cin >> apellido;
             cout << "\n Matricula: "; cin >> mat;
             nom=nom+" "+apellido;
             trascend.agregaColaborador(nom,mat,tm,lvl);
             cout << "Se ha registrado un nuevo colaborador \n";
             break;
        /* Funciones suspendidas temporalmente
        case 6:
            cout << "Introduce la matricula de la persona a la que se le quiera cambiar el cargo \n";
            cin >> mat;
            if(trascend.cambiaCargoM(mat)==false){
                cout << "Persona no encontrada \n";
            }
            break;

        case 7:
            cout << "Introduce la matricula de la persona a la que se le quiera cambiar el cargo \n";
            cin >> mat;
            if(trascend.cambiaCargoCT(mat)==false){
                cout << "Persona no encontrada \n";
            }
            break;

        case 8:
            cout << "Introduce la matricula del colaborador al que se le quiere cambiar el nivel \n";
            cin >> mat;
            if(trascend.cambiaNivelCol(mat)==false){
                cout << "Colaborador no encontrado \n";
            }
            break;
            */

        case 6:
            cout << "MESA";
            trascend.infoMesa();
            cout << "COMITE TECNICO";
            trascend.infoCT();
            cout << "COLABORADORES";
            trascend.infoCol();
            break;
      }
   }
   trascend.borra(); //eliminar los objetos creados para que no afecten en la memoria
return 0;
}
