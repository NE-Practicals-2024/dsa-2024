#include "utils.cpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
# include <colordlg.h>

using namespace std;

void printHelp()
{
    std::cout << "Menu:\n";
    std::cout << "1. Register a Patient\n";
    std::cout << "2. Register a Doctor\n";
    std::cout << "3. Register an appointment\n";
    std::cout << "4. Display Patients\n";
    std::cout << "5. Display Doctors\n";
    std::cout << "6. Display Appointments\n";
    std::cout << "7. Exit\n";
}

int main()
{

    cout << "=============================================================" << endl;
    cout << "**********= WELCOME TO OUR HEALTH CARE SYSTEM🥳🥳  =********" << endl;
    cout << "**********=      RUHENGERI REFFERAL HOSPITAL        =********" << endl;
    cout << "**********=   Developed by Precieux Mugisha - RCA   =********" << endl;
    cout << "=============================================================" << endl;

    struct Patient *patientsHead = NULL;
    struct Doctor *doctorsHead = NULL;
    struct Appointment *appointmentsHead = NULL;
    std::string choice;
    printHelp();
    while (true)
    {
    startProgram:
        std::cout << "Enter your choice: ";
        std::getline(std::cin, choice);

        if (choice == "1")
        {
        startPatientRegistration:
            int id;
            string name;
            string dob;
            string gender;
            cout << "PATIENT REGISTRATION" << endl;
            cout << "___________________________" << endl;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "NAME: ";
            getline(cin, name);
            cout << "DoB: ";
            cin >> dob;
            cout << "GENDER: ";
            cin >> gender;
            if (!validatePatientRegistration(id, dob, patientsHead))
            {
                cout << "Re-enter your patient info" << endl;
                goto startPatientRegistration;
            }
            addPatient(&patientsHead, id, name, dob, gender);
            cout << "Patient registered successfully" << endl;
        }
        else if (choice == "2")
        {
        startDoctorRegistration:
            int id;
            string name;
            string specialization;
            cout << "DOCTOR REGISTRATION" << endl;
            cout << "___________________________" << endl;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "NAME: ";
            getline(cin, name);
            cout << "SPECIALIZATION: ";
            cin >> specialization;
            if (!validateDoctorRegistration(id, doctorsHead))
            {
                cout << "Re-enter your doctor info" << endl;
                goto startDoctorRegistration;
            }
            addDoctor(&doctorsHead, id, name, specialization);
            cout << "Doctor registered successfully" << endl;
        }

        else if (choice == "3")
        {
        startAppointmentRegistration:
            int id;
            int patientId;
            int doctorId;
            string appointmentDate;
            cout << "APPOINTMENT REGISTRATION" << endl;
            cout << "___________________________" << endl;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "P_ID: ";
            cin >> patientId;
            cout << "D_ID: ";
            cin >> doctorId;
            cout << "DATE: ";
            cin >> appointmentDate;
            if (!validateAppointmentRegistration(id, patientId, doctorId, appointmentDate, patientsHead, doctorsHead, appointmentsHead))
            {
                cout << "Re-enter your appointment data" << endl;
                goto startAppointmentRegistration;
            }
            addAppointment(&appointmentsHead, id, doctorId, patientId, appointmentDate);
            cout << "Appointment registered successfully" << endl;
        }
        else if (choice == "4")
        {
            displayPatients(patientsHead);
        }
        else if (choice == "5")
        {
            displayDoctors(doctorsHead);
        }
        else if (choice == "6")
        {
            displayAppointments(appointmentsHead);
        }
        else if (choice == "7")
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
