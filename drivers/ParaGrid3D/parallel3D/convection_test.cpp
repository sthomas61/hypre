#include <math.h>


//============================================================================
int Type_Boundary(double x, double y, double z){
  if (x < 0.00001 || x>999.9999)
    return Dirichlet;
  else
    return Neumann;
}


//============================================================================
// This is a convection dominated problem. We have the exact solution.
//============================================================================
double exact(double *c){
  return sin(c[0]*(c[1]+1)*(c[2]+2)) ;
}
//============================================================================
void func_K(double *c, double K[][3], int atribut){
  K[0][0] = 1.;  K[0][1] = 0.;  K[0][2] = 0.;
  K[1][0] = 0.;  K[1][1] = 1.;  K[1][2] = 0.;
  K[2][0] = 0.;  K[2][1] = 0.;  K[2][2] = 1.;
}
//============================================================================
void func_K_Inv(double *c, double K[][3], int atribut){
  K[0][0] = 1.;  K[0][1] = 0.;  K[0][2] = 0.;
  K[1][0] = 0.;  K[1][1] = 1.;  K[1][2] = 0.;
  K[2][0] = 0.;  K[2][1] = 0.;  K[2][2] = 1.;
}

//============================================================================
double func_c(double *c){
  return 0.0;
}

//============================================================================
double func_f(double *c){
  double x = c[0], y=c[1], z = c[2];

  return (sin(x*(y+1)*(z+2))*(y+1)*(y+1)*(z+2)*(z+2) +
	  sin(x*(y+1)*(z+2))*x*x*(z+2)*(z+2) + 
	  sin(x*(y+1)*(z+2))*x*x*(y+1)*(y+1)
	  + 100000*cos(x*(y+1)*(z+2))*(y+1)*(z+2)
	  + 20000*cos(x*(y+1)*(z+2))*x*(z+2)
	  + 3000*cos(x*(y+1)*(z+2))*x*(y+1));
}

//============================================================================
// Dirichlet boundary value
//============================================================================
double func_u0(double *c){
  return exact(c);
}

//============================================================================

double func_gn(double *c){
  return 0.;
}

//============================================================================

void func_b(double *c, double b[3]){
  b[0] = 100000.;
  b[1] = 20000.;
  b[2] = 3000.;
}

//============================================================================
