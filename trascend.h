#ifndef TRASCEND_H
#define TRASCEND_H
#include <iostream>
#include "Miembro.h"

using namespace std;

const int CUPO=50;

class Trascend{
  private:

    Miembro *m[CUPO]; //Apuntador
    Miembro *ct[CUPO];
    Miembro *col[CUPO];

    int nMesa,nCT,nCol;
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
    bool cambiaCargo(string);

    //borrar
    void borra(){for(int i=0;i<nMesa;i++){delete m[i];}
    for(int i=0;i<nCT;i++){delete ct[i];}
    for(int i=0;i<nCol;i++){delete col[i];}}

};

Trascend::Trascend(){
 nMesa=0;
 nCT=0;
 nCol=0;
 fondos=0;

}

void Trascend::llenaMiembros(){

    //mesa
    m[nMesa]=new Mesa("Carlos Sanchez","A01702188","mesa","presidente");
    nMesa++;
    m[nMesa]=new Mesa("Rafael Romo","A01701493","mesa","vicepresidente");
    nMesa++;
    m[nMesa]=new Mesa("Alejandra Lopez","A01702071","mesa","tesoreria");
    nMesa++;
    m[nMesa]=new Mesa("Romina Gramlich","A01701313","mesa","publicidad");
    nMesa++;
    m[nMesa]=new Mesa("Daniel Cruz","A01701370","mesa","patrocinios");
    nMesa++;

    //ct
    ct[nCT]=new ComiteTecnico("Emilio Valdez","A01704832","CT","cursos");
    nCT++;
    ct[nCT]=new ComiteTecnico("Balam Bravo","A01703834","CT","cursos");
    nCT++;

    //col
    col[nCol]=new Colaboradores("Juan Perez","A00000000","colaborador","C");
    nCol++;

}

void Trascend::printMiembro(string member){
    for(int i=0;i<nMesa;i++){
        if(m[i]->getTM()==member){
            cout << m[i]->strMiembro() << endl;
        }
    }
    for(int i=0;i<nCT;i++){
        if(ct[i]->getTM()==member){
            cout << ct[i]->strMiembro() << endl;
        }
    }
    for(int i=0;i<nCol;i++){
        if(col[i]->getTM()==member){
            cout << col[i]->strMiembro() << endl;
        }
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

void Trascend::agregaMesa(string nom,string mat,string tm,string carg){
    m[nMesa]=new Mesa(nom,mat,tm,carg);
    nMesa++;
}


void Trascend::agregaCT(string nom,string mat,string tm,string carg){
    ct[nCT]=new ComiteTecnico(nom,mat,tm,carg);
    nCT++;
}

void Trascend::agregaColaborador(string nom,string mat,string tm,string lvl){
    col[nCol]=new Colaboradores(nom,mat,tm,lvl);
    nCol++;
}

void Trascend::agregaFondos(float fond){
   fondos=fondos+fond;
}

bool Trascend::cambiaCargo(string mat){
   string nc;
   for(int i=0;i<nMesa;i++){
     if(mat==m[i]->getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        m[i]->NuevoCargo(nc);
        return true;}
   }
   for(int i=0;i<nCT;i++){
     if(mat==ct[i]->getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        ct[i]->NuevoCargo(nc);
        return true;}
   }
   for(int i=0;i<nCT;i++){
     if(mat==col[i]->getMatricula()){
        cout << "Persona encontrada, introduce nuevo cargo \n";
        cin >> nc;
        col[i]->NuevoCargo(nc);
        return true;}
   }
   return false;
}

#endif // TRASCEND_H
