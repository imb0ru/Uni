
int main()
{
    int esito;
    float monete[] = {10, 10, 10, 10, 10};

    if(monete[0]==monete[1]){
        if(monete[2]==monete[3]){
            if(monete[0]==monete[4]){
                esito=0;
            }else{
                esito=5;
            }
        }else if(monete[2]==monete[0]){
                esito=4;
            }else{
                esito=3;
        }
    }else if(monete[0]==monete[4]){
        esito=2;
    }else{
        esito=1;
    }
    printf("%d", esito);
    return 0;
}
