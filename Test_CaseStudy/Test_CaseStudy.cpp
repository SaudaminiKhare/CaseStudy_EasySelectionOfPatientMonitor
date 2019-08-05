#include "pch.h"
#include "CppUnitTest.h"
#include "string"
#include "windows.h"
#include "../CaseStudy_EasySelectionOfPatientMonitor/patient_monitor.h"
#include <filesystem> // Microsoft-specific implementation header file name
using namespace std::experimental::filesystem::v1;
//#define MAX 50;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCaseStudy
{
	TEST_CLASS(TestCaseStudy)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			struct PatientMonitor PM[no_monitors];
			char* cwd;
			//cwd = std::filesystem::current_path();
			Logger::WriteMessage("In the path yo!");
			Logger::WriteMessage(current_path().c_str());
			readfile();

			vector<string> test_monitor;
			int len = 0;
			char s1[100], s2[100];
			string s3, s4;
			test_monitor.push_back("IntelliVue Guardian Solution");
			test_monitor.push_back("IntelliVue MX550");
			test_monitor.push_back("SureSigns VSi");
			test_monitor.push_back("SureSigns VS2+");
			int inp[no_features] = { 1,1,0,1,0 };
			vector<string> ret_mon;
			ret_mon = display(inp);

			for (auto i = test_monitor.begin(), j = ret_mon.begin(); i != test_monitor.end(); ++i, ++j)
			{
				
				s3 = *i;
				s4 = *j;
				//s2 = s3.c_str();
				strcpy_s(s1, s3.c_str());
				strcpy_s(s2, s4.c_str());
				Logger::WriteMessage(s1);
				Logger::WriteMessage(s2);
				Assert::AreEqual(s1, s2, true, NULL, NULL);
			}
			
		}
		
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(0, check_length("yy"));
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(1, check_length("y"));
		}

		TEST_METHOD(TestMethod4)
		{
			struct PatientMonitor PM[no_monitors];
			char* cwd;
			//cwd = std::filesystem::current_path();
			Logger::WriteMessage("In the path yo!");
			Logger::WriteMessage(current_path().c_str());
			readfile();

			vector<string> test_monitor;
			int len = 0;
			char s1[100], s2[100];
			string s3, s4;
			test_monitor.push_back("SureSigns VSi");
			int inp[no_features] = { 1,0,1,1,0 };
			vector<string> ret_mon;
			ret_mon = display(inp);

			for (auto i = test_monitor.begin(), j = ret_mon.begin(); i != test_monitor.end(); ++i, ++j)
			{

				s3 = *i;
				s4 = *j;
				//s2 = s3.c_str();
				strcpy_s(s1, s3.c_str());
				strcpy_s(s2, s4.c_str());
				Logger::WriteMessage(s1);
				Logger::WriteMessage(s2);
				Assert::AreEqual(s1, s2, true, NULL, NULL);
			}

		}

		TEST_METHOD(TestMethod5)
		{
			struct PatientMonitor PM[no_monitors];
			char* cwd;
			//cwd = std::filesystem::current_path();
			Logger::WriteMessage("In the path yo!");
			Logger::WriteMessage(current_path().c_str());
			readfile();

			vector<string> test_monitor;
			int len = 0;
			char s1[100], s2[100];
			string s3, s4;
			test_monitor.push_back("SureSigns VSi");
			test_monitor.push_back("Avalon CL");
			int inp[no_features] = { 0,1,1,1,0 };
			vector<string> ret_mon;
			ret_mon = display(inp);

			for (auto i = test_monitor.begin(), j = ret_mon.begin(); i != test_monitor.end(); ++i, ++j)
			{

				s3 = *i;
				s4 = *j;
				//s2 = s3.c_str();
				strcpy_s(s1, s3.c_str());
				strcpy_s(s2, s4.c_str());
				Logger::WriteMessage(s1);
				Logger::WriteMessage(s2);
				Assert::AreEqual(s1, s2, true, NULL, NULL);
			}

		}
	};
}
