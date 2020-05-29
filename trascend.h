#ifndef TRASCEND_H
#define TRASCEND_H
#include <iostream>
#include "Miembro.h"

using namespace std;

const int CUPO=50;

class Trascend{
  private:

    Miembro *m[CUPO]; //Apuntador

    int nMiembro;
    float fondos;

  public:
    Trascend(); //por default

    //getters de las variables privadas
    float getFondos(){return fondos;}

    void llenaMiembros();

    void printMiembro(string);

    //Informacion del grupo
    void informacion();
    void mision();
    void vision();
    void infoMesa();
    void infoCT();
    void infoCol();

    //Metodos
    void agregaMesa(string,string,string,string);
    void agregaCT(string,string,string,string);
    void agregaColaborador(string,string,string,string);
    void agregaFondos(float);
    bool cambiaCargoM(string);
    bool cambiaCargoCT(string);
    bool cambiaNivelCol(string);

    //borrar
    void borra(){for(int i=0;i<nMiembro;i++){delete m[i];}}

};

Trascend::Trascend(){
 nMiembro=0;
 fondos=0;

}

void Trascend::llenaMiembros(){

    //mesa
    m[nMiembro]=new Mesa("Carlos Sanchez","A01702188","mesa","presidente");
    nMiembro++;
    m[nMiembro]=new Mesa("Rafael Romo","A01701493","mesa","vicepresidente");
    nMiembro++;
    m[nMiembro]=new Mesa("Alejandra Lopez","A01702071","mesa","tesoreria");
    nMiembro++;
    m[nMiembro]=new Mesa("Romina Gramlich","A01701313","mesa","publicidad");
    nMiembro++;
    m[nMiembro]=new Mesa("Daniel Cruz","A01701370","mesa","patrocinios");
    nMiembro++;

    //ct
    m[nMiembro]=new ComiteTecnico("Emilio Valdez","A01704832","CT","cursos");
    nMiembro++;
    m[nMiembro]=new ComiteTecnico("Balam Bravo","A01703834","CT","cursos");
    nMiembro++;

    //col
    m[nMiembro]=new Colaboradores("Juan P�rez","A00000000","colaborador","C");
    nMiembro++;

}

void Trascend::printMiembro(string member){
    for(int i=0;i<nMiembro;i++){
        if(m[i]->getTM()==member){
            cout << m[i]->strMiembro() << endl;
        }
    }
}

void Trascend::informacion(){
 cout << "\n Somos un grupo estudiantil con el prop�sito de";
 cout << "\n fomentar el balance en las 7 dimensiones que conforman";
 cout << "\n a la persona (F�sico, Emocional, Social, Espiritual e Intelectual)";
 cout << "\n para as�, alcanzar la autorrealizaci�n y libertad personal.";
 cout << "\n Nuestro objetivo es potencializar las habilidades y facultades";
 cout << "\n de nuestros integrantes mediante pl�ticas, conferencias y actividades en contacto con la naturaleza;";
 cout << "\n para impulsarlos a desarrollar la mejor versi�n de s� mismos." << endl;
}

void Trascend::mision(){
 cout << "\n Inspirar a estudiantes del Tecnol�gico de Monterrey a potencializar sus habilidades de liderazgo,";
 cout << "\n inteligencia emocional y desarrollo integral como personas, mediante actividades que favorezcan";
 cout << "\n el crecimiento personal y profesional en contacto con la  naturaleza, con el fin de alcanzar la plenitud";
 cout << "\n y el bienestar integral." << endl;
}

void Trascend::vision(){
 cout << "\n Lograr ser un grupo estudiantil que est� presente en m�s de un campus y cuente con varios colaboradores.";
 cout << "\n Con el paso del tiempo, poder progresar a actividades de otro nivel con la experiencia adquirida en los cursos b�sicos.";
 cout << "\n A su vez, crear en el grupo una estructura funcional para que las generaciones futuras puedan continuarlo." <<endl;
}

//Informacion sobre la mesa, el comite tecnico y los colaboradores
void Trascend::infoMesa(){
 cout << "\n Encargados de la organizaci�n general del grupo,"
      << "\n administraci�n de recursos, asignaci�n de actividades,"
      << "\n organizaci�n de eventos, publicidad y difusi�n."
      << "\n Encargados de crear m�dulos para temas de inteligencia emocional.\n " << endl;
}

void Trascend::infoCT(){
 cout << "\n Comit� conformado por personas especializadas en diversas"
      << "\n �reas al aire libre. Encargados de dar cursos b�sicos. \n"
      << endl;
}

void Trascend::infoCol(){
 cout << "\n Encargados de participar, contribuir y sumar al grupo de manera efectiva y responsable."
      << "\n Colaborar en vendimias, log�stica y difusi�n del grupo. \n" << endl;
}

void Trascend::agregaMesa(string nom,string mat,string tm,string carg){
    m[nMiembro]=new Mesa(nom,mat,tm,carg);
    nMiembro++;
}


void Trascend::agregaCT(string nom,string mat,string tm,string carg){
    m[nMiembro]=new ComiteTecnico(nom,mat,tm,carg);
    nMiembro++;
}

void Trascend::agregaColaborador(string nom,string mat,string tm,string lvl){
    m[nMiembro]=new Colaboradores(nom,mat,tm,lvl);
    nMiembro++;
}

void Trascend::agregaFondos(float fond){
   fondos=fondos+fond;
}

/*
Las 2 funciones a continuacion primero reciben un string con la matricula del alumno que se
quiera buscar para cambiarle el rango si pretenece a la mesa o al comite tecnico.
Si la funcion encuentra al alumno, pide un input con el nuevo cargo y devuelve verdadero.
Si no lo encuentra devuelve false.

Sin embargo aun tengo que ajustarlas al polimorfismo

bool Trascend::cambiaCargoM(string mat){
   string nc;
   for(int i=0;i<nMiembro;i++){
     if(mat==m[i]->getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        m[i]->NuevoCargo(nc);
        return true;
     }
   }
   return false;
}

bool Trascend::cambiaCargoCT(string mat){
   string nc;
   for(int i=0;i<nMiembro;i++){
     if(mat==m[i]->getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        m[i]->NuevoCargo(nc);
        return true;
     }
   }
   return false;
}

bool Trascend::cambiaNivelCol(string mat){
   string nn;
   for(int i=0;i<nMiembro;i++){
     if(mat==m[i]->getMatricula()){
        cout << "Persona encontrada, introduce nuevo nivel \n";
        cin >> nn;
        col[i]->actLvl(nn);
        return true;
     }
   }
   return false;
}
*/
#endif // TRASCEND_H
