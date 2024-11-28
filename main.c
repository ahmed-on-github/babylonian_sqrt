#include <stdio.h>
#include <math.h>

#define ABS(A) ((A)*(((A)>=0) - ((A)<0)))
#define ABS_DIFF(A,B) (((A)-(B))*(((A)>=(B)) - ((A)<(B))))

double babylonian_sqrt(double val){
    double sqrtNew , sqrtOld;

    /*Special Case 1: val < 0*/
    if( val < 0.0){ 
        sqrtNew = -1; /*Return -1 as an indication to a wrong input*/
    }
     /*Special case 2:  val = 0 or 1*/
    else if(val == 0.0 || val == 1.0){
        sqrtNew = val; /*Return value*/
    }
    else{
        sqrtOld = val/2.0; /*A valid initial value*/
        while(1){
            sqrtNew = (sqrtOld + val/sqrtOld)/2.0; /*Get the new sqrt as the average between current sqrt (sqrtOld) and val/sqrtOld */
            if(ABS_DIFF(sqrtNew, sqrtOld) < 1e-6) break; /*Stopping Criteria*/
            sqrtOld = sqrtNew; /*Update old value with the new value for the next iteration*/
        }
    }
    return sqrtNew;
}
int main() {
    double testArr [] = {4.0, 2.0 , 0.0 , 1.0, 1e6, 0.25 , 1e9, 1213467.0};
    char i = 0;
    /*Compare the babylonian_sqrt() results with the results from standard math.h sqrt()*/
    for( i = 0 ; i < ( sizeof(testArr)/sizeof(testArr[0]) ) ; i++){
        printf("babylonian_sqrt(%lf) = %lf\t sqrt(%lf) = %lf\n",
          testArr[i], babylonian_sqrt(testArr[i]), testArr[i], sqrt(testArr[i]));
    }
    return 0;
}
