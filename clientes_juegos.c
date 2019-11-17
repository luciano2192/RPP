#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "clientes_juegos.h"

int menuABM() {
    int menu;

    printf("\n1) Alta. ");
    printf("\n2) Modificacion. ");
    printf("\n3) Baja. ");
    printf("\n4) Listar. ");
    printf("\n5) Alquilar juego.");
    printf("\n6) Listar juegos alquilados.");
    printf("\n7) Menu listar.");
    printf("\n8) Salir.");
    printf("\nSeleccionar una opcion <1-8>: ");
    scanf( "%d" , &menu );

    return menu;
};

int menuModificacion() {
    int menu;

    printf("\n1) Apellido. ");
    printf("\n2) Nombre. ");
    printf("\n3) Sexo. ");
    printf("\n4) Domicilio.");
    printf("\n5) Telefono.");
    printf("\n6) Salir.");
    printf("\nSeleccionar una opcion <1-6>: ");
    scanf( "%d" , &menu );

    return menu;
};

int menuListar() {
    int menu;

    printf("\n1) Promedio y total de los juegos alquilados. ");
    printf("\n2) La cantidad de juegos cuyo importe NO superan el promedio. ");
    printf("\n3) Listar clientes que alquilaron un juego determinado. ");
    printf("\n4) Listar todos los juegos que fueron alquilados por un cliente determinado.");
    printf("\n5) Listar el/los juego/s menos alquilado/s.");
    printf("\n6) Listar el/los clientes que realizo mas alquileres.");
    printf("\n7) Listar todos los juegos alquilados en una fecha determinada.");
    printf("\n8) Listar todos los clientes que realizaron al menos un alquiler en una fecha determinada.");
    printf("\n9) Listar todos los juegos ordenados por importe(descendente), utilizando el metodo de burbujeo mas eficiente.");
    printf("\n10) Listar todos los clientes ordenados por apellido (ascendente), utilizando el metodo de insercion.");
    printf("\n11) Salir.");
    printf("\nSeleccionar una opcion <1-11>: ");
    scanf( "%d" , &menu );

    return menu;
};

int inicializar( eCliente *list , eAlquiler *alquileres , int len ) {
    int respuesta = -1;

    for( int i = 0 ; i < len ; i++ ) {
        list[i].isEmpty = 1;
        alquileres[i].isEmpty = 1;
    }

    return respuesta;
}

int cliente_aumentar( eCliente *list , int cantidad ) {
   int i, maximo = 0;

   for( i = 0 ; i < cantidad ; i++ ) {
       if( (list[i].isEmpty == 0) && (list[i].codigo > maximo) ) {
           maximo = list[i].codigo;
       }
   }
   return maximo + 1;
};

int alquiler_aumentar( eAlquiler *list , int cantidad ) {
   int i, maximo = 0;

   for( i = 0 ; i < cantidad ; i++ ) {
       if( (list[i].isEmpty == 0) && (list[i].codAlquiler > maximo) ) {
           maximo = list[i].codAlquiler;
       }
   }
   return maximo + 1;
};

int cliente_estaVacio( eCliente *list , int length ) {
 int i , respuesta = 0;

 for ( i = 0 ; i < length ; i++ ) {
   if( list[i].isEmpty == 0 ) {
     respuesta = 1;
     break;
   }
 }

 return respuesta;
};

int juego_estaVacio( eJuego *list , int length ) {
 int i , respuesta = 0;

 for ( i = 0 ; i < length ; i++ ) {
   if( list[i].isEmpty == 0 ) {
     respuesta = 1;
     break;
   }
 }

 return respuesta;
};

int alquiler_estaVacio( eAlquiler *list , int length ) {
 int i , respuesta = 0;

 for ( i = 0 ; i < length ; i++ ) {
   if( list[i].isEmpty == 0 ) {
     respuesta = 1;
     break;
   }
 }

 return respuesta;
};

char verificaSioNo( char* msj , char* msjError ) {
    char letra;
    printf( "\n%s\n" , msj );
    letra = toupper( getchar() );
    fflush(stdin);
    while( letra != 'S' && letra != 'N' ) {
        printf( "\n%s\n" , msjError );
        letra = toupper( getchar() );
    }
    return letra;
};

int cliente_hayLugar( eCliente *list , int len ) {
 int i , respuesta = -1;

 for ( i = 0 ; i < len ; i++ ) {
   if( list[i].isEmpty != 0 ) {
     respuesta = i;
     break;
   }
 };

 return respuesta;
};

int alquiler_hayLugar( eAlquiler *list , int len ) {
 int i , respuesta = -1;

 for ( i = 0 ; i < len ; i++ ) {
   if( list[i].isEmpty != 0 ) {
     respuesta = i;
     break;
   }
 };

 return respuesta;
};

void formatear( char text[] ) {
  int i , len = strlen(text);

  text[0] = toupper(text[0]);

  for( i = 1 ; i < len ; i++ ) {
    text[i] = tolower(text[i]);
  }
};

void altaCliente( eCliente list[] , int len , char apellido[] , char
nombre[] , char sexo , char domicilio[] , char telefono[] ) {
    int lugar = 0;

    lugar = cliente_hayLugar( list , len );

    if( lugar != -1 ) {
        list[lugar].codigo = cliente_aumentar( list , len );
        formatear(apellido);
        formatear(nombre);
        formatear(domicilio);
        strcpy( list[lugar].apellido , apellido );
        strcpy( list[lugar].nombre , nombre );
        list[lugar].sexo = sexo;
        strcpy( list[lugar].domicilio , domicilio );
        strcpy( list[lugar].telefono , telefono );
        list[lugar].isEmpty = 0;
        printf("INGRESO EXITOSO !");
    }
};

int buscarCod( eCliente *list , int len , int codigo ) {
    int i;
    int codCliente = 0;

    for ( i = 0 ; i < len ; i++ ) {
        if ( list[i].codigo == codigo ) {
            codCliente = i;
        }
    };

    if( codCliente != 0 ){
        return codCliente;
    } else {
        return codCliente;
    }
};


int modificarCliente( eCliente* list , int len , int codigo ) {

    int cod , respuesta = -1 , menuMod;
    char verificar , auxSexo;
    char auxNombre[31] , auxApellido[31] , auxDomicilio[51] , auxTelefono[21];

    cod = buscarCod( list , len , codigo );
    fflush(stdin);

    if( cod != 0 ) {

        printf( "DATOS ENCONTRADOS" );
        printCliente( list , cod );

        printf("¿ Que desea modificar ?");
        menuMod = menuModificacion();

        switch( menuMod ) {
            case 1:
                getString( auxApellido , "Ingrese el apellido: " , "ERROR ! valor incorrecto" , 31 );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        formatear(auxApellido);
                        strcpy( list[cod].apellido , auxApellido );
                    }
                respuesta = 0;
            break;
            case 2:
                getString( auxNombre , "Ingrese el nombre: " , "ERROR ! valor incorrecto" , 31 );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        formatear(auxNombre);
                        strcpy( list[cod].nombre , auxNombre );
                    }
                respuesta = 0;
            break;
            case 3:
                auxSexo = pedirSexo( "Ingrese el sexo <F | M>: " , "ERROR ! valor incorrecto" );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        list[cod].sexo = auxSexo;
                    }
                respuesta = 0;
            break;
            case 4:
                getString( auxDomicilio , "Ingrese el domicilio: " , "ERROR ! valor incorrecto" , 51 );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        formatear(auxDomicilio);
                        strcpy( list[cod].domicilio , auxDomicilio );
                    }
                respuesta = 0;
            break;
            case 5:
                pedirTelefono( auxTelefono , "Ingrese el telefono: " , "ERROR ! valor incorrecto" , 21 );
                verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
                    if( verificar == 'S') {
                        strcpy( list[cod].telefono , auxTelefono );
                    }
                respuesta = 0;
            break;
            case 6:
              respuesta = 0;
            break;
        }
    }
  return respuesta;
}

void borrarCliente( eCliente *list , int len , int cod ) {

 int i;
 char verificar;

 i = buscarCod( list , len , cod );

    if( i != 0 && list[i].isEmpty != 1 ) {

    printf("DATOS ENCONTRADOS");
    printCliente( list , i );

    verificar = verificaSioNo("Esta seguro ? s/n", "Ingrese S o N.");
        if( verificar == 'S') {
            list[i].isEmpty = 1;
            printf("DATO ELIMINADO CON EXITO.");
        }
    } else {
        printf("DATO INEXISTENTE.");
    }
}

void clonarCliente( eCliente origen[] , eCliente destino[] , int len ) {
    int i;

    for(i=0;i<len;i++) {
        destino[i] = origen[i];
    }
}

void ordenarClientes( eCliente *list , int len ) {
    int i , j;
    eCliente aux;

    for( i = 0 ; i < len-1 ; i++ ) {
        if( list[i].isEmpty == 0 ) {
            for( j = i + 1 ; j < len ; j++ ) {
                if ( strcmp( list[i].apellido , list[j].apellido ) > 0 )  {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                if( (strcmp( list[i].apellido , list[j].apellido ) == 0) && (strcmp( list[i].nombre , list[j].nombre ) > 0) ) {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    };
}

void printCliente( eCliente *list , int cod ) {
    printf("\n%d\t%s\t%s\t%c\t%s\t%s",list[cod].codigo,list[cod].apellido,list[cod].nombre,list[cod].sexo,list[cod].domicilio,list[cod].telefono);
};

int printClientes( eCliente *list , int len ) {
    int i , vacio , resp = 0;
    vacio = cliente_estaVacio( list , len );
    if ( vacio == 1 ) {
        printf("\nLISTADO DE CLIENTES\n");
        printf("CODIGO\tAPELLIDO\tNOMBRE\tSEXO\tDOMICILIO\tTELEFONO\n");
        for ( i = 0 ; i < len ; i++ ) {
            if( list[i].isEmpty == 0 ) {
                printCliente( list , i );
            }
        };
    } else {
        resp = 1;
        printf("\nNO HAY DATOS CARGADOS.");
    }
    return resp;
};

int ordenarJuegos( eJuego* list , int len ) {
  int i , j;
  eJuego aux;

  for( i = 0 ; i < len-1 ; i++ ) {
    for( j = i + 1 ; j < len ; j++ ) {
      if ( strcmp( list[i].descripcion , list[j].descripcion ) > 0 )  {
        aux = list[i];
        list[i] = list[j];
        list[j] = aux;
      }
    }
  };

  return 0;
}

int printJuegos( eJuego *list , int len ) {
  int i , vacio , resp = 0;
    vacio = juego_estaVacio( list , len );
    if ( vacio == 1 ) {
        printf( "\nLISTADO DE JUEGOS\n" );
        printf( "ID\tDESCRIPCION\tPRECIO\n" );
        for ( i = 0 ; i < len ; i++ ) {
            if( list[i].isEmpty == 0 ) {
                printf( "%d\t%s\t%.2f\n" , list[i].codigo , list[i].descripcion , list[i].importe );
            }
        };
    } else {
        resp = 1;
        printf("\nNO HAY DATOS CARGADOS.");
    }
    return resp;
};

int printAlquileres( eAlquiler *list , int len ) {
    int i , vacio , resp = 0;
    vacio = alquiler_estaVacio( list , len );
    if ( vacio == 1 ) {
        printf( "\nLISTADO DE ALQUILERES\n" );
        printf( "ID\tCODIGO JUEGO\tCODIGO CLIENTE\tFECHA ALQUILER\n" );
        for ( i = 0 ; i < len ; i++ ) {
            if( list[i].isEmpty == 0 ) {
                printf( "%d\t%d\t%d\t%d-%d-%d\n" , list[i].codAlquiler , list[i].codJuego.codigo , list[i].codCliente.codigo , list[i].fecha.dia , list[i].fecha.mes, list[i].fecha.anio );
            }
        };
    } else {
        resp = 1;
        printf("\nNO HAY DATOS CARGADOS.");
    }
    return resp;
};


char pedirSexo( char msj[] , char errorMsj[] ) {
  char auxLetra;

  while( auxLetra != 'F' && auxLetra != 'M' ) {
    auxLetra = getChar( msj , errorMsj );
  }

  return auxLetra;
};


void altaAlquilerJuego( eAlquiler *alquileres, eJuego *juegos , eCliente *clientes , int len , int lenJuegos ) {

    int vacio , lugar , i;
    int idCliente = -1 , idJuego = -1 , auxJuego , auxCliente , auxDia , auxMes , auxAnio ;

    vacio = cliente_estaVacio( clientes , len );
    lugar = alquiler_hayLugar( alquileres , len );

    if( vacio != 0 && lugar != -1 ) {

        printClientes( clientes , len );
        printJuegos( juegos , lenJuegos );

        auxJuego = getInt( "Ingrese el codigo del juego: " , "ERROR ! valor incorrecto" , 0 , 100 );

        for ( i = 0 ; i < lenJuegos ; i++ ) {
            if( juegos[i].codigo == auxJuego ) {
                idJuego = juegos[i].codigo;
                break;
            }
        };

        auxCliente = getInt( "Ingrese el codigo del cliente: " , "ERROR ! valor incorrecto" , 0 , len );

        idCliente = buscarCod( clientes , len , auxCliente );

        if( idCliente != -1 && idJuego != -1 ) {

            alquileres[lugar].codAlquiler = alquiler_aumentar( alquileres , len );
            alquileres[lugar].codCliente.codigo = auxCliente;
            alquileres[lugar].codJuego.codigo = idJuego;

            auxDia = getInt( "Dia: " , "ERROR ! valor incorrecto" , 1 , 31 );
            auxMes = getInt( "Mes: " , "ERROR ! valor incorrecto" , 1 , 12 );
            auxAnio = getInt( "Anio: " , "ERROR ! valor incorrecto" , 1900 , 2019 );

            alquileres[lugar].fecha.dia = auxDia;
            alquileres[lugar].fecha.mes = auxMes;
            alquileres[lugar].fecha.anio = auxAnio;
            alquileres[lugar].isEmpty = 0;
            printf("INGRESO EXITOSO.");
        } else {
            printf("DATOS INEXISTENTES.");
        }
    }
}


void listarPedidos( eJuego *juegos , eAlquiler *alquileres , eCliente *clientes , int lenClientes , int lenJuegos , int lenAlquileres ) {

    float promedio;
    int superaPromedio, menu;

    printf("\n::::::::::::::::::::::::::::CONSULTAS DISPONIBLES::::::::::::::::::::::::::::\n");

    do {
        menu = menuListar();
        switch(menu) {

            case 1:
                promedioJuegosAlquilados( &promedio , juegos , lenJuegos , alquileres , lenAlquileres );
                break;
            case 2:
                if( promedio != 0 ) {
                    superaPromedio = noSuperanPromedio( promedio , juegos , lenJuegos );
                    printf("\nNO SUPERAN EL PROMEDIO: %d" , superaPromedio);
                } else {
                    printf("\nNO CALCULO EL PROMEDIO, SELECCIONE LA OPCION UNO PARA CALCULARLO.");
                    break;
                }
                break;
            case 3:
                clientesQueAlquilaronXjuego( juegos , alquileres , clientes , lenClientes , lenAlquileres , lenJuegos );
                break;
            case 4:
                juegosQueAlquilaronXcliente( juegos , alquileres , clientes , lenClientes , lenAlquileres , lenJuegos );
                break;
            case 5:
                juegosMenosAlquilados( juegos , alquileres , lenAlquileres , lenJuegos );
                break;
            case 6:
                clientesConMasAlquileres( clientes , alquileres , lenAlquileres , lenClientes );
                break;
            case 7:
                juegosXfecha( juegos , alquileres , lenAlquileres , lenJuegos );
                break;
            case 8:
                clientesQueAlquilaronXfecha( clientes , alquileres , lenAlquileres , lenClientes );
                break;
            case 9:
                juegosOrdenadosPorImporte( juegos , lenJuegos );
                printJuegos( juegos , lenJuegos );
                break;
            case 10:
                clientesOrdenadosPorApellido( clientes , lenClientes );
                printClientes( clientes , lenClientes );
                break;
            case 11:
                break;
        }
    } while( menu != 11 );
}

void promedioJuegosAlquilados(  float *input , eJuego* juego , int lenJue , eAlquiler* alquiler , int lenAlq ) {

  int i , j , cantidadJuegos = 0 ;
  float suma = 0, promedio = 0;

    for ( i = 0 ; i < lenAlq ; i++ ) {
        for ( j = 0 ; j < lenJue ; j++ ) {
            if ( alquiler[i].codJuego.codigo == juego[j].codigo ) {
                suma += juego[j].importe;
                cantidadJuegos++;
            }
        }
    }

    promedio = suma / cantidadJuegos;

    if( suma > 0 && promedio > 0 ) {

        printf( "\nPROMEDIO JUEGOS ALQUILADOS\n" );
        printf( "\nTOTAL\tPROMEDIO\n" );
        printf( "\n%.2f\t%.2f\n" , suma , promedio );

        *input = promedio;
    };
}


int noSuperanPromedio( float prom , eJuego* list , int len ) {

    int i , cant = 0;

    for ( i = 0 ; i < len ; i++ ) {
        if( list[i].importe < prom ) {
            cant++;
        }
    };

    return cant;
}


void clientesQueAlquilaronXjuego( eJuego* juego , eAlquiler* alquiler , eCliente* cliente , int lenCli , int lenAlq , int lenJuegos ) {

    int i , j , auxJuego;

    printJuegos( juego , lenJuegos );

    auxJuego = getInt( "Ingrese el codigo del juego: " , "ERROR ! valor incorrecto" , 0 , 100 );

    for ( i = 0 ; i < lenAlq ; i++ ) {
        if ( alquiler[i].codJuego.codigo == auxJuego ) {
            for ( j = 0 ; j < lenCli ; j++ ) {
                if ( alquiler[i].codCliente.codigo == cliente[j].codigo ) {
                    printf( "%s\t%s\n", cliente[j].nombre , cliente[j].apellido );
                }
            }
        }
    }
};

void juegosQueAlquilaronXcliente( eJuego* juego , eAlquiler* alquiler , eCliente* cliente , int lenCli , int lenAlq , int lenJuegos) {

    int i , j , auxCliente;

    printClientes( cliente , lenCli );

    auxCliente = getInt( "Ingrese el codigo del cliente: " , "ERROR ! valor incorrecto" , 0 , lenCli );

    for ( i = 0 ; i < lenAlq ; i++ ) {
        if ( alquiler[i].codCliente.codigo == auxCliente ) {
            for ( j = 0 ; j < lenJuegos ; j++ ) {
                if ( alquiler[i].codJuego.codigo == juego[j].codigo ) {
                    printf( "\n%s", juego[j].descripcion );
                }
            }
        }
    }
};

void juegosMenosAlquilados( eJuego* juego , eAlquiler* alquiler , int lenAlquileres , int lenJuegos ) {

    int i , j = 0 , k , min;

    printf( "\n::::::::::::::::::::JUEGO/S MENOS ALQUILADO/S::::::::::::::::::::" );

    for ( i = 1 ; i < lenAlquileres ; i++ ) {
        min = alquiler[j].codJuego.codigo;
        if( min != alquiler[i].codJuego.codigo ) {
            for( k=0;k<lenJuegos;k++ ){
                if( alquiler[i].codJuego.codigo == juego[k].codigo ) {
                    printf( "\n-->> %s", juego[k].descripcion );
                    j++;
                }
            }
        break;
        }
    };
};

void clientesConMasAlquileres( eCliente* clientes , eAlquiler* alquiler , int lenAlquiler , int lenCliente ) {

    int i , k , max;

    printf( "\n::::::::::::::::::::CLIENTE/S CON MAS ALQUILERES::::::::::::::::::::" );

    for ( i = 1 ; i < lenAlquiler ; i++ ) {
        max = alquiler[i-1].codCliente.codigo;
        if( max == alquiler[i].codCliente.codigo ) {
            for( k=0;k<lenCliente;k++ ){
                if( alquiler[i].codCliente.codigo == clientes[k].codigo ) {
                    printf( "\n-->> %s\t%s", clientes[k].nombre , clientes[k].apellido );
                    break;
                }
            }
        }
    };
};

void juegosXfecha( eJuego* juego , eAlquiler* alquiler , int lenAlquileres , int lenJuegos ) {

    int i , j , auxDia , auxMes , auxAnio;

    auxDia = getInt( "Ingrese el dia: " , "ERROR ! valor incorrecto" , 0 , 31 );
    auxMes = getInt( "Ingrese el mes: " , "ERROR ! valor incorrecto" , 0 , 12 );
    auxAnio = getInt( "Ingrese el anio: " , "ERROR ! valor incorrecto" , 1900 , 2019 );

    for ( i = 0 ; i < lenAlquileres ; i++ ) {
        if( auxDia == alquiler[i].fecha.dia
                && auxMes == alquiler[i].fecha.mes
                    && auxAnio == alquiler[i].fecha.anio ) {

            for( j=0 ; j<lenJuegos ; j++ ) {
                if( alquiler[i].codJuego.codigo == juego[j].codigo ) {
                    printf( "\n-->> %s", juego[j].descripcion );
                }
            }

        }
    };
};

void clientesQueAlquilaronXfecha( eCliente* cliente , eAlquiler* alquiler , int lenAlquileres , int lenClientes ) {

    int i , j , auxDia , auxMes , auxAnio;

    auxDia = getInt( "Ingrese el dia: " , "ERROR ! valor incorrecto" , 0 , 31 );
    auxMes = getInt( "Ingrese el mes: " , "ERROR ! valor incorrecto" , 0 , 12 );
    auxAnio = getInt( "Ingrese el anio: " , "ERROR ! valor incorrecto" , 1900 , 2019 );

    for ( i = 0 ; i < lenAlquileres ; i++ ) {
        if( auxDia == alquiler[i].fecha.dia
                && auxMes == alquiler[i].fecha.mes
                    && auxAnio == alquiler[i].fecha.anio ) {

            for( j=0 ; j<lenClientes ; j++ ) {
                if( alquiler[i].codCliente.codigo == cliente[j].codigo ) {
                    printf( "\n-->> %s\t%s", cliente[j].nombre , cliente[j].apellido );
                }
            }
        }
    };
};


void juegosOrdenadosPorImporte( eJuego* juegos , int lenJuegos ) {

    int i , flagNoEstaOrdenado = 1;
    eJuego auxJuego;

    while( flagNoEstaOrdenado == 1 ) {
        flagNoEstaOrdenado = 0;
        for ( i = 1 ; i < lenJuegos ; i++ ) {
            if( juegos[i].importe > juegos[i - 1].importe ) {
                auxJuego = juegos[i];
                juegos[i] = juegos[i - 1];
                juegos[i - 1] = auxJuego;
                flagNoEstaOrdenado = 1;
            }
        }
    }
};

void clientesOrdenadosPorApellido( eCliente* clientes , int lenClientes ) {

    int i,j;
    eCliente temp;
    for(i=1;i<lenClientes;i++) {
        temp = clientes[i];
        j=i-1;
        while(j>=0 && strcmp( clientes[j].apellido , temp.apellido ) < 0 )
        {
            clientes[j+1] = clientes[j];
            j--;
        }

        clientes[j+1]=temp;
    }
};
