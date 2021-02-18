
int main()
{
    auto pf = new ProductFactory();
    Product* p = pf->createProduct("B");
	
    if(p != nullptr) p->operation();
	
	return 0;
}