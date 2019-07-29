#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <time.h>
#include <stdio.h>
using namespace std;

map<unsigned int, unsigned int> module;
map<unsigned int, unsigned int> out, dlog;

void AddDependency(unsigned int ModuleID, unsigned int DependModuleID)
{
       unsigned int a = ModuleID, b = DependModuleID;
		module[a] = b;
		dlog[a] = 1;
		out[a] = 0;
		out[b] = 0;
}

void ModuldeIsCycularDependency(unsigned int ModuleID)
{
		map<unsigned int, unsigned int>::iterator pData = module.begin();
		for (pData; pData != module.end(); pData++)
		{
			if (0 == out[pData->first])
			{
				vector<unsigned int> temp;
				unsigned int t = pData->first;
			     while (1 == dlog[t])
				{
					temp.push_back(t);
					if (find(temp.begin(), temp.end(), module[t]) != temp.end())
					{
						for (vector<unsigned int>::iterator k = temp.begin(); k != temp.end(); k++)
							out[*k] = 1;
						break;
					}
					t = module[t];
				}
			}
		}
}

int main()
{
	string s;
	while(cin >> s)
	{
		unsigned int a, b;
		const char *p = s.data();
		sscanf(p,"{%d,%d}", &a, &b);

		AddDependency(a, b);
	}

// 		if('}' == s[s.length() - 1])
// 		{
// 			break;
// 		}
	// }
	cout << "module is " << endl;
	map<unsigned int, unsigned int>::iterator moduleOut = module.begin();
	for(moduleOut; moduleOut != module.end(); moduleOut++) {
	    ModuldeIsCycularDependency(moduleOut -> first);
	    cout << moduleOut -> first << ", " << moduleOut -> second << endl;
	}
	cout << "the out is " << endl;
	map<unsigned int, unsigned int>::iterator ut = out.begin();
	for(ut; ut != out.end(); ut++) {
	    cout << ut -> first << ", " << ut -> second << endl;
	}

	cout << "the relation is " << endl;
	int sum=out.size();
	for (map<unsigned int, unsigned int>::iterator pOutput = out.begin(); pOutput != out.end(); pOutput++)
	{
		sum--;
		cout<<"{0x"<<hex<<pOutput->first<<", ";
		if(pOutput->second==1)
			cout<<"ture}";
		else
			cout<<"false}";

		if(sum==0)
			cout<<endl;
		else
			cout<<","<<endl;
	}
	return 0;
}