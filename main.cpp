#include<iostream>
#include<random>
#include<ctime>
#include<chrono>
#include<thread>
using namespace std;
//using namespace std::literals::chrono_literals;
int a;
int czas=time(0);
int* tab1;
int* tab2;
int* tab3;
int* tab4;
int* tab5;
int* tab0;
double results[5][6]; //tablica na piec wierszy-algorytmow i na 6 kolumn, kategorii porownania, <100 czas i operacje; <1000 czas i operacje; <10000 czas i operacje
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
            //for(int j=0;j<=i;j++){
            //    if(tab0[j]==temp){
            //    powt=true;
                //cout<<i<<" Powtórka!!!"<<temp<<endl;
             //  break;
             //   }
            //}
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
    cout<<"czas sortowania 1 algorytmu: "<<results[0][0]<<endl;
    cout<<"czas sortowania 2 algorytmu: "<<results[1][0]<<endl;
    cout<<"czas sortowania 3 algorytmu: "<<results[2][0]<<endl;
    cout<<"czas sortowania 4 algorytmu: "<<results[3][0]<<endl;
}
displaysorted(int a){
    int temp;
    cout<<"tab0"<<endl;
    for(int i=0; i<a;i++){
        cout<<"element "<<i+1<<" :"<<tab0[i]<<endl;
    }
    cin>>temp;
    cout<<"tab1"<<endl;
    for(int i=0; i<a;i++){
        cout<<"element "<<i+1<<" :"<<tab1[i]<<endl;
    }
    cin>>temp;
    cout<<"tab2"<<endl;
    for(int i=0; i<a;i++){
        cout<<"element "<<i+1<<" :"<<tab2[i]<<endl;
    }
    cin>>temp;
    cout<<"tab3"<<endl;
    for(int i=0; i<a;i++){
        cout<<"element "<<i+1<<" :"<<tab3[i]<<endl;
    }
    cin>>temp;
   cout<<"tab4"<<endl;
    for(int i=0; i<a;i++){
        cout<<"element "<<i+1<<" :"<<tab4[i]<<endl;
    }
    cin>>temp;
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
     auto start=std::chrono::high_resolution_clock::now();

   for(int i=1;i<a;i++){
        for(int j=i;(j>0)&&(tab1[j]<tab1[j-1]);j--)
        {
            temp=tab1[j];
            tab1[j]=tab1[j-1];
            tab1[j-1]=temp;
        }
   }
   auto end=std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> duration=end - start;
   results[0][0]=duration.count();
   cout<<"1 sort powiodlo sie"<<endl;
}

void sort2(){//variation 1 of insert sorting algorithm
    int temp;
    auto start=std::chrono::high_resolution_clock::now();
    int j;
   for(int i=1;i<a;i++){
       j=0;
        while((j<tab2[i])&&(tab2[j]<tab2[i])){
            j++;
        }
        temp=tab2[i];
        for(int ii=i;ii>j;ii--){
            tab2[ii]=tab2[ii-1];
        }
        tab2[j]=temp;
   }
   auto end=std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> duration=end - start;
   results[1][0]=duration.count();
    cout<<"2 sort powiodlo sie"<<endl;
}
void sort3(){//variation 2 of insert sorting algorithm mirror of sort2
    auto start=std::chrono::high_resolution_clock::now();
    for (int i = a - 2; i >= 0; i--) {
        int temp = tab3[i];
        int j = i;
        while (j < a - 1 && tab3[j + 1] < temp) {
            tab3[j] = tab3[j + 1];
            j++;
        }
        tab3[j] = temp;
    }
   auto end=std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> duration=end - start;
   results[2][0]=duration.count();
    cout<<"4 sort powiodlo sie"<<endl;
}
void sort4(){ //variation 3 of insert sorting algorithm mirror of sort2
}

//tab1[j]^=tab1[j-1];
//tab1[j-1]^=tab1[j];
//tab1[j]^=tab1[j-1];
int main() {
    while(true){
    int choice;
    cout<<"MENU OPCJI"<<endl<<"1. zainicjuj nowe tablice"<<endl<<"2. rozpocznij sortowanie"<<endl<<"3. podglad wynikow"<<endl<<"4. podglad tablic"<<endl<<"5. wyjscie"<<endl<<"============================"<<endl;
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
        sort3();
        sort4();
        break;
    case 3:
        displayres(a);
        break;
    case 4:
        displaysorted(a);
        break;
    case 5:
        deletemem();
        exit(0);
        break;
    }
    }
    return 0;
}
