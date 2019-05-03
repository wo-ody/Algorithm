#include <string>
#include <iostream>
#include "Key.h"

using namespace std;

Key::Key() {}

Key::Key(string _key_, string _value_) {
	key = _key_;
	value = stod(_value_);
}

string Key::get_key() const {
	return key;
}


double Key::get_value() const {
	return value;
}

void Key::set_key(string _key_) {
	key = _key_;
}

void Key::set_value(string _value_) {
	value = stod(_value_);
}

void Key::print() {
	cout << this->get_key() << "\t\t\t" << this->get_value() << endl;
}

bool operator<(const Key& left, const Key& right) {
	return left.get_key() < right.get_key();

}