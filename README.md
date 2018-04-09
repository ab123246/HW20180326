# HW20180326
GCD LCM program verify

程式碼:V1

```c
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
            Num1-=Num2;
            GCD=Num1;
        }else if (Num2>Num1 && Num2%Num1!=0){
            Num2-=Num1;
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

```

執行結果:V1

![image](https://raw.githubusercontent.com/andyneko/HW20180326/master/1.jpg)

遇到的問題:使用%來求餘數進行輾轉相除法行運算時發生crash 

問題原因:運算時發生1/0的運算導致程式crash

![image](https://raw.githubusercontent.com/andyneko/HW20180326/master/2.jpg)

修改後版本

程式碼V2:

```c
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

```

修改後執行結果

![image](https://raw.githubusercontent.com/andyneko/HW20180326/master/3.jpg)

心得:

這次製作的程式是GCD & LCM的驗證程式以及.h檔的應用，在.h檔的使用上目前沒有遇到什麼問題，但是在程式運算上卻遇到了一些小錯誤。原本在打輾轉相除法的運算的時候是想使用取餘數的方式做運算，可是因為遇到crash的問題後來改成用遞減的方式，最後才回頭研究如何修正原本會crash的版本，這次主要還是犯了邏輯上面的錯誤，而且修正後反而看起來更繁瑣，且執行時間也沒有比較快，這點必須再修正。而測試程式的部分我使用維基百科上面的程式做參考組，如果兩程式執行結果相同就會回傳1反之回傳0，測試範圍為1至1000。
