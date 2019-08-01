#pragma once
#include<iostream>
#include<string.h>
#include<limits>
#include<vector>
#include<fstream>
#include <sstream>


std::vector<std::string> display(int[]);
void readfile();
void chat();

const int no_features = 5;
const int no_monitors = 10;

//Structure to store monitor and their feature information
struct PatientMonitor
{
	std::string name;
	std::vector<int> FeatureList;
};

struct PatientMonitor PM[no_monitors];
std::string FeatureName[no_features + 1];

std::string ques;

std::string choice;

std::vector<std::string> list_monitor;
int input[no_monitors] = { 0 };


//Function for reading and storing monitors information from csv file
void readfile()
{
	std::string Features[no_features];
	std::ifstream ip("monitor.csv");

	if (!ip.is_open()) 
		std::cout << "ERROR: File Open" << '\n';

	int count = 0;

	std::string line;
	std::getline(ip, line);
	std::stringstream ss(line);
	std::string token;
	int j = 0;
	std::getline(ss, token, ',');	//To remove A1 cell
	while (std::getline(ss, token, ','))
	{
		FeatureName[j] = token;
		//cout << j << FeatureName[j] << endl;
		j++;
	}
	//cout << FeatureName[0];
	//cout << line;

	while (ip.good())
	{
		std::getline(ip, PM[count].name, ',');
		for (int i = 0; i < no_features - 1; i++)
		{
			std::getline(ip, Features[i], ',');
			PM[count].FeatureList.push_back(stoi(Features[i]));
		}
		std::getline(ip, Features[no_features - 1], '\n');
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


//Function for selecting suitable monitor according to user requirements
std::vector<std::string> display(int input[])
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
	//cout << "Max = " << max << endl;
	list_monitor.clear();
	int i = 1;
	for (int j = 0; j < no_monitors; j++)
	{
		if (count[j] == max)
		{
			list_monitor.push_back(PM[j].name);
			std::cout << i++ << ". patient monitor " << PM[j].name << " matches with a score of " << count[j] << "/" << i_sum << std::endl;
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

//Function for chatting with user
void chat()
{
	std::vector<std::string> list_monitor;
	std::string name;
	std::cout << "Hi there!! What's your name?       ";
	std::cin >> name;
	std::cout << "\nHi " << name << " ! Let me help you in selecting suitable patient monitor.\n\n";
	for (int i = 0; i < no_features; i++)
	{
	l_choice:std::cout << std::endl << "Do you want feature " << FeatureName[i] << " ??" << std::endl;
		std::cout << "(Enter y for yes and n for a no): ";
		while (1)
		{
			std::cin >> choice;
			std::cout << std::endl;
			try
			{
				if (choice.length() > 1)
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
						std::cout << "Wrong choice!! \nEnter again :  " ;
						continue;
					}
				}
			}
			catch (...)
			{
				std::cout << std::endl << "Multiple characters input for choice!" << std::endl;
				std::cout << "Enter choice again!" << std::endl;
				goto l_choice;
			}


		}
		std::cout << "\nRequired feautres :  ";
		for (int i = 0; i < no_features; i++)
		{
			if (input[i] == 1)
				std::cout << FeatureName[i] << "  ";
		}
		std::cout << "\n\n";
		list_monitor = display(input);
	}
	/*for (auto i = list_monitor.begin(); i != list_monitor.end(); ++i)
		cout << *i << " ";
	cout << endl;*/
}