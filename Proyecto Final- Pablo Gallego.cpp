#include <iostream>
using namespace std;

int const filas=4;
int const columnas=5;

void limpiarMatriz(bool matrizBool[filas][columnas], int matrizInt[filas][columnas]);
void mostrarMatrizBool(bool matriz[filas][columnas]);
void mostrarMatrizTexto(string matriz[filas][columnas]);
void mostrarMatrizEnteros(int matriz[filas][columnas]);

//PROCEDIMIENTOS
void ContenedoresNPuertos(bool Mdisponibilidad[filas][columnas]);
void CantidadContxPuerto (string NomPuertos [], int NumContenedores[], int NumPuertos);
void reporteMarca(string Mmarcas[filas][columnas]);

//FUNCIONES
float calcularOcupacion(bool Mdisponibilidad[filas][columnas]);
int valorRecaudadoPuerto(string puertoCarga[filas][columnas],string nombrePuerto);
float promedioPeso(int Mpeso[filas][columnas]);
int filaPesada(int pesos[filas][columnas]);
int filaliviana(int pesos[filas][columnas]);
int cantidadTipoArticulo(string tipoArticulo[filas][columnas],string tipoArticuloBuscado);
float promedioPesoPuerto(int pesos[filas][columnas],string puertoCarga[filas][columnas],string puertoBuscado);
string nombreEmpresaContenedorPesado(int pesos[filas][columnas], string marcas[filas][columnas]);
string nombreEmpresaContenedorLiviano(int pesos[filas][columnas], string marcas[filas][columnas]);

int main (){
	
	bool disponibilidad [filas][columnas];
	int peso [filas][columnas];
	string puertoCarga [filas][columnas];
	string marca [filas][columnas];
	string tipo [filas][columnas];

	int coofila=-1;
	int coocolumna=-1;
	int nContenedores=0;
	int totalContenedores=0;
	int nPuertos=0;
	float ocupacion=0.0;
	string puertoActual="";
	int precioPuerto=0;
	float promedioPesoBarco=0.0;
	int filaMayorPeso=0;
	int filaMenorPeso=0;
	bool preguntaTipo=0;
	int cantidadTipo=0;
	string tipoBuscado="";
	bool preguntaPromPeso=0;
	float promedioPesoXPuerto=0.0;
	string puertoPesoBuscado="";
	string marcaMasPesada="";
	string marcaMasLiviana="";

	limpiarMatriz(disponibilidad, peso);

	cout<<"\t"<<"~Bienvenido al barco~"<<endl;
	cout<<"Ingrese la cantidad de puertos"<<endl;
	cin>>nPuertos;
	string puertos [nPuertos];
	int contenedores [nPuertos];
	for (int i=0; i<nPuertos; i++){
		cout<<"Ingrese nombre de puerto "<<i+1<<endl;
		cin>>puertos[i];	
	}
	
	for (int i=0; i<nPuertos; i++){
		cout<<endl;
		cout<<"Bienvenido al puerto "<<puertos[i]<<":"<<endl;	
		cout<<"Ingrese el numero de contenedores "<<endl;
		cin>>nContenedores;
		contenedores[i]=nContenedores;
		puertoActual=puertos[i];
		
		for (int j=0; j<nContenedores; j++){
			cout<<"¿Donde quiere alamcenar el contenedor "<<j+1<<"?"<<endl;
			cout<<"Disponibilidad del Barco (1 disponible, 0 ocupado):"<<endl;
			mostrarMatrizBool(disponibilidad);
			cout<<"Ingrese coordenada fila:"<<endl;
			cin>>coofila;
			cout<<"Ingrese coordenada columna:"<<endl;
			cin>>coocolumna;
			if (coofila>=0 && coofila<filas && coocolumna>=0 && coocolumna<columnas && disponibilidad[coofila][coocolumna]==1){
				disponibilidad[coofila][coocolumna]=0;
				puertoCarga[coofila][coocolumna]=puertos[i];
				
				cout<<"Caracteristicas del contenedor: "<<endl;
				cout<<"Ingrese marca"<<endl;
				cin>>marca[coofila][coocolumna]; 
				cout<<"Ingrese peso en kg (no ingrese unidad)"<<endl;
				cin>>peso[coofila][coocolumna];
				cout<<"Ingrese tipo (A: Alimentos, B: Dispositivos electronicos, C: Ropa y demas textiles)"<<endl;
				cin>>tipo[coofila][coocolumna];	
				
				cout<<"~Contenedor ingresaso correctamente~"<<endl;
				ocupacion= calcularOcupacion(disponibilidad);
				cout<<"El porcentaje de ocupacion del barco es del "<<ocupacion<<"%"<<endl;
				precioPuerto=valorRecaudadoPuerto(puertoCarga,puertoActual);
				cout<<"El valor recaudado en el puerto "<<puertoActual<<" es de "<<precioPuerto<<"USD"<<endl;
				cout<<endl;
			}else {
				cout<<"X Posicion incorrecta X"<<endl;
				j=j-1;
			}
		}
		cout<<"***********************************************************************************"<<endl;
	}

	ContenedoresNPuertos(disponibilidad);
	CantidadContxPuerto (puertos, contenedores, nPuertos);
	reporteMarca(marca);
	promedioPesoBarco=promedioPeso(peso);
	cout<<"El promedio de peso de todos los contenedores es de "<<promedioPesoBarco<<" Kg"<<endl;
	filaMayorPeso=filaPesada(peso);
	cout<<"La fila mas pesada fue "<<filaMayorPeso<<endl;
	filaMenorPeso=filaliviana(peso);
	cout<<"La fila mas liviana fue "<<filaMenorPeso<<endl;
	
	cout<<"Desea saber cuantos contenedores hay segun su tipo de articulo? (Marque 1 verdadero, 0 falso)"<<endl;
	cin>>preguntaTipo;
	if (preguntaTipo==1){
		do{
		cout<<"Que tipo de contenedor quiere saber la cantidad?"<<endl;
		cin>>tipoBuscado;
		cantidadTipo=cantidadTipoArticulo(tipo,tipoBuscado);
		cout<<"El total de contenedores del tipo "<<tipoBuscado<<" es de "<<cantidadTipo<<endl;
		cout<<"Quiere saber cuantos contenedores de otro tipo de articulo? (Marque 1 verdadero, 0 falso)"<<endl;
		cin>>preguntaTipo;
		}while (preguntaTipo==1);	
	}
	
	cout<<"Desea saber el peso promedio recogido en un puerto? (Marque 1 verdadero, 0 falso)"<<endl;
	cin>>preguntaPromPeso;
	if (preguntaPromPeso==1){
		do{
			cout<<"De que puerto quiere saber el peso promedio?"<<endl;
			cin>>puertoPesoBuscado;
			promedioPesoXPuerto=promedioPesoPuerto(peso,puertoCarga,puertoPesoBuscado);
			cout<<"El promedio del peso del puerto "<<puertoPesoBuscado<<" es "<<promedioPesoXPuerto<<endl;
			cout<<"Quiere saber el peso promedio de otro puerto? (Marque 1 verdadero, 0 falso)"<<endl;
			cin>>preguntaPromPeso;	
		}while(preguntaPromPeso==1);
	}
	
	marcaMasPesada=nombreEmpresaContenedorPesado(peso,marca);
	cout<<"La marca con el contenedor mas pesado fue "<<marcaMasPesada<<endl;
	
	marcaMasLiviana=nombreEmpresaContenedorLiviano(peso,marca);
	cout<<"La marca con el contenedor mas liviano fue "<<marcaMasLiviana<<endl;
	
	return 0;
}

//**************************************************************************************************************************

//PROCEDIMIENTOS
void ContenedoresNPuertos(bool Mdisponibilidad[filas][columnas]){
	int contador=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Mdisponibilidad[i][j]==0){
				contador=contador+1;
			}
		}
	}
	cout<<"La cantidad de contenedores en el barco es "<<contador<<endl;

}

void CantidadContxPuerto (string NomPuertos [],int NumContenedores[],int NumPuertos){
	for(int i=0;i<filas;i=i+1){
		for(int j=0;j<columnas;j=j+1){
			if (NumContenedores[i]>NumContenedores[j]){
				int auxContenedores=NumContenedores[i];
				NumContenedores[i]=NumContenedores[j];
				NumContenedores[j]=auxContenedores;
				
				string auxPuertos=NomPuertos[i];
				NomPuertos[i]=NomPuertos[j];
				NomPuertos[j]=auxPuertos;
			}
		}
	}
	cout<<"Los puertos con mayor numero de contenedores a menor son:"<<endl;
	for(int i=0;i<NumPuertos;i++){
		cout<<NomPuertos[i]<<"= "<<NumContenedores[i]<<" contenedores"<<endl;
	}
}

//void MarcasPrimium(string Mmarcas[filas][columnas]){
//for(int i=0;i<filas;i++){
		//for(int j=0;j<columnas;j++){
			//if (i>0 && i<4 && j>0 && j<3 && Mmarcas[i][j]!=""){
				
			//}
		//}
	//}	
//}
//void MarcasEco(string Mmarcas[filas][columnas])

void reporteMarca(string Mmarcas[filas][columnas]){
bool pregunta=0;
string marcaBuscada="";
int contadorPremium=0;
int contadorEco=0;
int precio=0;
cout<<"Desea sabar el reporte segun marcas de contenedores? (Marque 1 verdadero, 0 falso)"<<endl;
cin>>pregunta;
if (pregunta==1){
	do{
		cout<<"Que marca quiere saber el reporte?"<<endl;
		cin>>marcaBuscada;
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if 	(i>0 && i<4 && j>0 && j<3 && Mmarcas[i][j]==marcaBuscada){
					contadorPremium=contadorPremium+1;
					precio=contadorPremium*300;
				}
			}
		}
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if 	(i==0 && i==3 && j==0 && j==4 && Mmarcas[i][j]==marcaBuscada){
					contadorEco=contadorEco+1;
					precio=precio+(contadorEco*100);
				}
			}
		}
		cout<<"Hay "<<contadorPremium<<" contenedores en zona premium, y "<<contadorEco<<" en zona economica."<<endl;
		cout<<"El precio a pagar es de "<<precio<<"USD"<<endl;
		cout<<"Desea sabar el reporte de otras marcas de contenedores? (Marque 1 verdadero, 0 falso)"<<endl;
		cin>>pregunta;
	}while (pregunta==1);
}
}

//FUNCIONES
float calcularOcupacion(bool Mdisponibilidad[filas][columnas]){
	float contador=0;
	float porcentajeOcupacion=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (Mdisponibilidad[i][j]==0){
			contador=contador+1;
			porcentajeOcupacion=(contador/20)*100;
			}
		}
	}
	return porcentajeOcupacion;
}

int valorRecaudadoPuerto(string puertoCarga[filas][columnas],string nombrePuerto){
int contadorPremium=0;
int contadorEco=0;
int precio=0;	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (i>0 && i<4 && j>0 && j<3 && puertoCarga[i][j]==nombrePuerto){
				contadorPremium=contadorPremium+1;
				precio=precio+(contadorPremium*300);
			}
		}
	}
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if 	(i==0 && i==3 && j==0 && j==4 && puertoCarga[i][j]==nombrePuerto){
				contadorEco=contadorEco+1;
				precio=precio+(contadorEco*100);
			}
		}
	}
	return precio;
}

float promedioPeso(int Mpeso[filas][columnas]){
float peso=0;
float promedio=0;
float contador=0;	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (Mpeso[i][j]!=0){
				contador=contador+1;
				peso=peso+Mpeso[i][j];
				promedio=peso/contador;
			}
		}
	}
return promedio;
}

int filaPesada(int pesos[filas][columnas]){
int mayor=INT_MIN;
int filamasPesada=-1;
int filaActual=-1;
int suma=0;
	for(int j=0;j<columnas;j++){
		for(int i=0;i<filas;i++){
			suma=suma+pesos[i][j];
			filaActual=i;
		}
		if (suma>mayor){
			filamasPesada=filaActual;
		}
		suma=0;
	}
return filamasPesada;
}

int filaliviana(int pesos[filas][columnas]){
int menor=INT_MAX;
int filaMasLiviana=-1;
int suma=0;
	for(int j=0;j<columnas;j++){
		for(int i=0;i<filas;i++){
			suma=suma+pesos[i][j];
			if (suma<menor){
				filaMasLiviana=i;
			}
		}
		suma=0;
	}
return filaMasLiviana;
}

int cantidadTipoArticulo(string tipoArticulo[filas][columnas],string tipoArticuloBuscado){
int contador=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if 	(tipoArticulo[i][j]==tipoArticuloBuscado){
				contador=contador+1;
			}
		}
	}
	return contador;	
}

float promedioPesoPuerto(int pesos[filas][columnas],string puertoCarga[filas][columnas],string puertoBuscado){
	float promedio=0.0;
	float suma=0.0;
	float contador=0.0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (puertoCarga[i][j]==puertoBuscado){
				contador=contador+1;
				suma=suma+pesos[i][j];
			}
		}
	}
	promedio=suma/contador;
	return promedio;
}

string nombreEmpresaContenedorPesado(int pesos[filas][columnas], string marcas[filas][columnas]){
	int mayor=INT_MIN;
	string marcaPesada="";
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (pesos[i][j]>mayor){
				marcaPesada=marcas[i][j];
			}
		}
	}
	return marcaPesada;
}

string nombreEmpresaContenedorLiviano(int pesos[filas][columnas], string marcas[filas][columnas]){
	int menor=INT_MAX;
	string marcaLiviana="";
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if (pesos[i][j]<menor){
				marcaLiviana=marcas[i][j];
			}
		}
	}
	return marcaLiviana;
}

//LIMPIAR MATRICES
void limpiarMatriz(bool matrizBool[filas][columnas], int matrizInt[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			matrizBool[i][j]=1;
			matrizInt[i][j]=0;
		}
	}
}
//IMPRIMIR MATRICES
void mostrarMatrizBool(bool matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void mostrarMatrizTexto(string matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void mostrarMatrizEnteros(int matriz[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<matriz[i][j]<<"\t";
		}
		cout<<endl;
	}
}



