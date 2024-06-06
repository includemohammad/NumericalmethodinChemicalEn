#include <iostream> 
#include <string>

using namespace std ; 

class serial 
{
    public : 

    int bitrate;
    string prity;
    int databit;
    float stop ;
    string portcom; 

    void serial_def();
    void serial_set();
    void serial_get ();
};



int main(){
    serial Mohammad ; 
    Mohammad.serial_def ();
    Mohammad.serial_get();
    Mohammad.serial_set();
    
    return 0; 
}

void serial::serial_def(){
    bitrate =9600;
    prity = "None ";
    databit = 8;
     stop =1;
    portcom = "CPM2";
}
void serial :: serial_get(){
    cout << "bitrate = "<< bitrate <<endl ;
    cout << "prity = " << prity<<endl  ;
    cout << "databit = " <<databit << endl ;
    cout << "stop bit = " << stop << endl ;
    cout << "port = " << portcom << endl ;
}

void serial :: serial_set (){

    cout << " Please Enter the your name of port (com 1~8): "<< endl ;
    cin >> portcom ; 
    cout<< "Please Enter the your  of biteRate value (4800 - 6800 - 9600 - 115200):" << endl ;
    cin >> bitrate ; 
    cout << "Please Enter the your of stopbit value (1 or 1.5 ) " << endl ; 
    cin >> stop ; 
    cout << " Please Enter the your of parity value (None-Odd-Even-space) :  "<< endl ; 
    cin>> prity ; 
    cout<< " Please Enter the your of Databite (2-4-6-8) : "<< endl ; 
    cin >> databit ;
    if ((portcom =="COM1")||(portcom=="COM2")||(portcom=="COM3")||(protcom=="COM4")||(protcom=="COM5")||(protcom=="COM6")||(protcom=="COM7")||(protcom=="COM8"))
    {
        cout << "Prot COM is Okay XD " << endl ; 
    }
    else {
         cout << "Port COM is not Okay :| " << endl ; 
    }
     if ((bitrate == 4600)|| (bitrate == 9600)|| (bitrate == 15200))
     {
        cout << "Bite Rate is Okay "<< endl ; 
        else {
            cout << "Bit Rate is not Okay :| " << endl ; 

        }
     }
      
      if ((stop==1)||(stop==1.5)||(stop == 2 ))
      {
        cout << "Stop bit is Okay "<< endl ; 
      }
      else{
         cout << "Stop bit is not Okay :|" << endl  ;         
      }
      if (((prity=="none")||(prity=="None"))||((prity=="Even")||(prity=="even"))||((prity=="Odd")||(prity=="odd"))||((prity=="space")))
      {
        cout << "Parity is okay "<< endl ; 
      }
      else{
         cout<< "Prity is not Okay :| "<< endl ; 

      }
if ((databit==2)||(databit==4)||(databit==6)||(databit==8))
{
    cout << "Data bit is Okay "<<endl ;
}
else{
    cout << "Data bit is not Okay :|" << endl ;
}

}