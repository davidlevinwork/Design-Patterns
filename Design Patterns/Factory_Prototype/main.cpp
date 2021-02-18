int main() {
    EmployeeFactory* employeeFactory = new EmployeeFactory();
    Employee *e = employeeFactory->create("developer");
	
    if(e)
        e->work();
    e = employeeFactory->create("ta");
    if(e)
        e->work();
    e = employeeFactory->create("garbage");
    if(e)
        e->work();
    return 0;
}