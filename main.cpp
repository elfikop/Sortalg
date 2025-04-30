#include<iostream>
#include<random>
#include<ctime>
#include<chrono>
#include<thread>
#include<fstream>
using namespace std;
int a; /*globally initialized array size variable, used in sorting algorithms*/
int czas=time(0); /*system time variable used as a seed for the random number generator, to prevent
some special cases, it is incremented each time when the new arrays are about to be generated*/
int* tab1; /* pointers to arrays that will be initialized in void ini() func*/
int* tab2;
int* tab3;
int* tab4;
int* tab5;
int* tab0; /* an array, we will never sort, it is the base array that is later filled with data with
randomization process in void randomize() func*/
double results[5][190]; /*fixed size array for results of time each algorithm had to inflict in order to
sort the array*/
void ini(int b){/*allocates memory dynamically, asigns pointers to memory*/
tab0=new int[b];
tab1=new int[b];
tab2=new int[b];
tab3=new int[b];
tab4=new int[b];
tab5=new int[b];
}
void cpy(int z){ /*function that copies tab0 array values to the arrays we will be sorting in the main
function of the program, takes the current array size as the only argument*/
memcpy(tab1, tab0,(4*z));/* the arguments of the memcpy are as shown in this example:
memcpy(where to copy,from where take the data,number of bytes)*/
memcpy(tab2, tab0,(4*z));/* on my computer the int size is 4 bytes so we basically move
4*array_size bytes from the source to the destination.*/
memcpy(tab3, tab0,(4*z));
memcpy(tab4, tab0,(4*z));
memcpy(tab5, tab0,(4*z));
}
void randomize(int b){ /* function that randomizes five tabs of int with values from range 1 to 1
000 000. the function takes a basic argument of current array size*/
ini(b); /*initializing the memory with the size of current array size*/
int i=0;
mt19937 gen(czas); // setting the seed for the random number generator*/
uniform_int_distribution<int> dist(1, 1000000); /*we set the random number generator settings
so in the end we will be getting int numbers from range 1-1 000 000*/
while(i<b){
tab0[i]= dist(gen); /*filling every tab0 array index memory with a randomly generated values*/
i++;
} cpy(b); /* in the end we copy tab0 to every other array*/
}
void test2(bool kol=0){ /* function that initializes the memory with a fixed size array of 100k
elements.*/
a=100000;/*later it fills the tab0 values with ascending or descending ints depending on the bool
argument given from user*/
ini(a); /* the function is needed to perform an second experiment described in the paperwork i
made*/
if(kol==0){
for(int i=0; i<a; i++){/* sorted array*/
tab0[i]= i;
}} else{
int m=99999;
for(int i=0; i<a; i++){/*descending sorted array*/
tab0[i]= m;
m--;
}} cpy(a);
}
void deletemem(){/* function that deletes alocated arrays after the sorting algorithms complete*/
delete[] tab0;
delete[] tab1;
delete[] tab2;
delete[] tab3;
delete[] tab4;
delete[] tab5;
}
void sort1(int p){/*basic insert sorting alg described in the paper*/
int temp;
auto start=std::chrono::high_resolution_clock::now();/* here we use a high resolution clock from
chrono libray to measure the start time of the algorithm*/
for(int i=1;i<a;i++){
temp=tab1[i];
int j=i;
while((j>0)&&(tab1[j-1]>temp))
{ tab1[j]=tab1[j-1];
j--;
} tab1[j]=temp;
} auto end=std::chrono::high_resolution_clock::now(); /* we set another mark to measure the end
time of the sorting algorithm*/
std::chrono::duration<double> duration=end - start; /* here we get the time that the algorithm had
to take in order to sort the array, we get it by substracting auto start - auto end*/
results[0][p]+=duration.count(); /* we sum the time result in a specific result index, for the sort1
algorithm: results[fixed 0 collumn][row depending on how many array sizes measurments have
been made before]*/
}
void sort2(int p){/*variation 2 of insertion sort*/
int temp;
auto start=std::chrono::high_resolution_clock::now();
int j;
for(int i=1;i<a;i++){
j=0;
while((j<i)&&(tab2[j]<tab2[i])){
j++;
} temp=tab2[i];
for(int ii=i;ii>j;ii--){
tab2[ii]=tab2[ii-1];
} tab2[j]=temp;
} auto end=std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration=end - start;
results[1][p]+=duration.count();
}
void sort3(int p) {/*variation 3 of insertion sort("mirror" of sort2)*/
int temp;
int j;
auto start = std::chrono::high_resolution_clock::now();
for (int i = a - 2; i >= 0; i--) {
j = a - 1;
while((j>i) && (tab3[j]>tab3[i])){
j--;
} temp =
tab3[i];
for (int ii = i; ii < j; ii++) {
tab3[ii] = tab3[ii + 1];
}
tab3[j] = temp;
} auto end =
std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration = end - start;
results[2][p]+=duration.count();
}
void sort4(int p){ /*variation 4 of insert sorting algorithm mirror of sort1*/
int temp;
auto start=std::chrono::high_resolution_clock::now();
for(int i=a-1;i>=0;i--){
temp=tab4[i];
int j=i;
while((j<(a-1))&&(tab4[j+1]<temp)){
tab4[j]=tab4[j+1];
j++;
} tab4[j]=temp;
} auto end=std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration=end - start;
results[3][p]=results[3][p]+duration.count();
}
void sort5(int p){/*Binary insertion sorting alg*/
int temp;
int left;
int right;
int shot;
auto start=std::chrono::high_resolution_clock::now();
for(int i=1; i<a; i++){
temp=tab5[i];
left=0;
right=i;
while(left<right){
shot=(left+right)/2;
if(tab5[shot] < temp)
left = shot + 1;
else
right = shot;
} shot =
left;
for (int ii=i; ii>shot; ii--){
tab5[ii]=tab5[ii - 1];
} tab5[shot]=temp;
} auto end=std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration=end - start;
results[4][p]+=duration.count();
} int main() {
int choice;
cout<<"MENU OPCJI"<<endl;
cout<<"Nacisnij 2, aby rololoczac pomiar automatyczny";
cout<<endl;
cout<<"Nacicnij 0, aby rozpoczac pomiar posortowanej";
cout<<endl;
cout<<"Nacisnij 1, aby rozpoczac pomiar odwrotnie posortowanej";
cout<<endl;
cin>>choice; /* after we chose the option number the algorithm goes as follows:*/
if (choice==2){/*here we perform very time consuming automatic measurments that perform
experiment 1 task*/
int c=0;/* c value is the number of how many array sizes measurments have been made
before*/
ofstream plik("test.txt", std::ios::out | std::ios::trunc );/* we open an output text file to save the
data later in the sorting measurment process*/
for(int n=10000;n<110000;n=n+100000){/* this is the main measure loop that varying from
the author wish iterates on the exact array sizes that are about to be generated, initially it has only
one array size - 10 000*/
a=n;/* we have to set a globall array size value to current n array size for the algorithms to
perform sorting*/
for(int i=1;i<=100;i++){/* we repeat the procedure generate data=>sort arras=>delete data
100 times in order to compute average time later*/
czas++;
randomize(a);
thread worker1(sort1,c);/* we use threads to speed up the whole process five times on the
worst case scenario, the c argument given for the sorting*/
thread worker2(sort2,c);/*algorithms is needed in order to sum the sorting time in the
right row of the result table*/
thread worker3(sort3,c);
thread worker4(sort4,c);
thread worker5(sort5,c);
worker1.join();/* the fastest algorithm complete theirs task to this point where the
program stops and waits for the slowest algorithms to join to continue the program on one thread*/
worker2.join();
worker3.join();
worker4.join();
worker5.join();
if(i%10==0){/*here we set some onscreen markings for the user to show him how much
time on average is needed for sorting 10 times the current n size arrays*/
cout<<"wykonalem "<<i<<" pomiarow..."<<endl;// with the slowest algortihm*/
cout<<"sredni czas: "<<(results[2][c]/i)<<endl;
}
deletemem();/*sorted arrays deletion*/
} cout<<"sortowanie udalo sie dla n=: "<<n<<endl;/* another marking, telling us that we
performed 100 sortings on current array size and that no we gonna increase the arr size by 100 000
elements*/
for(int ii=0;ii<5;ii++) /* at the end of sorting specyfic array size 100 times we compute the
average sorting time for each algorithm by following loop:*/
results[ii][c]/=100;
c++;
}
for(int x=0;x<2;x++){ /* when we finish sorting for all array sizes we wanted to, we output the
results array to the output file by following loops:*/
for(int z=0;z<5;z++){
plik<<results[z][x]<<";";
}
plik<<endl;
}
plik.close();
} else{
test2(choice);/* here we perform data generation for the asc sorted/desc sorterd sorting
experiment 2*/
sort1(0);/*sorting process*/
sort2(0);
sort3(0);
sort4(0);
sort5(0);
cout<<"wyniki dla tablic posortowanych/nieposortowanych"<<endl;/* this time we output
the results onscreen because there are always only five numbers as a result*/
cout<<results[0][0]<<" "<<results[1][0]<<" "<<results[2][0];
cout<<" "<<results[3][0];
cout<<" "<<results[4][0]<<endl;/* row indicies in the results table are now fixed as we perform
only one
array size sorting*/
deletemem();
}
return 0;
}
