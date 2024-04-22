#pragma once
#include "Client.h"
#include "Admin.h"
class DataSourceInterface
{
public:
    virtual void addClient(Client c) = 0;
    virtual void addEmployee(Employee e) = 0;
    virtual void addAdmin(Admin a) = 0;
    virtual void getAllClient() = 0;
    virtual void getAllEmployee() = 0;
    virtual void getAllAdmin() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;
};

