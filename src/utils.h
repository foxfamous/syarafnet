using namespace std;

template <class T>
T** createArray(int rows, int cols){
  T** array = new T*[rows];
  for(int row=0;row<rows;row++){
    array[row]= new T[cols];
  }
  for(int i=0; i<rows;i++){
    for(int j=0;j<cols;j++){
      array[i][j]=0;
    }
  }
  return array;
}

template <class IM, class IM_OUT>
void integralImage(IM * image, IM_OUT * outimage, int rows,int cols){
  int out_b,curpos,l1,l2,a,b,c,d;
  outimage[0]=(int)image[0];

  for (int j=1;j<cols;j++){
    outimage[j]=image[j]+outimage[j-1];
  }
	
  for(int i=1;i<rows;i++){
    curpos=i*cols;    
    outimage[curpos]=image[curpos]+outimage[curpos-cols];
   
  }
	
  for(int i=1;i<rows;i++){   
    for(int j=1;j<cols;j++){
      outimage[i*cols+j]=image[i*cols+j]+outimage[i*cols+j-1]+outimage[i*cols+j-cols]-outimage[i*cols+j-cols-1];
    }
  }	
}

template <class T, class U>
void averageFromIntegral(T* average, U* integralImage, int rows, int cols, int radius=2){
  int r=radius+1;
  int curpos,a,b,c,d;
  int area=(radius*2+1)*(radius*2+1);
  
  for(int i=r;i<rows-r;i++){
    for(int j=r;j<cols-r;j++){
      curpos=i*cols+j;
      b=curpos-r*cols;
      a=b-r;
      b+=radius;
      c=curpos+radius*cols;
      d=c+radius;
      c-=r;
      average[curpos]=(integralImage[a]+integralImage[d]-integralImage[b]-integralImage[c])/area;
    }
  }
}

template <class T, class U>
void averageIntegral(T* average, U* integralImage, int rows, int cols, int radius=2){
  int r=radius+1;
  T *curpos,*t,*l,*a,*b,*c,*d,*ti,*li,*ai,*offset;
  int l1,l2,temp,ci(cols+1),ri(rows+1);
  int area=(radius*2+1)*(radius*2+1);
  
  curpos=average+(radius)*cols;
  t=integralImage;
  l=integralImage+(2*radius+1)*cols;
  l1=2*radius+1;
  

int i;
  for( i=radius,offset=curpos,a=t,b=t+l1,c=l,d=l+l1;i<rows-radius-1;i++,curpos+=cols,t+=ci){
    
    for(int j=radius;j<cols-radius-1;j++,offset++,a++,b++,c++,d++){
      *(offset)+=*(a);
      *(offset)+=*(d);
      *(offset)-=*(c);
      *(offset)-=*(b);
    }
 
  }
}

template <class T,class U, class V>
void briefDescriptor(T* image, U* desc, V* patch, int rows, int cols){
  int desc_len=32;
  for(int i=20;i<rows-20;i+=5){
    for(int j=20;j<cols-20;j+=5){
      for(int k=0;k<desc_len;k++){
	desc[(i*cols+j)+k]=image[(i+patch[k])*cols+(j+patch[desc_len+k])]> image[(i+patch[desc_len*2+k])*cols+(j+patch[desc_len*3+k])];
      }
    }
  }
}