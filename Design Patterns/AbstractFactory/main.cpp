int main()
{
    std::cout << "Testing Star-Wars equipment:\n" << endl;
    Armory* first = new StarWarsArmory();
    Client(*first);

    std::cout << "Testing Plain-Armory equipment:\n" << endl;
    Armory* second = new PlainArmory();
    Client(*second);
	
	return 0;
}