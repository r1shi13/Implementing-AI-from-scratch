#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    float *data;
    int rows;
    int cols;
} Matrix;

int main(){
    FILE *p=fopen("Salary.csv","r");
    char b1[255];
    char b2[255];

    int i=0;    
    
    if (fgets(b1, 255, p) != NULL) {
        printf("%s", b1);
    }
    int c=0;
    for (int i1=0;i1<255 && b1[i1]!='\0';i1++){
        if (b1[i1]==','){
            c++;
        }
    }
    Matrix m;
    m.rows=0;
    m.cols=c+1;
    m.data=(float*)malloc(sizeof(float)*m.cols);
    if (m.data == NULL) return 1;
    while(fgets(b2,255,p)!=NULL){
        m.data[i]=strtof(strtok(b2,","),NULL);
        for(int a=1;a<m.cols;a++){
            m.data[i+a]=strtof(strtok(NULL,","),NULL);     
        }
        m.rows++;
        i=m.rows*m.cols;
        float *temp=(float*)realloc(m.data,sizeof(float)*(m.cols+i));
        if(temp!=NULL){
            m.data=temp;
        }
        

    }
    for (int j=0;j<i;j+=m.cols){
        printf("%.2f,%.2f,%.2f \n",m.data[j],m.data[j+1],m.data[j+2]);
    }
    printf("\n%d\n%d",m.rows,i);
    fclose(p);
    free(m.data);
}