#include"chat.h"

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
