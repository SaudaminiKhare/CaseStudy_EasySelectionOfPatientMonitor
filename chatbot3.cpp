#include<iostream>
#include<string>

using namespace std;

const int no_features = 5;
const int no_monitors = 5;

int patientMonitor[5][5] = { { 1,0,1,0,1 },{ 1,0,1,1,0 },{ 1,1,1,0,0 },{ 0,0,1,0,0 },{ 1,0,0,0,0 } };


void display(int input [])
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
	string features[no_features] = { "A", "B", "C", "D", "E" };
	string monitors[no_monitors] = { "A", "B", "C", "D", "E" };
	char choice;
	int input[no_monitors] = { 0 };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << patientMonitor[i][j] << " ";

		}
		cout << endl;
	}

	for (int i = 0; i < no_features ; i++)
	{
		cout << "Do you want feature " << features[i] << " ?" << endl;
		cout << "(Enter y for yes and n nor a no)"<<endl;
		while (1)
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y')
			{
				input[i] = 1;
				break;
			}
			else if (choice == 'n' || choice == 'N')
			{
				input[i] = 0;
				break;
			}
			else
			{
				cout << "Wrong choice!! \nEnter again : " << endl;
				continue;
			}
		}
		cout << "Required feautres :";
		for (int i = 0; i < no_features; i++)
		{
			cout << input[i]<<" ";
		}
		display(input);
	}

	
	
}