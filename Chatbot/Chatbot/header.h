#include<iostream>
#include<string.h>
#include<limits>
#include<vector>
#include<fstream>
#include <sstream>

using namespace std;

const int no_features = 5;
const int no_monitors = 10;

struct PatientMonitor
{
	string name;
	vector<int> FeatureList;
};

struct PatientMonitor PM[no_monitors];
string FeatureName[no_features + 1];

string ques;

char choice;
int input[no_monitors] = { 0 };

void display(int[]);
