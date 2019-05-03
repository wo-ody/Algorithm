#ifndef KEY_H
#define KEY_H
#include <string>
#include <vector>

using namespace std;

class Key {
public:
	Key();
	Key(string _key_, string _value_);
	string get_key() const;
	double get_value() const;
	void set_key(string _key_);
	void set_value(string _value_);
	void print();
private:
	string key;
	double value;
};

bool operator<(const Key& left, const Key& right);

#endif