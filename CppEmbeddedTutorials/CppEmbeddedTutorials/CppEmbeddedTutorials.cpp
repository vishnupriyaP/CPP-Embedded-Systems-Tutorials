#include "pch.h"
#include <iostream>
#include <bitset>
#include <iomanip>
#define MASK (0xF5)

using namespace std;

const int Max = 8 * sizeof(int);

struct bitfield {
	unsigned int b1 : 1;      // will use 1 bit
	unsigned int b2 : 1;      // 1 bit
	unsigned int nibble : 4;  // 4 bits
	unsigned int byte : 8;    // 8 bits
} bf;


void printBinary(unsigned int n)
{
	//using namespace std;
	int i = 7;
	while (i >= 0) {
		cout << (n >> i & 1);
		i--;
	}
	cout << endl;
}

bool isPalindrome(int n)
{
	bool palindrome = true;
	bitset<Max>b = n;
	for (int i = 0; i < Max / 2 - 1; i++) //xor the bit pattern starting from both ends
	{
		if (b[i] ^ b[Max - 1 - i])
		{
			palindrome = false;
			break;
		}
	}
	return palindrome;
}

int main()
{
	//using namespace std;
	int i;
	int tutorial_num = 0;
	
	cout << "Enter which tutorial number to work on: " << endl;
	cout << "1. Convert int to binary. " << endl;
	cout << "2. Extract least significant, most significant and sigh bit from an int." << endl;
	cout << "3. Mask" << endl;
	cout << "4. Check if binary val is a palindrome. " << endl;
	cin >> tutorial_num;
	if (tutorial_num == 1)
	{
		cout << "Enter number to convert to binary. ";
		while (cin >> i)
			cout << dec << i << "=="
			<< hex << "0x" << i << "=="
			//number of bits in an int, which is 8*sizeof(int)
			<< bitset<8 * sizeof(int)>(i) << endl; // bitset is used to print bits of an int
	}
	else if (tutorial_num == 2)
	{
		const int max = 8;
		short val;
		cout << "Enter number (int): " << endl;
		while (cin >> val)
		{
			//short val = 4;
			unsigned char left = val & 0xff;          // leftmost (least significant) byte; "& 0xff" masks the variable so it only shows the last eight bits 
			cout << dec << val << "=="
				<< hex << "0x" << val << endl;
			cout << "Leftmost byte (least significant): " << bitset<max>(left) << endl;

			unsigned char right = (val >> 8) & 0xff;  // rightmost (most significant) byte; right shifts val by 8 bits
			cout << "Rightmost byte(most significant) : " << bitset<max>(right) << endl;

			bool sign_bit = val & 0x8000;             // sign bit; and's val with 0x8000
			cout << "Sign bit: " << sign_bit << endl;
		}
	}

	else if (tutorial_num == 3)
	{
		unsigned int a = 15;

		cout << "MASK    : ";
		printBinary(MASK);

		cout << "a       : ";
		printBinary(a);

		a &= MASK;
		cout << "a & MASK: ";
		printBinary(a);

		return 0;
	}
}
