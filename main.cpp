#include <iostream>
#include <fstream>

using namespace std;
void verificar_hora_valida(int& hora) {
    while ((hora < 0) || (hora > 23)){
        cout << "Error. Ingrese una hora (entre 0 y 23): ";
        cin >> hora;
    }
}
void tiempo_libre(int& hora_inicio, int& hora_fin, int horario[]){
    while(true){
    if (hora_inicio < hora_fin) {
        for (int i = hora_inicio; i < hora_fin; ++i) {
            if (horario[i] != 0){
                cout<<"Error el horario ingresado ya se encuentra ocupado"<<endl;
                cout<<"Ingrese una hora de incio valida: "<<endl;cin>>hora_inicio;
                verificar_hora_valida(hora_inicio);
                cout<<"Ingrese una hora de finalizacion valida: "<<endl;cin>>hora_fin;
                verificar_hora_valida(hora_fin);
                break;
            }
        }
    } else if (hora_inicio > hora_fin) {
        int aux = hora_inicio - hora_fin;
        aux = 24 - aux;
        int j = hora_inicio;
        for (int i = 0; i < aux; i++) {
            if (j == 24) {
                j = 0;
            }
            if (horario[i] != 0){
                cout<<"Error el horario ingresado ya se encuentra ocupado"<<endl;
                cout<<"Ingrese una hora de incio valida: "<<endl;cin>>hora_inicio;
                verificar_hora_valida(hora_inicio);
                cout<<"Ingrese una hora de finalizacion valida: "<<endl;cin>>hora_fin;
                verificar_hora_valida(hora_fin);
                break;
            }
            j=++j;
        }
    }
    break;
}
}
void reemplazar(int hora_inicio, int hora_fin, int horario[],int num) {
    if (hora_inicio < hora_fin) {
        for (int i = hora_inicio; i < hora_fin; ++i) {
            horario[i] = num;
        }
    } else if (hora_inicio > hora_fin) {
        int aux = hora_inicio - hora_fin;
        aux = 24 - aux;
        int j = hora_inicio;
        for (int i = 0; i < aux; i++) {
            if (j == 24) {
                j = 0;
            }
            horario[j] = num;
            j=++j;
        }
    }
}

void elegir_matriz(int hora_inicio,int hora_fin,char dia,int L[],int M[],int W[],int J[],int V[],int S[],int D[],int num){
    switch(dia) {
      case 'L':
      case 'l':
        reemplazar(hora_inicio, hora_fin, L,num);
        break;
      case 'M':
      case 'm':
        reemplazar(hora_inicio, hora_fin, M,num);
        break;
      case 'W':
      case 'w':

        reemplazar(hora_inicio, hora_fin, W,num);
        break;
      case 'J':
      case 'j':
        reemplazar(hora_inicio, hora_fin, J,num);
        break;
      case 'V':
      case 'v':
        reemplazar(hora_inicio, hora_fin, V,num);
        break;
      case 'S':
      case 's':
        reemplazar(hora_inicio, hora_fin, S,num);
        break;
      case 'D':
      case 'd':
        reemplazar(hora_inicio, hora_fin, D,num);
        break;
      default:
        cout<<"Error, elija un dia valido donde L es lunes, M es martes W es miercoles J es jueves \n V es viernes, S es sabado y D es domingo";
        break;
    }

}
int* dia_mas_disponible(int L[],int M[],int W[],int J[],int V[],int S[],int D[]){
   int contador_L = 0;
   int contador_M = 0;
   int contador_W = 0;
   int contador_J = 0;
   int contador_V = 0;
   int contador_S = 0;
   int contador_D = 0;
   for (int i = 0; i < 24; i++) {
           if (L[i] == 0) contador_L++;
           if (M[i] == 0) contador_M++;
           if (W[i] == 0) contador_W++;
           if (J[i] == 0) contador_J++;
           if (V[i] == 0) contador_V++;
           if (S[i] == 0) contador_S++;
           if (D[i] == 0) contador_D++;
       }
   // if (cant_ceros_Cuarquier dia == max_cant_ceros) usaremos ramdom para crear aleatoreidad
       int max_cant_ceros = 0;
       int lista_max_ceros;
       if (contador_L > max_cant_ceros) {
           max_cant_ceros = contador_L;
           lista_max_ceros = 0;
       }
       if (contador_M > max_cant_ceros) {
           max_cant_ceros = contador_M;
           lista_max_ceros = 1;
       }
       if (contador_W > max_cant_ceros) {
           max_cant_ceros = contador_W;
           lista_max_ceros = 2;
       }
       if (contador_J > max_cant_ceros) {
           max_cant_ceros = contador_J;
           lista_max_ceros = 3;
       }
       if (contador_V > max_cant_ceros) {
           max_cant_ceros = contador_V;
           lista_max_ceros = 4;
       }
       if (contador_S > max_cant_ceros) {
           max_cant_ceros = contador_S;
           lista_max_ceros = 5;
       }
       if (contador_D > max_cant_ceros) {
           max_cant_ceros = contador_D;
           lista_max_ceros = 6;
       }

        if (lista_max_ceros = 0){
            return L;
        }
        if (lista_max_ceros = 1){
            return M;
        }
        if (lista_max_ceros = 2){
            return W;
        }
        if (lista_max_ceros = 3){
            return J;
        }
        if (lista_max_ceros = 4){
            return V;
        }
        if (lista_max_ceros = 5){
            return S;
        }
        if (lista_max_ceros = 6){
            return D;
        }

}
void distrubucion_aleatoria(int creditos,int L[],int M[],int W[],int J[],int V[],int S[],int D[]){
    int* dia_disponible;
    for (int i = 0; i < creditos; ++i) {
        for (int j = 0; j < 24; ++j) {
            dia_disponible = dia_mas_disponible(L,M,W,J,V,S,D);
           if (dia_disponible[j] == 0){
               dia_disponible[j] = 4;
           }
        }
    }
}
int main()
{
    int codigo_materia;
    char dia;
    int num;
    int creditos;
    char true_false;
    int hora_inicio;
    int hora_fin;
    int L[24]={0};
    int M[24]={0};
    int W[24]={0};
    int J[24]={0};
    int V[24]={0};
    int S[24]={0};
    int D[24]={0};


    cout << "Comencemos por Reservar las horas para dormir, dejando tiempo para actividades matutinas y antes de dormir.\n(cenar, ponerse la pijama, cepillarse los dientes,tener la cama, desayunar, cepillarse los dientes, ducharse etc..))" << endl;
    cout << "Para usar Horario predenterminado (10pm:7am) presione s\nPara elegir un horario personalizado presione n\n";
    cin >> true_false;
    num=1;
    switch (true_false) {
        case 's':
        case 'S':
            hora_inicio = 22;
            hora_fin = 7;
            reemplazar(hora_inicio, hora_fin, L,num);
            reemplazar(hora_inicio, hora_fin, M,num);
            reemplazar(hora_inicio, hora_fin, W,num);
            reemplazar(hora_inicio, hora_fin, J,num);
            reemplazar(hora_inicio, hora_fin, V,num);
            reemplazar(hora_inicio, hora_fin, S,num);
            reemplazar(hora_inicio, hora_fin, D,num);
            break;
        case 'n':
        case 'N':
            cout << "Elija la hora en que inicia su descanso en hora militar: ";
            cin >> hora_inicio;
            verificar_hora_valida(hora_inicio);
            hora_fin = hora_inicio + 9;
            if (hora_fin > 23){
                    hora_fin = hora_fin - 24;
           }
            verificar_hora_valida(hora_fin);
            reemplazar(hora_inicio, hora_fin, L,num);
            reemplazar(hora_inicio, hora_fin, M,num);
            reemplazar(hora_inicio, hora_fin, W,num);
            reemplazar(hora_inicio, hora_fin, J,num);
            reemplazar(hora_inicio, hora_fin, V,num);
            reemplazar(hora_inicio, hora_fin, S,num);
            reemplazar(hora_inicio, hora_fin, D,num);
            break;
        default:
            cout << "Opción inválida. Presione s\nPara elegir un horario personalizado presione n\n" << endl;
            break;
    }

    cout<<"Quiere reservar un horario semanal para actividades fuera de la universidad?"<<endl;
    cout<<"Presione s para reservar tiempo y n para continuar sin reserva: "<<endl;cin >> true_false;
    if (true_false == 's'){
        num=2;
            while (true){
            cout<<"Elija dia que quiere reservar Donde; \n L es lunes, M es martes W es miercoles J es jueves \n V es viernes, S es sabado y D es domingo"<<endl;cin>>dia;
            cout<<"Elija la hora en que inicia su actividad fuera de clase: "<<endl;cin>>hora_inicio;
                        verificar_hora_valida(hora_inicio);
            cout<<"Elija la hora en que termina su actividad fuera de clase: "<<endl;cin>>hora_fin;
                        verificar_hora_valida(hora_fin);
            elegir_matriz(hora_inicio, hora_fin,dia,L,M,W,J,V,S,D,num);
            cout<<"Si desea no reservar mas tiempo presione n, sino, presione cualquier tecla"<<endl;cin>>true_false;
        if (true_false == 'n' || true_false == 'N'){
break;
            }
        }
    }

    while (true){
        num = 3;
        cout<<"Escriba el codigo de la materia"<<endl;cin>>codigo_materia;
        ifstream pensum("pensum.txt"); // abre el archivo en modo lectura
        int numero;
        if (pensum.is_open()) { // verifica si el archivo se abrió correctamente
           while (pensum >> numero) { // lee un número a la vez desde el archivo
               int creditos;
               if (numero == codigo_materia){
                   for (int i = 0; i < 3; ++i) {
                      pensum>>numero;
                   }
                   creditos = numero;
                   break;
               }
           }
           pensum.close(); // cierra el archivo
        }
        else {
           cout << "No se pudo abrir el archivo" << endl;
        }
        while(true){
            cout<<"Elija dia que tiene su clase Donde; \n L es lunes, M es martes m es miercoles J es jueves \n V es viernes, S es sabado y D es domingo"<<endl;cin>>dia;
            cout<<"Elija la hora en que inicia la clase"<<endl;cin>>hora_inicio;
            cout<<"Elija la hora en que termina su clase"<<endl;cin>>hora_fin;
            elegir_matriz(hora_inicio, hora_fin,dia,L,M,W,J,V,S,D,num);
            cout<<"Si ya no tiene mas clases de esta materia esta semana presione presione n, si aun tiene presione cualquier letra"<<endl;cin>>true_false;
            if (true_false == 'n' || true_false == 'N'){
            distrubucion_aleatoria(creditos,L,M,W,J,V,S,D);
                break;
        }
    }
        cout<<"Si ya no tiene mas materias presione presione n, si aun tiene presione cualquier letra"<<endl;cin>>true_false;
    }
    return 0;
}

