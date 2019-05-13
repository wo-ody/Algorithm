#include <string>
#include <vector>
#include "Job.h"

using namespace std;

Job::Job() {}

Job::Job(string _name_, int _deadline_, int _profit_) {
	name = _name_;
	deadline = _deadline_;
	profit = _profit_;
}

string Job::get_name() const {
	return name;
}

int Job::get_deadline() const {
	return deadline;
}

int Job::get_profit() const {
	return profit;
}

void Job::set_name(string _name_) {
	name = _name_;
}

void Job::set_deadline(int _deadline_) {
	deadline = _deadline_;
}

void Job::set_profit(int _profit_) {
	profit = _profit_;
}

bool operator<(const Job &left, const Job &right)
{
	return left.get_profit() < right.get_profit();
}
ostream& operator<<(ostream& os, Job& edge)
{
	os << edge.get_name() << ' ' << edge.get_deadline() << ' ' << edge.get_profit();
	return os;
}


