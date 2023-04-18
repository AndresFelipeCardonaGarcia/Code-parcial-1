#include <iostream>
#include <fstream>

using namespace std;



int main()
{
    char dia;
    char hora;
    char true_false;
    int cantidad_materias;
    int hora_inicio;
    int hora_fin;
    int hora_dormir;
    cout<<"¿A que horas normalmente se acuesta?"<<endl;
    cout << "Para usar Horario predenterminado (22:7) presione s\nPara elegir un horario personalizado presione s\n";cin >> true_false;
    if (true_false = 1){
        hora_inicio=22;
        hora_fin=10;
    }
    else{
        cout<<"¿A qué horas normalmente se acuesta? "<<endl;cin >> hora_dormir;
        hora_inicio=hora_dormir;
        hora_fin=hora_inicio+91;
    }
    cout<<"¿Quiere reservar un horario semanal para actividades fuera de la universidad?"<<endl;
    cout<<"presione s para reservar tiempo y n para continuar sin reserva: "<<endl;cin >> true_false;
    if (true_false = 1){

    }
    cout<<"¿Cuántas materias tiene actualmente matriculadas? "<<endl;cin >> cantidad_materias;





    ifstream pensum("pensum.txt"); // abre el archivo en modo lectura
    int numero;
    if (pensum.is_open()) { // verifica si el archivo se abrió correctamente
       while (pensum >> numero) { // lee un número a la vez desde el archivo
          cout << numero << endl; // muestra el número en la consola

       }
       pensum.close(); // cierra el archivo
    }
    else {
       cout << "No se pudo abrir el archivo" << endl;
    }
    return 0;
}
/*








   ifstream archivo("datos.txt");
      vector<int> numeros;

      int valor;
      while (archivo >> valor) {
          numeros.push_back(valor);
      }

      archivo.close();

      // ahora puede utilizar el vector "numeros" que contiene los enteros del archivo
      return 0;
     */
