
#define SIZE 2

typedef struct s_monomio{

	int coeficiente;
	int grado;

}monomio;


void leer_monomio(monomio *p_monomio);

void imprimir_monomio(monomio *p_monomio);

monomio* mayor_menor_grado(monomio* pol);

void reading_vector(monomio* pol);

void calcular_valor(monomio* pol);
