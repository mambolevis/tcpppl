// Created by Samvel Khalatyan on Dec 26, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*2) Write an encryption program that reads from cin and writes the encoded
//      characters to cout. You might use this simple encryption scheme:
//
//      the encrypted form of a character c is cˆkey[i], where key is a string
//      passed as a command-line argument. The program uses the characters in
//      key in a cyclic manner until all the input has been read.
//
//      Re-encrypting encoded text with the same key produces the original
//      text. If no key (or a null string) is passed, then no encryption is
//      done.

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void print(const std::string &str)
{
    for(const auto &c:str)
        cout << hex << static_cast<int>(c) << '.';
}

class Processor
{
    public:
        Processor(const string &key): _key{key} {}

        string encrypt(const string &str)
        {
            return process(str);
        }

        string decrypt(const string &str)
        {
            return process(str);
        }

    private:
        string process(const string &str)
            // encrypt and decrypt operations are the same:
            //
            //      c ^= s
            //
            //  where c is the char to encrypt/decrypt
            //        s is the secret
        {
            string result;
            size_t i {0};
            for(string::const_iterator iter {str.begin()};
                    str.end() != iter;
                    ++iter, ++i)
            {
                result += (*iter) ^ _key[i % _key.size()];
            }

            return result;
        }

        string _key;
};

int main(int argc, char *argv[])
{
    Processor processor { 1 >= argc ? "secret" : argv[1] };

    cout << "input string > ";
    for(string str; cin >> str; cout << "input string > ")
    {
        string encrypted_str = processor.encrypt(str);
        string decrypted_str = processor.decrypt(encrypted_str);
        cout << "   string: " << str << endl;
        cout << "encrypted: ";
        print(encrypted_str);
        cout << endl;
        cout << "decrypted: " << decrypted_str << endl;
    }
}
