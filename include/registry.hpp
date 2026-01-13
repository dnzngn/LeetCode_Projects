#pragma once

#include <functional>
#include <map>
#include <string>
#include <iostream>

class Registry {
public:
    using TestFunc = std::function<void()>;
    
    static Registry& instance() {
        static Registry reg;
        return reg;
    }
    
    void add(int id, const std::string& name, TestFunc func) {
        problems_[id] = {name, func};
    }
    
    void run(int id) {
        if (problems_.find(id) != problems_.end()) {
            std::cout << "=== Problem " << id << ": " << problems_[id].first << " ===" << std::endl;
            problems_[id].second();
            std::cout << std::endl;
        } else {
            std::cout << "Problem " << id << " bulunamadi." << std::endl;
        }
    }
    
    void runAll() {
        for (const auto& [id, problem] : problems_) {
            run(id);
        }
    }
    
    void list() {
        std::cout << "Mevcut problemler:" << std::endl;
        for (const auto& [id, problem] : problems_) {
            std::cout << "  " << id << ": " << problem.first << std::endl;
        }
    }

private:
    Registry() = default;
    std::map<int, std::pair<std::string, TestFunc>> problems_;
};

#define REGISTER_PROBLEM(id, name) \
    static struct Register_##id { \
        Register_##id() { \
            Registry::instance().add(id, name, test); \
        } \
    } register_##id;
