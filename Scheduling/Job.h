#ifndef JOB_H
#define JOB_H
#include <string>
#include <vector>

using namespace std;

class Job {
public:
	Job();									// default constructor 
	Job(string name, int deadline, int profit); // constructor
	string get_name() const;
	int get_deadline() const;
	int get_profit() const;
	void set_name(string name);
	void set_deadline(int deadline);
	void set_profit(int profit);
private:
	string name;		// source node
	int deadline;		// destination node
	int profit;		// weight
};

bool operator<(const Job& left, const Job &right);
ostream& operator<<(ostream& os, Job& edge);
#endif
