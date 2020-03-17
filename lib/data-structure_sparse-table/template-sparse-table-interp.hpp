#include <iostream>
#include <random>
#include <functional>
#include "../template-main.hpp"

template <class Solver, class Monoid>
class SolverInterp {
    std::shared_ptr<Solver> solver = nullptr;
    std::vector<int> array;

    std::shared_ptr<Solver> make_solver() {
        return std::shared_ptr<Solver>(
            new Solver(array, Monoid())
        );
    }

public:
    void action_init() {
        int size, min, max;
        std::cin >> size >> min >> max;
        std::mt19937 random;
        if (size < 0) {
            std::cout << "false" << std::endl;
            return;
        }
        array.assign(size, 0);
        for (int i = 0; i < size; ++i) {
            array[i] = random() % (max - min) + min;
        }
        solver = nullptr;
        std::cout << "true" << std::endl;
    }
    void action_update() {
        int index, value;
        cin >> index >> value;
        if (index < 0 || index >= array.size()) {
            std::cout << "false" << std::endl;
            return;
        }
        array[index] = value;
        solver = nullptr;
        std::cout << "true" << std::endl;
    }
    void action_dump() {
        for (int i = 0; i < array.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << array[i];
        }
        std::cout << std::endl;
    }
    void action_query() {
        int l, r;
        cin >> l >> r;
        if (solver == nullptr) {
            solver = make_solver();
        }
        std::cout << solver->query(l, r) << std::endl;
    }
};

template <class Interp>
void setup(Interp *interp, std::string& header, std::map<std::string,Command>& commands) {
    commands["init"] =
        { "init {size} {min} {max}", std::bind(&Interp::action_init, interp) };
    commands["update"] =
        { "update {index} {value}", std::bind(&Interp::action_update, interp) };
    commands["dump"] =
        { "dump", std::bind(&Interp::action_dump, interp) };
    commands["query"] =
        { "query {l} {r}", std::bind(&Interp::action_query, interp) };
}