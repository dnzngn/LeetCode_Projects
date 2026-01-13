#include "registry.hpp"

int main(int argc, char* argv[]) {
    auto& registry = Registry::instance();
    
    std::cout << "========================================" << std::endl;
    std::cout << "       LeetCode Solutions Runner        " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
    
    if (argc < 2) {
        std::cout << "Kullanim: " << argv[0] << " <problem_id | all | list>" << std::endl;
        std::cout << std::endl;
        std::cout << "Ornekler:" << std::endl;
        std::cout << "  " << argv[0] << " 1       # Two Sum" << std::endl;
        std::cout << "  " << argv[0] << " all     # Tum problemler" << std::endl;
        std::cout << "  " << argv[0] << " list    # Problemleri listele" << std::endl;
        std::cout << std::endl;
        registry.list();
        return 0;
    }
    
    std::string arg = argv[1];
    
    if (arg == "all") {
        registry.runAll();
    } else if (arg == "list") {
        registry.list();
    } else {
        try {
            int id = std::stoi(arg);
            registry.run(id);
        } catch (...) {
            std::cout << "Gecersiz arguman: " << arg << std::endl;
        }
    }
    
    return 0;
}
