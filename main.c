#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "clientes_juegos.h"

#define TOTAL 4
#define CANTJUEGOS 4

eJuego juegos[CANTJUEGOS] = {
    { 33 , "Arcade Mario Kart" , 68.8 },
    { 55 , "Arcade Pacman" , 54.2 },
    { 76 , "Arcade Street Fighter" , 99.5 },
    { 15 , "Arcade Puzzle Bubble" , 32.9 },
};

int main()
{
    int opcionMenu , auxId , resPrint;
    char auxNombre[31] , auxApellido[31] , auxSexo , auxDomicilio[51] ,  auxTelefono[21];

    eCliente clientes[TOTAL];
    eCliente auxClientes[TOTAL];
    eAlquiler alquileres[TOTAL];

    alquileres_inicializar( alquileres , TOTAL );
    cliente_inicializar( clientes , TOTAL );

    do {

        opcionMenu = menuABM();

        switch( opcionMenu ) {
            case 1:
                if( cliente_hayLugar(clientes , TOTAL) == -1 ) {
                    printf("NO HAY LUGAR DISPONIBLE.");
                } else {
                    getString( auxApellido , "Ingrese el apellido: " , "ERROR ! valor incorrecto" , 31 );
                    getString( auxNombre , "Ingrese el nombre: " , "ERROR ! valor incorrecto" , 31 );
                    auxSexo = pedirSexo( "Ingrese el sexo <F | M>: " , "ERROR ! valor incorrecto" );
                    getString( auxDomicilio , "Ingrese el domicilio: " , "ERROR ! valor incorrecto" , 51 );
                    pedirTelefono( auxTelefono , "Ingrese el telefono: " , "ERROR ! valor incorrecto" , 21 );
                    altaCliente( clientes , TOTAL , auxApellido , auxNombre , auxSexo , auxDomicilio , auxTelefono );
                }
                break;
            case 2:
                resPrint = printClientes( clientes , TOTAL );
                if( resPrint != 1 ) {
                    auxId = getInt( "Ingrese el id: " , "ERROR ! valor incorrecto" , 0 , TOTAL );
                    modificarCliente( clientes , TOTAL , auxId );
                }
                break;
            case 3:
                resPrint = printClientes( clientes , TOTAL );
                if( resPrint != 1 ) {
                    auxId = getInt( "Ingrese el id: " , "ERROR ! valor incorrecto" , 0 , TOTAL );
                    borrarCliente( clientes , TOTAL , auxId );
                }
                break;
            case 4:
                clonarCliente( clientes , auxClientes , TOTAL );
                ordenarClientes( auxClientes , TOTAL );
                printClientes( auxClientes , TOTAL );
                break;
            case 5:
                altaAlquilerJuego( alquileres , juegos , clientes , TOTAL , CANTJUEGOS );
                break;
            case 6:
                printAlquileres( alquileres , TOTAL );
                break;
            case 7:
                listarPedidos( juegos , alquileres , clientes , TOTAL , CANTJUEGOS , TOTAL );
                break;
            case 8:
                break;
        }
    } while( opcionMenu != 8 );

    return 0;
}
