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

        if (lista_max_ceros == 0){
            return L;
        }
        if (lista_max_ceros == 1){
            return M;
        }
        if (lista_max_ceros == 2){
            return W;
        }
        if (lista_max_ceros == 3){
            return J;
        }
        if (lista_max_ceros == 4){
            return V;
        }
        if (lista_max_ceros == 5){
            return S;
        }
        if (lista_max_ceros == 6){
            return D;
        }

}
void distrubucion_aleatoria(int creditos,int L[],int M[],int W[],int J[],int V[],int S[],int D[],int codigo_materia){
    int* dia_disponible;
    dia_disponible = dia_mas_disponible(L,M,W,J,V,S,D);
    for (int i = 0; i < creditos; ++i) {
        for (int j = 0; j < 24; ++j) {
            dia_disponible = dia_mas_disponible(L,M,W,J,V,S,D);
           if (dia_disponible[j] == 0){
               dia_disponible[j] = codigo_materia;
               j=24;
           }
        }
    }
}
char imprimir(int dia[],int posicion){
    if (dia[posicion]==0)
        cout<<"libre";
    else if (dia[posicion]==1)
        cout<<"Dormir";
    else if (dia[posicion]==2)
        cout<<"Ocupado";
    else if (dia[posicion]==3)
        cout<<"clase";
    else
        cout<<"estudiar"<<dia[posicion];
    return ' ';
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
    cout << "\033c";
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
        cout << "\033c";
        cout<<"Escriba el codigo de la materia"<<endl;cin>>codigo_materia;
        ifstream pensum("pensum.txt"); // abre el archivo en modo lectura
        int numero;
        if (pensum.is_open()) { // verifica si el archivo se abrió correctamente
           while (pensum >> numero) { // lee un número a la vez desde el archivo
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
            distrubucion_aleatoria(creditos,L,M,W,J,V,S,D,codigo_materia);
                break;
        }
    }
        cout<<"Si ya no tiene mas materias presione presione n, si aun tiene presione cualquier letra"<<endl;cin>>true_false;
        if (true_false == 'n' || true_false == 'N'){
            break;
    }
    }
            cout << "\033c";
    cout<<"|    Hora    |    Lunes    |   Martes   |    Miercoles    |   Jueves    |   Viernes    |      Sabado      |     Domingo    |"<<endl;
    cout<<"     0-1         "<<imprimir(L,0)<<"    |   "<<imprimir(M,0)<<"   |    "<<imprimir(W,0)<<"    |   "<<imprimir(J,0)<<"   |    "<<imprimir(V,0)<<"    |   "<<imprimir(S,0)<<"   |    "<<imprimir(D,0)<<endl;
    cout<<"     1-2         "<<imprimir(L,1)<<"    |   "<<imprimir(M,1)<<"   |    "<<imprimir(W,1)<<"    |   "<<imprimir(J,1)<<"   |    "<<imprimir(V,1)<<"    |   "<<imprimir(S,1)<<"   |    "<<imprimir(D,1)<<endl;
    cout<<"     2-3         "<<imprimir(L,2)<<"    |   "<<imprimir(M,2)<<"   |    "<<imprimir(W,2)<<"    |   "<<imprimir(J,2)<<"   |    "<<imprimir(V,2)<<"    |   "<<imprimir(S,2)<<"   |    "<<imprimir(D,2)<<endl;
    cout<<"     3-4         "<<imprimir(L,3)<<"    |   "<<imprimir(M,3)<<"   |    "<<imprimir(W,3)<<"    |   "<<imprimir(J,3)<<"   |    "<<imprimir(V,3)<<"    |   "<<imprimir(S,3)<<"   |    "<<imprimir(D,3)<<endl;
    cout<<"     4-5         "<<imprimir(L,4)<<"    |   "<<imprimir(M,4)<<"   |    "<<imprimir(W,4)<<"    |   "<<imprimir(J,4)<<"   |    "<<imprimir(V,4)<<"    |   "<<imprimir(S,4)<<"   |    "<<imprimir(D,4)<<endl;
    cout<<"     5-6         "<<imprimir(L,5)<<"    |   "<<imprimir(M,5)<<"   |    "<<imprimir(W,5)<<"    |   "<<imprimir(J,5)<<"   |    "<<imprimir(V,5)<<"    |   "<<imprimir(S,5)<<"   |    "<<imprimir(D,5)<<endl;
    cout<<"     6-7         "<<imprimir(L,6)<<"    |   "<<imprimir(M,6)<<"   |    "<<imprimir(W,6)<<"    |   "<<imprimir(J,6)<<"   |    "<<imprimir(V,6)<<"    |   "<<imprimir(S,6)<<"   |    "<<imprimir(D,6)<<endl;
    cout<<"     7-8         "<<imprimir(L,7)<<"    |   "<<imprimir(M,7)<<"   |    "<<imprimir(W,7)<<"    |   "<<imprimir(J,7)<<"   |    "<<imprimir(V,7)<<"    |   "<<imprimir(S,7)<<"   |    "<<imprimir(D,7)<<endl;
    cout<<"     8-9         "<<imprimir(L,8)<<"    |   "<<imprimir(M,8)<<"   |    "<<imprimir(W,8)<<"    |   "<<imprimir(J,8)<<"   |    "<<imprimir(V,8)<<"    |   "<<imprimir(S,8)<<"   |    "<<imprimir(D,8)<<endl;
    cout<<"     9-10         "<<imprimir(L,9)<<"    |   "<<imprimir(M,9)<<"   |    "<<imprimir(W,9)<<"    |   "<<imprimir(J,9)<<"   |    "<<imprimir(V,9)<<"    |   "<<imprimir(S,9)<<"   |    "<<imprimir(D,9)<<endl;
    cout<<"     10-11         "<<imprimir(L,10)<<"    |   "<<imprimir(M,10)<<"   |    "<<imprimir(W,10)<<"    |   "<<imprimir(J,10)<<"   |    "<<imprimir(V,10)<<"    |   "<<imprimir(S,10)<<"   |    "<<imprimir(D,10)<<endl;
    cout<<"     11-12         "<<imprimir(L,11)<<"    |   "<<imprimir(M,11)<<"   |    "<<imprimir(W,11)<<"    |   "<<imprimir(J,11)<<"   |    "<<imprimir(V,11)<<"    |   "<<imprimir(S,11)<<"   |    "<<imprimir(D,11)<<endl;
    cout<<"     12-13         "<<imprimir(L,12)<<"    |   "<<imprimir(M,12)<<"   |    "<<imprimir(W,12)<<"    |   "<<imprimir(J,12)<<"   |    "<<imprimir(V,12)<<"    |   "<<imprimir(S,12)<<"   |    "<<imprimir(D,12)<<endl;
    cout<<"     13-14         "<<imprimir(L,13)<<"    |   "<<imprimir(M,13)<<"   |    "<<imprimir(W,13)<<"    |   "<<imprimir(J,13)<<"   |    "<<imprimir(V,13)<<"    |   "<<imprimir(S,13)<<"   |    "<<imprimir(D,13)<<endl;
    cout<<"     14-15         "<<imprimir(L,14)<<"    |   "<<imprimir(M,14)<<"   |    "<<imprimir(W,14)<<"    |   "<<imprimir(J,14)<<"   |    "<<imprimir(V,14)<<"    |   "<<imprimir(S,14)<<"   |    "<<imprimir(D,14)<<endl;
    cout<<"     15-16         "<<imprimir(L,15)<<"    |   "<<imprimir(M,15)<<"   |    "<<imprimir(W,15)<<"    |   "<<imprimir(J,15)<<"   |    "<<imprimir(V,15)<<"    |   "<<imprimir(S,15)<<"   |    "<<imprimir(D,15)<<endl;
    cout<<"     16-17         "<<imprimir(L,16)<<"    |   "<<imprimir(M,16)<<"   |    "<<imprimir(W,16)<<"    |   "<<imprimir(J,16)<<"   |    "<<imprimir(V,16)<<"    |   "<<imprimir(S,16)<<"   |    "<<imprimir(D,16)<<endl;
    cout<<"     17-18         "<<imprimir(L,17)<<"    |   "<<imprimir(M,17)<<"   |    "<<imprimir(W,17)<<"    |   "<<imprimir(J,17)<<"   |    "<<imprimir(V,17)<<"    |   "<<imprimir(S,17)<<"   |    "<<imprimir(D,17)<<endl;
    cout<<"     18-19         "<<imprimir(L,18)<<"    |   "<<imprimir(M,18)<<"   |    "<<imprimir(W,18)<<"    |   "<<imprimir(J,18)<<"   |    "<<imprimir(V,18)<<"    |   "<<imprimir(S,18)<<"   |    "<<imprimir(D,18)<<endl;
    cout<<"     19-20         "<<imprimir(L,19)<<"    |   "<<imprimir(M,19)<<"   |    "<<imprimir(W,19)<<"    |   "<<imprimir(J,19)<<"   |    "<<imprimir(V,19)<<"    |   "<<imprimir(S,19)<<"   |    "<<imprimir(D,19)<<endl;
    cout<<"     20-21         "<<imprimir(L,20)<<"    |   "<<imprimir(M,20)<<"   |    "<<imprimir(W,20)<<"    |   "<<imprimir(J,20)<<"   |    "<<imprimir(V,20)<<"    |   "<<imprimir(S,20)<<"   |    "<<imprimir(D,20)<<endl;
    cout<<"     21-22         "<<imprimir(L,21)<<"    |   "<<imprimir(M,21)<<"   |    "<<imprimir(W,21)<<"    |   "<<imprimir(J,21)<<"   |    "<<imprimir(V,21)<<"    |   "<<imprimir(S,21)<<"   |    "<<imprimir(D,21)<<endl;
    cout<<"     22-23         "<<imprimir(L,22)<<"    |   "<<imprimir(M,22)<<"   |    "<<imprimir(W,22)<<"    |   "<<imprimir(J,22)<<"   |    "<<imprimir(V,22)<<"    |   "<<imprimir(S,22)<<"   |    "<<imprimir(D,22)<<endl;
    cout<<"     23-0         "<<imprimir(L,23)<<"    |   "<<imprimir(M,23)<<"   |    "<<imprimir(W,23)<<"    |   "<<imprimir(J,23)<<"   |    "<<imprimir(V,23)<<"    |   "<<imprimir(S,23)<<"   |    "<<imprimir(D,23)<<endl;


    return 0;
}

