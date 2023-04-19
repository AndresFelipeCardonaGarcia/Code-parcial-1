#include <iostream>
#include <fstream>

using namespace std;

void verificar_hora_valida(int& hora) {
  do {
    cout << "Ingrese una hora (entre 0 y 23): ";
    cin >> hora;
  } while (hora < 0 || hora > 24);
}
void reemplazar(int hora_inicio, int hora_fin, int horario[]) {
    if (hora_inicio < hora_fin) {
        for (int i = hora_inicio; i < hora_fin; ++i) {
            horario[i] = 1;
        }
    } else if (hora_inicio > hora_fin) {
        int aux = hora_inicio - hora_fin;
        aux = 24 - aux;
        int j = hora_inicio;
        for (int i = 0; i < aux; i++) {
            if (j == 24) {
                j = 0;
            }
            horario[j] = 1;
            j=++j;
        }
    }
}
int main()
{
    int dias_clase;
    int codigo_materia;
    char dia;
    char hora;
    char true_false;
    int cantidad_materias;
    int hora_inicio;
    int hora_fin;
    int L[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int M[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int m[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int J[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int V[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int S[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int D[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


    cout << "Comencemos por Reservar las horas para dormir, dejando tiempo para actividades matutinas y antes de dormir" << endl;
    cout << "Para usar Horario predenterminado (10pm:7am) presione s\nPara elegir un horario personalizado presione n\n";
    cin >> true_false;

    switch (true_false) {
        case 's':
        case 'S':
            hora_inicio = 22;
            verificar_hora_valida(hora_inicio);
            hora_fin = 7;
            verificar_hora_valida(hora_fin);
            reemplazar(hora_inicio, hora_fin, L);
            reemplazar(hora_inicio, hora_fin, M);
            reemplazar(hora_inicio, hora_fin, m);
            reemplazar(hora_inicio, hora_fin, J);
            reemplazar(hora_inicio, hora_fin, V);
            reemplazar(hora_inicio, hora_fin, S);
            reemplazar(hora_inicio, hora_fin, D);
            break;
        case 'n':
        case 'N':
            cout << "Elija la hora en que inicia su descanso en hora militar: ";
            cin >> hora_inicio;
            verificar_hora_valida(hora_inicio);
            hora_fin = hora_inicio + 9;
            verificar_hora_valida(hora_fin);
            reemplazar(hora_inicio, hora_fin, L);
            reemplazar(hora_inicio, hora_fin, M);
            reemplazar(hora_inicio, hora_fin, m);
            reemplazar(hora_inicio, hora_fin, J);
            reemplazar(hora_inicio, hora_fin, V);
            reemplazar(hora_inicio, hora_fin, S);
            reemplazar(hora_inicio, hora_fin, D);
            break;
        default:
            cout << "Opción inválida. Presione s\nPara elegir un horario personalizado presione n\n" << endl;
            break;
    }

    cout<<"¿Quiere reservar un horario semanal para actividades fuera de la universidad?"<<endl;
    cout<<"presione s para reservar tiempo y n para continuar sin reserva: "<<endl;cin >> true_false;
    if (true_false = 's'){
        cout<<"Si desea reservar un rango de tiempo presiona s si desea reservar una hora exacta presiona n "<<endl;cin>>true_false;
        if (true_false = 's'){
            while (true){
            cout<<"Elija dia que quiere reservar"<<endl;cin>>dia;
            cout<<"Elija la hora en que inicia su actividad fuera de clase"<<endl;cin>>hora_inicio;
            cout<<"Elija la hora en que termina su actividad fuera de clase"<<endl;cin>>hora_fin;
            cout<<"Si desea reservar mas tiempo presione s, sino presione n"<<endl;cin>>true_false;
        if (true_false = 'n'){
            break;
            }
        }
        }
        else{
            cout<<"Elija dia que quiere reservar"<<endl;cin>>dia;
            cout<<"Elija la hora de su actividad fuera de clase"<<endl;cin>>hora_inicio;
            cout<<"Si desea reservar mas tiempo presione s, sino presione n"<<endl;cin>>true_false;
            while (true){
        if (true_false = 'n'){
            break;
            }
        }
    }
    }
    while (true){
        cout<<"Escriba el codigo de la materia"<<endl;cin>>codigo_materia;
        cout<<"Cuantos dias asiste a esa clase "<< codigo_materia<<endl;cin>>dias_clase;
        for (int i = 0; i < dias_clase; i++) {
            cout<<"Eliga L M m J V S D"<<endl;
            cout<<"Elija dia que tiene clase"<<endl;cin>>dia;
            cout<<"Elija la hora en que inicia la clase"<<endl;cin>>hora_inicio;
            cout<<"Elija la hora en que termina su clase"<<endl;cin>>hora_fin;
        }
    }


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
