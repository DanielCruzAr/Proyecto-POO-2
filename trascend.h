#ifndef TRASCEND_H
#define TRASCEND_H
#include <iostream>
#include "Miembro.h"

using namespace std;

const int CUPO=50;

class Trascend{
  private:
    //apuntadores
    Miembro *m[CUPO]; //Lista de mesa
    Miembro *ct[CUPO]; //Lista de comite tecnico
    Miembro *col[CUPO]; //Lista de colaboradores

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

void Trascend::llenaMiembros(){ //Funcion que crea los miembros actaules de Transcend

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
    col[nCol]=new Colaboradores("Juan Perez","A00000000","colaborador","C"); //Ejemplo de colaborador
    nCol++;

}

void Trascend::printMiembro(string member){ //Funci�n que recibe un tipo de miembro (Mesa, CT o colaborador)
    //e imprime todos los miembros que haya en mesa, comite t�cnico o colaboradores
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
//Las siguientes funciones solo imprimen informaci�n del grupo
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

//Funci�n que recibe par�matros para crear un nuevo objeto Mesa y lo agregue a la lista *m[]
void Trascend::agregaMesa(string nom,string mat,string tm,string carg){
    m[nMesa]=new Mesa(nom,mat,tm,carg);
    nMesa++;
}

//Funci�n que recibe par�matros para crear un nuevo objeto ComiteTecnico y lo agregue a la lista *ct[]
void Trascend::agregaCT(string nom,string mat,string tm,string carg){
    ct[nCT]=new ComiteTecnico(nom,mat,tm,carg);
    nCT++;
}

//Funci�n que recibe par�matros para crear un nuevo objeto Colaborador y lo agregue a la lista *col[]
void Trascend::agregaColaborador(string nom,string mat,string tm,string lvl){
    col[nCol]=new Colaboradores(nom,mat,tm,lvl);
    nCol++;
}
/*
Funci�n que le suma un input flotante a fondos
*/
void Trascend::agregaFondos(float fond){
   fondos=fondos+fond;
}

/*
*Funci�n que recibe una matr�cula y busca entre todos los miembros, si coincide con alguna llama a la funci�n
*NuevoCargo en Miembro.h para cambiar el cargo de la persona ya sea de mesa, comite tecnico o colaborador7
*En el ciclo for, si el par�metro de entrada mat es igual a la funci�n getMatricula del objeto (la cual nos regresa
*un string con la matr�cula) entonces nos permite actualizar el cargo y la funci�n regresa true,
si no es igual sigue buscando, si hay coincidencias entonces regresa false.
*/
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
return false;}

#endif // TRASCEND_H
