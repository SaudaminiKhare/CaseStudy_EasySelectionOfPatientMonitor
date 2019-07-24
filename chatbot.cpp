#include<iostream>

using namespace std;

class prop
{
public:
	

	int patientMonitor[5][5] = { { 1,0,1,0,1 },{ 1,0,1,1,0 },{ 1,1,1,0,0 },{ 0,0,1,0,0 },{ 1,0,0,0,0 } };
	

};

int main()
{
	prop p1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << p1.patientMonitor[i][j]<<" ";

		}
		cout << endl;
	}
	int input[5] = { 1,1,0,1,1 }, i_sum = 0;
	for (int i = 0; i < 5; i++)
		i_sum += input[i];
	int max = 0, max_index = 0;
	int count[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; j < 5; j++)
		{
			int output[5];
			if (input[j] == 1 && p1.patientMonitor[i][j] == 1)
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
			cout <<"patient monitor #"<< j << "matches with a score of "<<count[j]<<"/"<<i_sum<<endl;
		}
		
	}
	for (int j = 0; j < 5; j++)
	{
		cout << input[j] << " ";
	}



	return 0;
}