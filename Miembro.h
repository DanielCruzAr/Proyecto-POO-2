#ifndef MIEMBRO_H
#define MIEMBRO_H
#include<iostream>

using namespace std;

/*
Miembro será clase abstracta ya que se utilizarán las funciones
que
*/
class Miembro{
  /*
  Atributos de instancia. Estos son accesibles
  a traves de las clases que se hereden de esta
  */
  protected:
      string nombre, matricula, tipoM;

  //Métodos
  public:
    Miembro(){}
    Miembro(string nom,string mat,string tm);

    //Getters
    virtual string getMatricula(){return matricula;}
    string getTM(){return tipoM;}

    //Metodos abstractos que seran sobreescritos en mesa, ct, col
    virtual string strMiembro()=0;
    virtual void NuevoCargo(string)=0;
};

//Constructor que recibe parámetros
Miembro::Miembro(string nom,string mat, string tm){
 nombre=nom;
 matricula=mat;
 tipoM=tm;
}


//clase para la Mesa directiva del grupo que hereda a Miembro
class Mesa: public Miembro{
  //Variables de instancia privadas
  private:
    string cargoMesa;

  //Métodos
  public:
    Mesa();
    Mesa(string nom, string mat, string charge, string tm);

    //getters (sobreescritura)
    string getMatricula(){return matricula;}

    //Funciones
    string strMiembro();
    void NuevoCargo(string);
};

//Por default
Mesa::Mesa(){}

//Constructor de mesa
Mesa::Mesa(string nom, string mat, string tm, string charge) : Miembro(nom,mat,tm){
  cargoMesa=charge;
}

//Funcion para cambiar el cargo o rol
void Mesa::NuevoCargo(string nc){
  cargoMesa=nc;
}

/*
*Funcion para obtener el nombre, matricula y cargo en un string
*Regresa un string que será ocupado para la impresión desde otra
función.
*/
string Mesa::strMiembro(){
  string strM=nombre+"|"+matricula+"|"+cargoMesa;
  return strM;
}



//clase para el comite tecnico del grupo, que hereda a Miembro
class ComiteTecnico: public Miembro{
  //Variables de instancia privadas
  private:
    string cargoCT;

  //Métodos
  public:
    ComiteTecnico();
    ComiteTecnico(string nom,string mat,string tm,string charge);

    //getters (sobreescritura)
    string getMatricula(){return matricula;}

    //Funciones
    string strMiembro();
    void NuevoCargo(string);
};

//por default
ComiteTecnico::ComiteTecnico(){}

//Constructor
ComiteTecnico::ComiteTecnico(string nom,string mat,string tm,string charge): Miembro(nom,mat,tm){
    cargoCT=charge;
}

/*
*Funcion para obtener el nombre, matricula y cargo en un string
*Regresa un string que será ocupado para la impresión desde otra
función.
*/
string ComiteTecnico::strMiembro(){
  string strCT=nombre+"|"+matricula+"|"+cargoCT;
  return strCT;
}

void ComiteTecnico::NuevoCargo(string nuevo_cargo){
  cargoCT=nuevo_cargo;
}


//clase para los Colaboradores que hereda a miembros
class Colaboradores: public Miembro{
  //Variables de instancia privadas
  private:
      string nivel;

  //Métodos
  public:
      Colaboradores();
      Colaboradores(string,string,string,string);

      //getters (sobreescritura)
      string getMatricula(){return matricula;}

      //Funciones
      void NuevoCargo(string);
      string strMiembro();
};

//por default
Colaboradores::Colaboradores(){}

//Constructor
Colaboradores::Colaboradores(string nom,string mat,string tm,string lvl): Miembro(nom,mat,tm){
    nivel=lvl;
}

void Colaboradores::NuevoCargo(string nuevo_nivel){
    nivel=nuevo_nivel;
}

/*
*Funcion para obtener el nombre, matricula y cargo en un string
*Regresa un string que será ocupado para la impresión desde otra
función.
*/
string Colaboradores::strMiembro(){
  string strCol=nombre+"|"+matricula+"|"+nivel;
  return strCol;
}

#endif // MIEMBRO_H
