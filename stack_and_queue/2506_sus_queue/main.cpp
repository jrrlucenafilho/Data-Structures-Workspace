#include <iostream>

using namespace std;

#define SESSION_TIME 30 //min

typedef struct {
    int hour, min;
    int min_to_critical;
} tPatient;

int main(void)
{
    int patient_quant;
    int critical_patient_quant = 0;
    int total_elapsed_time_min = 0;
    tPatient placeholder_patient;

    while(!cin.eof()){   
        cin >> patient_quant;

        //Reset values per simulation iter
        critical_patient_quant = 0;
        total_elapsed_time_min = 7 * 60; //Since the clinic opens at 7 am (= 7 * 60 min)

        while(patient_quant--){
            cin >> placeholder_patient.hour;
            cin >> placeholder_patient.min;
            cin >> placeholder_patient.min_to_critical;

            //Increment only while overall patient time is higher than total elapsed in min
            while(total_elapsed_time_min < (placeholder_patient.hour * 60) + placeholder_patient.min){
                total_elapsed_time_min += SESSION_TIME;
            }
            
            //Patient-is-critical check
            if(total_elapsed_time_min - ((placeholder_patient.hour * 60) + placeholder_patient.min) > placeholder_patient.min_to_critical){
                ++critical_patient_quant;
            }

            total_elapsed_time_min += SESSION_TIME;
        }

        cout << critical_patient_quant << '\n';
    }

    return 0;

}