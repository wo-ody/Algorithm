#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Tokenizer.h"
#include "Job.h"
#include "trim.h"

using namespace std;

bool CompareObj(Job first, Job second);
vector<Job> read_jobs(char *fname);
void print_jobs(vector<Job> &jobs);
vector<Job>schedule(vector<Job> &jobs);
int find_max(vector<Job>&jobs);
bool isfeasible(vector<Job> &jobs);
void print_answers(vector<Job> &jobs);

int main()
{
	char *fName = "jobs.txt";
	vector<Job> jobs = read_jobs(fName);
	//print_jobs(jobs);

	//cout << endl << endl;
	sort(jobs.begin(), jobs.end(), CompareObj);
	//print_jobs(jobs);
	vector<Job> scheduled = schedule(jobs);
	print_answers(scheduled);

	return 1;

}//main

bool CompareObj(Job first, Job second) { return first.get_profit() > second.get_profit(); }//sorting(내림차순)
bool CompareDeadline(Job first, Job second) { return first.get_deadline() > second.get_deadline(); }//sorting

vector<Job> read_jobs(char *fName)
{
	ifstream fin(fName);
	string buf;
	Tokenizer str;
	string name;
	int deadline, profit;
	vector<Job> jobs;

	while (getline(fin, buf)) {
		str.set(buf, " \t\n");
		name = trim(str.next());
		string tmp = trim(str.next());
		deadline = atoi(tmp.c_str());
		string temp = trim(str.next());
		profit = atof(temp.c_str());
		jobs.push_back(Job(name, deadline, profit));
	}
	return jobs;
}

void print_jobs(vector<Job> &jobs)
{
	for (int i = 0; i < jobs.size(); i++)
		cout <<jobs[i].get_name() << " name" << " "
		<< jobs[i].get_deadline() << " deadline" << " "
		<< jobs[i].get_profit() << " profit" << endl;
}

void print_answers(vector<Job> &jobs)
{
	int total = 0;
	cout << "-----------------------------" << endl;
	cout << "Deadline" << "\t" << "Job" << "\t" << "Profit" << endl;
	for (int i = 0; i < jobs.size(); i++) {
		cout << i << jobs[i].get_deadline() << "\t"
			<< jobs[i].get_name() << "\t"
			<< jobs[i].get_profit() << "\t" << endl;
		total += jobs[i].get_profit();
	}
	cout << "-----------------------------" << endl;
	cout << "Total profit = " << total << endl;
	cout << "-----------------------------" << endl;
}

int find_max(vector<Job>&jobs)
{
	sort(jobs.begin(), jobs.end(), CompareDeadline);
	return jobs[0].get_deadline();
}

vector<Job>schedule(vector<Job> &jobs)
{
	int max = find_max(jobs);
	sort(jobs.begin(), jobs.end(), CompareObj);
	int i;
	vector<Job> J;//J 정렬된 상태(Profit 큰대로)
	vector<Job> K;
	J.push_back(jobs[0]);
	K = J;
	for (i = 1; i < jobs.size(); i++)
	{
		K.push_back(jobs[i]);
		if (isfeasible(K))
		{
			J = K;
		}	
	}
	return J;
}

bool isfeasible(vector<Job> &jobs)
{
	int max = find_max(jobs);
	sort(jobs.begin(), jobs.end(), CompareObj);
	int arr[10] = { 0, };
	if (jobs.size() > max)return false;
	for (int i = 0; i < max; i++)
	{
		int index = jobs[i].get_deadline();
		if (arr[index] == 0)return true;
		else
		{
			for (int j = index-1; j >= 1; j--)
			{
				if (arr[j] == 0)return true;
			}
		}
	}
	return false;
}//return true or false