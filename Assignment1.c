#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.142857
//function to round of the value
float Round(float r,int n){
    float y = roundf(r * pow(10,n)) / pow(10,n);
    return y;
    
}

//function to find the distance
float distance(float* A,float* B)
{
    float dist;
     dist=sqrt((pow((A[0]-B[0]),2)+pow((A[1]-B[1]),2)));
    return dist;
}

//function to multiply the matrices
float* multiplymatrix(float m1[2],float m2[2][2])
{
    
    float *mul = (float *) malloc(2 * sizeof(float));
    mul[0]=(m2[0][0])*(m1[0])+(m2[0][1])*(m1[1]);
    mul[1]=(m2[1][0])*(m1[0])+(m2[1][1])*(m1[1]);
    return mul;
}

//main function
int main ( void )
{
    int a11,a12,a21,a22;
float* a = (float*)malloc(2 * sizeof(float));
float* b = (float*)malloc(2 * sizeof(float));
float* c = (float*)malloc(2 * sizeof(float));
float (*trans)[2] = malloc(sizeof(float[2][2]));
float d12,d23,d31;
a[0]=1;a[1]=0;
b[0]=0;b[1]=2;
c[0]=2;c[1]=1;
printf("angle made by transformed x-axis with the given x-axis: ");
scanf("%d",&a11);
printf("angle made by transformed x-axis with the given y-axis:");
scanf("%d",&a12);
printf("angle made by transformed y-axis with the given x-axis:");
scanf("%d",&a21);
printf("angle made by transformed Y-axis with the given Y-axis:");
scanf("%d",&a22);
//transformation matrix
trans[0][0]=Round(cos((a11*pi)/180),3);
trans[0][1]=Round(cos((a12*pi)/180),3);
trans[1][0]=Round(cos((a21*pi)/180),3);
trans[1][1]=Round(cos((a22*pi)/180),3);

float* AT=  multiplymatrix(a, trans);
float* BT= multiplymatrix(b, trans);
float* CT= multiplymatrix(c, trans); 
d12=Round(distance(AT,BT),2);
d23=Round(distance(BT,CT),2);
d31=Round(distance(CT,AT),2);

printf("%f\n",d12);
printf("%f\n",d23);
printf("%f\n",d31);
if(d12==d23 && d23==d31)
{
    printf("It is an equilateral triangle");
}
else
{
    printf("It is not an equilateral triangle");
}
free(a);
free(b);
free(c);
free(trans);

}