#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

void calc_esfera (float r, float* area, float* volume);
int raizes (float a, float b, float c, float* x1, float* x2);
int pares (int n, int* vet);
void inverte (int n, int* vet);
double avalia (double* poli, int grau, double x);

int main(){
	//ESFERA
	float* area = malloc(sizeof(float));
	float* volume = malloc(sizeof(float));
	calc_esfera(2.0, area, volume);

	printf("%f\n", *area);
	printf("%f\n", *volume);
	free(area);
	free(volume);
	
	//Segundo grau
	float *x1 = malloc(sizeof(float));
	float *x2 = malloc(sizeof(float));
	if(raizes(4, -3, -1, x1, x2)){
			printf("%f %f\n", *x1, *x2);
		}
	else printf("Não foi, né?");
	free(x1);
	free(x2);
	
	//Vetor (pares e inversão)
	int* vet = (int *)malloc(41*sizeof(int)); //o tamanho original é 40
	preencheVetor(40, vet);
	printf("%d\n", pares(30, vet));
	inverte(40, vet);
	for(int i=0; i<=40; i++) printf("%d ", vet[i]);
	printf("\n");
	free(vet);
	
	//polinomio
	int grau = 2;
	double *poli = malloc((grau+1)*sizeof(double));
	
	poli[0] = 12;
	poli[1] = 2;
	poli[2] = 3;  
	printf("%lf\n", avalia(poli, 2, 4));
	free(poli);
	return 0;
}

void calc_esfera (float r, float* area, float* volume){
    *area = 4*PI*r*r;
    *volume = 4*PI*r*r*r/3;
}

int raizes (float a, float b, float c, float* x1, float* x2){
    float delta = pow(b,2) - 4*a*c;
    if(delta < 0) return 0;
    *x1 = ((-1)*b + sqrt(delta))/2*a;
    *x2 = ((-1)*b - sqrt(delta))/2*a;
    return 1;
}

int pares(int n, int* vet){
    int resultado = 0;
    for(int i=0; i<n; i++){
        if(vet[i]%2 == 0) resultado++;
    }
    return resultado;
}

void inverte(int n, int* vet){
    int aux = 0;
    for(int i=0; i <(n-n%2)/2; i++){
        aux = vet[i];
        vet[i] = vet[n-i];
        vet[n-i] = aux;
    }
}

double avalia (double* poli, int grau, double x){
    double resultado = 0;
    for(int i=0; i <= grau; i++){
        resultado += pow(x,i)*poli[i];
    }
    return resultado;
}