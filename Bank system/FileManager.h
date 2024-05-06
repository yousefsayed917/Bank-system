#pragma once

#include"DataSourceInterface.h"
#include"FilesHelper.h"
using namespace std;
#define C_FILE_PATH "data/clients.txt"
#define E_FILE_PATH "data/employees.txt"
#define A_FILE_PATH "data/admins.txt"
#define CID_FILE_PATH "data/clients_id.txt"
#define EID_FILE_PATH "data/employees_id.txt"
#define AID_FILE_PATH "data/admins_id.txt"
class FileManager : public DataSourceInterface
{
public:
    static void addClient(Client c) {
        Fileshelper::saveClient(c);
    }
    static void addEmployee(Employee e) {
        Fileshelper::saveEmployee(e);
    }
    static void addAdmin(Admin a) {
        Fileshelper::saveAdmin(a);
    }
    static void getAllClient() {
        Fileshelper::getClients();
    }
    static void getAllEmployee() {
        Fileshelper::getEmployees();
    }
    static void getAllAdmin() {
        Fileshelper::getAdmins();
    }
    static void removeAllClients() {
        Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
    }
    static void removeAllEmployees() {
        Fileshelper::ClearFile(E_FILE_PATH, EID_FILE_PATH);
    }
    static void removeAllAdmins() {
        Fileshelper::ClearFile(A_FILE_PATH, AID_FILE_PATH);
    }
    static void UpdateClientTXT() {
        Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
        for (cIt = clients.begin(); cIt != clients.end(); cIt++) {
            Fileshelper::saveClient(*cIt);
        }
    }
    static void UpdateEmployeeTXT() {
        Fileshelper::ClearFile(E_FILE_PATH, EID_FILE_PATH);
        for (eIt = employees.begin(); eIt != employees.end(); eIt++) {
            Fileshelper::saveEmployee(*eIt);
        }
    }
    static void UpdateAdminTXT() {
        Fileshelper::ClearFile(A_FILE_PATH, AID_FILE_PATH);
        for (aIt = admins.begin(); aIt != admins.end(); aIt++) {
            Fileshelper::saveEmployee(*aIt);
        }
    }
};

