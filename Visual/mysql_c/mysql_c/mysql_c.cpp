// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "Empresa@123", "db_empresa", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion Exitosa..." << endl;
        string puesto;
        cout << "Ingrese puesto: ";
        cin >> puesto;
        string insert = "insert into puestos(puesto) values('"+puesto+"')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
            cout << "Ingreso Exitoso..." << endl;
        }
        else {
            cout << "xxx Error al ingresar xxx" << endl;
        }
    }
    else {
        cout << "Error en la Conexion..." << endl;
    }
 
    system("pause");
    return 0;
}

