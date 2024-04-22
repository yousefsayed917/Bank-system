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
    void addClient(Client c) {
        Fileshelper::saveClient(c);
    }
    void addEmployee(Employee e) {
        Fileshelper::saveEmployee(e);
    }
    void addAdmin(Admin a) {
        Fileshelper::saveAdmin(a);
    }
    void getAllClient() {
        Fileshelper::getClients();
    }
    void getAllEmployee() {
        Fileshelper::getEmployees();
    }
    void getAllAdmin() {
        Fileshelper::getAdmins();
    }
    void removeAllClients() {
        Fileshelper::ClearFile(C_FILE_PATH, CID_FILE_PATH);
    }
    void removeAllEmployees() {
        Fileshelper::ClearFile(E_FILE_PATH, EID_FILE_PATH);
    }
    void removeAllAdmins() {
        Fileshelper::ClearFile(A_FILE_PATH, AID_FILE_PATH);
    }

};

