#include<stdio.h>
FILE* qn;
FILE* flt;
int main(){
    qn=fopen("question1text.text","r");
    if(qn!=NULL){
        while(fseek(qn,6,SEEK_SET)){
            char ch=fgetc(qn);
            if(ch==NULL){
                printf("it is float numbe:%f",ch);
                flt=fopen("float.text","w");
                fputs(qn,flt);
            }
            else{
                printf("it is alpha number%c\n",ch);

            }
        }
        fclose(qn);
        fclose(flt);
    }
    else
    printf("file is not opened.\n");
    return 0;
}

