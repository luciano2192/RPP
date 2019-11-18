/**
*\brief Recibe dos cadenas de texto , dos numeros y muestra las cadenas de texto segun corresponda.
*\param msj el mensaje a mostrar.
*\param errorMsj el mensaje a mostrar en caso de error.
*\param minLimit el limite inferior.
*\param maxLimit el limite superior.
*\return El valor ingresado por el usuario.
*
*/
int getInt( char msj[] , char errorMsj[] , int minLimit , int maxLimit );

/**
*\brief Recibe dos cadenas de texto , dos numeros y muestra las cadenas de texto segun corresponda.
*\param msj el mensaje a mostrar.
*\param errorMsj el mensaje a mostrar en caso de error.
*\param minLimit el limite inferior.
*\param maxLimit el limite superior.
*\return El valor ingresado por el usuario.
*
*/
float getFloat( char msj[] , char errorMsj[] , float minLimit , float maxLimit );

/**
*\brief Recibe un puntero, dos cadenas de texto, un numeros y muestra las cadenas de texto segun corresponda.
*\param input donde se almacena el dato obtenido.
*\param msj el mensaje a mostrar.
*\param errorMsj el mensaje a mostrar en caso de error.
*\param limit el limite superior.
*\return El valor ingresado por el usuario.
*
*/
void getString( char *input , char msj[] , char errorMsj[] , int limit );

/**
*\brief Recibe dos cadenas de texto y muestra las cadenas de texto segun corresponda.
*\param msj el mensaje a mostrar.
*\param errorMsj el mensaje a mostrar en caso de error.
*\return El valor ingresado por el usuario.
*
*/
char getChar( char msj[] , char errorMsj[] );

/**
*\brief Recibe una cadena de texto y verifica que sea un numero.
*\param cadena texto a verificar.
*\return 0 si no es numero - 1 si es un numero.
*
*/
int esNumero( char cadena[] );

/**
*\brief Recibe una cadena de texto y la convierte en int.
*\param cadena texto a convertir.
*\return 0 si no es numero - un int si la cadena es un numero.
*
*/
int toInt( char cadena[] );

/**
*\brief Recibe una cadena de texto y la convierte en float.
*\param cadena texto a convertir.
*\return 0 si no es numero - un float si la cadena es un numero.
*
*/
float toFloat( char cadena[] );

/**
*\brief Recibe una cadena de texto y la guarda.
*\param nombre cadena de texto donde se guarda.
*\param cantidad limite de la cadena.
*
*/
void miFgets( char nombre[] , int cantidad );

/**
*\brief Recibe una cadena de texto y verifica que sean letras.
*\param letras texto a verificar.
*\return 0 si no son letras - 1 si son letras.
*
*/
int sonLetras( char letras[] );

/**
*\brief Recibe un puntero, dos cadenas de texto, un numeros y muestra las cadenas de texto segun corresponda.
*\param input donde se almacena el dato obtenido.
*\param msj el mensaje a mostrar.
*\param errorMsj el mensaje a mostrar en caso de error.
*\param limit el limite superior.
*\return El valor ingresado por el usuario.
*
*/
void pedirTelefono( char *input , char msj[] , char errorMsj[] , int limit );
