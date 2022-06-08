#include <iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<vector>
#include<math.h>
using namespace std;
//prototype
char name[50];
int nfilas();
int ncol(int);
int elementos;
vector<string>datos;
//principal funtion
int main(){
	cout<<"dame el nombre del archivo (agregar .csv)";
	cin>>name;
	int filas=nfilas();
	int col=ncol(filas);
	int car[filas][col];
	int cmod[filas-2][col-2];
	int n=0,imod=0,jmod=0;
	cout<<"\n filas, columnas, elementos "<<filas<<","<<col<<","<<elementos<<endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<col;j++){			
			cout<<"pos"<<i<<j;
			car[i][j]=stoi(datos.at(n));
			cout<<"car "<<car[i][j]<<"<- "<<n<<endl;
			n++;
		}
		
	}
	//procesado
	//creacion del nuevo archivo
	ofstream file;
	file.open("imagenmod.csv",ios::out);
	if(file.fail()){
		cout<<"error no se pudo generar el archivo";
		exit(1);
	}
	//print
	cout<<"\n \t mod"<<endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<col;j++){
			cout<<"pos: "<<i<<j<<" "<<car[i][j]<<endl;
			
		}
	}
	//procesar
	for(int i=0;i<filas-2;i++){
		for(int j=0;j<col-2;j++){			
			cout<<"pos"<<i<<j;
			cmod[imod][jmod]=(car[i][j]+car[i][j+1]+car[i][j+2]+car[i+1][j]+car[i+1][j+1]+car[i+1][j+2]+car[i+2][j]+car[i+2][j+1]+car[i+2][j+2])/9;
			cout<<"car "<<cmod[imod][jmod]<<"<- "<<imod<<jmod<<endl;
			file<<cmod[imod][jmod]<<",";
			jmod++;
		}
		imod++;
		file<<endl;	
	}
	file.close();
	system("imagenmod.csv");
	system("pause");
	return 0;
}
//definition 
//obteniendo datos del archivo
int nfilas(){
	int cont=0;
	ifstream infile(name);
	string line= "";
	vector<string>datos_csv;
	while(getline(infile,line)){
		cont++;
		stringstream strstr(line);
		string word="";
		while (getline(strstr,word,';')){
			datos_csv.push_back(word);
		}
	}
	cout<<"\n";
	for(int i=0;i<datos_csv.size();i++){
		cout<<datos_csv.at(i)<<"\n";	
	}
	infile.close();
	return cont;
}
int ncol(int filas){
	int cont=0;
	ifstream infile(name);
	string line="";
	while(getline(infile,line)){
		stringstream strstr(line);
		string word="";
		while(getline(strstr,word,',')){
			datos.push_back(word);
			cont++;
		}
	}
	elementos=cont;
	cont/=filas;
	cout<<"\n";
	infile.close();
	return cont;
}