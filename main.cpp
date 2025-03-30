
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
double results[5][190]; //tab for results
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
void checkif(){ // function that checks if the sorting gave the right results
    int i=0;
    while((tab1[i]<=tab1[i+1])&&(i<(a-2))){
        i++;
    }
    if(tab1[i]>tab1[i+1])
        cout<<"tab no. 1 has an sorting error on position: "<<i<<endl;
    i=0;
    while((tab2[i]<=tab2[i+1])&&(i<(a-2))){
        i++;
    }
    if(tab2[i]>tab2[i+1])
        cout<<"tab no. 2 has an sorting error on position: "<<i<<endl;
    i=0;
    while((tab3[i]<=tab3[i+1])&&(i<(a-2))){
        i++;
    }
    if(tab3[i]>tab3[i+1])
        cout<<"tab no. 3 has an sorting error on position: "<<i<<endl;
    i=0;
    while((tab4[i]<=tab4[i+1])&&(i<(a-2))){
        i++;
    }
    if(tab4[i]>tab4[i+1])
        cout<<"tab no. 4 has an sorting error on position:  "<<i<<endl;
    i=0;
    while((tab5[i]<=tab5[i+1])&&(i<(a-2))){
        i++;
    }
    if(tab5[i]>tab5[i+1])
        cout<<"tab no. 5 has an sorting error on position: "<<i<<endl;
}
void displayres(int a){
    cout<<"sorting time of alg no. 1: "<<results[0][0]<<endl;
    cout<<"sorting time of alg no. 2: : "<<results[1][0]<<endl;
    cout<<"sorting time of alg no. 3: : "<<results[2][0]<<endl;
    cout<<"sorting time of alg no. 4: : "<<results[3][0]<<endl;
    cout<<"sorting time of alg no. 5: : "<<results[4][0]<<endl;
}
displaysorted(int a){
    int temp;
    cin>>temp;
    switch(temp){
    case 0:
       cout<<"tab0"<<endl;
        for(int i=0; i<a;i++){
            cout<<"element "<<i+1<<" :"<<tab0[i]<<endl;
            }
        break;
    case 1:
       cout<<"tab1"<<endl;
        for(int i=0; i<a;i++){
            cout<<"element "<<i+1<<" :"<<tab1[i]<<endl;
            }
        break;
    case 2:
       cout<<"tab2"<<endl;
        for(int i=0; i<a;i++){
            cout<<"element "<<i+1<<" :"<<tab2[i]<<endl;
            }
        break;
    case 3:
       cout<<"tab0"<<endl;
        for(int i=0; i<a;i++){
            cout<<"element "<<i+1<<" :"<<tab3[i]<<endl;
            }
        break;
    case 4:
       cout<<"tab4"<<endl;
        for(int i=0; i<a;i++){
            cout<<"element "<<i+1<<" :"<<tab4[i]<<endl;
            }
        break;
    case 5:
       cout<<"tab5"<<endl;
        for(int i=0; i<a;i++){
            cout<<"element "<<i+1<<" :"<<tab5[i]<<endl;
            }
        break;
    }
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
   //cout<<"1 sort powiodlo sie"<<endl;
}


void sort2(int p){//variation 1 of insert sorting algorithm mistakes made here
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
    //cout<<"2 sort powiodlo sie"<<endl;
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
   //cout<<"4 sort powiodlo sie"<<endl;
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
    //cout<<"5 sort powiodlo sie"<<endl;
}

int main() {
    while(true){
    int choice;
    cout<<"Options:"<<endl<<"1. initialize new arrays"<<endl<<"2. start sorting"<<endl<<"3. view results(time)"<<endl<<"4. inspect arrays"<<endl<<"5. inspect arrays automaticaly"<<endl<<"6. exit"<<endl<<"============================"<<endl;
    cin>>choice;
    switch(choice){

    case 1:
        deletemem();
        cout<<"insert the size of an arrays you want to create"<<endl;
        cin>>a;
        czas++;
        srand(czas);
        randomize(a);
        break;
    case 2:
        sort1(0);
        sort2(0);
        sort3(0);
        sort4(0);
        sort5(0);
        break;
    case 3:
        displayres(a);
        break;
    case 4:
        displaysorted(a);
        break;
    case 5:
        checkif();
        break;
    case 6:
        deletemem();
        exit(0);
        break;
    }
    }
    return 0;
}

