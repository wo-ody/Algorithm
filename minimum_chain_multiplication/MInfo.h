///////////////////////////////////////////////////////////////////////////////
// Student.h
// ===========

#ifndef MINFO_H
#define MINFO_H_
#include <string>
#include <vector>

using namespace std;

class MInfo{
public:
	MInfo();
	MInfo(string _name_, int _row_,int _col_);
	string get_name() const;
	int get_row() const;
	int get_col() const;
	void set_name(string _name_);
	void set_row(int _row_);
	void set_col(int _col_);
private:
	string name;
	int row;
	int col;
};

bool operator<(const MInfo& left, const MInfo& right) ;

#endif