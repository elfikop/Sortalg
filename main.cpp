#include<iostream>
#include<random>
#include<ctime>
using namespace std;
int a;
int czas=time(0);
int* tab1;
int* tab2;
int* tab3;
int* tab4;
int* tab5;
int* tab0;
int results[5][6]; //tablica na piec wierszy-algorytmow i na 6 kolumn, kategorii porownania, <100 czas i operacje; <1000 czas i operacje; <10000 czas i operacje
void randomize(int b){
    tab0=new int[b];
    tab1=new int[b];
    tab2=new int[b];
    tab3=new int[b];
    tab4=new int[b];
    tab5=new int[b];
    int i=0;
    while(i<b){
        int temp=(rand()%b)+1;
        bool powt=false;
        if(i==0){
            tab0[0]=temp;
            i++;
        }
        else{
            for(int j=0;j<=i;j++){
                if(tab0[j]==temp){
                powt=true;
                //cout<<i<<" Powtórka!!!"<<temp<<endl;
                break;
                }
            }
            if(!powt){
                tab0[i]=temp;
                i++;
            }
        }
    }
    cout<<"sukces"<<endl;
    cout<<sizeof(int);
    memcpy(tab1, tab0,(4*a));
    memcpy(tab2, tab0,(4*a));
    memcpy(tab3, tab0,(4*a));
    memcpy(tab4, tab0,(4*a));
    memcpy(tab5, tab0,(4*a));
}
void displayres(int a){
    cout<<"tab0"<<endl;
    for(int i=0; i<a;i++){
        cout<<"element "<<i+1<<" :"<<tab0[i]<<endl;
    }
    cout<<"tab1"<<endl;
    for(int i=0; i<a;i++){
        cout<<"element "<<i+1<<" :"<<tab1[i]<<endl;
    }
    cout<<"tab2"<<endl;
    for(int i=0; i<a;i++){
        cout<<"element "<<i+1<<" :"<<tab2[i]<<endl;
    }
    //cout<<"tab3"<<endl;
    //for(int i=0; i<a;i++){
    //    cout<<"element "<<i+1<<" :"<<tab3[i]<<endl;
    //}
//
   //cout<<"tab4"<<endl;
    //for(int i=0; i<a;i++){
    //    cout<<"element "<<i+1<<" :"<<tab4[i]<<endl;
    //}
    //cout<<"tab5"<<endl;
    //for(int i=0; i<a;i++){
    //    cout<<"element "<<i+1<<" :"<<tab5[i]<<endl;
    //}
}
void deletemem(){
    delete[] tab0;
    delete[] tab1;
    delete[] tab2;
    delete[] tab3;
    delete[] tab4;
    delete[] tab5;
}
void sort1(){//basic insert sorting alg
    int temp;
   for(int i=1;i<a;i++){
        for(int j=i;(j>0)&&(tab1[j]<tab1[j-1]);j--)
        {
            temp=tab1[j];
            tab1[j]=tab1[j-1];
            tab1[j-1]=temp;

        }
   }

}
void sort2(){//basic insert sorting alg
    int temp;
   for(int i=1;i<a;i++){
        for(int j=i;(j>0)&&(tab2[j]<tab2[j-1]);j--)
        {
            temp=tab2[j];
            tab2[j]=tab2[j-1];
            tab2[j-1]=temp;

        }
   }

}
//tab1[j]^=tab1[j-1];
//tab1[j-1]^=tab1[j];
//tab1[j]^=tab1[j-1];
int main() {
    while(true){
    int choice;
    cout<<"MENU OPCJI"<<endl<<"1. zainicjuj nowe tablice"<<endl<<"2. rozpocznij sortowanie"<<endl<<"3. podglad wynikow"<<endl<<"4. wyjscie"<<endl<<"============================"<<endl;
    cin>>choice;
    switch(choice){
    case 1:
        deletemem();
        cout << "wywolanie finkcji inicjujacej tavlice "<<endl;
        cout<<"podaj wielkosc tablicy"<<endl;
        cin>>a;
        czas++;
        srand(czas);
        randomize(a);
        break;
    case 2:
        sort1();
        sort2();


        break;
    case 3:
        displayres(a);
        break;
    case 4:
        deletemem();
        exit(0);
        break;
    default:
        cout<<"niun"<<endl;
        break;
    }
    }
    return 0;
}
