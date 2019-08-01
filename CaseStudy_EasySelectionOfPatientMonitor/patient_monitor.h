#pragma once
#include<iostream>
#include<string.h>
#include<limits>
#include<vector>
#include<fstream>
#include <sstream>

void display(int[]);
void readfile();
void chat();

const int no_features = 5;
const int no_monitors = 10;

struct PatientMonitor
{
	std::string name;
	std::vector<int> FeatureList;
};

struct PatientMonitor PM[no_monitors];
std::string FeatureName[no_features + 1];

std::string ques;

char choice;
int input[no_monitors] = { 0 };

void readfile()
{
	std::string Features[no_features];
	std::ifstream ip("monitor.csv");

	if (!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

	int count = 0;

	std::string line;
	std::getline(ip, line);
	std::stringstream ss(line);
	std::string token;
	int j = 0;
	std::getline(ss, token, ',');	//To remove A1 cell
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
	std::cout << "Max = " << max << std::endl;
	for (int j = 0; j < no_monitors; j++)
	{
		if (count[j] == max)
		{
			std::cout << "patient monitor " << PM[j].name << " matches with a score of " << count[j] << "/" << i_sum << std::endl;
		}

	}
	for (int j = 0; j < 5; j++)
	{
		std::cout << input[j] << " ";
	}
}


void chat()
{
	std::string name;
	std::cout << "Hi there!! What's your name?"<<std::endl;
	std::cin >> name;
	std::cout << "Hi " << name << " ! Let me help you in selecting suitable patient monitor.";
	for (int i = 0; i < no_features; i++)
	{
		std::cout << "\nDo you want feature " << FeatureName[i] << " ?" << std::endl;
		std::cout << "(Enter y for yes and n for no)" << "";
		while (1)
		{

			std::cin >> choice;
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
				std::cout << "Wrong choice!! \nEnter again : " << std::endl;
				continue;
			}

		}
		std::cout << "Required feautres :";
		for (int i = 0; i < no_features; i++)
		{
			std::cout << input[i] << " ";
		}
		display(input);
	}
}




