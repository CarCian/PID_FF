#include "control_loop.h"

//We can use the class constructor to set parameters
CONTROLLER::CONTROLLER(double P, double I, double D, double xdes, double dt) {

    _P=P;
    _I=I;
    _D=D;
    set_xdes(xdes);
    _dt=dt;

    boost::thread loop_thread(&CONTROLLER::loop,this);

}


//Sense: get input to change the state of our System

//Random initial value
void CONTROLLER::system_start() {
    
    srand((unsigned)time(NULL));
    _output=rand()/(RAND_MAX+1.0);

}

void CONTROLLER::loop() {

double err=0, P_err=0, I_err=0, D_err=0, old_err=0;

system_start();
_input=0;
int N=0;

//To empty old data
ofstream f_output("Output.txt");
ofstream f_error("Error.txt");
ofstream f_ref("Ref.txt");
f_output<<"";
f_error<<"";
f_ref<<"";
f_error.close();
f_output.close();
f_ref.close();
//

cout<<"Starting Output: "<<_output<<"\n Starting Input: "<<_input<<"\n";

f_output.open("Output-txt");
f_error.open("Error.txt");
f_ref.open("Ref.txt");

while( abs(err-old_err)>0.001 || N==0){

//Print to file 

f_output<<_output<<endl;
f_error<<err<<endl;
f_ref<<_xdes<<endl;

//

//Feed_Forward
old_err=err;
err=_xdes-_output;
P_err=err;
I_err=I_err+err*_dt;
D_err=(err-old_err)/_dt;
_input=_P*P_err+_I*I_err+_D*D_err;
_output=_input;
//

cout<<"CONTROL OUTPUT: "<<_output<<"\n";
cout<<"ERROR: "<<err<<"\n";
cout<<"SIMULATION TIME: "<<N*_dt<<"\n";
usleep(0.1e6);
N++;
}

f_error.close();
f_output.close();
f_ref.close();

cout<<"RISE TIME cd ..:"<<N*_dt<<"\n";

}


