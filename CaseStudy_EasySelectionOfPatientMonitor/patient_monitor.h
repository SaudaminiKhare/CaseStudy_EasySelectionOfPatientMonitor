#pragma once
#include<iostream>
#include<string>
#include<limits>
#include<vector>
#include<fstream>
#include <sstream>
#include <filesystem> // Microsoft-specific implementation header file name

using namespace std::experimental::filesystem::v1;
using namespace std;

vector<string> display(int[]);
void readfile();
void chat();
int check_length(string);

const int no_features = 5;
const int no_monitors = 11;

struct PatientMonitor
{
	string name;
	vector<int> FeatureList;
};

struct PatientMonitor PM[no_monitors];
string FeatureName[no_features + 1];

string ques;

string choice;

vector<string> list_monitor;
int input[no_monitors] = { 0 };

int check_length(string s)
{
	if (s.length() > 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

string return_monitor(string s)
{
	return s;
}

void readfile()
{
	string Features[no_features];
	cout << current_path() << endl;
	
	ifstream ip("monitor.csv");

	cout<< current_path() <<endl;

	if (!ip.is_open()) 
		cout << "ERROR: File Open" << '\n';

	int count = 0;

	string line;
	getline(ip, line);
	stringstream ss(line);
	string token;
	int j = 0;
	getline(ss, token, ',');	//To remove A1 cell
	while (getline(ss, token, ','))
	{
		FeatureName[j] = token;
		//cout << j << FeatureName[j] << endl;
		j++;
	}
	//cout << FeatureName[0];
	//cout << line;

	while (ip.good())
	{
		getline(ip, PM[count].name, ',');
		//try {
			for (int i = 0; i < no_features - 1; i++)
			{
				getline(ip, Features[i], ',');
				PM[count]
					.FeatureList
					.push_back(
						stoi(
							Features[i]
						));
			}
		//}
		//catch (...) {
			//cout << "In exception" << endl;
		//}
		getline(ip, Features[no_features - 1], '\n');
		PM[count].FeatureList.push_back(stoi(Features[no_features - 1]));

		//cout << PM[count].name << endl;
		/*for (int i = 0; i < no_features; i++)
		{
			cout << Features[i];
		}
		cout <<"   end of line "<<r<<endl;*/
		count++;
	}

	/*for (int i = 0; i < no_monitors; i++)
	{
		for (auto it = PM[i].FeatureList.begin(); it != PM[i].FeatureList.end(); it++)
			cout << *it << " ";
		cout << endl;
	}*/

	ip.close();
}

vector<string> display(int input[])
{

	int count[no_monitors] = { 0 };
	int i_sum = 0;
	for (int i = 0; i < no_features; i++)
		i_sum += input[i];
	int max = 0, max_index = 0;

	for (int i = 0; i < no_monitors; i++)
	{
		for (int j = 0; j < no_features; j++)
		{
			int output[no_monitors];
			if (input[j] == 1 && PM[i].FeatureList[j] == 1)
			{
				count[i]++;
				output[j] = 1;
			}
			else
				output[j] = 0;

		}
		if (count[i] >= max)
		{
			/*max_index = i;*/
			max = count[i];
		}
	}
	//cout << "Max = " << max << endl;
	list_monitor.clear();
	int i = 0;
	for (int j = 0; j < no_monitors; j++)
	{
		if (count[j] == max)
		{
			list_monitor.push_back(PM[j].name);
			cout << i<< ". patient monitor " << PM[j].name << " matches with a score of " << count[j] << "/" << i_sum << endl;
			i++;
		}
	}
	
	/*for (int j = 0; j < 5; j++)
	{
		cout << input[j] << " ";
	}*/

	/*for (auto i = list_monitor.begin(); i != list_monitor.end(); ++i)
		cout << *i << " ";
	cout << endl;*/
	return list_monitor;
}


void chat()
{
	vector<string> list_monitor;
	string name;
	cout << "Hi there!! What's your name?: ";
	cin >> name;
	cout << "\nHi " << name << " ! Let me help you in selecting suitable patient monitor." << endl;
	for (int i = 0; i < no_features; i++)
	{
	l_choice:cout << endl << "\nDo you want feature " << FeatureName[i] << " ?" << endl;
		cout << "(Enter y for yes and n nor a no): ";
		while (1)
		{
			cin >> choice;
			try
			{
				int valid = 0;
				valid = check_length(choice);
				if (valid == 0)
				{
					throw "Input too long!! Input choice again";
				}
				else
				{
					if (choice.compare("Y") == 0 || choice.compare("y") == 0)
					{
						input[i] = 1;
						break;
					}
					else if (choice.compare("N") == 0 || choice.compare("n") == 0)
					{
						input[i] = 0;
						break;
					}
					//if (strcmpi("Y",choice)==0 || strcmpi("YES", choice)==0)
					//{
					//	input[i] = 1;
					//	break;
					//}
					//else if (strcmpi("N", choice)==0 || strcmpi("NO", choice)==0)
					//{
					//	input[i] = 0;
					//	break;
					//}
					else
					{
						cout << "Wrong choice!! \nEnter again :  ";
						continue;
					}
				}
			}
			catch (...)
			{
				cout << endl << "Multiple characters input for choice!" << endl;
				cout << "Enter choice again!" << endl;
				goto l_choice;
			}


		}
		/*cout << "Required feautres :";
		for (int i = 0; i < no_features; i++)
		{
			cout << input[i] << " ";
		}*/
		list_monitor = display(input);
		
	}
	for (auto i = list_monitor.begin(); i != list_monitor.end(); ++i)
		cout << *i << endl;
	cout << endl;
}