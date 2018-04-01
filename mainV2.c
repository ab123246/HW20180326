#include<stdio.h>
#include<stdlib.h>
#include"main.h"

int GCDVerify(int, int);
int main(){
    int Num1,Num2,ans;
    boolean FactorizationVerifyAns,AlgorithmVerifyAns;
    FactorizationVerifyAns=test_gcd_using_factorization();
    fprintf(stderr,"factorization VerifyAns=%d",FactorizationVerifyAns);
    AlgorithmVerifyAns=test_gcd_using_euclidean_algorithm();
    fprintf(stderr,"\neuclidean algorithm VerifyAns=%d",AlgorithmVerifyAns);
}

int gcd_using_factorization(int Num1,int Num2){
    int c,GCD=1;
	if(Num1<=Num2)
    	c=Num1;
	else
	    c=Num2;
	for(int LoopNum1=2; LoopNum1<=c; LoopNum1++){
    	if((Num1%LoopNum1==0)&&(Num2%LoopNum1==0)){
        	GCD*=LoopNum1;
        	Num1/=LoopNum1;
        	Num2/=LoopNum1;
        	LoopNum1--;
    	}
	}
	return GCD;
}
int gcd_using_euclidean_algorithm(int Num1,int Num2){
    int GCD;
    while(Num1>0 || Num2>0){
        if(Num1>Num2 && Num1%Num2!=0){
            Num1%=Num2;
            GCD=Num1;
        }else if (Num2>Num1 && Num2%Num1!=0){
            Num2%=Num1;
            GCD=Num2;
        }else{
            if(Num2>Num1)
                GCD=Num1;
            else
                GCD=Num2;
            break;
        }
    }
    return GCD;
}

boolean test_gcd_using_factorization(){
    for(int LoopNum1=1;LoopNum1<=1000;LoopNum1++)
        for(int LoopNum2=1;LoopNum2<=1000;LoopNum2++)
            if(gcd_using_factorization(LoopNum1,LoopNum2) != GCDVerify(LoopNum1,LoopNum2))
            return false;return true;
    return true;
}
boolean test_gcd_using_euclidean_algorithm(){
    for(int LoopNum1=1;LoopNum1<=1000;LoopNum1++)
        for(int LoopNum2=1;LoopNum2<=1000;LoopNum2++)
            if(gcd_using_euclidean_algorithm(LoopNum1,LoopNum2) != GCDVerify(LoopNum1,LoopNum2))
                return false;
    return true;
}
int GCDVerify(int a, int b)
{
	if (b)
            while((a %= b) && (b %= a))
                ;
	return a + b;
}
