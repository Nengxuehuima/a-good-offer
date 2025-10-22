int main() { 
	
	std::map<int,std::string> myMap = { {1, "cat"}, {2, "dog"}, {3, "bird"}, {4, "fish"}, {5, "rabbit"} }; 
	for (auto it = myMap.begin(); it != myMap.end(); ) {
		if (it->second.find('i') != std::string::npos)
			it = myMap.erase(it);
		else
			++it;
	}

	for (const auto& it : myMap)
		std::cout << it.first << ": " << it.second << std::endl;

	return 0;
	
	
}
