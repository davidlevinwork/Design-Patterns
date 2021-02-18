
int main()
{
    // new Singleton(); // Won't work
    Singleton* s = Singleton::getInstance(); 
    Singleton* r = Singleton::getInstance();

    /** The addresses will be the same */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
	
	return 0;
}