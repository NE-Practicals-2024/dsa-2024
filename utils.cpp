#include "data.cpp"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

vector<string> split(const string &str, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
};

bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

bool validateDate(const string &date)
{
    vector<string> parts = split(date, '/');
    if (parts.size() != 3)
    {
        cout << "Date format should be dd/mm/yyyy";
        return false;
    }

    int day = stoi(parts[0]);
    int month = stoi(parts[1]);
    int year = stoi(parts[2]);

    if (month < 1 || month > 12)
    {
        cout << "Invalid months passed";
        return false;
    }
    if (year < 1)
    {
        cout << "Invalid years passed";
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1])
    {
        cout << "Invalid days passed";
        return false;
    }

    return true;
}

bool validatePatientRegistration(int id, string &dob, Patient *patientsHead)
{
    if (!validateDate(dob))
    {
        return false;
    }
    return true;
}

bool validateDoctorRegistration(int id, Doctor *doctorsHead)
{
    // Loop through the linked list starting from *doctorsHead to check if id is not duplicated

    return true;
}

bool validateAppointmentRegistration(int patientId, int doctorId, string &date, Patient *patientsHead, Doctor *doctorsHead)
{
    if (!validateDate(date))
    {
        return false;
    }
    // Loop through the link
    return true;
}

//=================================================================
/*
    Functions to display the different nodess
 */
// This function iterates through the patients linked list and displays the patients one by one
void displayPatients(struct Patient *head)
{
    struct Patient *temp = head;

    // iterate the entire linked list and print the data
    while (temp != NULL)
    {
        cout << "Patient ID: " << head->patient_id
             << ", Name: " << head->name
             << ", DOB: " << head->dob
             << ", Gender: " << head->gender
             << endl;
        head = head->next;
        temp = temp->next;
    }
}

// This function iterates through the doctors linked list and displays the doctors one by one
void displayDoctors(struct Doctor *head)
{
    struct Doctor *temp = head;

    // iterate the entire linked list and print the data
    while (temp != NULL)
    {
        cout << "Doctor ID: " << head->doctor_id
             << ", Name: " << head->name
             << ", Specialization: " << head->specialization
             << endl;
        head = head->next;
        temp = temp->next;
    }
}

void displayAppointments(struct Appointment *head)
{
    struct Appointment *temp = head;

    // iterate the entire linked list and print the data
    while (temp != NULL)
    {
        cout << "Appointment ID: " << head->appointment_id
             << ", P_ID: " << head->patient_id
             << ", D_ID: " << head->doctor_id
             << ", DATE: " << head->appointment_date
             << endl;
        head = head->next;
        temp = temp->next;
    }
}

// ==============================================================
/*
    Functions to add nodes to others in the linked list
*/
void addPatient(Patient **head, int id, string name, string dob, string gender)
{
    // create a new node
    struct Patient *newNode = new Patient();
    newNode->patient_id = id;
    newNode->name = name;
    newNode->dob = dob;
    newNode->gender = gender;
    newNode->next = (*head);
    (*head) = newNode;
}

void addDoctor(Doctor **head, int id, string name, string specialization)
{
    // create a new node
    struct Doctor *newNode = new Doctor();
    newNode->doctor_id = id;
    newNode->name = name;
    newNode->specialization = specialization;
    newNode->next = (*head);
    (*head) = newNode;
}

void addAppointment(Appointment **head, int id, int doctor_id, int patient_id, string appointment_date)
{
    // create a new node
    struct Appointment *newNode = new Appointment();
    newNode->appointment_id = id;
    newNode->doctor_id = doctor_id;
    newNode->appointment_date = appointment_date;
    newNode->patient_id = patient_id;
    newNode->next = (*head);
    (*head) = newNode;
}