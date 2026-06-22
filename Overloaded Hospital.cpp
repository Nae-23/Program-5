#include <fstream>
#include <iostream>

using namespace std;

float calculateCharges(int days, float dailyRate, float medicationCharges, float serviceCharges)
{
	// Inpatient charge calculation.
	return (days * dailyRate) + medicationCharges + serviceCharges;
}

float calculateCharges(float medicationCharges, float serviceCharges)
{
	// Outpatient charge calculation.
	return medicationCharges + serviceCharges;
}

int main()
{
	char patientType;
	cout << "Was the patient admitted as an inpatient or outpatient? (I/O): ";
	cin >> patientType;

	float totalCharges = 0.0;

	// Inpatient information.
	if (patientType == 'I' || patientType == 'O')
	{
		int daysSpent = 0;
		float dailyRate = 0.0;
		float medicationCharges = 0.0;
		float serviceCharges = 0.0;

		cout << "Enter the number of days spent in the hospital: ";
		cin >> daysSpent;

		cout << "Enter the daily rate: ";
		cin >> dailyRate;

		cout << "Enter hospital medication charges: ";
		cin >> medicationCharges;

		cout << "Enter charges for hospital services: ";
		cin >> serviceCharges;

		totalCharges = calculateCharges(daysSpent, dailyRate, medicationCharges, serviceCharges);
		cout << "\nHospital Charges Report\n";
		cout << "Patient type: Inpatient\n";
		cout << "Total charges: $" << totalCharges << '\n';

		ofstream reportFile("hospital_charges_report.txt");
		reportFile << "Hospital Charges Report\n";
		reportFile << "Patient type: Inpatient\n";
		reportFile << "Total charges: $" << totalCharges << '\n';
	}
	else
	{
		// Outpatient information.
		float medicationCharges = 0.0;
		float serviceCharges = 0.0;

		cout << "Enter charges for hospital services: ";
		cin >> serviceCharges;

		cout << "Enter hospital medication charges: ";
		cin >> medicationCharges;

		totalCharges = calculateCharges(medicationCharges, serviceCharges);
		cout << "\nHospital Charges Report\n";
		cout << "Patient type: Outpatient\n";
		cout << "Total charges: $" << totalCharges << '\n';

		ofstream reportFile("hospital_charges_report.txt");
		reportFile << "Hospital Charges Report\n";
		reportFile << "Patient type: Outpatient\n";
		reportFile << "Total charges: $" << totalCharges << '\n';
	}

	return 0;
}
