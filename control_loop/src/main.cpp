#include "control_loop.h"

using namespace std;

//the goal is to implement a simple PID controller, 
//running on input value to reach the desired one

// Sense: read a value from keyboard
// Plan:  generate the correct input
// Act:   set the input

double XDES;
double DT;
double KP;
double KI;
double KD;

int main(int argc, char** argv) {

    KP=atof(argv[1]);
    KI=atof(argv[2]);
    KD=atof(argv[3]);
    DT=atof(argv[4]);

    cout<<"Starting Reference for Control: "<<endl;
    cin>>XDES;

    CONTROLLER C_FF(KP,KI,KD,XDES,DT);

    while(true){

        cout<<"Reference: "<<endl;
        cin>>XDES;
        C_FF.set_xdes(XDES);

    }

    return 0;
}
