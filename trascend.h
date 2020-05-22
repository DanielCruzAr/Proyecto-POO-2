#ifndef TRASCEND_H
#define TRASCEND_H
#include <iostream>
#include "Miembro.h"

using namespace std;

const int CUPO=50;

class Trascend{
  private:

    Mesa m[CUPO];
    ComiteTecnico ct[CUPO];
    Colaboradores col[CUPO];

    int nMesa,nCT,nCol;
    float fondos;

  public:
    Trascend(); //por default

    //getters de las variables privadas
    float getFondos();

    void printMesa();
    void printCT();
    void printColaboradores();

    void llenaMesa();
    void llenaCT();
    void llenaCol();

    //Informacion del grupo
    void informacion();
    void mision();
    void vision();
    void infoMesa();
    void infoCT();
    void infoCol();

    //Metodos
    void agregaMesa(string,string,string);
    void agregaCT(string,string,string);
    void agregaColaborador(string,string,string);
    void agregaFondos(float);
    bool cambiaCargoM(string);
    bool cambiaCargoCT(string);
    bool cambiaNivelCol(string);

};

Trascend::Trascend(){
 nMesa=0;
 nCT=0;
 nCol=0;

 fondos=0;

}

void Trascend::llenaMesa(){

  m[0]= Mesa("Carlos Sanchez","A01702188","presidente");
  nMesa++;
  m[1]= Mesa("Rafael Romo","A01701493","vicepresidente");
  nMesa++;
  m[2]= Mesa("Alejandra Lopez","A01702071","tesoreria");
  nMesa++;
  m[3]= Mesa("Romina Gramlich","A01701313","publicidad");
  nMesa++;
  m[4]= Mesa("Daniel Cruz","A01701370","patrocinios");
  nMesa++;

}

void Trascend::llenaCT(){

 ct[0]=ComiteTecnico("Emilio Valdez","A01704832","cursos");
 nCT++;
 ct[1]=ComiteTecnico("Balam Bravo","A01703834","cursos");
 nCT++;

}

void Trascend::llenaCol(){

 col[0]=Colaboradores("Juan Pérez","A00000000","C");
 nCol++;

}

float Trascend::getFondos(){
  return fondos;
}

void Trascend::printMesa(){
  for(int i=0;i<nMesa;i++){
    cout << m[i].strMesa() << endl;
  }
}

void Trascend::printCT(){
  for(int i=0;i<nCT;i++){
    cout << ct[i].strComTec() << endl;
  }
}

void Trascend::printColaboradores(){
  for(int i=0;i<nCol;i++){
    cout << col[i].strColaborador() << endl;
  }
}

void Trascend::informacion(){
 cout << "\n Somos un grupo estudiantil con el propósito de";
 cout << "\n fomentar el balance en las 7 dimensiones que conforman";
 cout << "\n a la persona (Físico, Emocional, Social, Espiritual e Intelectual)";
 cout << "\n para así, alcanzar la autorrealización y libertad personal.";
 cout << "\n Nuestro objetivo es potencializar las habilidades y facultades";
 cout << "\n de nuestros integrantes mediante pláticas, conferencias y actividades en contacto con la naturaleza;";
 cout << "\n para impulsarlos a desarrollar la mejor versión de sí mismos." << endl;
}

void Trascend::mision(){
 cout << "\n Inspirar a estudiantes del Tecnológico de Monterrey a potencializar sus habilidades de liderazgo,";
 cout << "\n inteligencia emocional y desarrollo integral como personas, mediante actividades que favorezcan";
 cout << "\n el crecimiento personal y profesional en contacto con la  naturaleza, con el fin de alcanzar la plenitud";
 cout << "\n y el bienestar integral." << endl;
}

void Trascend::vision(){
 cout << "\n Lograr ser un grupo estudiantil que esté presente en más de un campus y cuente con varios colaboradores.";
 cout << "\n Con el paso del tiempo, poder progresar a actividades de otro nivel con la experiencia adquirida en los cursos básicos.";
 cout << "\n A su vez, crear en el grupo una estructura funcional para que las generaciones futuras puedan continuarlo." <<endl;
}

//Informacion sobre la mesa, el comite tecnico y los colaboradores
void Trascend::infoMesa(){
 cout << "\n Encargados de la organización general del grupo,"
      << "\n administración de recursos, asignación de actividades,"
      << "\n organización de eventos, publicidad y difusión."
      << "\n Encargados de crear módulos para temas de inteligencia emocional.\n " << endl;
}

void Trascend::infoCT(){
 cout << "\n Comité conformado por personas especializadas en diversas"
      << "\n áreas al aire libre. Encargados de dar cursos básicos. \n"
      << endl;
}

void Trascend::infoCol(){
 cout << "\n Encargados de participar, contribuir y sumar al grupo de manera efectiva y responsable."
      << "\n Colaborar en vendimias, logística y difusión del grupo. \n" << endl;
}

void Trascend::agregaMesa(string nom,string mat,string carg){
    Mesa nuevaMesa(nom,mat,carg);
    m[nMesa]=nuevaMesa;
    nMesa++;
}


void Trascend::agregaCT(string nom,string mat,string carg){
    ComiteTecnico nuevoCT(nom,mat,carg);
    ct[nCT]=nuevoCT;
    nCT++;
}

void Trascend::agregaColaborador(string nom,string mat,string lvl){
    Colaboradores nuevoColaborador(nom,mat,lvl);
    col[nCol]=nuevoColaborador;
    nCol++;
}

void Trascend::agregaFondos(float fond){
   fondos=fondos+fond;
}

/*
Las 2 funciones a continuacion primero reciben un string con la matricula del alumno que se
quiera buscar para cambiarle el rango si pretenece a la mesa o al comite tecnico.
Si la funcion encuentra al alumno, pide un input con el nuevo cargo y devuelve verdadero.
Si no lo encuentra devuelve false.
*/
bool Trascend::cambiaCargoM(string mat){
   string nc;
   for(int i=0;i<nMesa;i++){
     if(mat==m[i].getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        m[i].NuevoCargo(nc);
        return true;
     }
   }
   return false;
}

bool Trascend::cambiaCargoCT(string mat){
   string nc;
   for(int i=0;i<nMesa;i++){
     if(mat==ct[i].getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        ct[i].NuevoCargo(nc);
        return true;
     }
   }
   return false;
}

bool Trascend::cambiaNivelCol(string mat){
   string nn;
   for(int i=0;i<nCol;i++){
     if(mat==col[i].getMatricula()){
        cout << "Persona encontrada, introduce nuevo nivel \n";
        cin >> nn;
        col[i].actLvl(nn);
        return true;
     }
   }
   return false;
}

#endif // TRASCEND_H
