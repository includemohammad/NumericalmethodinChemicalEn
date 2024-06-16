/*****************************
 ******SERIES PROBLEM*********
 ****************************/
#include<stdio.h>
#include<math.h>
#include<conio.h>
main(){
    FILE *fp=NULL;
    fp=fopen("seriesProblem4.txt","w");
    double t0,t1,R,sum,z,eps;
    printf("Enter the desired accuracy: ");
    scanf("%lf",&eps);
    for(z=0;z<=1;z=z+0.1){
        int i=1;
        //Initialize First Term
        t0=z;
        //Make sum equal to the first term
        sum=t0;
        do{
            //Find the ratio of the second term to the first term using already known relation
            R=-(M_PI*M_PI*pow(z,4))/((4*i+1));
            //Calculate the second term
            t1=R*t0;
            //find the new sum
            sum=sum+t1;
            t0=t1;
            i++;
            //keep on summing terms until the required accuracy is reached
        }while(fabs(t1/sum)>eps);
        sum=sum*cos(M_PI*z*z/2);
        fprintf(fp,"%lf\t%lf\n",z,sum);
    }
     getch();
     return 0;
}