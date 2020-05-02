//Una empresa necesita llevar el control de los datos personales de sus 10 empleados
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <regex>
#include <iomanip>
using namespace std;
struct	reg{
	int		CODE;
	string	DEPTO;
	string	NAME;
	char	JOB[20];
	float	PAGO;
};

	int		zCODE,tempCODE,flag;
	string	zDEPTO,tempDEPTO;
	string	zNAME,tempNAME;
	char	zJOB[20],tempJOB[20];
	float	zPAGO,tempPAGO;
	
void	ingresar()	;
void 	modificar();
void	modificarPASO2();
void 	eliminar();
void	reporte();

int main(){
int	operacion=0;
system("color 03");	
	do{
	cout<<"--------------------------------------------"<<endl;	
	cout<<"Bienvenido, que accion desea realizar ?"<<endl<<endl;
	cout<<"1. Ingreso de datos"<<endl<<"2. Modificacion de Datos"<<endl<<"3. Borrado de Datos"<<endl<<"4. Reportes"<<endl<<"0. Salir"<<endl;
	cout<<"--------------------------------------------"<<endl;	
	cin>>operacion;
 	if (operacion==1){
 		system("CLS");
		ingresar();	};
 	if (operacion==2){
 		system("CLS");
		modificar();	};
 	if (operacion==3){
 		system("CLS");
		eliminar();	};
 	if (operacion==4){
		system("CLS");
		reporte();	};
 } 	while (operacion!=0);
 	return (0);				}	

void ingresar(){
	string	a=" ",b="_";
 	cout<<"ingrese el CODIGO del empleado a registrar:	"				 ;cin>>zCODE;
 	cout<<"ingrese el DEPTO-> |1. GERENCIA| |2. ADMON| |3. PRODUCCION|:	";cin>>zDEPTO;fflush(stdin);
 //	cout<<"ingrese el NOMBRE del empleado:	";cin.getline(zNAME,20);fflush(stdin);
	cout<<"ingrese el NOMBRE del empleado:	";getline (cin, zNAME,'\n' ) ;	
 	cout<<"ingrese el PUESTO que desempeña:	";cin>>zJOB;
 	cout<<"ingrese el SALARIO devengado:	";cin>>zPAGO;
 //CONVERSION DE ESPACIOS A GUIONES	
 	char	aux[20];
	strcpy(aux,zNAME.c_str());
 	for(int i=0; i<strlen(aux); i++){
 			if (aux[i]==32){
 		aux[i]=95;
 		}
 		}
 zNAME=aux;
 	
//	reemplaca espacios en blanco " " con "_"	
//	const auto obj = regex{ " " };
//  const auto repl = string{ "_" };
//  const auto valor = zNAME;
//  zNAME=regex_replace(valor, obj, repl);
 
//  zNAME = regex_replace(zNAME, regex(a), b);	
 //	buscar_y_remplazar(zNAME, a, b);
 //	GUARDANDO 
 ofstream grabararchivo;
	try {
		grabararchivo.open("CV_EJERCICIO_EN_CLASE_01.txt",ios::app);
		grabararchivo<<zCODE<<"\t"<<zDEPTO<<"\t"<<zNAME<<"\t"<<zJOB<<"\t"<<zPAGO<<endl;
		grabararchivo.close();		
		}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;	
		}

}
void modificar(){
 	int	salida;
	//Solicitud de DATOS
	cout<<"Ingrese el CODIGO del empleado al que desea modificar DATOS:	"<<endl;	cin>>tempCODE;
	
	do {
 	cout<<"ingrese el DEPTO-> |1. GERENCIA| |2. ADMON| |3. PRODUCCION|:	";cin>>tempDEPTO;fflush(stdin);
	cout<<"ingrese el NOMBRE del empleado:	";getline (cin, tempNAME,'\n' ) ;
 	cout<<"ingrese el PUESTO que desempeña:	";cin>>tempJOB;
 	cout<<"ingrese el SALARIO devengado:	";cin>>tempPAGO;
	cout<<"\nDesea Modificar algo MAS? Si= 1/No= 2: "<<endl; cin>>salida;fflush(stdin);
	cout<<tempNAME;
	} while (salida!=2);
	
	char	aux[20];
	strcpy(aux,tempNAME.c_str());
 	for(int i=0; i<strlen(aux); i++){
 			if (aux[i]==32){
 			aux[i]=95;
 				}
 				}
 tempNAME=aux;
	
	modificarPASO2();
}
void modificarPASO2(){
 	ifstream data_a; //archivo original
	ofstream data_temp; //archivo temporal
	
	remove			("temp.txt");
	data_a.open		("CV_EJERCICIO_EN_CLASE_01.txt",ios::in);
	data_temp.open	("temp.txt",ios::app);
		
	//leer archivo anterior
	while (data_a>>zCODE>>zDEPTO>>zNAME>>zJOB>>zPAGO){	
		if(tempCODE==zCODE){
			data_temp<<zCODE<<"\t"<<tempDEPTO<<"\t"<<tempNAME<<"\t"<<tempJOB<<"\t"<<tempPAGO<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag=1;
		}			
		else if(tempCODE!=zCODE)
			data_temp<<zCODE<<"\t"<<zDEPTO<<"\t"<<zNAME<<"\t"<<zJOB<<"\t"<<zPAGO<<endl;							
	}
	data_a.close();
	data_temp.close();
	
	if (flag==1){
		remove("CV_EJERCICIO_EN_CLASE_01.txt");
		rename("temp.txt","CV_EJERCICIO_EN_CLASE_01.txt");
	}	
}



void eliminar(){
 	int	salida;
	//Solicitud de DATOS
	
	
	do {
	cout<<"Ingrese el CODIGO del empleado al que desea ELIMINAR DATOS:	"<<endl;	cin>>tempCODE;
	cout<<"\nEsta seguro que Desea ELIMINAR Estos DATOS? Si= 1/No= 2: "<<endl; cin>>salida;fflush(stdin);
	} while (salida!=1);
	
	
 	ifstream data_a; //archivo original
	ofstream data_temp; //archivo temporal
	
	remove			("temp.txt");
	data_a.open		("CV_EJERCICIO_EN_CLASE_01.txt",ios::in);
	data_temp.open	("temp.txt",ios::app);
		
	//leer archivo anterior
	while (data_a>>zCODE>>zDEPTO>>zNAME>>zJOB>>zPAGO){
		if(tempCODE==zCODE){
			cout<<"Registro ELIMINADO...."<<endl;
			flag=1;
		}			
		else if(tempCODE!=zCODE)
			data_temp<<zCODE<<"\t"<<zDEPTO<<"\t"<<zNAME<<"\t"<<zJOB<<"\t"<<zPAGO<<endl;							
	}
	data_a.close();
	data_temp.close();
	
	if (flag==1){
		remove("CV_EJERCICIO_EN_CLASE_01.txt");
		rename("temp.txt","CV_EJERCICIO_EN_CLASE_01.txt");
	}	
}
void reporte(){
	float SUMA=0;
	 	ifstream data_a; //archivo original
	 	data_a.open		("CV_EJERCICIO_EN_CLASE_01.txt",ios::in);
	 	//leer archivo anterior
cout<<setw(6)<<"CODIGO"<<"|"<<setw(20)<<"DEPTO"<<"|"<<setw(15)<<"NOMBRE"<<"|"<<setw(20)<<"Puesto"<<"|"<<setw(15)<<"Sueldo"<<"|"<<setw(8)<<endl;
	while (data_a>>zCODE>>zDEPTO>>zNAME>>zJOB>>zPAGO){
		SUMA=SUMA+zPAGO;
		cout<<setw(6)<<zCODE<<"|"<<setw(20)<<zDEPTO<<"|"<<setw(15)<<zNAME<<"|"<<setw(20)<<zJOB<<"|"<<setw(15)<<zPAGO<<"|"<<setw(8)<<endl;
	 }
cout<<"Total de Planilla: Q."<<SUMA<<endl;



}
