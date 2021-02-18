int main()
{
    Pizza* firstOrder = new withA(new SimplePizza());
    firstOrder->make();

    Pizza* secondOrder = new withA(new withA(new SimplePizza));
    secondOrder->make();
	
	return 0;
}