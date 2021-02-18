int main()
{
    MathCalculator* x = new DistanceCache(new PowCalculator);

    cout << x->getTotalPow(5,6);
    cout << x->getTotalPow(5,6);
    cout << x->getTotalPow(6,4);

	return 0;
}