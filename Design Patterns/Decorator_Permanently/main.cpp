
int main(){
    I* i = new C(new A(new B(new SomeI()))); // you can change the order of components, the result will be the same
    i->act();
	
    return 0;
}