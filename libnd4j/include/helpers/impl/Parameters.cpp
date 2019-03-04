//
// Created by raver on 2/28/2019.
//

#include "../benchmark/Parameters.h"

namespace nd4j {
    Parameters* Parameters::addIntParam(std::string string, int param) {
        _intParams[string] = param;
        return this;
    }

    int Parameters::getIntParam(std::string string) const {
        if (_intParams.count(string) == 0)
            throw std::runtime_error("Not available intParameter requested");

        return _intParams.at(string);
    }

    Parameters* Parameters::addIntParam(std::initializer_list<std::string> strings, std::initializer_list<int> params) {
        std::vector<std::string> s(strings);
        std::vector<int> p(params);

        if (s.size() != p.size())
            throw std::runtime_error("addIntParam: number of keys and values should match");

        for (int e = 0; e < s.size(); e++)
            _intParams[s[e]] = p[e];

        return this;
    }

    Parameters* Parameters::addBoolParam(std::string string, bool param) {
        _boolParams[string] = param;
        return this;
    }

    Parameters* Parameters::addBoolParam(std::initializer_list<std::string> strings, std::initializer_list<bool> params) {
        std::vector<std::string> s(strings);
        std::vector<bool> p(params);

        if (s.size() != p.size())
            throw std::runtime_error("addIntParam: number of keys and values should match");

        for (int e = 0; e < s.size(); e++)
            _boolParams[s[e]] = p[e];

        return this;
    }

    Parameters* Parameters::addArrayParam(std::string string, std::initializer_list<int> param) {
        _arrayParams[string] = std::vector<int>(param);
        return this;
    }

    Parameters* Parameters::addArrayParam(std::initializer_list<std::string> strings, std::initializer_list<std::initializer_list<int>> params) {
        std::vector<std::string> s(strings);
        std::vector<std::initializer_list<int>> p(params);

        if (s.size() != p.size())
            throw std::runtime_error("addIntParam: number of keys and values should match");

        for (int e = 0; e < s.size(); e++)
            _arrayParams[s[e]] = std::vector<int>(p[e]);

        return this;
    }

    bool Parameters::getBoolParam(std::string string) const {
        if (_boolParams.count(string) == 0)
            throw std::runtime_error("Not available boolParameter requested");

        return _boolParams.at(string);
    }

    std::vector<int> Parameters::getArrayParam(std::string string) const {
        if (_arrayParams.count(string) == 0)
            throw std::runtime_error("Not available arrayParameter requested");

        return _arrayParams.at(string);
    }
}
