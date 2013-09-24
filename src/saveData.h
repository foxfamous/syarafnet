
#include <string>
using namespace std;

template <class T>
void saveData(T* image,const char * filename,int rows, int cols,bool isFloat=false){
  T* input=image;
  FILE *stream;
  stream=fopen( filename, "w" );
  const char *format=isFloat?"%f,":"%i,";
  if(stream!=NULL){
    for(int x = 0; x < rows; x++){
      for(int y = 0; y < cols; y++){	
	fprintf( stream, format, (T)*(input+x*cols+y) );		
      }
      fprintf( stream, "\n" );
    }
    fclose( stream );
  }
}

