/*
Drone calculator
To calculate the total weight, thrust required per motor, battery estimation
developed by varigonda vamsi;
*/
#include <iostream>
#include <fstream>

using namespace std;

double Flightparameters( double frame,double payload,double motors,double electronics,double battery ){
double total = frame+payload+battery+electronics;
return total;
}
double Pflightparameters( double frame,double payload,double motors,double electronics,double battery ){
double thrust = (1.75*(frame+payload+battery+electronics))/motors;
return thrust;
}

double Battery( double motors,double currenth, double currentf, double currentc, double time ){
double totalc = ((currentf+currenth)/2)* motors + currentc ;
double Ah = (totalc*time)/60;
return Ah;
}

int main()
{

    ofstream file_("result.txt");
    if (file_.is_open()){
    string name;
    char select;
    double frame, payload, motors, electronics, battery, currenth, currentf, currentc, time;
    cout << "Calculator to calculate the flight time of the drone" << endl;
    cout << "enter the project/file name" <<endl;
    cin >> name;
    file_<<name;
    file_<<"/n";
    cout << "No of motors" << endl;
    cin >> motors;
    file_<<"Number of motors used in the build: \n";
    file_<<motors;
    cout << "Enter the weight of the frame in grams" << endl;
    cin >> frame;
    cout << "Enter the weight of the payload in grams" << endl;
    cin >> payload;
    cout << "Enter the weight of the electronics including motor, esc, fc, wiring in grams" << endl;
    cin >> electronics;
    cout << "Enter the estimated weight of the battery" << endl;
    cin >> battery;
    cout << "Total wight: ";
    cout << Flightparameters (frame, payload, motors, electronics, battery )<< endl;
    file_<< "Total up weight: \n";
    file_<< Flightparameters (frame, payload, motors, electronics, battery );
    cout << "Thrust required to produce per motor to hover: ";
    file_<< "Thrust required to produce per motor to hover: \n";
    file_<< Flightparameters (frame, payload, motors, electronics, battery )/ (motors);
    cout << Flightparameters (frame, payload, motors, electronics, battery )/ (motors) << endl;
    cout << "Thrust required to produce per motor to have a practical flight: ";
    cout << Pflightparameters(frame, payload, motors, electronics, battery) << endl;
    file_<< "Thrust required to produce per motor to have a practical flight: \n";
    file_<< Pflightparameters(frame, payload, motors, electronics, battery);
    cout <<"enter the current draw per motor to produce the required thrust mentioned for hover."<<endl;
    cin >> currenth;
    cout <<"enter the current draw per motor to produce the required thrust mentioned for practical flight."<<endl;
    cin >> currentf;
    cout <<"enter the current draw for addition components like fc, servos, leds etc"<<endl;
    cin >> currentc;
    cout << "What is the required flight time in minutes "<<endl;
    cin >> time;
    file_<< "Flight time: \n";
    file_<< time;
    cout << "Capacity of the battery required in Ah: ";
    file_<< "Capacity of the battery required in Ah: \n";
    file_<< Battery( motors, currenth, currentf, currentc, time);
    cout << Battery( motors, currenth, currentf, currentc, time);
    cout << "Thanks for using the calculator "<<endl;
    file_.close();
    }
    return 0;
}
