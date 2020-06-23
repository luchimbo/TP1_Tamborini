#include <stdio.h>

#define MSJ_COMIENZO "Hola joven Padawan, voy a hacerte una serie de preguntas para saber mas de vos\n"
#define MSJ_MIDICLORIANOS "Cual es tu nivel de midiclorianos en tu organismo?\nEl nivel tiene que encontrarse en el rango de 100.0 y 2999.9\n"
#define MSJ_VOLUNTAD "Como es tu voluntad?\n Floja [f], Buena, [b], Mediana [m], Alta [a], Enorme [e], Peligrosa [p]\n"
#define MSJ_PASADO "Como ha sido tu pasado?\nBueno [b], Normal [n] o Tragico [t]\n"


const char DEF_VOLUNTAD = 'x';
#define VOLUNTAD_FLOJA 'f'
#define VOLUNTAD_BUENA 'b'
#define VOLUNTAD_MEDIANA 'm'
#define VOLUNTAD_ALTA 'a'
#define VOLUNTAD_ENORME 'e'
#define VOLUNTAD_PELIGROSA 'p'

const float DEF_VOLUNTAD_NUM = 2.234F;

const char DEF_PASADO = 'z';
#define PASADO_BUENO 'b'
#define PASADO_NORMAL 'n'
#define PASADO_TRAGICO 't'

const float DEF_PASADO_NUM = 3.543F;

const float DEF_MIDICLORIANOS = 1.346345F;
const float MIN_MIDICLORIANOS = 100.0F;
const float MAX_MIDICLORIANOS = 2999.9F;


const float INFLUENCIA = 3.4F;
const float OSCURIDAD = 0.001117684315F;

const float VALOR_VOL_FLOJA_BUENA = 10.3F;
const float VALOR_VOL_MED_ALTA = 54.5F;
const float VALOR_VOL_ENOR_PEL = 103.4F;

const float VALOR_PAS_NORM_TRAGICO = 0.4F;
const float VALOR_PAS_BUENO = 1.5F;

void comienzo(){
	printf(MSJ_COMIENZO);
}

float recibir_midiclorianos()
{

	float midiclorianos_recibido = DEF_MIDICLORIANOS;
	printf(MSJ_MIDICLORIANOS);
	scanf("%f", &midiclorianos_recibido);

	while ((midiclorianos_recibido < MIN_MIDICLORIANOS) || (midiclorianos_recibido > MAX_MIDICLORIANOS))
	{
		printf("No se encuentra dentro del rango. Intente de nuevo\n");
		printf(MSJ_MIDICLORIANOS);
		scanf("%f", &midiclorianos_recibido);
	}

	return midiclorianos_recibido;
}

char recibir_voluntad()
{
	char voluntad_recibida = DEF_VOLUNTAD;
	printf(MSJ_VOLUNTAD);
	scanf(" %c", &voluntad_recibida);

	while ((voluntad_recibida != VOLUNTAD_ALTA) && (voluntad_recibida != VOLUNTAD_PELIGROSA) && (voluntad_recibida != VOLUNTAD_ENORME) && (voluntad_recibida != VOLUNTAD_MEDIANA) && (voluntad_recibida != VOLUNTAD_BUENA) && (voluntad_recibida != VOLUNTAD_FLOJA))
	{	
	printf("No entiendo lo que estas diciendo. Intente de nuevo\n");
	printf(MSJ_VOLUNTAD);
	scanf(" %c", &voluntad_recibida);
	}
	return voluntad_recibida;
}


char recibir_pasado()
{
	char pasado_recibido = DEF_PASADO;
	printf(MSJ_PASADO);
	scanf(" %c", &pasado_recibido);

	while ((pasado_recibido != PASADO_BUENO) && (pasado_recibido != PASADO_NORMAL) && (pasado_recibido != PASADO_TRAGICO))
	{
	printf("No entiendo lo que estas diciendo. Intente de nuevo\n");
	printf(MSJ_PASADO);
	scanf(" %c", &pasado_recibido);
	}
	return pasado_recibido;
}

float valor_voluntad(char voluntad)
{
	float voluntad_num_recibido = DEF_VOLUNTAD_NUM;
	switch (voluntad)
	{
		case VOLUNTAD_ALTA:
			voluntad_num_recibido = VALOR_VOL_MED_ALTA;
			break;
		case VOLUNTAD_FLOJA:
			voluntad_num_recibido = VALOR_VOL_FLOJA_BUENA;
			break;
		case VOLUNTAD_BUENA:
			voluntad_num_recibido = VALOR_VOL_FLOJA_BUENA;
			break;
		case VOLUNTAD_MEDIANA:
			voluntad_num_recibido = VALOR_VOL_MED_ALTA;
			break;
		case VOLUNTAD_ENORME:
			voluntad_num_recibido = VALOR_VOL_ENOR_PEL;
			break;
		case VOLUNTAD_PELIGROSA:
			voluntad_num_recibido = VALOR_VOL_ENOR_PEL;
			break;
	}
return voluntad_num_recibido;
}

float valor_pasado (char pasado)
{
	float pasado_num_recibido = DEF_PASADO_NUM;
	switch(pasado){
	case PASADO_BUENO:
		pasado_num_recibido = VALOR_PAS_BUENO;
	case PASADO_TRAGICO:
		pasado_num_recibido = VALOR_PAS_NORM_TRAGICO;
	case PASADO_NORMAL:
		pasado_num_recibido = VALOR_PAS_NORM_TRAGICO;
	}
return pasado_num_recibido;
}


float calculo_probabilidad_convertirse(float voluntad_num, float pasado_num, float midiclorianos, float influencia_padawan){
	
	float probabilidad_convertirse;

 	probabilidad_convertirse = voluntad_num+(OSCURIDAD*influencia_padawan)/pasado_num;

 	return probabilidad_convertirse;
}

float calculo_convertirse_jedi(float voluntad_num, float influencia_padawan){
	float calculo_jedi_recibido;
	float voluntad_convertirse_jedi = ((voluntad_num*20/100)+voluntad_num);
	float influencia_convertirse_jedi = (influencia_padawan-(influencia_padawan*75/100));
	
	calculo_jedi_recibido = influencia_convertirse_jedi/voluntad_convertirse_jedi;
	return calculo_jedi_recibido;
}



int main(){

float midiclorianos = DEF_MIDICLORIANOS;
char voluntad = DEF_VOLUNTAD;
char pasado = DEF_PASADO;
float voluntad_num;
float pasado_num;
float probabilidad_convertirse;
float tiempo_jedi;

comienzo();

midiclorianos = recibir_midiclorianos();

float influencia_padawan = midiclorianos * INFLUENCIA;

printf("Midiclorianos recibidos = %f\n", midiclorianos);

voluntad = recibir_voluntad();

printf("Voluntad recibida: %c\n", voluntad);

pasado = recibir_pasado();

printf ("Pasado recibido: %c\n", pasado);

voluntad_num = valor_voluntad(voluntad); 

pasado_num = valor_pasado(pasado);

probabilidad_convertirse = calculo_probabilidad_convertirse(voluntad_num, pasado_num, midiclorianos, influencia_padawan);

printf("Probabilidad de convertirse al lado oscuro: %f\n", probabilidad_convertirse);

tiempo_jedi = (int)calculo_convertirse_jedi(voluntad_num, influencia_padawan);

printf("En %f en meses se convertira en jedi\n ", tiempo_jedi);

if (probabilidad_convertirse > 85)
printf("Transmite lo que has aprendido: fuerza, maestria; pero insensates, debilidad, fracaso tambien. ¡Si, fracaso sobre todo! El mejor profesor, el fracaso es.\n By Master Yoda\n"); 


return 0;
}