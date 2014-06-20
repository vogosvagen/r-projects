#include<iostream>

using namespace std;

void eularPath(int** matrix,int n){
	int oddv=0;
	int countodd=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
			if(matrix[i][j]==1)
				countodd++;
		}
		if(countodd%2==1)
			oddv++;
		cout<<"\n";
		countodd=0;
	}
	if(oddv==0 && n>0){
		cout<<"Eular circuit excists!\n";
	}
	else if(oddv==2)
		cout<<"Eular path excists!\n";
	else
		cout<<"No Eular path Found :(\n";	
}

void relation(int** matrix,int n){
	cout<<"Type in 0 or 1.\n 0 : U not connected to V.\n 1 : U connected to V\n"; 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int con=0;
			if(i==j)
				cout<<"Reflexive?";
			cout<<"is vertix "<<i+1<<" connected to vertix "<<j+1<<" : ";
			cin>>con;
			if(con==0 || con==1)
				matrix[i][j]=con;
			else
				matrix[i][j]=0;
			;
		}
	}
}

void print(int** matrix,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	int numVer=-1;
	
	while(numVer<=0){
		cout<<"How many Verticies? ";
		cin>>numVer;
	}
	int** matrix;
	matrix =new int* [numVer];
	for(int i=0;i<numVer;i++){
		matrix[i]=new int[numVer];
		for(int j=0;j<numVer;j++)
			matrix[i][j]=0;
	}
	int choice1=0,choice2=0;

	while(choice1==0){
		relation(matrix,numVer);
		cout<<"Is this correct?\n\n";
		print(matrix,numVer);
		
		cout<<"Enter 0 if you are not done yet.\nEnter 1 if you are done\n";
		
		cin>>choice1;
		if(choice1==0){
			cout<<"1- change number of verticies\n";
			cout<<"2- change relation between verticies\n";
			cin>>choice2;
			if(choice2==1){
				cout<<"How many Verticies? ";
				cin>>numVer;
				matrix =new int* [numVer];
				for(int i=0;i<numVer;i++){
					matrix[i]=new int[numVer];
					for(int j=0;j<numVer;j++)
						matrix[i][j]=0;
				}
			}
		}
	}

	cout<<"Checking Eular Path";
	eularPath(matrix,numVer);
	return 0;
}