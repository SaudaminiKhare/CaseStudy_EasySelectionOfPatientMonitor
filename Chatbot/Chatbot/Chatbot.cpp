#include"input.h"

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
		cout << j << FeatureName[j] << endl;
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