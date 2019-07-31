#include<iostream>
#include<string.h>
#include<limits>
#include<vector>
#include<fstream>
#include <sstream>

using namespace std;

void display(int[]);
void readfile();
void chat();

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

void readfile()
{
	string Features[no_features];
	ifstream ip("book1.csv");

	if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

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
		for (int i = 0; i < no_features - 1; i++)
		{
			getline(ip, Features[i], ',');
			PM[count].FeatureList.push_back(stoi(Features[i]));
		}
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

void display(int input[])
{

	int count[no_monitors] = { 0 };
	int i_sum = 0;
	for (int i = 0; i < 5; i++)
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
	cout << "Max = " << max << endl;
	for (int j = 0; j < no_monitors; j++)
	{
		if (count[j] == max)
		{
			cout << "patient monitor " << PM[j].name << " matches with a score of " << count[j] << "/" << i_sum << endl;
		}

	}
	for (int j = 0; j < 5; j++)
	{
		cout << input[j] << " ";
	}
}


void chat()
{

	for (int i = 0; i < no_features; i++)
	{
		cout << "Do you want feature " << FeatureName[i] << " ?" << endl;
		cout << "(Enter y for yes and n nor a no)" << endl;
		while (1)
		{

			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				input[i] = 1;
				break;
			}
			else if (choice == 'n' || choice == 'N')
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
				cout << "Wrong choice!! \nEnter again : " << endl;
				continue;
			}

		}
		cout << "Required feautres :";
		for (int i = 0; i < no_features; i++)
		{
			cout << input[i] << " ";
		}
		display(input);
	}
}



