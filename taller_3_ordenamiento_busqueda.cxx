#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

#include <list>
#include <set>

// TODO #1: incluir cabecera arbol AVL
#include "ArbolAVL.h"

// -------------------------------------------------------------------------
typedef std::list< std::string > TList;
typedef std::set< std::string >  TSet;
// TODO #2: definir arbol AVL de tipo std::string
typedef ArbolAVL< std::string > TAVL;

// -------------------------------------------------------------------------
template< class TArbol >
bool LeerArbol( TArbol& arbol, const std::string& nomArch );

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  if( argc < 2 )
  {
    std::cerr << "Uso: " << argv[ 0 ] << " archivo_entrada" << std::endl;
    return( -1 );

  } // fi

  // Declarar arboles a usar
  TSet miArbolRN; // arbol rojinegro
  // TODO #3: arbol AVL 
  TAVL miArbolAVL;

  // Llenar arbol rojinegro y calcular el tiempo empleado
  std::clock_t inicioLecturaRN = std::clock( );
  bool lecturaRN = LeerArbol( miArbolRN, argv[ 1 ] );
  std::clock_t finLecturaRN = std::clock( );
  double tiempoLecturaRN = ( finLecturaRN - inicioLecturaRN ) / double( CLOCKS_PER_SEC );
  if( lecturaRN )
    std::cout
      << "Tiempo de llenado arbol RN = "
      << tiempoLecturaRN << "segs."
      << std::endl;
  else
    std::cout
      << "Error al leer \"" << argv[ 1 ]
      << "\" para llenar el arbol RN."
      << std::endl;
  
  // Llenar arbol AVL y calcular el tiempo empleado
  std::clock_t inicioLecturaAVL = std::clock( );
  // TODO #4: usar el archivo para llenar el arbol AVL 
  bool lecturaAVL = LeerArbol( miArbolAVL, argv[ 1 ] );
  std::clock_t finLecturaAVL = std::clock( );
  double tiempoLecturaAVL = ( finLecturaAVL - inicioLecturaAVL ) / double( CLOCKS_PER_SEC );
  /* TODO #5: informar tiempo de llenado del arbol AVL */
     if( lecturaAVL )
     std::cout
     << "Tiempo de llenado arbol AVL = "
     << tiempoLecturaAVL << "segs."
     << std::endl;
     else
     std::cout
     << "Error al leer \"" << argv[ 1 ]
     << "\" para llenar el arbol AVL."
     << std::endl;


  // Obtener el recorrido en inorden del arbol AVL
  TList inordenAVL;
  // TODO #6: llamar funcion que genera el recorrido en inorden
  miArbolAVL.inordenEnLista( inordenAVL );
  if( inordenAVL.size( ) != miArbolRN.size( ) )
  {
    std::cout << "Cantidad de elementos en los arboles no coinciden." << std::endl;
    return( -1 );

  } // fi

  // Comparar los arboles
  TSet::const_iterator rnIt = miArbolRN.begin( );
  TList::const_iterator avlIt = inordenAVL.begin( );
  bool iguales = true;
  for( ; rnIt != miArbolRN.end( ); rnIt++, avlIt++ )
    iguales &= ( *rnIt == *avlIt );

  // Informar si los arboles coinciden o no
  std::cout << "Los arboles ";
  if( !iguales )
    std::cout << "no ";
  std::cout << "coinciden." << std::endl;
  
  return( 0 );
}

// -------------------------------------------------------------------------
template< class TArbol >
bool LeerArbol( TArbol& arbol, const std::string& nomArch )
{
  std::ifstream entrada( nomArch.c_str( ) );
  if( !entrada )
    return( false );
  while( !entrada.eof( ) )
  {
    std::string codigo, valor;
    entrada >> codigo >> valor;
    if( codigo == "add" )
      arbol.insert( valor );  // El arbol debe proveer el metodo "insert"
    else if( codigo == "del" )
      arbol.erase( valor );   // El arbol debo proveer el metodo "erase"

  } // elihw
  entrada.close( );
  return( true );
}

// eof - taller_3_ordenamiento_busqueda.cxx
