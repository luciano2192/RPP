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

/**
*\brief Muestra el menu principal del abm.
*\return El valor ingresado por el usuario.
*
*/
int menuABM();

/**
*\brief Muestra el menu para modificar los datos del abm.
*\return El valor ingresado por el usuario.
*
*/
int menuModificacion();

/**
*\brief Muestra el menu para listar los datos ingresados.
*\return El valor ingresado por el usuario.
*
*/
int menuListar();

/**
*\brief aumenta automaticamente el indice.
*\param list lista.
*\param int largo de la lista.
*\return El indice.
*
*/
int cliente_aumentar( eCliente *list , int );

/**
*\brief aumenta automaticamente el indice.
*\param list lista.
*\param int largo de la lista.
*\return El indice.
*
*/
int alquiler_aumentar( eAlquiler *list , int );

/**
*\brief verifica S o N.
*\param msj mensaje a mostrar.
*\param msjError mensaje a mostrar en caso de error.
*\return El valor ingresado.
*
*/
char verificaSioNo( char* msj , char* msjError );

/**
*\brief verifica si hay lugar disponible.
*\param list lista a recorrer.
*\param length largo de la lista.
*\return -1 si no hay lugar - int con posicion del lugar disponible.
*
*/
int cliente_hayLugar( eCliente* list , int length );

/**
*\brief verifica si hay lugar disponible.
*\param list lista a recorrer.
*\param length largo de la lista.
*\return -1 si no hay lugar - int con posicion del lugar disponible.
*
*/
int alquiler_hayLugar( eAlquiler* list , int length );

/**
*\brief formatea una cadena de texto, primer letra en mayuscula el resto en minuscula.
*\param text cadena a formatear.
*
*/
void formatear( char text[] );

/**
*\brief agrega un cliente a la lista.
*\param list lista donde se agregan.
*\param len largo de la lista.
*\param apellido cadena de texto.
*\param nombre cadena de texto.
*\param sexo caracter.
*\param domicilio cadena de texto.
*\param telefono cadena de texto.
*
*/
void altaCliente( eCliente list[] , int len , char apellido[] , char
nombre[] , char sexo , char domicilio[] , char telefono[] );

/**
*\brief verifica si la lista esta vacia.
*\param list lista a recorrer.
*\param length largo de la lista.
*\return 0 si no esta vacia - 1 si esta vacia.
*
*/
int cliente_estaVacio( eCliente* list , int length );

/**
*\brief verifica si la lista esta vacia.
*\param list lista a recorrer.
*\param length largo de la lista.
*\return 0 si no esta vacia - 1 si esta vacia.
*
*/
int juego_estaVacio( eJuego* list , int length );

/**
*\brief verifica si la lista esta vacia.
*\param list lista a recorrer.
*\param length largo de la lista.
*\return 0 si no esta vacia - 1 si esta vacia.
*
*/
int alquiler_estaVacio( eAlquiler* list , int length );

/**
*\brief inicializa la lista.
*\param alquileres lista a recorrer.
*\param len largo de la lista.
*\return -1 si no inicializo - 0 si fue exitoso.
*
*/
int alquileres_inicializar( eAlquiler *alquileres , int len );

/**
*\brief inicializa la lista.
*\param list lista a recorrer.
*\param len largo de la lista.
*\return -1 si no inicializo - 0 si fue exitoso.
*
*/
int cliente_inicializar( eCliente *list , int len );

/**
*\brief elimina un dato de la lista.
*\param list lista a recorrer.
*\param len largo de la lista.
*\param codigo codigo a buscar.
*
*/
void borrarCliente( eCliente* list , int len , int codigo );

/**
*\brief ordena la lista.
*\param list lista a recorrer.
*\param len largo de la lista.
*
*/
void ordenarClientes( eCliente *list , int len );

/**
*\brief imprime los datos de un cliente.
*\param list lista a recorrer.
*\param cod codigo a buscar.
*
*/
void printCliente( eCliente *list , int cod );

/**
*\brief imprime los datos de todos los cliente.
*\param list lista a recorrer.
*\param len largo de la lista.
*\return 0 si se puede imprimir - 1 si no se puede.
*
*/
int printClientes( eCliente* list , int len );

/**
*\brief modifica los datos de un cliente.
*\param list lista a recorrer.
*\param len largo de la lista.
*\param cod del cliente a modificar.
*\return 0 si se modifico - -1 si no se modifico.
*
*/
int modificarCliente( eCliente* list , int len , int codigo );

/**
*\brief busca un cliente.
*\param list lista a recorrer.
*\param len largo de la lista.
*\param cod del cliente a buscar.
*\return 0 si no se encuentra - codigo del cliente.
*
*/
int buscarCod( eCliente *list , int len , int codigo );

/**
*\brief ordena la lista.
*\param list lista a recorrer.
*\param len largo de la lista.
*\return 0 al finalizar.
*
*/
int ordenarJuegos( eJuego* list , int len );

/**
*\brief imprime los datos de todos los juegos.
*\param list lista a recorrer.
*\param len largo de la lista.
*\return 0 si se puede imprimir - 1 si no se puede.
*
*/
int printJuegos( eJuego* list , int len );

/**
*\brief Recibe dos cadenas de texto y muestra las cadenas de texto segun corresponda.
*\param msj el mensaje a mostrar.
*\param errorMsj el mensaje a mostrar en caso de error.
*\return El valor ingresado por el usuario.
*
*/
char pedirSexo( char msj[] , char errorMsj[] );

/**
*\brief copia la estructura origen a destino.
*\param origen estructura a ser copiada.
*\param destino estructura copia.
*\param len largo de la lista.
*
*/
void clonarCliente( eCliente origen[] , eCliente destino[] , int len );

/**
*\brief agrega un alquiler a la lista.
*\param alquileres lista donde se agregan.
*\param juegos lista de juegos.
*\param clientes lista de clientes.
*\param len largo lista.
*\param lenJuegos largo lista juegos.
*
*/
void altaAlquilerJuego( eAlquiler *alquileres, eJuego *juegos , eCliente *clientes , int len , int lenJuegos );

/**
*\brief imprime los datos de todos los alquileres.
*\param list lista a recorrer.
*\param len largo de la lista.
*\return 0 si se puede imprimir - 1 si no se puede.
*
*/
int printAlquileres( eAlquiler *list , int len );

/**
*\brief muestra las distintas consultas disponibles .
*\param juegos lista de juegos.
*\param alquileres lista de alquileres.
*\param clientes lista de clientes.
*\param lenClientes largo de la lista clientes.
*\param lenJuegos largo de la lista juegos.
*\param lenAlquileres largo de la lista alquileres.
*
*/
void listarPedidos( eJuego *juegos , eAlquiler *alquileres , eCliente *clientes , int lenClientes , int lenJuegos , int lenAlquileres );

/**
*\brief Promedio y total de los juegos alquilados.
*\param input donde se almacena el promedio.
*\param juego lista de juegos.
*\param alquiler lista de alquileres.
*\param lenJue largo de la lista juegos.
*\param lenAlq largo de la lista alquileres.
*
*/
void promedioJuegosAlquilados(  float *input , eJuego* juego , int lenJue , eAlquiler* alquiler , int lenAlq );

/**
*\brief La cantidad de juegos cuyo importe NO superan el promedio.
*\param prom el promedio a comparar.
*\param list lista de juegos.
*\param len largo de la lista juegos.
*\return 0 caso de error - int con cantidad si se puede.
*
*/
int noSuperanPromedio( float prom , eJuego* list , int len );

/**
*\brief Listar clientes que alquilaron un juego determinado.
*\param juego lista de juegos.
*\param alquiler lista de alquileres.
*\param cliente lista de clientes.
*\param lenCli largo de la lista clientes.
*\param lenJuegos largo de la lista juegos.
*\param lenAlq largo de la lista alquileres.
*
*/
void clientesQueAlquilaronXjuego( eJuego* juego , eAlquiler* alquiler , eCliente* cliente , int lenCli , int lenAlq , int lenJuegos );

/**
*\brief Listar todos los juegos que fueron alquilados por un cliente determinado.
*\param juego lista de juegos.
*\param alquiler lista de alquileres.
*\param cliente lista de clientes.
*\param lenCli largo de la lista clientes.
*\param lenJuegos largo de la lista juegos.
*\param lenAlq largo de la lista alquileres.
*
*/
void juegosQueAlquilaronXcliente( eJuego* juego , eAlquiler* alquiler , eCliente* cliente , int lenCli , int lenAlq , int lenJuegos);

/**
*\brief Listar el/los juego/s menos alquilado/s.
*\param juego lista de juegos.
*\param alquiler lista de alquileres.
*\param lenJuegos largo de la lista juegos.
*\param lenAlq largo de la lista alquileres.
*
*/
void juegosMenosAlquilados( eJuego* juego , eAlquiler* alquiler , int lenAlq , int lenJuegos );

/**
*\brief Listar el/los clientes que realizo mas alquileres.
*\param clientes lista de clientes.
*\param alquiler lista de alquileres.
*\param lenCliente largo de la lista clientes.
*\param lenAlquiler largo de la lista alquileres.
*
*/
void clientesConMasAlquileres( eCliente* clientes , eAlquiler* alquiler , int lenAlquiler , int lenCliente );

/**
*\brief Listar todos los juegos alquilados en una fecha determinada.
*\param juego lista de juegos.
*\param alquiler lista de alquileres.
*\param lenJuegos largo de la lista juegos.
*\param lenAlquileres largo de la lista alquileres.
*
*/
void juegosXfecha( eJuego* juego , eAlquiler* alquiler , int lenAlquileres , int lenJuegos );

/**
*\brief Listar todos los clientes que realizaron al menos un alquiler en una fecha determinada.
*\param cliente lista de clientes.
*\param alquiler lista de alquileres.
*\param lenClientes largo de la lista clientes.
*\param lenAlquileres largo de la lista alquileres.
*
*/
void clientesQueAlquilaronXfecha( eCliente* cliente , eAlquiler* alquiler , int lenAlquileres , int lenClientes );

/**
*\brief Listar todos los juegos ordenados por importe(descendente), utilizando el metodo de burbujeo mas eficiente.
*\param juegos lista de juegos.
*\param lenJuegos largo de la lista juegos.
*
*/
void juegosOrdenadosPorImporte( eJuego* juegos , int lenJuegos );

/**
*\brief Listar todos los clientes ordenados por apellido (ascendente), utilizando el metodo de insercion.
*\param clientes lista de clientes.
*\param lenClientes largo de la lista clientes.
*
*/
void clientesOrdenadosPorApellido( eCliente* clientes , int lenClientes );
