int main(){
    Manager* m0=new Manager();
    Manager* m1=new Manager();
    Manager* m2=new Manager();
    Employee* e0=new Engineer();
    Employee* e1=new Engineer();
    Employee* e2=new Engineer();
    Employee* e3=new Engineer();
    m0->addEmployee(e0);
    m0->addEmployee(m1);
    m1->addEmployee(e1);
    m1->addEmployee(e2);
    m1->addEmployee(m2);
    m2->addEmployee(e3);
	
    try{
        m1->addEmployee(e0);
    }catch(CycleException e){
        cout<<"catch 1"<<endl; }
	
    try{
        m2->addEmployee(m0);
    }catch(CycleException e){
		cout<<"catch 2"<<endl;}
	
    try{
        m1->addEmployee(m1);
    }catch(CycleException e){
		cout<<"catch 3"<<endl;}
		
    delete m0;
    
	return 0;
}