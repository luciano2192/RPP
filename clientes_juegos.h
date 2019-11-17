typedef struct {
    int dia , mes , anio;
} eFecha;

typedef struct {
    int codigo;
    char descripcion[51];
    float importe;
    int isEmpty;
} eJuego;

typedef struct {
    int codigo;
    char apellido[31];
    char nombre[31];
    char sexo;
    char domicilio[51];
    char telefono[21];
    int isEmpty;
} eCliente;

typedef struct {
    int codAlquiler;
    eJuego codJuego;
    eCliente codCliente;
    eFecha fecha;
    int isEmpty;
} eAlquiler;


int menuABM();

int menuModificacion();

int menuListar();

int cliente_aumentar( eCliente *list , int );
int alquiler_aumentar( eAlquiler *list , int );

char verificaSioNo( char* msj , char* msjError );

int cliente_hayLugar( eCliente* list , int length );
int alquiler_hayLugar( eAlquiler* list , int length );

void formatear( char text[] );

void altaCliente( eCliente list[] , int len , char apellido[] , char
nombre[] , char sexo , char domicilio[] , char telefono[] );

int cliente_estaVacio( eCliente* list , int length );
int juego_estaVacio( eJuego* list , int length );
int alquiler_estaVacio( eAlquiler* list , int length );

int inicializar( eCliente *list , eAlquiler *alquileres , int len );

void borrarCliente( eCliente* list , int len , int codigo );

void ordenarClientes( eCliente *list , int len );

void printCliente( eCliente *list , int cod );

int printClientes( eCliente* list , int len );

int modificarCliente( eCliente* list , int len , int codigo );

int cliente_buscarCod( eCliente* list , int len , int codigo );
int juego_buscarCod( eJuego *list , int len , int codigo );

int ordenarJuegos( eJuego* list , int len );

int printJuegos( eJuego* list , int len );

char pedirSexo( char msj[] , char errorMsj[] );

void clonarCliente( eCliente origen[] , eCliente destino[] , int len );

void altaAlquilerJuego( eAlquiler *alquileres, eJuego *juegos , eCliente *clientes , int len , int lenJuegos );

int printAlquileres( eAlquiler *list , int len );

void listarPedidos( eJuego *juegos , eAlquiler *alquileres , eCliente *clientes , int lenClientes , int lenJuegos , int lenAlquileres );

void promedioJuegosAlquilados(  float *input , eJuego* juego , int lenJue , eAlquiler* alquiler , int lenAlq );

int noSuperanPromedio( float prom , eJuego* list , int len );

void clientesQueAlquilaronXjuego( eJuego* juego , eAlquiler* alquiler , eCliente* cliente , int lenCli , int lenAlq , int lenJuegos );

void juegosQueAlquilaronXcliente( eJuego* juego , eAlquiler* alquiler , eCliente* cliente , int lenCli , int lenAlq , int lenJuegos);

void juegosMenosAlquilados( eJuego* juego , eAlquiler* alquiler , int lenAlq , int lenJuegos );

void clientesConMasAlquileres( eCliente* clientes , eAlquiler* alquiler , int lenAlquiler , int lenCliente );

void juegosXfecha( eJuego* juego , eAlquiler* alquiler , int lenAlquileres , int lenJuegos );

void clientesQueAlquilaronXfecha( eCliente* cliente , eAlquiler* alquiler , int lenAlquileres , int lenClientes );

void juegosOrdenadosPorImporte( eJuego* juegos , int lenJuegos );

void clientesOrdenadosPorApellido( eCliente* clientes , int lenClientes );
