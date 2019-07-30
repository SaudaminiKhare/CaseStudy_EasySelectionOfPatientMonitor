#include"processing.h"

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

