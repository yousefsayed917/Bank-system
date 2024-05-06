#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "Parser.h"

using namespace std;
#define C_FILE_PATH "data/clients.txt"
#define E_FILE_PATH "data/employees.txt"
#define A_FILE_PATH "data/admins.txt"
#define CID_FILE_PATH "data/clients_id.txt"
#define EID_FILE_PATH "data/employees_id.txt"
#define AID_FILE_PATH "data/admins_id.txt"
class Fileshelper
{
public:
    static void saveLast(string filePath, int id) {
        fstream clientsidFile;
        clientsidFile.open(filePath, ios::out);
        if (clientsidFile.is_open()) {
            clientsidFile << id;
        }
        clientsidFile.close();
    }
    static int getLast(string filePath) {
        fstream clientsidFile;
        int id;
        clientsidFile.open(filePath, ios::in);
        clientsidFile >> id;
        clientsidFile.close();
        return id;
    }
    static void saveClient(Client c) {
        int id = getLast(CID_FILE_PATH);
        fstream clientsFile;
        clientsFile.open(C_FILE_PATH, ios::out | ios::app);
        if (clientsFile.is_open()) {
            clientsFile << id + 1 << '#' << c.getName() << '#' << c.getPassword() << '#' << c.getBalance() << endl;
            clientsFile.close();
        }
        saveLast(CID_FILE_PATH, id + 1);
    }
    static void saveEmployee(Employee e) {
        int id = getLast(EID_FILE_PATH);
        fstream employeesFile;
        employeesFile.open(E_FILE_PATH, ios::out | ios::app);
        if (employeesFile.is_open()) {
            employeesFile << id + 1 << '#' << e.getName() << '#' << e.getPassword() << '#' << e.getSalary() << endl;
            employeesFile.close();
        }
        saveLast(EID_FILE_PATH, id + 1);
    }
    static void saveAdmin(Admin a) {
        int id = getLast(AID_FILE_PATH);
        fstream employeesFile;
        employeesFile.open(A_FILE_PATH, ios::out | ios::app);
        if (employeesFile.is_open()) {
            employeesFile << id + 1 << '#' << a.getName() << '#' << a.getPassword() << '#' << a.getSalary() << endl;
            employeesFile.close();
        }
        saveLast(AID_FILE_PATH, id + 1);
    }
    static void getClients() {
        fstream myFile;
        myFile.open(C_FILE_PATH, ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line))
            {
                clients.push_back(Parser::parseToClient(line));
            }
        }
        myFile.close();
    }
    static void getEmployees() {
        fstream myFile;
        myFile.open(E_FILE_PATH, ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line))
            {
                employees.push_back(Parser::parseToEmployee(line));
            }
        }
        myFile.close();
    }
    static void getAdmins() {
        fstream myFile;
        myFile.open(A_FILE_PATH, ios::in);
        if (myFile.is_open()) {
            string line;
            while (getline(myFile, line))
            {
                admins.push_back(Parser::parseToAdmin(line));
            }
        }
        myFile.close();
    }
    static void ClearFile(string fileName, string lastIdFile) {
        fstream file1, file2;
        file1.open(fileName, ios::out);
        file1.close();
        file2.open(lastIdFile, ios::out);
        file2 << 0;
        file2.close();
    }
};

