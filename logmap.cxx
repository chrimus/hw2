#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	
	float x_values[Nend-Nskip];
	ofstream out("output.dat");

	for(double r=0; r <= 4; r += 0.001){
	   x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1-x);
	   		   //cout << r << "\t" << x << endl;
			   //save x_101 in in x_values[0] and so forth
			   x_values[i-Nskip-1]= x;
   	   }
   	   //print r and current x_i values to file
   	   for(int i=1; i<=100; i++){
			   out << r << "\t" << x_values[i-1] << endl;
	   }
   	   
	}
	out.close();


	return 0;
}
