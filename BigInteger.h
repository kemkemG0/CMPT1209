#ifndef BIGINTEGER_H
#define BIGINTEGER_H

using namespace std;

class BigInteger {
public:
  BigInteger();
  BigInteger(long long ll_int);
  BigInteger(const BigInteger &obj);
  BigInteger(BigInteger &&obj) noexcept;
  virtual BigInteger &operator=(const BigInteger &obj);
  virtual BigInteger &operator=(BigInteger &&obj) noexcept;
  virtual ~BigInteger();

  virtual void to_c_string(char *cstr);

  friend ostream &operator<<(ostream &os, const BigInteger &obj);
  friend istream &operator>>(istream &is, BigInteger &obj);

  int operator[](int ind);

protected:
  char *digits;
  int numOfDigits;
  int capacity;

private:
  bool isNegative;
  void doubleBuffer();
};

BigInteger::BigInteger() {
  cout << "called" << endl;
  capacity = 10;
  numOfDigits = 1;
  digits = new char[capacity];
  isNegative = false;
}

BigInteger::BigInteger(long long ll_int) {
  capacity = 10;
  numOfDigits = 0;
  digits = new char[capacity];
  isNegative = ll_int < 0;
  if (ll_int == 0) {
    digits[0] = 0;
    numOfDigits = 1;
    return;
  }
  ll_int = abs(ll_int);
  while (ll_int) {
    digits[numOfDigits++] = '0' + (ll_int % 10);
    ll_int /= 10;
  }
}

BigInteger::BigInteger(const BigInteger &obj) {
  // copy constructor
  capacity = obj.capacity;
  numOfDigits = obj.numOfDigits;
  isNegative = obj.isNegative;
  digits = new char[capacity];
  for (int i = 0; i < numOfDigits; i++) {
    digits[i] = obj.digits[i];
  }
}

BigInteger::BigInteger(BigInteger &&obj) noexcept {
  // move constructor
  capacity = obj.capacity;
  numOfDigits = obj.numOfDigits;
  isNegative = obj.isNegative;
  digits = obj.digits;
  obj.digits = nullptr;
}

BigInteger &BigInteger::operator=(const BigInteger &obj) {
  // copy assignment
  if (this == &obj)
    return *this;

  capacity = obj.capacity;
  numOfDigits = obj.numOfDigits;
  isNegative = obj.isNegative;
  for (int i = 0; i < numOfDigits; i++) {
    digits[i] = obj.digits[i];
  }
  return *this;
}

BigInteger &BigInteger::operator=(BigInteger &&obj) noexcept {
  // move assignment
  if (this == &obj)
    return *this;

  capacity = obj.capacity;
  numOfDigits = obj.numOfDigits;
  isNegative = obj.isNegative;
  digits = obj.digits;
  obj.digits = nullptr;
  return *this;
}

BigInteger::~BigInteger() {
  delete[] digits;
  digits = nullptr;
}

void BigInteger::to_c_string(char *cstr) {
  cstr[0] = isNegative ? '-' : '+';
  int i = 1;
  for (int j = numOfDigits - 1; j >= 0; --j) {
    cstr[i] = digits[j];
    ++i;
  }
  cstr[i] = '\0';
  return;
}

ostream &operator<<(ostream &os, const BigInteger &obj) {
  char sign = obj.isNegative ? '-' : '+';
  os << sign;
  for (int i = obj.numOfDigits - 1; i >= 0; i--)
    os << obj.digits[i];
  return os;
};

istream &operator>>(istream &is, BigInteger &obj) {
  obj.capacity = 100;
  obj.numOfDigits = 0;
  int possible_invalid_ind = 1; // 1-index
  char cstr[100];
  is >> cstr;
  if (cstr[0] == '+')
    obj.isNegative = false;
  else if (cstr[0] == '-')
    obj.isNegative = true;
  else
    throw possible_invalid_ind;

  possible_invalid_ind = 2;
  int ind = 0;
  for (int i = 1; i < 100; i++) {
    if (cstr[i] == '\n' or cstr[i] == '\0')
      break;
    if (!isdigit(cstr[i]))
      throw runtime_error(to_string(possible_invalid_ind) +
                          "th character is invalid.");
    obj.digits[ind] = cstr[i];
    ind++;
    possible_invalid_ind++;
    obj.numOfDigits++;
  }
  // swap reverse one
  for (int i = 0; i < obj.numOfDigits / 2; i++) {
    swap(obj.digits[i], obj.digits[obj.numOfDigits - 1 - i]);
  }
  return is;
}

void BigInteger::doubleBuffer() {
  char *tmp = new char[capacity * 2];
  for (int i = 0; i < numOfDigits; i++) {
    tmp[i] = digits[i];
  }
  delete[] digits;
  digits = tmp;
  capacity *= 2;
}

int BigInteger::operator[](int ind) {
  if (ind <= 0 || ind >= numOfDigits + 1)
    throw out_of_range("out of range");
  return digits[numOfDigits - ind] - '0';
}

/* ---------------------------------------------------------------------------------------------*/

class UnsignedBigInteger : public BigInteger {
public:
  UnsignedBigInteger(long long value);
  UnsignedBigInteger(const UnsignedBigInteger &obj);
  UnsignedBigInteger(UnsignedBigInteger &&obj);

  virtual UnsignedBigInteger &operator=(const UnsignedBigInteger &obj);
  virtual UnsignedBigInteger &operator=(UnsignedBigInteger &&obj) noexcept;
  virtual ~UnsignedBigInteger();

  virtual void to_c_string(char *cstr);

  friend ostream &operator<<(ostream &os, const UnsignedBigInteger &obj);
  friend istream &operator>>(istream &is, UnsignedBigInteger &obj);
};

UnsignedBigInteger::UnsignedBigInteger(long long value) : BigInteger(value) {
  if (value < 0)
    throw domain_error("negative value is invalid");
}

// copy constructor
UnsignedBigInteger::UnsignedBigInteger(const UnsignedBigInteger &obj)
    : BigInteger(obj) {}

// move constructor
UnsignedBigInteger::UnsignedBigInteger(UnsignedBigInteger &&obj)
    : BigInteger(obj) {}

UnsignedBigInteger &
UnsignedBigInteger::operator=(const UnsignedBigInteger &obj) {
  BigInteger::operator=(obj);
  return *this;
}

UnsignedBigInteger &
UnsignedBigInteger::operator=(UnsignedBigInteger &&obj) noexcept {
  BigInteger::operator=(obj);
  return *this;
}

UnsignedBigInteger::~UnsignedBigInteger() { BigInteger::~BigInteger(); }

ostream &operator<<(ostream &os, const UnsignedBigInteger &obj) {
  for (int i = obj.numOfDigits - 1; i >= 0; i--)
    os << obj.digits[i];
  return os;
};

istream &operator>>(istream &is, UnsignedBigInteger &obj) {
  obj.capacity = 100;
  obj.numOfDigits = 0;
  int possible_invalid_ind = 1; // 1-index
  char cstr[100];
  is >> cstr;
  int ind = 0;
  for (int i = 0; i < 100; i++) {
    if (cstr[i] == '\n' or cstr[i] == '\0')
      break;
    if (!isdigit(cstr[i]))
      throw runtime_error(to_string(possible_invalid_ind) +
                          "th character is invalid.");
    obj.digits[ind] = cstr[i];
    ind++;
    possible_invalid_ind++;
    obj.numOfDigits++;
  }
  // swap reverse one
  for (int i = 0; i < obj.numOfDigits / 2; i++) {
    swap(obj.digits[i], obj.digits[obj.numOfDigits - 1 - i]);
  }
  return is;
}

void UnsignedBigInteger::to_c_string(char *cstr) {
  int i = 0;
  for (int j = numOfDigits - 1; j >= 0; --j) {
    cstr[i] = digits[j];
    ++i;
  }
  cstr[i] = '\0';
}

#endif