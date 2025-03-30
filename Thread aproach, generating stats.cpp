
#include<iostream>
#include<random>
#include<ctime>
#include<chrono>
#include<thread>
#include<fstream>
using namespace std;
int a;
int czas=time(0);
int* tab1;
int* tab2;
int* tab3;
int* tab4;
int* tab5;
int* tab0;
double results[5][190]; //tab for results of both time results and number of oeprations each algorithm had to inflict in order to sort the array
void randomize(int b){ // function that randomizes and initializes four tabs of int from range 1 to aprox 32000
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
            if(!powt){
                tab0[i]=temp;
                i++;
            }
        }
    }
    //cout<<"succes!"<<endl;
    memcpy(tab1, tab0,(4*a));
    memcpy(tab2, tab0,(4*a));
    memcpy(tab3, tab0,(4*a));
    memcpy(tab4, tab0,(4*a));
    memcpy(tab5, tab0,(4*a));
}

void deletemem(){
    delete[] tab0;
    delete[] tab1;
    delete[] tab2;
    delete[] tab3;
    delete[] tab4;
    delete[] tab5;
}
void sort1(int p){//basic insert sorting alg
    int temp;
     auto start=std::chrono::high_resolution_clock::now();

   for(int i=1;i<a;i++){
        temp=tab1[i];
        int j=i;
        while((j>0)&&(tab1[j-1]>temp))
        {
            tab1[j]=tab1[j-1];
            j--;
        }
        tab1[j]=temp;
   }
   auto end=std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> duration=end - start;
   results[0][p]=results[0][p]+duration.count();
}


void sort2(int p){//variation 1
    int temp;
    auto start=std::chrono::high_resolution_clock::now();
    int j;
   for(int i=1;i<a;i++){
       j=0;
        while((j<i)&&(tab2[j]<tab2[i])){
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
   results[1][p]=results[1][p]+duration.count();
}
void sort3(int p) {
    int temp;
    auto start = std::chrono::high_resolution_clock::now();
    int j;

    for (int i = a - 2; i >= 0; i--) {
        j = a - 1;
        while ((j > i) && (tab3[j] > tab3[i])) {
            j--;
        }
        temp = tab3[i];
        for (int ii = i; ii < j; ii++) {
            tab3[ii] = tab3[ii + 1];
        }
        tab3[j] = temp;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    results[2][p] += duration.count();
}
void sort4(int p){ //variation 3 of insert sorting algorithm mirror of sort1
      int temp;
     auto start=std::chrono::high_resolution_clock::now();

   for(int i=a-1;i>=0;i--){
        temp=tab4[i];
        int j=i;
        while((j<(a-1))&&(tab4[j+1]<temp))
        {
            tab4[j]=tab4[j+1];
            j++;
        }
        tab4[j]=temp;
   }
   auto end=std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> duration=end - start;
   results[3][p]=results[3][p]+duration.count();
}
void sort5(int p){//Binary insertion sorting alg
    int temp;
    int left;
    int right;
    int shot;
    auto start=std::chrono::high_resolution_clock::now();
    for (int i = 1; i < a; i++) {
        temp = tab5[i];
        left = 0;
        right = i;
        while (left < right) {
            shot = (left + right) / 2;
            if (tab5[shot] < temp)
                left = shot + 1;
            else
                right = shot;
        }
        shot = left;
        for (int ii = i; ii > shot; ii--) {
            tab5[ii] = tab5[ii - 1];
        }
        tab5[shot] = temp;
    }
   auto end=std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> duration=end - start;
   results[4][p]=results[4][p]+duration.count();
}
int main() {
    int choice;
    cout<<"MENU OPCJI"<<endl<<"0. start"<<endl;
    cin>>choice;
    switch(choice){
        case 0:{
        deletemem();
        int c=0;
        ofstream plik("example.txt", std::ios::out | std::ios::trunc );
        for(int n=10000;n<=210000;n=n+25000){
                a=n;
                for(int i=1;i<=20;i++){
                    czas++;
                    srand(czas);
                    randomize(a);
                    thread worker1(sort1,c);
                    thread worker2(sort2,c);
                    thread worker3(sort3,c);
                    thread worker4(sort4,c);
                    thread worker5(sort5,c);
                    worker1.join();
                    worker2.join();
                    worker3.join();
                    worker4.join();
                    worker5.join();
                    if(i%1==0)
                        cout<<"wykonalem "<<i<<" pomiarow..."<<endl;
                    deletemem();
                }
                cout<<"sortowanie udalo sie dla n=: "<<n<<endl;
                for(int ii=0;ii<5;ii++)
                    results[ii][c]=results[ii][c]/20;
        c++;

        }
        for(int x=0;x<9;x++){
            for(int z=0;z<5;z++){
                plik<<results[z][x];plik<<";";
            }plik<<endl;
        }

        plik.close();
        break;}
        }

         return 0;
         }
