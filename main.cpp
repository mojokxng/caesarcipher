/*
 * Student Name:
 * Course: COSC 4553
 * Assignment: 1
 * File name: main.cpp
 * Program Purpose: Encrypts and decrypts a text file using a simple arithmetic cipher
 * and a nonnegative integer key no more than 120
 *
 * Program limitations: None known
 * Development Computer: custom/personal
 * Operating System: windows 11
 * IDE: zed
 * Compiler: g++
 * Build Directions:
 * Program's Operational Status: yes
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

int decode(int shift, int encoded){
    int decoded;
    decoded = (encoded - shift + 256) % 256;
    return decoded;
}
int encode(int shift, int decoded){
    int encoded;
    encoded = (decoded + shift) % 256;
    return encoded;
}

int main(int argc, char* argv[]) {
    // argument checker
    if (argc != 3){
        std::cerr << "user input invalid. Use -e or -d and an integer\n";
        return 1;
    }
    // All variables after checker.
    std::string option = argv[1];
    int shift = std::stoi(argv[2]);
    std::ofstream out("build\\output.txt");

    if (shift < 0 || shift > 120) {
        std::cerr << "Shift must be positive and less than 120\n";
        return 1;
    }
    // user selects decode
    if (option == "-d"){
        unsigned char uc;
        while (true){
            int c = std::cin.get();
            if (c == EOF){
                break;
            }
            uc = decode(shift, c);

            out << uc;
        }
        std::cerr << "Decryption complete\n";
        return 0;
    // user selects encode
    } else if (option == "-e"){
        unsigned char uc;
        while (true){
            int c = std::cin.get();
            if (c == EOF){
                break;
            }
            uc = encode(shift, c);
            out << uc;
        }
        std::cerr << "Encryption complete\n";
        return 0;
    // user selects anything else
    } else {
        std::cerr << "Invalid option\n";
        return 1;
    }
    return 0;
}
