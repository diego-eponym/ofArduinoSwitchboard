//
//  ofSensor.h
//  ofArduinoSwitchboard
//
//  Created by Diego Zaks on 11/7/14.
//
//

#ifndef ofArduinoSwitchboard_ofSensor_h
#define ofArduinoSwitchboard_ofSensor_h


#endif

#include "ofMain.h"
#include "ofEvents.h"

class ofSensor{
public:
    
    int currentValue;
    
    ofSensor(){
        
    }
    
    void statusOn(){
        ofAddListener(ofEvents().update, this, &ofSensor::update);
    }
    
    void statusOff(){
        ofRemoveListener(ofEvents().update, this, &ofSensor::update);
    }
    
    void changeState(ofEventArgs & args){
        if (!sensorActive) {
            cout << "Inactive" << endl;
        } else {
            cout << "Active" << endl;
        }
        return sensorActive;
    }

    void setSensorValue(int value) {
        currentValue = value;
        return currentValue;
    }


    
private:
    bool sensorActive = false;
    
};