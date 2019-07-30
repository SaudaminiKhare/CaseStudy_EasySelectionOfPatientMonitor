#include<iostream>
#include<string.h>
#include<limits>
#include<vector>
#include<fstream>
#include <sstream>

using namespace std;

const int no_features = 5;
const int no_monitors = 10;
int patientMonitor[5][5] = { { 1,0,1,0,1 },{ 1,0,1,1,0 },{ 1,1,1,0,0 },{ 0,0,1,0,0 },{ 1,0,0,0,0 } };


void create()
{
	fstream fout;

	fout.open("patientmonitor.csv", ios::out | ios::app);

	for(int i = 0; i < no_monitors; i++)
	{
		fout << "hello\nworld";
	}
	
}

struct PatientMonitor
{
	string name;
	vector<int> FeatureList;
};

struct PatientMonitor PM[no_monitors];
string FeatureName[no_features];

void readfile()
{
	string Features[no_features];
	ifstream ip("book1.csv");

	if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

	int count = 0;
	
	string line;
	getline(ip, line);
	cout << line;

	while (ip.good()) 
	{	
		getline(ip, PM[count].name, ',');
		for (int i = 0; i < no_features-1; i++)
		{
			getline(ip, Features[i], ',');
			PM[count].FeatureList.push_back(stoi(Features[i]));
		}
		getline(ip, Features[no_features-1], '\n');
		PM[count].FeatureList.push_back(stoi(Features[no_features-1]));

		
		
		cout << PM[count].name ;
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

	int count[5] = { 0 };
	int i_sum = 0;
	for (int i = 0; i < 5; i++)
		i_sum += input[i];
	int max = 0, max_index = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int output[5];
			if (input[j] == 1 && patientMonitor[i][j] == 1)
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
	for (int j = 0; j < 5; j++)
	{
		if (count[j] == max)
		{
			cout << "patient monitor #" << j << "matches with a score of " << count[j] << "/" << i_sum << endl;
		}

	}
	for (int j = 0; j < 5; j++)
	{
		cout << input[j] << " ";
	}
}

int main()
{
	string ques;
	
	char choice;
	int input[no_monitors] = { 0 };
	readfile();

	for (int i = 0; i < no_monitors; i++)
	{
		for (auto it = PM[i].FeatureList.begin(); it != PM[i].FeatureList.end(); it++)
			cout << *it << " ";
		cout << endl;
	}

	/*for (int i = 0; i < no_features; i++)
	{
		cout << "Do you want feature " << features[i] << " ?" << endl;
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
		display(input);*/
	//}
}