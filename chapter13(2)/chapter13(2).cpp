
#include <iostream>
struct Business
{
	int ad_views{};
	int ad_clicks{};
	double cost{};
};
Business get_business()
{
	Business advertisment;
	std::cout << "Enter ad views: ";
	std::cin >> advertisment.ad_views;
	std::cout << "Enter ad clicks: ";
	std::cin >> advertisment.ad_clicks;
	std::cout << "Enter cost: ";
	std::cin >> advertisment.cost;
	return advertisment;
}
void printBusiness(const Business& advertisment)
{
	std::cout << "Ad views: " << advertisment.ad_views << "\n";
	std::cout << "Ad clicks: " << advertisment.ad_clicks << "\n";
	std::cout << "Cost:$ " << advertisment.cost << "\n";

	std::cout << "Cost per click:$ "
		<< (advertisment.ad_views * advertisment.ad_clicks / 100 * advertisment.cost) << "\n";
}


int main()
{
	Business advertisment = get_business();
	printBusiness(advertisment);
	return 0;
}
